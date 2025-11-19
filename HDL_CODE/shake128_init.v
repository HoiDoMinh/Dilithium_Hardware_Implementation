
module shake128_init(
    output [1599:0] state_s,
    output [31:0] state_pos
    );
    
    keccak_init keccak_init(
	   	.s(state_s)
	   	);
	
    assign state_pos = 0;
	
endmodule