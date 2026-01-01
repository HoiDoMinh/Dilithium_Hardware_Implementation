module shake256_squeezeblocks #(
    parameter MAX_NBLOCKS   = 5,      // s? block t?i ?a, ch?n tùy module
    parameter SHAKE256_RATE = 136     // 136 bytes / block
)(
    input  clock,
    input  reset,
    input  start,
    input  [1599:0] state_s_in,
    input  [63:0]   nblocks,   // s? block th?c s? c?n squeeze (<= MAX_NBLOCKS)
    output [(SHAKE256_RATE*8*MAX_NBLOCKS)-1:0] out,
    output [1599:0] state_s_out,
    output done
);

    localparam OUTLEN = SHAKE256_RATE * 8 * MAX_NBLOCKS;  // s? bit c?a out

    keccak_squeezeblocks #(.outlen(OUTLEN)) keccak_squeezeblocks_inst (
        .clock (clock),
        .reset (reset),
        .start (start),
        .nblocks (nblocks),          // keccak_squeezeblocks s? x? lý nblocks block
        .s_in  (state_s_in),
        .r     (SHAKE256_RATE),
        .out   (out),
        .s_out (state_s_out),
        .done  (done)
    );

endmodule

