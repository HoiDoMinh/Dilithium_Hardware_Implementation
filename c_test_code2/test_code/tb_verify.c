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

// PARAMETERS
#define MLEN    64
#define PRELEN  32
#define K       6
#define L       5
#define N       256
#define D       13

// Các hằng số kích thước
#define CRYPTO_PUBLICKEYBYTES 1952
#define CRYPTO_SECRETKEYBYTES 4032
#define CRYPTO_BYTES          3309
#define SEEDBYTES             32
#define CRHBYTES              64
#define CTILDEBYTES           48
#define TRBYTES               64
#define POLYW1_PACKEDBYTES    128

// Hàm in Hex format
void print_hex(const char *label, const void *buf, size_t len) {
    const uint8_t *bytes = buf;
    printf("%s (hex, %zu bytes)\n", label, len);
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", bytes[i]);
        if ((i % 52) == 51) printf("\n");
    }
    printf("\n\n");
}

// Hàm in input cho Verilog testbench
void print_verilog_input_hex(const char *name, const uint8_t *buf, size_t len) {
    printf("%s[%zu:0] = %zu'h", name, len * 8 - 1, len * 8);
    for (int i = (int)len - 1; i >= 0; i--) {
        printf("%02x", buf[i]);
    }
    printf(";\n");
}

