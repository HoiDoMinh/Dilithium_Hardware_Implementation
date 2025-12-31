# ==============================================================
# File generated on Wed Dec 31 20:32:18 +0700 2025
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
# SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
# IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
# Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
# ==============================================================
CSIM_DESIGN = 1

__SIM_FPO__ = 1

__HLS_FPO_v6_1__ = 1

__SIM_MATHHLS__ = 1

__SIM_OPENCV__ = 1

__SIM_FFT__ = 1

__SIM_FIR__ = 1

__SIM_DDS__ = 1

ObjDir = obj

HLS_SOURCES = ../../../TB_DILITHIUM_MODULE.c ../../../../../C_test_CODE/tb_crypto_sign_keypair.c ../../../../../C_test_CODE/tb_montgomery_reduce_32bit.c ../../../../../C_test_CODE/tb_packing_pb_sk.c ../../../../../C_test_CODE/tb_parallel_ntt_32bit.c ../../../../../C_test_CODE/tb_poly_uniform.c ../../../../../C_test_CODE/tb_poly_uniform_eta.c ../../../../../C_test_CODE/tb_polyvec_matrix_pointwise_montgomery.c ../../../../../C_test_CODE/tb_polyvecl_polyveck_eta.c ../../../tb_polyveclntt.c ../../../../../C_test_CODE/tb_shake256.c ../../../../../C_test_CODE/tb_sign.c ../../../../../C_test_CODE/tb_symmetric.c ../../../tb_verify.c ../../../../../C_test_CODE/test_keccak_fips202.c ../../../../../C_test_CODE/test_power2round_polyveck.c ../../../../../C_test_CODE/test_randombytes.c ../../../../../C_test_CODE/testbench_fips202.c ../../../../../dilithium/ref/fips202.c ../../../../../dilithium/ref/ntt.c ../../../../../dilithium/ref/packing.c ../../../../../dilithium/ref/poly.c ../../../../../dilithium/ref/polyvec.c ../../../../../dilithium/ref/randombytes.c ../../../../../dilithium/ref/reduce.c ../../../../../dilithium/ref/rounding.c ../../../../../dilithium/ref/sign.c ../../../../../dilithium/ref/symmetric-shake.c ../../../../../dilithium/ref/test_expandmatrix.c ../../../../../dilithium/ref/test_keccak_state.c

TARGET := csim.exe

AUTOPILOT_ROOT := D:/systemfile/Vivado/2018.3
AUTOPILOT_MACH := win64
ifdef AP_GCC_M32
  AUTOPILOT_MACH := Linux_x86
  IFLAG += -m32
endif
ifndef AP_GCC_PATH
  AP_GCC_PATH := D:/systemfile/Vivado/2018.3/msys64/mingw64/bin
endif
AUTOPILOT_TOOL := ${AUTOPILOT_ROOT}/${AUTOPILOT_MACH}/tools
AP_CLANG_PATH := ${AUTOPILOT_ROOT}/msys64/mingw64/bin
AUTOPILOT_TECH := ${AUTOPILOT_ROOT}/common/technology


IFLAG += -I "${AUTOPILOT_TOOL}/systemc/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include/opencv"
IFLAG += -I "${AUTOPILOT_ROOT}/include/ap_sysc"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_FP_comp"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_comp"
IFLAG += -I "${AUTOPILOT_TOOL}/auto_cc/include"
IFLAG += -D__SIM_FPO__

IFLAG += -D__HLS_FPO_v6_1__

IFLAG += -D__SIM_OPENCV__

IFLAG += -D__SIM_FFT__

IFLAG += -D__SIM_FIR__

IFLAG += -D__SIM_DDS__

IFLAG += -D__DSP48E1__
IFLAG += -I../../. 
IFLAG += -g
IFLAG += -DNT
LFLAG += -Wl,--enable-auto-import 
DFLAG += -DAUTOCC
DFLAG += -D__xilinx_ip_top= -DAESL_TB
CCFLAG += 
TOOLCHAIN += 



include ./Makefile.rules

all: $(TARGET)



AUTOCC := cmd //c apcc.bat  

$(ObjDir)/TB_DILITHIUM_MODULE.o: ../../../TB_DILITHIUM_MODULE.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../TB_DILITHIUM_MODULE.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/TB_DILITHIUM_MODULE.d

$(ObjDir)/tb_crypto_sign_keypair.o: ../../../../../C_test_CODE/tb_crypto_sign_keypair.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../C_test_CODE/tb_crypto_sign_keypair.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/tb_crypto_sign_keypair.d

$(ObjDir)/tb_montgomery_reduce_32bit.o: ../../../../../C_test_CODE/tb_montgomery_reduce_32bit.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../C_test_CODE/tb_montgomery_reduce_32bit.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/tb_montgomery_reduce_32bit.d

