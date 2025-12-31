/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;
/* Structure forward decls */
typedef struct l_struct_OC_polyvecl l_struct_OC_polyvecl;
typedef struct l_struct_OC_poly l_struct_OC_poly;
typedef struct l_struct_OC_polyveck l_struct_OC_polyveck;

/* Structure contents */
struct l_struct_OC_poly {
  signed int field0[256];
};

struct l_struct_OC_polyvecl {
  l_struct_OC_poly field0[5];
};

struct l_struct_OC_polyveck {
  l_struct_OC_poly field0[6];
};


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void print_bytes_hex( char *llvm_cbe_label,  char *llvm_cbe_buf, signed long long llvm_cbe_len);
void print_verilog_input_non_reverse( char *llvm_cbe_name,  char *llvm_cbe_buf, signed long long llvm_cbe_len);
void print_verilog_input_hex( char *llvm_cbe_name,  char *llvm_cbe_buf, signed long long llvm_cbe_len);
signed int main(void);
void pqcrystals_dilithium_fips202_ref_shake256( char *, signed long long ,  char *, signed long long );
void pqcrystals_dilithium3_ref_polyvec_matrix_expand(l_struct_OC_polyvecl *,  char *);
void pqcrystals_dilithium3_ref_polyvecl_uniform_eta(l_struct_OC_polyvecl *,  char *, signed short );
void pqcrystals_dilithium3_ref_polyveck_uniform_eta(l_struct_OC_polyveck *,  char *, signed short );
void pqcrystals_dilithium3_ref_polyvecl_ntt(l_struct_OC_polyvecl *);
void pqcrystals_dilithium3_ref_polyvec_matrix_pointwise_montgomery(l_struct_OC_polyveck *, l_struct_OC_polyvecl *, l_struct_OC_polyvecl *);
void pqcrystals_dilithium3_ref_polyveck_reduce(l_struct_OC_polyveck *);
void pqcrystals_dilithium3_ref_polyveck_invntt_tomont(l_struct_OC_polyveck *);
void pqcrystals_dilithium3_ref_polyveck_add(l_struct_OC_polyveck *, l_struct_OC_polyveck *, l_struct_OC_polyveck *);
void pqcrystals_dilithium3_ref_polyveck_caddq(l_struct_OC_polyveck *);
void pqcrystals_dilithium3_ref_polyveck_power2round(l_struct_OC_polyveck *, l_struct_OC_polyveck *, l_struct_OC_polyveck *);
void pqcrystals_dilithium3_ref_pack_pk( char *,  char *, l_struct_OC_polyveck *);
void pqcrystals_dilithium3_ref_pack_sk( char *,  char *,  char *,  char *, l_struct_OC_polyveck *, l_struct_OC_polyvecl *, l_struct_OC_polyveck *);
signed int pqcrystals_dilithium3_ref_signature_internal( char *, signed long long *,  char *, signed long long ,  char *, signed long long ,  char *,  char *);
signed int pqcrystals_dilithium3_ref_verify_internal( char *, signed long long ,  char *, signed long long ,  char *, signed long long ,  char *);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str[10] = "%s (hex)\n";
static  char aesl_internal__OC_str1[6] = "%02x ";
static  char aesl_internal__OC_str4[18] = "%s[%zu:0] = %zu'h";
static  char aesl_internal__OC_str5[5] = "%02x";
static  char aesl_internal_main_OC_fixed_seed[32] = "^\xB3\x17\x42\x91\xEE\xAC\rwd0\x02\xF4\x89\xDE<\x10V\xA9\xBB\xC0\x99~\x11/M\\j9\x87\xF1";
static  char aesl_internal__OC_str7[31] = "CHUYEN KHOAN 1000USD CHO ALICE";
static  char aesl_internal__OC_str8[8] = "BANKING";
static  char aesl_internal_main_OC_rnd[32] = { ((unsigned char )-86), ((unsigned char )27), ((unsigned char )44), ((unsigned char )61), ((unsigned char )78), ((unsigned char )95), ((unsigned char )96), ((unsigned char )113), ((unsigned char )-126), ((unsigned char )-109), ((unsigned char )-92), ((unsigned char )-75), ((unsigned char )-58), ((unsigned char )-41), ((unsigned char )-24), ((unsigned char )-7), ((unsigned char )10), ((unsigned char )27), ((unsigned char )44), ((unsigned char )61), ((unsigned char )78), ((unsigned char )95), ((unsigned char )96), ((unsigned char )113), ((unsigned char )-120), ((unsigned char )-103), ((unsigned char )-86), ((unsigned char )-69), ((unsigned char )-52), ((unsigned char )-35), ((unsigned char )-18), ((unsigned char )-1) };
static  char aesl_internal__OC_str10[12] = "Random Seed";
static  char aesl_internal__OC_str11[11] = "Random RND";
static  char aesl_internal__OC_str17[16] = "Signature (sig)";
static  char aesl_internal_str4[28] = "--- [3] SIGNING PROCESS ---";
static  char aesl_internal__OC_str16[27] = "Sign failed with code: %d\n";
static  char aesl_internal_str7[42] = "[PASS] Signature Verification SUCCESSFUL!";
static  char aesl_internal_str2[2] = ";";
static  char aesl_internal__OC_str12[16] = "Public Key (pk)";
static  char aesl_internal_str6[27] = "--- [4] VERIFY PROCESS ---";
static  char aesl_internal_str5[34] = "Signature generated successfully.";
static  char aesl_internal_str9[38] = "[FAIL] Signature Verification FAILED!";
static  char aesl_internal__OC_str13[16] = "Secret Key (sk)";
static  char aesl_internal__OC_str22[23] = "       Error code: %d\n";
static  char aesl_internal_str[2] = "\n";
static  char aesl_internal_str8[66] = "       The signature matches the message, prefix, and public key.";
static  char aesl_internal_str3[47] = "--- [2] KEYGEN PROCESS (Manual Fixed Seed) ---";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

