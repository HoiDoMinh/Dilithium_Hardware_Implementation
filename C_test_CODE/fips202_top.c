/******************************************************************************
 * File: fips202_top.c
 * Description: Complete top-level wrapper for Vivado HLS synthesis of FIPS202
 * Author: HLS Implementation
 * Date: 2025
 *
 * This file provides HLS-friendly wrappers for:
 * - SHA3-256 (fixed 32-byte output)
 * - SHAKE256 (variable output, up to 64 bytes)
 * - Keccak-f[1600] core permutation
 *
 * All functions use fixed-size arrays for HLS compatibility
 ******************************************************************************/

#include "fips202.h"
#include <stdint.h>
#include <stddef.h>

// ============================================================================
// CONFIGURATION PARAMETERS
// ============================================================================

#define MAX_INPUT_SIZE   256   // Maximum input message size (bytes)
#define MAX_OUTPUT_SIZE  64    // Maximum output size for SHAKE (bytes)
#define SHA3_256_OUTPUT  32    // SHA3-256 output size (bytes)
#define NROUNDS          24    // Keccak-f[1600] rounds

// Keccak round constants (copied for top function access)
static const uint64_t RC[24] = {
    0x0000000000000001ULL, 0x0000000000008082ULL, 0x800000000000808aULL,
    0x8000000080008000ULL, 0x000000000000808bULL, 0x0000000080000001ULL,
    0x8000000080008081ULL, 0x8000000000008009ULL, 0x000000000000008aULL,
    0x0000000000000088ULL, 0x0000000080008009ULL, 0x000000008000000aULL,
    0x000000008000808bULL, 0x800000000000008bULL, 0x8000000000008089ULL,
    0x8000000000008003ULL, 0x8000000000008002ULL, 0x8000000000000080ULL,
    0x000000000000800aULL, 0x800000008000000aULL, 0x8000000080008081ULL,
    0x8000000000008080ULL, 0x0000000080000001ULL, 0x8000000080008008ULL
};

// ROL macro (rotate left)
#define ROL(a, offset) (((a) << (offset)) ^ ((a) >> (64-(offset))))

// ============================================================================
// TOP FUNCTION 1: SHA3-256 (RECOMMENDED FOR BEGINNERS)
// ============================================================================

/*************************************************
 * Name:        fips202_sha3_256_top
 *
 * Description: Top-level function for SHA3-256 hash
 *              This is the SIMPLEST option for HLS synthesis
 *              Fixed input/output sizes make it easy to synthesize
 *
 * Arguments:   - uint8_t output[32]: 32-byte output hash
 *              - uint8_t input[MAX_INPUT_SIZE]: input message buffer
 *              - unsigned int input_len: actual input length (0 to MAX_INPUT_SIZE)
 *
 * Returns:     None (output written to output array)
 *
 * HLS Directives:
 *   - s_axilite: Control interface for CPU
 *   - m_axi: Memory-mapped interface for data transfer
 **************************************************/
void fips202_sha3_256_top(
    uint8_t output[SHA3_256_OUTPUT],
    uint8_t input[MAX_INPUT_SIZE],
    unsigned int input_len
)
{
    // ========== HLS INTERFACE PRAGMAS ==========

    // Control interface (for CPU to trigger function)
    #pragma HLS INTERFACE mode=s_axilite port=return bundle=control
    #pragma HLS INTERFACE mode=s_axilite port=input_len bundle=control

    // Memory interfaces (for data transfer via AXI)
    #pragma HLS INTERFACE mode=m_axi depth=32 port=output offset=slave bundle=gmem0
    #pragma HLS INTERFACE mode=m_axi depth=256 port=input offset=slave bundle=gmem1

    // ========== DATAFLOW OPTIMIZATION ==========
    #pragma HLS DATAFLOW

    // Boundary check to prevent overflow
    unsigned int actual_len = input_len;
    if (actual_len > MAX_INPUT_SIZE) {
        actual_len = MAX_INPUT_SIZE;
    }

    // Call the SHA3-256 function from fips202.c
    sha3_256(output, input, actual_len);
}

// ============================================================================
// TOP FUNCTION 2: SHAKE256 (Variable Output)
// ============================================================================

