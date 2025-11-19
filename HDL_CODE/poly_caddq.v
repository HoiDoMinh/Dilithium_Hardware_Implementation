
module poly_caddq(
    input signed [8191:0] a_in,
    output signed [8191:0] a_out
    );
    
    localparam N = 256;
    
    wire signed [31:0] a [0:N - 1];
    wire signed [31:0] out [0:N - 1];
   
    generate
        genvar x;
        for (x = 0; x < N; x = x + 1) begin
		    assign a[x] = a_in[32 * x + 31:32 * x];
		    caddq caddq(.a(a[x]), .a_out(out[x]));
		    assign a_out[32 * x + 31:32 * x] = out[x];
		end
	endgenerate
    
endmodule