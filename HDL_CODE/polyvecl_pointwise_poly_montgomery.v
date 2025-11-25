module polyvecl_pointwise_poly_montgomery(
    input  signed [8191:0] a_in,             // poly a
    input  signed [40959:0] v_in,            // L poly (L=5), m?i poly 8192 bit
    output signed [40959:0] r_out
);
    localparam L = 5;

    wire signed [8191:0] v [0:L-1];
    wire signed [8191:0] r [0:L-1];

    genvar i;
    generate 
        for (i = 0; i < L; i = i + 1) begin : GEN_VEC_L
            // tách t?ng poly v[i]
            assign v[i] = v_in[8192*i + 8191 : 8192*i];

            poly_pointwise_montgomery ppm_inst (
                .a_in(a_in),
                .b_in(v[i]),
                .c_out(r[i])
            );

            assign r_out[8192*i + 8191 : 8192*i] = r[i];
        end
    endgenerate

endmodule