/*************************************************
 * Name:        fips202_shake256_top
 *
 * Description: Top-level function for SHAKE256 XOF (eXtendable Output Function)
 *              Supports variable-length output up to MAX_OUTPUT_SIZE bytes
 *
 * Arguments:   - uint8_t output[MAX_OUTPUT_SIZE]: output buffer
 *              - uint8_t input[MAX_INPUT_SIZE]: input message buffer
 *              - unsigned int input_len: actual input length
 *              - unsigned int output_len: desired output length (0 to MAX_OUTPUT_SIZE)
 *
 * Returns:     None (output written to output array)
 **************************************************/
void fips202_shake256_top(
    uint8_t output[MAX_OUTPUT_SIZE],
    uint8_t input[MAX_INPUT_SIZE],
    unsigned int input_len,
    unsigned int output_len
)
{
    // ========== HLS INTERFACE PRAGMAS ==========
    #pragma HLS INTERFACE mode=s_axilite port=return bundle=control
    #pragma HLS INTERFACE mode=s_axilite port=input_len bundle=control
    #pragma HLS INTERFACE mode=s_axilite port=output_len bundle=control

    #pragma HLS INTERFACE mode=m_axi depth=64 port=output offset=slave bundle=gmem0
    #pragma HLS INTERFACE mode=m_axi depth=256 port=input offset=slave bundle=gmem1

    // ========== DATAFLOW OPTIMIZATION ==========
    #pragma HLS DATAFLOW

    // Boundary checks
    unsigned int actual_inlen = input_len;
    unsigned int actual_outlen = output_len;

    if (actual_inlen > MAX_INPUT_SIZE) {
        actual_inlen = MAX_INPUT_SIZE;
    }
    if (actual_outlen > MAX_OUTPUT_SIZE) {
        actual_outlen = MAX_OUTPUT_SIZE;
    }

    // Call SHAKE256
    shake256(output, actual_outlen, input, actual_inlen);
}

// ============================================================================
// TOP FUNCTION 3: KECCAK CORE ONLY (For Advanced Users)
// ============================================================================

/*************************************************
 * Name:        fips202_keccak_permute_top
 *
 * Description: Direct access to Keccak-f[1600] permutation
 *              This is the CORE cryptographic primitive
 *              Useful for custom implementations or research
 *
 * Arguments:   - uint64_t state[25]: 1600-bit state (25 x 64-bit words)
 *                                    Input/output (modified in-place)
 *
 * Returns:     None (state modified in-place)
 *
 * Note: This implements the full Keccak-f[1600] permutation
 *       by copying the code from KeccakF1600_StatePermute
 *       (cannot call static function directly)
 **************************************************/
