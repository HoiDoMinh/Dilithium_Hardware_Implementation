module pack_sig #(
    parameter CTILDEBYTES = 48,
    parameter L = 5,
    parameter K = 6,
    parameter N = 256,
    parameter OMEGA = 55,
    parameter POLYZ_PACKEDBYTES = 640,
    parameter CRYPTO_BYTES =
        CTILDEBYTES + L*POLYZ_PACKEDBYTES + (OMEGA + K)
)(
    input  [CTILDEBYTES*8-1:0]     c_in,
    input  [L*256*32-1:0]          z_in,
    input  [K*N*32-1:0]            h_in,
    output [CRYPTO_BYTES*8-1:0]    sig_out
);

    genvar i;

    // ---- 1. copy c ----
    generate
        for (i = 0; i < CTILDEBYTES; i = i + 1) begin
            assign sig_out[8*i +: 8] = c_in[8*i +: 8];
        end
    endgenerate

    // ---- 2. pack z ----
    wire [POLYZ_PACKEDBYTES*8-1:0] z_pack [0:L-1];

    generate
        for (i = 0; i < L; i = i + 1) begin
            polyz_pack u_pz (
                .a_in ( z_in[i*256*32 +: 256*32] ),
                .r_out( z_pack[i] )
            );

            assign sig_out[(CTILDEBYTES + i*POLYZ_PACKEDBYTES)*8
                            +: POLYZ_PACKEDBYTES*8] = z_pack[i];
        end
    endgenerate

    // ---- 3. encode h ----
    localparam H_OFFSET = CTILDEBYTES + L*POLYZ_PACKEDBYTES;

    integer ii, jj;
    reg [7:0] idx_val [0:OMEGA+K-1];
    reg [7:0] kpos;

    always @(*) begin
        // zero
        for (ii = 0; ii < OMEGA + K; ii = ii + 1)
            idx_val[ii] = 8'd0;

        kpos = 0;

        for (ii = 0; ii < K; ii = ii + 1) begin
            for (jj = 0; jj < N; jj = jj + 1) begin
                if (h_in[(ii*N + jj)*32 +: 32] != 32'd0) begin
                    if (kpos < OMEGA) begin
                        idx_val[kpos] = jj[7:0];
                        kpos = kpos + 1;
                    end
                end
            end
            idx_val[OMEGA + ii] = kpos;
        end
    end

    generate
        for (i = 0; i < OMEGA + K; i = i + 1) begin
            assign sig_out[(H_OFFSET + i)*8 +: 8] = idx_val[i];
        end
    endgenerate

endmodule

