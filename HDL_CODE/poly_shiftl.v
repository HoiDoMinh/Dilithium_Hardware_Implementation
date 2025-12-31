module poly_shiftl(
    input  signed [8191:0] a_in,
    output signed [8191:0] a_out
);
    
    localparam N = 256;
    localparam D = 13;
    
    wire signed [31:0] a [0:N-1];
    wire signed [31:0] t [0:N-1];
    
    generate
        genvar x;
        for (x = 0; x < N; x = x + 1) begin : shiftl_loop
            assign a[x] = a_in[32*x + 31 : 32*x];
            
            assign t[x] = a[x] <<< D;
           
            assign a_out[32*x + 31 : 32*x] = t[x];
        end
    endgenerate
    
endmodule
