module SHAKE256 #(
    parameter r       = 1088,         // rate = 1088 bit cho SHAKE256
    parameter c       = 512,          // capacity = 512
    parameter outlen  = 511,          // output bits
    parameter len     = 512           // input bits
)(
    input  [len-1:0] in,
    input  clk, reset,
    input  start,
    output reg done,
    output [outlen:0] SHAKEout
);


    // 1. PAD 

    localparam PADDED = ((len + 5 + 1 + r - 1) / r) * r; 

    reg [PADDED-1:0] P;

    always @(*) begin
        P                = 0;
        P[len-1:0]       = in;          // input
        P[len +: 5]      = 5'b11111;   // domain separator
        P[PADDED-1]      = 1'b1;       // final bit
    end

    // 2. CHIA thành các block 1088-bit ?? absorb vào state Keccak
    localparam BLOCKS = PADDED / r;

    wire [r-1:0] P_slices [0:BLOCKS-1];

    genvar i;
    generate
        for (i = 0; i < BLOCKS; i = i + 1) begin
            assign P_slices[i] = P[r*i + r-1 : r*i];
        end
    endgenerate


    // 3. State Keccak

    reg [1599:0] A;
    wire [1599:0] Aout;


    // 4. FSM: Absorb ? Permute
    localparam IDLE = 0, WAIT = 1, LOAD = 2, ABSORB = 3, PERMUTE = 4, DONE = 5;

    reg [2:0] state, next_state;
    reg [7:0] index;
    reg rstPF;
    reg [3:0] rstcount;

    always @(posedge clk) begin
        if (reset) state <= IDLE;
        else state <= next_state;
    end

    always @(*) begin
        case (state)
        IDLE:    next_state = WAIT;
        WAIT:    next_state = start ? LOAD : WAIT;
        LOAD:    next_state = ABSORB;
        ABSORB:  next_state = PERMUTE;
        PERMUTE: next_state = (rstcount < 10) ? PERMUTE :
                              (index == BLOCKS-1) ? DONE : ABSORB;
        DONE:    next_state = (!start) ? IDLE : DONE;
        endcase
    end

    always @(posedge clk) begin
        case (state)
        LOAD: begin
            index   <= 0;
            rstPF   <= 1;
            rstcount <= 0;
            A       <= 0;
        end

        ABSORB: begin
            if (index == 0)
                A[r-1:0] <= P_slices[0];      // absorb block ??u
            else
                A <= Aout ^ P_slices[index];  // absorb block ti?p theo
            rstPF <= 1;
            rstcount <= 0;
        end

        PERMUTE: begin

            rstPF <= 0;
            rstcount <= rstcount + 1;
            if (rstcount == 10) index <= index + 1;
        end

        DONE: done <= 1;
        default: done <= 0;
        endcase
    end

    // KECCAK-f1600
    PermuteFunction KeccakF(
        .Ain(A),
        .Aout(Aout),
        .clk(clk),
        .rst(rstPF)
    );


    // 5. Output SHAKE256 
    wire [outlen:0] SHAKE = Aout[outlen:0];

    generate
        for (i = 0; i < (outlen + 1)/8; i = i + 1) begin
            assign SHAKEout[
                8 * (((outlen + 1)/8 - 1) - i) + 7 :
                8 * (((outlen + 1)/8 - 1) - i)
            ] = SHAKE[8*i + 7 : 8*i];
        end
    endgenerate

endmodule
