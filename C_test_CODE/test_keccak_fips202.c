#if 0
#include <stdio.h>
#include <stdint.h>
#include "fips202.h"

// test keccak absorb + finalize
int main(void) {
    uint64_t s[25];       // Keccak state 25 lanes x 64-bit
    uint8_t in[8] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
    unsigned int pos = 0;
    unsigned int rate = 136;   // typical rate for SHAKE128 (136 bytes)
    uint8_t domain = 0x1F;     // domain separation byte
    size_t inlen = 8;

    // 1️⃣ Khởi tạo state
    keccak_init(s);
    printf("=== TEST keccak_absorb + keccak_finalize ===\n\n");

    // 2️⃣ Gọi hàm absorb
    pos = keccak_absorb(s, pos, rate, in, inlen);
    printf("State sau absorb + finalize:\n");
        for (int j = 0; j < 25; j++) {
            printf("s[%02d] = %016llx\n", j, (unsigned long long)s[j]);
        }

    // 3️⃣ Finalize absorb
    keccak_finalize(s, pos, rate, domain);

    // 4️⃣ In ra state kết quả
    printf("State sau absorb + finalize:\n");
    for (int i = 0; i < 25; i++) {
        printf("s[%02d] = %016llx\n", i, (unsigned long long)s[i]);
    }

    return 0;
}
#endif
