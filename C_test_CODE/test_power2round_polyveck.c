#if 0
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "params.h"
#include "polyvec.h"
#include "poly.h"
#include "rounding.h"
int main(void) {
    polyveck v, v0, v1;

    int32_t test_values[] = {
            0, 4095, 4096, 4097,8192, 8193,12288,-1,-4096, -4097,50000,100000, 8380416
        };

        for (int i = 0; i < K; i++) {
            for (int j = 0; j < N; j++) {
                v.vec[i].coeffs[j] = test_values[j % 15];
            }
        }

    polyveck_power2round(&v1, &v0, &v);

    for (int k = 0; k < 1; k++) {
        printf("Poly %d:\n", k);
        for (int t = 0; t < 13; t++) {
            printf("  a=%d -> a1=%d, a0=%d\n",
                   v.vec[k].coeffs[t],
                   v1.vec[k].coeffs[t],
                   v0.vec[k].coeffs[t]);
        }
    }
    return 0;
}
#endif
