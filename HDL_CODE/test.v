`timescale 1ns/1ps

module crypto_sign_signature_internal #(
    parameter M_MAX = 64,
    parameter PRE_MAX = 32
  ) (
    input clock,
    input reset,
    input start_sign_internal,
    output reg done_sign_internal,
    output [26471:0] sig,

    // Data inputs
    input [8*M_MAX-1:0] m,
    input [31:0] mlen,
    input [8*PRE_MAX-1:0] pre,
    input [31:0] prelen,
    input [255:0] rnd,
    input [32255:0] sk
  );

  // PARAMETERS
  localparam K = 6, L = 5;
  localparam SEEDBYTES = 32, TRBYTES = 64, CRHBYTES = 64;
  localparam RNDBYTES = 32, CTILDEBYTES = 48;
  localparam POLYW1_PACKEDBYTES = 128;
  localparam Q = 8380417, GAMMA1 = 524288, GAMMA2 = 261888;
  localparam BETA = 196, OMEGA = 55;

  // FSM States
  localparam ST_IDLE = 4'd0;
  localparam ST_CALC_MU = 4'd1;
  localparam ST_CALC_RHO = 4'd2;
  localparam ST_PRECOMP = 4'd3;
  localparam ST_SAMPLE_Y = 4'd4;
  localparam ST_COMPUTE_W = 4'd5;
  localparam ST_CHALLENGE = 4'd6;
  localparam ST_COMPUTE_Z = 4'd7;
  localparam ST_CHECK_Z = 4'd8;
  localparam ST_COMPUTE_CS2 = 4'd9;
  localparam ST_CHECK_W0 = 4'd10;
  localparam ST_COMPUTE_CT0 = 4'd11;
  localparam ST_CHECK_H = 4'd12;
  localparam ST_PACK_SIG = 4'd13;
  localparam ST_DONE = 4'd14;

  reg [3:0] state, next_state;
  reg [15:0] nonce;

  // Control/Status Wires
  wire z_norm_pass, w0_norm_pass, h_norm_pass, hint_count_pass;
  wire [31:0] hint_count;

  // Done signals
  wire done_z_norm, done_w0_norm, done_h_norm, done_make_hint;
  wire done_cs1_mult, done_cs2_mult, done_ct0_mult, done_w_mult;
  // 1. INPUT BYTE REVERSAL
  wire [32255:0] sk_reversed;
  genvar i;
  generate
    for (i = 0; i < 4032; i = i + 1)
    begin : reverse_sk
      assign sk_reversed[8*i + 7 : 8*i] = sk[8*(4031-i) + 7 : 8*(4031-i)];
    end
  endgenerate

  wire [8*M_MAX-1:0] m_reversed;
  generate
    for (i = 0; i < M_MAX; i = i + 1)
    begin : reverse_m
      assign m_reversed[8*i + 7 : 8*i] = m[8*(M_MAX-1-i) + 7 : 8*(M_MAX-1-i)];
    end
  endgenerate

  wire [8*PRE_MAX-1:0] pre_reversed;
  generate
    for (i = 0; i < PRE_MAX; i = i + 1)
    begin : reverse_pre
      assign pre_reversed[8*i + 7 : 8*i] = pre[8*(PRE_MAX-1-i) + 7 : 8*(PRE_MAX-1-i)];
    end
  endgenerate
  // STEP 1: Unpack Secret Key
  wire [255:0] rho, key;
  wire [511:0] tr;
  localparam VECK_WIDTH = K * 256 * 32;
  localparam VECL_WIDTH = L * 256 * 32;
  wire signed [VECK_WIDTH-1:0] t0, s2;
  wire signed [VECL_WIDTH-1:0] s1;

  unpack_sk unpack_sk_inst (
              .sk_in(sk),
              .rho_out(rho),
              .tr_out(tr),
              .key_out(key),
              .t0_out(t0),
              .s1_out(s1),
              .s2_out(s2)
            );
  // STEP 2: Compute MU
  localparam MU_BITS = 8 * (TRBYTES + PRE_MAX + M_MAX);
  wire [MU_BITS-1:0] mu_input;
  generate
    for (i = 0; i < TRBYTES; i = i + 1)
      assign mu_input[8*i +: 8] = tr[8*i +: 8];
    for (i = 0; i < PRE_MAX; i = i + 1)
      assign mu_input[8*(TRBYTES+i) +: 8] = (i < prelen) ? pre_reversed[8*i +: 8] : 8'd0;
    for (i = 0; i < M_MAX; i = i + 1)
      assign mu_input[8*(TRBYTES+PRE_MAX+i) +: 8] = (i < mlen) ? m_reversed[8*i +: 8] : 8'd0;
  endgenerate

  wire [511:0] mu;
  wire done_mu;
  reg start_mu_reg;

  SHAKE256 #(.r(1088), .c(512), .outlen(512), .len(MU_BITS)) shake256_mu (
             .in(mu_input), .reset(reset), .clk(clock), .start(start_mu_reg),
             .SHAKEout(mu), .done(done_mu)
           );
  // STEP 3: Compute RHOPRIME
  localparam RP_BITS = 8 * (SEEDBYTES + RNDBYTES + CRHBYTES);
  wire [RP_BITS-1:0] rhoprime_input;
  generate
    for (i = 0; i < SEEDBYTES; i = i + 1)
      assign rhoprime_input[8*i +: 8] = key[8*i +: 8];
    for (i = 0; i < RNDBYTES; i = i + 1)
      assign rhoprime_input[8*(SEEDBYTES+i) +: 8] = rnd[8*i +: 8];
    for (i = 0; i < CRHBYTES; i = i + 1)
      assign rhoprime_input[8*(SEEDBYTES+RNDBYTES+i) +: 8] = mu[8*i +: 8];
  endgenerate

  wire [511:0] rhoprime;
  wire done_rhoprime;
  reg start_rho_reg;

  SHAKE256 #(.r(1088), .c(512), .outlen(512), .len(RP_BITS)) shake256_rhoprime (
             .in(rhoprime_input), .reset(reset), .clk(clock), .start(start_rho_reg),
             .SHAKEout(rhoprime), .done(done_rhoprime)
           );
  // STEP 4: Parallel Precomputation & STORAGE (FIX 1: Data Persistence)
  reg start_precomp_reg;
  wire [255:0] rho_reversed;
  generate for (i = 0; i < 32; i = i + 1)
      assign rho_reversed[8*i +: 8] = rho[8*(31-i) +: 8];
  endgenerate

  // Wires from modules
  wire signed [65535:0] mat1_wire, mat2_wire, mat3_wire;
  wire signed [49151:0] mat4_wire;
  wire signed [VECL_WIDTH-1:0] s1_ntt_wire;
  wire signed [VECK_WIDTH-1:0] s2_ntt_wire, t0_ntt_wire;
  wire done_matrix_expand, done_s1_ntt, done_s2_ntt, done_t0_ntt;

  // Registers to STORE results (Kh?c ph?c vi?c m?t d? li?u khi chuy?n state)
  reg signed [65535:0] mat1_stored, mat2_stored, mat3_stored;
  reg signed [49151:0] mat4_stored;
  reg signed [VECL_WIDTH-1:0] s1_ntt_stored;
  reg signed [VECK_WIDTH-1:0] s2_ntt_stored;
  reg signed [VECK_WIDTH-1:0] t0_ntt_stored;

  polyvec_matrix_expand polyvec_matrix_expand_inst (
                          .clock(clock), .reset(reset), .start(start_precomp_reg),
                          .rho_in(rho),
                          .mat1(mat1_wire), .mat2(mat2_wire), .mat3(mat3_wire), .mat4(mat4_wire),
                          .done(done_matrix_expand)
                        );

  // --- NTT Logic for S1, S2, T0 (Input Reversed, Output Stored) ---
  genvar x, y_gen;
  wire [VECL_WIDTH-1:0] s1_reversed_in;
  // S1 Reverse
  generate for (x=0; x<L; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign s1_reversed_in[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = s1[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate

  // S1 NTT
  wire [VECL_WIDTH-1:0] s1_ntt_temp;
  polyvecl_ntt #(.L(L)) polyvecl_ntt_s1 (
                 .clock(clock), .reset(reset), .start(start_precomp_reg),
                 .v_in(s1_reversed_in), .v_out(s1_ntt_temp), .done(done_s1_ntt)
               );
  // Reverse S1 Output (to Wire)
  generate for (x=0; x<L; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign s1_ntt_wire[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = s1_ntt_temp[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate

  // S2 & T0 Setup (Similar to S1)
  wire [VECK_WIDTH-1:0] s2_reversed_in, t0_reversed_in;
  wire [VECK_WIDTH-1:0] s2_ntt_temp, t0_ntt_temp;

  // S2 Reverse In
  generate for (x=0; x<K; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign s2_reversed_in[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = s2[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate
  // S2 NTT
  polyveck_ntt #(.K(K)) polyveck_ntt_s2 (
                 .clock(clock), .reset(reset), .start(start_precomp_reg),
                 .v_in(s2_reversed_in), .v_out(s2_ntt_temp), .done(done_s2_ntt)
               );
  // S2 Reverse Out
  generate for (x=0; x<K; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign s2_ntt_wire[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = s2_ntt_temp[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate

  // T0 Reverse In
  generate for (x=0; x<K; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign t0_reversed_in[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = t0[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate
  // T0 NTT
  polyveck_ntt #(.K(K)) polyveck_ntt_t0 (
                 .clock(clock), .reset(reset), .start(start_precomp_reg),
                 .v_in(t0_reversed_in), .v_out(t0_ntt_temp), .done(done_t0_ntt)
               );
  // T0 Reverse Out
  generate for (x=0; x<K; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign t0_ntt_wire[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = t0_ntt_temp[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate

  // Latch các giá tr? wire vào register khi module con báo done
  reg latched_mat_done, latched_s1_done, latched_s2_done, latched_t0_done;

  always @(posedge clock)
  begin
    if (reset || state == ST_CALC_RHO)
    begin
      {latched_mat_done, latched_s1_done, latched_s2_done, latched_t0_done} <= 4'b0;
    end
    else if (state == ST_PRECOMP)
    begin
      if (done_matrix_expand)
      begin
        latched_mat_done <= 1'b1;
        mat1_stored <= mat1_wire;
        mat2_stored <= mat2_wire;
        mat3_stored <= mat3_wire;
        mat4_stored <= mat4_wire;
      end
      if (done_s1_ntt)
      begin
        latched_s1_done <= 1'b1;
        s1_ntt_stored <= s1_ntt_wire;
      end
      if (done_s2_ntt)
      begin
        latched_s2_done <= 1'b1;
        s2_ntt_stored <= s2_ntt_wire;
      end
      if (done_t0_ntt)
      begin
        latched_t0_done <= 1'b1;
        t0_ntt_stored <= t0_ntt_wire;
      end
    end
  end
  wire all_precomp_done = latched_mat_done & latched_s1_done & latched_s2_done & latched_t0_done;

  // MAIN LOOP: Sample Y and Compute W
  reg start_y_sample_reg;
  always @(posedge clock)
  begin
    if (reset)
      start_y_sample_reg <= 0;
    else
      start_y_sample_reg <= (state == ST_PRECOMP && all_precomp_done) ||
                         (state == ST_CHECK_Z && next_state == ST_SAMPLE_Y) ||
                         (state == ST_CHECK_W0 && next_state == ST_SAMPLE_Y) ||
                         (state == ST_CHECK_H && next_state == ST_SAMPLE_Y);
  end

  wire signed [VECL_WIDTH-1:0] y;
  wire done_y, done_y_ntt;
  polyvecl_uniform_gamma1 polyvecl_uniform_gamma1_inst (
                            .clock(clock), .reset(reset), .start(start_y_sample_reg),
                            .seed(rhoprime), .nonce(nonce), .v_out(y), .done(done_y)
                          );
  // Y NTT
  wire [VECL_WIDTH-1:0] y_reversed_in;
  generate for (x=0; x<L; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign y_reversed_in[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = y[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate

  wire signed [VECL_WIDTH-1:0] y_ntt_temp, y_ntt;
  polyvecl_ntt #(.L(L)) polyvecl_ntt_y (
                 .clock(clock), .reset(reset), .start(done_y),
                 .v_in(y_reversed_in), .v_out(y_ntt_temp), .done(done_y_ntt)
               );
  // Reverse output Y
  generate for (x=0; x<L; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign y_ntt[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = y_ntt_temp[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate

  // COMPUTE W (Matrix * Y)
  wire signed [VECK_WIDTH-1:0] w_temp, w_reduced_temp;
  wire signed [VECK_WIDTH-1:0] w_invntt_temp, w_caddq;
  wire done_w_invntt;
  wire [VECK_WIDTH-1:0] w_reduced, w_invntt;

  polyvec_matrix_pointwise_montgomery polyvec_matrix_mult (
                                        .clock(clock), .reset(reset),
                                        .start(state == ST_COMPUTE_W && done_y_ntt && !done_w_mult),
                                        .v_in(y_ntt),
                                        .mat1(mat1_stored), .mat2(mat2_stored),
                                        .mat3(mat3_stored), .mat4(mat4_stored),
                                        .t_out(w_temp), .done(done_w_mult)
                                      );

  polyveck_reduce polyveck_reduce_w (.v_in(w_temp), .v_out(w_reduced_temp));

  // Reverse W before InvNTT
  generate for (x=0; x<K; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign w_reduced[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = w_reduced_temp[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate

  polyveck_invntt_tomont polyveck_invntt_w (
                           .clock(clock), .reset(reset),
                           .start(state == ST_COMPUTE_W && done_w_mult && !done_w_invntt),
                           .v_in(w_reduced), .v_out(w_invntt_temp), .done(done_w_invntt)
                         );

  // Reverse W after InvNTT
  generate for (x=0; x<K; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign w_invntt[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = w_invntt_temp[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate

  polyveck_caddq polyveck_caddq_w (.v_in(w_invntt), .v_out(w_caddq));
  wire signed [VECK_WIDTH-1:0] w1_decomp, w0_decomp;
  polyveck_decompose polyveck_decompose_inst (.v_in(w_caddq), .v1_out(w1_decomp), .v0_out(w0_decomp));

  wire [K*POLYW1_PACKEDBYTES*8-1:0] w1_packed;
  polyveck_pack_w1 polyveck_pack_w1_inst (.w1_in(w1_decomp), .r_out(w1_packed));


  // CHALLENGE & COMPUTE Z
  localparam CH_IN_BITS = 8*CRHBYTES + K*POLYW1_PACKEDBYTES*8;
  wire [CH_IN_BITS-1:0] challenge_input;
  generate
    for (i = 0; i < CRHBYTES; i = i + 1)
      assign challenge_input[8*i +: 8] = mu[8*i +: 8];
    for (i = 0; i < K*POLYW1_PACKEDBYTES; i = i + 1)
      assign challenge_input[8*(CRHBYTES+i) +: 8] = w1_packed[8*i +: 8];
  endgenerate
  wire [8*CTILDEBYTES-1:0] ctilde;
  wire done_ctilde, done_cp, done_cp_ntt;
  reg start_ctilde_hold;
  always @(posedge clock)
  begin
    if (reset)
      start_ctilde_hold <= 1'b0;
    else if (state == ST_COMPUTE_W && done_w_invntt)
      start_ctilde_hold <= 1'b1;
    else if (done_ctilde)
      start_ctilde_hold <= 1'b0;
  end
  SHAKE256 #(.r(1088), .c(512), .outlen(8*CTILDEBYTES), .len(CH_IN_BITS)) shake256_challenge (
             .in(challenge_input), .reset(reset), .clk(clock), .start(start_ctilde_hold), .SHAKEout(ctilde), .done(done_ctilde)
           );

  // FIX: RESET poly_challenge khi b?t ??u vòng m?i
  wire poly_challenge_reset;
  assign poly_challenge_reset = reset || (state == ST_COMPUTE_W && done_w_invntt);
  wire signed [8191:0] cp_temp;
  reg signed [8191:0] cp_reg;
  reg cp_valid;
  poly_challenge poly_challenge_inst (
                   .clock(clock), .reset(poly_challenge_reset),
                   .start(state == ST_CHALLENGE && done_ctilde && !done_cp),
                   .seed_in(ctilde), .c_out(cp_temp), .done(done_cp)
                 );
  //  FIX: Latch CP
  always @(posedge clock)
  begin
    if (reset)
    begin
      cp_reg <= 8192'd0;
      cp_valid <= 1'b0;
    end
    else if (state == ST_COMPUTE_W && done_w_invntt)
    begin
      // Clear CP khi b?t ??u CHALLENGE m?i
      cp_reg <= 8192'd0;
      cp_valid <= 1'b0;
    end
    else if (state == ST_SAMPLE_Y)
    begin
      // Clear CP khi reject (v? l?i SAMPLE_Y)
      cp_reg <= 8192'd0;
      cp_valid <= 1'b0;
    end
    else if (done_cp && state == ST_CHALLENGE)
    begin
      // Latch CP m?i ch? khi ?ang ? CHALLENGE state
      cp_reg <= cp_temp;
      cp_valid <= 1'b1;
    end
  end
  // Reverse CP before NTT
  wire signed [8191:0] cp_reversed_in, cp_ntt_temp, cp_ntt;
  generate for (x=0; x<256; x=x+1)
      assign cp_reversed_in[32*x+31:32*x] = cp_reg[32*(255-x)+31:32*(255-x)];
  endgenerate
  wire poly_ntt_reset;
  assign poly_ntt_reset = reset ||
         (state == ST_COMPUTE_W && done_w_invntt) ||
         (state == ST_SAMPLE_Y);
  reg start_cp_ntt_hold;
  always @(posedge clock)
  begin
    if (reset)
    begin
      start_cp_ntt_hold <= 1'b0;
    end
    else if (state == ST_COMPUTE_W && done_w_invntt)
    begin
      // Clear start khi b?t ??u CHALLENGE m?i
      start_cp_ntt_hold <= 1'b0;
    end
    else if (state == ST_SAMPLE_Y)
    begin
      // Clear start khi reject
      start_cp_ntt_hold <= 1'b0;
    end
    else if (state == ST_CHALLENGE && cp_valid && !done_cp_ntt)
    begin
      // Start NTT ch? khi: (1) ?ang CHALLENGE, (2) CP ?ã s?n sàng, (3) NTT ch?a done
      start_cp_ntt_hold <= 1'b1;
    end
    else if (done_cp_ntt)
    begin
      // Clear sau khi NTT xong
      start_cp_ntt_hold <= 1'b0;
    end
  end
  poly_ntt poly_ntt_cp (
             .clock(clock), .reset(poly_ntt_reset),
             .start(start_cp_ntt_hold), .poly_in(cp_reversed_in),
             .poly_out(cp_ntt_temp), .done(done_cp_ntt)
           );
  // Reverse CP NTT Out
  generate for (x=0; x<256; x=x+1)
      assign cp_ntt[32*x+31:32*x] = cp_ntt_temp[32*(255-x)+31:32*(255-x)];
  endgenerate
  // COMPUTE Z & CHECK Z
  wire signed [VECL_WIDTH-1:0] cs1_ntt, cs1_temp, cs1, z_temp, z_final;
  wire done_cs1_invntt;

  polyvecl_pointwise_poly_montgomery polyvecl_mult_cs1 (
                                       .clock(clock), .reset(reset),
                                       .start(state == ST_COMPUTE_Z && !done_cs1_mult),
                                       .a_in(cp_ntt),
                                       .v_in(s1_ntt_stored),
                                       .r_out(cs1_ntt), .done(done_cs1_mult)
                                     );

  wire [VECL_WIDTH-1:0] cs1_ntt_reversed;
  generate for (x=0; x<L; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign cs1_ntt_reversed[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = cs1_ntt[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate

  polyvecl_invntt_tomont polyvecl_invntt_cs1 (
                           .clock(clock), .reset(reset),
                           .start(state == ST_COMPUTE_Z && done_cs1_mult && !done_cs1_invntt),
                           .v_in(cs1_ntt_reversed), .v_out(cs1_temp), .done(done_cs1_invntt)
                         );

  // Reverse CS1 Final
  generate for (x=0; x<L; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign cs1[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = cs1_temp[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate

  polyvecl_add polyvecl_add_z (.v_in(cs1), .u_in(y), .w_out(z_temp));
  polyvecl_reduce polyvecl_reduce_z (.v_in(z_temp), .v_out(z_final));

  polyvecl_chknorm polyvecl_chknorm_z (
                     .clock(clock), .reset(reset),
                     .start(state == ST_CHECK_Z && !done_z_norm),
                     .v_in(z_final), .B(GAMMA1 - BETA), .flag(z_norm_pass), .done(done_z_norm)
                   );

  // COMPUTE CS2 & CHECK W0
  wire signed [VECK_WIDTH-1:0] cs2_ntt, cs2_temp, cs2, w0_sub, w0_reduced_check;
  wire done_cs2_invntt;

  polyveck_pointwise_poly_montgomery polyveck_mult_cs2 (
                                       .clock(clock), .reset(reset),
                                       .start(state == ST_COMPUTE_CS2 && !done_cs2_mult),
                                       .a_in(cp_ntt),
                                       .v_in(s2_ntt_stored),
                                       .r_out(cs2_ntt), .done(done_cs2_mult)
                                     );

  wire [VECK_WIDTH-1:0] cs2_ntt_reversed;
  generate for (x=0; x<K; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign cs2_ntt_reversed[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = cs2_ntt[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate

  polyveck_invntt_tomont polyveck_invntt_cs2 (
                           .clock(clock), .reset(reset),
                           .start(state == ST_COMPUTE_CS2 && done_cs2_mult && !done_cs2_invntt),
                           .v_in(cs2_ntt_reversed), .v_out(cs2_temp), .done(done_cs2_invntt)
                         );

  generate for (x=0; x<K; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign cs2[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = cs2_temp[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate

  polyveck_sub polyveck_sub_w0 (.u_in(w0_decomp), .v_in(cs2), .w_out(w0_sub));
  polyveck_reduce polyveck_reduce_w0 (.v_in(w0_sub), .v_out(w0_reduced_check));

  polyveck_chknorm polyveck_chknorm_w0 (
                     .clock(clock), .reset(reset),
                     .start(state == ST_CHECK_W0 && !done_w0_norm),
                     .v_in(w0_reduced_check), .B(GAMMA2 - BETA), .flag(w0_norm_pass), .done(done_w0_norm)
                   );

  // COMPUTE CT0 & CHECK H (FIX: Dùng STORED T0)
  wire signed [VECK_WIDTH-1:0] ct0_ntt, ct0_temp, h_ct0;
  wire done_ct0_invntt;

  polyveck_pointwise_poly_montgomery polyveck_mult_ct0 (
                                       .clock(clock), .reset(reset),
                                       .start(state == ST_COMPUTE_CT0 && !done_ct0_mult),
                                       .a_in(cp_ntt),
                                       .v_in(t0_ntt_stored), // ? FIX: Dùng Stored T0
                                       .r_out(ct0_ntt), .done(done_ct0_mult)
                                     );

  wire [VECK_WIDTH-1:0] ct0_ntt_reversed;
  generate for (x=0; x<K; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign ct0_ntt_reversed[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = ct0_ntt[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate

  polyveck_invntt_tomont polyveck_invntt_ct0 (
                           .clock(clock), .reset(reset),
                           .start(state == ST_COMPUTE_CT0 && done_ct0_mult && !done_ct0_invntt),
                           .v_in(ct0_ntt_reversed), .v_out(ct0_temp), .done(done_ct0_invntt)
                         );

  generate for (x=0; x<K; x=x+1)
      for (y_gen=0; y_gen<256; y_gen=y_gen+1)
        assign h_ct0[8192*x+32*y_gen+31 : 8192*x+32*y_gen] = ct0_temp[8192*x+32*(255-y_gen)+31 : 8192*x+32*(255-y_gen)];
  endgenerate

  wire signed [VECK_WIDTH-1:0] h_reduced, w0_plus_h, hints;
  polyveck_reduce polyveck_reduce_h (.v_in(h_ct0), .v_out(h_reduced));

  polyveck_chknorm polyveck_chknorm_h (
                     .clock(clock), .reset(reset),
                     .start(state == ST_CHECK_H && !done_h_norm),
                     .v_in(h_reduced), .B(GAMMA2), .flag(h_norm_pass), .done(done_h_norm)
                   );

  polyveck_add polyveck_add_w0h (.v_in(w0_reduced_check), .u_in(h_reduced), .w_out(w0_plus_h));

  polyveck_make_hint polyveck_make_hint_inst (
                       .clock(clock), .reset(reset),
                       .start(state == ST_CHECK_H && !done_make_hint),
                       .v0_in(w0_plus_h), .v1_in(w1_decomp), .h_out(hints), .count(hint_count), .done(done_make_hint)
                     );
  assign hint_count_pass = (hint_count <= OMEGA);

  pack_sig pack_sig_inst (.c_in(ctilde), .z_in(z_final), .h_in(hints), .sig_out(sig));
  // FSM CONTROL LOGIC (Keep Standard)
  always @(posedge clock)
  begin
    if (reset)
    begin
      state <= ST_IDLE;
      nonce <= 16'd0;
      done_sign_internal <= 1'b0;
    end
    else
    begin
      state <= next_state;
      done_sign_internal <= (state == ST_DONE);
      if (state == ST_IDLE && start_sign_internal)
        nonce <= 16'd0;
      else if ((state == ST_CHECK_Z && next_state == ST_SAMPLE_Y) ||
               (state == ST_CHECK_W0 && next_state == ST_SAMPLE_Y) ||
               (state == ST_CHECK_H && next_state == ST_SAMPLE_Y))
        nonce <= nonce + 16'd1;
    end
  end

  always @(*)
  begin
    next_state = state;
    case (state)
      ST_IDLE:
        if (start_sign_internal)
          next_state = ST_CALC_MU;
      ST_CALC_MU:
        if (done_mu)
          next_state = ST_CALC_RHO;
      ST_CALC_RHO:
        if (done_rhoprime)
          next_state = ST_PRECOMP;
      ST_PRECOMP:
        if (all_precomp_done)
          next_state = ST_SAMPLE_Y;
      ST_SAMPLE_Y:
        if (done_y)
          next_state = ST_COMPUTE_W;
      ST_COMPUTE_W:
        if (done_w_invntt)
          next_state = ST_CHALLENGE;
      ST_CHALLENGE:
      begin
        if (done_cp_ntt)
          next_state = ST_COMPUTE_Z;
      end
      ST_COMPUTE_Z:
      begin
        if (done_cs1_invntt)
          next_state = ST_CHECK_Z;
      end
      ST_CHECK_Z:
      begin
        if (done_z_norm)
        begin
          if (z_norm_pass === 1'b1)
            next_state = ST_COMPUTE_CS2;
          else
            next_state = ST_SAMPLE_Y;
        end
      end
      ST_COMPUTE_CS2:
        if (done_cs2_invntt)
          next_state = ST_CHECK_W0;
      ST_CHECK_W0:
      begin
        if (done_w0_norm)
        begin
          if (w0_norm_pass === 1'b1)
            next_state = ST_COMPUTE_CT0;
          else
            next_state = ST_SAMPLE_Y;
        end
      end
      ST_COMPUTE_CT0:
        if (done_ct0_invntt)
          next_state = ST_CHECK_H;
      ST_CHECK_H:
      begin
        if (done_h_norm && done_make_hint)
        begin
          if ((h_norm_pass === 1'b1) && (hint_count_pass === 1'b1))
            next_state = ST_PACK_SIG;
          else
            next_state = ST_SAMPLE_Y;
        end
      end
      ST_PACK_SIG:
        next_state = ST_DONE;
      ST_DONE:
        next_state = ST_DONE;
      default:
        next_state = ST_IDLE;
    endcase
  end

  always @(posedge clock)
  begin
    if (reset)
    begin
      {start_mu_reg, start_rho_reg, start_precomp_reg} <= 3'b0;
    end
    else
    begin
      start_mu_reg <= (state == ST_IDLE && start_sign_internal);
      start_rho_reg <= (state == ST_CALC_MU && done_mu);
      start_precomp_reg <= (state == ST_CALC_RHO && done_rhoprime);
    end
  end

endmodule
