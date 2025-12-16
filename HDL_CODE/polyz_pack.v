module polyz_pack(
    input  [8191:0] a_in,       // 256 coeff × 32-bit
    output [5119:0] r_out       // 640 bytes = 5120 bits
);
    localparam N = 256;
    localparam GAMMA1 = (1 << 19);  

    genvar i;
    generate
        for (i = 0; i < N/2; i = i + 1) begin : pack_loop


            wire signed [31:0] a0 = a_in[32*(2*i+0) + 31 : 32*(2*i+0)];
            wire signed [31:0] a1 = a_in[32*(2*i+1) + 31 : 32*(2*i+1)];

            wire [31:0] t0 = GAMMA1 - a0;
            wire [31:0] t1 = GAMMA1 - a1;

     
            wire [7:0] b0 =  t0[7:0];
            wire [7:0] b1 =  t0[15:8];
            wire [7:0] b2 = { t1[3:0], t0[19:16] };// = t0>>16 | (t1<<4)
            wire [7:0] b3 =  t1[11:4];
            wire [7:0] b4 =  t1[19:12];

            assign r_out[8*(5*i+0) + 7 : 8*(5*i+0)] = b0;
            assign r_out[8*(5*i+1) + 7 : 8*(5*i+1)] = b1;
            assign r_out[8*(5*i+2) + 7 : 8*(5*i+2)] = b2;
            assign r_out[8*(5*i+3) + 7 : 8*(5*i+3)] = b3;
            assign r_out[8*(5*i+4) + 7 : 8*(5*i+4)] = b4;

        end
    endgenerate

endmodule
