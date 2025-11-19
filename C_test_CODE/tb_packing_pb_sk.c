#if 0
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "params.h"
#include "poly.h"
#include "polyvec.h"
#include "packing.h"

// In mảng byte dạng hex (big-endian để thuận Verilog)
void print_bytes_hex(const char *label, const uint8_t *buf, size_t len) {
    printf("%s =\n", label);
    for (int i = len - 1; i >= 0; i--) {
        printf("%02x", buf[i]);
        if ((len - i) % 32 == 0) printf("\n");
    }
    if (len % 32 != 0) printf("\n");
    printf("\n");
}

// In polynomial dạng hex 32bit
void print_poly_hex(const char *label, const poly *a) {
    printf("%s =\n", label);
    for (int i = N - 1; i >= 0; i--) {
        printf("%08x", (uint32_t)a->coeffs[i]);
        if ((N - i) % 8 == 0) printf("\n");
    }
    printf("\n");
}

// Điền dữ liệu xác định để test (không dùng random)
void fill_test_data(uint8_t *buf, size_t len, uint8_t seed) {
    for (size_t i = 0; i < len; i++) buf[i] = (seed + i) & 0xFF;
}

// Điền polyvector mẫu (coeff tăng dần hoặc lặp)
void fill_polyveck(polyveck *v, int tag) {
    for (int j = 0; j < K; j++) {
        for (int i = 0; i < N; i++) {
            v->vec[j].coeffs[i] = (i + tag) & 0xFFFFF;  // 20 bit OK cho t0,t1
        }
    }
}

void fill_polyvecl(polyvecl *v, int tag) {
    for (int j = 0; j < L; j++) {
        for (int i = 0; i < N; i++) {
            v->vec[j].coeffs[i] = (i + tag) & 0xFF;   // 8 bit cho s1, s2 đủ
        }
    }
}

int main() {
    printf("Dilithium Testbench for pack_pk() + pack_sk()\n");

    // INPUTS
    uint8_t rho[SEEDBYTES];
    uint8_t key[SEEDBYTES];
    uint8_t tr[TRBYTES];
    uint8_t pk[CRYPTO_PUBLICKEYBYTES];
    uint8_t sk[CRYPTO_SECRETKEYBYTES];

    polyveck t1, t0, s2;
    polyvecl s1;

    // Điền dữ liệu có thể lặp lại
    fill_test_data(rho, SEEDBYTES, 0x10);
    fill_test_data(key, SEEDBYTES, 0x20);
    fill_test_data(tr, TRBYTES,  0x30);

    fill_polyveck(&t1, 1);
    fill_polyveck(&t0, 2);
    fill_polyvecl(&s1, 3);
    fill_polyveck(&s2, 4);

    // PACK
    pack_pk(pk, rho, &t1);
    pack_sk(sk, rho, tr, key, &t0, &s1, &s2);

    // PRINT OUTPUT
    print_bytes_hex("pk", pk, CRYPTO_PUBLICKEYBYTES);
    print_bytes_hex("sk", sk, CRYPTO_SECRETKEYBYTES);

    return 0;
}
#endif
