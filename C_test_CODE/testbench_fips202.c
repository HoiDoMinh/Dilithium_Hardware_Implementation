#if 0
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "fips202.h"


void print_hex(const char *label, const uint8_t *data, size_t len) {
    printf("%s: ", label);
    for(size_t i = 0; i < len; i++) {
        printf("%02x", data[i]);
        if((i+1) % 32 == 0 && i != len-1) printf("\n%*s", (int)strlen(label)+2, "");
    }
    printf("\n");
}

// ham so sanh ket qua
int compare_result(const char *test_name, const uint8_t *result, const uint8_t *expected, size_t len) {
    if(memcmp(result, expected, len) == 0) {
        printf("[PASS] %s\n", test_name);
        return 1;
    } else {
        printf("[FAIL] %s\n", test_name);
        print_hex("  Got     ", result, len);
        print_hex("  Expected", expected, len);
        return 0;
    }
}


// TEST 1: SHA3-256
void test_sha3_256() {
    printf("TEST 1: SHA3-256\n");

    // Test case 1: Empty string
    uint8_t input1[] = "";
    uint8_t output1[32];
    uint8_t expected1[32] = {
        0xa7, 0xff, 0xc6, 0xf8, 0xbf, 0x1e, 0xd7, 0x66,
        0x51, 0xc1, 0x47, 0x56, 0xa0, 0x61, 0xd6, 0x62,
        0xf5, 0x80, 0xff, 0x4d, 0xe4, 0x3b, 0x49, 0xfa,
        0x82, 0xd8, 0x0a, 0x4b, 0x80, 0xf8, 0x43, 0x4a
    };
    sha3_256(output1, input1, 0);
    compare_result("SHA3-256: Empty string", output1, expected1, 32);

    // Test case 2: "abc"
    uint8_t input2[] = "abc";
    uint8_t output2[32];
    uint8_t expected2[32] = {
        0x3a, 0x98, 0x5d, 0xa7, 0x4f, 0xe2, 0x25, 0xb2,
        0x04, 0x5c, 0x17, 0x2d, 0x6b, 0xd3, 0x90, 0xbd,
        0x85, 0x5f, 0x08, 0x6e, 0x3e, 0x9d, 0x52, 0x5b,
        0x46, 0xbf, 0xe2, 0x45, 0x11, 0x43, 0x15, 0x32
    };
    sha3_256(output2, input2, 3);
    compare_result("SHA3-256: 'abc'", output2, expected2, 32);

    // Test case 3: Longer message
    uint8_t input3[] = "The quick brown fox jumps over the lazy dog";
    uint8_t output3[32];
    sha3_256(output3, input3, strlen((char*)input3));
    print_hex("SHA3-256: Long message", output3, 32);
}


// TEST 2: SHA3-512
void test_sha3_512() {
    printf("TEST 2: SHA3-512\n");
    // Test case 1: Empty string
    uint8_t input1[] = "";
    uint8_t output1[64];
    uint8_t expected1[64] = {
        0xa6, 0x9f, 0x73, 0xcc, 0xa2, 0x3a, 0x9a, 0xc5,
        0xc8, 0xb5, 0x67, 0xdc, 0x18, 0x5a, 0x75, 0x6e,
        0x97, 0xc9, 0x82, 0x16, 0x4f, 0xe2, 0x58, 0x59,
        0xe0, 0xd1, 0xdc, 0xc1, 0x47, 0x5c, 0x80, 0xa6,
        0x15, 0xb2, 0x12, 0x3a, 0xf1, 0xf5, 0xf9, 0x4c,
        0x11, 0xe3, 0xe9, 0x40, 0x2c, 0x3a, 0xc5, 0x58,
        0xf5, 0x00, 0x19, 0x9d, 0x95, 0xb6, 0xd3, 0xe3,
        0x01, 0x75, 0x85, 0x86, 0x28, 0x1d, 0xcd, 0x26
    };
    sha3_512(output1, input1, 0);
    compare_result("SHA3-512: Empty string", output1, expected1, 64);

    // Test case 2: "abc"
    uint8_t input2[] = "abc";
    uint8_t output2[64];
    uint8_t expected2[64] = {
        0xb7, 0x51, 0x85, 0x0b, 0x1a, 0x57, 0x16, 0x8a,
        0x56, 0x93, 0xcd, 0x92, 0x4b, 0x6b, 0x09, 0x6e,
        0x08, 0xf6, 0x21, 0x82, 0x74, 0x44, 0xf7, 0x0d,
        0x88, 0x4f, 0x5d, 0x02, 0x40, 0xd2, 0x71, 0x2e,
        0x10, 0xe1, 0x16, 0xe9, 0x19, 0x2a, 0xf3, 0xc9,
        0x1a, 0x7e, 0xc5, 0x76, 0x47, 0xe3, 0x93, 0x40,
        0x57, 0x34, 0x0b, 0x4c, 0xf4, 0x08, 0xd5, 0xa5,
        0x65, 0x92, 0xf8, 0x27, 0x4e, 0xec, 0x53, 0xf0
    };
    sha3_512(output2, input2, 3);
    compare_result("SHA3-512: 'abc'", output2, expected2, 64);
}


