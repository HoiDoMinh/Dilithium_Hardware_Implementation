`timescale 1ns/1ps
`include "byte_and_print.vh"     

module tb_poly_challenge;

    localparam N            = 256;
    localparam CTILDEBYTES  = 48;
    reg clock;
    reg reset;
    reg start;

    reg  [CTILDEBYTES*8-1:0] seed_in;
    wire [N*32-1:0]          c_out;
    wire                     done;

    integer i;

    wire [7:0] c_bytes [0:N*4 - 1];
    `BYTE_ASSIGN_GEN(cout, N*4, c_out, c_bytes)

    poly_challenge DUT (
        .clock(clock),
        .reset(reset),
        .start(start),
        .seed_in(seed_in),
        .c_out(c_out),
        .done(done)
    );


    initial begin
        clock = 0;
        forever #5 clock = ~clock;
    end

    initial begin

        reset = 1;
        start = 0;
        seed_in = 0;

        #20;
        reset = 0;

        // Set seed gi?ng C-code
        //for (i = 0; i < CTILDEBYTES; i = i + 1)
         //   seed_in[8*i +: 8] = 8'hABCDFF;   
       // #20;
	seed_in=384'h2f2e2d2c2b2a292827262524232221201f1e1d1c1b1a191817161514131211100f0e0d0c0b0a09080706050403020100;

        start = 1;
        #30;
        start = 0;
        wait(done);
        `PRINT_HEX_ARRAY("challenge output", c_bytes, N*4)
        $finish;
    end

    initial begin
        #1000000;
        $display("\n[ERROR] SIMULATION TIMEOUT!!!\n");
        $finish;
    end

endmodule

