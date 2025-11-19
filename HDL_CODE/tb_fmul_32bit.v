module tb_fmul_32bit;

    reg clock;
    reg reset;
    reg start;
    reg signed [31:0] a;
    reg signed [31:0] b;
    wire done;
    wire  signed [31:0] reduce;

fqmul_32bit dut
    (
    .clock(clock),
    .reset(reset),
    .start(start),
    .a(a),
    .b(b),
    .done(done),
    .reduce(reduce)
    );

    initial clock = 0;
    always #5 clock = ~clock;
    
    // Task 
    task run_test;
        input signed [31:0] test_value1;
	input signed [31:0] test_value2;
        begin
            reset = 1;
            start = 0;
            a = 0;b=0;
            #20;  
            
            reset = 0;
            #10;  
            
            a = test_value1;
	    b = test_value2;
            start = 1;
            #10; 
            start = 0;  
            
            // (RTS = 1)
            wait(done == 1);
            #1;
            $display("a=%20d*b=%20d -> reduce=%11d ", test_value1,test_value2,reduce);
            
            #20;  
        end
    endtask
    
    initial begin
        reset = 1;
        start = 0;
        a = 0;b=0;
        #30;
        reset = 0;
        #10;
        
        // Ch?y các test case
	run_test(32'd0,-31'd1); 
	run_test(32'd121212,-31'sd218182981); 
	run_test(32'd1,31'd1); 
 
 
	                   
        #50;
        $finish;
    end





endmodule 
