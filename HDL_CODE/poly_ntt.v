
module poly_ntt (
    input clock,
    input reset,
    input start,
    input signed [8191:0] poly_in,   // 256 × 32-bit
    output signed [8191:0] poly_out,
    output done
);
    parallel_ntt_32bit u_ntt (
        .clock(clock),
        .reset(reset),
        .start(start),
        .inp(poly_in),
        .out(poly_out),
        .done(done)
    );
endmodule
