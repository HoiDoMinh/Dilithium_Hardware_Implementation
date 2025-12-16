module poly_make_hint(
    input  signed [8191:0] a0_in,   // 256 × 32-bit
    input  signed [8191:0] a1_in,
    output signed [8191:0] h_out,
    output [8:0]           count
);

    localparam N = 256;

    wire signed [31:0] a0 [0:N-1];
    wire signed [31:0] a1 [0:N-1];
    wire               h_bit [0:N-1];

    genvar x;
    generate
        for (x = 0; x < N; x = x + 1) begin : GEN_HINT
            assign a0[x] = a0_in[32*x + 31 : 32*x];
            assign a1[x] = a1_in[32*x + 31 : 32*x];

            make_hint u_make_hint (
                .a0(a0[x]),
                .a1(a1[x]),
                .overflow_signal(h_bit[x])
            );

            assign h_out[32*x + 31 : 32*x] = {31'd0, h_bit[x]};
        end
    endgenerate

    // COUNT number of 1 bits (s)
    integer i;
    reg [8:0] s;

    always @(*) begin
        s = 0;
        for (i = 0; i < N; i = i + 1)
            s = s + h_bit[i];
    end

    assign count = s;

endmodule

