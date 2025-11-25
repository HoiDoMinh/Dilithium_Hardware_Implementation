module poly_decompose(
    input  signed [8191:0] a_in,     // 256 coeff × 32-bit
    output signed [8191:0] a1_out,   // 256 coeff
    output signed [8191:0] a0_out
);

    localparam N = 256;

    wire signed [31:0] a  [0:N-1];
    wire signed [31:0] a1 [0:N-1];
    wire signed [31:0] a0 [0:N-1];

    genvar i;
    generate
        for (i = 0; i < N; i = i + 1) begin : DECOMP_LOOP

            assign a[i] = a_in[32*i + 31 : 32*i];

            decompose decompose_inst (
                .a(a[i]),
                .a0(a0[i]),
                .a1(a1[i])
            );

            assign a1_out[32*i + 31 : 32*i] = a1[i];
            assign a0_out[32*i + 31 : 32*i] = a0[i];
        end
    endgenerate

endmodule
