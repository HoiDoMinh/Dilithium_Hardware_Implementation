
module DILITHIUM_TOP_MODULE #(
    parameter M_MAX = 64,
    parameter PRE_MAX = 32
)(
    input  wire                 clock,
    input  wire                 reset,
    input  wire                 start_system, // Start complete pipeline
    
    // Data inputs for Sign/Verify
    input  wire [8*M_MAX-1:0]   m,
    input  wire [31:0]          mlen,
    input  wire [8*PRE_MAX-1:0] pre,
    input  wire [31:0]          prelen,
    input  wire [255:0]         rnd,          // Randomness for signing

    // System outputs
    output reg                  done_system,  // Pipeline complete
    output reg                  system_pass,  // 1 = Verify OK, 0 = Verify Failed
    
    // Debug outputs
    output wire [15615:0]       debug_pk,
    output wire [32255:0]       debug_sk,
    output wire [26471:0]       debug_sig
);
    
    
    // KeyGen Signals
    reg  start_keygen;
    wire done_keygen;
    wire [15615:0] pk_wire;
    wire [32255:0] sk_wire;
    
    reg [15615:0] pk_reg;
    reg [32255:0] sk_reg;

    // Sign Signals
    reg  start_sign;
    wire done_sign;
    wire [26471:0] sig_wire;
    
    // Register to store Signature
    reg [26471:0] sig_reg;

    // Verify Signals
    reg  start_verify;
    wire done_verify;
    wire verify_result_wire; // 0=Valid, 1=Invalid

    // Module 1: Key Generation
    crypto_sign_keypair u_keygen (
        .clock(clock),
        .reset(reset),
        .start_keygen(start_keygen),
        .done_keygen(done_keygen),
        .pk(pk_wire),
        .sk(sk_wire)
    );

    // Module 2: Signature Generation (uses SK from KeyGen)
    crypto_sign_signature_internal #(
        .M_MAX(M_MAX), 
        .PRE_MAX(PRE_MAX)
    ) u_signer (
        .clock(clock),
        .reset(reset),
        .start_sign_internal(start_sign),
        .done_sign_internal(done_sign),
        .sig(sig_wire),
   
        .m(m),
        .mlen(mlen),
        .pre(pre),
        .prelen(prelen),
        .rnd(rnd),
        .sk(sk_reg) // Use stored SK
    );

    // Module 3: Signature Verification (uses PK from KeyGen and SIG from Signer)
    crypto_sign_verify_internal #(
        .M_MAX(M_MAX), 
        .PRE_MAX(PRE_MAX)
    ) u_verifier (
        .clock(clock),
        .reset(reset),
        .start_verify(start_verify),
        
        .sig(sig_reg),
        .m(m),
        .mlen(mlen),
        .pre(pre),
        .prelen(prelen),
        .pk(pk_reg),   
        
        .verify_result(verify_result_wire),
        .done_verify(done_verify)
    );

    // Debug outputs (assign stored values)
    assign debug_pk = pk_reg;
    assign debug_sk = sk_reg;
    assign debug_sig = sig_reg;

    // FSM CONTROL

    reg [2:0] state, next_state;
    
    localparam S_IDLE    = 3'd0;
    localparam S_KEYGEN  = 3'd1;
    localparam S_SIGN    = 3'd2;
    localparam S_VERIFY  = 3'd3;
    localparam S_DONE    = 3'd4;

    // State register
    always @(posedge clock) begin
        if (reset) begin
            state <= S_IDLE;
        end else begin
            state <= next_state;
        end
    end

    // Next state logic
    always @(*) begin
        next_state = state;
        
        case (state)
            S_IDLE: begin
                if (start_system) begin
                    next_state = S_KEYGEN;
                end
            end

            S_KEYGEN: begin
                if (done_keygen) begin
                    next_state = S_SIGN;
                end
            end

            S_SIGN: begin
                if (done_sign) begin
                    next_state = S_VERIFY;
                end
            end

            S_VERIFY: begin
                if (done_verify) begin
                    next_state = S_DONE;
                end
            end

            S_DONE: begin
                next_state = S_DONE;
            end
            
            default: next_state = S_IDLE;
        endcase
    end

    // Output and datapath control
    always @(posedge clock) begin
        if (reset) begin
            // Reset all control signals
            start_keygen <= 1'b0;
            start_sign <= 1'b0;
            start_verify <= 1'b0;
            done_system <= 1'b0;
            system_pass <= 1'b0;
            
            // Reset data registers
            pk_reg <= {15616{1'b0}};
            sk_reg <= {32256{1'b0}};
            sig_reg <= {26472{1'b0}};
        end else begin
            start_keygen <= 1'b0;
            start_sign <= 1'b0;
            start_verify <= 1'b0;
            
            case (state)
                S_IDLE: begin
                    done_system <= 1'b0;
                    system_pass <= 1'b0;
                    
                    if (next_state == S_KEYGEN) begin
                        start_keygen <= 1'b1;
                    end
                end

                S_KEYGEN: begin
                    if (done_keygen) begin
                        pk_reg <= pk_wire;
                        sk_reg <= sk_wire;
                        
                        if (next_state == S_SIGN) begin
                            start_sign <= 1'b1;
                        end
                    end
                end

                S_SIGN: begin
                    if (done_sign) begin

                        sig_reg <= sig_wire;
                        
                        if (next_state == S_VERIFY) begin
                            start_verify <= 1'b1; 
                        end
                    end
                end

                S_VERIFY: begin
                    if (done_verify) begin
                        // verify_result_wire: 0=Valid, 1=Invalid
                        // system_pass: 1=Pass, 0=Fail
                        system_pass <= (verify_result_wire == 1'b0);
                        
                        if (next_state == S_DONE) begin
                            done_system <= 1'b1;
                        end
                    end
                end

                S_DONE: begin
                    done_system <= 1'b1;
                end
                
                default: begin
                    done_system <= 1'b0;
                    system_pass <= 1'b0;
                end
            endcase
        end
    end

endmodule