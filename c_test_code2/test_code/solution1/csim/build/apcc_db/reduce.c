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
signed int pqcrystals_dilithium3_ref_montgomery_reduce(signed long long llvm_cbe_a);
signed int pqcrystals_dilithium3_ref_reduce32(signed int llvm_cbe_a);
signed int pqcrystals_dilithium3_ref_caddq(signed int llvm_cbe_a);
signed int pqcrystals_dilithium3_ref_freeze(signed int llvm_cbe_a);


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

signed int pqcrystals_dilithium3_ref_montgomery_reduce(signed long long llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  unsigned long long llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  unsigned long long llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  unsigned long long llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_montgomery_reduce\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = trunc i64 %%a to i32, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_montgomery_reduce  --> \n", ++aesl_llvm_cbe_3_count);
  llvm_cbe_tmp__1 = (unsigned int )((unsigned int )llvm_cbe_a&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = mul i32 %%1, 58728449, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_montgomery_reduce  --> \n", ++aesl_llvm_cbe_4_count);
  llvm_cbe_tmp__2 = (unsigned int )((unsigned int )(llvm_cbe_tmp__1&4294967295ull)) * ((unsigned int )(58728449u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__2&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%2 to i64, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_montgomery_reduce  --> \n", ++aesl_llvm_cbe_8_count);
  llvm_cbe_tmp__3 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = mul i64 %%3, -8380417, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_montgomery_reduce  --> \n", ++aesl_llvm_cbe_9_count);
  llvm_cbe_tmp__4 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__3&18446744073709551615ull)) * ((unsigned long long )(18446744073701171199ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__4&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add i64 %%4, %%a, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_montgomery_reduce  --> \n", ++aesl_llvm_cbe_10_count);
  llvm_cbe_tmp__5 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__4&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_a&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__5&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = lshr i64 %%5, 32, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_montgomery_reduce  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__6 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__5&18446744073709551615ull)) >> ((unsigned long long )(32ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__6&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = trunc i64 %%6 to i32, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_montgomery_reduce  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__7 = (unsigned int )((unsigned int )llvm_cbe_tmp__6&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__7);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_montgomery_reduce}\n");
  return llvm_cbe_tmp__7;
}


signed int pqcrystals_dilithium3_ref_reduce32(signed int llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_reduce32\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = add nsw i32 %%a, 4194304, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_reduce32  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__8 = (unsigned int )((unsigned int )(llvm_cbe_a&4294967295ull)) + ((unsigned int )(4194304u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__8&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = ashr i32 %%1, 23, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_reduce32  --> \n", ++aesl_llvm_cbe_19_count);
  llvm_cbe_tmp__9 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__8) >> ((signed int )23u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__9));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = mul i32 %%2, -8380417, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_reduce32  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(llvm_cbe_tmp__9&4294967295ull)) * ((unsigned int )(4286586879u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__10&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add i32 %%3, %%a, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_reduce32  --> \n", ++aesl_llvm_cbe_24_count);
  llvm_cbe_tmp__11 = (unsigned int )((unsigned int )(llvm_cbe_tmp__10&4294967295ull)) + ((unsigned int )(llvm_cbe_a&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__11&4294967295ull)));
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_reduce32}\n");
  return llvm_cbe_tmp__11;
}


signed int pqcrystals_dilithium3_ref_caddq(signed int llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_caddq\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = ashr i32 %%a, 31, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_caddq  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__12 = (unsigned int )((signed int )(((signed int )llvm_cbe_a) >> ((signed int )31u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__12));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = and i32 %%1, 8380417, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_caddq  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__13 = (unsigned int )llvm_cbe_tmp__12 & 8380417u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add nsw i32 %%2, %%a, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_caddq  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__14 = (unsigned int )((unsigned int )(llvm_cbe_tmp__13&4294967295ull)) + ((unsigned int )(llvm_cbe_a&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__14&4294967295ull)));
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_caddq}\n");
  return llvm_cbe_tmp__14;
}


signed int pqcrystals_dilithium3_ref_freeze(signed int llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_freeze\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call i32 @pqcrystals_dilithium3_ref_reduce32(i32 %%a), !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_freeze  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__15 = (unsigned int ) /*tail*/ pqcrystals_dilithium3_ref_reduce32(llvm_cbe_a);
if (AESL_DEBUG_TRACE) {
printf("\nArgument a = 0x%X",llvm_cbe_a);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__15);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call i32 @pqcrystals_dilithium3_ref_caddq(i32 %%1), !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_freeze  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__16 = (unsigned int ) /*tail*/ pqcrystals_dilithium3_ref_caddq(llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__15);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__16);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_freeze}\n");
  return llvm_cbe_tmp__16;
}