void fips202_keccak_permute_top(uint64_t state[25])
{
    // ========== HLS INTERFACE PRAGMAS ==========
    #pragma HLS INTERFACE mode=s_axilite port=return bundle=control
    #pragma HLS INTERFACE mode=bram port=state depth=25

    // ========== ARRAY PARTITIONING ==========
    // Partition state array for parallel access
    #pragma HLS ARRAY_PARTITION variable=state cyclic factor=5 dim=1

    // ========== LOCAL VARIABLES ==========
    int round;

    // 5x5 state lanes (A array)
    uint64_t Aba, Abe, Abi, Abo, Abu;
    uint64_t Aga, Age, Agi, Ago, Agu;
    uint64_t Aka, Ake, Aki, Ako, Aku;
    uint64_t Ama, Ame, Ami, Amo, Amu;
    uint64_t Asa, Ase, Asi, Aso, Asu;

    // Temporary variables for Theta
    uint64_t BCa, BCe, BCi, BCo, BCu;
    uint64_t Da, De, Di, Do, Du;

    // 5x5 state lanes (E array - after transformation)
    uint64_t Eba, Ebe, Ebi, Ebo, Ebu;
    uint64_t Ega, Ege, Egi, Ego, Egu;
    uint64_t Eka, Eke, Eki, Eko, Eku;
    uint64_t Ema, Eme, Emi, Emo, Emu;
    uint64_t Esa, Ese, Esi, Eso, Esu;

    // ========== LOAD STATE FROM ARRAY ==========
    #pragma HLS PIPELINE off
    Aba = state[0];  Abe = state[1];  Abi = state[2];  Abo = state[3];  Abu = state[4];
    Aga = state[5];  Age = state[6];  Agi = state[7];  Ago = state[8];  Agu = state[9];
    Aka = state[10]; Ake = state[11]; Aki = state[12]; Ako = state[13]; Aku = state[14];
    Ama = state[15]; Ame = state[16]; Ami = state[17]; Amo = state[18]; Amu = state[19];
    Asa = state[20]; Ase = state[21]; Asi = state[22]; Aso = state[23]; Asu = state[24];

    // ========== 24 ROUNDS OF KECCAK-F[1600] ==========
    // Loop is unrolled by factor of 2 (processes 2 rounds per iteration)
    #pragma HLS PIPELINE off
    ROUND_LOOP: for(round = 0; round < NROUNDS; round += 2) {
        // Hint to unroll loop by 2
        #pragma HLS UNROLL factor=2

        // ==================== ROUND n (EVEN) ====================

        // --- THETA: Linear mixing of columns ---
        BCa = Aba ^ Aga ^ Aka ^ Ama ^ Asa;
        BCe = Abe ^ Age ^ Ake ^ Ame ^ Ase;
        BCi = Abi ^ Agi ^ Aki ^ Ami ^ Asi;
        BCo = Abo ^ Ago ^ Ako ^ Amo ^ Aso;
        BCu = Abu ^ Agu ^ Aku ^ Amu ^ Asu;

        Da = BCu ^ ROL(BCe, 1);
        De = BCa ^ ROL(BCi, 1);
        Di = BCe ^ ROL(BCo, 1);
        Do = BCi ^ ROL(BCu, 1);
        Du = BCo ^ ROL(BCa, 1);

        // --- RHO + PI + CHI + IOTA: Slice 0 ---
        Aba ^= Da; BCa = Aba;
        Age ^= De; BCe = ROL(Age, 44);
        Aki ^= Di; BCi = ROL(Aki, 43);
        Amo ^= Do; BCo = ROL(Amo, 21);
        Asu ^= Du; BCu = ROL(Asu, 14);
        Eba = BCa ^ ((~BCe) & BCi);
        Eba ^= RC[round];
        Ebe = BCe ^ ((~BCi) & BCo);
        Ebi = BCi ^ ((~BCo) & BCu);
        Ebo = BCo ^ ((~BCu) & BCa);
        Ebu = BCu ^ ((~BCa) & BCe);

        // --- RHO + PI + CHI + IOTA: Slice 1 ---
        Abo ^= Do; BCa = ROL(Abo, 28);
        Agu ^= Du; BCe = ROL(Agu, 20);
        Aka ^= Da; BCi = ROL(Aka, 3);
        Ame ^= De; BCo = ROL(Ame, 45);
        Asi ^= Di; BCu = ROL(Asi, 61);
        Ega = BCa ^ ((~BCe) & BCi);
        Ege = BCe ^ ((~BCi) & BCo);
        Egi = BCi ^ ((~BCo) & BCu);
        Ego = BCo ^ ((~BCu) & BCa);
        Egu = BCu ^ ((~BCa) & BCe);

        // --- RHO + PI + CHI + IOTA: Slice 2 ---
        Abe ^= De; BCa = ROL(Abe, 1);
        Agi ^= Di; BCe = ROL(Agi, 6);
        Ako ^= Do; BCi = ROL(Ako, 25);
        Amu ^= Du; BCo = ROL(Amu, 8);
        Asa ^= Da; BCu = ROL(Asa, 18);
        Eka = BCa ^ ((~BCe) & BCi);
        Eke = BCe ^ ((~BCi) & BCo);
        Eki = BCi ^ ((~BCo) & BCu);
        Eko = BCo ^ ((~BCu) & BCa);
        Eku = BCu ^ ((~BCa) & BCe);

        // --- RHO + PI + CHI + IOTA: Slice 3 ---
        Abu ^= Du; BCa = ROL(Abu, 27);
        Aga ^= Da; BCe = ROL(Aga, 36);
        Ake ^= De; BCi = ROL(Ake, 10);
        Ami ^= Di; BCo = ROL(Ami, 15);
        Aso ^= Do; BCu = ROL(Aso, 56);
        Ema = BCa ^ ((~BCe) & BCi);
        Eme = BCe ^ ((~BCi) & BCo);
        Emi = BCi ^ ((~BCo) & BCu);
        Emo = BCo ^ ((~BCu) & BCa);
        Emu = BCu ^ ((~BCa) & BCe);

        // --- RHO + PI + CHI + IOTA: Slice 4 ---
        Abi ^= Di; BCa = ROL(Abi, 62);
        Ago ^= Do; BCe = ROL(Ago, 55);
        Aku ^= Du; BCi = ROL(Aku, 39);
        Ama ^= Da; BCo = ROL(Ama, 41);
        Ase ^= De; BCu = ROL(Ase, 2);
        Esa = BCa ^ ((~BCe) & BCi);
        Ese = BCe ^ ((~BCi) & BCo);
        Esi = BCi ^ ((~BCo) & BCu);
        Eso = BCo ^ ((~BCu) & BCa);
        Esu = BCu ^ ((~BCa) & BCe);

        // ==================== ROUND n+1 (ODD) ====================

        // --- THETA ---
        BCa = Eba ^ Ega ^ Eka ^ Ema ^ Esa;
        BCe = Ebe ^ Ege ^ Eke ^ Eme ^ Ese;
        BCi = Ebi ^ Egi ^ Eki ^ Emi ^ Esi;
        BCo = Ebo ^ Ego ^ Eko ^ Emo ^ Eso;
        BCu = Ebu ^ Egu ^ Eku ^ Emu ^ Esu;

        Da = BCu ^ ROL(BCe, 1);
        De = BCa ^ ROL(BCi, 1);
        Di = BCe ^ ROL(BCo, 1);
        Do = BCi ^ ROL(BCu, 1);
        Du = BCo ^ ROL(BCa, 1);

        // --- RHO + PI + CHI + IOTA: Slice 0 ---
        Eba ^= Da; BCa = Eba;
        Ege ^= De; BCe = ROL(Ege, 44);
        Eki ^= Di; BCi = ROL(Eki, 43);
        Emo ^= Do; BCo = ROL(Emo, 21);
        Esu ^= Du; BCu = ROL(Esu, 14);
        Aba = BCa ^ ((~BCe) & BCi);
        Aba ^= RC[round + 1];
        Abe = BCe ^ ((~BCi) & BCo);
        Abi = BCi ^ ((~BCo) & BCu);
        Abo = BCo ^ ((~BCu) & BCa);
        Abu = BCu ^ ((~BCa) & BCe);

        // --- RHO + PI + CHI + IOTA: Slice 1 ---
        Ebo ^= Do; BCa = ROL(Ebo, 28);
        Egu ^= Du; BCe = ROL(Egu, 20);
        Eka ^= Da; BCi = ROL(Eka, 3);
        Eme ^= De; BCo = ROL(Eme, 45);
        Esi ^= Di; BCu = ROL(Esi, 61);
        Aga = BCa ^ ((~BCe) & BCi);
        Age = BCe ^ ((~BCi) & BCo);
        Agi = BCi ^ ((~BCo) & BCu);
        Ago = BCo ^ ((~BCu) & BCa);
        Agu = BCu ^ ((~BCa) & BCe);

        // --- RHO + PI + CHI + IOTA: Slice 2 ---
        Ebe ^= De; BCa = ROL(Ebe, 1);
        Egi ^= Di; BCe = ROL(Egi, 6);
        Eko ^= Do; BCi = ROL(Eko, 25);
        Emu ^= Du; BCo = ROL(Emu, 8);
        Esa ^= Da; BCu = ROL(Esa, 18);
        Aka = BCa ^ ((~BCe) & BCi);
        Ake = BCe ^ ((~BCi) & BCo);
        Aki = BCi ^ ((~BCo) & BCu);
        Ako = BCo ^ ((~BCu) & BCa);
        Aku = BCu ^ ((~BCa) & BCe);

        // --- RHO + PI + CHI + IOTA: Slice 3 ---
        Ebu ^= Du; BCa = ROL(Ebu, 27);
        Ega ^= Da; BCe = ROL(Ega, 36);
        Eke ^= De; BCi = ROL(Eke, 10);
        Emi ^= Di; BCo = ROL(Emi, 15);
        Eso ^= Do; BCu = ROL(Eso, 56);
        Ama = BCa ^ ((~BCe) & BCi);
        Ame = BCe ^ ((~BCi) & BCo);
        Ami = BCi ^ ((~BCo) & BCu);
        Amo = BCo ^ ((~BCu) & BCa);
        Amu = BCu ^ ((~BCa) & BCe);

        // --- RHO + PI + CHI + IOTA: Slice 4 ---
        Ebi ^= Di; BCa = ROL(Ebi, 62);
        Ego ^= Do; BCe = ROL(Ego, 55);
        Eku ^= Du; BCi = ROL(Eku, 39);
        Ema ^= Da; BCo = ROL(Ema, 41);
        Ese ^= De; BCu = ROL(Ese, 2);
        Asa = BCa ^ ((~BCe) & BCi);
        Ase = BCe ^ ((~BCi) & BCo);
        Asi = BCi ^ ((~BCo) & BCu);
        Aso = BCo ^ ((~BCu) & BCa);
        Asu = BCu ^ ((~BCa) & BCe);
    }

    // ========== STORE STATE BACK TO ARRAY ==========
    #pragma HLS PIPELINE off
    state[0] = Aba;  state[1] = Abe;  state[2] = Abi;  state[3] = Abo;  state[4] = Abu;
    state[5] = Aga;  state[6] = Age;  state[7] = Agi;  state[8] = Ago;  state[9] = Agu;
    state[10] = Aka; state[11] = Ake; state[12] = Aki; state[13] = Ako; state[14] = Aku;
    state[15] = Ama; state[16] = Ame; state[17] = Ami; state[18] = Amo; state[19] = Amu;
    state[20] = Asa; state[21] = Ase; state[22] = Asi; state[23] = Aso; state[24] = Asu;
}

