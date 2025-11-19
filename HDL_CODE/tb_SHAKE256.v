`timescale 1ns / 1ps
`include "byte_and_print.vh"

module tb_SHAKE256;
    parameter r      = 1088;     // rate
    parameter c      = 512;      // capacity
    parameter len    = 272;      // 34 bytes input
    parameter outlen = 1023;     // 128 bytes output (0..1023)

    reg  [len-1:0] in;
    reg  clk, reset, start;
    wire done;
    wire [outlen:0] SHAKEout;          // 1024 bits


    SHAKE256 #(.r(r), .c(c), .outlen(outlen), .len(len)) dut (
        .in(in),
        .clk(clk),
        .reset(reset),
        .start(start),
        .done(done),
        .SHAKEout(SHAKEout)
    );


    wire [7:0] SHAKEout_t      [0:127];   
    wire [7:0] SHAKEout_inv_t  [0:127]; 
    wire [7:0] seed_in_t       [0:33];    

    integer i;

    `BYTE_ASSIGN_GEN(shakeout,     128, SHAKEout,      SHAKEout_t)

    wire [outlen:0] SHAKEout_inv;        // bus ??o byte (1024 bit)

    genvar x;
    generate
        for (x = 0; x < 128; x = x + 1) begin: INV_BYTES
            assign SHAKEout_inv[8*x + 7 : 8*x] = SHAKEout[8*(127 - x) + 7 : 8*(127 - x)];
        end
    endgenerate

    `BYTE_ASSIGN_GEN(shakeout_inv, 128, SHAKEout_inv,  SHAKEout_inv_t)
    `BYTE_ASSIGN_GEN(in,           34,  in,            seed_in_t)

    // Clock
    always #5 clk = ~clk;

    // Reset task
    task do_reset;
    begin
        reset = 1;
        start = 0;
        in    = 0;
        #50;
        reset = 0;
        #20;
    end
    endtask

    // Test task
    task run_test;
        input [len-1:0] msg;
    begin
        do_reset();

        in = msg;        // n?p input
        #10;

        start = 1; #10;
        start = 0;

        wait(done == 1);
        #10;

        `PRINT_HEX_ARRAY("SEED input", seed_in_t, 34)
        `PRINT_HEX_ARRAY("SHAKE256 output (inverse bytes)", SHAKEout_inv_t, 128)
        $write("rho      = ");
        for (i = 0; i < 32; i = i + 1) begin
            $write("%02x ", SHAKEout_inv_t[i]);
        end
        $write("\n");

        $write("rhoprime = ");
        for (i = 32; i < 96; i = i + 1) begin
            $write("%02x ", SHAKEout_inv_t[i]);
        end
        $write("\n");

        $write("key      = ");
        for (i = 96; i < 128; i = i + 1) begin
            $write("%02x ", SHAKEout_inv_t[i]);
        end
        $write("\n\n");

        #40;
    end
    endtask

    // Initial
    initial begin
        clk = 0; reset = 1; start = 0; in = 0;

        #50;
        reset = 0;
        #30;
        //run_test(272'h05066cb904fd193372ca57ec0a8164f83d49ee17db2c908a6fb2415dc80377af129e);
        //run_test(272'h05063cf04f5a8e187122cd0b5099aa332f7d906c01fe1144d9a30e551988ccf37a12);
	run_test(272'h0506bc9a78563412ffeeddccbbaafedcba9876543210efcdab8967452301efbeadde);
	//run_test(272'h050678695a4b3c2d1e0f1032547698badcfeffeeddccbbaa99887766554433221100);
        //run_test(272'h050600f187396a5c4d2f117e99c0bba956103cde89f4023064770dacee914217b35e);
        #100;
        $finish;
    end

    // Timeout
    initial begin
        #200000;
        $display("\n[ERROR] SIMULATION TIMEOUT!\n");
        $finish;
    end

endmodule

