module crypto_sign_keypair (
    input  wire                 clock,
    input  wire                 reset,
    input  wire                 start_keygen,
    output reg                  done_keygen,
    output wire [15615:0]       pk,   
    output wire [32255:0]       sk    
);

  localparam K = 6;
  localparam L = 5;

  // --- SIGNALS ---
  wire [271:0] randombytes_temp;
  wire [1023:0] seedbuf_shaked;
  wire [1023:0] seedbuf_shaked_inverse;

  wire [255:0] rho_temp;
  wire [511:0] rhoprime_temp;
  wire [255:0] key_temp;
  wire [511:0] tr_temp;
  wire [511:0] tr_inversed;

  wire signed [65535:0] mat1_temp, mat2_temp, mat3_temp;
  wire signed [49151:0] mat4_temp;

  wire [15:0] nonce_polyvecl_uniform_eta = 0;
  wire [15:0] nonce_polyveck_uniform_eta = L;

  wire signed [40959:0] s1_temp, s1hat, s1_inverse, s1hat_inverse;
  wire signed [49151:0] s2_temp;

  // Done signals
  wire done_shake_1;
  wire done_shake_2;
  wire done_polyvec_matrix_expand;
  wire done_polyvecl_uniform_eta;
  wire done_polyveck_uniform_eta;
  wire done_polyvecl_ntt;
  wire done_polyvec_matrix_pointwise_montgomery;
  wire done_polyveck_invntt;

  wire signed [49151:0] t1, t1_reduced, t1_invntt, t1_added, t1_caddqed, t0, t1_power2round;
  wire signed [49151:0] t1_reduced_inverse, t1_invntt_inverse;

  reg internal_start;

  // 1. SYNCHRONIZATION LOGIC
  reg sync_matrix_done;
  reg sync_s1_ntt_done;
  reg start_matrix_mult_pulse;

  always @(posedge clock) begin
      if (reset || internal_start) begin
          sync_matrix_done <= 0;
          sync_s1_ntt_done <= 0;
          start_matrix_mult_pulse <= 0;
      end else begin

          if (done_polyvec_matrix_expand) 
              sync_matrix_done <= 1;
          
 
          if (done_polyvecl_ntt) 
              sync_s1_ntt_done <= 1;


          if (sync_matrix_done && sync_s1_ntt_done && !start_matrix_mult_pulse) begin
              start_matrix_mult_pulse <= 1; 
          end else begin
              start_matrix_mult_pulse <= 0; 
          end
      end
  end

  // 2. DATAPATH

  randombytes #(.in_len(32)) randombytes (.random_out(randombytes_temp[255:0]));
  assign randombytes_temp[263:256] = K;
  assign randombytes_temp[271:264] = L;

  SHAKE_256 #(.r(1088), .c(512), .outlen(1024), .len(272)) shake256_1 (
      .in(randombytes_temp), .reset(reset), .clk(clock), .SHAKEout(seedbuf_shaked),
      .start(internal_start), .done(done_shake_1)
  );

  generate
    genvar x, y;
    for (x = 0; x < 128; x = x + 1) assign seedbuf_shaked_inverse[8 * x + 7:8 * x] = seedbuf_shaked[8 * (127 - x) + 7:8 * (127 - x)];
  endgenerate

  assign rho_temp = seedbuf_shaked_inverse[255:0];
  assign rhoprime_temp = seedbuf_shaked_inverse[767:256];
  assign key_temp = seedbuf_shaked_inverse[1023:768];

  polyvec_matrix_expand polyvec_matrix_expand (
      .clock (clock), .reset (reset), .start (done_shake_1),
      .rho_in(rho_temp), .mat1(mat1_temp), .mat2(mat2_temp), .mat3(mat3_temp), .mat4(mat4_temp),
      .done(done_polyvec_matrix_expand)
  );

  polyvecl_uniform_eta polyvecl_uniform_eta (
      .clock(clock), .reset(reset), .start(done_shake_1),
      .nonce(nonce_polyvecl_uniform_eta), .seed(rhoprime_temp), .v_out(s1_temp), 
      .done(done_polyvecl_uniform_eta)
  );

  polyveck_uniform_eta polyveck_uniform_eta (
      .clock(clock), .reset(reset), .start(done_shake_1),
      .nonce(nonce_polyveck_uniform_eta), .seed(rhoprime_temp), .v_out(s2_temp), 
      .done(done_polyveck_uniform_eta)
  );

  // --- S1 Path ---
  generate
    for (x = 0; x < L; x = x + 1) for (y = 0; y < 256; y = y + 1) 
        assign s1_inverse[8192*x + 32*y + 31 : 8192*x + 32*y] = s1_temp[8192*x + 32*(255-y) + 31 : 8192*x + 32*(255-y)];
  endgenerate

  polyvecl_ntt#(.L(L)) polyvecl_ntt (
      .clock(clock), .reset(reset), .start(done_polyvecl_uniform_eta),
      .v_in (s1_inverse), .v_out(s1hat), .done (done_polyvecl_ntt)
  );

  generate
    for (x = 0; x < L; x = x + 1) for (y = 0; y < 256; y = y + 1) 
        assign s1hat_inverse[8192*x + 32*y + 31 : 8192*x + 32*y] = s1hat[8192*x + 32*(255-y) + 31 : 8192*x + 32*(255-y)];
  endgenerate


  polyvec_matrix_pointwise_montgomery polyvec_matrix_pointwise_montgomery (
      .clock(clock), .reset(reset),
      .start(start_matrix_mult_pulse), 
      .v_in (s1hat_inverse),
      .mat1(mat1_temp), .mat2(mat2_temp), .mat3(mat3_temp), .mat4(mat4_temp),
      .t_out(t1), .done(done_polyvec_matrix_pointwise_montgomery)
  );

  polyveck_reduce polyveck_reduce (.v_in(t1), .v_out(t1_reduced));

  // --- Continue Pipeline ---
  generate
    for (x = 0; x < K; x = x + 1) for (y = 0; y < 256; y = y + 1) 
        assign t1_reduced_inverse[8192*x + 32*y + 31 : 8192*x + 32*y] = t1_reduced[8192*x + 32*(255-y) + 31 : 8192*x + 32*(255-y)];
  endgenerate

  polyveck_invntt_tomont polyveck_invntt_tomont (
      .clock(clock), .reset(reset), .start(done_polyvec_matrix_pointwise_montgomery),
      .v_in (t1_reduced_inverse), .v_out(t1_invntt), .done (done_polyveck_invntt)
  );

  generate
    for (x = 0; x < K; x = x + 1) for (y = 0; y < 256; y = y + 1) 
        assign t1_invntt_inverse[8192*x + 32*y + 31 : 8192*x + 32*y] = t1_invntt[8192*x + 32*(255-y) + 31 : 8192*x + 32*(255-y)];
  endgenerate

  polyveck_add polyveck_add (.v_in(t1_invntt_inverse), .u_in(s2_temp), .w_out(t1_added));
  polyveck_caddq polyveck_caddq (.v_in(t1_added), .v_out(t1_caddqed));
  polyveck_power2round polyveck_power2round (.v_in(t1_caddqed), .v0_out(t0), .v1_out(t1_power2round));

  pack_pk pack_pk (.rho_in(rho_temp), .t1_in(t1_power2round), .pk_out(pk));

  SHAKE_256 #(.r(1088), .c(512), .outlen(512), .len(15616)) shake256_2 (
      .in(pk), .reset(reset), .clk(clock),
      .start(done_polyveck_invntt),
      .SHAKEout(tr_temp), .done(done_shake_2)
  );

  generate
    for (x = 0; x < 64; x = x + 1) assign tr_inversed[8*x+7:8*x] = tr_temp[8*(63-x)+7:8*(63-x)];
  endgenerate

  pack_sk pack_sk (
      .rho_in(rho_temp), .key_in(key_temp), .tr_in(tr_inversed),
      .t0_in(t0), .s1_in(s1_temp), .s2_in(s2_temp), .sk_out(sk)
  );

  // 3. FSM
  localparam ST_IDLE = 2'd0, ST_RUNNING = 2'd1, ST_DONE = 2'd2;
  reg [1:0] state, next_state;

  always @(posedge clock) begin
    if (reset) begin
      state <= ST_IDLE;
      internal_start <= 0;
      done_keygen <= 0;
    end else begin
      state <= next_state;
      case (next_state)
        ST_IDLE: begin internal_start <= 0; done_keygen <= 0; end
        ST_RUNNING: begin
            if (state == ST_IDLE) internal_start <= 1; else internal_start <= 0;
            done_keygen <= 0;
        end
        ST_DONE: begin internal_start <= 0; done_keygen <= 1; end
      endcase
    end
  end
always @(*) begin
    next_state = state;
    case (state)
      ST_IDLE: if (start_keygen) next_state = ST_RUNNING;
      ST_RUNNING: if (done_shake_2) next_state = ST_DONE;
      ST_DONE: next_state = ST_IDLE; // Auto reset for next run
      default: next_state = ST_IDLE;
    endcase
  end
endmodule