// ============================================================================
// TOP FUNCTION 4: SHAKE128 (Alternative XOF with different rate)
// ============================================================================

/*************************************************
 * Name:        fips202_shake128_top
 *
 * Description: Top-level function for SHAKE128 XOF
 *              Alternative to SHAKE256 with different security level
 *              SHAKE128 has rate=168 bytes vs SHAKE256 rate=136 bytes
 *
 * Arguments:   - uint8_t output[MAX_OUTPUT_SIZE]: output buffer
 *              - uint8_t input[MAX_INPUT_SIZE]: input message buffer
 *              - unsigned int input_len: actual input length
 *              - unsigned int output_len: desired output length
 *
 * Returns:     None (output written to output array)
 **************************************************/
void fips202_shake128_top(
    uint8_t output[MAX_OUTPUT_SIZE],
    uint8_t input[MAX_INPUT_SIZE],
    unsigned int input_len,
    unsigned int output_len
)
{
    // ========== HLS INTERFACE PRAGMAS ==========
    #pragma HLS INTERFACE mode=s_axilite port=return bundle=control
    #pragma HLS INTERFACE mode=s_axilite port=input_len bundle=control
    #pragma HLS INTERFACE mode=s_axilite port=output_len bundle=control

    #pragma HLS INTERFACE mode=m_axi depth=64 port=output offset=slave bundle=gmem0
    #pragma HLS INTERFACE mode=m_axi depth=256 port=input offset=slave bundle=gmem1

    // ========== DATAFLOW OPTIMIZATION ==========
    #pragma HLS DATAFLOW

    // Boundary checks
    unsigned int actual_inlen = input_len;
    unsigned int actual_outlen = output_len;

    if (actual_inlen > MAX_INPUT_SIZE) {
        actual_inlen = MAX_INPUT_SIZE;
    }
    if (actual_outlen > MAX_OUTPUT_SIZE) {
        actual_outlen = MAX_OUTPUT_SIZE;
    }

    // Call SHAKE128
    shake128(output, actual_outlen, input, actual_inlen);
}

