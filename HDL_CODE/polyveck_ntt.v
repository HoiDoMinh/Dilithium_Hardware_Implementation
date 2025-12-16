
module polyveck_ntt (
    input clock,
    input reset,
    input start,
    input signed [49151:0] v_in,
    output signed [49151:0] v_out,
    output reg done
);

  localparam K = 6;

  wire signed [8191:0] v_in_temp[K - 1:0];
  reg signed [8191:0] v_out_temp[K - 1:0];

  reg signed [8191:0] v_in_reg;
  wire signed [8191:0] v_out_wire;

  reg start_ntt;
  wire done_ntt;

  parallel_ntt_32bit parallel_ntt_32bit (
      .clock(clock),
      .reset(reset),
      .start  (start_ntt),
      .inp  (v_in_reg),
      .out  (v_out_wire),
      .done  (done_ntt)
  );

  generate
    genvar x;
    for (x = 0; x < K; x = x + 1) begin
      assign v_in_temp[x] = v_in[8192*x+8191:8192*x];
      assign v_out[8192*x+8191:8192*x] = v_out_temp[x];
    end
  endgenerate

  localparam SIZE = 3;
  localparam IDLE = 3'd0, PRE_RD_INP = 3'd1, RD_INP = 3'd2;

  reg [SIZE-1:0] state;
  reg [SIZE-1:0] next_state;

  reg [2:0] index;

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
        start_ntt = 0;
        next_state = PRE_RD_INP;
      end
      PRE_RD_INP: begin
        done = 0;
        start_ntt = 0;
        if (start == 1'b1) begin
          next_state = RD_INP;
        end else begin
          next_state = PRE_RD_INP;
        end
      end
      RD_INP: begin
        done = 0;
        start_ntt = 0;
        next_state = 3;
      end
      3: begin
        done = 0;
        start_ntt = 1;
        next_state = 4;
      end
      4: begin
        done = 0;
        if (done_ntt) begin
          if (index + 1 < K) begin
            next_state = 3;
          end else begin
            next_state = 5;
          end
          start_ntt = 0;
        end else begin
          next_state = 4;
          start_ntt = 1;
        end
      end
      5: begin
        done = 1;
        start_ntt = 0;
        if (~start) begin
          next_state = IDLE;
        end else begin
          next_state = 5;
        end
      end
      default: begin
        next_state = IDLE;
      end
    endcase
  end

  always @(posedge clock) begin
    case (state)
      RD_INP: begin
        index <= 0;
      end
      3: begin
        v_in_reg <= v_in_temp[index];
      end
      4: begin
        if (done_ntt) begin
          v_out_temp[index] <= v_out_wire;
          index <= index + 1;
        end
      end
    endcase
  end
endmodule