
module keccak_finalize (
    input clock,
    input reset,
    input start,
    input [1599:0] s_in,
    input [31:0] pos,
    input [31:0] r,
    input [7:0] p,
    output [1599:0] s_out,
    output reg done
);

  wire [63:0] sin_t[0:24];
  reg [63:0] s[0:24];

  generate
    genvar x;
    for (x = 0; x < 25; x = x + 1) begin
      assign sin_t[x] = s_in[64*x+63:64*x];
    end
  endgenerate

  generate
    for (x = 0; x < 25; x = x + 1) begin
      assign s_out[64*x+63:64*x] = s[x];
    end
  endgenerate

  reg [5:0] index = 0;

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
      3: if (index < 25) next_state = RD_INP;
 else next_state = 4;
      4: next_state = 5;
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
      RD_INP: begin
        s[index] <= sin_t[index];
        index <= index + 1;
      end
      4: begin
        s[pos/8] <= sin_t[pos/8] ^ (p << (8 * (pos % 8)));
        s[r/8-1] <= sin_t[r/8-1] ^ (1 << 63);
      end
      5: begin
      end
    endcase
  end

endmodule
