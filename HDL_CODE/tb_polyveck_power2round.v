`timescale 1ns/1ps
`include "byte_and_print.vh"
module tb_polyveck_power2round;
    reg signed [49151:0] v_in;
    wire signed [49151:0] v0_out, v1_out;
    
    polyveck_power2round dut(v_in, v1_out, v0_out);
    
    integer i;
    reg signed [31:0] a, a0, a1;
    
    initial begin
        for (i = 0; i < 1536; i = i + 1) begin
            case(i % 16)
                0:  v_in[32*i+:32] = 0;
                1:  v_in[32*i+:32] = 4095;
                2:  v_in[32*i+:32] = 4096;
                3:  v_in[32*i+:32] = 4097;
                4:  v_in[32*i+:32] = 8192;
		5:  v_in[32*i+:32] = 8193;
                6:  v_in[32*i+:32] = 12288;
                7:  v_in[32*i+:32] = -1;
                8:  v_in[32*i+:32] = -4096;
		9:  v_in[32*i+:32] = -4097;
                10:  v_in[32*i+:32] = 50000;
		11:  v_in[32*i+:32] = 100000;
		12:  v_in[32*i+:32] = 8380416;
                default: v_in[32*i+:32] = i;
            endcase
        end
        
        #10;
        
        for (i = 0; i < 13; i = i + 1) begin
            a = v_in[32*i+:32];
            a1 = v1_out[32*i+:32];
            a0 = v0_out[32*i+:32];
            $display("a=%d -> a1=%d, a0=%d",a, a1, a0);
        end
        
        $finish;
    end
endmodule
