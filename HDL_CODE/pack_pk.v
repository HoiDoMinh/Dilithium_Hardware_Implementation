
module pack_pk(
    input [255:0] rho_in,
    input [49151:0] t1_in,
    output [15615:0] pk_out     //uint8_t pk[CRYPTO_PUBLICKEYBYTES=(SEEDBYTES + K*POLYT1_PACKEDBYTES)]
    );                              //                                =256+6*320*8=15616
    
    localparam POLYT1_PACKEDBYTES = 320;
    localparam SEEDBYTES = 32;
    localparam K = 6;
    
    assign pk_out[255:0] = rho_in;
    
    generate
        genvar i;
        for (i = 0; i < K; i = i + 1)
            polyt1_pack polyt1_pack(.a_in(t1_in[8192 * i + 8191:8192 * i]), .r_out(pk_out[8 * POLYT1_PACKEDBYTES * i + 8 * POLYT1_PACKEDBYTES - 1 + 256:8 * POLYT1_PACKEDBYTES * i + 256]));
	endgenerate
	
endmodule