module randombytes #(parameter in_len = 32)(
    output [in_len * 8 - 1:0] random_out
);
    // 1. Khai báo dây ch?a giá tr? g?c (Ch?a ??o)
    wire [in_len * 8 - 1:0] raw_data;
    
    // 2. Gán giá tr? c?ng vào dây g?c
    assign raw_data = 256'h5eb3174291eeac0d77643002f489de3c1056a9bbc0997e112f4d5c6a3987f100;

    // 3. ??o ng??c t? raw_data sang random_out
    genvar i;
    generate
        for (i = 0; i < in_len; i = i + 1) begin : reverse_rnd_bytes
            assign random_out[8*i + 7 : 8*i] = raw_data[8*(in_len-1-i) + 7 : 8*(in_len-1-i)];
        end
    endgenerate

endmodule
