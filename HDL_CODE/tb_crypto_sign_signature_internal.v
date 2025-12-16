`timescale 1ns/1ps
`include "byte_and_print.vh"

module tb_crypto_sign_signature_internal;

  // ========================================================================
  // CLOCK / RESET
  // ========================================================================
  reg clock;
  reg reset;

  initial clock = 0;
  always #5 clock = ~clock;   // 100 MHz (10ns period)

  // ========================================================================
  // DUT INPUTS
  // ========================================================================
  reg start_sign_internal;
  reg [8*64-1:0]  m;
  reg [31:0]      mlen;
  reg [8*32-1:0]  pre;
  reg [31:0]      prelen;
  reg [255:0]     rnd;
  reg [32255:0]   sk;

  // ========================================================================
  // DUT OUTPUTS
  // ========================================================================
  wire done_sign_internal;
  wire [26471:0] sig;

  // ========================================================================
  // DUT INSTANTIATION
  // ========================================================================
  crypto_sign_signature_internal dut (
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

  integer i;

  // ========================================================================
  // FSM STATE NAME DECODER
  // ========================================================================
  function [127:0] state_name;
    input [3:0] st;
    begin
      case (st)
        4'd0: state_name = "IDLE";
        4'd1: state_name = "SAMPLE_Y";
        4'd2: state_name = "COMPUTE_W";
        4'd3: state_name = "CHALLENGE";
        4'd4: state_name = "COMPUTE_Z";
        4'd5: state_name = "CHECK_Z";
        4'd6: state_name = "COMPUTE_CS2";
        4'd7: state_name = "CHECK_W0";
        4'd8: state_name = "COMPUTE_CT0";
        4'd9: state_name = "CHECK_H";
        4'd10: state_name = "PACK_SIG";
        4'd11: state_name = "DONE";
        default: state_name = "UNKNOWN";
      endcase
    end
  endfunction

  // ========================================================================
  // MONITOR 1: FSM State Tracker (using local prev_state)
  // ========================================================================
  reg [3:0] prev_state;
  integer state_cycles;
  
  initial begin
    prev_state = 4'd0;
    state_cycles = 0;
  end

  always @(posedge clock) begin
    if (reset) begin
      prev_state <= 4'd0;
      state_cycles <= 0;
    end else begin
      if (dut.state != prev_state) begin
        $display("[%0t] FSM: %-12s ? %-12s (cycles=%0d, nonce=%0d)",
                 $time, state_name(prev_state), state_name(dut.state), 
                 state_cycles, dut.nonce);
        prev_state <= dut.state;
        state_cycles <= 0;
      end else begin
        state_cycles <= state_cycles + 1;
        
        // WATCHDOG: Detect stuck state
        if (state_cycles == 50000) begin
          $display("\n========================================");
          $display("ERROR: FSM STUCK!");
          $display("========================================");
          $display("State: %s", state_name(dut.state));
          $display("Cycles: %0d", state_cycles);
          $display("Nonce: %0d", dut.nonce);
          $display("Time: %0t ns", $time);
          $display("\n--- Done Signals ---");
          $display("done_mu          : %b", dut.done_mu);
          $display("done_rhoprime    : %b", dut.done_rhoprime);
          $display("precompute_done  : %b", dut.precompute_done);
          $display("  done_mat_r     : %b", dut.done_mat_r);
          $display("  done_s1_r      : %b", dut.done_s1_r);
          $display("  done_s2_r      : %b", dut.done_s2_r);
          $display("  done_t0_r      : %b", dut.done_t0_r);
          $display("done_y           : %b", dut.done_y);
          $display("done_y_ntt       : %b", dut.done_y_ntt);
          $display("done_w_mult      : %b", dut.done_w_mult);
          $display("done_w_invntt    : %b", dut.done_w_invntt);
          $display("done_ctilde      : %b", dut.done_ctilde);
          $display("done_cp          : %b", dut.done_cp);
          $display("done_cp_ntt      : %b", dut.done_cp_ntt);
          $display("done_cs1_invntt  : %b", dut.done_cs1_invntt);
          $display("done_cs2_invntt  : %b", dut.done_cs2_invntt);
          $display("done_ct0_invntt  : %b", dut.done_ct0_invntt);
          $display("\n--- Norm Check Flags ---");
          $display("z_norm_pass      : %b", dut.z_norm_pass);
          $display("w0_norm_pass     : %b", dut.w0_norm_pass);
          $display("h_norm_pass      : %b", dut.h_norm_pass);
          $display("hint_count       : %0d (max=55)", dut.hint_count);
          $display("hint_count_pass  : %b", dut.hint_count_pass);
          $display("\n--- First few data samples ---");
          $display("y[31:0]          : %h", dut.y[31:0]);
          $display("z_final[31:0]    : %h", dut.z_final[31:0]);
          $display("w0_reduced[31:0] : %h", dut.w0_reduced[31:0]);
          $display("========================================\n");
          $finish;
        end
      end
    end
  end

  // ========================================================================
  // MONITOR 2: Done Signal Tracker
  // ========================================================================
  always @(posedge clock) begin
    if (!reset) begin
      if (dut.done_mu)
        $display("[%0t] ? done_mu", $time);
      if (dut.done_rhoprime)
        $display("[%0t] ? done_rhoprime", $time);
      if (dut.precompute_done)
        $display("[%0t] ? precompute_done", $time);
      if (dut.done_y)
        $display("[%0t] ? done_y (nonce=%0d)", $time, dut.nonce);
      if (dut.done_y_ntt)
        $display("[%0t] ? done_y_ntt", $time);
      if (dut.done_w_mult)
        $display("[%0t] ? done_w_mult", $time);
      if (dut.done_w_invntt)
        $display("[%0t] ? done_w_invntt", $time);
      if (dut.done_ctilde)
        $display("[%0t] ? done_ctilde", $time);
      if (dut.done_cp)
        $display("[%0t] ? done_cp", $time);
      if (dut.done_cp_ntt)
        $display("[%0t] ? done_cp_ntt", $time);
      if (dut.done_cs1_invntt)
        $display("[%0t] ? done_cs1_invntt", $time);
      if (dut.done_cs2_invntt)
        $display("[%0t] ? done_cs2_invntt", $time);
      if (dut.done_ct0_invntt)
        $display("[%0t] ? done_ct0_invntt", $time);
    end
  end

  // ========================================================================
  // MONITOR 3: Rejection Counter
  // ========================================================================
  integer rejection_count;
  initial rejection_count = 0;

  always @(posedge clock) begin
    if (reset) begin
      rejection_count <= 0;
    end else begin
      // Detect rejection: transition from CHECK state back to SAMPLE_Y
      if (prev_state == 4'd5 && dut.state == 4'd1) begin
        rejection_count <= rejection_count + 1;
        $display("[%0t] ??  REJECTION from CHECK_Z (count=%0d)", $time, rejection_count);
      end
      if (prev_state == 4'd7 && dut.state == 4'd1) begin
        rejection_count <= rejection_count + 1;
        $display("[%0t] ??  REJECTION from CHECK_W0 (count=%0d)", $time, rejection_count);
      end
      if (prev_state == 4'd9 && dut.state == 4'd1) begin
        rejection_count <= rejection_count + 1;
        $display("[%0t] ??  REJECTION from CHECK_H (count=%0d)", $time, rejection_count);
      end
      
      if (rejection_count > 100) begin
        $display("\n========================================");
        $display("ERROR: TOO MANY REJECTIONS (%0d)", rejection_count);
        $display("========================================");
        $display("This indicates a logic error in norm checks or data flow.");
        $finish;
      end
    end
  end

  // ========================================================================
  // MONITOR 4: Nonce Tracker
  // ========================================================================
  reg [15:0] prev_nonce;
  initial prev_nonce = 0;

  always @(posedge clock) begin
    if (reset) begin
      prev_nonce <= 0;
    end else begin
      if (dut.nonce != prev_nonce) begin
        $display("[%0t] Nonce: %0d ? %0d", $time, prev_nonce, dut.nonce);
        prev_nonce <= dut.nonce;
      end
    end
  end

  // ========================================================================
  // MONITOR 5: Check State Details
  // ========================================================================
  always @(posedge clock) begin
    if (!reset) begin
      // Sample data when entering CHECK states
      if (dut.state == 4'd5 && prev_state != 4'd5) begin
        $display("[%0t] Entering CHECK_Z: z_norm_pass=%b", $time, dut.z_norm_pass);
      end
      if (dut.state == 4'd7 && prev_state != 4'd7) begin
        $display("[%0t] Entering CHECK_W0: w0_norm_pass=%b", $time, dut.w0_norm_pass);
      end
      if (dut.state == 4'd9 && prev_state != 4'd9) begin
        $display("[%0t] Entering CHECK_H: h_norm_pass=%b, hint_count=%0d", 
                 $time, dut.h_norm_pass, dut.hint_count);
      end
    end
  end

  // ========================================================================
  // TEST SEQUENCE
  // ========================================================================
  initial begin
    $display("\n========================================");
    $display("DILITHIUM SIGNATURE TESTBENCH");
    $display("========================================");
    $display("Clock: 100MHz (10ns period)");
    $display("Timeout: 5ms");
    $display("========================================\n");

    reset = 1;
    start_sign_internal = 0;

    mlen   = 64;
    prelen = 32;

    // Initialize test data
    for (i = 0; i < 64; i = i + 1)
      m[8*i +: 8] = 8'h11;

    for (i = 0; i < 32; i = i + 1)
      pre[8*i +: 8] = 8'h22;

    for (i = 0; i < 32; i = i + 1)
      rnd[8*i +: 8] = 8'h33;

    // Simplified SK for faster testing (just set to some value)
    sk = 32256'h8c1816a5b9c279cf;

    $display("[%0t] Releasing reset...", $time);
    #50 reset = 0;

    $display("[%0t] Starting signature generation...", $time);
    #20 start_sign_internal = 1;
    #10 start_sign_internal = 0;

    $display("[%0t] Waiting for completion...\n", $time);

    // Wait for done
    @(posedge done_sign_internal);

    $display("\n========================================");
    $display("SUCCESS: Signature completed!");
    $display("Time: %0t ns", $time);
    $display("Rejections: %0d", rejection_count);
    $display("Final nonce: %0d", dut.nonce);
    $display("========================================\n");

    #100;
    $finish;
  end

  // ========================================================================
  // GLOBAL TIMEOUT
  // ========================================================================
  initial begin
    #5_000_000;  // 5ms
    $display("\n========================================");
    $display("ERROR: GLOBAL TIMEOUT (5ms)");
    $display("========================================");
    $display("Final state: %s", state_name(dut.state));
    $display("Rejections: %0d", rejection_count);
    $display("Nonce: %0d", dut.nonce);
    $display("========================================\n");
    $finish;
  end

endmodule
