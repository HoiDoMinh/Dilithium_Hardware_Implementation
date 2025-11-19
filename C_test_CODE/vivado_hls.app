<project xmlns="com.autoesl.autopilot.project" name="dilithium_key-HLS" top="keccak_finalize">
    <files>
        <file name="../tb_crypto_sign_keypair.c" sc="0" tb="1" cflags=""/>
        <file name="../tb_montgomery_reduce_32bit.c" sc="0" tb="1" cflags=""/>
        <file name="../tb_packing_pb_sk.c" sc="0" tb="1" cflags=""/>
        <file name="../tb_parallel_ntt_32bit.c" sc="0" tb="1" cflags=""/>
        <file name="../tb_poly_uniform.c" sc="0" tb="1" cflags=""/>
        <file name="../tb_poly_uniform_eta.c" sc="0" tb="1" cflags=""/>
        <file name="../tb_polyvec_matrix_pointwise_montgomery.c" sc="0" tb="1" cflags=""/>
        <file name="../tb_polyvecl_polyveck_eta.c" sc="0" tb="1" cflags=""/>
        <file name="../tb_shake256.c" sc="0" tb="1" cflags=""/>
        <file name="../tb_symmetric.c" sc="0" tb="1" cflags=""/>
        <file name="../../../../../dilithium/ref/test_expandmatrix.c" sc="0" tb="1" cflags=""/>
        <file name="../test_keccak_fips202.c" sc="0" tb="1" cflags=""/>
        <file name="../../../../../dilithium/ref/test_keccak_state.c" sc="0" tb="1" cflags=""/>
        <file name="../test_power2round_polyveck.c" sc="0" tb="1" cflags=""/>
        <file name="../test_randombytes.c" sc="0" tb="1" cflags=" -Wno-unknown-pragmas"/>
        <file name="../testbench_fips202.c" sc="0" tb="1" cflags=" -Wno-unknown-pragmas"/>
        <file name="../../../dilithium/ref/api.h" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/config.h" sc="0" tb="false" cflags=""/>
        <file name="dilithium_key-HLS/fips202.c" sc="0" tb="false" cflags=""/>
        <file name="dilithium_key-HLS/fips202.h" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/ntt.c" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/ntt.h" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/packing.c" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/packing.h" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/params.h" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/poly.c" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/poly.h" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/polyvec.c" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/polyvec.h" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/randombytes.c" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/randombytes.h" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/reduce.c" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/reduce.h" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/rounding.c" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/rounding.h" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/sign.c" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/sign.h" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/symmetric-shake.c" sc="0" tb="false" cflags=""/>
        <file name="../../../dilithium/ref/symmetric.h" sc="0" tb="false" cflags=""/>
    </files>
    <includePaths/>
    <libraryPaths/>
    <Simulation>
        <SimFlow name="csim" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <solutions xmlns="">
        <solution name="solution1" status="active"/>
    </solutions>
</project>

