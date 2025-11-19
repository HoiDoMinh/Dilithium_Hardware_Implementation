
module polyveck_caddq(
    input signed [49151:0] v_in,
    output signed [49151:0] v_out
	);
    
    localparam K = 6;
    
    wire signed [8191:0] v_in_temp  [0:K - 1];
    wire signed [8191:0] v_out_temp [0:K - 1];
    
    generate
        genvar x;
        for (x = 0; x < K; x = x + 1) begin
		    assign v_in_temp[x] = v_in[8192 * x + 8191:8192 * x];
		    poly_caddq poly_caddq(.a_in(v_in_temp[x]), .a_out(v_out_temp[x]));
		    assign v_out[8192 * x + 8191:8192 * x] = v_out_temp[x];
		end
	endgenerate
	
endmodule