module make_hint(
    input  signed [31:0] a0,
    input  signed [31:0] a1,
    output overflow_signal
);

    localparam Q       = 32'd8380417;
    localparam GAMMA2  = (Q-1)/32;        // = 261887 cho Dilithium Mode 3

    assign overflow_signal =(a0 >  GAMMA2) ||(a0 < -GAMMA2) ||((a0 == -GAMMA2) && (a1 != 0));

endmodule

