module use_hint(
    input  signed [31:0] a,
    input         [0:0]  hint,     // 1-bit
    output signed [31:0] a1_out
);

    wire signed [31:0] a0;
    wire signed [31:0] a1;

    decompose decompose_inst(
        .a(a),
        .a0(a0),
        .a1(a1)
    );

    wire signed [31:0] a1_plus  = (a1 + 1) & 32'sd15;
    wire signed [31:0] a1_minus = (a1 - 1) & 32'sd15;

    assign a1_out =(hint == 0) ? a1 :(a0 > 0) ? a1_plus : a1_minus;

endmodule
