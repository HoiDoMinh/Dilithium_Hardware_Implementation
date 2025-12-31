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
void randombytes( char *llvm_cbe_out, signed long long llvm_cbe_outlen);
__declspec(dllimport) signed int CryptAcquireContextA(signed long long *,  char *,  char *, signed int , signed int );
__declspec(dllimport) signed int CryptGenRandom(signed long long , signed int ,  char *);
__declspec(dllimport) signed int CryptReleaseContext(signed long long , signed int );


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

void randombytes( char *llvm_cbe_out, signed long long llvm_cbe_outlen) {
  static  unsigned long long aesl_llvm_cbe_ctx_count = 0;
  signed long long llvm_cbe_ctx;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  unsigned long long llvm_cbe_tmp__2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
   char *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  unsigned long long llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec1_count = 0;
  unsigned long long llvm_cbe__2e_rec1;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @randombytes\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i32 @CryptAcquireContextA(i64* %%ctx, i8* null, i8* null, i32 1, i32 -268435456) nounwind, !dbg !50 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_10_count);
  llvm_cbe_tmp__1 = (unsigned int )CryptAcquireContextA((signed long long *)(&llvm_cbe_ctx), ( char *)(( char *)/*NULL*/0), ( char *)(( char *)/*NULL*/0), 1u, 4026531840u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
printf("\nArgument  = 0x%X",4026531840u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
  if (((llvm_cbe_tmp__1&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__11;
  } else {
    llvm_cbe_tmp__2__PHI_TEMPORARY = (unsigned long long )llvm_cbe_outlen;   /* for PHI node */
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

llvm_cbe_tmp__11:
if (AESL_DEBUG_TRACE)
printf("\n  call void @abort() noreturn nounwind, !dbg !50 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_13_count);
  abort();
if (AESL_DEBUG_TRACE) {
}
  /*UNREACHABLE*/;
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = phi i64 [ %%16, %%15 ], [ %%outlen, %%0  for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__2 = (unsigned long long )llvm_cbe_tmp__2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__2);
printf("\n = 0x%I64X",llvm_cbe_tmp__8);
printf("\noutlen = 0x%I64X",llvm_cbe_outlen);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ %%.rec1, %%15 ], [ 0, %%0  for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n.rec1 = 0x%I64X",llvm_cbe__2e_rec1);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr i8* %%out, i64 %%.re for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__3 = ( char *)(&llvm_cbe_out[(((signed long long )llvm_cbe__2e_rec))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}
  if (((llvm_cbe_tmp__2&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__12;
  } else {
    goto llvm_cbe_tmp__13;
  }

llvm_cbe_tmp__14:
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec1 = add i64 %%.rec, %%9, !dbg !49 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe__2e_rec1_count);
  llvm_cbe__2e_rec1 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__4&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec1 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec1&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sub i64 %%4, %%9, !dbg !50 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__8 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__2&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__4&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__8&18446744073709551615ull)));
  llvm_cbe_tmp__2__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__8;   /* for PHI node */
  llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec1;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

llvm_cbe_tmp__13:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = select i1 %%8, i64 1048576, i64 %%4, !dbg !50 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_20_count);
  llvm_cbe_tmp__4 = (unsigned long long )(((((unsigned long long )llvm_cbe_tmp__2&18446744073709551615ULL) > ((unsigned long long )1048576ull&18446744073709551615ULL))) ? ((unsigned long long )1048576ull) : ((unsigned long long )llvm_cbe_tmp__2));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i64* %%ctx, align 8, !dbg !49 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__5 = (unsigned long long )*(&llvm_cbe_ctx);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = trunc i64 %%9 to i32, !dbg !49 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__6 = (unsigned int )((unsigned int )llvm_cbe_tmp__4&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = call i32 @CryptGenRandom(i64 %%10, i32 %%11, i8* %%5) nounwind, !dbg !49 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__7 = (unsigned int )CryptGenRandom(llvm_cbe_tmp__5, llvm_cbe_tmp__6, ( char *)llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__5);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__6);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__7);
}
  if (((llvm_cbe_tmp__7&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__15;
  } else {
    goto llvm_cbe_tmp__14;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__15:
if (AESL_DEBUG_TRACE)
printf("\n  call void @abort() noreturn nounwind, !dbg !51 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_36_count);
  abort();
if (AESL_DEBUG_TRACE) {
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__12:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i64* %%ctx, align 8, !dbg !51 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__9 = (unsigned long long )*(&llvm_cbe_ctx);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = call i32 @CryptReleaseContext(i64 %%18, i32 0) nounwind, !dbg !51 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__10 = (unsigned int )CryptReleaseContext(llvm_cbe_tmp__9, 0u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__9);
printf("\nArgument  = 0x%X",0u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__10);
}
  if (((llvm_cbe_tmp__10&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__16;
  } else {
    goto llvm_cbe_tmp__17;
  }

llvm_cbe_tmp__16:
if (AESL_DEBUG_TRACE)
printf("\n  call void @abort() noreturn nounwind, !dbg !51 for 0x%I64xth hint within @randombytes  --> \n", ++aesl_llvm_cbe_55_count);
  abort();
if (AESL_DEBUG_TRACE) {
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__17:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @randombytes}\n");
  return;
}

