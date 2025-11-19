
module polyvec_matrix_expand (
    input clock,
    input reset,
    input start,
    input [255:0] rho_in,
    output signed [65535:0] mat1,
    output signed [65535:0] mat2,
    output signed [65535:0] mat3,
    output signed [49151:0] mat4,
    output reg done
);

  localparam K = 6;
  localparam L = 5;

  reg [2:0] i;
  reg [2:0] j;

  wire [15:0] nonce = (i << 8) + j;

  reg start_poly_uniform;
  reg [4:0] mat_column_i;

  // Outputs
  wire signed [8191:0] a_out;
  wire done_poly_uniform;

  reg signed [8191:0] mat_column1[0:7];  //[00],[01],[02],[03],[04],[10],[11],[12]
  reg signed [8191:0] mat_column2[0:7];  //[13],[14],[20],[21],[22],[23],[24],[30]
  reg signed [8191:0] mat_column3[0:7];  //[31],[32],[33],[34],[40],[41],[42],[43]
  reg signed [8191:0] mat_column4[0:5];  //[44],[50],[51],[52],[53],[54]

  poly_uniform poly_uniform (
      .clock(clock),
      .reset(reset),
      .start(start_poly_uniform),
      .seed (rho_in),
      .nonce(nonce),
      .a_out(a_out),
      .done (done_poly_uniform)
  );

  generate
    genvar x;
    for (x = 0; x < 8; x = x + 1) begin
      assign mat1[8192*x+8191:8192*x] = mat_column1[x];
    end
  endgenerate

  generate
    for (x = 0; x < 8; x = x + 1) begin
      assign mat2[8192*x+8191:8192*x] = mat_column2[x];
    end
  endgenerate

  generate
    for (x = 0; x < 8; x = x + 1) begin
      assign mat3[8192*x+8191:8192*x] = mat_column3[x];
    end
  endgenerate

  generate
    for (x = 0; x < 6; x = x + 1) begin
      assign mat4[8192*x+8191:8192*x] = mat_column4[x];
    end
  endgenerate

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
        start_poly_uniform = 0;
        next_state = PRE_RD_INP;
      end
      PRE_RD_INP: begin
        done = 0;
        start_poly_uniform = 0;
        if (start == 1'b1) begin
          next_state = RD_INP;
        end else begin
          next_state = PRE_RD_INP;
        end
      end
      RD_INP: begin
        done = 0;
        start_poly_uniform = 0;
        next_state = 3;
      end
      3: begin
        done = 0;
        start_poly_uniform = 1;
        next_state = 4;
      end
      4: begin
        done = 0;
        if (done_poly_uniform) begin
          if (~(i + 1 == K && j + 1 == L)) next_state = 3;
          else next_state = 5;
          start_poly_uniform = 0;
        end else begin
          next_state = 4;
          start_poly_uniform = 1;
        end
      end
      5: begin
        done = 1;
        start_poly_uniform = 0;
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
        i <= 0;
        j <= 0;
        mat_column_i <= 0;
      end
      3: begin
      end
      4: begin
        if (done_poly_uniform) begin
          if (mat_column_i < 8) mat_column1[mat_column_i] <= a_out;
          else if (mat_column_i < 16) mat_column2[mat_column_i-8] <= a_out;
          else if (mat_column_i < 24) mat_column3[mat_column_i-16] <= a_out;
          else mat_column4[mat_column_i-24] <= a_out;
          mat_column_i <= mat_column_i + 1;
          if (j + 1 == L) begin
            i <= i + 1;
            j <= 0;
          end else j <= j + 1;
        end
      end
      5: begin
      end
    endcase
  end
endmodule
