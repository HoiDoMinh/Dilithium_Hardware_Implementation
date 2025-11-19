/*
module pack_sk(
    input [255:0] rho_in,
    input [255:0] key_in,
    input [255:0] tr_in,
    input [49151:0] t0_in,
    input [40959:0] s1_in,
    input [49151:0] s2_in,
    output [29183:0] sk_out
    );
    
    localparam K = 6;
    localparam L = 5;
    localparam POLYETA_PACKEDBYTES = 96;
    
    assign sk_out[255:0] = rho_in;
    assign sk_out[511:256] = key_in;
    assign sk_out[767:512] = tr_in;
    
    wire [L*1024-1:0] polyeta_pack_s1;   // 5*1024 = 5120 bit
    
    generate
        genvar i;
        for (i = 0; i < L; i = i + 1) begin
             polyeta_pack polyeta_pack_1(.a_in(s1_in[8192 * i + 8191:8192 * i]), .r_out(polyeta_pack_s1[1024*i + 1023 : 1024*i]));
	    end
    endgenerate

    assign sk_out[4607:768] = polyeta_pack_s1;
    
    wire [K*1024-1:0] polyeta_pack_s2;   // 6*1024 = 6144 bit
    generate
        for (i = 0; i < K; i = i + 1) begin
             polyeta_pack polyeta_pack_2(.a_in(s2_in[8192 * i + 8191:8192 * i]), .r_out(polyeta_pack_s2[1024*i + 1023 : 1024*i]));
	    end
    endgenerate

    assign sk_out[9215:4608] = polyeta_pack_s2; 

    wire [19967:0] polyet0_pack;
    
    generate
        for (i = 0; i < K; i = i + 1) begin
             polyt0_pack polyt0_pack_1(.a_in(t0_in[8192 * i + 8191:8192 * i]), .r_out(polyet0_pack[3328 * i + 3327:3328 * i]));
	    end
    endgenerate
    
    assign sk_out[29183:9216] = polyet0_pack; 
    	
endmodule
*/





module pack_sk(
    input  [255:0]     rho_in,      // 32 bytes
    input  [255:0]     key_in,      // 32 bytes
    input  [511:0]     tr_in,       // 64 bytes (TRBYTES = 64)
    input  [49151:0]   t0_in,       // 6 polys × 8192 bit
    input  [40959:0]   s1_in,       // 5 polys × 8192 bit
    input  [49151:0]   s2_in,       // 6 polys × 8192 bit
    output [32255:0]   sk_out       // 4032 bytes = 32256 bits
);

    localparam K = 6;
    localparam L = 5;
    localparam POLYETA_PACKEDBYTES = 128;   // ETA=4
    localparam POLYT0_PACKEDBYTES  = 416;   // 3328 bit


    // 1) rho (32 bytes)
    assign sk_out[255:0] = rho_in;
    // 2) key (32 bytes)
    assign sk_out[511:256] = key_in;
    // 3) tr (64 bytes = 512 bit)
    assign sk_out[1023:512] = tr_in;
    // 4) s1 : L polys, each = 128 bytes = 1024 bit
    wire [L*1024-1:0] polyeta_pack_s1;

    genvar i;
    generate
        for (i = 0; i < L; i = i + 1) begin : pack_s1_loop
            polyeta_pack polyeta_s1 (
                .a_in (s1_in[8192*i + 8191 : 8192*i]),
                .r_out(polyeta_pack_s1[1024*i + 1023 : 1024*i])
            );
        end
    endgenerate

    assign sk_out[6143:1024] = polyeta_pack_s1;

    // 5) s2 : K polys, each = 128 bytes = 1024 bit
    wire [K*1024-1:0] polyeta_pack_s2;

    generate
        for (i = 0; i < K; i = i + 1) begin : pack_s2_loop
            polyeta_pack polyeta_s2 (
                .a_in (s2_in[8192*i + 8191 : 8192*i]),
                .r_out(polyeta_pack_s2[1024*i + 1023 : 1024*i])
            );
        end
    endgenerate

    // s2 b?t ??u t? bit 6144
    assign sk_out[12287:6144] = polyeta_pack_s2;

    // 6) t0 : K polys, each 416 bytes = 3328 bit
    wire [K*3328-1:0] polyt0_pack_out;

    generate
        for(i = 0; i < K; i = i + 1) begin : pack_t0_loop
            polyt0_pack polyt0_inst(
                .a_in(t0_in[8192*i + 8191 : 8192*i]),
                .r_out(polyt0_pack_out[3328*i + 3327 : 3328*i])
            );
        end
    endgenerate
    // t0 from 12288
    assign sk_out[32255:12288] = polyt0_pack_out;

endmodule
