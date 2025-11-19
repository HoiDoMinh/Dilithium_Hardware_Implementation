
module shake256_squeezeblocks(
    input clock,
    input reset,
    input start,
    input [1599:0] state_s_in,
    input [63:0] nblocks,
    output [2175:0] out,
    output [1599:0] state_s_out,
    output done
    );
    
    localparam SHAKE256_RATE = 136;
    
    keccak_squeezeblocks#(.outlen(2176)) keccak_squeezeblocks(
	   	.clock(clock),
	   	.reset(reset),
	   	.start(start),
	   	.nblocks(nblocks),
	   	.s_in(state_s_in),
	   	.r(SHAKE256_RATE),
	   	.out(out),
	   	.s_out(state_s_out),
	   	.done(done)
	   	);
		 	
endmodule