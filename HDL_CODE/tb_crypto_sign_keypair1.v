`timescale 1ns/1ps
`include "byte_and_print.vh"

module tb_crypto_sign_keypair1;

    parameter CLK_PERIOD = 10;    // 10 ns

    // DUT signals
    reg clock;
    reg reset;
    reg start_keygen;
    wire done_keygen;
    wire [15615:0] pk;
    wire [32255:0] sk;

    integer cycle_count;
    integer start_cycle;
    integer end_cycle;
    integer latency_cycles;

    wire [7:0] pk_t [0:1951];
    wire [7:0] sk_t [0:4031];

    integer i;

    // DUT
    crypto_sign_keypair dut(
        .clock(clock),
        .reset(reset),
        .start_keygen(start_keygen),
        .done_keygen(done_keygen),
        .pk(pk),
        .sk(sk)
    );
    `BYTE_ASSIGN_GEN(pk, 1952, pk, pk_t)
    `BYTE_ASSIGN_GEN(sk, 4032, sk, sk_t)

    // Clock
    initial clock = 0;
    always #(CLK_PERIOD/2) clock = ~clock;

    // Global cycle counter
    always @(posedge clock) begin
        if (reset)
            cycle_count <= 0;
        else
            cycle_count <= cycle_count + 1;
    end

    initial begin

        // Reset
        reset = 1;
        start_keygen = 0;
        #(CLK_PERIOD*2) reset = 0;
        #(CLK_PERIOD) start_keygen = 1;

        start_cycle = cycle_count;
        $display("[%0t ns] START asserted at cycle %0d",$time, cycle_count);


        wait(done_keygen == 1);

        end_cycle = cycle_count;
        latency_cycles = end_cycle - start_cycle;

        $display("\n================ LATENCY REPORT ================");
        $display("Start cycle      : %0d", start_cycle);
        $display("End cycle        : %0d", end_cycle);
        $display("Latency (cycles) : %0d cycles", latency_cycles);
        $display("Latency (time)   : %0d ns", latency_cycles * CLK_PERIOD);
        $display("Frequency        : 100 MHz");
        $display("Throughput       : %.4f operations/sec",1.0e9 / (latency_cycles * CLK_PERIOD));
        $display("================================================\n");

        // Print keys
        $display("\n================ PUBLIC KEY ================");
        `PRINT_HEX_ARRAY("  pk", pk_t, 1952)

        $display("\n================ SECRET KEY ================");
        `PRINT_HEX_ARRAY("  sk", sk_t, 4032)

        $display("\n============ SIMULATION COMPLETE ============\n");

        #(CLK_PERIOD*10);
        $finish;
    end

    initial begin
        #1000000;
        $display("\n[ERROR] SIMULATION TIMEOUT!!!\n");
        $finish;
    end

endmodule
