module polyeta_pack(
    input  [8191:0] a_in,     // 256 coeff × 32 bit
    output [1023:0] r_out      // 128 bytes = 1024 bit
    );

    localparam N   = 256;
    localparam ETA = 4;

    genvar i;
    generate
        for (i = 0; i < N/2; i = i + 1) begin : pack_loop

            // 2 he so 32bit
            wire signed [31:0] a0 = a_in[32*(2*i+0) + 31 : 32*(2*i+0)];
            wire signed [31:0] a1 = a_in[32*(2*i+1) + 31 : 32*(2*i+1)];

            // t[k] = ETA - coeff [0:4]
            wire [7:0] t0_temp = ETA - a0;
            wire [7:0] t1_temp = ETA - a1;
            

            wire [3:0] t0 = t0_temp[3:0];
            wire [3:0] t1 = t1_temp[3:0];
            // pack: t0 | (t1 << 4)
            wire [7:0] byte_i = t0 | (t1 << 4);

            assign r_out[8*i + 7 : 8*i] = byte_i;
        end
    endgenerate
endmodule
