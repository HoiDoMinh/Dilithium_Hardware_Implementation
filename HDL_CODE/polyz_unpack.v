module polyz_unpack(
    input  [5119:0] a_in,     // 640 bytes = 5120 bits (little-endian, byte 0 = a_in[7:0])
    output [8191:0] r_out     // 256 coeff × 32-bit signed
);
    localparam N       = 256;
    localparam GAMMA1  = (1 << 19);  // 524288

    genvar i;
    generate
        for (i = 0; i < N/2; i = i + 1) begin : unpack_loop
            // C: a[5*i + k]
            wire [7:0] a0 = a_in[(5*i+0)*8 +: 8];
            wire [7:0] a1 = a_in[(5*i+1)*8 +: 8];
            wire [7:0] a2 = a_in[(5*i+2)*8 +: 8];
            wire [7:0] a3 = a_in[(5*i+3)*8 +: 8];
            wire [7:0] a4 = a_in[(5*i+4)*8 +: 8];

            // coeff0 = (a0) | (a1 << 8) | (a2 << 16) & 0xFFFFF
            wire [19:0] coeff0_20 = {a2[3:0], a1, a0};

            // coeff1 = (a2 >> 4) | (a3 << 4) | (a4 << 12)
            wire [19:0] coeff1_20 = {a4, a3, a2[7:4]};

            wire signed [31:0] t0 = GAMMA1 - coeff0_20;
            wire signed [31:0] t1 = GAMMA1 - coeff1_20;

            assign r_out[32*(2*i+0) +: 32] = t0;
            assign r_out[32*(2*i+1) +: 32] = t1;

        end
    endgenerate

endmodule

