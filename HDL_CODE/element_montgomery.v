module element_montgomery (
    input  wire        clk,
    input  signed [31:0] a,
    input  signed [31:0] b,
    output reg  signed [31:0] res
);
    wire signed [63:0] mult_result;
    wire signed [31:0] mont_result;
    
    assign mult_result = a * b;
    
    montgomery_reduce u_mont (
        .a(mult_result),
        .t(mont_result)
    );
    
    // Pipeline register
    always @(posedge clk) begin
        res <= mont_result;
    end
endmodule