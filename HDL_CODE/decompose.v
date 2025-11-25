module decompose(
    input  signed [31:0] a,
    output signed [31:0] a0,
    output signed [31:0] a1
);
    localparam signed Q           = 32'sd8380417;
    localparam signed GAMMA2      = (Q-1)/32;       // 261887
    localparam signed TWO_GAMMA2  = 2*GAMMA2;       // 523774
    localparam signed HALF_Q      = (Q-1)/2;        // 4190208

    wire signed [31:0] temp1 = (a + 32'sd127) >>> 7;
    wire signed [31:0] temp2 = (temp1 * 32'sd1025 + 32'sd2097152) >>> 22;

    assign a1 = temp2 & 32'sd15;

    wire signed [31:0] temp_a0 = a - (a1 * TWO_GAMMA2);

    assign a0 = temp_a0 - (((HALF_Q - temp_a0) >>> 31) & Q);

endmodule

