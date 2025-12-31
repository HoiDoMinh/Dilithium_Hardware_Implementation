module poly_chknorm (
    input  signed [8191:0] a_in,     // 256 coeff × 32-bit
    input  signed [31:0]   B,        // bound
    output reg             flag      // 1 = Fail, 0 = Pass
);
    parameter N = 256;
    localparam signed Q_1_over_8 = 32'sd1047552; // (Q-1)/8

    wire signed [31:0] a [0:255];
    genvar i;
    generate
        for (i = 0; i < N; i = i + 1) begin : UNPACK
            assign a[i] = a_in[32*i + 31 : 32*i];
        end
    endgenerate

    integer k;
    reg signed [31:0] t; // Bi?n t?m l?u tr? tuy?t ??i
    reg signed [31:0] sign;

    always @(*) begin
        flag = 0; // M?c ??nh OK
        
        if (B > Q_1_over_8) begin
            flag = 1; // Bound l?i -> Fail
        end
        else begin
            for (k = 0; k < N; k = k + 1) begin
                // OPTIMIZED ABSOLUTE VALUE (MATCHING C CODE)
                // Công th?c này ?úng cho c? s? âm và s? d??ng trong tr??ng h?u h?n
                sign = a[k] >>> 31;
                t = a[k] - (sign & (a[k] <<< 1)); 
                
                // Ki?m tra bound
                if (t >= B) begin
                    flag = 1; // Fail
                end
            end
        end
    end
endmodule
