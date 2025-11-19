`timescale 1ns/1ps
`include "byte_and_print.vh"

module tb_crypto_sign_keypair;
    reg clock;
    reg reset;
    reg start_keygen;
    wire done_keygen;
    wire [15615:0] pk;
    wire [32255:0] sk;
    
    // Instantiate DUT
    crypto_sign_keypair dut(
        .clock(clock),
        .reset(reset),
        .start_keygen(start_keygen),
        .done_keygen(done_keygen),
        .pk(pk),
        .sk(sk)
    );
    
    // Clock generation
    initial clock = 0;
    always #5 clock = ~clock;
    
    // 1. Random bytes và SHAKE256 input
    wire [271:0] randombytes_temp = dut.randombytes_temp;
    
    // 2. SHAKE256 output - TR??C inverse
    wire [1023:0] seedbuf_shaked = dut.seedbuf_shaked;
    
    // 3. SHAKE256 output - SAU inverse
    wire [1023:0] seedbuf_shaked_inverse = dut.seedbuf_shaked_inverse;
    
    // 4. rho, rhoprime, key
    wire [255:0] rho_temp = dut.rho_temp;
    wire [511:0] rhoprime_temp = dut.rhoprime_temp;
    wire [255:0] key_temp = dut.key_temp;
    
    // 5. s1, s2 - Output t? uniform_eta
    wire signed [40959:0] s1_temp = dut.s1_temp;
    wire signed [49151:0] s2_temp = dut.s2_temp;
    
    // 6. s1_inverse - SAU khi ??o ng??c
    wire [40959:0] s1_inverse = dut.s1_inverse;
    
    // 7. s1hat - Output t? NTT
    wire signed [40959:0] s1hat = dut.s1hat;
    
    // 8. s1hat_inverse - SAU khi ??o ng??c l?n 2
    wire [40959:0] s1hat_inverse = dut.s1hat_inverse;
    
    // 9. Matrix A
    wire signed [65535:0] mat1_temp = dut.mat1_temp;
    wire signed [65535:0] mat2_temp = dut.mat2_temp;
    wire signed [65535:0] mat3_temp = dut.mat3_temp;
    wire signed [49151:0] mat4_temp = dut.mat4_temp;
    
    // 10. t1 - K?t qu? matrix multiply
    wire signed [49151:0] t1 = dut.t1;
    wire signed [49151:0] t1_reduced = dut.t1_reduced;
    wire [49151:0] t1_reduced_inverse = dut.t1_reduced_inverse;
    
    // 11. t1_invntt - Sau invNTT
    wire signed [49151:0] t1_invntt = dut.t1_invntt;
    wire [49151:0] t1_invntt_inverse = dut.t1_invntt_inverse;
    
    // 12. Các b??c cu?i
    wire signed [49151:0] t1_added = dut.t1_added;
    wire signed [49151:0] t1_caddqed = dut.t1_caddqed;
    wire signed [49151:0] t0 = dut.t0;
    wire signed [49151:0] t1_power2round = dut.t1_power2round;
    
    // 13. tr - SHAKE256 l?n 2
    wire [511:0] tr_temp = dut.tr_temp;
    wire [511:0] tr_inversed = dut.tr_inversed;
    
    // 14. Done signals
    wire done_shake_1 = dut.done_shake_1;
    wire done_polyvecl_uniform_eta = dut.done_polyvecl_uniform_eta;
    wire done_polyveck_uniform_eta = dut.done_polyveck_uniform_eta;
    wire done_polyvec_matrix_expand = dut.done_polyvec_matrix_expand;
    wire done_polyvecl_ntt = dut.done_polyvecl_ntt;
    wire done_polyvec_matrix_pointwise_montgomery = dut.done_polyvec_matrix_pointwise_montgomery;
    wire done_polyveck_invntt = dut.done_polyveck_invntt;
    wire done_shake_2 = dut.done_shake_2;
    //bytes declare
    
    wire [7:0] randombytes_t [0:33];
    wire [7:0] seedbuf_shaked_t [0:127];
    wire [7:0] seedbuf_shaked_inverse_t [0:127];
    wire [7:0] rho_t [0:31];
    wire [7:0] rhoprime_t [0:63];
    wire [7:0] key_t [0:31];
    
    wire [7:0] s1_t [0:5119];      // 5 * 256 * 4 = 5120 bytes
    wire [7:0] s1_inverse_t [0:5119];
    wire [7:0] s2_t [0:6143];      // 6 * 256 * 4 = 6144 bytes
    
    wire [7:0] s1hat_t [0:5119];
    wire [7:0] s1hat_inverse_t [0:5119];
    
    wire [7:0] mat1_t [0:8191];    // 8192 bytes
    wire [7:0] mat2_t [0:8191];
    wire [7:0] mat3_t [0:8191];
    wire [7:0] mat4_t [0:6143];
    
    wire [7:0] t1_t [0:6143];
    wire [7:0] t1_reduced_t [0:6143];
    wire [7:0] t1_reduced_inverse_t [0:6143];
    wire [7:0] t1_invntt_t [0:6143];
    wire [7:0] t1_invntt_inverse_t [0:6143];
    wire [7:0] t1_added_t [0:6143];
    wire [7:0] t1_caddqed_t [0:6143];
    wire [7:0] t0_t [0:6143];
    wire [7:0] t1_power2round_t [0:6143];
    
    wire [7:0] tr_t [0:63];
    wire [7:0] tr_inversed_t [0:63];
    
    wire [7:0] pk_t [0:1951];
    wire [7:0] sk_t [0:4031];
    
    
    integer i;
    
    `BYTE_ASSIGN_GEN(randombytes,           34,  randombytes_temp,          randombytes_t)
    `BYTE_ASSIGN_GEN(seedbuf_shaked,       128,  seedbuf_shaked,            seedbuf_shaked_t)
    `BYTE_ASSIGN_GEN(seedbuf_shaked_inv,   128,  seedbuf_shaked_inverse,    seedbuf_shaked_inverse_t)
    `BYTE_ASSIGN_GEN(rho,                   32,  rho_temp,                  rho_t)
    `BYTE_ASSIGN_GEN(rhoprime,              64,  rhoprime_temp,             rhoprime_t)
    `BYTE_ASSIGN_GEN(key,                   32,  key_temp,                  key_t)
    
    `BYTE_ASSIGN_GEN(s1,                  5120,  s1_temp,                   s1_t)
    `BYTE_ASSIGN_GEN(s1_inv,              5120,  s1_inverse,                s1_inverse_t)
    `BYTE_ASSIGN_GEN(s2,                  6144,  s2_temp,                   s2_t)
    
    `BYTE_ASSIGN_GEN(s1hat,               5120,  s1hat,                     s1hat_t)
    `BYTE_ASSIGN_GEN(s1hat_inv,           5120,  s1hat_inverse,             s1hat_inverse_t)
    
    `BYTE_ASSIGN_GEN(mat1,                8192,  mat1_temp,                 mat1_t)
    `BYTE_ASSIGN_GEN(mat2,                8192,  mat2_temp,                 mat2_t)
    `BYTE_ASSIGN_GEN(mat3,                8192,  mat3_temp,                 mat3_t)
    `BYTE_ASSIGN_GEN(mat4,                6144,  mat4_temp,                 mat4_t)
    
    `BYTE_ASSIGN_GEN(t1,                  6144,  t1,                        t1_t)
    `BYTE_ASSIGN_GEN(t1_red,              6144,  t1_reduced,                t1_reduced_t)
    `BYTE_ASSIGN_GEN(t1_red_inv,          6144,  t1_reduced_inverse,        t1_reduced_inverse_t)
    `BYTE_ASSIGN_GEN(t1_invntt,           6144,  t1_invntt,                 t1_invntt_t)
    `BYTE_ASSIGN_GEN(t1_invntt_inv,       6144,  t1_invntt_inverse,         t1_invntt_inverse_t)
    `BYTE_ASSIGN_GEN(t1_add,              6144,  t1_added,                  t1_added_t)
    `BYTE_ASSIGN_GEN(t1_caddq,            6144,  t1_caddqed,                t1_caddqed_t)
    `BYTE_ASSIGN_GEN(t0,                  6144,  t0,                        t0_t)
    `BYTE_ASSIGN_GEN(t1_p2r,              6144,  t1_power2round,            t1_power2round_t)
    
    `BYTE_ASSIGN_GEN(tr,                    64,  tr_temp,                   tr_t)
    `BYTE_ASSIGN_GEN(tr_inv,                64,  tr_inversed,               tr_inversed_t)
    
    `BYTE_ASSIGN_GEN(pk,                  1952,  pk,                        pk_t)
    `BYTE_ASSIGN_GEN(sk,                  4032,  sk,                        sk_t)
    

    // TEST 

    initial begin
        reset = 1;
        start_keygen = 0;
        #20 reset = 0;
        #10 start_keygen = 1;
        
        //TEST 1: SHAKE256
        wait(done_shake_1);
        #10;
        $display("\nTEST 1: SHAKE256 #1");
        $display("Input to SHAKE256:");
        `PRINT_HEX_ARRAY("  randombytes_temp", randombytes_t, 34)
        
        $display("\nOutput from SHAKE256 (RAW - before inverse):");
        `PRINT_HEX_ARRAY("  seedbuf_shaked", seedbuf_shaked_t, 128)
        
        $display("\nOutput from SHAKE256 (AFTER inverse):");
        `PRINT_HEX_ARRAY("  seedbuf_shaked_inverse", seedbuf_shaked_inverse_t, 128)
        
        $display("\nExtracted values:");
        `PRINT_HEX_ARRAY("  rho", rho_t, 32)
        `PRINT_HEX_ARRAY("  rhoprime", rhoprime_t, 64)
        `PRINT_HEX_ARRAY("  key", key_t, 32)
        
        //TEST 2: s1, s2 generation
        wait(done_polyvecl_uniform_eta && done_polyveck_uniform_eta);
        #10;
        $display("\nTEST 2: s1, s2 Generation");
        
        $display("\ns1 (from polyvecl_uniform_eta):");
        `PRINT_HEX_ARRAY("  s1_temp", s1_t, 5120)
        
        $display("\ns1_inverse (after reversing coefficients):");
        `PRINT_HEX_ARRAY("  s1_inverse", s1_inverse_t, 5120)
        
        $display("\ns2 (from polyveck_uniform_eta):");
        `PRINT_HEX_ARRAY("  s2_temp", s2_t, 6144)
        //TEST 3: Matrix A
        wait(done_polyvec_matrix_expand);
        #10;
        $display("\nTEST 3: Matrix A Expansion");
        //`PRINT_HEX_ARRAY("  mat1 (poly 0)", mat1_t, 1024)  // In 1024 bytes ??u
        //`PRINT_HEX_ARRAY("  mat2 (poly 0)", mat2_t, 1024)
        `PRINT_HEX_ARRAY("  mat1 ", mat1_t, 8192)  
        `PRINT_HEX_ARRAY("  mat2 ", mat2_t, 8192)
        `PRINT_HEX_ARRAY("  mat3 ", mat3_t, 8192)
        `PRINT_HEX_ARRAY("  mat4 ", mat4_t, 6144)
        //TEST 4: NTT
        wait(done_polyvecl_ntt);
        #10;
        $display("\nTEST 4: NTT");
        
        $display("\ns1hat (output from NTT):");
        `PRINT_HEX_ARRAY("  s1hat", s1hat_t, 5120)
        
        $display("\ns1hat_inverse (after reversing again):");
        `PRINT_HEX_ARRAY("  s1hat_inverse", s1hat_inverse_t, 5120)
        
        
        
        //TEST 5: Matrix multiplication
        wait(done_polyvec_matrix_pointwise_montgomery);
        #10;
        $display("\nTEST 5: Matrix Multiplication");
        
        $display("\nt1 (A * s1hat in NTT domain):");
        `PRINT_HEX_ARRAY("  t1", t1_t, 6144)  // In poly ??u tiên
        
        $display("\nt1_reduced:");
        `PRINT_HEX_ARRAY("  t1_reduced", t1_reduced_t, 6144)
        
        $display("\nt1_reduced_inverse:");
        `PRINT_HEX_ARRAY("  t1_reduced_inverse", t1_reduced_inverse_t, 6144)
        
        //TEST 6: invNTT
        wait(done_polyveck_invntt);
        #10;
        $display("\nTEST 6: Inverse NTT");
        
        $display("\nt1_invntt (back to normal domain):");
        `PRINT_HEX_ARRAY("  t1_invntt", t1_invntt_t, 6144)
        
        $display("\nt1_invntt_inverse:");
        `PRINT_HEX_ARRAY("  t1_invntt_inverse", t1_invntt_inverse_t, 6144)
        
        
        //TEST 7: Add, caddq, power2round
        #50;  
        $display("\nTEST 7: Final Operations");
        
        $display("\nt1_added (t1 + s2):");
        `PRINT_HEX_ARRAY("  t1_added", t1_added_t, 6144)
        
        $display("\nt1_caddqed:");
        `PRINT_HEX_ARRAY("  t1_caddqed", t1_caddqed_t, 6144)
        
        $display("\nt0 and t1_power2round:");
        `PRINT_HEX_ARRAY("  t0", t0_t, 6144)
        `PRINT_HEX_ARRAY("  t1_power2round", t1_power2round_t, 6144)
        
        //TEST 8: Final outputs
        wait(done_keygen);
        #10;
        $display("\nTEST 8: Final Outputs");
        
        $display("\ntr (SHAKE256 of pk):");
        `PRINT_HEX_ARRAY("  tr_temp (before inverse)", tr_t, 64)
        `PRINT_HEX_ARRAY("  tr_inversed", tr_inversed_t, 64)
        
        $display("\nPublic Key:");
        `PRINT_HEX_ARRAY("  pk", pk_t, 1952)
        
        $display("\nSecret Key:");
        `PRINT_HEX_ARRAY("  sk", sk_t, 4032)
        
        $display("\nSIMULATION COMPLETE\n");
        $finish;
    end
    
    // Timeout
    initial begin
        #1000000;  // 1ms timeout
        $display("\n[ERROR] SIMULATION TIMEOUT!\n");
        $finish;
    end
    
endmodule
