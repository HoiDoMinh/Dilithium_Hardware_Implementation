
#if 0
#include <stdio.h>
#include <stdint.h>
#include "params.h"
#include "ntt.h"
#include "reduce.h"



int main(void) {
    int32_t a[N];
    int i,j,k;

    for (i = 0; i < N; i++) {
    	a[i] = -10*(i+10 + 1);
    }

    printf("Input coefficients:\n");
    for (j = 0; j < N; j++) {
        printf("a[%d] = %d  ", j, a[j]);
        if((j+1)%10==0) printf("\n");
    }

    //ntt(a);
    invntt_tomont(a);
    printf("\nOutput coefficients (after NTT):\n");
    for (k = 0; k < N; k++) {
        printf("a[%d] = %d  ", k, a[k]);
        if((k+1)%8==0) printf("\n");
    }

    return 0;
}
#endif
