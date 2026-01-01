//Matrix * vector (NTT)
module polyvec_matrix_pointwise_montgomery (
    input clock,
    input reset,
    input start,
    input signed [40959:0] v_in,   // polyvecl v (5 dathuc × 8192b)
    input signed [65535:0] mat1,   // matrix 6*5
    input signed [65535:0] mat2,
    input signed [65535:0] mat3,
    input signed [49151:0] mat4,
    output signed [49151:0] t_out,  // 6 da thuc × 8192b = 49152b
    output reg done
);

  localparam K = 6;

  // Inputs
  reg start_polyvecl_pointwise_acc_montgomery;
  reg signed [40959:0] u_temp;

  // Outputs
  wire signed [8191:0] linear_w;
  wire done_polyvecl_pointwise_acc_montgomery;

  reg signed [8191:0] t[0:K - 1];

  polyvecl_pointwise_acc_montgomery polyvecl_pointwise_acc_montgomery (
      .clock(clock),
      .reset(reset),
      .start(start_polyvecl_pointwise_acc_montgomery),
      .u_in(u_temp),
      .v_in(v_in),
      .w_out(linear_w),
      .done(done_polyvecl_pointwise_acc_montgomery)
  );

  generate
    genvar x;
    for (x = 0; x < K; x = x + 1) begin
      assign t_out[8192*x+8191:8192*x] = t[x];
    end
  endgenerate

  reg [2:0] i;

  always @(*)
    case (i)   //i la hang cua ma tran(6 hang)
      0: u_temp <= mat1[40959:0];
      1: u_temp <= {mat2[16383:0], mat1[65535:40960]};
      2: u_temp <= mat2[57343:16384];
      3: u_temp <= {mat3[32767:0],mat2[65535:57344]};
      4: u_temp <= {mat4[8191:0], mat3[65535:32768]};
      5: u_temp <= mat4[49151:8192];
    endcase

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
        start_polyvecl_pointwise_acc_montgomery = 0;
        next_state = PRE_RD_INP;
      end
      PRE_RD_INP: begin
        done = 0;
        start_polyvecl_pointwise_acc_montgomery = 0;
        if (start == 1'b1) begin
          next_state = RD_INP;
        end else begin
          next_state = PRE_RD_INP;
        end
      end
      RD_INP: begin
        done = 0;
        start_polyvecl_pointwise_acc_montgomery = 0;
        next_state = 3;
      end
      3: begin
        done = 0;
        start_polyvecl_pointwise_acc_montgomery = 1;
        next_state = 4;
      end
      4: begin
        done = 0;
        if (done_polyvecl_pointwise_acc_montgomery) begin
          start_polyvecl_pointwise_acc_montgomery = 0;
          if (i + 1 < K) begin
            next_state = 3;
          end else begin
            next_state = 5;
          end
        end else begin
          start_polyvecl_pointwise_acc_montgomery = 1;
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
      2: i <= 0;
      4: begin
        if (done_polyvecl_pointwise_acc_montgomery) begin
          t[i] <= linear_w;
          i <= i + 1;
        end
      end
    endcase
  end

endmodule
