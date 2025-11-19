
module poly_power2round(
    input signed [8191:0] a_in,
    output signed [8191:0] a0_out,
    output signed [8191:0] a1_out
    );

    localparam N = 256;

    wire signed [31:0] a_temp [0:255];
    wire signed [31:0] a0_temp  [0:255];
    wire signed [31:0] a1_temp  [0:255];  

	   	
    generate
		genvar x;
		for (x = 0; x < N; x = x + 1) begin
		    assign a_temp[x] = a_in[32 * x + 31:32 * x];
		    power2round power2round(.a(a_temp[x]), .a0(a0_temp[x]), .a1(a1_temp[x]));
		    assign a0_out[32 * x + 31:32 * x] = a0_temp[x]; 
		    assign a1_out[32 * x + 31:32 * x] = a1_temp[x];
		end
	endgenerate

endmodule