module PermuteFunction(Ain, Aout, clk, rst);

	input [1599:0] Ain;
	output [1599:0] Aout;
	input clk, rst;

	reg [1599:0] regA;
	reg [2:0] round;

	always @(posedge clk) begin
		if(rst) begin
			regA <= Ain;
			round <= 3'b0;
		end else if(round < 3'b101) begin
			regA <= Aout;
			round <= round + 1;
			
		end
	end

	PermuteFunc_FourRound PermuteFunc_FourRound_u0(.Ain(regA), .Aout(Aout), .round(round));

endmodule