
module polyvecl_chknorm(
    input  signed [40959:0] v_in,   // 5 polys × 8192 bit
    input  signed [31:0]    B,       // bound
    output                  flag     // 1 = v??t ng??ng, 0 = OK
);

    localparam L=5;

    wire signed [8191:0] poly [0:L-1];
    wire                 chk  [0:L-1];

    wire [L-1:0] chk_vec;

    genvar i;
    generate
        for(i = 0; i < L; i = i + 1) begin : GEN_CHK
            assign poly[i] = v_in[8192*i + 8191 : 8192*i];

            poly_chknorm chk_inst(
                .a_in(poly[i]),
                .B(B),
                .flag(chk[i])
            );

            assign chk_vec[i] = chk[i];   //packed vector
        end
    endgenerate

    // N?u b?t k? poly nào fail ? flag = 1
    assign flag = |chk_vec;

endmodule