// TEST 3: SHAKE128
void test_shake128() {
    printf("TEST 3: SHAKE128 XOF\n");

    // Test case 1: Generate 32 bytes
    uint8_t input1[] = "abc";
    uint8_t output1[32];
    shake128(output1, 32, input1, 3);
    print_hex("SHAKE128: 'abc' -> 32 bytes", output1, 32);

    // Test case 2: Generate 64 bytes (variable output)
    uint8_t output2[64];
    shake128(output2, 64, input1, 3);
    print_hex("SHAKE128: 'abc' -> 64 bytes", output2, 64);

    // Test case 3: Generate 168 bytes (one full block)
    uint8_t output3[168];
    shake128(output3, 168, input1, 3);
    print_hex("SHAKE128: 'abc' -> 168 bytes (first 32)", output3, 32);

    // Test case 4: Empty input
    uint8_t input4[] = "";
    uint8_t output4[32];
    shake128(output4, 32, input4, 0);
    print_hex("SHAKE128: Empty -> 32 bytes", output4, 32);
}


// TEST 4: SHAKE256

void test_shake256() {
    printf("TEST 4: SHAKE256 XOF\n");


    // Test case 1: Generate 32 bytes
    uint8_t input1[] = "abc";
    uint8_t output1[32];
    shake256(output1, 32, input1, 3);
    print_hex("SHAKE256: 'abc' -> 32 bytes", output1, 32);

    // Test case 2: Generate 64 bytes
    uint8_t output2[64];
    shake256(output2, 64, input1, 3);
    print_hex("SHAKE256: 'abc' -> 64 bytes", output2, 64);

    // Test case 3: Generate 136 bytes (one full block)
    uint8_t output3[128];
    shake256(output3, 136, input1, 3);
    print_hex("SHAKE256: 'abc' -> 136 bytes (first 32)", output3, 32);
}


// TEST 5: SHAKE128 Incremental API

void test_shake128_incremental() {
    printf("TEST 5: SHAKE128 Incremental API\n");

    keccak_state state;
    uint8_t output1[32], output2[32];

    // Test: One-shot vs incremental should give same result
    uint8_t msg1[] = "Hello";
    uint8_t msg2[] = " World";

    // One-shot
    uint8_t combined[11] = "Hello World";
    shake128(output1, 32, combined, 11);
    print_hex("One-shot 'Hello World'", output1, 32);

    // Incremental
    shake128_init(&state);
    shake128_absorb(&state, msg1, 5);
    shake128_absorb(&state, msg2, 6);
    shake128_finalize(&state);
    shake128_squeeze(output2, 32, &state);
    print_hex("Incremental 'Hello'+'World'", output2, 32);

    compare_result("Incremental == One-shot", output2, output1, 32);

    // Test: Continue squeezing
    uint8_t output3[32];
    shake128_squeeze(output3, 32, &state);
    print_hex("Continue squeezing 32 more bytes", output3, 32);
}

// TEST 6: SHAKE256 Incremental API
void test_shake256_incremental() {
    printf("TEST 6: SHAKE256 Incremental API\n");


    keccak_state state;
    uint8_t output1[64], output2[64];

    // One-shot
    uint8_t msg[] = "Dilithium Signature Scheme";
    shake256(output1, 64, msg, strlen((char*)msg));
    print_hex("One-shot", output1, 64);

    // Incremental
    shake256_init(&state);
    shake256_absorb(&state, msg, strlen((char*)msg));
    shake256_finalize(&state);
    shake256_squeeze(output2, 64, &state);
    print_hex("Incremental", output2, 64);

    compare_result("SHAKE256: Incremental == One-shot", output2, output1, 64);
}

// TEST 7: absorb_once API

void test_absorb_once() {
    printf("TEST 7: absorb_once API\n");

    keccak_state state1, state2;
    uint8_t output1[32], output2[32];
    uint8_t msg[] = "Test message for absorb_once";

    // Method 1: init + absorb + finalize
    shake128_init(&state1);
    shake128_absorb(&state1, msg, strlen((char*)msg));
    shake128_finalize(&state1);
    shake128_squeeze(output1, 32, &state1);

    // Method 2: absorb_once
    shake128_absorb_once(&state2, msg, strlen((char*)msg));
    shake128_squeeze(output2, 32, &state2);

    compare_result("absorb_once == init+absorb+finalize", output2, output1, 32);
}


// TEST 8: squeezeblocks API
void test_squeezeblocks() {
    printf("TEST 8: squeezeblocks API\n");

    keccak_state state;
    uint8_t msg[] = "Test";
    uint8_t output1[SHAKE128_RATE * 3]; // 3 blocks = 504 bytes
    uint8_t output2[SHAKE128_RATE * 3];

    // Method 1: Using squeeze
    shake128_absorb_once(&state, msg, 4);
    shake128_squeeze(output1, SHAKE128_RATE * 3, &state);

    // Method 2: Using squeezeblocks
    shake128_absorb_once(&state, msg, 4);
    shake128_squeezeblocks(output2, 3, &state);

    compare_result("squeezeblocks == squeeze for full blocks",
                   output2, output1, SHAKE128_RATE * 3);

    print_hex("First block (168 bytes)", output2, SHAKE128_RATE);
}


int main_disabled() {
    test_sha3_256();           // Hash function tests
    test_sha3_512();           // 512-bit hash
    test_shake128();           // Extendable output function
    test_shake256();           // Higher security XOF
    test_shake128_incremental(); // Streaming API
    test_shake256_incremental(); // Streaming API for SHAKE256
    test_absorb_once();        // Optimized single-pass API
    test_squeezeblocks();      // Efficient block extraction


    return 0;
}
#endif
