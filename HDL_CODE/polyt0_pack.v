module polyt0_pack(
    input  [8191:0] a_in,     // 256 coeff × 32-bit signed
    output [3327:0] r_out     // 416 bytes
);
    localparam N = 256;
    localparam D = 13;
    
    genvar i;
    generate
        for (i = 0; i < N/8; i = i + 1) begin : pack_loop
            //  Extract 32-bit SIGNED coefficients
            wire signed [31:0] coeff0 = a_in[32*(8*i+0) + 31 : 32*(8*i+0)];
            wire signed [31:0] coeff1 = a_in[32*(8*i+1) + 31 : 32*(8*i+1)];
            wire signed [31:0] coeff2 = a_in[32*(8*i+2) + 31 : 32*(8*i+2)];
            wire signed [31:0] coeff3 = a_in[32*(8*i+3) + 31 : 32*(8*i+3)];
            wire signed [31:0] coeff4 = a_in[32*(8*i+4) + 31 : 32*(8*i+4)];
            wire signed [31:0] coeff5 = a_in[32*(8*i+5) + 31 : 32*(8*i+5)];
            wire signed [31:0] coeff6 = a_in[32*(8*i+6) + 31 : 32*(8*i+6)];
            wire signed [31:0] coeff7 = a_in[32*(8*i+7) + 31 : 32*(8*i+7)];
            

            // t = (1 << 12) - coeff
            wire [31:0] t0_32 = 32'sd4096 - coeff0;
            wire [31:0] t1_32 = 32'sd4096 - coeff1;
            wire [31:0] t2_32 = 32'sd4096 - coeff2;
            wire [31:0] t3_32 = 32'sd4096 - coeff3;
            wire [31:0] t4_32 = 32'sd4096 - coeff4;
            wire [31:0] t5_32 = 32'sd4096 - coeff5;
            wire [31:0] t6_32 = 32'sd4096 - coeff6;
            wire [31:0] t7_32 = 32'sd4096 - coeff7;
            
            // Extract 13-bit unsigned
            wire [12:0] t0 = t0_32[12:0];
            wire [12:0] t1 = t1_32[12:0];
            wire [12:0] t2 = t2_32[12:0];
            wire [12:0] t3 = t3_32[12:0];
            wire [12:0] t4 = t4_32[12:0];
            wire [12:0] t5 = t5_32[12:0];
            wire [12:0] t6 = t6_32[12:0];
            wire [12:0] t7 = t7_32[12:0];
            

            // Pack 8×13-bit thanh 13 bytes
   
            wire [7:0] b0  =  t0[7:0];
            wire [7:0] b1  = ((t0 >>  8) | (t1 << 5)) & 8'hFF;
            wire [7:0] b2  =  (t1 >>  3)              & 8'hFF;
            wire [7:0] b3  = ((t1 >> 11) | (t2 << 2)) & 8'hFF;
            wire [7:0] b4  = ((t2 >>  6) | (t3 << 7)) & 8'hFF;
            wire [7:0] b5  =  (t3 >>  1)              & 8'hFF;
            wire [7:0] b6  = ((t3 >>  9) | (t4 << 4)) & 8'hFF;
            wire [7:0] b7  =  (t4 >>  4)              & 8'hFF;
            wire [7:0] b8  = ((t4 >> 12) | (t5 << 1)) & 8'hFF;
            wire [7:0] b9  = ((t5 >>  7) | (t6 << 6)) & 8'hFF;
            wire [7:0] b10 =  (t6 >>  2)              & 8'hFF;
            wire [7:0] b11 = ((t6 >> 10) | (t7 << 3)) & 8'hFF;
            wire [7:0] b12 =  (t7 >>  5)              & 8'hFF;
            
            //Assign to output
            localparam integer BASE = 13*i;
            assign r_out[8*(BASE+ 0) + 7 : 8*(BASE+ 0)] = b0;
            assign r_out[8*(BASE+ 1) + 7 : 8*(BASE+ 1)] = b1;
            assign r_out[8*(BASE+ 2) + 7 : 8*(BASE+ 2)] = b2;
            assign r_out[8*(BASE+ 3) + 7 : 8*(BASE+ 3)] = b3;
            assign r_out[8*(BASE+ 4) + 7 : 8*(BASE+ 4)] = b4;
            assign r_out[8*(BASE+ 5) + 7 : 8*(BASE+ 5)] = b5;
            assign r_out[8*(BASE+ 6) + 7 : 8*(BASE+ 6)] = b6;
            assign r_out[8*(BASE+ 7) + 7 : 8*(BASE+ 7)] = b7;
            assign r_out[8*(BASE+ 8) + 7 : 8*(BASE+ 8)] = b8;
            assign r_out[8*(BASE+ 9) + 7 : 8*(BASE+ 9)] = b9;
            assign r_out[8*(BASE+10) + 7 : 8*(BASE+10)] = b10;
            assign r_out[8*(BASE+11) + 7 : 8*(BASE+11)] = b11;
            assign r_out[8*(BASE+12) + 7 : 8*(BASE+12)] = b12;
        end
    endgenerate
endmodule