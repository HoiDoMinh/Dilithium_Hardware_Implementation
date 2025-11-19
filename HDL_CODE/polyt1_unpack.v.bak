
module polyt1_unpack(
    input  [2559:0] linear_a,        // 320 bytes = 2560 bits
    output [8191:0] linear_r         // 256 coeff × 32-bit slot (ch? dùng 10 bit th?p)
    );

    localparam N = 256;

    generate
        genvar i;
        for (i = 0; i < N/4; i = i + 1) begin : unpack_loop

            // L?y 5 byte t? linear_a
            // linear_a[7:0] = byte 0, little endian nh? C
            wire [7:0] a0 = linear_a[8*(5*i+0) + 7 : 8*(5*i+0)];
            wire [7:0] a1 = linear_a[8*(5*i+1) + 7 : 8*(5*i+1)];
            wire [7:0] a2 = linear_a[8*(5*i+2) + 7 : 8*(5*i+2)];
            wire [7:0] a3 = linear_a[8*(5*i+3) + 7 : 8*(5*i+3)];
            wire [7:0] a4 = linear_a[8*(5*i+4) + 7 : 8*(5*i+4)];

            // Gi?i nén ?úng theo C (mask 10-bit: & 0x3FF)
            wire [9:0] r0 = ((a0 >> 0) | (a1 << 8)) & 10'h3FF;
            wire [9:0] r1 = ((a1 >> 2) | (a2 << 6)) & 10'h3FF;
            wire [9:0] r2 = ((a2 >> 4) | (a3 << 4)) & 10'h3FF;
            wire [9:0] r3 = ((a3 >> 6) | (a4 << 2)) & 10'h3FF;

            // Gán vào linear_r (??u ra 32-bit/coeff)
            assign linear_r[32*(4*i+0) + 9  : 32*(4*i+0)] = r0;
            assign linear_r[32*(4*i+1) + 9  : 32*(4*i+1)] = r1;
            assign linear_r[32*(4*i+2) + 9  : 32*(4*i+2)] = r2;
            assign linear_r[32*(4*i+3) + 9  : 32*(4*i+3)] = r3;

            // Các bit cao h?n 9 c?a m?i coeff = 0
            assign linear_r[32*(4*i+0) + 31 : 32*(4*i+0) + 10] = 0;
            assign linear_r[32*(4*i+1) + 31 : 32*(4*i+1) + 10] = 0;
            assign linear_r[32*(4*i+2) + 31 : 32*(4*i+2) + 10] = 0;
            assign linear_r[32*(4*i+3) + 31 : 32*(4*i+3) + 10] = 0;

        end
    endgenerate

endmodule
