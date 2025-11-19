
module polyvecl_pointwise_acc_montgomery (
    input clock,
    input reset,
    input start,
    input [40959:0] u_in,
    input [40959:0] v_in,
    output reg [8191:0] w_out,
    output reg done
);

  localparam L = 5;

  // Inputs
  reg [8191:0] a_temp;
  reg [8191:0] b_temp;

  wire [8191:0] c_add_temp;

  // Outputs
  wire [8191:0] t_temp;

  wire [8191:0] u[0:L - 1];
  wire [8191:0] v[0:L - 1];

  poly_pointwise_montgomery poly_pointwise_montgomery (
      .a_in (a_temp),
      .b_in (b_temp),
      .c_out(t_temp)
  );

  poly_add poly_add (
      .a_in (w_out),
      .b_in (t_temp),
      .c_out(c_add_temp)
  );

  generate
    genvar x;
    for (x = 0; x < L; x = x + 1) begin
      assign u[x] = u_in[8192*x+8191:8192*x];
      assign v[x] = v_in[8192*x+8191:8192*x];
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
        next_state = PRE_RD_INP;
      end
      PRE_RD_INP: begin
        done = 0;
        if (start == 1'b1) begin
          next_state = RD_INP;
        end else begin
          next_state = PRE_RD_INP;
        end
      end
      RD_INP: begin
        done = 0;
        next_state = 3;
      end
      3: begin
        done = 0;
        next_state = 4;
      end
      4: begin
        done = 0;
        if (i + 1 < L) begin
          next_state = 3;
        end else begin
          next_state = 5;
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
        begin
          i <= 0;
          w_out <= 8192'd0;
        end
      end
      3: begin
        a_temp <= u[i];
        b_temp <= v[i];
      end
      4: begin
        w_out <= c_add_temp;
        i <= i + 1;
      end
    endcase
  end

endmodule
