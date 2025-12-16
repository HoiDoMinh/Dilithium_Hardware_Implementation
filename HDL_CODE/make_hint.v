module make_hint(
    input  signed [31:0] a0,
    input  signed [31:0] a1,
    output                overflow_signal
);
    localparam signed [31:0] Q      = 32'sd8380417;
    localparam signed [31:0] GAMMA2 = (Q-1) / 32;   // 32'sd261887

    wire signed [31:0] negG = -GAMMA2;

    assign overflow_signal =
        (a0 >  GAMMA2) ||
        (a0 <  negG)   ||
        ((a0 == negG) && (a1 != 0));
endmodule

