#if 0
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "sign.h"
#include "params.h"
#include "packing.h"
#include "polyvec.h"
#include "poly.h"
#include "randombytes.h"
#include "fips202.h"

#define MLEN    64
#define PRELEN  32

// Kích thước CHÍNH XÁC như trong Verilog testbench
#define POLYVECL_BYTES  5120  // L * N * 4 = 5 * 256 * 4
#define POLYVECK_BYTES  6144  // K * N * 4 = 6 * 256 * 4
#define POLY_BYTES      1024  // N * 4 = 256 * 4
#define SIG_BYTES       3309

void print_hex(const char *label, const void *buf, size_t len) {
    const uint8_t *bytes = buf;
    printf("%s (hex, %zu bytes)\n", label, len);
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", bytes[i]);
        if ((i % 52) == 51) printf("\n");
    }
    printf("\n\n");
}

void print_verilog_input_hex(const char *name, const uint8_t *buf, size_t len) {
    printf("%s[%zu:0] = %zu'h", name, len * 8 - 1, len * 8);
    for (int i = (int)len - 1; i >= 0; i--) {
        printf("%02x", buf[i]);
    }
    printf(";\n");
}

int main(void) {
    /* 1) CẤP BỘ NHỚ TĨNH ĐẦY ĐỦ */
    uint8_t sig[CRYPTO_BYTES];
    size_t  siglen;
    uint8_t m[MLEN];
    size_t  mlen = MLEN;
    uint8_t pre[PRELEN];
    size_t  prelen = PRELEN;
    uint8_t rnd[RNDBYTES];
    uint8_t pk[CRYPTO_PUBLICKEYBYTES];
    uint8_t sk[CRYPTO_SECRETKEYBYTES];
    unsigned int i;

    /* Khởi tạo dữ liệu test cố định */
    for (i = 0; i < MLEN; i++)
        m[i] = 0x11;
    for (i = 0; i < PRELEN; i++)
        pre[i] = 0x22;
    for (i = 0; i < RNDBYTES; i++)
        rnd[i] = 0x33;

    /* Sinh keypair chuẩn từ code tham chiếu */
    crypto_sign_keypair(pk, sk);

    printf("\n========== VERILOG INPUT DATA ==========\n");
    print_verilog_input_hex("INPUT message m", m, mlen);
    print_verilog_input_hex("INPUT pre", pre, prelen);
    print_verilog_input_hex("INPUT rnd", rnd, RNDBYTES);
    print_verilog_input_hex("INPUT secret key sk", sk, CRYPTO_SECRETKEYBYTES);
    printf("========================================\n\n");

    /* 2) BIẾN NỘI BỘ GIỐNG HỆT CODE GỐC */
    unsigned int n;
    uint8_t seedbuf[2 * SEEDBYTES + TRBYTES + 2 * CRHBYTES];
    uint8_t *rho, *tr, *key, *mu, *rhoprime;
    uint16_t nonce = 0;

    // [FIX] Thêm biến này để lưu giá trị nonce hiện tại cho việc in ấn đồng bộ
    uint16_t current_nonce = 0;

    polyvecl mat[K], s1, y, z;
    polyveck t0, s2, w1, w0, h;
    poly cp;
    keccak_state state;

    rho      = seedbuf;
    tr       = rho + SEEDBYTES;
    key      = tr + TRBYTES;
    mu       = key + SEEDBYTES;
    rhoprime = mu + CRHBYTES;

    /* 3) UNPACK SECRET KEY */
    unpack_sk(rho, tr, key, &t0, &s1, &s2, sk);

    printf("========== PRECOMPUTE COMPLETE ==========\n");
    print_hex("RHO", rho, 32);                    // 32 bytes
    print_hex("KEY", key, 32);                    // 32 bytes
    print_hex("TR", tr, 64);                      // 64 bytes

    /* 4) mu = CRH(tr || pre || m) */
    shake256_init(&state);
    shake256_absorb(&state, tr, TRBYTES);
    shake256_absorb(&state, pre, prelen);
    shake256_absorb(&state, m, mlen);
    shake256_finalize(&state);
    shake256_squeeze(mu, CRHBYTES, &state);

    print_hex("MU", mu, 64);                      // 64 bytes

    /* 5) rhoprime = CRH(key || rnd || mu) */
    shake256_init(&state);
    shake256_absorb(&state, key, SEEDBYTES);
    shake256_absorb(&state, rnd, RNDBYTES);
    shake256_absorb(&state, mu, CRHBYTES);
    shake256_finalize(&state);
    shake256_squeeze(rhoprime, CRHBYTES, &state);

    print_hex("RHOPRIME", rhoprime, 64);          // 64 bytes

    /* 6) Expand matrix + NTT(s1, s2, t0) */
    polyvec_matrix_expand(mat, rho);
    print_hex("MATRIX", mat, 128);

    // PRINT FULL 5120 BYTES (như Verilog)
    print_hex("S1", &s1, 64);         // 5120 bytes
    polyvecl_ntt(&s1);
    print_hex("S1_NTT (Stored)", &s1, 64);        // 64 bytes (chỉ in đầu)

    //  PRINT FULL 6144 BYTES (như Verilog)
    print_hex("S2", &s2, 64);                     // 64 bytes (chỉ in đầu)
    polyveck_ntt(&s2);
    print_hex("S2_NTT (Stored)", &s2, 64);        // 64 bytes (chỉ in đầu)

    print_hex("T0", &t0, 64);                     // 64 bytes (chỉ in đầu)
    polyveck_ntt(&t0);
    print_hex("T0_NTT (Stored)", &t0, 64);        // 64 bytes (chỉ in đầu)
    printf("=========================================\n\n");

rej:
    /* [FIX] Lưu lại nonce hiện tại để in log cho đúng (vì hàm dưới sẽ tăng nonce) */
    current_nonce = nonce;

    /* 7) Sample y */
    // Logic vẫn giữ nguyên: dùng nonce hiện tại tính toán, sau đó tăng lên 1
    polyvecl_uniform_gamma1(&y, rhoprime, nonce++);

    /* [FIX] Dùng current_nonce cho tất cả các lệnh printf trong vòng lặp này */
    printf("========== COMPUTE_W COMPLETE (nonce=%u) ==========\n", current_nonce);
    print_hex("Y", &y, 64);                       // 64 bytes (chỉ in đầu)

    /* 8) w = A * y */
    z = y;
    polyvecl_ntt(&z);
    print_hex("Y_NTT", &z, 64);                   // 64 bytes (chỉ in đầu)

    polyvec_matrix_pointwise_montgomery(&w1, mat, &z);

    polyveck_reduce(&w1);
    print_hex("W_REDUCED", &w1, 64);              // 64 bytes (chỉ in đầu)

    polyveck_invntt_tomont(&w1);
    print_hex("W_INVNTT", &w1, 64);               // 64 bytes (chỉ in đầu)

    /* 9) Decompose w → w0, w1 */
    polyveck_caddq(&w1);
    print_hex("W_CADDQ", &w1, 64);                // 64 bytes (chỉ in đầu)

    polyveck_decompose(&w1, &w0, &w1);
    print_hex("W1_DECOMP", &w1, 64);              // 64 bytes (chỉ in đầu)
    print_hex("W0_DECOMP", &w0, 64);              // 64 bytes (chỉ in đầu)
    printf("====================================================\n\n");

    /* pack w1 vào sig[0 .. K*POLYW1_PACKEDBYTES-1] */
    polyveck_pack_w1(sig, &w1);

    /* 10) Challenge c = H(mu || w1) */
    shake256_init(&state);
    shake256_absorb(&state, mu, CRHBYTES);
    shake256_absorb(&state, sig, K * POLYW1_PACKEDBYTES);
    shake256_finalize(&state);
    shake256_squeeze(sig, CTILDEBYTES, &state);

    printf("========== CHALLENGE COMPLETE (nonce=%u) ==========\n", current_nonce);
    print_hex("CTILDE", sig, 48);                 // 48 bytes

    poly_challenge(&cp, sig);
    print_hex("CP (Reg)", &cp, 64);               // 64 bytes (chỉ in đầu)

    /* 11) z = y + c*s1 */
    poly_ntt(&cp);
    print_hex("CP_NTT", &cp, 64);                 // 64 bytes (chỉ in đầu)
    printf("===================================================\n\n");

    polyvecl_pointwise_poly_montgomery(&z, &cp, &s1);

    printf("========== COMPUTE_Z COMPLETE (nonce=%u) ==========\n", current_nonce);
    print_hex("CS1_NTT", &z, 64);                 // 64 bytes (chỉ in đầu)

    polyvecl_invntt_tomont(&z);
    print_hex("CS1", &z, 64);                     // 64 bytes (chỉ in đầu)

    polyvecl_add(&z, &z, &y);
    print_hex("Z_TEMP", &z, 64);                  // 64 bytes (chỉ in đầu)

    polyvecl_reduce(&z);
    print_hex("Z_FINAL", &z, 64);                 // 64 bytes (chỉ in đầu)
    printf("===================================================\n\n");

    printf("========== CHECK_Z (nonce=%u) ==========\n", current_nonce);
    if (polyvecl_chknorm(&z, GAMMA1 - BETA)) {
        printf("z_norm_pass = 0\n");
        printf("GAMMA1-BETA = %d\n", GAMMA1 - BETA);
        printf("========================================\n\n");
        printf("!!! REJECTION from CHECK_Z !!!\n");
        printf(" Reason: Z norm failed\n\n");
        goto rej;
    } else {
        printf("z_norm_pass = 1\n");
        printf("GAMMA1-BETA = %d\n", GAMMA1 - BETA);
        printf("========================================\n\n");
    }

    /* 12) w0 - c*s2 */
    polyveck_pointwise_poly_montgomery(&h, &cp, &s2);

    printf("========== COMPUTE_CS2 COMPLETE (nonce=%u) ==========\n", current_nonce);
    print_hex("CS2_NTT", &h, 64);                 // 64 bytes (chỉ in đầu)

    polyveck_invntt_tomont(&h);
    print_hex("CS2", &h, 64);                     // 64 bytes (chỉ in đầu)
    printf("======================================================\n\n");

    polyveck_sub(&w0, &w0, &h);

    polyveck_reduce(&w0);

    printf("========== CHECK_W0 (nonce=%u) ==========\n", current_nonce);
    print_hex("W0_REDUCED_CHECK", &w0, 64);       // 64 bytes (chỉ in đầu)

    if (polyveck_chknorm(&w0, GAMMA2 - BETA)) {
        printf("w0_norm_pass = 0\n");
        printf("GAMMA2-BETA  = %d\n", GAMMA2 - BETA);
        printf("=========================================\n\n");
        printf("!!! REJECTION from CHECK_W0 !!!\n");
        printf(" Reason: W0 norm failed\n\n");
        goto rej;
    } else {
        printf("w0_norm_pass = 1\n");
        printf("GAMMA2-BETA  = %d\n", GAMMA2 - BETA);
        printf("=========================================\n\n");
    }

    /* 13) Compute hint h */
    polyveck_pointwise_poly_montgomery(&h, &cp, &t0);
    polyveck_invntt_tomont(&h);
    polyveck_reduce(&h);

    printf("========== CHECK_H (nonce=%u) ==========\n", current_nonce);

    if (polyveck_chknorm(&h, GAMMA2)) {
        printf("h_norm_pass      = 0\n");
        printf("GAMMA2           = %d\n", GAMMA2);
        print_hex("H_REDUCED", &h, 64);            // 64 bytes (chỉ in đầu)
        printf("========================================\n\n");
        printf("!!! REJECTION from CHECK_H !!!\n");
        printf(" Reason: Hint norm failed\n\n");
        goto rej;
    } else {
        printf("h_norm_pass      = 1\n");
        printf("GAMMA2           = %d\n", GAMMA2);
    }

    print_hex("H_REDUCED", &h, 64);                // 64 bytes (chỉ in đầu)

    polyveck_add(&w0, &w0, &h);
    print_hex("W0_PLUS_H", &w0, 64);              // 64 bytes (chỉ in đầu)

    n = polyveck_make_hint(&h, &w0, &w1);
    print_hex("HINTS", &h, 64);                    // 64 bytes (chỉ in đầu)

    if (n > OMEGA) {
        printf("hint_count       = %u (max %d)\n", n, OMEGA);
        printf("hint_count_pass  = 0\n");
        printf("========================================\n\n");
        printf("!!! REJECTION from CHECK_H !!!\n");
        printf(" Reason: Hint count > OMEGA\n\n");
        goto rej;
    } else {
        printf("hint_count       = %u (max %d)\n", n, OMEGA);
        printf("hint_count_pass  = 1\n");
        printf("========================================\n\n");
    }

    /* 14) PACK SIGNATURE (c || z || h) */
    pack_sig(sig, sig, &z, &h);
    siglen = CRYPTO_BYTES;

    printf("========== SIGNATURE COMPLETE ==========\n");
    // In ra nonce cuối cùng thành công (là current_nonce)
    printf("Final nonce: %u\n", current_nonce);
    print_hex("FINAL_SIGNATURE", sig, SIG_BYTES); // 3309 bytes
    printf("Signature length = %zu\n", siglen);
    printf("========================================\n\n");

    printf("SUCCESS!\n");
    return 0;
}
#endif