void print_bytes_hex( char *llvm_cbe_label,  char *llvm_cbe_buf, signed long long llvm_cbe_len) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
   char *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  unsigned char llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  unsigned long long llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_putchar_count = 0;
  unsigned int llvm_cbe_putchar;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @print_bytes_hex\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([10 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* %%label) nounwind, !dbg !6 for 0x%I64xth hint within @print_bytes_hex  --> \n", ++aesl_llvm_cbe_9_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])), ( char *)llvm_cbe_label);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
  if (((llvm_cbe_len&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%11, %%10 ], [ 0, %%0  for 0x%I64xth hint within @print_bytes_hex  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__7);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i8* %%buf, i64 %%storemerge1, !dbg !5 for 0x%I64xth hint within @print_bytes_hex  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__2 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8* %%3, align 1, !dbg !5 for 0x%I64xth hint within @print_bytes_hex  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__3 = (unsigned char )*llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = zext i8 %%4 to i32, !dbg !5 for 0x%I64xth hint within @print_bytes_hex  --> \n", ++aesl_llvm_cbe_19_count);
  llvm_cbe_tmp__4 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__3&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 %%5) nounwind, !dbg !5 for 0x%I64xth hint within @print_bytes_hex  --> \n", ++aesl_llvm_cbe_20_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])), llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__4);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = urem i64 %%storemerge1, 52, !dbg !6 for 0x%I64xth hint within @print_bytes_hex  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__6 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) % ((unsigned long long )(52ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__6&18446744073709551615ull)));
  if (((llvm_cbe_tmp__6&18446744073709551615ULL) == (51ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__8;
  } else {
    goto llvm_cbe_tmp__9;
  }

llvm_cbe_tmp__9:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i64 %%storemerge1, 1, !dbg !6 for 0x%I64xth hint within @print_bytes_hex  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__7 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__7&18446744073709551615ull)));
  if (((llvm_cbe_tmp__7&18446744073709551615ULL) == (llvm_cbe_len&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__7;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe_tmp__8:
if (AESL_DEBUG_TRACE)
printf("\n  %%putchar = tail call i32 @putchar(i32 10) nounwind, !dbg !6 for 0x%I64xth hint within @print_bytes_hex  --> \n", ++aesl_llvm_cbe_putchar_count);
   /*tail*/ putchar(10u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn putchar = 0x%X",llvm_cbe_putchar);
}
  goto llvm_cbe_tmp__9;

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = tail call i32 @puts(i8* getelementptr inbounds ([2 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !6 for 0x%I64xth hint within @print_bytes_hex  --> \n", ++aesl_llvm_cbe_puts_count);
   /*tail*/ puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @print_bytes_hex}\n");
  return;
}


void print_verilog_input_non_reverse( char *llvm_cbe_name,  char *llvm_cbe_buf, signed long long llvm_cbe_len) {
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  unsigned long long llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  unsigned long long llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
   char *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  unsigned char llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @print_verilog_input_non_reverse\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = shl i64 %%len, 3, !dbg !5 for 0x%I64xth hint within @print_verilog_input_non_reverse  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__10 = (unsigned long long )llvm_cbe_len << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add i64 %%1, -1, !dbg !5 for 0x%I64xth hint within @print_verilog_input_non_reverse  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__11 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__10&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__11&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([18 x i8]* @aesl_internal_.str4, i64 0, i64 0), i8* %%name, i64 %%2, i64 %%1) nounwind, !dbg !5 for 0x%I64xth hint within @print_verilog_input_non_reverse  --> \n", ++aesl_llvm_cbe_43_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 18
#endif
])), ( char *)llvm_cbe_name, llvm_cbe_tmp__11, llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__11);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__10);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = trunc i64 %%len to i32, !dbg !5 for 0x%I64xth hint within @print_verilog_input_non_reverse  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__13 = (unsigned int )((unsigned int )llvm_cbe_len&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add nsw i32 %%4, -1, !dbg !5 for 0x%I64xth hint within @print_verilog_input_non_reverse  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__14 = (unsigned int )((unsigned int )(llvm_cbe_tmp__13&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__14&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__14) < ((signed int )0u))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%12, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @print_verilog_input_non_reverse  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__20);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%storemerge1 to i64, !dbg !5 for 0x%I64xth hint within @print_verilog_input_non_reverse  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__15 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i8* %%buf, i64 %%7, !dbg !5 for 0x%I64xth hint within @print_verilog_input_non_reverse  --> \n", ++aesl_llvm_cbe_53_count);
  llvm_cbe_tmp__16 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__15))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__15));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i8* %%8, align 1, !dbg !5 for 0x%I64xth hint within @print_verilog_input_non_reverse  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__17 = (unsigned char )*llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = zext i8 %%9 to i32, !dbg !5 for 0x%I64xth hint within @print_verilog_input_non_reverse  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__18 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__17&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str5, i64 0, i64 0), i32 %%10) nounwind, !dbg !5 for 0x%I64xth hint within @print_verilog_input_non_reverse  --> \n", ++aesl_llvm_cbe_56_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__18);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__19);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%storemerge1, 1, !dbg !6 for 0x%I64xth hint within @print_verilog_input_non_reverse  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__20 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__20&4294967295ull)));
  if (((llvm_cbe_tmp__20&4294967295U) == (llvm_cbe_tmp__13&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__20;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = tail call i32 @puts(i8* getelementptr inbounds ([2 x i8]* @aesl_internal_str2, i64 0, i64 0)), !dbg !6 for 0x%I64xth hint within @print_verilog_input_non_reverse  --> \n", ++aesl_llvm_cbe_puts_count);
   /*tail*/ puts(( char *)((&aesl_internal_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @print_verilog_input_non_reverse}\n");
  return;
}


void print_verilog_input_hex( char *llvm_cbe_name,  char *llvm_cbe_buf, signed long long llvm_cbe_len) {
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  unsigned long long llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  unsigned long long llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2_2e_in_count = 0;
  unsigned int llvm_cbe_storemerge2_2e_in;
  unsigned int llvm_cbe_storemerge2_2e_in__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge2_count = 0;
  unsigned int llvm_cbe_storemerge2;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned long long llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
   char *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  unsigned char llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @print_verilog_input_hex\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = shl i64 %%len, 3, !dbg !5 for 0x%I64xth hint within @print_verilog_input_hex  --> \n", ++aesl_llvm_cbe_72_count);
  llvm_cbe_tmp__21 = (unsigned long long )llvm_cbe_len << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add i64 %%1, -1, !dbg !5 for 0x%I64xth hint within @print_verilog_input_hex  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__22 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__21&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__22&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([18 x i8]* @aesl_internal_.str4, i64 0, i64 0), i8* %%name, i64 %%2, i64 %%1) nounwind, !dbg !5 for 0x%I64xth hint within @print_verilog_input_hex  --> \n", ++aesl_llvm_cbe_74_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 18
#endif
])), ( char *)llvm_cbe_name, llvm_cbe_tmp__22, llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__22);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__21);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__23);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = trunc i64 %%len to i32, !dbg !5 for 0x%I64xth hint within @print_verilog_input_hex  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )llvm_cbe_len&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
  if ((((signed int )llvm_cbe_tmp__24) > ((signed int )0u))) {
    llvm_cbe_storemerge2_2e_in__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__24;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2.in = phi i32 [ %%storemerge2, %%.lr.ph ], [ %%4, %%0  for 0x%I64xth hint within @print_verilog_input_hex  --> \n", ++aesl_llvm_cbe_storemerge2_2e_in_count);
  llvm_cbe_storemerge2_2e_in = (unsigned int )llvm_cbe_storemerge2_2e_in__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2.in = 0x%X",llvm_cbe_storemerge2_2e_in);
printf("\nstoremerge2 = 0x%X",llvm_cbe_storemerge2);
printf("\n = 0x%X",llvm_cbe_tmp__24);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2 = add nsw i32 %%storemerge2.in, -1, !dbg !6 for 0x%I64xth hint within @print_verilog_input_hex  --> \n", ++aesl_llvm_cbe_storemerge2_count);
  llvm_cbe_storemerge2 = (unsigned int )((unsigned int )(llvm_cbe_storemerge2_2e_in&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge2 = 0x%X\n", ((unsigned int )(llvm_cbe_storemerge2&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sext i32 %%storemerge2 to i64, !dbg !5 for 0x%I64xth hint within @print_verilog_input_hex  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__25 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i8* %%buf, i64 %%6, !dbg !5 for 0x%I64xth hint within @print_verilog_input_hex  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__26 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__25))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__25));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i8* %%7, align 1, !dbg !5 for 0x%I64xth hint within @print_verilog_input_hex  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__27 = (unsigned char )*llvm_cbe_tmp__26;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = zext i8 %%8 to i32, !dbg !5 for 0x%I64xth hint within @print_verilog_input_hex  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__28 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__27&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str5, i64 0, i64 0), i32 %%9) nounwind, !dbg !5 for 0x%I64xth hint within @print_verilog_input_hex  --> \n", ++aesl_llvm_cbe_83_count);
   /*tail*/ printf(( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__28);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__29);
}
  if ((((signed int )llvm_cbe_storemerge2) > ((signed int )0u))) {
    llvm_cbe_storemerge2_2e_in__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge2;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = tail call i32 @puts(i8* getelementptr inbounds ([2 x i8]* @aesl_internal_str2, i64 0, i64 0)), !dbg !6 for 0x%I64xth hint within @print_verilog_input_hex  --> \n", ++aesl_llvm_cbe_puts_count);
   /*tail*/ puts(( char *)((&aesl_internal_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @print_verilog_input_hex}\n");
  return;
}


signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_pk_count = 0;
   char llvm_cbe_pk[1952];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_sk_count = 0;
   char llvm_cbe_sk[4032];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_sig_count = 0;
   char llvm_cbe_sig[3309];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_siglen_count = 0;
  signed long long llvm_cbe_siglen;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_m_count = 0;
   char llvm_cbe_m[64];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_pre_count = 0;
   char llvm_cbe_pre[32];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_seedbuf_count = 0;
   char llvm_cbe_seedbuf[128];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_tr_count = 0;
   char llvm_cbe_tr[64];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_s1_count = 0;
  l_struct_OC_polyvecl llvm_cbe_s1;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_s1hat_count = 0;
  l_struct_OC_polyvecl llvm_cbe_s1hat;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_s2_count = 0;
  l_struct_OC_polyveck llvm_cbe_s2;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_t1_count = 0;
  l_struct_OC_polyveck llvm_cbe_t1;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_t0_count = 0;
  l_struct_OC_polyveck llvm_cbe_t0;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_mat_count = 0;
  l_struct_OC_polyvecl llvm_cbe_mat[6];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_fixed_seed_count = 0;
   char llvm_cbe_fixed_seed[32];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_rnd_count = 0;
   char llvm_cbe_rnd[32];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
   char *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
   char *llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
   char *llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
   char *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
   char *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
   char *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
   char *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
   char *llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
   char *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
   char *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
   char *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
   char *llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
   char *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
   char *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
   char *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  l_struct_OC_polyvecl *llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  unsigned int llvm_cbe_tmp__46;
  unsigned int llvm_cbe_tmp__46__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  unsigned long long llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  signed int *llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  signed int *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  unsigned int llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  unsigned int llvm_cbe_tmp__52;
  unsigned int llvm_cbe_tmp__52__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  unsigned long long llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  signed int *llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  signed int *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  unsigned int llvm_cbe_tmp__58;
  unsigned int llvm_cbe_tmp__58__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  unsigned long long llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  signed int *llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  signed int *llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  unsigned int llvm_cbe_tmp__64;
  unsigned int llvm_cbe_tmp__64__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  unsigned int llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  unsigned long long llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  signed int *llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  signed int *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  unsigned int llvm_cbe_tmp__70;
  unsigned int llvm_cbe_tmp__70__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  unsigned int llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  unsigned long long llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  signed int *llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  signed int *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
   char *llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
   char *llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
   char *llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts1_count = 0;
  unsigned int llvm_cbe_puts1;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
   char *llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  unsigned int llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts2_count = 0;
  unsigned int llvm_cbe_puts2;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  unsigned int llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts3_count = 0;
  unsigned int llvm_cbe_puts3;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  unsigned long long llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  unsigned int llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts4_count = 0;
  unsigned int llvm_cbe_puts4;
  static  unsigned long long aesl_llvm_cbe_puts5_count = 0;
  unsigned int llvm_cbe_puts5;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts6_count = 0;
  unsigned int llvm_cbe_puts6;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  unsigned int llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [32 x i8]* %%fixed_seed, i64 0, i64 0, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__30 = ( char *)(&llvm_cbe_fixed_seed[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i8* @memcpy(i8* %%1, i8* getelementptr inbounds ([32 x i8]* @aesl_internal_main.fixed_seed, i64 0, i64 0), i64 32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_103_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__30, ( char *)((&aesl_internal_main_OC_fixed_seed[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
])), 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__31);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [64 x i8]* %%m, i64 0, i64 0, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__32 = ( char *)(&llvm_cbe_m[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 64
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call i8* @memset(i8* %%3, i32 0, i64 64 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_105_count);
  ( char *)memset(( char *)llvm_cbe_tmp__32, 0u, 64ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",64ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__33);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [32 x i8]* %%pre, i64 0, i64 0, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__34 = ( char *)(&llvm_cbe_pre[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = call i8* @memset(i8* %%5, i32 0, i64 32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_107_count);
  ( char *)memset(( char *)llvm_cbe_tmp__34, 0u, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__35);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = call i8* @memcpy(i8* %%3, i8* getelementptr inbounds ([31 x i8]* @aesl_internal_.str7, i64 0, i64 0), i64 31 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_108_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__32, ( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 31
#endif
])), 31ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",31ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__36);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call i8* @memcpy(i8* %%5, i8* getelementptr inbounds ([8 x i8]* @aesl_internal_.str8, i64 0, i64 0), i64 8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_109_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__34, ( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])), 8ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",8ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [32 x i8]* %%rnd, i64 0, i64 0, !dbg !12 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__38 = ( char *)(&llvm_cbe_rnd[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call i8* @memcpy(i8* %%9, i8* getelementptr inbounds ([32 x i8]* @aesl_internal_main.rnd, i64 0, i64 0), i64 32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_112_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__38, ( char *)((&aesl_internal_main_OC_rnd[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
])), 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([47 x i8]* @aesl_internal_str3, i64 0, i64 0)), !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 47
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [128 x i8]* %%seedbuf, i64 0, i64 0, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__40 = ( char *)(&llvm_cbe_seedbuf[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 128
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = call i8* @memcpy(i8* %%11, i8* %%1, i64 32 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_120_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__40, ( char *)llvm_cbe_tmp__30, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__41);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [128 x i8]* %%seedbuf, i64 0, i64 32, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__42 = ( char *)(&llvm_cbe_seedbuf[(((signed long long )32ull))
#ifdef AESL_BC_SIM
 % 128
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )32ull) < 128 && "Write access out of array 'seedbuf' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 6, i8* %%13, align 16, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_122_count);
  *llvm_cbe_tmp__42 = ((unsigned char )6);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )6));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds [128 x i8]* %%seedbuf, i64 0, i64 33, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__43 = ( char *)(&llvm_cbe_seedbuf[(((signed long long )33ull))
#ifdef AESL_BC_SIM
 % 128
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )33ull) < 128 && "Write access out of array 'seedbuf' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 5, i8* %%14, align 1, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_124_count);
  *llvm_cbe_tmp__43 = ((unsigned char )5);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )5));
if (AESL_DEBUG_TRACE)
printf("\n  call void @print_verilog_input_non_reverse(i8* getelementptr inbounds ([12 x i8]* @aesl_internal_.str10, i64 0, i64 0), i8* %%1, i64 32), !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_125_count);
  print_verilog_input_non_reverse(( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 12
#endif
])), ( char *)llvm_cbe_tmp__30, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @print_verilog_input_non_reverse(i8* getelementptr inbounds ([11 x i8]* @aesl_internal_.str11, i64 0, i64 0), i8* %%9, i64 32), !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_126_count);
  print_verilog_input_non_reverse(( char *)((&aesl_internal__OC_str11[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 11
#endif
])), ( char *)llvm_cbe_tmp__38, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256(i8* %%11, i64 128, i8* %%11, i64 34) nounwind, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_127_count);
  pqcrystals_dilithium_fips202_ref_shake256(( char *)llvm_cbe_tmp__40, 128ull, ( char *)llvm_cbe_tmp__40, 34ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",128ull);
printf("\nArgument  = 0x%I64X",34ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [128 x i8]* %%seedbuf, i64 0, i64 96, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__44 = ( char *)(&llvm_cbe_seedbuf[(((signed long long )96ull))
#ifdef AESL_BC_SIM
 % 128
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds [6 x %%struct.polyvecl]* %%mat, i64 0, i64 0, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__45 = (l_struct_OC_polyvecl *)(&llvm_cbe_mat[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvec_matrix_expand(%%struct.polyvecl* %%16, i8* %%11) nounwind, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_141_count);
  pqcrystals_dilithium3_ref_polyvec_matrix_expand((l_struct_OC_polyvecl *)llvm_cbe_tmp__45, ( char *)llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvecl_uniform_eta(%%struct.polyvecl* %%s1, i8* %%13, i16 zeroext 0) nounwind, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_142_count);
  pqcrystals_dilithium3_ref_polyvecl_uniform_eta((l_struct_OC_polyvecl *)(&llvm_cbe_s1), ( char *)llvm_cbe_tmp__42, ((unsigned short )0));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned short )0));
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_uniform_eta(%%struct.polyveck* %%s2, i8* %%13, i16 zeroext 5) nounwind, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_143_count);
  pqcrystals_dilithium3_ref_polyveck_uniform_eta((l_struct_OC_polyveck *)(&llvm_cbe_s2), ( char *)llvm_cbe_tmp__42, ((unsigned short )5));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned short )5));
}
  llvm_cbe_tmp__46__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_memcpy;

  do {     /* Syntactic loop 'memcpy' to make GCC happy */
llvm_cbe_memcpy:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = phi i32 [ 0, %%0 ], [ %%18, %%memcpy ], !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__46 = (unsigned int )llvm_cbe_tmp__46__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__46);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__47);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i32 %%17, 1, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__47 = (unsigned int )((unsigned int )(llvm_cbe_tmp__46&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__47&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sext i32 %%17 to i64, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_147_count);
  llvm_cbe_tmp__48 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct.polyvecl* %%s1hat, i64 0, i32 0, i64 0, i32 0, i64 %%19, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_148_count);
  llvm_cbe_tmp__49 = (signed int *)(&llvm_cbe_s1hat.field0[(((signed long long )0ull))].field0[(((signed long long )llvm_cbe_tmp__48))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__48));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 0, i32 0, i64 %%19, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__50 = (signed int *)(&llvm_cbe_s1.field0[(((signed long long )0ull))].field0[(((signed long long )llvm_cbe_tmp__48))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__48));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i32* %%21, align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_150_count);
  llvm_cbe_tmp__51 = (unsigned int )*llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%22, i32* %%20, align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_151_count);
  *llvm_cbe_tmp__49 = llvm_cbe_tmp__51;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__51);
  if (((llvm_cbe_tmp__46&4294967295U) == (255u&4294967295U))) {
    llvm_cbe_tmp__52__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_memcpy1;
  } else {
    llvm_cbe_tmp__46__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__47;   /* for PHI node */
    goto llvm_cbe_memcpy;
  }

  } while (1); /* end of syntactic loop 'memcpy' */
  do {     /* Syntactic loop 'memcpy1' to make GCC happy */
llvm_cbe_memcpy1:
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = phi i32 [ %%25, %%memcpy1 ], [ 0, %%memcpy ], !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__52 = (unsigned int )llvm_cbe_tmp__52__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__52);
printf("\n = 0x%X",llvm_cbe_tmp__53);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i32 %%24, 1, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__53 = (unsigned int )((unsigned int )(llvm_cbe_tmp__52&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__53&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = sext i32 %%24 to i64, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_156_count);
  llvm_cbe_tmp__54 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.polyvecl* %%s1hat, i64 0, i32 0, i64 1, i32 0, i64 %%26, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__55 = (signed int *)(&llvm_cbe_s1hat.field0[(((signed long long )1ull))].field0[(((signed long long )llvm_cbe_tmp__54))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__54));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 1, i32 0, i64 %%26, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__56 = (signed int *)(&llvm_cbe_s1.field0[(((signed long long )1ull))].field0[(((signed long long )llvm_cbe_tmp__54))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__54));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i32* %%28, align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_159_count);
  llvm_cbe_tmp__57 = (unsigned int )*llvm_cbe_tmp__56;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%29, i32* %%27, align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_160_count);
  *llvm_cbe_tmp__55 = llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
  if (((llvm_cbe_tmp__52&4294967295U) == (255u&4294967295U))) {
    llvm_cbe_tmp__58__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_memcpy2;
  } else {
    llvm_cbe_tmp__52__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__53;   /* for PHI node */
    goto llvm_cbe_memcpy1;
  }

  } while (1); /* end of syntactic loop 'memcpy1' */
  do {     /* Syntactic loop 'memcpy2' to make GCC happy */
llvm_cbe_memcpy2:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = phi i32 [ %%32, %%memcpy2 ], [ 0, %%memcpy1 ], !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__58 = (unsigned int )llvm_cbe_tmp__58__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__58);
printf("\n = 0x%X",llvm_cbe_tmp__59);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add i32 %%31, 1, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__59 = (unsigned int )((unsigned int )(llvm_cbe_tmp__58&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__59&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = sext i32 %%31 to i64, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__60 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds %%struct.polyvecl* %%s1hat, i64 0, i32 0, i64 2, i32 0, i64 %%33, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_166_count);
  llvm_cbe_tmp__61 = (signed int *)(&llvm_cbe_s1hat.field0[(((signed long long )2ull))].field0[(((signed long long )llvm_cbe_tmp__60))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__60));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 2, i32 0, i64 %%33, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__62 = (signed int *)(&llvm_cbe_s1.field0[(((signed long long )2ull))].field0[(((signed long long )llvm_cbe_tmp__60))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__60));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i32* %%35, align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_168_count);
  llvm_cbe_tmp__63 = (unsigned int )*llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%36, i32* %%34, align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_169_count);
  *llvm_cbe_tmp__61 = llvm_cbe_tmp__63;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
  if (((llvm_cbe_tmp__58&4294967295U) == (255u&4294967295U))) {
    llvm_cbe_tmp__64__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_memcpy3;
  } else {
    llvm_cbe_tmp__58__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__59;   /* for PHI node */
    goto llvm_cbe_memcpy2;
  }

  } while (1); /* end of syntactic loop 'memcpy2' */
  do {     /* Syntactic loop 'memcpy3' to make GCC happy */
llvm_cbe_memcpy3:
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = phi i32 [ %%39, %%memcpy3 ], [ 0, %%memcpy2 ], !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__64 = (unsigned int )llvm_cbe_tmp__64__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__64);
printf("\n = 0x%X",llvm_cbe_tmp__65);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add i32 %%38, 1, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_173_count);
  llvm_cbe_tmp__65 = (unsigned int )((unsigned int )(llvm_cbe_tmp__64&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__65&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = sext i32 %%38 to i64, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_174_count);
  llvm_cbe_tmp__66 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds %%struct.polyvecl* %%s1hat, i64 0, i32 0, i64 3, i32 0, i64 %%40, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__67 = (signed int *)(&llvm_cbe_s1hat.field0[(((signed long long )3ull))].field0[(((signed long long )llvm_cbe_tmp__66))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 3, i32 0, i64 %%40, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__68 = (signed int *)(&llvm_cbe_s1.field0[(((signed long long )3ull))].field0[(((signed long long )llvm_cbe_tmp__66))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load i32* %%42, align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__69 = (unsigned int )*llvm_cbe_tmp__68;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%43, i32* %%41, align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_178_count);
  *llvm_cbe_tmp__67 = llvm_cbe_tmp__69;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__69);
  if (((llvm_cbe_tmp__64&4294967295U) == (255u&4294967295U))) {
    llvm_cbe_tmp__70__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_memcpy4;
  } else {
    llvm_cbe_tmp__64__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__65;   /* for PHI node */
    goto llvm_cbe_memcpy3;
  }

  } while (1); /* end of syntactic loop 'memcpy3' */
  do {     /* Syntactic loop 'memcpy4' to make GCC happy */
llvm_cbe_memcpy4:
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = phi i32 [ %%46, %%memcpy4 ], [ 0, %%memcpy3 ], !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_181_count);
  llvm_cbe_tmp__70 = (unsigned int )llvm_cbe_tmp__70__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__70);
printf("\n = 0x%X",llvm_cbe_tmp__71);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add i32 %%45, 1, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__71 = (unsigned int )((unsigned int )(llvm_cbe_tmp__70&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__71&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = sext i32 %%45 to i64, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_183_count);
  llvm_cbe_tmp__72 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds %%struct.polyvecl* %%s1hat, i64 0, i32 0, i64 4, i32 0, i64 %%47, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__73 = (signed int *)(&llvm_cbe_s1hat.field0[(((signed long long )4ull))].field0[(((signed long long )llvm_cbe_tmp__72))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__72));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 4, i32 0, i64 %%47, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__74 = (signed int *)(&llvm_cbe_s1.field0[(((signed long long )4ull))].field0[(((signed long long )llvm_cbe_tmp__72))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__72));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load i32* %%49, align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_186_count);
  llvm_cbe_tmp__75 = (unsigned int )*llvm_cbe_tmp__74;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%50, i32* %%48, align 4, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_187_count);
  *llvm_cbe_tmp__73 = llvm_cbe_tmp__75;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
  if (((llvm_cbe_tmp__70&4294967295U) == (255u&4294967295U))) {
    goto llvm_cbe_tmp__85;
  } else {
    llvm_cbe_tmp__70__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__71;   /* for PHI node */
    goto llvm_cbe_memcpy4;
  }

  } while (1); /* end of syntactic loop 'memcpy4' */
