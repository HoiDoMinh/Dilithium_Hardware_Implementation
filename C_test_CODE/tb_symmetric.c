#if 0
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "params.h"
#include "symmetric.h"
#include "fips202.h"

// Hàm in dữ liệu dạng hex
void print_hex(const char *label, const uint8_t *data, size_t len) {
    printf("%s (%zu bytes):\n", label, len);
    for (size_t i = 0; i < len; i++) {
        printf("%02x", data[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
        else
            printf(" ");
    }
    if (len % 16 != 0) printf("\n");
    printf("\n");
}

int main(void) {
    keccak_state state128, state256;
    uint8_t seed[SEEDBYTES];
    uint8_t crhseed[CRHBYTES];
    uint16_t nonce = 42; // ví dụ nonce = 42 (0x2A)
    uint8_t out[64]; // dữ liệu squeeze ra từ SHAKE
    int i;

    // Khởi tạo seed mẫu để test (giá trị tăng dần)
    for (i = 0; i < SEEDBYTES; i++)
        seed[i] = (uint8_t)i;
    for (i = 0; i < CRHBYTES; i++)
        crhseed[i] = (uint8_t)(i + 100);

    // In seed & nonce
    print_hex("Input seed (SHAKE128)", seed, SEEDBYTES);
    printf("Nonce: %u (0x%04X)\n\n", nonce, nonce);

    dilithium_shake128_stream_init(&state128, seed, nonce);

    shake128_squeeze(out, sizeof(out), &state128);

    // In output
    print_hex("SHAKE128 output", out, sizeof(out));
    // In seed & nonce

    print_hex("Input seed (SHAKE256)", crhseed, CRHBYTES);
    printf("Nonce: %u (0x%04X)\n\n", nonce, nonce);

    dilithium_shake256_stream_init(&state256, crhseed, nonce);
    shake256_squeeze(out, sizeof(out), &state256);

    // In output
    print_hex("SHAKE256 output", out, sizeof(out));


    return 0;
}
#endif
