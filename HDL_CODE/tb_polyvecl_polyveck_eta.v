`timescale 1ns/1ps
`include "byte_and_print.vh"
module tb_polyvecl_polyveck_eta;
    reg clock;
    reg reset;
    reg start;
    reg [511:0] seed;
    reg [15:0] nonce_l, nonce_k;
    wire signed [40959:0] v_out_l;
    wire signed [49151:0] v_out_k;
    wire done_l, done_k;

    polyvecl_uniform_eta dut1 (
         .clock(clock),
         .reset(reset),
         .start(start),
         .seed(seed),
         .nonce(nonce_l),
         .v_out(v_out_l),   // 5 ?a th?c 5*8192 = 40960
         .done(done_l)
    );
    polyveck_uniform_eta dut2 (
         .clock(clock),
         .reset(reset),
         .start(start),
         .seed(seed),
         .nonce(nonce_k),
         .v_out(v_out_k),   // 6 ?a th?c 6*8192 = 49152
         .done(done_k)
    );

    initial clock = 0;
    always #5 clock = ~clock;
    
    wire [7:0] rho_prime_t [63:0];
    wire [7:0] v_outl_t [5119:0];
    wire [7:0] v_outk_t [6143:0];
    
     `BYTE_ASSIGN_GEN(seed,  64, seed,                  rho_prime_t)
    `BYTE_ASSIGN_GEN(vl,  5120, v_out_l,                  v_outl_t)
    `BYTE_ASSIGN_GEN(vk,  6144, v_out_k,                  v_outk_t)

    integer i = 0, j = 0;


    initial begin
        reset = 1;
        start = 0;
        seed = 512'hc0b0a09080706050403020102143658778695a4b3c2d1e0f1032547698badcfebc9a78563412ffeeddccbbaafedcba9876543210efcdab8967452301efbeadde;
	//seed = 512'h3412ffeeddccbbaaf0debc9a78563412f0e1d2c3b4a5968778695a4b3c2d1e0f00112233445566778899aabbccddeeffffeeddccbbaa99887766554433221100;
	//seed = 512'h8796a5b4c3d2e1f01234567889abcdeffedcba987654321099887766efbeadde3cf04f5a8e187122cd0b5099aa332f7d906c01fe1144d9a30e551988ccf37a12;
	//seed = 512'h00102132435465768798a9bacbdcedfeefcdab8967452301efde99884713aa556cb904fd193372ca57ec0a8164f83d49ee17db2c908a6fb2415dc80377af129e;
        nonce_l = 16'd1234;
        nonce_k = 16'd5678;  // = L

        #20 reset = 0;
        #10 start = 1;

        wait(done_l && done_k);

        //$display("seed_rhoprime_in = %0h", seed);
	$display("nonce_l = %0d",nonce_l);
	`PRINT_HEX_ARRAY("seed rhoprime", rho_prime_t, 64)
        `PRINT_HEX_ARRAY("v_out veckl", v_outl_t, 5120) 
	 
	`PRINT_HEX_ARRAY("seed rhoprime", rho_prime_t, 64)
         $display("nonce_k = %0d",nonce_k);
        `PRINT_HEX_ARRAY("v_out veckk", v_outk_t, 6144)

        #10 start = 0;
        #50 $finish;
    end

endmodule
