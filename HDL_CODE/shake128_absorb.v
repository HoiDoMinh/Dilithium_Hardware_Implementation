
module shake128_absorb #(parameter in_len = 32)(
    input clock,
    input reset,
    input start,
    input [1599:0] state_s_in,
    input [31:0] state_pos_in,
    input [in_len * 8 - 1:0] in,
    input [63:0] inlen,
    output [1599:0] state_s_out,
    output [31:0] state_pos_out,
    output done
    );
    
    localparam SHAKE128_RATE = 168;

    keccak_absorb #(.in_len(in_len)) keccak_absorb(
	   	.clock(clock),
	   	.start(start),
	   	.reset(reset),
	   	.s_in(state_s_in),
	   	.pos(state_pos_in),
	   	.r(SHAKE128_RATE),
	   	.in(in),
	   	.inlen(inlen),
	   	.s_out(state_s_out),
	   	.i(state_pos_out),
	   	.done(done)
	   	);
	   	
endmodule