$(ObjDir)/tb_packing_pb_sk.o: ../../../../../C_test_CODE/tb_packing_pb_sk.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../C_test_CODE/tb_packing_pb_sk.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/tb_packing_pb_sk.d

$(ObjDir)/tb_parallel_ntt_32bit.o: ../../../../../C_test_CODE/tb_parallel_ntt_32bit.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../C_test_CODE/tb_parallel_ntt_32bit.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/tb_parallel_ntt_32bit.d

$(ObjDir)/tb_poly_uniform.o: ../../../../../C_test_CODE/tb_poly_uniform.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../C_test_CODE/tb_poly_uniform.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/tb_poly_uniform.d

$(ObjDir)/tb_poly_uniform_eta.o: ../../../../../C_test_CODE/tb_poly_uniform_eta.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../C_test_CODE/tb_poly_uniform_eta.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/tb_poly_uniform_eta.d

$(ObjDir)/tb_polyvec_matrix_pointwise_montgomery.o: ../../../../../C_test_CODE/tb_polyvec_matrix_pointwise_montgomery.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../C_test_CODE/tb_polyvec_matrix_pointwise_montgomery.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/tb_polyvec_matrix_pointwise_montgomery.d

$(ObjDir)/tb_polyvecl_polyveck_eta.o: ../../../../../C_test_CODE/tb_polyvecl_polyveck_eta.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../C_test_CODE/tb_polyvecl_polyveck_eta.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/tb_polyvecl_polyveck_eta.d

$(ObjDir)/tb_polyveclntt.o: ../../../tb_polyveclntt.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../tb_polyveclntt.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -I../../../../.  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/tb_polyveclntt.d

$(ObjDir)/tb_shake256.o: ../../../../../C_test_CODE/tb_shake256.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../C_test_CODE/tb_shake256.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/tb_shake256.d

$(ObjDir)/tb_sign.o: ../../../../../C_test_CODE/tb_sign.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../C_test_CODE/tb_sign.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/tb_sign.d

$(ObjDir)/tb_symmetric.o: ../../../../../C_test_CODE/tb_symmetric.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../C_test_CODE/tb_symmetric.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/tb_symmetric.d

$(ObjDir)/tb_verify.o: ../../../tb_verify.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../tb_verify.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/tb_verify.d

$(ObjDir)/test_keccak_fips202.o: ../../../../../C_test_CODE/test_keccak_fips202.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../C_test_CODE/test_keccak_fips202.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/test_keccak_fips202.d

$(ObjDir)/test_power2round_polyveck.o: ../../../../../C_test_CODE/test_power2round_polyveck.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../C_test_CODE/test_power2round_polyveck.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/test_power2round_polyveck.d

$(ObjDir)/test_randombytes.o: ../../../../../C_test_CODE/test_randombytes.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../C_test_CODE/test_randombytes.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/test_randombytes.d

$(ObjDir)/testbench_fips202.o: ../../../../../C_test_CODE/testbench_fips202.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../C_test_CODE/testbench_fips202.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/testbench_fips202.d

$(ObjDir)/fips202.o: ../../../../../dilithium/ref/fips202.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../dilithium/ref/fips202.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/fips202.d

$(ObjDir)/ntt.o: ../../../../../dilithium/ref/ntt.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../dilithium/ref/ntt.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/ntt.d

$(ObjDir)/packing.o: ../../../../../dilithium/ref/packing.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../dilithium/ref/packing.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/packing.d

$(ObjDir)/poly.o: ../../../../../dilithium/ref/poly.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../dilithium/ref/poly.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/poly.d

$(ObjDir)/polyvec.o: ../../../../../dilithium/ref/polyvec.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../dilithium/ref/polyvec.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/polyvec.d

$(ObjDir)/randombytes.o: ../../../../../dilithium/ref/randombytes.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../dilithium/ref/randombytes.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/randombytes.d

$(ObjDir)/reduce.o: ../../../../../dilithium/ref/reduce.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../dilithium/ref/reduce.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/reduce.d

$(ObjDir)/rounding.o: ../../../../../dilithium/ref/rounding.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../dilithium/ref/rounding.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/rounding.d

$(ObjDir)/sign.o: ../../../../../dilithium/ref/sign.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../dilithium/ref/sign.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/sign.d

$(ObjDir)/symmetric-shake.o: ../../../../../dilithium/ref/symmetric-shake.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../dilithium/ref/symmetric-shake.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/symmetric-shake.d

$(ObjDir)/test_expandmatrix.o: ../../../../../dilithium/ref/test_expandmatrix.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../dilithium/ref/test_expandmatrix.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/test_expandmatrix.d

$(ObjDir)/test_keccak_state.o: ../../../../../dilithium/ref/test_keccak_state.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../../dilithium/ref/test_keccak_state.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/test_keccak_state.d
