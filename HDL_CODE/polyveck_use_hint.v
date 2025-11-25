module polyveck_use_hint(
    input  signed [49151:0] u_in,   // 6 polys × 8192 bit
    input         [1535:0]  h_in,   // 6 polys × 256 bits 
    output signed [49151:0] w_out
);

    localparam K = 6;
    wire signed [8191:0] u_poly [0:K-1];
    wire        [255:0] h_poly [0:K-1];
    wire signed [8191:0] w_poly [0:K-1];

    genvar i;
    generate
        for (i = 0; i < K; i = i + 1) begin : VECK_LOOP

            // extract each polynomial
            assign u_poly[i] = u_in[8192*i + 8191 : 8192*i];
            assign h_poly[i] = h_in[256*i + 255 : 256*i];

   
            poly_use_hint poly_use_hint_inst (
                .a_in(u_poly[i]),
                .h_in(h_poly[i]),
                .b_out(w_poly[i])
            );

            assign w_out[8192*i + 8191 : 8192*i] = w_poly[i];

        end
    endgenerate

endmodule
