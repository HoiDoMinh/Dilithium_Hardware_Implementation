module poly_ntt (
    input  wire                 clock,
    input  wire                 reset,      // ? Reset t? top module
    input  wire                 start,
    input  wire signed [8191:0] poly_in,
    output reg  signed [8191:0] poly_out,
    output reg                  done
);
    wire signed [8191:0] core_out;
    wire                 core_done;
    reg                  core_start;
    
    parallel_ntt_32bit u_ntt (
        .clock(clock),
        .reset(reset),  // 
        .start(core_start), 
        .inp(poly_in),      
        .out(core_out),
        .done(core_done)
    );

    // FSM
    reg [1:0] state;
    localparam S_IDLE = 2'd0, S_WAIT = 2'd1, S_DONE = 2'd2;

    always @(posedge clock) begin
        if (reset) begin
            // ? Reset toàn b? khi có tín hi?u reset (bao g?m new_nonce_round)
            state      <= S_IDLE;
            poly_out   <= 8192'd0; 
            done       <= 1'b0;
            core_start <= 1'b0;
        end else begin
            case (state)
                S_IDLE: begin
                    done       <= 1'b0;
                    core_start <= 1'b0;
                    if (start) begin
                        core_start <= 1'b1;
                        state      <= S_WAIT;
                    end
                end
                
                S_WAIT: begin
                    core_start <= 1'b0;
                    if (core_done) begin
                        poly_out <= core_out; 
                        done     <= 1'b1;    // ? B?t done cùng lúc l?u output
                        state    <= S_DONE;
                    end
                end
                
                S_DONE: begin
                    done  <= 1'b0;  // ? T?t done sau 1 cycle ?? tránh trigger l?i
                    state <= S_IDLE;
                end
            
                default: state <= S_IDLE;
            endcase
        end
    end
endmodule
