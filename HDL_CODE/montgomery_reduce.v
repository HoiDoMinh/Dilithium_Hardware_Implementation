module montgomery_reduce (
    input  signed [63:0] a,
    output signed [31:0] t
);
    localparam signed [31:0] Q    = 32'sd8380417;
    localparam signed [31:0] QINV = 32'sd58728449;
    
    // Logic t? h?p thu?n túy (Combinational Logic)
    wire signed [31:0] a_low = a[31:0];
    wire signed [63:0] u     = a_low * QINV;
    wire signed [31:0] u_low = u[31:0];
    wire signed [63:0] v     = u_low * Q;
    
    assign t = (a - v) >>> 32; // Dùng >>> ?? shift có d?u (Arithmetic Shift)
endmodule