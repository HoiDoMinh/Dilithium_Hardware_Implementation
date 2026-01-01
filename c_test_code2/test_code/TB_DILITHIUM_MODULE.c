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
#define M_MAX 64
#define PRE_MAX 32

// --- Helper Functions ---

void print_bytes_hex(const char *label, const void *buf, size_t len)
{
    const uint8_t *bytes = buf;
    printf("%s (hex)\n", label);
    for (size_t i = 0; i < len; i++)
    {
        printf("%02x ", bytes[i]);
        if ((i % 52) == 51)
            printf("\n");
    }
    printf("\n\n");
}
void print_verilog_input_non_reverse(const char *name, const uint8_t *buf, size_t len)
{
    printf("%s[%zu:0] = %zu'h", name, len * 8 - 1, len * 8);
    for (int i = 0; i <= (int)len - 1; i++)
    {
        printf("%02x", buf[i]);
    }
    printf(";\n");
}

void print_verilog_input_hex(const char *name, const uint8_t *buf, size_t len)
{
    printf("%s[%zu:0] = %zu'h", name, len * 8 - 1, len * 8);
    for (int i = (int)len - 1; i >= 0; i--)
    {
        printf("%02x", buf[i]);
    }
    printf(";\n");
}

// --- Main Testbench ---

int main(void)
{
    // 1. Khai báo biến chung
    uint8_t pk[CRYPTO_PUBLICKEYBYTES];
    uint8_t sk[CRYPTO_SECRETKEYBYTES];
    uint8_t sig[CRYPTO_BYTES];
    size_t siglen;

    uint8_t m[M_MAX];
    uint8_t pre[PRE_MAX]; // Prefix context
    // uint8_t rnd[32];      // Random seed cho Signing

    int ret;

    // 1b. Khai báo biến cho phần KeyGen thủ công
    uint8_t seedbuf[2 * SEEDBYTES + CRHBYTES];
    uint8_t tr[TRBYTES];
    const uint8_t *rho, *rhoprime, *key;
    polyvecl s1, s1hat;
    polyveck s2, t1, t0;
    polyvecl mat[K];

    // Fixed seed
    uint8_t fixed_seed[SEEDBYTES] = {
        0x5e, 0xb3, 0x17, 0x42, 0x91, 0xee, 0xac, 0x0d,
        0x77, 0x64, 0x30, 0x02, 0xf4, 0x89, 0xde, 0x3c,
        0x10, 0x56, 0xa9, 0xbb, 0xc0, 0x99, 0x7e, 0x11,
        0x2f, 0x4d, 0x5c, 0x6a, 0x39, 0x87, 0xf1, 0x00};
    // Xóa sạch buffer
    memset(m, 0, M_MAX);
    memset(pre, 0, PRE_MAX);

    unsigned int i;
    strcpy((char *)m, "CHUYEN KHOAN 1000USD CHO ALICE TU JAN");
    strcpy((char *)pre, "BANKING NHE AE");
    uint8_t rnd[32] = {
        0xAA, 0x1B, 0x2C, 0x3D, 0x4E, 0x5F, 0x60, 0x71,
        0x82, 0x93, 0xA4, 0xB5, 0xC6, 0xD7, 0xE8, 0xF9,
        0x0A, 0x1B, 0x2C, 0x3D, 0x4E, 0x5F, 0x60, 0x71,
        0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
    size_t mlen = 64;
    size_t prelen = 32;

    // 3. KEYGEN
    printf("--- [2] KEYGEN PROCESS (Manual Fixed Seed) ---\n");

    memcpy(seedbuf, fixed_seed, SEEDBYTES);
    seedbuf[SEEDBYTES] = K;
    seedbuf[SEEDBYTES + 1] = L;

    /* Print initial random seed */
    // print_bytes_hex("Random Seed", fixed_seed, SEEDBYTES);
    // truyen truc tiep random seed va random RND vao verilog
    print_verilog_input_non_reverse("Random Seed", fixed_seed, SEEDBYTES);
    print_verilog_input_non_reverse("Random RND", rnd, SEEDBYTES);

    /* SHAKE256 expansion */
    shake256(seedbuf, 2 * SEEDBYTES + CRHBYTES, seedbuf, SEEDBYTES + 2);

    rho = seedbuf;
    rhoprime = rho + SEEDBYTES;
    key = rhoprime + CRHBYTES;

    /* Expand matrix A */
    polyvec_matrix_expand(mat, rho);

    /* Generate s1, s2 */
    polyvecl_uniform_eta(&s1, rhoprime, 0);
    polyveck_uniform_eta(&s2, rhoprime, L);

    /* NTT(s1) */
    s1hat = s1;
    polyvecl_ntt(&s1hat);

    /* t1 = A * s1hat */
    polyvec_matrix_pointwise_montgomery(&t1, mat, &s1hat);
    polyveck_reduce(&t1);
    polyveck_invntt_tomont(&t1);

    /* t = t1 + s2 */
    polyveck_add(&t1, &t1, &s2);
    polyveck_caddq(&t1);

    /* power2round -> t1, t0 */
    polyveck_power2round(&t1, &t0, &t1);

    /* Pack public key */
    pack_pk(pk, rho, &t1);
    print_bytes_hex("Public Key (pk)", pk, CRYPTO_PUBLICKEYBYTES);

    /* Hash public key -> tr */
    shake256(tr, TRBYTES, pk, CRYPTO_PUBLICKEYBYTES);

    /* Pack secret key */
    pack_sk(sk, rho, tr, key, &t0, &s1, &s2);
    print_bytes_hex("Secret Key (sk)", sk, CRYPTO_SECRETKEYBYTES);
    // print_verilog_input_hex("Secret Key (sk)", sk, CRYPTO_SECRETKEYBYTES);

    // 4. SIGN (Ký - Sử dụng hàm internal có 'pre' và 'rnd')
    printf("--- [3] SIGNING PROCESS ---\n");

    ret = crypto_sign_signature_internal(sig, &siglen,
                                         m, mlen,
                                         pre, prelen,
                                         rnd,
                                         sk);

    if (ret == 0)
        printf("Signature generated successfully.\n");
    else
        printf("Sign failed with code: %d\n", ret);

    print_bytes_hex("Signature (sig)", sig, CRYPTO_BYTES);
    // print_verilog_input_hex("expected_sig", sig, CRYPTO_BYTES);

    // 5. VERIFY (Xác minh - Sử dụng hàm internal có 'pre')
    printf("--- [4] VERIFY PROCESS ---\n");

    ret = crypto_sign_verify_internal(sig, siglen,
                                      m, mlen,
                                      pre, prelen,
                                      pk);

    if (ret == 0)
    {
        printf("[PASS] Signature Verification SUCCESSFUL!\n");
        printf("       The signature matches the message, prefix, and public key.\n");
    }
    else
    {
        printf("[FAIL] Signature Verification FAILED!\n");
        printf("       Error code: %d\n", ret);
    }

    return 0;
}
