
module unpack_pk(
    input  [15615:0] pk_in,      // CRYPTO_PUBLICKEYBYTES = 32 + 6*320 = 1952 bytes = 15616 bits
    output [255:0]   rho_out,    // SEEDBYTES = 32 bytes
    output [49151:0] t1_out      // K * N * 32 bits = 6 * 256 * 32 = 49152 bits
);

    localparam POLYT1_PACKEDBYTES = 320; // 320 bytes * 8 = 2560 bits
    localparam SEEDBYTES = 32;
    localparam K = 6;
    localparam N = 256;

    // 1. Tách rho 
    assign rho_out = pk_in[255:0];

    // 2. Tách và gi?i nén t1 (K vectors)
    generate
        genvar i;
        for (i = 0; i < K; i = i + 1) begin : loop_unpack_t1
            
            localparam PK_START = 256 + (i * 2560);
            localparam PK_END   = PK_START + 2560 - 1;

   
            localparam T1_START = i * 8192;
            localparam T1_END   = T1_START + 8192 - 1;

            polyt1_unpack u_polyt1_unpack (
                .linear_a (pk_in[PK_END : PK_START]),
                .linear_r (t1_out[T1_END : T1_START])
            );
        end
    endgenerate

endmodule