#if 0
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "params.h"
#include "poly.h"

//in seed dưới dạng hex
void print_seed_hex(const uint8_t seed[CRHBYTES]) {
    printf("seed_in = ");
    for (int i = CRHBYTES - 1; i >= 0; i--) {
        printf("%02x", seed[i]);
    }
    printf("\n");
}

//in polynomial dưới dạng hex (Verilog output)
void print_poly_hex(const poly *a) {
    printf("a_out = \n");
    int count = 0;
    for (int i = N-1; i >= 0; i--) {
        uint32_t coeff = (uint32_t)a->coeffs[i];
        printf("%08x", coeff);

        count++;

        if (count % 16 == 0) {
            printf("\n");
        }
    }
    if (count % 16 != 0) {
        printf("\n");
    }
    printf("\n");
}

void hex_string_to_bytes(const char *hex_str, uint8_t *bytes, size_t byte_len) {
    for (size_t i = 0; i < byte_len; i++) {
        sscanf(hex_str + 2*i, "%2hhx", &bytes[i]);
    }
}
int main(void) {
    poly a;
    uint8_t seed[CRHBYTES];
    uint16_t nonce;

    memset(seed, 0, CRHBYTES);

    //const char*seed_hex = "0102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20";
    //const char*seed_hex = "29CF91BB67D46DD88664CF7D438A2175BAEAB3A70F15AF1E36F677FB15E6D5E10D56AC51088365E9F09AD2CC0255E4418A9AF06074B9873FC0A2B5D8E7DC3B03";
    const char*seed_hex = "423EBEB6470CFACE82D0734AEFC47F52D787FD85ACA5CAFB29AE61BEDA24B21D1D5A2960CDB63AA7108E35FB249DE8D2CACBB465DD17D39918D62017FB147B1F";
    hex_string_to_bytes(seed_hex, seed, 64);
    // Các byte còn lại = 0

    nonce = 0x4D;

    print_seed_hex(seed);
    printf("nonce = %04x\n", nonce);
    // Gọi hàm poly_uniform_eta
    poly_uniform_eta(&a, seed, nonce);

    // In kết quả
    print_poly_hex(&a);
    for (int i = 0; i < 10; i++) {
        printf("a[%3d] = %8d (0x%08x)\n", i, a.coeffs[i], (uint32_t)a.coeffs[i]);
    }
    return 0;
}

#endif
