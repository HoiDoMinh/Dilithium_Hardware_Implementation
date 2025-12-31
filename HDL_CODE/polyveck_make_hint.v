module polyveck_make_hint (
    input  wire                 clock,
    input  wire                 reset,
    input  wire                 start,
    input  wire signed [49151:0] v0_in,
    input  wire signed [49151:0] v1_in,
    output reg  signed [49151:0] h_out,
    output reg         [31:0]    count,
    output reg                  done
);

    localparam K = 6;

    // 1. INPUT REGISTERS (Ch?t d? li?u ??u vào)
    reg signed [49151:0] v0_reg;
    reg signed [49151:0] v1_reg;

    // 2. WIRES CHO LOGIC T? H?P
    wire signed [8191:0] v0_slice [0:K-1];
    wire signed [8191:0] v1_slice [0:K-1];
    wire signed [8191:0] h_slice  [0:K-1];
    wire [8:0]           s_slice  [0:K-1];
    
    // Wire t?ng h?p k?t qu?
    wire [49151:0] h_comb_result;
    wire [31:0]    count_comb_result;

    // 3. INSTANTIATE LOGIC T? H?P (Gi? nguyên logic c? c?a b?n)
    genvar i;
    generate
        for (i = 0; i < K; i = i + 1) begin : GEN_VEC
            // L?y input t? REGISTER thay vì input port
            assign v0_slice[i] = v0_reg[8192*i + 8191 : 8192*i];
            assign v1_slice[i] = v1_reg[8192*i + 8191 : 8192*i];

            // Module con v?n là t? h?p
            poly_make_hint u_poly_make_hint (
                .a0_in (v0_slice[i]),
                .a1_in (v1_slice[i]),
                .h_out (h_slice[i]),
                .count (s_slice[i])
            );

            // Gom k?t qu? vào wire t?ng
            assign h_comb_result[8192*i + 8191 : 8192*i] = h_slice[i];
        end
    endgenerate

    assign count_comb_result = s_slice[0] + s_slice[1] + s_slice[2] + s_slice[3] + s_slice[4] + s_slice[5];

    // 4. FSM ?I?U KHI?N (State Machine)
    reg [1:0] state;
    localparam S_IDLE = 0, S_CALC = 1, S_DONE = 2;

    always @(posedge clock) begin
        if (reset) begin
            state   <= S_IDLE;
            done    <= 0;
            h_out   <= 0;
            count   <= 0;
            v0_reg  <= 0;
            v1_reg  <= 0;
        end else begin
            case (state)
                S_IDLE: begin
                    done <= 0;
                    if (start) begin
                        // L?y m?u Input
                        v0_reg <= v0_in;
                        v1_reg <= v1_in;
                        state  <= S_CALC;
                    end
                end

                S_CALC: begin
                    // ??i 1 chu k? cho m?ch t? h?p ?n ??nh
                    // Sau ?ó ch?t k?t qu? vào Output Register
                    h_out <= h_comb_result;
                    count <= count_comb_result;
                    state <= S_DONE;
                end

                S_DONE: begin
                    done  <= 1;
                    state <= S_IDLE; // Ho?c ch? handshake n?u c?n
                end
            endcase
        end
    end

endmodule
