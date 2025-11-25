module polyw1_pack(
    input  [8191:0] a_in,    // 256 coeffs × 32-bit = 8192 bit
    output [1023:0] r_out    // 128 bytes = 1024 bit
);
    localparam N = 256;

    genvar i;
    generate

        // r[i] = a[2*i] | (a[2*i+1] << 4);
        for (i = 0; i < N/2; i = i + 1) begin : pack_loop
            wire [31:0] coeff0 = a_in[32*(2*i+0) + 31 : 32*(2*i+0)];
            wire [31:0] coeff1 = a_in[32*(2*i+1) + 31 : 32*(2*i+1)];

            // w1 ? [0, 15]
            wire [3:0] c0 = coeff0[3:0];
            wire [3:0] c1 = coeff1[3:0];

            // Ghép thành 1 byte: th?p = c0, cao = c1
            wire [7:0] byte_i = {c1, c0};
            assign r_out[8*i + 7 : 8*i] = byte_i;
        end
    endgenerate

endmodule
