
module polyveck_power2round(
    input signed [49151:0] v_in,
    output signed [49151:0] v1_out,
    output signed [49151:0] v0_out
    );
    
    localparam K = 6;
    
    wire signed [8191:0] v [0:K - 1];
    wire signed [8191:0] v0 [0:K - 1];
    wire signed [8191:0] v1 [0:K - 1];
    
    generate
        genvar x;
        for (x = 0; x < K; x = x + 1) begin
    	    assign v[x] = v_in[8192 * x + 8191:8192 * x];
    	    poly_power2round poly_power2round(.a_in(v[x]),.a0_out(v0[x]),.a1_out(v1[x]));
    	    assign v0_out[8192 * x + 8191:8192 * x] = v0[x];
    	    assign v1_out[8192 * x + 8191:8192 * x] = v1[x]; 
        end
    endgenerate
	
endmodule