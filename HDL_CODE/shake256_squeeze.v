module shake256_squeeze #(
    parameter out_len = 32     
)(
    input  clock,
    input  reset,
    input  start,

    input  [1599:0] state_s_in,     // 1600-bit state
    input  [31:0]   state_pos_in,   // pos hien tai
    input  [63:0]   outlen,         

    output [1599:0] state_s_out,    // state sau squeeze
    output [31:0]   state_pos_out, 
    output [out_len*8-1:0] out,     // output bytes
    output done
);

    localparam SHAKE256_RATE = 136;

    keccak_squeeze #(
        .out_len(out_len)
    ) keccak_squeeze_inst (
        .clock     (clock),
        .reset     (reset),
        .start     (start),

        .s_in      (state_s_in),
        .pos_in    (state_pos_in),
        .r         (SHAKE256_RATE),
        .outlen_in (outlen),

        .s_out     (state_s_out),
        .pos_out   (state_pos_out),
        .out       (out),
        .done      (done)
    );

endmodule

