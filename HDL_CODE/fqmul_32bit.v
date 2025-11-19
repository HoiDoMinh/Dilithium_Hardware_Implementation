// nhan 2 so 32bit dung montgomery_reduce_32bit
module fqmul_32bit
    (
    input clock,
    input reset,
    input start,
    input signed [31:0] a,
    input signed [31:0] b,
    output done,
    output  signed [31:0] reduce
    );
    
    localparam SIZE = 1;
    localparam IDLE = 1'd0, CALC = 1'd1;
    
    	reg [SIZE-1:0] state = 1'd0;
	reg [SIZE-1:0] next_state;
	
	reg signed [63:0] mult;
	reg start_montgomery_reduce;
	wire done_montgomery_reduce;
	
	montgomery_reduce_32bit montgomery_reduce_32bit(.clock(clock), .reset(reset), .start(start_montgomery_reduce), .done(done_montgomery_reduce),
	                                                    .a(mult), .t(reduce));	
	assign done = done_montgomery_reduce;
	//fsm change state logic 
	always @(posedge clock)
        begin
            if (reset == 1'b1)
                begin
                    state <= IDLE;
                end
            else
                begin
                    state <= next_state;
                end
        end
    
    always @(*)
        begin
            case(state)
                IDLE:
                    begin
                        if (start == 1'b1)
                            begin
                                next_state = CALC;
                            end
                        else
                            begin
                                next_state = IDLE;
                            end
                    end
                
                CALC:
                    begin
                        if (done_montgomery_reduce == 1'b1)
                            begin
                                next_state = IDLE;
                            end
                        else
                            begin
                                next_state = CALC;
                            end
                    end
                 
                default:
                    begin
                        next_state = IDLE;
                    end
            endcase
        end
    
    always @(posedge clock)
        begin
            case(state)
                IDLE:
                    begin
                        if (start == 1'b1)
                            begin
                                mult <= a * b;
                                start_montgomery_reduce <= 1'b1;
                            end
                    end
                
                CALC:
                    begin
                        start_montgomery_reduce <= 1'b0;
                    end
                
                default:
                    begin
                        mult <= 64'sd0;
                        start_montgomery_reduce <= 1'b0;
                    end
            endcase
        end  
endmodule