module poly_chknorm (
    input  signed [8191:0] a_in,     // 256 coeff × 32-bit = 8192 bit
    input  signed [31:0]   B,        // bound
    output reg             flag      // 1 = vi pham, 0 = OK
);

    parameter N = 256;
    localparam signed Q = 32'sd8380417;
    localparam signed Q_1_over_8 = (Q - 1) >>> 3;   // (Q-1)/8 = 1047552

    wire signed [31:0] a [0:255];

    genvar i;
    generate
        for (i = 0; i < N; i = i + 1) begin : UNPACK
            assign a[i] = a_in[32*i + 31 : 32*i];
        end
    endgenerate

    integer k;
    reg signed [31:0] t;
    reg signed [31:0] sign;

    always @(*) begin
        flag = 0;

        // If(B > (Q-1)/8) return 1
        if (B > Q_1_over_8) begin
            flag = 1;
        end
        else begin
            for (k = 0; k < N; k = k + 1) begin
                // sign = a[i] >> 31 (0 ho?c -1)
                sign = a[k] >>> 31;

                // t = a - (sign & (2*a))  => abs(a)
                t = a[k] - (sign & (a[k] <<< 1));

                // if(abs(a[i]) >= B)
                if (t >= B)
                    flag = 1;
            end
        end
    end

endmodule

