

module tb_poly_uniform_eta;
  reg clock, reset, start;
  reg [511:0] seed;
  reg [15:0] nonce;
  wire signed [8191:0] a_out;
  wire done;
  
  poly_uniform_eta dut (
    .clock(clock),
    .reset(reset),
    .start(start),
    .seed(seed),
    .nonce(nonce),
    .a_out(a_out),
    .done(done)
  );
  
  initial clock = 0;
  always #5 clock = ~clock;
  
  initial begin
    reset = 1;
    start = 0;
    //seed = 512'h201f1e1d1c1b1a191817161514131211100f0e0d0c0b0a090807060504030201201f1e1d1c1b1a191817161514131211100f0e0d0c0b0a090807060504030201;
      seed = 512'h1f7b14fb1720d61899d317dd65b4cbcad2e89d24fb358e10a73ab6cd60295a1d1db224dabe61ae29fbcaa5ac85fd87d7527fc4ef4a73d082cefa0c47b6be3e42;
      nonce = 16'h4d;
    
    #20 reset = 0;
    #10 start = 1;
    
    wait(done);
    $display("seed_in = %0h",seed);
    $display("nonce = %0h",nonce); 
    $display("a_out = %0h",a_out);
    #10 start = 0;
    #50 $finish;
  end
endmodule