module polyveck_make_hint(
    input  signed [49151:0] v0_in,
    input  signed [49151:0] v1_in,
    output [49151:0]        h_out,
    output [31:0]           count
);
    localparam K = 6;

    wire signed [8191:0] v0 [0:K-1];
    wire signed [8191:0] v1 [0:K-1];
    wire        [8191:0] h  [0:K-1];
    wire [8:0]           s  [0:K-1];

    genvar i;
    generate
        for (i = 0; i < K; i = i + 1) begin : GEN_VEC
            assign v0[i] = v0_in[8192*i + 8191 : 8192*i];
            assign v1[i] = v1_in[8192*i + 8191 : 8192*i];

            poly_make_hint u_poly_make_hint (
                .a0_in (v0[i]),
                .a1_in (v1[i]),
                .h_out (h[i]),
                .count (s[i])
            );

            assign h_out[8192*i + 8191 : 8192*i] = h[i];
        end
    endgenerate

    assign count = s[0] + s[1] + s[2] + s[3] + s[4] + s[5];

endmodule
