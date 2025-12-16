module polyeta_unpack (
    input  [1023:0] a_in,
    output [8191:0]  r_out
);
    localparam N = 256;
    localparam signed [31:0] ETA_S = 32'sd4;

    genvar i;
    generate
      for (i = 0; i < N/2; i = i + 1) begin : unpack_loop
        wire [7:0] byte_i = a_in[8*i + 7 : 8*i];

        wire [3:0] t0 = byte_i[3:0];
        wire [3:0] t1 = byte_i[7:4];

        wire signed [31:0] coeff0 = ETA_S - $signed({28'd0, t0});
        wire signed [31:0] coeff1 = ETA_S - $signed({28'd0, t1});

        assign r_out[32*(2*i+0) +: 32] = coeff0;
        assign r_out[32*(2*i+1) +: 32] = coeff1;
      end
    endgenerate
endmodule

