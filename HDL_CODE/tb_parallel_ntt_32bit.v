`timescale 1ns / 1ps

module tb_parallel_ntt_32bit;
    reg clock;
    reg reset;
    reg start;
    reg signed [0:8191] inp; // 256 he so 32-bit
    wire done;
    wire signed [0:8191] out;

    integer i;

    parallel_ntt_32bit uut (
        .clock(clock),
        .reset(reset),
        .start(start),
        .inp(inp),
        .done(done),
        .out(out)
    );


    initial clock = 0;
    always #5 clock = ~clock; // 100MHz


    initial begin


        // Kh?i t?o
        reset = 1;
        start = 0;
        inp = 0;
        #20;
        reset = 0;

        // [1,2,3,...,256]
        for (i = 0; i < 256; i = i + 1) begin
            inp[(i*32) +: 32] = i + 1;
        end
        #10;
        start = 1;

        wait(done == 1);
        #10;


        for (i = 0; i < 256; i = i + 1) begin
            $display("out[%0d] = %0d", i, $signed(out[(i*32) +: 32]));
        end

        #50;
        $finish;
    end
endmodule
