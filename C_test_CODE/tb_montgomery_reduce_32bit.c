#if 0

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "params.h"
#include "poly.h"
#include "reduce.h"

int main(void) {
    int64_t a[30];

    a[0]  = 0;
    a[1]  = 1;
    a[2]  = -1;
    a[3]  = INT64_MAX;
    a[4]  = INT64_MIN;
    a[5]  = (int64_t)INT32_MAX;           /* 2^31-1 */
    a[6]  = (int64_t)INT32_MIN;           /* -2^31 */
    a[7]  = (1LL << 33);                  /* 2^33 */
    a[8]  = -(1LL << 33);
    a[9]  = 123456789LL;
    a[10] = -123456789LL;
    a[11] = 0x0000000100000000LL;         /* 2^32 */
    a[12] = 0x00000000FFFFFFFFLL;
    a[13] = -0x00000000FFFFFFFFLL;
    a[14] = 0x1234567890ABCDEFLL;
    a[15] = -0x1234567890ABCDEFLL;
    a[16] = 0x7FFFFFFFFFFFFFFFLL;
    a[17] = (int64_t)0x8000000000000000ULL;
    a[18] = 0x00FF00FF00FF00FFLL;
    a[19] = -0x00FF00FF00FF00FFLL;

    srand((unsigned)time(NULL));
    for (int j = 0; j < 10; j++) {
        uint64_t hi = ((uint64_t)rand() << 31) ^ (uint64_t)rand();
        uint64_t lo = ((uint64_t)rand() << 31) ^ (uint64_t)rand();
        uint64_t val = (hi << 32) ^ lo;
        a[20 + j] = (int64_t)val;
    }

    printf("Running montgomery_reduce tests (%zu cases)\n", (size_t)(sizeof(a)/sizeof(a[0])));
    printf("Format: index : input(hex) (dec) -> output(hex) (dec)\n\n");

    for (int i = 0; i < 30; i++) {
        int32_t r = montgomery_reduce(a[i]);
        printf("[%02d] : 0x%016llx (%20lld) -> 0x%08x (%11d)\n",
               i,
               (unsigned long long)a[i],
               (long long)a[i],
               (unsigned int)(uint32_t)r,
               (int)r);
    }

    return 0;
}
#endif
