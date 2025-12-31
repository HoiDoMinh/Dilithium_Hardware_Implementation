`timescale 1ns/1ps
`include "byte_and_print.vh"

module tb_crypto_sign_signature_internal;

    // 1. PARAMETERS
    localparam M_MAX = 64;
    localparam PRE_MAX = 32;
    localparam K = 6;
    localparam L = 5;
    localparam N = 256;
    
    localparam POLYVECL_BYTES = L * N * 4; // 5120 bytes
    localparam POLYVECK_BYTES = K * N * 4; // 6144 bytes
    localparam POLY_BYTES = N * 4;         // 1024 bytes
    localparam SIG_BYTES = 3309;

    // ========================================================================
    // 2. CLOCK / RESET
    // ========================================================================
    reg clock;
    reg reset;
    
    initial clock = 0;
    always #5 clock = ~clock;

    // ========================================================================
    // 3. DUT SIGNALS
    // ========================================================================
    reg start_sign_internal;
    reg [8*M_MAX-1:0] m;
    reg [31:0] mlen;
    reg [8*PRE_MAX-1:0] pre;
    reg [31:0] prelen;
    reg [255:0] rnd;
    reg [32255:0] sk;
    
    wire done_sign_internal;
    wire [26471:0] sig;

    // ========================================================================
    // 4. DUT INSTANTIATION
    // ========================================================================
    crypto_sign_signature_internal #(
        .M_MAX(M_MAX), 
        .PRE_MAX(PRE_MAX)
    ) dut (
        .clock(clock),
        .reset(reset),
        .start_sign_internal(start_sign_internal),
        .done_sign_internal(done_sign_internal),
        .sig(sig),
        .m(m),
        .mlen(mlen),
        .pre(pre),
        .prelen(prelen),
        .rnd(rnd),
        .sk(sk)
    );

    integer i,fd;

    // ========================================================================
    // 5. BYTE ARRAYS FOR PRINTING
    // ========================================================================
    reg [7:0] rho_bytes [0:31];
    reg [7:0] key_bytes [0:31];
    reg [7:0] tr_bytes [0:63];
    reg [7:0] mu_bytes [0:63];
    reg [7:0] rhoprime_bytes [0:63];
    reg [7:0] ctilde_bytes [0:47];
    
    // Vectors
    reg [7:0] s1_bytes [0:POLYVECL_BYTES-1];
    reg [7:0] s1_ntt_bytes [0:POLYVECL_BYTES-1];
    reg [7:0] s2_bytes [0:POLYVECK_BYTES-1];
    reg [7:0] s2_ntt_bytes [0:POLYVECK_BYTES-1];
    reg [7:0] t0_bytes [0:POLYVECK_BYTES-1];
    reg [7:0] t0_ntt_bytes [0:POLYVECK_BYTES-1];
    
    reg [7:0] y_bytes [0:POLYVECL_BYTES-1];
    reg [7:0] y_ntt_bytes [0:POLYVECL_BYTES-1];
    reg [7:0] z_temp_bytes [0:POLYVECL_BYTES-1];
    reg [7:0] z_final_bytes [0:POLYVECL_BYTES-1];
    
    reg [7:0] w_reduced_bytes [0:POLYVECK_BYTES-1];
    reg [7:0] w_invntt_bytes [0:POLYVECK_BYTES-1];
    reg [7:0] w_caddq_bytes [0:POLYVECK_BYTES-1];
    reg [7:0] w1_decomp_bytes [0:POLYVECK_BYTES-1];
    reg [7:0] w0_decomp_bytes [0:POLYVECK_BYTES-1];
    reg [7:0] w0_reduced_check_bytes [0:POLYVECK_BYTES-1];
    
    reg [7:0] cs1_ntt_bytes [0:POLYVECL_BYTES-1];
    reg [7:0] cs1_bytes [0:POLYVECL_BYTES-1];
    reg [7:0] cs2_ntt_bytes [0:POLYVECK_BYTES-1];
    reg [7:0] cs2_bytes [0:POLYVECK_BYTES-1];
    
    reg [7:0] h_reduced_bytes [0:POLYVECK_BYTES-1];
    reg [7:0] hints_bytes [0:POLYVECK_BYTES-1];
    reg [7:0] w0_plus_h_bytes [0:POLYVECK_BYTES-1];
    
    reg [7:0] cp_bytes [0:POLY_BYTES-1];
    reg [7:0] cp_ntt_bytes [0:POLY_BYTES-1];
    
    reg [7:0] sig_bytes [0:SIG_BYTES-1];

    // ========================================================================
    // 6. EXTRACT BYTES FROM SIGNALS 
    // ========================================================================
    always @(*) begin
        // Seeds and hashes
        for (i = 0; i < 32; i = i + 1) begin
            rho_bytes[i] = dut.rho[8*i +: 8];
            key_bytes[i] = dut.key[8*i +: 8];
        end
        for (i = 0; i < 64; i = i + 1) begin
            tr_bytes[i] = dut.tr[8*i +: 8];
            mu_bytes[i] = dut.mu[8*i +: 8];
            rhoprime_bytes[i] = dut.rhoprime[8*i +: 8];
        end
        for (i = 0; i < 48; i = i + 1) begin
            ctilde_bytes[i] = dut.ctilde[8*i +: 8];
        end
        
        // Vectors
        for (i = 0; i < POLYVECL_BYTES; i = i + 1) begin
            s1_bytes[i] = dut.s1[8*i +: 8];
            // ??c tr?c ti?p wire t? Top module
            s1_ntt_bytes[i] = dut.s1_ntt_wire[8*i +: 8]; 
            
            y_bytes[i] = dut.y[8*i +: 8];
            y_ntt_bytes[i] = dut.y_ntt[8*i +: 8];
            z_temp_bytes[i] = dut.z_temp[8*i +: 8];
            z_final_bytes[i] = dut.z_final[8*i +: 8];
            cs1_ntt_bytes[i] = dut.cs1_ntt[8*i +: 8];
            cs1_bytes[i] = dut.cs1[8*i +: 8];
        end
        
        for (i = 0; i < POLYVECK_BYTES; i = i + 1) begin
            s2_bytes[i] = dut.s2[8*i +: 8];
            // ??c tr?c ti?p wire
            s2_ntt_bytes[i] = dut.s2_ntt_wire[8*i +: 8]; 
            
            t0_bytes[i] = dut.t0[8*i +: 8];
            // ??c tr?c ti?p wire
            t0_ntt_bytes[i] = dut.t0_ntt_wire[8*i +: 8]; 
            
            w_reduced_bytes[i] = dut.w_reduced_temp[8*i +: 8];       
            w_invntt_bytes[i] = dut.w_invntt[8*i +: 8];
            w_caddq_bytes[i] = dut.w_caddq[8*i +: 8];
            w1_decomp_bytes[i] = dut.w1_decomp[8*i +: 8];
            w0_decomp_bytes[i] = dut.w0_decomp[8*i +: 8];
            w0_reduced_check_bytes[i] = dut.w0_reduced_check[8*i +: 8];
            
            cs2_ntt_bytes[i] = dut.cs2_ntt[8*i +: 8];
            cs2_bytes[i] = dut.cs2[8*i +: 8];
            h_reduced_bytes[i] = dut.h_reduced[8*i +: 8];
            hints_bytes[i] = dut.hints[8*i +: 8];
            w0_plus_h_bytes[i] = dut.w0_plus_h[8*i +: 8];
        end
        
        // Challenge
        for (i = 0; i < POLY_BYTES; i = i + 1) begin
            // ??c t? wire cp_direct
            cp_bytes[i] = dut.cp_direct[8*i +: 8];
            cp_ntt_bytes[i] = dut.cp_ntt[8*i +: 8];
        end
        
        // Signature
        for (i = 0; i < SIG_BYTES; i = i + 1) begin
            sig_bytes[i] = sig[8*i +: 8];
        end
    end

    // ========================================================================
    // 7. FSM STATE NAME HELPER
    // ========================================================================
    function [127:0] state_name;
        input [3:0] st;
        begin
            case (st)
                4'd0: state_name = "IDLE";
                4'd1: state_name = "CALC_MU";
                4'd2: state_name = "CALC_RHO";
                4'd3: state_name = "PRECOMP";
                4'd4: state_name = "SAMPLE_Y";
                4'd5: state_name = "COMPUTE_W";
                4'd6: state_name = "CHALLENGE";
                4'd7: state_name = "COMPUTE_Z";
                4'd8: state_name = "CHECK_Z";
                4'd9: state_name = "COMPUTE_CS2";
                4'd10: state_name = "CHECK_W0";
                4'd11: state_name = "COMPUTE_CT0";
                4'd12: state_name = "CHECK_H";
                4'd13: state_name = "PACK_SIG";
                4'd14: state_name = "DONE";
                default: state_name = "UNKNOWN";
            endcase
        end
    endfunction

    // ========================================================================
    // 8. MONITORING LOGIC (UPDATE FOR 1=FAIL LOGIC)
    // ========================================================================
    reg [3:0] prev_state;
    integer state_cycles;
    integer rejection_count;
    
    // Previous done signals for edge detection
    reg prev_all_precomp_done;
    reg prev_done_w_invntt;
    reg prev_done_cp_ntt;
    reg prev_done_cs1_invntt;
    reg prev_done_z_norm;
    reg prev_done_w0_norm;
    reg prev_done_cs2_invntt;
    reg prev_done_make_hint;
    reg prev_done_h_norm;
    reg prev_done_sign_internal;
    
    initial begin
        prev_state = 4'd0;
        state_cycles = 0;
        rejection_count = 0;
        prev_all_precomp_done = 0;
        prev_done_w_invntt = 0;
        prev_done_cp_ntt = 0;
        prev_done_cs1_invntt = 0;
        prev_done_z_norm = 0;
        prev_done_w0_norm = 0;
        prev_done_cs2_invntt = 0;
        prev_done_make_hint = 0;
        prev_done_h_norm = 0;
	prev_done_sign_internal = 0;
    end

    // State Transitions
    always @(posedge clock) begin
        if (reset) begin
            prev_state <= 4'd0;
            state_cycles <= 0;
        end else begin
            if (dut.state != prev_state) begin
                $display("\n[%0t] FSM: %-12s -> %-12s (cycles=%0d, nonce=%0d)",
                    $time, state_name(prev_state), state_name(dut.state),
                    state_cycles, dut.nonce);
                prev_state <= dut.state;
                state_cycles <= 0;
            end else begin
                state_cycles <= state_cycles + 1;
            end
        end
    end

    // ========================================================================
    // 9. EVENT DUMPING (UPDATE: Check FAIL flags instead of PASS)
    // ========================================================================
    always @(posedge clock) begin
        if (!reset) begin
            if (dut.all_precomp_done && !prev_all_precomp_done) begin
                $display("\n========== PRECOMPUTE COMPLETE ==========");
                `PRINT_HEX_ARRAY("RHO", rho_bytes, 32)
                `PRINT_HEX_ARRAY("KEY", key_bytes, 32)
                `PRINT_HEX_ARRAY("TR", tr_bytes, 64)
                `PRINT_HEX_ARRAY("MU", mu_bytes, 64)
                `PRINT_HEX_ARRAY("RHOPRIME", rhoprime_bytes, 64)
                `PRINT_HEX_ARRAY("S1_NTT", s1_ntt_bytes, 64)
                `PRINT_HEX_ARRAY("S2_NTT", s2_ntt_bytes, 64)
                `PRINT_HEX_ARRAY("T0_NTT", t0_ntt_bytes, 64)
                $display("=========================================\n");
            end
            
            if (dut.done_w_invntt && !prev_done_w_invntt) begin
                $display("\n========== COMPUTE_W COMPLETE (nonce=%0d) ==========", dut.nonce);
                `PRINT_HEX_ARRAY("Y", y_bytes, 64)
                `PRINT_HEX_ARRAY("Y_NTT", y_ntt_bytes, 64)
                `PRINT_HEX_ARRAY("W_REDUCED", w_reduced_bytes, 64)
                `PRINT_HEX_ARRAY("W_INVNTT", w_invntt_bytes, 64)
                `PRINT_HEX_ARRAY("W_CADDQ", w_caddq_bytes, 64)
                `PRINT_HEX_ARRAY("W1_DECOMP", w1_decomp_bytes, 64)
                `PRINT_HEX_ARRAY("W0_DECOMP", w0_decomp_bytes, 64)
                $display("====================================================\n");
            end
            
            if (dut.done_cp_ntt && !prev_done_cp_ntt) begin
                $display("\n========== CHALLENGE COMPLETE (nonce=%0d) ==========", dut.nonce);
                `PRINT_HEX_ARRAY("CTILDE", ctilde_bytes, 48)
                `PRINT_HEX_ARRAY("CP (Direct)", cp_bytes, 64)
                `PRINT_HEX_ARRAY("CP_NTT", cp_ntt_bytes, 64)
                $display("===================================================\n");
            end
            
            if (dut.done_cs1_invntt && !prev_done_cs1_invntt) begin
                $display("\n========== COMPUTE_Z COMPLETE (nonce=%0d) ==========", dut.nonce);
                `PRINT_HEX_ARRAY("CS1_NTT", cs1_ntt_bytes, 64)
                `PRINT_HEX_ARRAY("CS1", cs1_bytes, 64)
                `PRINT_HEX_ARRAY("Z_TEMP", z_temp_bytes, 64)
                `PRINT_HEX_ARRAY("Z_FINAL", z_final_bytes, 64)
                $display("===================================================\n");
            end
            
            // --- FIX: Hi?n th? tr?ng thái Pass/Fail ?úng ngh?a (1=Fail) ---
            if (dut.done_z_norm && !prev_done_z_norm) begin
                $display("\n========== CHECK_Z (nonce=%0d) ==========", dut.nonce);
                $display("Check Result: %s (Flag: %b)", 
                         dut.z_norm_fail ? "FAILED (Norm too high)" : "PASSED", 
                         dut.z_norm_fail);
                $display("========================================\n");
            end
            
            if (dut.done_cs2_invntt && !prev_done_cs2_invntt) begin
                $display("\n========== COMPUTE_CS2 COMPLETE (nonce=%0d) ==========", dut.nonce);
                `PRINT_HEX_ARRAY("CS2_NTT", cs2_ntt_bytes, 64)
                `PRINT_HEX_ARRAY("CS2", cs2_bytes, 64)
                $display("======================================================\n");
            end
            
            if (dut.done_w0_norm && !prev_done_w0_norm) begin
                $display("\n========== CHECK_W0 (nonce=%0d) ==========", dut.nonce);
                $display("Check Result: %s (Flag: %b)", 
                         dut.w0_norm_fail ? "FAILED (Norm too high)" : "PASSED", 
                         dut.w0_norm_fail);
                `PRINT_HEX_ARRAY("W0_REDUCED_CHECK", w0_reduced_check_bytes, 64)
                $display("=========================================\n");
            end
            
            if (dut.done_h_norm && dut.done_make_hint && !prev_done_make_hint) begin
                $display("\n========== CHECK_H (nonce=%0d) ==========", dut.nonce);
                $display("Check Result: %s", 
                         (dut.h_norm_fail || dut.hint_count_fail) ? "FAILED" : "PASSED");
                $display("  - H Norm Flag: %b (%s)", dut.h_norm_fail, dut.h_norm_fail ? "Fail" : "Pass");
                $display("  - Hint Count : %0d (Max 55) -> Flag: %b (%s)", 
                         dut.hint_count, dut.hint_count_fail, dut.hint_count_fail ? "Fail" : "Pass");
                         
                `PRINT_HEX_ARRAY("H_REDUCED", h_reduced_bytes, 64)
                `PRINT_HEX_ARRAY("W0_PLUS_H", w0_plus_h_bytes, 64)
                `PRINT_HEX_ARRAY("HINTS", hints_bytes, 64)
                $display("========================================\n");
            end
            
            if (done_sign_internal && !prev_done_sign_internal) begin
                $display("\n========== SIGNATURE COMPLETE ==========");
                $display("Time : %0t ns", $time);
                $display("Final nonce: %0d", dut.nonce);
                $display("Total Rejections : %0d", rejection_count);
                //`PRINT_HEX_ARRAY("FINAL_SIGNATURE", sig_bytes, SIG_BYTES)
		`DUMP_HEX_FILE("sig.hex", sig_bytes, SIG_BYTES)
		$system("notepad sig.hex");
                $display("========================================\n");
            end
        end
        
        // Update previous values
        prev_all_precomp_done <= dut.all_precomp_done;
        prev_done_w_invntt <= dut.done_w_invntt;
        prev_done_cp_ntt <= dut.done_cp_ntt;
        prev_done_cs1_invntt <= dut.done_cs1_invntt;
        prev_done_z_norm <= dut.done_z_norm;
        prev_done_w0_norm <= dut.done_w0_norm;
        prev_done_cs2_invntt <= dut.done_cs2_invntt;
        prev_done_make_hint <= dut.done_make_hint;
        prev_done_h_norm <= dut.done_h_norm;
	prev_done_sign_internal <= done_sign_internal;
    end

    // ========================================================================
    // 10. REJECTION MONITOR & ERROR CHECK (Logic 1=FAIL)
    // ========================================================================
    always @(posedge clock) begin
        if (reset) begin
            rejection_count <= 0;
        end else begin
            // Ki?m tra n?u FSM chuy?n t? tr?ng thái CHECK v? SAMPLE_Y (t?c là REJECT)
            if ((prev_state == 4'd8  && dut.state == 4'd4) || // CHECK_Z -> SAMPLE_Y
                (prev_state == 4'd10 && dut.state == 4'd4) || // CHECK_W0 -> SAMPLE_Y
                (prev_state == 4'd12 && dut.state == 4'd4))   // CHECK_H -> SAMPLE_Y
            begin
                rejection_count <= rejection_count + 1;
                $display("\n!!! REJECTION #%0d DETECTED at %s !!!", rejection_count, state_name(prev_state));
                
                // In lý do chi ti?t (Logic: Flag=1 là L?i)
                case (prev_state)
                    4'd8:  $display(" -> Reason: Z Norm Check FAILED (z_norm_fail=1)");
                    4'd10: $display(" -> Reason: W0 Norm Check FAILED (w0_norm_fail=1)");
                    4'd12: begin
                        if (dut.h_norm_fail) 
                            $display(" -> Reason: H Norm Check FAILED (h_norm_fail=1)");
                        if (dut.hint_count_fail) 
                            $display(" -> Reason: Hint Count Limit FAILED (count=%0d > 55)", dut.hint_count);
                    end
                endcase
           
                // Gi?i h?n s? l?n reject
                if (rejection_count > 30) begin
                    $display("\n[ERROR] TOO MANY REJECTIONS (%0d). Algorithm might be stuck or logic incorrect.", rejection_count);
                    $finish;
                end
            end
        end
    end

    // ========================================================================
    // 11. MAIN INITIAL BLOCK
    // ========================================================================
    initial begin
        $display("\n========================================");
        $display("DILITHIUM SIGNATURE DEBUG TESTBENCH");
        $display("========================================\n");

        reset = 1;
        start_sign_internal = 0;
        mlen = 64;
        prelen = 32;

        // Fill message and prefix with pattern
        for (i = 0; i < 64; i = i + 1) m[8*i +: 8] = 8'h11;
        for (i = 0; i < 32; i = i + 1) pre[8*i +: 8] = 8'h22;
        for (i = 0; i < 32; i = i + 1) rnd[8*i +: 8] = 8'h33;

        // DÁN KEY C?A B?N VÀO ?ÂY
        sk = 32256'h73c3c0b1b07b2cc32a246a1e6e241d9ebfc468b638d486366f684e501466770922feef1eb1c132cfe83590cef6140ede496281da60526bbafa4e05959a69cfc0d2099776f3983147dcf0bd8aa20c4777677036aa9402613d32e19637f95707b3370928c1d2b9a2ff00fd339eaa31febfe052010bd5e00cfdb90c2dcffc6acc34d0588dab28f2ed1bca9f51f20659ba8a7bb7ab22cc453812c807cff79bfb309185dc1ac8527f9844fee01a00092cdc2edcbbe3fdc025690a78575d89b26c9c3900d1f19d39ae74fe7500c1ac05c823d0aa7722f3e1d7613e3bb5bec5a2fd0d8836a53ac73b16f24eef73853b19c3d94f4973524f4fa5f6f5511b8f6cf016df6d622c64340dfb66ccbccbca8ce1e0dc7cfcd62dd41ef4cf72222d2fca70b62b49175df1e0e4e28466926759fc5657c19bc75d637e70adbce72457e5f8627e1bbc510d8954388ae8feba5d976ec4834f05acc4d5514f3d57531d6ff95aacb40a512266e0478e7682070b7bd27118c173274ff9f7aa14a1736e97256ae7d47465f7474cd0aa7b08e1ad622a9e4efa6c8ad3269680730a0bf0c50e0a9c2f883341dddf5ac1390478bdc182f29d5d3be55a979a427812cde39275d0d10f43a0f9559433c1a2d464a5d7c74c09fdd493097d2b14ab6619c34cfbd02f3011a69616d8118204d1d8e907e9cc901dd0b70960b6c719d08e50c30f7a2c3759fa0e7fa823c8e7d882d63d907ae6ab7f7ec702a301ad35bc9e6643d4f75f0f90f794124fa9a2855e1aa4f65e57785dd8c4f0e57d5663f701700414435708b07279ab5142b2a30fdab20b67fd9f8f1dc06dd8c81863f9f9cdf780d51473fb588141de40414bb56c65011615ceb2e07e73f447ac3eb9a71ac2e3c4d02299345b2f57ee04778bcccb0221d5445911669740b8f0bb37cf8390e3db108d55528213bd94ebc0db8bd8aa7ee762ab150c9e784d1595de75fd952225fd9054dfdb3e7741bfc719de19ab0f1132ded6f5075464ee37c6d33666de00d968707e67e86f0d6ca791497377f8ea845c5465db02ba13ca2a03ad624c04c8c8ba7602cc3f8de9a209ec6d1850e8cd79245cb35c4bd52675f44d75fb277467702cd99536c3d5dfc58b00a2f8cb5ccfed782fca617e5fc9c254a270901785795e7cc6bd0ea1a44d06696fe2a8e347c8097a7fdaea76c95161026d3ed27f91ae787562d0c5db75d08884a72dca105bf07944331007399fef47eb91a339e5abf5cc56dea4b0c63574bf75e10e5843299fea9b1833143b68890f68eb6eac8f0437fe958f381f1619617b03eb786aec995923554f29c6c425f7573f9c0425687fe4c1c2078f240ac1fdaa483ca18a46a810ee35c7c2c0b576e83c90169cabbed98907e607857aca3dd54f0c5dac3ff775cf3dbcab7aa1a15d6c14e34c351b5b6ca877bb7694717ce047425ff80d9542250dc87c590455aa102d37c34ef3f4279b8453c60b46921e5850b34a0ff249fe26273ef1384ee376edadacfb5765df40ffd32f66e76e55347ea3472824f080f846dd8879173af97658c865fd039dae25338512299211e1f722a29270b3caeb0d5aaedf35b977a38094c78f757e58c86651ef1ab8bdf8f16d609b921ba9f44724173fad88548170b76b0915f3b6062b609a0581cfc2ea2d4590e42996a430a271361a142a7ae44c8cc72223e692e01a068a5550e665e27edc75aeb1d47f2434491ad25c9ca3704d96e229602367a58fb8df1aa20d44868beaf095799cd69a5e4419d85cf1268f2dcb1ac840acbb25d0d5d8ebfffae79a4005a6a5a9e93d4d4231e17aa5e4292aa3e0e9d1ea740c70cc35182599af3cf4336cd13c90738669b3ab630fae48c23f6108a1e28500abe935e1d95a0026785f8c2b8a5b96b238c8601cbfb718b5a9c451184e57265badf7bf2425c116e904d5fdab893c00e35a80d67219d5a589e5f964708ef1ae3ef8851bbe1d2cb52f7a251dfe057b5e7b438e7299934a45ff0def6d8d2c1fd8d88f694eb36116331138f6d04eb242b952b619ebd74e3a69448bc6ce96b76b9bd4ba8edeab2795b3b7b276f52c11afc3e9e62a71f6f4ea7dd1bd277c1e32c0145d3dab5ca7d847363ba4fcc4741a02ddabbb30e8167c877ac712a752ae2fd8b1400ddf92eaab8b9fd5b99f4197a7954c8b46495846ff4d17a34d1dbaccc4f4df0ba90054cd2594a03dcd60529f8667b09ed6384b89d095599638268454c7644624260db045b7f8f96a00ddc9f03dd7d37f84b1a2af4f0061f4731c2784414d83bfcf02e2bbde211cfd83cff69038fd7b4a96b7d1546eb80e7ebb63960efe372fd541207831e0df5fea905814c5aabd68dfe93d5f29038aa859db2f6f7a06a5fff34e20130c353db811b570e671bc73ec26bc27a411f3994aaa9c2cdcea176f11c534044009a8c519437c3a5e5b67f9fe6e2ece39d173651319dab22fc68dd8f60f47a0f05a7c18a2f9eea176bec3061dedd75ab1d991c3ec5c052638076a59c199aa5d0de1cded6c3372fdc446f16dc3e7812e8465e2171b3bddeb3ffa2e4a6aa6a6ddaaa71f8d24aabbd4dcc8fb763479babfba54bc19bd05d04015768e5197094c76f8f3913a70b186ecf3169c96127f1e1b8ddadaf89f0c6641ccb5b0024a669c70b8153aa20a8d7fa1159b094e844c4b5a163b1c33ee25a57bdd7cd1ce9eaecc2146c4a1747a14f064b36da56ea4460507def35e6d6439056d460e787af5e65b630829409d5bc66cac6cc4c86dbb0fa978cedc3ecfc5fe5deed74f729aa84a17c9914d7c0f48d958e016a51aa3fb4c57d2776c986bb9a674f7ad0a42b04a4648fb10bc2f8789c30973f00d4ce44a22dc1cf3f7e5f49ff3e3964c4e4d3f9dbbde47c1461061a21d6d11e3cccd8706e40b116edb269e25b184f8f8db7f47b7bc59dc9b93bfc04d4cac666c16682f5f300b11eefb48badf916f0973d8a1e2fbd8c1806b74e3cc3a7c8f40598afe63875381c55692fd272bdf38c420ccc2825d7d6072384a4669a9ad37734c2fe6c8d0c1a8bf38f648c1230e2621d45f21c740b6893f6f437d1d9d7b6e07333593b3315a65f627e84923f7707ae2d1b338bf073e4a987fcdf00869214901aad4f860193c4f36ef0feccc6c89ee93ba7c6eaec726af6a0e6cd0dee21b1c8aa5d652f77d03467578e3e4c9a4800d32d908b0ad66973d98c8dcb6bbefcd78a92d8db0e2dd4b9e877ae1a7b1faef494a6f74d378e2a1276d7a517195bd3b74f058aab1e6af35c4425db51c34beb8df0c5ea4b92469ec2f7d7bad485e3bd684f685cf2d1fea521119af0c6823bbe904b85690fc2cf4abdda6ce0e7dc6aaffc6355fcec1ff331dc9d816d87119976fc3956a79d998283db4227787fe78358573036d311145bf30f68c5a2021ba065bb62b10c089734f95b77ffcf73df858940f6706d1676440aa07141d5fc839829a8c55e7adac06b33114a234bed37c3b49c922e0867e4315ca47b2e5875361c794a6c0aa794c45166752bf0b8797334bd14d6447498a3058e8efe52da6c924738842836262205463560338063681278882814040106086644817737056700488814537308333417328641626301066475070288226403721156683204416450785271708365573045051878273074410566473817387334270008274273180016368011462472781053477506514005637481527065183121730831518516405612146282071845426874766168526702282317784387105338861233025440368706144067387158006281413113433188287158384343645355656842025872175325406272356051161622128416881837004774747760670888031425613506406470321647455840383560306066708364352413210837385884436875167852066252832224702834480427067317473053574476081552748525661867573162661047258072752320885053288158878377341650368316855882170408061886583723031853760077461876364517660420620222118416305602161073225812644326682621155327828037015325768771141800235126516253567675578227338607180486448855254850422337212188285880566334841300545280237463370041542762842021400813525072386334137664681772514401017526331687615544038300328346244440781786585816640321416275186162348662028536458645253034041033324252358580408172453362863231304744732458643825887500527721285767747754460001557017553241404250378710664264855770351607062126385102171771552620304610028482004661167051377307033002435488437024481820524740345275723033633036032483164571252206055261251763012125735203847605666707513110608432804820824172544187126044334466641737381083166425523481527225537244043702074002274358775841162461405076563256255626641217022416514505275723804417178251213472558842083182381086665022287768634053271442057865326545530505202002886321540146172831587287687256634107384103714415288577037384522575858324473484231241851831164306877177848067221577526043460843581670684084362277010721864313551811783557481468628416373801655716433587375288452012727425334312236805773706653080374384078780016621264816784007877766474322043664278280380254647857152777233785106404761536031731182784543318441051376705436706628242400265642126245374642441718625138837647860360443776805710452187802882285754162568344515884576111702517415603124647364823546812304881226461321710406538385323075665102103334237654462416787782731114672550730162828848576455605442557363646137725702836476165764808128470120687188225151447046267340861442241865184630137483144486585414372334418013755084201813625167655658057077346646862661833512503525310503703815662665750113120682357825246738160302571447046134557838671838243284010743132826387376761783830840600048176022174671012855551617511846267206735741770567680217782771123413222222843680433322076017104284566102464804886354471100176024757210812471365450151027586425432801882154822152557140336548047766481651211270488043468738521386662206514523145040663711587541656876380354334786133362728524567711840328843433743570143437268808242466834048618073516484437577526606704681115602671767622064547422207776666260826215756614245616312778254406c55c4fd87e9c6702a3db696c01b7f2c883720567ab41a85aea38f664051d4cdd7a413ab81f1745e8985b630fa7b87577565e2b2bded1fbf5c82780d40ef8dbeed08cec1fafdeaa31a1bdc9949b2053e128cfb25f827532bb3fa27a107de160c726efa1579820aa54e5c4458147e6ccc90d209e2ed10fb38da21839c56fd4d4ff; // Ví d?, hãy thay b?ng key th?t

        // ====================================================================

        #100 reset = 0;
        #50 start_sign_internal = 1;
        #10 start_sign_internal = 0;

        wait(done_sign_internal);
        
        #100;
        $display("\n========================================");
        $display("SUCCESS! SIGNATURE GENERATED.");
        $display("========================================\n");
        $finish;
    end

    // TIMEOUT GUARD 
    initial begin
        #50_000_000;
        $display("\n========================================");
        $display("ERROR: TIMEOUT (Simulation ran too long)");
        $display("========================================\n");
        $finish;
    end

endmodule