int main(void) {
    /* 1. KHỞI TẠO DỮ LIỆU ĐẦU VÀO */
    uint8_t pk[CRYPTO_PUBLICKEYBYTES];
    uint8_t sk[CRYPTO_SECRETKEYBYTES];
    uint8_t sig[CRYPTO_BYTES];
    size_t  siglen;
    uint8_t m[MLEN];
    uint8_t pre[PRELEN];
    uint8_t rnd[RNDBYTES]; // rnd dùng lúc sign
    unsigned int i;

    // Fix dữ liệu Message & Prefix
    for(i = 0; i < MLEN; ++i) m[i] = 0x11;
    for(i = 0; i < PRELEN; ++i) pre[i] = 0x22;
    for(i = 0; i < RNDBYTES; ++i) rnd[i] = 0x33;

    // Sinh Keypair và Signature HỢP LỆ để test Verify
    // (Trong thực tế Verilog Verify, bạn sẽ paste signature này vào testbench)
    crypto_sign_keypair(pk, sk);

    // Gọi hàm Sign nội bộ (bạn cần đảm bảo hàm này có trong thư viện C của bạn hoặc copy từ testbench sign)
    // Giả sử có hàm wrapper: crypto_sign_signature(sig, &siglen, m, MLEN, sk);
    // Hoặc gọi trực tiếp internal nếu sửa prototype để nhận rnd cố định:
    // crypto_sign_signature_internal(sig, &siglen, m, MLEN, pre, PRELEN, rnd, sk);

    // Ở đây tôi giả lập việc sign đã xong và ta có `sig` và `pk` hợp lệ.
    // Để test đồng bộ, bạn nên dùng chính bộ (pk, sk, sig) mà testbench Sign C đã sinh ra.

    // [QUAN TRỌNG] : Để testbench C Verify này có ý nghĩa, bạn cần chạy Testbench Sign C trước,
    // lấy kết quả `pk` và `sig` từ đó, rồi Hardcode vào đây hoặc đảm bảo Seed Random giống hệt.

    // Tuy nhiên, để code chạy được độc lập, ta sẽ sign lại tại chỗ:
    crypto_sign_signature_internal(sig, &siglen, m, MLEN, pre, PRELEN, rnd, sk);

    printf("\n========== VERILOG VERIFY INPUT DATA ==========\n");
    print_verilog_input_hex("INPUT public key pk", pk, CRYPTO_PUBLICKEYBYTES);
    print_verilog_input_hex("INPUT signature sig", sig, CRYPTO_BYTES);
    print_verilog_input_hex("INPUT message m", m, MLEN);
    print_verilog_input_hex("INPUT pre", pre, PRELEN);
    printf("===============================================\n\n");

    /* 2. BẮT ĐẦU QUÁ TRÌNH VERIFY (Mô phỏng chi tiết) */

    // Biến nội bộ
    uint8_t buf[K*POLYW1_PACKEDBYTES];
    uint8_t rho[SEEDBYTES];
    uint8_t mu[CRHBYTES];
    uint8_t c[CTILDEBYTES];
    uint8_t c2[CTILDEBYTES];
    poly cp;
    polyvecl mat[K], z;
    polyveck t1, w1, h;
    keccak_state state;

    if(siglen != CRYPTO_BYTES) {
        printf("Error: Signature length mismatch\n");
        return -1;
    }

    /* STEP 1: UNPACK PUBLIC KEY */
    unpack_pk(rho, &t1, pk);

    printf("========== UNPACK PUBLIC KEY ==========\n");
    print_hex("RHO", rho, SEEDBYTES);
    // In t1 dạng unpacked (nếu cần so sánh sâu)
    // print_hex("T1 (PolyVecK)", &t1, sizeof(t1));

    /* STEP 2: UNPACK SIGNATURE */
    if(unpack_sig(c, &z, &h, sig)) {
        printf("Error: Signature unpack failed (Malformed)\n");
        return -1;
    }

    printf("========== UNPACK SIGNATURE ==========\n");
    print_hex("C_TILDE (from sig)", c, CTILDEBYTES);
    print_hex("Z (PolyVecL)", &z, sizeof(z)); // ~5120 bytes unpack
    // print_hex("H (PolyVecK)", &h, sizeof(h));

    /* STEP 3: CHECK Z NORM */
    if(polyvecl_chknorm(&z, GAMMA1 - BETA)) {
        printf("Error: Z Norm Check FAILED\n");
        return -1;
    }
    printf("CHECK_Z: PASSED\n\n");

    /* STEP 4: COMPUTE MU */
    // 4.1 Hash PK -> TR (mu_temp)
    uint8_t mu_temp[TRBYTES]; // TRBYTES = 64
    shake256(mu_temp, TRBYTES, pk, CRYPTO_PUBLICKEYBYTES);

    // 4.2 Hash TR + Pre + M -> MU
    shake256_init(&state);
    shake256_absorb(&state, mu_temp, TRBYTES);
    shake256_absorb(&state, pre, PRELEN);
    shake256_absorb(&state, m, MLEN);
    shake256_finalize(&state);
    shake256_squeeze(mu, CRHBYTES, &state);

    printf("========== COMPUTE MU ==========\n");
    print_hex("MU_TEMP (Hash PK)", mu_temp, TRBYTES);
    print_hex("MU (Hash Msg)", mu, CRHBYTES);

    /* STEP 5: EXPAND MATRIX A */
    polyvec_matrix_expand(mat, rho);
    // print_hex("MATRIX A", mat, sizeof(mat));

    /* STEP 6: COMPUTE Az (NTT -> Mult) */
    polyvecl_ntt(&z);
    print_hex("Z_NTT", &z, sizeof(z)); // 64 bytes đầu

    polyvec_matrix_pointwise_montgomery(&w1, mat, &z);
    // w1 lúc này chứa Az

    /* STEP 7: COMPUTE c*t1 */
    poly_challenge(&cp, c);
    print_hex("CP (Poly)", &cp, sizeof(cp));

    poly_ntt(&cp);
    print_hex("CP_NTT", &cp, sizeof(cp));

    polyveck_shiftl(&t1);
    polyveck_ntt(&t1);
    print_hex("T1_NTT (Shifted)", &t1, sizeof(t1)); // 64 bytes đầu

    polyveck t1_copy = t1; // Sao lưu để debug nếu cần
    polyveck_pointwise_poly_montgomery(&t1, &cp, &t1);
    // t1 lúc này chứa c*t1

    /* STEP 8: COMPUTE w1 = Az - c*t1 */
    polyveck_sub(&w1, &w1, &t1);
    polyveck_reduce(&w1);
    polyveck_invntt_tomont(&w1);

    print_hex("W1 (Before Hint)", &w1, sizeof(w1)); // 64 bytes đầu

    /* STEP 9: RECONSTRUCT w1 (Use Hint) */
    polyveck_caddq(&w1);
    polyveck_use_hint(&w1, &w1, &h);

    print_hex("W1 (Reconstructed)", &w1, sizeof(w1)); // 64 bytes đầu

    /* STEP 10: PACK W1 */
    polyveck_pack_w1(buf, &w1);
    print_hex("W1_PACKED", buf, K*POLYW1_PACKEDBYTES);

    /* STEP 11: FINAL HASH (c2) */
    shake256_init(&state);
    shake256_absorb(&state, mu, CRHBYTES);
    shake256_absorb(&state, buf, K*POLYW1_PACKEDBYTES);
    shake256_finalize(&state);
    shake256_squeeze(c2, CTILDEBYTES, &state);

    printf("========== FINAL CHECK ==========\n");
    print_hex("C_TILDE (Signature)", c, CTILDEBYTES);
    print_hex("C2 (Calculated)", c2, CTILDEBYTES);

    /* STEP 12: COMPARE */
    int result = 0;
    for(i = 0; i < CTILDEBYTES; ++i) {
        if(c[i] != c2[i]) {
            result = -1;
            break;
        }
    }

    if (result == 0) {
        printf("VERIFY RESULT: SUCCESS (Valid Signature)\n");
    } else {
        printf("VERIFY RESULT: FAILED (Invalid Signature)\n");
    }

    return result;
}
#endif
