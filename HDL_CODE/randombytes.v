module randombytes #(parameter in_len = 32)(
    output [in_len * 8 - 1:0] random_out
    );
    
    assign random_out = 256'h00f187396a5c4d2f117e99c0bba956103cde89f4023064770dacee914217b35e;
endmodule
