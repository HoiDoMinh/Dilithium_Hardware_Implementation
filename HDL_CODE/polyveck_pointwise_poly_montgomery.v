module polyveck_pointwise_poly_montgomery (
    input  wire                   clock,
    input  wire                   reset,
    input  wire                   start,
    input  wire signed [8191:0]   a_in,   // 1 Poly A (Gi? nguyên)
    input  wire signed [49151:0]  v_in,   // Vector V (6 Poly -> 49152 bits)
    output reg  signed [49151:0]  r_out,  // Result   (6 Poly -> 49152 bits)
    output reg                    done
);

    // THAY ??I PARAMETER: K = 6
    localparam K = 6;
    localparam N = 256;

    // --- 1. DATA UNPACKING ---
    wire signed [31:0] a_coeffs [0:N-1];
    wire signed [31:0] v_coeffs [0:K-1][0:N-1]; // M?ng 2 chi?u kích th??c K=6

    genvar i, k;
    generate
        // Unpack A
        for (i = 0; i < N; i = i + 1) begin : UNPACK_A
            assign a_coeffs[i] = a_in[32*i + 31 : 32*i];
        end

        // Unpack V (K=6 polys)
        for (k = 0; k < K; k = k + 1) begin : UNPACK_V
            for (i = 0; i < N; i = i + 1) begin : UNPACK_V_COEFFS
                // Index bit ???c tính d?a trên K
                assign v_coeffs[k][i] = v_in[(k*N + i)*32 + 31 : (k*N + i)*32];
            end
        end
    endgenerate

    // --- 2. INTERNAL VARIABLES ---
    reg  [8:0] counter;
    reg        running;
    
    // Khai báo integer ? ??u module ?? tránh l?i syntax
    integer store_idx; 
    integer r; // Bi?n dùng cho vòng l?p reset (n?u c?n)

    // Input registers cho b? nhân (Pipeline Stage 1)
    reg signed [31:0] reg_a;
    reg signed [31:0] reg_v [0:K-1]; // M?ng thanh ghi kích th??c 6
    
    // Wires k?t qu? t? b? Reduce (Combinational)
    wire signed [31:0] res_node [0:K-1];

    // --- 3. CALCULATION CORE (6 Parallel Units) ---
    generate
        for (k = 0; k < K; k = k + 1) begin : CALC_UNITS
            wire signed [63:0] product;
            
            // Nhân: a * v (K?t qu? 64 bit)
            assign product = reg_a * reg_v[k];
            
            // Reduce: G?i module t? h?p
            montgomery_reduce u_red (
                .a(product),
                .t(res_node[k])
            );
        end
    endgenerate

    // --- 4. CONTROL LOGIC & PIPELINE ---
    always @(posedge clock) begin
        if (reset) begin
            counter <= 0;
            running <= 0;
            done    <= 0;
            r_out   <= 0;
            reg_a   <= 0;
            
            // Reset th? công cho 6 thanh ghi (K=6)
            reg_v[0] <= 0; reg_v[1] <= 0; reg_v[2] <= 0; 
            reg_v[3] <= 0; reg_v[4] <= 0; reg_v[5] <= 0;
            
        end else begin
            // Logic Start
            if (start) begin
                running <= 1;
                counter <= 0;
                done    <= 0;
            end

            if (running) begin
                // --- STAGE 1: FETCH DATA ---
                if (counter < N) begin
                    reg_a    <= a_coeffs[counter];
                    
                    // Load d? li?u cho 6 poly
                    reg_v[0] <= v_coeffs[0][counter];
                    reg_v[1] <= v_coeffs[1][counter];
                    reg_v[2] <= v_coeffs[2][counter];
                    reg_v[3] <= v_coeffs[3][counter];
                    reg_v[4] <= v_coeffs[4][counter];
                    reg_v[5] <= v_coeffs[5][counter]; // Thêm poly th? 6
                end

                // --- STAGE 2: STORE RESULT ---
                if (counter > 0) begin
                    store_idx = counter - 1;
                    
                    // L?u k?t qu? cho 6 poly
                    r_out[(0*N + store_idx)*32 +: 32] <= res_node[0];
                    r_out[(1*N + store_idx)*32 +: 32] <= res_node[1];
                    r_out[(2*N + store_idx)*32 +: 32] <= res_node[2];
                    r_out[(3*N + store_idx)*32 +: 32] <= res_node[3];
                    r_out[(4*N + store_idx)*32 +: 32] <= res_node[4];
                    r_out[(5*N + store_idx)*32 +: 32] <= res_node[5]; // Thêm poly th? 6
                end

                // --- CONTROL ---
                if (counter == N) begin
                    running <= 0;
                    done    <= 1;
                end else begin
                    counter <= counter + 1;
                end
            end else begin
                done <= 0; 
            end
        end
    end

endmodule
