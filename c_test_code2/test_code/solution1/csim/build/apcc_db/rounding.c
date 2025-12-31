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

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int pqcrystals_dilithium3_ref_power2round(signed int *llvm_cbe_a0, signed int llvm_cbe_a);
signed int pqcrystals_dilithium3_ref_decompose(signed int *llvm_cbe_a0, signed int llvm_cbe_a);
signed int pqcrystals_dilithium3_ref_make_hint(signed int llvm_cbe_a0, signed int llvm_cbe_a1);
signed int pqcrystals_dilithium3_ref_use_hint(signed int llvm_cbe_a, signed int llvm_cbe_hint);


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

signed int pqcrystals_dilithium3_ref_power2round(signed int *llvm_cbe_a0, signed int llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_power2round\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = add nsw i32 %%a, 4095, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_power2round  --> \n", ++aesl_llvm_cbe_4_count);
  llvm_cbe_tmp__1 = (unsigned int )((unsigned int )(llvm_cbe_a&4294967295ull)) + ((unsigned int )(4095u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__1&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = ashr i32 %%1, 13, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_power2round  --> \n", ++aesl_llvm_cbe_5_count);
  llvm_cbe_tmp__2 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__1) >> ((signed int )13u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__2));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = and i32 %%1, -8192, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_power2round  --> \n", ++aesl_llvm_cbe_10_count);
  llvm_cbe_tmp__3 = (unsigned int )llvm_cbe_tmp__1 & 4294959104u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sub nsw i32 %%a, %%3, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_power2round  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__4 = (unsigned int )((unsigned int )(llvm_cbe_a&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__3&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__4&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%4, i32* %%a0, align 4, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_power2round  --> \n", ++aesl_llvm_cbe_13_count);
  *llvm_cbe_a0 = llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_power2round}\n");
  return llvm_cbe_tmp__2;
}


signed int pqcrystals_dilithium3_ref_decompose(signed int *llvm_cbe_a0, signed int llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_decompose\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = add nsw i32 %%a, 127, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_decompose  --> \n", ++aesl_llvm_cbe_22_count);
  llvm_cbe_tmp__5 = (unsigned int )((unsigned int )(llvm_cbe_a&4294967295ull)) + ((unsigned int )(127u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__5&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = ashr i32 %%1, 7, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_decompose  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__6 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__5) >> ((signed int )7u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__6));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = mul nsw i32 %%2, 1025, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_decompose  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__7 = (unsigned int )((unsigned int )(llvm_cbe_tmp__6&4294967295ull)) * ((unsigned int )(1025u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__7&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add nsw i32 %%3, 2097152, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_decompose  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__8 = (unsigned int )((unsigned int )(llvm_cbe_tmp__7&4294967295ull)) + ((unsigned int )(2097152u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__8&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = lshr i32 %%4, 22, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_decompose  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__9 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__8&4294967295ull)) >> ((unsigned int )(22u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__9&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = and i32 %%5, 15, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_decompose  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__10 = (unsigned int )llvm_cbe_tmp__9 & 15u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = mul i32 %%6, -523776, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_decompose  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__11 = (unsigned int )((unsigned int )(llvm_cbe_tmp__10&4294967295ull)) * ((unsigned int )(4294443520u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__11&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i32 %%7, %%a, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_decompose  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__12 = (unsigned int )((unsigned int )(llvm_cbe_tmp__11&4294967295ull)) + ((unsigned int )(llvm_cbe_a&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__12&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = sub nsw i32 4190208, %%8, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_decompose  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__13 = (unsigned int )((unsigned int )(4190208u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__12&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__13&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = ashr i32 %%9, 31, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_decompose  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__14 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__13) >> ((signed int )31u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__14));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = and i32 %%10, 8380417, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_decompose  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__15 = (unsigned int )llvm_cbe_tmp__14 & 8380417u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sub nsw i32 %%8, %%11, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_decompose  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__16 = (unsigned int )((unsigned int )(llvm_cbe_tmp__12&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__15&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__16&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%12, i32* %%a0, align 4, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_decompose  --> \n", ++aesl_llvm_cbe_40_count);
  *llvm_cbe_a0 = llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_decompose}\n");
  return llvm_cbe_tmp__10;
}


signed int pqcrystals_dilithium3_ref_make_hint(signed int llvm_cbe_a0, signed int llvm_cbe_a1) {
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond1_count = 0;
  bool llvm_cbe_or_2e_cond1;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_make_hint\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = or i1 %%1, %%2, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_make_hint  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )(((((signed int )llvm_cbe_a0) > ((signed int )261888u)) | (((signed int )llvm_cbe_a0) < ((signed int )4294705408u)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
  if (llvm_cbe_or_2e_cond) {
    goto llvm_cbe_tmp__17;
  } else {
    goto llvm_cbe_tmp__18;
  }

llvm_cbe_tmp__18:
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond1 = or i1 %%4, %%5, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_make_hint  --> \n", ++aesl_llvm_cbe_or_2e_cond1_count);
  llvm_cbe_or_2e_cond1 = (bool )((((llvm_cbe_a0&4294967295U) != (4294705408u&4294967295U)) | ((llvm_cbe_a1&4294967295U) == (0u&4294967295U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond1 = 0x%X\n", llvm_cbe_or_2e_cond1);
  if (llvm_cbe_or_2e_cond1) {
    llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__19;
  } else {
    goto llvm_cbe_tmp__17;
  }

llvm_cbe_tmp__17:
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe_tmp__19;

llvm_cbe_tmp__19:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ 1, %%6 ], [ 0, %%3  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_make_hint  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_make_hint}\n");
  return llvm_cbe_storemerge;
}


signed int pqcrystals_dilithium3_ref_use_hint(signed int llvm_cbe_a, signed int llvm_cbe_hint) {
  static  unsigned long long aesl_llvm_cbe_a0_count = 0;
  signed int llvm_cbe_a0;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  unsigned int llvm_cbe_tmp__26;
  unsigned int llvm_cbe_tmp__26__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_use_hint\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i32 @pqcrystals_dilithium3_ref_decompose(i32* %%a0, i32 %%a), !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_use_hint  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__20 = (unsigned int )pqcrystals_dilithium3_ref_decompose((signed int *)(&llvm_cbe_a0), llvm_cbe_a);
if (AESL_DEBUG_TRACE) {
printf("\nArgument a = 0x%X",llvm_cbe_a);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__20);
}
  if (((llvm_cbe_hint&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__26__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__20;   /* for PHI node */
    goto llvm_cbe_tmp__27;
  } else {
    goto llvm_cbe_tmp__28;
  }

llvm_cbe_tmp__28:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%a0, align 4, !dbg !5 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_use_hint  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__21 = (unsigned int )*(&llvm_cbe_a0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
  if ((((signed int )llvm_cbe_tmp__21) > ((signed int )0u))) {
    goto llvm_cbe_tmp__29;
  } else {
    goto llvm_cbe_tmp__30;
  }

llvm_cbe_tmp__29:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%1, 1, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_use_hint  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__22 = (unsigned int )((unsigned int )(llvm_cbe_tmp__20&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__22&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = and i32 %%7, 15, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_use_hint  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__23 = (unsigned int )llvm_cbe_tmp__22 & 15u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
  llvm_cbe_tmp__26__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__23;   /* for PHI node */
  goto llvm_cbe_tmp__27;

llvm_cbe_tmp__30:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%1, 15, !dbg !5 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_use_hint  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(llvm_cbe_tmp__20&4294967295ull)) + ((unsigned int )(15u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__24&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = and i32 %%10, 15, !dbg !5 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_use_hint  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__25 = (unsigned int )llvm_cbe_tmp__24 & 15u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
  llvm_cbe_tmp__26__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__25;   /* for PHI node */
  goto llvm_cbe_tmp__27;

llvm_cbe_tmp__27:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = phi i32 [ %%11, %%9 ], [ %%8, %%6 ], [ %%1, %%0  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_use_hint  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__26 = (unsigned int )llvm_cbe_tmp__26__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__26);
printf("\n = 0x%X",llvm_cbe_tmp__25);
printf("\n = 0x%X",llvm_cbe_tmp__23);
printf("\n = 0x%X",llvm_cbe_tmp__20);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_use_hint}\n");
  return llvm_cbe_tmp__26;
}

