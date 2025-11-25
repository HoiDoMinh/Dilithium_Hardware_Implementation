module poly_use_hint(
    input  signed [8191:0] a_in,   // 256 coeff × 32-bit
    input         [255:0]  h_in,   // 256 hints (1 bit each)
    output signed [8191:0] b_out   // corrected 256 coeff × 32-bit
);

    localparam N = 256;

    wire signed [31:0] a [0:N-1];
    wire signed [31:0] b [0:N-1];

    genvar i;
    generate
        for (i = 0; i < N; i = i + 1) begin : USE_HINT_LOOP
            assign a[i] = a_in[32*i + 31 : 32*i];

            use_hint use_hint_inst (
                .a(a[i]),
                .hint(h_in[i]),     // 1-bit hint
                .a1_out(b[i])
            );

            assign b_out[32*i + 31 : 32*i] = b[i];
        end
    endgenerate

endmodule
