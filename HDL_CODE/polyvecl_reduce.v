

module polyvecl_reduce(
    input signed [40959:0] v_in,
    output signed [40959:0] v_out
);
    
    localparam L = 5;
    
    wire signed [8191:0] v_in_t [0:L - 1];
    wire signed [8191:0] v_out_t [0:L - 1];
    
    generate
        genvar x;
        for (x = 0; x < L; x = x + 1) begin
		    assign v_in_t[x] = v_in[8192 * x + 8191:8192 * x];
		    poly_reduce poly_reduce(.a_in(v_in_t[x]), .a_out(v_out_t[x]));
		    assign v_out[8192 * x + 8191:8192 * x] = v_out_t[x];
		end
	endgenerate
	
endmodule