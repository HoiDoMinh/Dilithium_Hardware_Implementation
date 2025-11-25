module polyz_unpack(
    input  [5119:0] a_in,     // 640 bytes = 5120 bit
    output [8191:0] r_out     // 256 coeff × 32-bit
);

    localparam N       = 256;
    localparam GAMMA1  = (1 << 19);  // 524288

    genvar i;

    generate
        for (i = 0; i < N/2; i = i + 1) begin : unpack_loop

            // 
            wire [7:0] a0 = a_in[8*(5*i+0) + 7 : 8*(5*i+0)];
            wire [7:0] a1 = a_in[8*(5*i+1) + 7 : 8*(5*i+1)];
            wire [7:0] a2 = a_in[8*(5*i+2) + 7 : 8*(5*i+2)];
            wire [7:0] a3 = a_in[8*(5*i+3) + 7 : 8*(5*i+3)];
            wire [7:0] a4 = a_in[8*(5*i+4) + 7 : 8*(5*i+4)];

            //  coeff0 = 20 bit,coeff1 = 20 bit
            wire [19:0] coeff0_20 ={a2, a1, a0} & 20'hFFFFF;

            wire [19:0] coeff1_20 =({a4, a3, a2} >> 4);


            wire [31:0] t0 = GAMMA1 - coeff0_20;
            wire [31:0] t1 = GAMMA1 - coeff1_20;

            assign r_out[32*(2*i+0) + 31 : 32*(2*i+0)] = t0;
            assign r_out[32*(2*i+1) + 31 : 32*(2*i+1)] = t1;

        end
    endgenerate

endmodule
