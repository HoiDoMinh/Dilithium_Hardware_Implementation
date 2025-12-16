module polyveck_make_hint(
    input  signed [49151:0] v0_in,   // K=6 polys, each 256 coeffs × 32-bit
    input  signed [49151:0] v1_in,
    output [49151:0] h_out
);
    localparam K = 6;
    
    // Unpack vector inputs
    wire signed [8191:0] v0 [0:K-1];
    wire signed [8191:0] v1 [0:K-1];
    wire [8191:0] h [0:K-1];
    
    genvar i;
    generate
        for (i = 0; i < K; i = i + 1) begin : polyvec_loop
            // Unpack inputs
            assign v0[i] = v0_in[8192*i + 8191 : 8192*i];
            assign v1[i] = v1_in[8192*i + 8191 : 8192*i];
            

            poly_make_hint poly_make_hint_inst (
                .a0_in(v0[i]),
                .a1_in(v1[i]),
                .h_out(h[i])
            );
            
            assign h_out[8192*i + 8191 : 8192*i] = h[i];
        end
    endgenerate

endmodule