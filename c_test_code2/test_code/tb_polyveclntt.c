#if 0
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "sign.h"
#include "params.h"
#include "packing.h"
#include "polyvec.h"
#include "poly.h"
#include "randombytes.h"
#include "fips202.h"

#define MLEN 64

// Hàm in Hex (Little Endian bytes)
void print_hex(const char *label, const void *buf, size_t len) {
    const uint8_t *bytes = buf;
    printf("%s (hex)\n", label);
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", bytes[i]);
        if ((i % 52) == 51) printf("\n");
    }
    printf("\n\n");
}

// Hàm in Input format Verilog
void print_verilog_input_hex(const char *name, const uint8_t *buf, size_t len) {
    printf("%s[%zu:0] = %zu'h", name, len * 8 - 1, len * 8);
    for (int i = (int)len - 1; i >= 0; i--) {
        printf("%02x", buf[i]);
    }
    printf(";\n\n");
}

// Hàm điền dữ liệu ngẫu nhiên vào polyvecl
void random_polyvecl(polyvecl *v) {
    uint8_t buf[L * N * 4];
    randombytes(buf, sizeof(buf)); // Sinh ngẫu nhiên
    for(int i=0; i<L; i++) {
        for(int j=0; j<N; j++) {
            // Giả lập load dữ liệu 32-bit (chưa cần chuẩn range, chỉ cần data để test nhân)
            v->vec[i].coeffs[j] = (int32_t)(buf[i*N*4 + j*4] |
                                           (buf[i*N*4 + j*4 + 1] << 8) |
                                           (buf[i*N*4 + j*4 + 2] << 16) |
                                           (buf[i*N*4 + j*4 + 3] << 24));
        }
    }
}

// Hàm điền dữ liệu ngẫu nhiên vào polyveck
void random_polyveck(polyveck *v) {
    uint8_t buf[K * N * 4];
    randombytes(buf, sizeof(buf));
    for(int i=0; i<K; i++) {
        for(int j=0; j<N; j++) {
            v->vec[i].coeffs[j] = (int32_t)(buf[i*N*4 + j*4] |
                                           (buf[i*N*4 + j*4 + 1] << 8) |
                                           (buf[i*N*4 + j*4 + 2] << 16) |
                                           (buf[i*N*4 + j*4 + 3] << 24));
        }
    }
}

int main(void) {
    polyvecl s1;
    polyveck s2, t0;

    // 1. Tạo dữ liệu giả lập (Random)
    random_polyvecl(&s1);
    random_polyveck(&s2);
    random_polyveck(&t0);

    printf("========== TEST CASE INPUTS (COPY TO VERILOG) ==========\n");
    // In Input dạng Verilog để copy vào Testbench
    // Lưu ý: sizeof(s1) có thể bao gồm padding struct, nên dùng hằng số tính toán sẽ an toàn hơn
    // polyvecl = L * N * 4 bytes
    print_verilog_input_hex("s1_input", (uint8_t *)&s1, L * N * 4);
    print_verilog_input_hex("s2_input", (uint8_t *)&s2, K * N * 4);
    print_verilog_input_hex("t0_input", (uint8_t *)&t0, K * N * 4);
    printf("========================================================\n\n");

    // 2. Thực hiện NTT (Reference)
    polyvecl_ntt(&s1);
    polyveck_ntt(&s2);
    polyveck_ntt(&t0);

    // 3. In Output mong đợi
    printf("========== EXPECTED OUTPUTS (FOR COMPARISON) ==========\n");
    print_hex("S1_NTT", (uint8_t *)&s1, L * N * 4);
    print_hex("S2_NTT", (uint8_t *)&s2, K * N * 4);
    print_hex("T0_NTT", (uint8_t *)&t0, K * N * 4);

    return 0;
}
#endif
