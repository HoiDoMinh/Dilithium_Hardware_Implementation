
module shake128_squeezeblocks(
    input clock,
    input reset,
    input start,
    input [1599:0] state_s_in,
    input [63:0] nblocks,
    output [6735:0] out,
    output [1599:0] state_s_out,
    output done
    );
    
    localparam SHAKE128_RATE = 168;
    
    keccak_squeezeblocks#(.outlen(6736)) keccak_squeezeblocks(
	   	.clock(clock),
	   	.reset(reset),
        	.start(start),
	   	.nblocks(nblocks),
	   	.s_in(state_s_in),
	   	.r(SHAKE128_RATE),
	   	.out(out),
	   	.s_out(state_s_out),
	   	.done(done)
	   	);
	   	 	
endmodule