// ============================================================================
// TOP FUNCTION 5: SHA3-512 (64-byte output)
// ============================================================================

/*************************************************
 * Name:        fips202_sha3_512_top
 *
 * Description: Top-level function for SHA3-512 hash
 *              Produces 64-byte (512-bit) hash output
 *
 * Arguments:   - uint8_t output[64]: 64-byte output hash
 *              - uint8_t input[MAX_INPUT_SIZE]: input message buffer
 *              - unsigned int input_len: actual input length
 *
 * Returns:     None (output written to output array)
 **************************************************/
void fips202_sha3_512_top(
    uint8_t output[64],
    uint8_t input[MAX_INPUT_SIZE],
    unsigned int input_len
)
{
    // ========== HLS INTERFACE PRAGMAS ==========
    #pragma HLS INTERFACE mode=s_axilite port=return bundle=control
    #pragma HLS INTERFACE mode=s_axilite port=input_len bundle=control

    #pragma HLS INTERFACE mode=m_axi depth=64 port=output offset=slave bundle=gmem0
    #pragma HLS INTERFACE mode=m_axi depth=256 port=input offset=slave bundle=gmem1

    // ========== DATAFLOW OPTIMIZATION ==========
    #pragma HLS DATAFLOW

    // Boundary check
    unsigned int actual_len = input_len;
    if (actual_len > MAX_INPUT_SIZE) {
        actual_len = MAX_INPUT_SIZE;
    }

    // Call SHA3-512
    sha3_512(output, input, actual_len);
}

// ============================================================================
// END OF FILE
// ============================================================================
