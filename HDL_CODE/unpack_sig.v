module unpack_sig #(
    parameter CTILDEBYTES = 48,
    parameter L = 5,
    parameter K = 6,
    parameter N = 256,
    parameter OMEGA = 55,
    parameter POLYZ_PACKEDBYTES = 640,
    // T?ng kích th??c ch? ký
    parameter CRYPTO_BYTES = CTILDEBYTES + L*POLYZ_PACKEDBYTES + (OMEGA + K)
)(
    input  [CRYPTO_BYTES*8-1:0]    sig_in,
    
    output [CTILDEBYTES*8-1:0]     c_out,
    output [L*N*32-1:0]            z_out,
    output [K*N*32-1:0]            h_out,
   
    output reg                     valid_flag // 0 = Success, 1 = Error
);

    genvar i;
    integer k, j;

    // 1. Unpack 'c' (Challenge Hash)
    generate
        for (i = 0; i < CTILDEBYTES; i = i + 1) begin : copy_c
            assign c_out[8*i +: 8] = sig_in[8*i +: 8];
        end
    endgenerate

    // 2. Unpack 'z' (Vector L)
    localparam Z_OFFSET_BYTES = CTILDEBYTES;
    
    generate
        for (i = 0; i < L; i = i + 1) begin : unpack_z
            polyz_unpack u_pz_unpack (
                .a_in ( sig_in[(Z_OFFSET_BYTES + i*POLYZ_PACKEDBYTES)*8 +: POLYZ_PACKEDBYTES*8] ),
                .r_out( z_out[i*N*32 +: N*32] )
            );
        end
    endgenerate

    // 3. Decode 'h' (Hint Vector
  
    localparam H_OFFSET_BYTES = CTILDEBYTES + L*POLYZ_PACKEDBYTES;
    
    // M?ng t?m ?? l?u giá tr? h gi?i nén
    reg [31:0] h_temp [0:K-1][0:N-1]; 
    
    // Các bi?n dùng trong vòng l?p always block
    reg [7:0]  current_k;             // Bi?n k trong C
    reg [7:0]  limit_k;               // sig[OMEGA + i]
    reg [7:0]  sig_byte_j;            // sig[j]
    reg [7:0]  sig_byte_prev;         // sig[j-1]
    
    always @(*) begin
        valid_flag = 1'b0; 
        current_k = 8'd0;


        for (k = 0; k < K; k = k + 1) begin
            for (j = 0; j < N; j = j + 1) begin
                h_temp[k][j] = 32'd0;
            end
        end

        for (k = 0; k < K; k = k + 1) begin
            
            limit_k = sig_in[(H_OFFSET_BYTES + OMEGA + k)*8 +: 8];

            // Check C: if(sig[OMEGA + i] < k || sig[OMEGA + i] > OMEGA) return 1;
            if (limit_k < current_k || limit_k > OMEGA) begin
                valid_flag = 1'b1;
            end
            for (j = 0; j < OMEGA; j = j + 1) begin
                if (j >= current_k && j < limit_k) begin
                    // ??c sig[j] (Index hint)
                    sig_byte_j = sig_in[(H_OFFSET_BYTES + j)*8 +: 8];
                    
                    // if(j > k && sig[j] <= sig[j-1]) return 1;
                    if (j > current_k) begin
                        sig_byte_prev = sig_in[(H_OFFSET_BYTES + (j-1))*8 +: 8];
                        if (sig_byte_j <= sig_byte_prev) begin
                            valid_flag = 1'b1;
                        end
                    end
                    if (sig_byte_j < N) begin
                        h_temp[k][sig_byte_j] = 32'd1;
                    end
                end
            end
            current_k = limit_k;
        end

        // Check C cu?i cùng: Các ch? s? th?a ph?i b?ng 0
        // for(j = k; j < OMEGA; ++j) if(sig[j]) return 1;
        for (j = 0; j < OMEGA; j = j + 1) begin
            if (j >= current_k) begin
                sig_byte_j = sig_in[(H_OFFSET_BYTES + j)*8 +: 8];
                if (sig_byte_j != 8'd0) begin
                    valid_flag = 1'b1;
                end
            end
        end
    end

    generate
        genvar gk, gj;
        for (gk = 0; gk < K; gk = gk + 1) begin : flatten_h_k
            for (gj = 0; gj < N; gj = gj + 1) begin : flatten_h_n
                assign h_out[(gk*N + gj)*32 +: 32] = h_temp[gk][gj];
            end
        end
    endgenerate

endmodule