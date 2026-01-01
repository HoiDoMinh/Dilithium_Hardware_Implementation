

module polyvecl_uniform_eta (
    input clock,
    input reset,
    input start,
    input [511:0] seed,
    input [15:0] nonce,
    output signed [40959:0] v_out,   //5 da thuc 5*8192 = 40960
    output reg done
);

  localparam L = 5;

  reg start_poly_uniform_eta;
  reg [4:0] linear_v_i;

  // Outputs
  wire [8191:0] linear_a;
  wire done_poly_uniform_eta;

  reg signed[8191:0] v[0:4];

  reg [15:0] nonce_reg;

  poly_uniform_eta poly_uniform_eta (
      .clock(clock),
      .reset(reset),
      .start(start_poly_uniform_eta),
      .seed(seed),
      .nonce(nonce_reg),
      .a_out(linear_a),
      .done(done_poly_uniform_eta)
  );

  generate
    genvar x;
    for (x = 0; x < 5; x = x + 1) begin
      assign v_out[8192*x+8191:8192*x] = v[x];
    end
  endgenerate

  reg [2:0] i;

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
        start_poly_uniform_eta = 0;
        next_state = PRE_RD_INP;
      end
      PRE_RD_INP: begin
        done = 0;
        start_poly_uniform_eta = 0;
        if (start == 1'b1) begin
          next_state = RD_INP;
        end else begin
          next_state = PRE_RD_INP;
        end
      end
      RD_INP: begin
        done = 0;
        start_poly_uniform_eta = 0;
        next_state = 3;
      end
      3: begin
        done = 0;
        next_state = 4;
        start_poly_uniform_eta = 1;
      end
      4: begin
        done = 0;
        if (done_poly_uniform_eta) begin
          start_poly_uniform_eta = 0;
          if (i + 1 < L) begin
            next_state = 3;
          end else begin
            next_state = 5;
          end
        end else begin
          start_poly_uniform_eta = 1;
          next_state = 4;
        end
      end
      5: begin
        done = 1;
        if (~start) begin
          next_state = IDLE;
        end else begin
          next_state = 5;
        end
      end
    endcase
  end

  always @(posedge clock) begin
    case (state)
      2: begin
        i <= 0;
        nonce_reg <= nonce;
        linear_v_i <= 0;
      end
      4: begin
        if (done_poly_uniform_eta) begin
          v[linear_v_i] <= linear_a;
          linear_v_i <= linear_v_i + 1;
          nonce_reg <= nonce_reg + 1;
          i <= i + 1;
        end
      end
    endcase
  end

endmodule
