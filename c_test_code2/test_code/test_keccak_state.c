#if 0
#include <stdio.h>
#include <stdint.h>
#include <string.h>
//#include "fips202.h"

void keccak_init(uint64_t s[25]);
unsigned int keccak_absorb(uint64_t s[25], unsigned int pos, unsigned int r, const uint8_t *in, size_t inlen);
void keccak_finalize(uint64_t s[25], unsigned int pos, unsigned int r, uint8_t p);
unsigned int keccak_squeeze(uint8_t *out, size_t outlen, uint64_t s[25], unsigned int pos, unsigned int r);

void KeccakF1600_StatePermute(uint64_t s[25]) {
    for (int i = 0; i < 25; i++) {
        s[i] ^= 0xAAAAAAAAAAAAAAAAULL;
    }
}

//----------------------------------------------
// In mảng state 5x5 (64-bit mỗi phần tử)
//----------------------------------------------
void print_state(uint64_t s[25]) {
    for (int k = 0; k < 25; k++) {
        printf("s[%2d] = %016llx\n", k, (unsigned long long)s[k]);
    }
    printf("---------------------------------------------\n");
}

//----------------------------------------------
// MAIN TEST
//----------------------------------------------
int main(void) {
    uint64_t state[25];
    uint8_t input[32];
    uint8_t output[32];
    unsigned int pos;

    // 1. Test keccak_init
    printf("=== TEST keccak_init ===\n");
    keccak_init(state);
    print_state(state);

    // 2. Test keccak_absorb
    printf("=== TEST keccak_absorb ===\n");
    for (int i = 0; i < 32; i++)
        input[i] = i; // dữ liệu vào đơn giản 0..31

    pos = 0;
    pos = keccak_absorb(state, pos, 16, input, 32); // r = 16 bytes để dễ test (SHAKE128 thường là 168)
    printf("After absorb (pos=%u):\n", pos);
    print_state(state);

    // 3. Test keccak_finalize
    printf("=== TEST keccak_finalize ===\n");
    keccak_finalize(state, pos, 16, 0x1F); // ví dụ p=0x1F (domain separation)
    print_state(state);

    // 4. Test keccak_squeeze
    printf("=== TEST keccak_squeeze ===\n");
    memset(output, 0, sizeof(output));
    pos = keccak_squeeze(output, 32, state, 0, 16);

    printf("Output bytes:\n");
    for (int j = 0; j < 32; j++) {
        printf("%02x ", output[j]);
        if ((j+1)%16 == 0) printf("\n");
    }
    printf("\nFinal pos = %u\n", pos);
    print_state(state);

    return 0;
}
#endif
