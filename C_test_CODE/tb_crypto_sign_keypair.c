
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

void print_bytes_hex(const char *label, const void *buf, size_t len) {
    const uint8_t *bytes = buf;
    printf("%s (hex)\n", label);
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", bytes[i]);
        if ((i % 52) == 51) printf("\n");
    }
    printf("\n\n");
}
void print_verilog_input_hex(const char *name, const uint8_t *buf, size_t len) {
    printf("%s[%zu:0] = %zu'h", name, len*8 - 1, len*8);
    for (ssize_t i = len - 1; i >= 0; i--) {
        printf("%02x", buf[i]);
    }
    printf(";\n");
}

int main(void) {
    uint8_t pk[CRYPTO_PUBLICKEYBYTES];
    uint8_t sk[CRYPTO_SECRETKEYBYTES];
    uint8_t seedbuf[2*SEEDBYTES + CRHBYTES];
    uint8_t tr[TRBYTES];
    const uint8_t *rho, *rhoprime, *key;
    polyvecl s1, s1hat;
    polyveck s2, t1, t0;
    polyvecl mat[K];

    /*uint8_t fixed_seed[SEEDBYTES] = {
        0x9e, 0x12, 0xaf, 0x77, 0x03, 0xc8, 0x5d, 0x41,
        0xb2, 0x6f, 0x8a, 0x90, 0x2c, 0xdb, 0x17, 0xee,
        0x49, 0x3d, 0xf8, 0x64, 0x81, 0x0a, 0xec, 0x57,
        0xca, 0x72, 0x33, 0x19, 0xfd, 0x04, 0xb9, 0x6c
    };
    uint8_t fixed_seed[SEEDBYTES] = {
        0x12, 0x7a, 0xf3, 0xcc, 0x88, 0x19, 0x55, 0x0e,
        0xa3, 0xd9, 0x44, 0x11, 0xfe, 0x01, 0x6c, 0x90,
        0x7d, 0x2f, 0x33, 0xaa, 0x99, 0x50, 0x0b, 0xcd,
        0x22, 0x71, 0x18, 0x8e, 0x5a, 0x4f, 0xf0, 0x3c
    };

    uint8_t fixed_seed[SEEDBYTES] = {
        0xde, 0xad, 0xbe, 0xef, 0x01, 0x23, 0x45, 0x67,
        0x89, 0xab, 0xcd, 0xef, 0x10, 0x32, 0x54, 0x76,
        0x98, 0xba, 0xdc, 0xfe, 0xaa, 0xbb, 0xcc, 0xdd,
        0xee, 0xff, 0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc
    };
    uint8_t fixed_seed[SEEDBYTES] = {
        0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
        0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
        0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10,
        0x0f, 0x1e, 0x2d, 0x3c, 0x4b, 0x5a, 0x69, 0x78
    };*/
    uint8_t fixed_seed[SEEDBYTES] = {
        0x5e, 0xb3, 0x17, 0x42, 0x91, 0xee, 0xac, 0x0d,
        0x77, 0x64, 0x30, 0x02, 0xf4, 0x89, 0xde, 0x3c,
        0x10, 0x56, 0xa9, 0xbb, 0xc0, 0x99, 0x7e, 0x11,
        0x2f, 0x4d, 0x5c, 0x6a, 0x39, 0x87, 0xf1, 0x00
    };

    memcpy(seedbuf, fixed_seed, SEEDBYTES);
    seedbuf[SEEDBYTES]   = K;
    seedbuf[SEEDBYTES+1] = L;

    /* Print initial random seed (32 bytes) */
    print_bytes_hex("Random Seed", fixed_seed, SEEDBYTES);
    print_verilog_input_hex("Random Seed",fixed_seed,SEEDBYTES);

    //print_verilog_input_hex("seedbuf",seedbuf,SEEDBYTES+2);
    /* SHAKE256 */
    shake256(seedbuf, 2*SEEDBYTES + CRHBYTES, seedbuf, SEEDBYTES+2);

    //print_verilog_input_hex("seedbuf",seedbuf,2*SEEDBYTES + CRHBYTES);
    /* Print seedbuf after shake256 */
    //print_bytes_hex("seedbuf_shaked", seedbuf, sizeof(seedbuf));

    rho = seedbuf;
    rhoprime = rho + SEEDBYTES;
    key = rhoprime + CRHBYTES;

    /* Print rho, rhoprime, key */
    //print_bytes_hex("rho", rho, SEEDBYTES);
    //print_bytes_hex("rhoprime", rhoprime, CRHBYTES);
    //print_bytes_hex("key", key, SEEDBYTES);

    /* Expand matrix A */
    polyvec_matrix_expand(mat, rho);

    /* Print mat */
    //print_bytes_hex("mat", mat, sizeof(mat));

    /* Generate s1, s2 */
    polyvecl_uniform_eta(&s1, rhoprime, 0);
    polyveck_uniform_eta(&s2, rhoprime, L);

    //print_verilog_input_hex("rhoprime", rhoprime, CRHBYTES);
    /* Print s1, s2 */
    //print_bytes_hex("s1", &s1, sizeof(s1));
    //print_bytes_hex("s2", &s2, sizeof(s2));


    /* NTT(s1) */
    s1hat = s1;
    polyvecl_ntt(&s1hat);


    /* Print s1hat */
   // print_bytes_hex("s1hat", &s1hat, sizeof(s1hat));

    /* t1 = A * s1hat */
    polyvec_matrix_pointwise_montgomery(&t1, mat, &s1hat);
    polyveck_reduce(&t1);

    /* Print t1 after reduce (before invntt) */
    //print_bytes_hex("t1_after_reduce", &t1, sizeof(t1));

    polyveck_invntt_tomont(&t1);

    /* Print t1 after invntt */
    //print_bytes_hex("t1_after_invntt", &t1, sizeof(t1));

    /* t = t1 + s2 */
    polyveck_add(&t1, &t1, &s2);

    /* Print t1 after add s2 */
    //print_bytes_hex("t1_after_add_s2", &t1, sizeof(t1));

    polyveck_caddq(&t1);

    /* Print t1 after caddq */
   // print_bytes_hex("t1_after_caddq", &t1, sizeof(t1));

    /* power2round */
    polyveck_power2round(&t1, &t0, &t1);

    /* Print t1 and t0 after power2round */
    //print_bytes_hex("t0_after_power2round", &t0, sizeof(t0));
    //print_bytes_hex("t1_after_power2round", &t1, sizeof(t1));


    //pack public
    //print_verilog_input_hex("rho",rho,SEEDBYTES);
    //print_verilog_input_hex("t1",&t1,sizeof(t1));

    /* Pack public key */
    pack_pk(pk, rho, &t1);

    /* Print pk */
    print_bytes_hex("pk", pk, sizeof(pk));

    /* Hash public key */
    shake256(tr, TRBYTES, pk, CRYPTO_PUBLICKEYBYTES);

    /* Print tr */
    //print_bytes_hex("tr", tr, sizeof(tr));

    /* Pack secret key */
    pack_sk(sk, rho, tr, key, &t0, &s1, &s2);

    /* Print sk */
    print_bytes_hex("sk", sk, sizeof(sk));
//#endif
    return 0;
}

