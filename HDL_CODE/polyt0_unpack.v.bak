module polyt0_unpack(
    input  [3327:0] a_in,      // 416 bytes
    output [8191:0] r_out      // 256 coeff x 32-bit
);
    localparam N = 256;
    localparam D = 13;

    genvar i;
    generate
        for (i = 0; i < N/8; i = i + 1) begin : unpack_loop

            // Extract 13 bytes
            wire [7:0] b0  = a_in[8*(13*i+ 0) + 7 : 8*(13*i+ 0)];
            wire [7:0] b1  = a_in[8*(13*i+ 1) + 7 : 8*(13*i+ 1)];
            wire [7:0] b2  = a_in[8*(13*i+ 2) + 7 : 8*(13*i+ 2)];
            wire [7:0] b3  = a_in[8*(13*i+ 3) + 7 : 8*(13*i+ 3)];
            wire [7:0] b4  = a_in[8*(13*i+ 4) + 7 : 8*(13*i+ 4)];
            wire [7:0] b5  = a_in[8*(13*i+ 5) + 7 : 8*(13*i+ 5)];
            wire [7:0] b6  = a_in[8*(13*i+ 6) + 7 : 8*(13*i+ 6)];
            wire [7:0] b7  = a_in[8*(13*i+ 7) + 7 : 8*(13*i+ 7)];
            wire [7:0] b8  = a_in[8*(13*i+ 8) + 7 : 8*(13*i+ 8)];
            wire [7:0] b9  = a_in[8*(13*i+ 9) + 7 : 8*(13*i+ 9)];
            wire [7:0] b10 = a_in[8*(13*i+10) + 7 : 8*(13*i+10)];
            wire [7:0] b11 = a_in[8*(13*i+11) + 7 : 8*(13*i+11)];
            wire [7:0] b12 = a_in[8*(13*i+12) + 7 : 8*(13*i+12)];
            
            // t0: bits 0-12 (8 bits from b0, 5 bits from b1)
            wire [12:0] t0 = {b1[4:0], b0};
            
            // t1: bits 13-25 (3 bits from b1, 8 bits from b2, 2 bits from b3)
            wire [12:0] t1 = {b3[1:0], b2, b1[7:5]};
            
            // t2: bits 26-38 (6 bits from b3, 7 bits from b4)
            wire [12:0] t2 = {b4[6:0], b3[7:2]};
            
            // t3: bits 39-51 (1 bit from b4, 8 bits from b5, 4 bits from b6)
            wire [12:0] t3 = {b6[3:0], b5, b4[7]};
            
            // t4: bits 52-64 (4 bits from b6, 8 bits from b7, 1 bit from b8)
            wire [12:0] t4 = {b8[0], b7, b6[7:4]};
            
            // t5: bits 65-77 (7 bits from b8, 6 bits from b9)
            wire [12:0] t5 = {b9[5:0], b8[7:1]};
            
            // t6: bits 78-90 (2 bits from b9, 8 bits from b10, 3 bits from b11)
            wire [12:0] t6 = {b11[2:0], b10, b9[7:6]};
            
            // t7: bits 91-103 (5 bits from b11, 8 bits from b12)
            wire [12:0] t7 = {b12, b11[7:3]};

            // Calculate coefficients: 4096 - t (Using 32-bit signed arithmetic)
            // L?u ý: 32'sd4096 là s? d??ng, t là unsigned 13-bit, k?t qu? có th? âm
            wire signed [31:0] c0 = 32'sd4096 - {19'd0, t0};
            wire signed [31:0] c1 = 32'sd4096 - {19'd0, t1};
            wire signed [31:0] c2 = 32'sd4096 - {19'd0, t2};
            wire signed [31:0] c3 = 32'sd4096 - {19'd0, t3};
            wire signed [31:0] c4 = 32'sd4096 - {19'd0, t4};
            wire signed [31:0] c5 = 32'sd4096 - {19'd0, t5};
            wire signed [31:0] c6 = 32'sd4096 - {19'd0, t6};
            wire signed [31:0] c7 = 32'sd4096 - {19'd0, t7};

            // Assign output
            assign r_out[32*(8*i+0) + 31 : 32*(8*i+0)] = c0;
            assign r_out[32*(8*i+1) + 31 : 32*(8*i+1)] = c1;
            assign r_out[32*(8*i+2) + 31 : 32*(8*i+2)] = c2;
            assign r_out[32*(8*i+3) + 31 : 32*(8*i+3)] = c3;
            assign r_out[32*(8*i+4) + 31 : 32*(8*i+4)] = c4;
            assign r_out[32*(8*i+5) + 31 : 32*(8*i+5)] = c5;
            assign r_out[32*(8*i+6) + 31 : 32*(8*i+6)] = c6;
            assign r_out[32*(8*i+7) + 31 : 32*(8*i+7)] = c7;
        end
    endgenerate

endmodule
