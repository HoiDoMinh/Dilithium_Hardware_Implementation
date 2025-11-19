#if 0
#include <stdio.h>
#include "params.h"
#include "poly.h"
#include "polyvec.h"
#include "ntt.h"
#include "reduce.h"

#define K 6
#define L 5
#define N 256

int main(void) {
    unsigned int i, j, n;

    polyvecl v;
    polyvecl mat[K];
    polyveck t;
    // Giống như testbench Verilog — mỗi hệ số = i+1, i+1000,...
    for (j = 0; j < L; ++j)
        for (n = 0; n < N; ++n)
            v.vec[j].coeffs[n] = n + 1; // v_in = [1,2,3,...]

    for (i = 0; i < K; ++i)
        for (j = 0; j < L; ++j)
            for (n = 0; n < N; ++n)
                mat[i].vec[j].coeffs[n] = (i + 1) * 1000 + n; // tương tự mat1..4 trong Verilog

    polyvec_matrix_pointwise_montgomery(&t, mat, &v);

    for (i = 0; i < K; ++i) {
        printf("---- t[%u] ----\n", i);
        for (n = 0; n < 8; ++n) {  // chỉ in 8 hệ số đầu để gọn
            printf("coeff[%u] = %d\n", n, t.vec[i].coeffs[n]);
        }
    }

    return 0;
}
#endif
