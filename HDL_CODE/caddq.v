
//[0,q)
//out=a+((a<0)?q:0)
module caddq(
    input signed [31:0] a,
    output  signed [31:0] a_out
    );
    wire signed [31:0] temp;
    assign temp = (a >>> 31) & 32'sd8380417;   //a >= 0: a >>> 31 = 32'h00000000 ;a < 0: a >>> 31 = 32'hFFFFFFFF
					       // >>> : dich phai co dau
    assign a_out = a + temp;
endmodule