llvm_cbe_tmp__85:
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvecl_ntt(%%struct.polyvecl* %%s1hat) nounwind, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_190_count);
  pqcrystals_dilithium3_ref_polyvecl_ntt((l_struct_OC_polyvecl *)(&llvm_cbe_s1hat));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvec_matrix_pointwise_montgomery(%%struct.polyveck* %%t1, %%struct.polyvecl* %%16, %%struct.polyvecl* %%s1hat) nounwind, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_191_count);
  pqcrystals_dilithium3_ref_polyvec_matrix_pointwise_montgomery((l_struct_OC_polyveck *)(&llvm_cbe_t1), (l_struct_OC_polyvecl *)llvm_cbe_tmp__45, (l_struct_OC_polyvecl *)(&llvm_cbe_s1hat));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_reduce(%%struct.polyveck* %%t1) nounwind, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_192_count);
  pqcrystals_dilithium3_ref_polyveck_reduce((l_struct_OC_polyveck *)(&llvm_cbe_t1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_invntt_tomont(%%struct.polyveck* %%t1) nounwind, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_193_count);
  pqcrystals_dilithium3_ref_polyveck_invntt_tomont((l_struct_OC_polyveck *)(&llvm_cbe_t1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_add(%%struct.polyveck* %%t1, %%struct.polyveck* %%t1, %%struct.polyveck* %%s2) nounwind, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_194_count);
  pqcrystals_dilithium3_ref_polyveck_add((l_struct_OC_polyveck *)(&llvm_cbe_t1), (l_struct_OC_polyveck *)(&llvm_cbe_t1), (l_struct_OC_polyveck *)(&llvm_cbe_s2));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_caddq(%%struct.polyveck* %%t1) nounwind, !dbg !15 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_195_count);
  pqcrystals_dilithium3_ref_polyveck_caddq((l_struct_OC_polyveck *)(&llvm_cbe_t1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_power2round(%%struct.polyveck* %%t1, %%struct.polyveck* %%t0, %%struct.polyveck* %%t1) nounwind, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_196_count);
  pqcrystals_dilithium3_ref_polyveck_power2round((l_struct_OC_polyveck *)(&llvm_cbe_t1), (l_struct_OC_polyveck *)(&llvm_cbe_t0), (l_struct_OC_polyveck *)(&llvm_cbe_t1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds [1952 x i8]* %%pk, i64 0, i64 0, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_197_count);
  llvm_cbe_tmp__76 = ( char *)(&llvm_cbe_pk[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 1952
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_pack_pk(i8* %%53, i8* %%11, %%struct.polyveck* %%t1) nounwind, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_198_count);
  pqcrystals_dilithium3_ref_pack_pk(( char *)llvm_cbe_tmp__76, ( char *)llvm_cbe_tmp__40, (l_struct_OC_polyveck *)(&llvm_cbe_t1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @print_bytes_hex(i8* getelementptr inbounds ([16 x i8]* @aesl_internal_.str12, i64 0, i64 0), i8* %%53, i64 1952), !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_199_count);
  print_bytes_hex(( char *)((&aesl_internal__OC_str12[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
])), ( char *)llvm_cbe_tmp__76, 1952ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1952ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = getelementptr inbounds [64 x i8]* %%tr, i64 0, i64 0, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_200_count);
  llvm_cbe_tmp__77 = ( char *)(&llvm_cbe_tr[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 64
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256(i8* %%54, i64 64, i8* %%53, i64 1952) nounwind, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_201_count);
  pqcrystals_dilithium_fips202_ref_shake256(( char *)llvm_cbe_tmp__77, 64ull, ( char *)llvm_cbe_tmp__76, 1952ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",64ull);
printf("\nArgument  = 0x%I64X",1952ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds [4032 x i8]* %%sk, i64 0, i64 0, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_202_count);
  llvm_cbe_tmp__78 = ( char *)(&llvm_cbe_sk[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4032
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_pack_sk(i8* %%55, i8* %%11, i8* %%54, i8* %%15, %%struct.polyveck* %%t0, %%struct.polyvecl* %%s1, %%struct.polyveck* %%s2) nounwind, !dbg !14 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_203_count);
  pqcrystals_dilithium3_ref_pack_sk(( char *)llvm_cbe_tmp__78, ( char *)llvm_cbe_tmp__40, ( char *)llvm_cbe_tmp__77, ( char *)llvm_cbe_tmp__44, (l_struct_OC_polyveck *)(&llvm_cbe_t0), (l_struct_OC_polyvecl *)(&llvm_cbe_s1), (l_struct_OC_polyveck *)(&llvm_cbe_s2));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @print_bytes_hex(i8* getelementptr inbounds ([16 x i8]* @aesl_internal_.str13, i64 0, i64 0), i8* %%55, i64 4032), !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_204_count);
  print_bytes_hex(( char *)((&aesl_internal__OC_str13[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
])), ( char *)llvm_cbe_tmp__78, 4032ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",4032ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts1 = call i32 @puts(i8* getelementptr inbounds ([28 x i8]* @aesl_internal_str4, i64 0, i64 0)), !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts1_count);
  puts(( char *)((&aesl_internal_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 28
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts1 = 0x%X",llvm_cbe_puts1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = getelementptr inbounds [3309 x i8]* %%sig, i64 0, i64 0, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_205_count);
  llvm_cbe_tmp__79 = ( char *)(&llvm_cbe_sig[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3309
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = call i32 @pqcrystals_dilithium3_ref_signature_internal(i8* %%56, i64* %%siglen, i8* %%3, i64 64, i8* %%5, i64 32, i8* %%9, i8* %%55) nounwind, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_206_count);
  llvm_cbe_tmp__80 = (unsigned int )pqcrystals_dilithium3_ref_signature_internal(( char *)llvm_cbe_tmp__79, (signed long long *)(&llvm_cbe_siglen), ( char *)llvm_cbe_tmp__32, 64ull, ( char *)llvm_cbe_tmp__34, 32ull, ( char *)llvm_cbe_tmp__38, ( char *)llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",64ull);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__80);
}
  if (((llvm_cbe_tmp__80&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__86;
  } else {
    goto llvm_cbe_tmp__87;
  }

llvm_cbe_tmp__86:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts2 = call i32 @puts(i8* getelementptr inbounds ([34 x i8]* @aesl_internal_str5, i64 0, i64 0)), !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts2_count);
  puts(( char *)((&aesl_internal_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 34
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts2 = 0x%X",llvm_cbe_puts2);
}
  goto llvm_cbe_tmp__88;

llvm_cbe_tmp__87:
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([27 x i8]* @aesl_internal_.str16, i64 0, i64 0), i32 %%57) nounwind, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_215_count);
  printf(( char *)((&aesl_internal__OC_str16[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 27
#endif
])), llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__80);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__81);
}
  goto llvm_cbe_tmp__88;

llvm_cbe_tmp__88:
if (AESL_DEBUG_TRACE)
printf("\n  call void @print_bytes_hex(i8* getelementptr inbounds ([16 x i8]* @aesl_internal_.str17, i64 0, i64 0), i8* %%56, i64 3309), !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_217_count);
  print_bytes_hex(( char *)((&aesl_internal__OC_str17[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
])), ( char *)llvm_cbe_tmp__79, 3309ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",3309ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts3 = call i32 @puts(i8* getelementptr inbounds ([27 x i8]* @aesl_internal_str6, i64 0, i64 0)), !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts3_count);
  puts(( char *)((&aesl_internal_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 27
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts3 = 0x%X",llvm_cbe_puts3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = load i64* %%siglen, align 8, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_224_count);
  llvm_cbe_tmp__82 = (unsigned long long )*(&llvm_cbe_siglen);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = call i32 @pqcrystals_dilithium3_ref_verify_internal(i8* %%56, i64 %%63, i8* %%3, i64 64, i8* %%5, i64 32, i8* %%53) nounwind, !dbg !13 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_225_count);
  llvm_cbe_tmp__83 = (unsigned int )pqcrystals_dilithium3_ref_verify_internal(( char *)llvm_cbe_tmp__79, llvm_cbe_tmp__82, ( char *)llvm_cbe_tmp__32, 64ull, ( char *)llvm_cbe_tmp__34, 32ull, ( char *)llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__82);
printf("\nArgument  = 0x%I64X",64ull);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__83);
}
  if (((llvm_cbe_tmp__83&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__89;
  } else {
    goto llvm_cbe_tmp__90;
  }

llvm_cbe_tmp__89:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts4 = call i32 @puts(i8* getelementptr inbounds ([42 x i8]* @aesl_internal_str7, i64 0, i64 0)), !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts4_count);
  puts(( char *)((&aesl_internal_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 42
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts4 = 0x%X",llvm_cbe_puts4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts5 = call i32 @puts(i8* getelementptr inbounds ([66 x i8]* @aesl_internal_str8, i64 0, i64 0)), !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts5_count);
  puts(( char *)((&aesl_internal_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 66
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts5 = 0x%X",llvm_cbe_puts5);
}
  goto llvm_cbe_tmp__91;

llvm_cbe_tmp__90:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts6 = call i32 @puts(i8* getelementptr inbounds ([38 x i8]* @aesl_internal_str9, i64 0, i64 0)), !dbg !17 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts6_count);
  puts(( char *)((&aesl_internal_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 38
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts6 = 0x%X",llvm_cbe_puts6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([23 x i8]* @aesl_internal_.str22, i64 0, i64 0), i32 %%64) nounwind, !dbg !16 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_234_count);
  printf(( char *)((&aesl_internal__OC_str22[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 23
#endif
])), llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__83);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__84);
}
  goto llvm_cbe_tmp__91;

llvm_cbe_tmp__91:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return 0u;
}

