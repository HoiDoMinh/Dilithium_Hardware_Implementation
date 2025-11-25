module polyt0_unpack(
    input  [3327:0] a_in,     // 416 bytes (13 * 32 blocks)
    output [8191:0] r_out     // 256 coeff × 32-bit signed
);
    localparam N = 256;
    localparam D = 13;

    genvar i;
    generate
        for (i = 0; i < N/8; i = i + 1) begin : unpack_loop

            // 13 bytes input per block
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

            wire [12:0] t0 = ({b1[4:0], b0});                                 // coeff0
            wire [12:0] t1 = ({b3, b2, b1[7:5]});                              // coeff1
            wire [12:0] t2 = ({b4[1:0], b3[7:2]});                             // coeff2
            wire [12:0] t3 = ({b6, b5, b4[7:2]});                              // coeff3
            wire [12:0] t4 = ({b8, b7, b6[7:4]});                              // coeff4
            wire [12:0] t5 = ({b9[6:0], b8[7:1]});                             // coeff5
            wire [12:0] t6 = ({b11, b10, b9[7:6]});                            // coeff6
            wire [12:0] t7 = ({b12[7:0], b11[7:3]});                           // coeff7

            //coeff = 4096 - t
            wire signed [31:0] c0 = 32'sd4096 - t0;
            wire signed [31:0] c1 = 32'sd4096 - t1;
            wire signed [31:0] c2 = 32'sd4096 - t2;
            wire signed [31:0] c3 = 32'sd4096 - t3;
            wire signed [31:0] c4 = 32'sd4096 - t4;
            wire signed [31:0] c5 = 32'sd4096 - t5;
            wire signed [31:0] c6 = 32'sd4096 - t6;
            wire signed [31:0] c7 = 32'sd4096 - t7;

            // assign output 
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

