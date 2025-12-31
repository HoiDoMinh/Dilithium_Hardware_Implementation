############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project test_code
add_files ../dilithium/ref/api.h
add_files ../dilithium/ref/config.h
add_files ../dilithium/ref/fips202.c
add_files ../dilithium/ref/fips202.h
add_files ../dilithium/ref/ntt.c
add_files ../dilithium/ref/ntt.h
add_files ../dilithium/ref/packing.c
add_files ../dilithium/ref/packing.h
add_files ../dilithium/ref/params.h
add_files ../dilithium/ref/poly.c
add_files ../dilithium/ref/poly.h
add_files ../dilithium/ref/polyvec.c
add_files ../dilithium/ref/polyvec.h
add_files ../dilithium/ref/randombytes.c
add_files ../dilithium/ref/randombytes.h
add_files ../dilithium/ref/reduce.c
add_files ../dilithium/ref/reduce.h
add_files ../dilithium/ref/rounding.c
add_files ../dilithium/ref/rounding.h
add_files ../dilithium/ref/sign.c
add_files ../dilithium/ref/sign.h
add_files ../dilithium/ref/symmetric-shake.c
add_files ../dilithium/ref/symmetric.h
add_files ../dilithium/ref/test_expandmatrix.c
add_files ../dilithium/ref/test_keccak_state.c
add_files -tb test_code/TB_DILITHIUM_MODULE.c
add_files -tb ../C_test_CODE/tb_crypto_sign_keypair.c
add_files -tb ../C_test_CODE/tb_montgomery_reduce_32bit.c
add_files -tb ../C_test_CODE/tb_packing_pb_sk.c
add_files -tb ../C_test_CODE/tb_parallel_ntt_32bit.c
add_files -tb ../C_test_CODE/tb_poly_uniform.c
add_files -tb ../C_test_CODE/tb_poly_uniform_eta.c
add_files -tb ../C_test_CODE/tb_polyvec_matrix_pointwise_montgomery.c
add_files -tb ../C_test_CODE/tb_polyvecl_polyveck_eta.c
add_files -tb test_code/tb_polyveclntt.c -cflags "-I."
add_files -tb ../C_test_CODE/tb_shake256.c
add_files -tb ../C_test_CODE/tb_sign.c
add_files -tb ../C_test_CODE/tb_symmetric.c
add_files -tb test_code/tb_verify.c
add_files -tb ../C_test_CODE/test_keccak_fips202.c
add_files -tb ../C_test_CODE/test_power2round_polyveck.c
add_files -tb ../C_test_CODE/test_randombytes.c
add_files -tb ../C_test_CODE/testbench_fips202.c
open_solution "solution1"
set_part {xa7a12tcsg325-1q}
create_clock -period 10 -name default
#source "./test_code/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
