module poly_uniform_eta (
    input clock,
    input reset,
    input start,
    input [511:0] seed,
    input [15:0] nonce,
    output signed [8191:0] a_out,
    output reg done
);
  localparam N = 256;
  localparam SHAKE256_RATE = 136;
  localparam POLY_UNIFORM_ETA_NBLOCKS = 2;

  //Inter Outputs
  wire [1599:0] state_s;
  wire [31:0] state_pos;
  wire [2175:0] linear_buf;
  wire [1599:0] linear_state_s_out;
  
  reg start_dilithium_shake256_stream_init;
  wire done_dilithium_shake256_stream_init;
  wire done_shake256_squeezeblocks;

  reg [63:0] nblocks = 5;
  reg [31:0] len = 256;
  reg [31:0] buflen = 272;

  reg [7:0] buff[0:271];
  wire [7:0] buff_in[0:271];

  //Inter Outputs
  wire [31:0] ctr;

  wire done_rej_eta;

  generate
    genvar x;
    for (x = 0; x < 272; x = x + 1) begin
      assign buff_in[x] = linear_buf[8*x+7:8*x];
    end
  endgenerate

    dilithium_shake256_stream_init dilithium_shake256_stream_init (
      .clock(clock),
      .reset(reset),
      .start(start_dilithium_shake256_stream_init),
      .seed(seed),
      .nonce(nonce),
      .state_s(state_s),
      .state_pos(state_pos),
      .done(done_dilithium_shake256_stream_init)
  );
  shake256_squeezeblocks shake256_squeezeblocks (
      .clock(clock),
      .reset(reset),
      .start(done_dilithium_shake256_stream_init),
      .state_s_in(state_s),
      .nblocks(nblocks),
      .out(linear_buf),
      .state_s_out(linear_state_s_out),
      .done(done_shake256_squeezeblocks)
  );

    rej_eta rej_eta (
      .clock(clock),
      .reset(reset),
      .start(done_shake256_squeezeblocks),
      .len(len),   //256
      .buf_in(linear_buf), // 840 bytes
      .buflen(buflen),     // 840
      .a_out(a_out),
      .ctr(ctr),
      .done(done_rej_eta)
  );

  localparam SIZE = 3;
  localparam IDLE = 3'd0, PRE_RD_INP = 3'd1, RD_INP = 3'd2;

  reg [SIZE-1:0] state;
  reg [SIZE-1:0] next_state;

  always @(posedge clock) begin
    if (reset == 1'b1) begin
      state <= IDLE;
    end else begin
      state <= next_state;
    end
  end

  always @(*) begin
    case (state)
      IDLE: begin
        done = 0;
        start_dilithium_shake256_stream_init = 0;
        next_state = PRE_RD_INP;
      end
      PRE_RD_INP: begin
        done = 0;
        start_dilithium_shake256_stream_init = 0;
        if (start == 1'b1) begin
          next_state = RD_INP;
        end else begin
          next_state = PRE_RD_INP;
        end
      end
      RD_INP: begin
        done = 0;
        if (done_rej_eta) begin
          next_state = RD_INP;
          start_dilithium_shake256_stream_init = 0;
        end else begin
          start_dilithium_shake256_stream_init = 1;
          next_state = 3;
        end
      end
      3: begin
        if (done_rej_eta) begin
          done = 1;
          if (~start) begin
            start_dilithium_shake256_stream_init = 0;
            next_state = IDLE;
          end else begin
            start_dilithium_shake256_stream_init = 1;
            next_state = 3;
          end
        end else begin
          done = 0;
          start_dilithium_shake256_stream_init = 1;
          next_state = 3;
        end
      end
    endcase
  end

endmodule

