
module shake256_finalize(
    input clock,
    input reset,
    input start,
    input [1599:0] state_s_in,
    input [31:0] state_pos_in,
    output [1599:0] state_s_out,
    output [31:0] state_pos_out,
    output done
    );
    
    localparam SHAKE256_RATE = 136;
    localparam p = 8'd31;
    
    keccak_finalize keccak_finalize(
	   	.clock(clock),
	   	.reset(reset),
	   	.start(start),
	   	.s_in(state_s_in),
	   	.pos(state_pos_in),
	   	.r(SHAKE256_RATE),
	   	.p(p),
	   	.s_out(state_s_out),
	   	.done(done)
	   	);
	   	
	assign state_pos_out = SHAKE256_RATE;
	   	
endmodule








module shake128_finalize(
    input clock,
    input reset,
    input start,
    input [1599:0] state_s_in,
    input [31:0] state_pos_in,
    output [1599:0] state_s_out,
    output [31:0] state_pos_out,
    output done
    );
    
    localparam SHAKE128_RATE = 168;
    localparam p = 8'd31;
    
    keccak_finalize keccak_finalize(
	   	.clock(clock),
	   	.start(start),
	   	.reset(reset),
	   	.s_in(state_s_in),
	   	.pos(state_pos_in),
	   	.r(SHAKE128_RATE),
	   	.p(p),
	   	.s_out(state_s_out),
	   	.done(done)
	   	);
	   	
	assign state_pos_out = SHAKE128_RATE;
	   	
endmodule
module shake128_finalize(
    input clock,
    input reset,
    input start,
    input [1599:0] state_s_in,
    input [31:0] state_pos_in,
    output [1599:0] state_s_out,
    output [31:0] state_pos_out,
    output done
    );
    
    localparam SHAKE128_RATE = 168;
    localparam p = 8'd31;
    
    keccak_finalize keccak_finalize(
	   	.clock(clock),
	   	.start(start),
	   	.reset(reset),
	   	.s_in(state_s_in),
	   	.pos(state_pos_in),
	   	.r(SHAKE128_RATE),
	   	.p(p),
	   	.s_out(state_s_out),
	   	.done(done)
	   	);
	   	
	assign state_pos_out = SHAKE128_RATE;
	   	
endmodule