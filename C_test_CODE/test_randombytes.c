#if 0
#include <stdio.h>
#include <stdint.h>
#include "randombytes.h"

int main_disabled() {
    uint8_t buffer[32];  // Sinh 32 byte ngẫu nhiên

    randombytes(buffer, sizeof(buffer));

    printf("Random bytes generated:\n");
    for (int i = 0; i < 32; i++) {
        printf("%02x", buffer[i]);
    }
    return 0;
}
#endif
