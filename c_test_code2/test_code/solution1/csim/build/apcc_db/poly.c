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
typedef struct l_struct_OC_poly l_struct_OC_poly;
typedef struct l_struct_OC_keccak_state l_struct_OC_keccak_state;

/* Structure contents */
struct l_struct_OC_poly {
  signed int field0[256];
};

struct l_struct_OC_keccak_state {
  signed long long field0[25];
  unsigned int field1;
};


/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void pqcrystals_dilithium3_ref_poly_reduce(l_struct_OC_poly *llvm_cbe_a);
signed int pqcrystals_dilithium3_ref_reduce32(signed int );
void pqcrystals_dilithium3_ref_poly_caddq(l_struct_OC_poly *llvm_cbe_a);
signed int pqcrystals_dilithium3_ref_caddq(signed int );
void pqcrystals_dilithium3_ref_poly_add(l_struct_OC_poly *llvm_cbe_c, l_struct_OC_poly *llvm_cbe_a, l_struct_OC_poly *llvm_cbe_b);
void pqcrystals_dilithium3_ref_poly_sub(l_struct_OC_poly *llvm_cbe_c, l_struct_OC_poly *llvm_cbe_a, l_struct_OC_poly *llvm_cbe_b);
void pqcrystals_dilithium3_ref_poly_shiftl(l_struct_OC_poly *llvm_cbe_a);
void pqcrystals_dilithium3_ref_poly_ntt(l_struct_OC_poly *llvm_cbe_a);
void pqcrystals_dilithium3_ref_ntt(signed int *);
void pqcrystals_dilithium3_ref_poly_invntt_tomont(l_struct_OC_poly *llvm_cbe_a);
void pqcrystals_dilithium3_ref_invntt_tomont(signed int *);
void pqcrystals_dilithium3_ref_poly_pointwise_montgomery(l_struct_OC_poly *llvm_cbe_c, l_struct_OC_poly *llvm_cbe_a, l_struct_OC_poly *llvm_cbe_b);
signed int pqcrystals_dilithium3_ref_montgomery_reduce(signed long long );
void pqcrystals_dilithium3_ref_poly_power2round(l_struct_OC_poly *llvm_cbe_a1, l_struct_OC_poly *llvm_cbe_a0, l_struct_OC_poly *llvm_cbe_a);
signed int pqcrystals_dilithium3_ref_power2round(signed int *, signed int );
void pqcrystals_dilithium3_ref_poly_decompose(l_struct_OC_poly *llvm_cbe_a1, l_struct_OC_poly *llvm_cbe_a0, l_struct_OC_poly *llvm_cbe_a);
signed int pqcrystals_dilithium3_ref_decompose(signed int *, signed int );
signed int pqcrystals_dilithium3_ref_poly_make_hint(l_struct_OC_poly *llvm_cbe_h, l_struct_OC_poly *llvm_cbe_a0, l_struct_OC_poly *llvm_cbe_a1);
signed int pqcrystals_dilithium3_ref_make_hint(signed int , signed int );
void pqcrystals_dilithium3_ref_poly_use_hint(l_struct_OC_poly *llvm_cbe_b, l_struct_OC_poly *llvm_cbe_a, l_struct_OC_poly *llvm_cbe_h);
signed int pqcrystals_dilithium3_ref_use_hint(signed int , signed int );
signed int pqcrystals_dilithium3_ref_poly_chknorm(l_struct_OC_poly *llvm_cbe_a, signed int llvm_cbe_B);
void pqcrystals_dilithium3_ref_poly_uniform(l_struct_OC_poly *llvm_cbe_a,  char *llvm_cbe_seed, signed short llvm_cbe_nonce);
void pqcrystals_dilithium3_ref_dilithium_shake128_stream_init(l_struct_OC_keccak_state *,  char *, signed short );
void pqcrystals_dilithium_fips202_ref_shake128_squeezeblocks( char *, signed long long , l_struct_OC_keccak_state *);
static signed int aesl_internal_rej_uniform(signed int *llvm_cbe_a, signed int llvm_cbe_len,  char *llvm_cbe_buf, signed int llvm_cbe_buflen);
void pqcrystals_dilithium3_ref_poly_uniform_eta(l_struct_OC_poly *llvm_cbe_a,  char *llvm_cbe_seed, signed short llvm_cbe_nonce);
void pqcrystals_dilithium3_ref_dilithium_shake256_stream_init(l_struct_OC_keccak_state *,  char *, signed short );
void pqcrystals_dilithium_fips202_ref_shake256_squeezeblocks( char *, signed long long , l_struct_OC_keccak_state *);
static signed int aesl_internal_rej_eta(signed int *llvm_cbe_a, signed int llvm_cbe_len,  char *llvm_cbe_buf, signed int llvm_cbe_buflen);
void pqcrystals_dilithium3_ref_poly_uniform_gamma1(l_struct_OC_poly *llvm_cbe_a,  char *llvm_cbe_seed, signed short llvm_cbe_nonce);
void pqcrystals_dilithium3_ref_polyz_unpack(l_struct_OC_poly *llvm_cbe_r,  char *llvm_cbe_a);
void pqcrystals_dilithium3_ref_poly_challenge(l_struct_OC_poly *llvm_cbe_c,  char *llvm_cbe_seed);
void pqcrystals_dilithium_fips202_ref_shake256_init(l_struct_OC_keccak_state *);
void pqcrystals_dilithium_fips202_ref_shake256_absorb(l_struct_OC_keccak_state *,  char *, signed long long );
void pqcrystals_dilithium_fips202_ref_shake256_finalize(l_struct_OC_keccak_state *);
void pqcrystals_dilithium3_ref_polyeta_pack( char *llvm_cbe_r, l_struct_OC_poly *llvm_cbe_a);
void pqcrystals_dilithium3_ref_polyeta_unpack(l_struct_OC_poly *llvm_cbe_r,  char *llvm_cbe_a);
void pqcrystals_dilithium3_ref_polyt1_pack( char *llvm_cbe_r, l_struct_OC_poly *llvm_cbe_a);
void pqcrystals_dilithium3_ref_polyt1_unpack(l_struct_OC_poly *llvm_cbe_r,  char *llvm_cbe_a);
void pqcrystals_dilithium3_ref_polyt0_pack( char *llvm_cbe_r, l_struct_OC_poly *llvm_cbe_a);
void pqcrystals_dilithium3_ref_polyt0_unpack(l_struct_OC_poly *llvm_cbe_r,  char *llvm_cbe_a);
void pqcrystals_dilithium3_ref_polyz_pack( char *llvm_cbe_r, l_struct_OC_poly *llvm_cbe_a);
void pqcrystals_dilithium3_ref_polyw1_pack( char *llvm_cbe_r, l_struct_OC_poly *llvm_cbe_a);


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

void pqcrystals_dilithium3_ref_poly_reduce(l_struct_OC_poly *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  unsigned long long llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  signed int *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_reduce\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__6;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%6, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_reduce  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_reduce  --> \n", ++aesl_llvm_cbe_10_count);
  llvm_cbe_tmp__1 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_reduce  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__2 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__1))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_reduce  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__3 = (unsigned int )*llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i32 @pqcrystals_dilithium3_ref_reduce32(i32 %%4) nounwind, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_reduce  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__4 = (unsigned int ) /*tail*/ pqcrystals_dilithium3_ref_reduce32(llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__3);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__4);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%5, i32* %%3, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_reduce  --> \n", ++aesl_llvm_cbe_14_count);
  *llvm_cbe_tmp__2 = llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i32 %%storemerge1, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_reduce  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__5 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__5&4294967295ull)));
  if (((llvm_cbe_tmp__5&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__7;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__5;   /* for PHI node */
    goto llvm_cbe_tmp__6;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__7:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_reduce}\n");
  return;
}


void pqcrystals_dilithium3_ref_poly_caddq(l_struct_OC_poly *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  signed int *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_caddq\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__13;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__13:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%6, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_caddq  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_caddq  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__8 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_caddq  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__9 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__8))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_caddq  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__10 = (unsigned int )*llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i32 @pqcrystals_dilithium3_ref_caddq(i32 %%4) nounwind, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_caddq  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__11 = (unsigned int ) /*tail*/ pqcrystals_dilithium3_ref_caddq(llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__10);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__11);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%5, i32* %%3, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_caddq  --> \n", ++aesl_llvm_cbe_36_count);
  *llvm_cbe_tmp__9 = llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i32 %%storemerge1, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_caddq  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__12 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__12&4294967295ull)));
  if (((llvm_cbe_tmp__12&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__14;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__12;   /* for PHI node */
    goto llvm_cbe_tmp__13;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__14:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_caddq}\n");
  return;
}


void pqcrystals_dilithium3_ref_poly_add(l_struct_OC_poly *llvm_cbe_c, l_struct_OC_poly *llvm_cbe_a, l_struct_OC_poly *llvm_cbe_b) {
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  unsigned long long llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  signed int *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  signed int *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  signed int *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_add\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__23;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__23:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%9, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_add  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__22);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_add  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__15 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_add  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__16 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__15))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__15));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_add  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__17 = (unsigned int )*llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.poly* %%b, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_add  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__18 = (signed int *)(&llvm_cbe_b->field0[(((signed long long )llvm_cbe_tmp__15))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__15));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* %%5, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_add  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__19 = (unsigned int )*llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%6, %%4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_add  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__20 = (unsigned int )((unsigned int )(llvm_cbe_tmp__19&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__17&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__20&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.poly* %%c, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_add  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__21 = (signed int *)(&llvm_cbe_c->field0[(((signed long long )llvm_cbe_tmp__15))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__15));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%7, i32* %%8, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_add  --> \n", ++aesl_llvm_cbe_65_count);
  *llvm_cbe_tmp__21 = llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i32 %%storemerge1, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_add  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__22 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__22&4294967295ull)));
  if (((llvm_cbe_tmp__22&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__24;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__22;   /* for PHI node */
    goto llvm_cbe_tmp__23;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__24:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_add}\n");
  return;
}


void pqcrystals_dilithium3_ref_poly_sub(l_struct_OC_poly *llvm_cbe_c, l_struct_OC_poly *llvm_cbe_a, l_struct_OC_poly *llvm_cbe_b) {
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  unsigned long long llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  signed int *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  signed int *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  signed int *llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_sub\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__33;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__33:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%9, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_sub  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__32);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_sub  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__25 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_sub  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__26 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__25))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__25));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_sub  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__27 = (unsigned int )*llvm_cbe_tmp__26;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.poly* %%b, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_sub  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__28 = (signed int *)(&llvm_cbe_b->field0[(((signed long long )llvm_cbe_tmp__25))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__25));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* %%5, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_sub  --> \n", ++aesl_llvm_cbe_92_count);
  llvm_cbe_tmp__29 = (unsigned int )*llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sub nsw i32 %%4, %%6, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_sub  --> \n", ++aesl_llvm_cbe_93_count);
  llvm_cbe_tmp__30 = (unsigned int )((unsigned int )(llvm_cbe_tmp__27&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__29&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__30&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.poly* %%c, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_sub  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__31 = (signed int *)(&llvm_cbe_c->field0[(((signed long long )llvm_cbe_tmp__25))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__25));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%7, i32* %%8, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_sub  --> \n", ++aesl_llvm_cbe_95_count);
  *llvm_cbe_tmp__31 = llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i32 %%storemerge1, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_sub  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__32 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__32&4294967295ull)));
  if (((llvm_cbe_tmp__32&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__34;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__32;   /* for PHI node */
    goto llvm_cbe_tmp__33;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__34:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_sub}\n");
  return;
}


void pqcrystals_dilithium3_ref_poly_shiftl(l_struct_OC_poly *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  unsigned long long llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  signed int *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  unsigned int llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_shiftl\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__40;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__40:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%6, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_shiftl  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_shiftl  --> \n", ++aesl_llvm_cbe_112_count);
  llvm_cbe_tmp__35 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_shiftl  --> \n", ++aesl_llvm_cbe_113_count);
  llvm_cbe_tmp__36 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__35))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__35));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_shiftl  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__37 = (unsigned int )*llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = shl i32 %%4, 13, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_shiftl  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__38 = (unsigned int )llvm_cbe_tmp__37 << 13u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%5, i32* %%3, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_shiftl  --> \n", ++aesl_llvm_cbe_116_count);
  *llvm_cbe_tmp__36 = llvm_cbe_tmp__38;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i32 %%storemerge1, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_shiftl  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__39 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__39&4294967295ull)));
  if (((llvm_cbe_tmp__39&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__41;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__39;   /* for PHI node */
    goto llvm_cbe_tmp__40;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__41:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_shiftl}\n");
  return;
}


void pqcrystals_dilithium3_ref_poly_ntt(l_struct_OC_poly *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  signed int *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_ntt\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 0, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_ntt  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__42 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_ntt(i32* %%1) nounwind, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_ntt  --> \n", ++aesl_llvm_cbe_127_count);
   /*tail*/ pqcrystals_dilithium3_ref_ntt((signed int *)llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_ntt}\n");
  return;
}


void pqcrystals_dilithium3_ref_poly_invntt_tomont(l_struct_OC_poly *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  signed int *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_invntt_tomont\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 0, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_invntt_tomont  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__43 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_invntt_tomont(i32* %%1) nounwind, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_invntt_tomont  --> \n", ++aesl_llvm_cbe_132_count);
   /*tail*/ pqcrystals_dilithium3_ref_invntt_tomont((signed int *)llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_invntt_tomont}\n");
  return;
}


void pqcrystals_dilithium3_ref_poly_pointwise_montgomery(l_struct_OC_poly *llvm_cbe_c, l_struct_OC_poly *llvm_cbe_a, l_struct_OC_poly *llvm_cbe_b) {
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  unsigned long long llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  signed int *llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  unsigned long long llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  signed int *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  unsigned int llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  unsigned long long llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  unsigned long long llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  unsigned int llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  signed int *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_pointwise_montgomery\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__55;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__55:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%12, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_pointwise_montgomery  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__54);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_pointwise_montgomery  --> \n", ++aesl_llvm_cbe_147_count);
  llvm_cbe_tmp__44 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_pointwise_montgomery  --> \n", ++aesl_llvm_cbe_148_count);
  llvm_cbe_tmp__45 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__44))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__44));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_pointwise_montgomery  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__46 = (unsigned int )*llvm_cbe_tmp__45;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sext i32 %%4 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_pointwise_montgomery  --> \n", ++aesl_llvm_cbe_150_count);
  llvm_cbe_tmp__47 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.poly* %%b, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_pointwise_montgomery  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__48 = (signed int *)(&llvm_cbe_b->field0[(((signed long long )llvm_cbe_tmp__44))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__44));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i32* %%6, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_pointwise_montgomery  --> \n", ++aesl_llvm_cbe_152_count);
  llvm_cbe_tmp__49 = (unsigned int )*llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sext i32 %%7 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_pointwise_montgomery  --> \n", ++aesl_llvm_cbe_153_count);
  llvm_cbe_tmp__50 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i64 %%8, %%5, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_pointwise_montgomery  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__51 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__50&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__47&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__51&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call i32 @pqcrystals_dilithium3_ref_montgomery_reduce(i64 %%9) nounwind, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_pointwise_montgomery  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__52 = (unsigned int ) /*tail*/ pqcrystals_dilithium3_ref_montgomery_reduce(llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__51);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__52);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.poly* %%c, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_pointwise_montgomery  --> \n", ++aesl_llvm_cbe_156_count);
  llvm_cbe_tmp__53 = (signed int *)(&llvm_cbe_c->field0[(((signed long long )llvm_cbe_tmp__44))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__44));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%10, i32* %%11, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_pointwise_montgomery  --> \n", ++aesl_llvm_cbe_157_count);
  *llvm_cbe_tmp__53 = llvm_cbe_tmp__52;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i32 %%storemerge1, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_pointwise_montgomery  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__54 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__54&4294967295ull)));
  if (((llvm_cbe_tmp__54&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__56;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__54;   /* for PHI node */
    goto llvm_cbe_tmp__55;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__56:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_pointwise_montgomery}\n");
  return;
}


void pqcrystals_dilithium3_ref_poly_power2round(l_struct_OC_poly *llvm_cbe_a1, l_struct_OC_poly *llvm_cbe_a0, l_struct_OC_poly *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  unsigned long long llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  signed int *llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  signed int *llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  unsigned int llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  unsigned int llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  signed int *llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_power2round\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__64;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__64:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%8, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_power2round  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__63);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_power2round  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__57 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.poly* %%a0, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_power2round  --> \n", ++aesl_llvm_cbe_181_count);
  llvm_cbe_tmp__58 = (signed int *)(&llvm_cbe_a0->field0[(((signed long long )llvm_cbe_tmp__57))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__57));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_power2round  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__59 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__57))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__57));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%4, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_power2round  --> \n", ++aesl_llvm_cbe_183_count);
  llvm_cbe_tmp__60 = (unsigned int )*llvm_cbe_tmp__59;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = tail call i32 @pqcrystals_dilithium3_ref_power2round(i32* %%3, i32 %%5) nounwind, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_power2round  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__61 = (unsigned int ) /*tail*/ pqcrystals_dilithium3_ref_power2round((signed int *)llvm_cbe_tmp__58, llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__60);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__61);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.poly* %%a1, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_power2round  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__62 = (signed int *)(&llvm_cbe_a1->field0[(((signed long long )llvm_cbe_tmp__57))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__57));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%6, i32* %%7, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_power2round  --> \n", ++aesl_llvm_cbe_186_count);
  *llvm_cbe_tmp__62 = llvm_cbe_tmp__61;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i32 %%storemerge1, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_power2round  --> \n", ++aesl_llvm_cbe_187_count);
  llvm_cbe_tmp__63 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__63&4294967295ull)));
  if (((llvm_cbe_tmp__63&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__65;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__63;   /* for PHI node */
    goto llvm_cbe_tmp__64;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__65:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_power2round}\n");
  return;
}


void pqcrystals_dilithium3_ref_poly_decompose(l_struct_OC_poly *llvm_cbe_a1, l_struct_OC_poly *llvm_cbe_a0, l_struct_OC_poly *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  unsigned long long llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  signed int *llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  signed int *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  unsigned int llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  signed int *llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  unsigned int llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_decompose\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__73;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__73:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%8, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_decompose  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__72);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_decompose  --> \n", ++aesl_llvm_cbe_209_count);
  llvm_cbe_tmp__66 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.poly* %%a0, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_decompose  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__67 = (signed int *)(&llvm_cbe_a0->field0[(((signed long long )llvm_cbe_tmp__66))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_decompose  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__68 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__66))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%4, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_decompose  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__69 = (unsigned int )*llvm_cbe_tmp__68;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = tail call i32 @pqcrystals_dilithium3_ref_decompose(i32* %%3, i32 %%5) nounwind, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_decompose  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__70 = (unsigned int ) /*tail*/ pqcrystals_dilithium3_ref_decompose((signed int *)llvm_cbe_tmp__67, llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__69);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__70);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.poly* %%a1, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_decompose  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__71 = (signed int *)(&llvm_cbe_a1->field0[(((signed long long )llvm_cbe_tmp__66))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%6, i32* %%7, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_decompose  --> \n", ++aesl_llvm_cbe_215_count);
  *llvm_cbe_tmp__71 = llvm_cbe_tmp__70;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i32 %%storemerge1, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_decompose  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__72 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__72&4294967295ull)));
  if (((llvm_cbe_tmp__72&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__74;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__72;   /* for PHI node */
    goto llvm_cbe_tmp__73;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__74:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_decompose}\n");
  return;
}


signed int pqcrystals_dilithium3_ref_poly_make_hint(l_struct_OC_poly *llvm_cbe_h, l_struct_OC_poly *llvm_cbe_a0, l_struct_OC_poly *llvm_cbe_a1) {
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  unsigned int llvm_cbe_tmp__75;
  unsigned int llvm_cbe_tmp__75__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  unsigned long long llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  signed int *llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  unsigned int llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  signed int *llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  unsigned int llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  unsigned int llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  signed int *llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  unsigned int llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  unsigned int llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_make_hint\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__75__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__85;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__85:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%11, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_make_hint  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__84);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = phi i32 [ 0, %%0 ], [ %%10, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_make_hint  --> \n", ++aesl_llvm_cbe_243_count);
  llvm_cbe_tmp__75 = (unsigned int )llvm_cbe_tmp__75__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__75);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__83);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_make_hint  --> \n", ++aesl_llvm_cbe_244_count);
  llvm_cbe_tmp__76 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.poly* %%a0, i64 0, i32 0, i64 %%3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_make_hint  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__77 = (signed int *)(&llvm_cbe_a0->field0[(((signed long long )llvm_cbe_tmp__76))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__76));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%4, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_make_hint  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__78 = (unsigned int )*llvm_cbe_tmp__77;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.poly* %%a1, i64 0, i32 0, i64 %%3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_make_hint  --> \n", ++aesl_llvm_cbe_247_count);
  llvm_cbe_tmp__79 = (signed int *)(&llvm_cbe_a1->field0[(((signed long long )llvm_cbe_tmp__76))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__76));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i32* %%6, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_make_hint  --> \n", ++aesl_llvm_cbe_248_count);
  llvm_cbe_tmp__80 = (unsigned int )*llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = tail call i32 @pqcrystals_dilithium3_ref_make_hint(i32 %%5, i32 %%7) nounwind, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_make_hint  --> \n", ++aesl_llvm_cbe_249_count);
  llvm_cbe_tmp__81 = (unsigned int ) /*tail*/ pqcrystals_dilithium3_ref_make_hint(llvm_cbe_tmp__78, llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__78);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__80);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__81);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.poly* %%h, i64 0, i32 0, i64 %%3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_make_hint  --> \n", ++aesl_llvm_cbe_250_count);
  llvm_cbe_tmp__82 = (signed int *)(&llvm_cbe_h->field0[(((signed long long )llvm_cbe_tmp__76))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__76));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%8, i32* %%9, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_make_hint  --> \n", ++aesl_llvm_cbe_251_count);
  *llvm_cbe_tmp__82 = llvm_cbe_tmp__81;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i32 %%8, %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_make_hint  --> \n", ++aesl_llvm_cbe_252_count);
  llvm_cbe_tmp__83 = (unsigned int )((unsigned int )(llvm_cbe_tmp__81&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__75&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__83&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i32 %%storemerge1, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_make_hint  --> \n", ++aesl_llvm_cbe_256_count);
  llvm_cbe_tmp__84 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__84&4294967295ull)));
  if (((llvm_cbe_tmp__84&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__86;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__84;   /* for PHI node */
    llvm_cbe_tmp__75__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__83;   /* for PHI node */
    goto llvm_cbe_tmp__85;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__86:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_make_hint}\n");
  return llvm_cbe_tmp__83;
}


void pqcrystals_dilithium3_ref_poly_use_hint(l_struct_OC_poly *llvm_cbe_b, l_struct_OC_poly *llvm_cbe_a, l_struct_OC_poly *llvm_cbe_h) {
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  unsigned long long llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  signed int *llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  unsigned int llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  signed int *llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  unsigned int llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  unsigned int llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  signed int *llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  unsigned int llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_use_hint\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__95;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__95:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%9, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_use_hint  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__94);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_use_hint  --> \n", ++aesl_llvm_cbe_279_count);
  llvm_cbe_tmp__87 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_use_hint  --> \n", ++aesl_llvm_cbe_280_count);
  llvm_cbe_tmp__88 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__87))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__87));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%3, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_use_hint  --> \n", ++aesl_llvm_cbe_281_count);
  llvm_cbe_tmp__89 = (unsigned int )*llvm_cbe_tmp__88;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.poly* %%h, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_use_hint  --> \n", ++aesl_llvm_cbe_282_count);
  llvm_cbe_tmp__90 = (signed int *)(&llvm_cbe_h->field0[(((signed long long )llvm_cbe_tmp__87))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__87));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* %%5, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_use_hint  --> \n", ++aesl_llvm_cbe_283_count);
  llvm_cbe_tmp__91 = (unsigned int )*llvm_cbe_tmp__90;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__91);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call i32 @pqcrystals_dilithium3_ref_use_hint(i32 %%4, i32 %%6) nounwind, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_use_hint  --> \n", ++aesl_llvm_cbe_284_count);
  llvm_cbe_tmp__92 = (unsigned int ) /*tail*/ pqcrystals_dilithium3_ref_use_hint(llvm_cbe_tmp__89, llvm_cbe_tmp__91);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__89);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__91);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__92);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.poly* %%b, i64 0, i32 0, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_use_hint  --> \n", ++aesl_llvm_cbe_285_count);
  llvm_cbe_tmp__93 = (signed int *)(&llvm_cbe_b->field0[(((signed long long )llvm_cbe_tmp__87))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__87));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%7, i32* %%8, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_use_hint  --> \n", ++aesl_llvm_cbe_286_count);
  *llvm_cbe_tmp__93 = llvm_cbe_tmp__92;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__92);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i32 %%storemerge1, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_use_hint  --> \n", ++aesl_llvm_cbe_287_count);
  llvm_cbe_tmp__94 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__94&4294967295ull)));
  if (((llvm_cbe_tmp__94&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__96;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__94;   /* for PHI node */
    goto llvm_cbe_tmp__95;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__96:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_use_hint}\n");
  return;
}


signed int pqcrystals_dilithium3_ref_poly_chknorm(l_struct_OC_poly *llvm_cbe_a, signed int llvm_cbe_B) {
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  unsigned long long llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  signed int *llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  unsigned int llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  unsigned int llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  unsigned int llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  unsigned int llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  unsigned int llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  unsigned int llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  unsigned int llvm_cbe_tmp__105;
  unsigned int llvm_cbe_tmp__105__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_chknorm\n");
  if ((((signed int )llvm_cbe_B) > ((signed int )1047552u))) {
    llvm_cbe_tmp__105__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ %%12, %%3 ], [ 0, %%0  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_chknorm  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",llvm_cbe_tmp__104);
printf("\n = 0x%X",0u);
}
  if ((((unsigned int )llvm_cbe_storemerge&4294967295U) < ((unsigned int )256u&4294967295U))) {
    goto llvm_cbe_tmp__106;
  } else {
    llvm_cbe_tmp__105__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

llvm_cbe_tmp__106:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i32 %%storemerge to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_chknorm  --> \n", ++aesl_llvm_cbe_312_count);
  llvm_cbe_tmp__97 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__97);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_chknorm  --> \n", ++aesl_llvm_cbe_313_count);
  llvm_cbe_tmp__98 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__97))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__97));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* %%5, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_chknorm  --> \n", ++aesl_llvm_cbe_314_count);
  llvm_cbe_tmp__99 = (unsigned int )*llvm_cbe_tmp__98;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = ashr i32 %%6, 31, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_chknorm  --> \n", ++aesl_llvm_cbe_315_count);
  llvm_cbe_tmp__100 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__99) >> ((signed int )31u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__100));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = shl nsw i32 %%6, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_chknorm  --> \n", ++aesl_llvm_cbe_318_count);
  llvm_cbe_tmp__101 = (unsigned int )llvm_cbe_tmp__99 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = and i32 %%7, %%8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_chknorm  --> \n", ++aesl_llvm_cbe_319_count);
  llvm_cbe_tmp__102 = (unsigned int )llvm_cbe_tmp__100 & llvm_cbe_tmp__101;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sub nsw i32 %%6, %%9, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_chknorm  --> \n", ++aesl_llvm_cbe_320_count);
  llvm_cbe_tmp__103 = (unsigned int )((unsigned int )(llvm_cbe_tmp__99&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__102&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__103&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i32 %%storemerge, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_chknorm  --> \n", ++aesl_llvm_cbe_324_count);
  llvm_cbe_tmp__104 = (unsigned int )((unsigned int )(llvm_cbe_storemerge&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__104&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__103) < ((signed int )llvm_cbe_B))) {
    llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__104;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_tmp__105__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = phi i32 [ 1, %%0 ], [ 0, %%.preheader ], [ 1, %%3  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_chknorm  --> \n", ++aesl_llvm_cbe_327_count);
  llvm_cbe_tmp__105 = (unsigned int )llvm_cbe_tmp__105__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__105);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",1u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_chknorm}\n");
  return llvm_cbe_tmp__105;
}


void pqcrystals_dilithium3_ref_poly_uniform(l_struct_OC_poly *llvm_cbe_a,  char *llvm_cbe_seed, signed short llvm_cbe_nonce) {
  static  unsigned long long aesl_llvm_cbe_buf_count = 0;
   char llvm_cbe_buf[842];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_state_count = 0;
  l_struct_OC_keccak_state llvm_cbe_state;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
   char *llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  signed int *llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  unsigned int llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  unsigned int llvm_cbe_tmp__110;
  unsigned int llvm_cbe_tmp__110__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  unsigned int llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  unsigned int llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  unsigned int llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  unsigned long long llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
   char *llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  unsigned char llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  unsigned long long llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
   char *llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  unsigned int llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  unsigned long long llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
   char *llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  unsigned int llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  unsigned long long llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  signed int *llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  unsigned int llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  unsigned int llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  unsigned int llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_uniform\n");
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_dilithium_shake128_stream_init(%%struct.keccak_state* %%state, i8* %%seed, i16 zeroext %%nonce) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_343_count);
  pqcrystals_dilithium3_ref_dilithium_shake128_stream_init((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_seed, llvm_cbe_nonce);
if (AESL_DEBUG_TRACE) {
printf("\nArgument nonce = 0x%X",llvm_cbe_nonce);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [842 x i8]* %%buf, i64 0, i64 0, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_344_count);
  llvm_cbe_tmp__107 = ( char *)(&llvm_cbe_buf[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 842
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake128_squeezeblocks(i8* %%1, i64 5, %%struct.keccak_state* %%state) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_345_count);
  pqcrystals_dilithium_fips202_ref_shake128_squeezeblocks(( char *)llvm_cbe_tmp__107, 5ull, (l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",5ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 0, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_346_count);
  llvm_cbe_tmp__108 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call fastcc i32 @aesl_internal_rej_uniform(i32* %%2, i32 256, i8* %%1, i32 840), !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_347_count);
  llvm_cbe_tmp__109 = (unsigned int )aesl_internal_rej_uniform((signed int *)llvm_cbe_tmp__108, 256u, ( char *)llvm_cbe_tmp__107, 840u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",256u);
printf("\nArgument  = 0x%X",840u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__109);
}
  if ((((unsigned int )llvm_cbe_tmp__109&4294967295U) < ((unsigned int )256u&4294967295U))) {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__109;   /* for PHI node */
    llvm_cbe_tmp__110__PHI_TEMPORARY = (unsigned int )840u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  } else {
    goto llvm_cbe__2e__crit_edge6;
  }

  do {     /* Syntactic loop '.lr.ph5' to make GCC happy */
llvm_cbe__2e_lr_2e_ph5:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ %%24, %%._crit_edge ], [ %%3, %%0  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",llvm_cbe_tmp__127);
printf("\n = 0x%X",llvm_cbe_tmp__109);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = phi i32 [ %%19, %%._crit_edge ], [ 840, %%0  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_355_count);
  llvm_cbe_tmp__110 = (unsigned int )llvm_cbe_tmp__110__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__110);
printf("\n = 0x%X",llvm_cbe_tmp__122);
printf("\n = 0x%X",840u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = urem i32 %%5, 3, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_356_count);
  llvm_cbe_tmp__111 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__110&4294967295ull)) % ((unsigned int )(3u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__111&4294967295ull)));
  if (((llvm_cbe_tmp__111&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = zext i32 %%6 to i64, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_385_count);
  llvm_cbe_tmp__120 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__111&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__120);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds [842 x i8]* %%buf, i64 0, i64 %%17, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_386_count);
  llvm_cbe_tmp__121 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__120))
#ifdef AESL_BC_SIM
 % 842
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__120));
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake128_squeezeblocks(i8* %%18, i64 1, %%struct.keccak_state* %%state) nounwind, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_387_count);
  pqcrystals_dilithium_fips202_ref_shake128_squeezeblocks(( char *)llvm_cbe_tmp__121, 1ull, (l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = or i32 %%6, 168, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_388_count);
  llvm_cbe_tmp__122 = (unsigned int )llvm_cbe_tmp__111 | 168u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = zext i32 %%storemerge3 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_394_count);
  llvm_cbe_tmp__123 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge3&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%20, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_395_count);
  llvm_cbe_tmp__124 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__123))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__123));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = sub i32 256, %%storemerge3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_396_count);
  llvm_cbe_tmp__125 = (unsigned int )((unsigned int )(256u&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge3&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__125&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = call fastcc i32 @aesl_internal_rej_uniform(i32* %%21, i32 %%22, i8* %%1, i32 %%19), !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_397_count);
  llvm_cbe_tmp__126 = (unsigned int )aesl_internal_rej_uniform((signed int *)llvm_cbe_tmp__124, llvm_cbe_tmp__125, ( char *)llvm_cbe_tmp__107, llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__125);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__122);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__126);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i32 %%23, %%storemerge3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_398_count);
  llvm_cbe_tmp__127 = (unsigned int )((unsigned int )(llvm_cbe_tmp__126&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge3&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__127&4294967295ull)));
  if ((((unsigned int )llvm_cbe_tmp__127&4294967295U) < ((unsigned int )256u&4294967295U))) {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__127;   /* for PHI node */
    llvm_cbe_tmp__110__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__122;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph5;
  } else {
    goto llvm_cbe__2e__crit_edge6;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__128:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ 0, %%.lr.ph ], [ %%16, %%9  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__119);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i32 %%8, %%storemerge12, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_371_count);
  llvm_cbe_tmp__113 = (unsigned int )((unsigned int )(llvm_cbe_tmp__112&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge12&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__113&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i32 %%10 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_372_count);
  llvm_cbe_tmp__114 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__113&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__114);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [842 x i8]* %%buf, i64 0, i64 %%11, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_373_count);
  llvm_cbe_tmp__115 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__114))
#ifdef AESL_BC_SIM
 % 842
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__114));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__114) < 842)) fprintf(stderr, "%s:%d: warning: Read access out of array 'buf' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i8* %%12, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_374_count);
  llvm_cbe_tmp__116 = (unsigned char )*llvm_cbe_tmp__115;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__116);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i32 %%storemerge12 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_375_count);
  llvm_cbe_tmp__117 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge12&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__117);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [842 x i8]* %%buf, i64 0, i64 %%14, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_376_count);
  llvm_cbe_tmp__118 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__117))
#ifdef AESL_BC_SIM
 % 842
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__117));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__117) < 842 && "Write access out of array 'buf' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%13, i8* %%15, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_377_count);
  *llvm_cbe_tmp__118 = llvm_cbe_tmp__116;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__116);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i32 %%storemerge12, 1, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_378_count);
  llvm_cbe_tmp__119 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__119&4294967295ull)));
  if (((llvm_cbe_tmp__119&4294967295U) == (llvm_cbe_tmp__111&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__119;   /* for PHI node */
    goto llvm_cbe_tmp__128;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sub i32 %%5, %%6, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform  --> \n", ++aesl_llvm_cbe_369_count);
  llvm_cbe_tmp__112 = (unsigned int )((unsigned int )(llvm_cbe_tmp__110&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__111&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__112&4294967295ull)));
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__128;

  } while (1); /* end of syntactic loop '.lr.ph5' */
llvm_cbe__2e__crit_edge6:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_uniform}\n");
  return;
}


static signed int aesl_internal_rej_uniform(signed int *llvm_cbe_a, signed int llvm_cbe_len,  char *llvm_cbe_buf, signed int llvm_cbe_buflen) {
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  unsigned int llvm_cbe_tmp__129;
  unsigned int llvm_cbe_tmp__129__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  unsigned int llvm_cbe_tmp__130;
  unsigned int llvm_cbe_tmp__130__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  unsigned int llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  unsigned int llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  unsigned long long llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
   char *llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  unsigned char llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  unsigned int llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  unsigned int llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  unsigned long long llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
   char *llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  unsigned char llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  unsigned int llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  unsigned int llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  unsigned long long llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
   char *llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  unsigned char llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  unsigned int llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  unsigned int llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  unsigned int llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  unsigned int llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  unsigned int llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  unsigned int llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  unsigned long long llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  signed int *llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_rej_uniform\n");
  llvm_cbe_tmp__129__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__130__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_backedge;

  do {     /* Syntactic loop '.backedge' to make GCC happy */
llvm_cbe__2e_backedge:
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = phi i32 [ 0, %%0 ], [ %%5, %%28 ], [ %%5, %%7  for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_427_count);
  llvm_cbe_tmp__129 = (unsigned int )llvm_cbe_tmp__129__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__129);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__131);
printf("\n = 0x%X",llvm_cbe_tmp__131);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = phi i32 [ 0, %%0 ], [ %%29, %%28 ], [ %%2, %%7  for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_428_count);
  llvm_cbe_tmp__130 = (unsigned int )llvm_cbe_tmp__130__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__130);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__151);
printf("\n = 0x%X",llvm_cbe_tmp__130);
}
  if ((((unsigned int )llvm_cbe_tmp__130&4294967295U) < ((unsigned int )llvm_cbe_len&4294967295U))) {
    goto llvm_cbe_tmp__154;
  } else {
    goto llvm_cbe__2e_critedge;
  }

llvm_cbe_tmp__155:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i32 %%1, 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_434_count);
  llvm_cbe_tmp__132 = (unsigned int )((unsigned int )(llvm_cbe_tmp__129&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__132&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = zext i32 %%1 to i64, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_440_count);
  llvm_cbe_tmp__133 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__129&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__133);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i8* %%buf, i64 %%9, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_441_count);
  llvm_cbe_tmp__134 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__133))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__133));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i8* %%10, align 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_442_count);
  llvm_cbe_tmp__135 = (unsigned char )*llvm_cbe_tmp__134;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__135);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = zext i8 %%11 to i32, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_443_count);
  llvm_cbe_tmp__136 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__135&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__136);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add i32 %%1, 2, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_450_count);
  llvm_cbe_tmp__137 = (unsigned int )((unsigned int )(llvm_cbe_tmp__129&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__137&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i32 %%8 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_456_count);
  llvm_cbe_tmp__138 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__132&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__138);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds i8* %%buf, i64 %%14, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_457_count);
  llvm_cbe_tmp__139 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__138))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__138));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i8* %%15, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_458_count);
  llvm_cbe_tmp__140 = (unsigned char )*llvm_cbe_tmp__139;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__140);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = zext i8 %%16 to i32, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_459_count);
  llvm_cbe_tmp__141 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__140&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__141);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = shl nuw nsw i32 %%17, 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_460_count);
  llvm_cbe_tmp__142 = (unsigned int )llvm_cbe_tmp__141 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__142);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = zext i32 %%13 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_466_count);
  llvm_cbe_tmp__143 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__137&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__143);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds i8* %%buf, i64 %%19, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_467_count);
  llvm_cbe_tmp__144 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__143))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__143));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i8* %%20, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_468_count);
  llvm_cbe_tmp__145 = (unsigned char )*llvm_cbe_tmp__144;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__145);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = zext i8 %%21 to i32, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_469_count);
  llvm_cbe_tmp__146 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__145&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__146);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = shl nuw nsw i32 %%22, 16, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_470_count);
  llvm_cbe_tmp__147 = (unsigned int )llvm_cbe_tmp__146 << 16u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__147);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = and i32 %%23, 8323072, !dbg !16 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_471_count);
  llvm_cbe_tmp__148 = (unsigned int )llvm_cbe_tmp__147 & 8323072u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__148);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = or i32 %%18, %%12, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_472_count);
  llvm_cbe_tmp__149 = (unsigned int )llvm_cbe_tmp__142 | llvm_cbe_tmp__136;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__149);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = or i32 %%25, %%24, !dbg !16 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_473_count);
  llvm_cbe_tmp__150 = (unsigned int )llvm_cbe_tmp__149 | llvm_cbe_tmp__148;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__150);
  if ((((unsigned int )llvm_cbe_tmp__150&4294967295U) < ((unsigned int )8380417u&4294967295U))) {
    goto llvm_cbe_tmp__156;
  } else {
    llvm_cbe_tmp__129__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__131;   /* for PHI node */
    llvm_cbe_tmp__130__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__130;   /* for PHI node */
    goto llvm_cbe__2e_backedge;
  }

llvm_cbe_tmp__154:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add i32 %%1, 3, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_431_count);
  llvm_cbe_tmp__131 = (unsigned int )((unsigned int )(llvm_cbe_tmp__129&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__131&4294967295ull)));
  if ((((unsigned int )llvm_cbe_tmp__131&4294967295U) > ((unsigned int )llvm_cbe_buflen&4294967295U))) {
    goto llvm_cbe__2e_critedge;
  } else {
    goto llvm_cbe_tmp__155;
  }

llvm_cbe_tmp__156:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add i32 %%2, 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_482_count);
  llvm_cbe_tmp__151 = (unsigned int )((unsigned int )(llvm_cbe_tmp__130&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__151&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = zext i32 %%2 to i64, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_487_count);
  llvm_cbe_tmp__152 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__130&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__152);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds i32* %%a, i64 %%30, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_488_count);
  llvm_cbe_tmp__153 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__152))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__152));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%26, i32* %%31, align 4, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_uniform  --> \n", ++aesl_llvm_cbe_489_count);
  *llvm_cbe_tmp__153 = llvm_cbe_tmp__150;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__150);
  llvm_cbe_tmp__129__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__131;   /* for PHI node */
  llvm_cbe_tmp__130__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__151;   /* for PHI node */
  goto llvm_cbe__2e_backedge;

  } while (1); /* end of syntactic loop '.backedge' */
llvm_cbe__2e_critedge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_rej_uniform}\n");
  return llvm_cbe_tmp__130;
}


void pqcrystals_dilithium3_ref_poly_uniform_eta(l_struct_OC_poly *llvm_cbe_a,  char *llvm_cbe_seed, signed short llvm_cbe_nonce) {
  static  unsigned long long aesl_llvm_cbe_buf_count = 0;
   char llvm_cbe_buf[272];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_state_count = 0;
  l_struct_OC_keccak_state llvm_cbe_state;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
   char *llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  signed int *llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  unsigned int llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  unsigned long long llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  signed int *llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  unsigned int llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  unsigned int llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  unsigned int llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_uniform_eta\n");
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_dilithium_shake256_stream_init(%%struct.keccak_state* %%state, i8* %%seed, i16 zeroext %%nonce) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_eta  --> \n", ++aesl_llvm_cbe_503_count);
  pqcrystals_dilithium3_ref_dilithium_shake256_stream_init((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_seed, llvm_cbe_nonce);
if (AESL_DEBUG_TRACE) {
printf("\nArgument nonce = 0x%X",llvm_cbe_nonce);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [272 x i8]* %%buf, i64 0, i64 0, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_eta  --> \n", ++aesl_llvm_cbe_504_count);
  llvm_cbe_tmp__157 = ( char *)(&llvm_cbe_buf[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 272
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_squeezeblocks(i8* %%1, i64 2, %%struct.keccak_state* %%state) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_eta  --> \n", ++aesl_llvm_cbe_505_count);
  pqcrystals_dilithium_fips202_ref_shake256_squeezeblocks(( char *)llvm_cbe_tmp__157, 2ull, (l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",2ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 0, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_eta  --> \n", ++aesl_llvm_cbe_506_count);
  llvm_cbe_tmp__158 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call fastcc i32 @aesl_internal_rej_eta(i32* %%2, i32 256, i8* %%1, i32 272), !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_eta  --> \n", ++aesl_llvm_cbe_507_count);
  llvm_cbe_tmp__159 = (unsigned int )aesl_internal_rej_eta((signed int *)llvm_cbe_tmp__158, 256u, ( char *)llvm_cbe_tmp__157, 272u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",256u);
printf("\nArgument  = 0x%X",272u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__159);
}
  if ((((unsigned int )llvm_cbe_tmp__159&4294967295U) < ((unsigned int )256u&4294967295U))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__159;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%9, %%.lr.ph ], [ %%3, %%0  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_eta  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__164);
printf("\n = 0x%X",llvm_cbe_tmp__159);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_squeezeblocks(i8* %%1, i64 1, %%struct.keccak_state* %%state) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_eta  --> \n", ++aesl_llvm_cbe_515_count);
  pqcrystals_dilithium_fips202_ref_shake256_squeezeblocks(( char *)llvm_cbe_tmp__157, 1ull, (l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = zext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_eta  --> \n", ++aesl_llvm_cbe_516_count);
  llvm_cbe_tmp__160 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__160);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%5, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_eta  --> \n", ++aesl_llvm_cbe_517_count);
  llvm_cbe_tmp__161 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__160))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__160));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sub i32 256, %%storemerge1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_eta  --> \n", ++aesl_llvm_cbe_518_count);
  llvm_cbe_tmp__162 = (unsigned int )((unsigned int )(256u&4294967295ull)) - ((unsigned int )(llvm_cbe_storemerge1&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__162&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call fastcc i32 @aesl_internal_rej_eta(i32* %%6, i32 %%7, i8* %%1, i32 136), !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_eta  --> \n", ++aesl_llvm_cbe_519_count);
  llvm_cbe_tmp__163 = (unsigned int )aesl_internal_rej_eta((signed int *)llvm_cbe_tmp__161, llvm_cbe_tmp__162, ( char *)llvm_cbe_tmp__157, 136u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__162);
printf("\nArgument  = 0x%X",136u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__163);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i32 %%8, %%storemerge1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_eta  --> \n", ++aesl_llvm_cbe_520_count);
  llvm_cbe_tmp__164 = (unsigned int )((unsigned int )(llvm_cbe_tmp__163&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge1&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__164&4294967295ull)));
  if ((((unsigned int )llvm_cbe_tmp__164&4294967295U) < ((unsigned int )256u&4294967295U))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__164;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_uniform_eta}\n");
  return;
}


static signed int aesl_internal_rej_eta(signed int *llvm_cbe_a, signed int llvm_cbe_len,  char *llvm_cbe_buf, signed int llvm_cbe_buflen) {
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond2_count = 0;
  bool llvm_cbe_or_2e_cond2;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  unsigned int llvm_cbe_tmp__165;
  unsigned int llvm_cbe_tmp__165__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  unsigned int llvm_cbe_tmp__166;
  unsigned int llvm_cbe_tmp__166__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  unsigned long long llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
   char *llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  unsigned char llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  unsigned int llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  unsigned int llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  unsigned int llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  unsigned int llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  unsigned int llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  unsigned int llvm_cbe_tmp__175;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  unsigned long long llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  signed int *llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  unsigned int llvm_cbe_tmp__178;
  unsigned int llvm_cbe_tmp__178__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond1_count = 0;
  bool llvm_cbe_or_2e_cond1;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  unsigned int llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  unsigned int llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  unsigned long long llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  signed int *llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_be_count = 0;
  unsigned int llvm_cbe__2e_be;
  unsigned int llvm_cbe__2e_be__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned int llvm_cbe__2e_lcssa;
  unsigned int llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_rej_eta\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond2 = and i1 %%1, %% for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_or_2e_cond2_count);
  llvm_cbe_or_2e_cond2 = (bool )((((llvm_cbe_len&4294967295U) != (0u&4294967295U)) & ((llvm_cbe_buflen&4294967295U) != (0u&4294967295U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond2 = 0x%X\n", llvm_cbe_or_2e_cond2);
  if (llvm_cbe_or_2e_cond2) {
    llvm_cbe_tmp__165__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe_tmp__166__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_critedge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = phi i32 [ %%.be, %%.backedge ], [ 0, %%0  for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_553_count);
  llvm_cbe_tmp__165 = (unsigned int )llvm_cbe_tmp__165__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__165);
printf("\n.be = 0x%X",llvm_cbe__2e_be);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = phi i32 [ %%10, %%.backedge ], [ 0, %%0  for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_554_count);
  llvm_cbe_tmp__166 = (unsigned int )llvm_cbe_tmp__166__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__166);
printf("\n = 0x%X",llvm_cbe_tmp__172);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = zext i32 %%4 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_555_count);
  llvm_cbe_tmp__167 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__166&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__167);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds i8* %%buf, i64 %%5, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_556_count);
  llvm_cbe_tmp__168 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__167))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__167));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i8* %%6, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_557_count);
  llvm_cbe_tmp__169 = (unsigned char )*llvm_cbe_tmp__168;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__169);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i8 %%7 to i32, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_558_count);
  llvm_cbe_tmp__170 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__169&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__170);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = and i32 %%8, 15, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_559_count);
  llvm_cbe_tmp__171 = (unsigned int )llvm_cbe_tmp__170 & 15u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__171);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i32 %%4, 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_563_count);
  llvm_cbe_tmp__172 = (unsigned int )((unsigned int )(llvm_cbe_tmp__166&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__172&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = lshr i32 %%8, 4, !dbg !15 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_568_count);
  llvm_cbe_tmp__173 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__170&4294967295ull)) >> ((unsigned int )(4u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__173&4294967295ull)));
  if ((((unsigned int )llvm_cbe_tmp__171&4294967295U) < ((unsigned int )9u&4294967295U))) {
    goto llvm_cbe_tmp__183;
  } else {
    llvm_cbe_tmp__178__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__165;   /* for PHI node */
    goto llvm_cbe_tmp__184;
  }

llvm_cbe__2e_backedge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.be = phi i32 [ %%24, %%22 ], [ %%19, %%18  for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe__2e_be_count);
  llvm_cbe__2e_be = (unsigned int )llvm_cbe__2e_be__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.be = 0x%X",llvm_cbe__2e_be);
printf("\n = 0x%X",llvm_cbe_tmp__180);
printf("\n = 0x%X",llvm_cbe_tmp__178);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = and i1 %%27, %%2 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )(((((unsigned int )llvm_cbe__2e_be&4294967295U) < ((unsigned int )llvm_cbe_len&4294967295U)) & (((unsigned int )llvm_cbe_tmp__172&4294967295U) < ((unsigned int )llvm_cbe_buflen&4294967295U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
  if (llvm_cbe_or_2e_cond) {
    llvm_cbe_tmp__165__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_be;   /* for PHI node */
    llvm_cbe_tmp__166__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__172;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_be;   /* for PHI node */
    goto llvm_cbe__2e_critedge;
  }

llvm_cbe_tmp__184:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = phi i32 [ %%15, %%13 ], [ %%3, %%.lr.ph  for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_586_count);
  llvm_cbe_tmp__178 = (unsigned int )llvm_cbe_tmp__178__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__178);
printf("\n = 0x%X",llvm_cbe_tmp__175);
printf("\n = 0x%X",llvm_cbe_tmp__165);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond1 = and i1 %%20, %%21, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_or_2e_cond1_count);
  llvm_cbe_or_2e_cond1 = (bool )(((((unsigned char )llvm_cbe_tmp__169&255U) < ((unsigned char )((unsigned char )-112)&255U)) & (((unsigned int )llvm_cbe_tmp__178&4294967295U) < ((unsigned int )llvm_cbe_len&4294967295U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond1 = 0x%X\n", llvm_cbe_or_2e_cond1);
  if (llvm_cbe_or_2e_cond1) {
    goto llvm_cbe_tmp__185;
  } else {
    llvm_cbe__2e_be__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__178;   /* for PHI node */
    goto llvm_cbe__2e_backedge;
  }

llvm_cbe_tmp__183:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sub i32 4, %%9, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_574_count);
  llvm_cbe_tmp__174 = (unsigned int )((unsigned int )(4u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__171&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__174&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add i32 %%3, 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_575_count);
  llvm_cbe_tmp__175 = (unsigned int )((unsigned int )(llvm_cbe_tmp__165&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__175&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = zext i32 %%3 to i64, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_582_count);
  llvm_cbe_tmp__176 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__165&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__176);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds i32* %%a, i64 %%16, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_583_count);
  llvm_cbe_tmp__177 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__176))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__176));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%14, i32* %%17, align 4, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_584_count);
  *llvm_cbe_tmp__177 = llvm_cbe_tmp__174;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__174);
  llvm_cbe_tmp__178__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__175;   /* for PHI node */
  goto llvm_cbe_tmp__184;

llvm_cbe_tmp__185:
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sub i32 4, %%11, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_590_count);
  llvm_cbe_tmp__179 = (unsigned int )((unsigned int )(4u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__173&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__179&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i32 %%19, 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_591_count);
  llvm_cbe_tmp__180 = (unsigned int )((unsigned int )(llvm_cbe_tmp__178&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__180&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = zext i32 %%19 to i64, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_598_count);
  llvm_cbe_tmp__181 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__178&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__181);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds i32* %%a, i64 %%25, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_599_count);
  llvm_cbe_tmp__182 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__181))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__181));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%23, i32* %%26, align 4, !dbg !14 for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe_600_count);
  *llvm_cbe_tmp__182 = llvm_cbe_tmp__179;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__179);
  llvm_cbe__2e_be__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__180;   /* for PHI node */
  goto llvm_cbe__2e_backedge;

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e_critedge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i32 [ 0, %%0 ], [ %%.be, %%.backedge  for 0x%I64xth hint within @aesl_internal_rej_eta  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned int )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%X",llvm_cbe__2e_lcssa);
printf("\n = 0x%X",0u);
printf("\n.be = 0x%X",llvm_cbe__2e_be);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_rej_eta}\n");
  return llvm_cbe__2e_lcssa;
}


void pqcrystals_dilithium3_ref_poly_uniform_gamma1(l_struct_OC_poly *llvm_cbe_a,  char *llvm_cbe_seed, signed short llvm_cbe_nonce) {
  static  unsigned long long aesl_llvm_cbe_buf_count = 0;
   char llvm_cbe_buf[680];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_state_count = 0;
  l_struct_OC_keccak_state llvm_cbe_state;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
   char *llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_uniform_gamma1\n");
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_dilithium_shake256_stream_init(%%struct.keccak_state* %%state, i8* %%seed, i16 zeroext %%nonce) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_gamma1  --> \n", ++aesl_llvm_cbe_614_count);
  pqcrystals_dilithium3_ref_dilithium_shake256_stream_init((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_seed, llvm_cbe_nonce);
if (AESL_DEBUG_TRACE) {
printf("\nArgument nonce = 0x%X",llvm_cbe_nonce);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [680 x i8]* %%buf, i64 0, i64 0, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_gamma1  --> \n", ++aesl_llvm_cbe_615_count);
  llvm_cbe_tmp__186 = ( char *)(&llvm_cbe_buf[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 680
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_squeezeblocks(i8* %%1, i64 5, %%struct.keccak_state* %%state) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_gamma1  --> \n", ++aesl_llvm_cbe_616_count);
  pqcrystals_dilithium_fips202_ref_shake256_squeezeblocks(( char *)llvm_cbe_tmp__186, 5ull, (l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",5ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyz_unpack(%%struct.poly* %%a, i8* %%1), !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_uniform_gamma1  --> \n", ++aesl_llvm_cbe_617_count);
  pqcrystals_dilithium3_ref_polyz_unpack((l_struct_OC_poly *)llvm_cbe_a, ( char *)llvm_cbe_tmp__186);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_uniform_gamma1}\n");
  return;
}


void pqcrystals_dilithium3_ref_polyz_unpack(l_struct_OC_poly *llvm_cbe_r,  char *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;
  static  unsigned long long aesl_llvm_cbe_649_count = 0;
  static  unsigned long long aesl_llvm_cbe_650_count = 0;
  static  unsigned long long aesl_llvm_cbe_651_count = 0;
  static  unsigned long long aesl_llvm_cbe_652_count = 0;
  static  unsigned long long aesl_llvm_cbe_653_count = 0;
  static  unsigned long long aesl_llvm_cbe_654_count = 0;
  static  unsigned long long aesl_llvm_cbe_655_count = 0;
  static  unsigned long long aesl_llvm_cbe_656_count = 0;
  static  unsigned long long aesl_llvm_cbe_657_count = 0;
  static  unsigned long long aesl_llvm_cbe_658_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_659_count = 0;
  unsigned int llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
  unsigned long long llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
   char *llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  unsigned char llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  unsigned int llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  unsigned int llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  unsigned long long llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_666_count = 0;
  signed int *llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_667_count = 0;
  static  unsigned long long aesl_llvm_cbe_668_count = 0;
  unsigned int llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_669_count = 0;
  unsigned long long llvm_cbe_tmp__196;
  static  unsigned long long aesl_llvm_cbe_670_count = 0;
   char *llvm_cbe_tmp__197;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
  unsigned char llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
  unsigned int llvm_cbe_tmp__199;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
  unsigned int llvm_cbe_tmp__200;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
  unsigned int llvm_cbe_tmp__201;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  unsigned int llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  unsigned long long llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
   char *llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  unsigned char llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
  unsigned int llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  unsigned int llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;
  unsigned int llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  unsigned int llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_684_count = 0;
  static  unsigned long long aesl_llvm_cbe_685_count = 0;
  unsigned char llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe_686_count = 0;
  unsigned int llvm_cbe_tmp__211;
  static  unsigned long long aesl_llvm_cbe_687_count = 0;
  unsigned int llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe_688_count = 0;
  unsigned int llvm_cbe_tmp__213;
  static  unsigned long long aesl_llvm_cbe_689_count = 0;
  unsigned long long llvm_cbe_tmp__214;
  static  unsigned long long aesl_llvm_cbe_690_count = 0;
  signed int *llvm_cbe_tmp__215;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  unsigned int llvm_cbe_tmp__216;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;
  unsigned long long llvm_cbe_tmp__217;
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
   char *llvm_cbe_tmp__218;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  unsigned char llvm_cbe_tmp__219;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  unsigned int llvm_cbe_tmp__220;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  unsigned int llvm_cbe_tmp__221;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  unsigned int llvm_cbe_tmp__222;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  unsigned int llvm_cbe_tmp__223;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  unsigned long long llvm_cbe_tmp__224;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
   char *llvm_cbe_tmp__225;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  unsigned char llvm_cbe_tmp__226;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  unsigned int llvm_cbe_tmp__227;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  unsigned int llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  unsigned int llvm_cbe_tmp__229;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  unsigned int llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  unsigned int llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  unsigned int llvm_cbe_tmp__232;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_polyz_unpack\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__233;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__233:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%47, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__232);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = mul i32 %%storemerge1, 5, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_659_count);
  llvm_cbe_tmp__187 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) * ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__187&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_660_count);
  llvm_cbe_tmp__188 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__187&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__188);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i8* %%a, i64 %%3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_661_count);
  llvm_cbe_tmp__189 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__188))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__188));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i8* %%4, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_662_count);
  llvm_cbe_tmp__190 = (unsigned char )*llvm_cbe_tmp__189;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__190);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i8 %%5 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_663_count);
  llvm_cbe_tmp__191 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__190&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__191);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = shl i32 %%storemerge1, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_664_count);
  llvm_cbe_tmp__192 = (unsigned int )llvm_cbe_storemerge1 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__192);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i32 %%7 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_665_count);
  llvm_cbe_tmp__193 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__192&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__193);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_666_count);
  llvm_cbe_tmp__194 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__193))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__193));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%6, i32* %%9, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_667_count);
  *llvm_cbe_tmp__194 = llvm_cbe_tmp__191;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__191);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i32 %%2, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_668_count);
  llvm_cbe_tmp__195 = (unsigned int )((unsigned int )(llvm_cbe_tmp__187&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__195&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i32 %%10 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_669_count);
  llvm_cbe_tmp__196 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__195&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__196);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds i8* %%a, i64 %%11, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_670_count);
  llvm_cbe_tmp__197 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__196))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__196));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i8* %%12, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_671_count);
  llvm_cbe_tmp__198 = (unsigned char )*llvm_cbe_tmp__197;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__198);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i8 %%13 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_672_count);
  llvm_cbe_tmp__199 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__198&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__199);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = shl nuw nsw i32 %%14, 8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_673_count);
  llvm_cbe_tmp__200 = (unsigned int )llvm_cbe_tmp__199 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__200);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = or i32 %%15, %%6, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_674_count);
  llvm_cbe_tmp__201 = (unsigned int )llvm_cbe_tmp__200 | llvm_cbe_tmp__191;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__201);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%16, i32* %%9, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_675_count);
  *llvm_cbe_tmp__194 = llvm_cbe_tmp__201;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__201);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add i32 %%2, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_676_count);
  llvm_cbe_tmp__202 = (unsigned int )((unsigned int )(llvm_cbe_tmp__187&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__202&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = zext i32 %%17 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_677_count);
  llvm_cbe_tmp__203 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__202&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__203);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds i8* %%a, i64 %%18, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_678_count);
  llvm_cbe_tmp__204 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__203))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__203));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i8* %%19, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_679_count);
  llvm_cbe_tmp__205 = (unsigned char )*llvm_cbe_tmp__204;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__205);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = zext i8 %%20 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_680_count);
  llvm_cbe_tmp__206 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__205&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__206);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = shl nuw nsw i32 %%21, 16, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_681_count);
  llvm_cbe_tmp__207 = (unsigned int )llvm_cbe_tmp__206 << 16u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__207);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = and i32 %%22, 983040, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_682_count);
  llvm_cbe_tmp__208 = (unsigned int )llvm_cbe_tmp__207 & 983040u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__208);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = or i32 %%23, %%16, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_683_count);
  llvm_cbe_tmp__209 = (unsigned int )llvm_cbe_tmp__208 | llvm_cbe_tmp__201;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__209);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%24, i32* %%9, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_684_count);
  *llvm_cbe_tmp__194 = llvm_cbe_tmp__209;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__209);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i8* %%19, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_685_count);
  llvm_cbe_tmp__210 = (unsigned char )*llvm_cbe_tmp__204;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__210);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = zext i8 %%25 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_686_count);
  llvm_cbe_tmp__211 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__210&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__211);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = lshr i32 %%26, 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_687_count);
  llvm_cbe_tmp__212 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__211&4294967295ull)) >> ((unsigned int )(4u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__212&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = or i32 %%7, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_688_count);
  llvm_cbe_tmp__213 = (unsigned int )llvm_cbe_tmp__192 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__213);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = zext i32 %%28 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_689_count);
  llvm_cbe_tmp__214 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__213&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__214);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%29, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_690_count);
  llvm_cbe_tmp__215 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__214))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__214));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%27, i32* %%30, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_691_count);
  *llvm_cbe_tmp__215 = llvm_cbe_tmp__212;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__212);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add i32 %%2, 3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_692_count);
  llvm_cbe_tmp__216 = (unsigned int )((unsigned int )(llvm_cbe_tmp__187&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__216&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = zext i32 %%31 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_693_count);
  llvm_cbe_tmp__217 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__216&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__217);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds i8* %%a, i64 %%32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_694_count);
  llvm_cbe_tmp__218 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__217))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__217));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i8* %%33, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_695_count);
  llvm_cbe_tmp__219 = (unsigned char )*llvm_cbe_tmp__218;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__219);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = zext i8 %%34 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_696_count);
  llvm_cbe_tmp__220 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__219&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__220);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = shl nuw nsw i32 %%35, 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_697_count);
  llvm_cbe_tmp__221 = (unsigned int )llvm_cbe_tmp__220 << 4u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__221);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = or i32 %%36, %%27, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_698_count);
  llvm_cbe_tmp__222 = (unsigned int )llvm_cbe_tmp__221 | llvm_cbe_tmp__212;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__222);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%37, i32* %%30, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_699_count);
  *llvm_cbe_tmp__215 = llvm_cbe_tmp__222;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__222);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = add i32 %%2, 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_700_count);
  llvm_cbe_tmp__223 = (unsigned int )((unsigned int )(llvm_cbe_tmp__187&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__223&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = zext i32 %%38 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_701_count);
  llvm_cbe_tmp__224 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__223&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__224);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds i8* %%a, i64 %%39, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_702_count);
  llvm_cbe_tmp__225 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__224))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__224));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = load i8* %%40, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_703_count);
  llvm_cbe_tmp__226 = (unsigned char )*llvm_cbe_tmp__225;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__226);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = zext i8 %%41 to i32, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_704_count);
  llvm_cbe_tmp__227 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__226&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__227);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = shl nuw nsw i32 %%42, 12, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_705_count);
  llvm_cbe_tmp__228 = (unsigned int )llvm_cbe_tmp__227 << 12u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__228);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = or i32 %%37, %%43, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_706_count);
  llvm_cbe_tmp__229 = (unsigned int )llvm_cbe_tmp__222 | llvm_cbe_tmp__228;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__229);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = sub nsw i32 524288, %%24, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_707_count);
  llvm_cbe_tmp__230 = (unsigned int )((unsigned int )(524288u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__209&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__230&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%45, i32* %%9, align 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_708_count);
  *llvm_cbe_tmp__194 = llvm_cbe_tmp__230;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__230);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = sub nsw i32 524288, %%44, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_709_count);
  llvm_cbe_tmp__231 = (unsigned int )((unsigned int )(524288u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__229&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__231&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%46, i32* %%30, align 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_710_count);
  *llvm_cbe_tmp__215 = llvm_cbe_tmp__231;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__231);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = add i32 %%storemerge1, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_unpack  --> \n", ++aesl_llvm_cbe_711_count);
  llvm_cbe_tmp__232 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__232&4294967295ull)));
  if (((llvm_cbe_tmp__232&4294967295U) == (128u&4294967295U))) {
    goto llvm_cbe_tmp__234;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__232;   /* for PHI node */
    goto llvm_cbe_tmp__233;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__234:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_polyz_unpack}\n");
  return;
}


void pqcrystals_dilithium3_ref_poly_challenge(l_struct_OC_poly *llvm_cbe_c,  char *llvm_cbe_seed) {
  static  unsigned long long aesl_llvm_cbe_buf_count = 0;
   char llvm_cbe_buf[136];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_state_count = 0;
  l_struct_OC_keccak_state llvm_cbe_state;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
   char *llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  unsigned char llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  unsigned long long llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
   char *llvm_cbe_tmp__238;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  unsigned char llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  unsigned long long llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  unsigned long long llvm_cbe_tmp__241;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
  unsigned long long llvm_cbe_tmp__242;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
  static  unsigned long long aesl_llvm_cbe_795_count = 0;
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
   char *llvm_cbe_tmp__243;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  unsigned char llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  unsigned long long llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  unsigned long long llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  unsigned long long llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
  static  unsigned long long aesl_llvm_cbe_816_count = 0;
  static  unsigned long long aesl_llvm_cbe_817_count = 0;
  static  unsigned long long aesl_llvm_cbe_818_count = 0;
  static  unsigned long long aesl_llvm_cbe_819_count = 0;
  static  unsigned long long aesl_llvm_cbe_820_count = 0;
  static  unsigned long long aesl_llvm_cbe_821_count = 0;
  static  unsigned long long aesl_llvm_cbe_822_count = 0;
  static  unsigned long long aesl_llvm_cbe_823_count = 0;
  static  unsigned long long aesl_llvm_cbe_824_count = 0;
   char *llvm_cbe_tmp__248;
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  unsigned char llvm_cbe_tmp__249;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  unsigned long long llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  unsigned long long llvm_cbe_tmp__251;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  unsigned long long llvm_cbe_tmp__252;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
   char *llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;
  unsigned char llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
  unsigned long long llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  unsigned long long llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
  unsigned long long llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_850_count = 0;
  static  unsigned long long aesl_llvm_cbe_851_count = 0;
  static  unsigned long long aesl_llvm_cbe_852_count = 0;
  static  unsigned long long aesl_llvm_cbe_853_count = 0;
  static  unsigned long long aesl_llvm_cbe_854_count = 0;
  static  unsigned long long aesl_llvm_cbe_855_count = 0;
  static  unsigned long long aesl_llvm_cbe_856_count = 0;
  static  unsigned long long aesl_llvm_cbe_857_count = 0;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;
  static  unsigned long long aesl_llvm_cbe_860_count = 0;
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  static  unsigned long long aesl_llvm_cbe_863_count = 0;
  static  unsigned long long aesl_llvm_cbe_864_count = 0;
  static  unsigned long long aesl_llvm_cbe_865_count = 0;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
   char *llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  unsigned char llvm_cbe_tmp__259;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
  unsigned long long llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_869_count = 0;
  unsigned long long llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_870_count = 0;
  unsigned long long llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_871_count = 0;
  static  unsigned long long aesl_llvm_cbe_872_count = 0;
  static  unsigned long long aesl_llvm_cbe_873_count = 0;
  static  unsigned long long aesl_llvm_cbe_874_count = 0;
  static  unsigned long long aesl_llvm_cbe_875_count = 0;
  static  unsigned long long aesl_llvm_cbe_876_count = 0;
  static  unsigned long long aesl_llvm_cbe_877_count = 0;
  static  unsigned long long aesl_llvm_cbe_878_count = 0;
  static  unsigned long long aesl_llvm_cbe_879_count = 0;
  static  unsigned long long aesl_llvm_cbe_880_count = 0;
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
   char *llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  unsigned char llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  unsigned long long llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  unsigned long long llvm_cbe_tmp__266;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  unsigned long long llvm_cbe_tmp__267;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
   char *llvm_cbe_tmp__268;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;
  unsigned char llvm_cbe_tmp__269;
  static  unsigned long long aesl_llvm_cbe_910_count = 0;
  unsigned long long llvm_cbe_tmp__270;
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
  unsigned long long llvm_cbe_tmp__271;
  static  unsigned long long aesl_llvm_cbe_912_count = 0;
  unsigned long long llvm_cbe_tmp__272;
  static  unsigned long long aesl_llvm_cbe_913_count = 0;
  static  unsigned long long aesl_llvm_cbe_914_count = 0;
  static  unsigned long long aesl_llvm_cbe_915_count = 0;
  static  unsigned long long aesl_llvm_cbe_916_count = 0;
  static  unsigned long long aesl_llvm_cbe_917_count = 0;
  static  unsigned long long aesl_llvm_cbe_918_count = 0;
  static  unsigned long long aesl_llvm_cbe_919_count = 0;
  static  unsigned long long aesl_llvm_cbe_920_count = 0;
  static  unsigned long long aesl_llvm_cbe_921_count = 0;
  static  unsigned long long aesl_llvm_cbe_922_count = 0;
  static  unsigned long long aesl_llvm_cbe_923_count = 0;
  static  unsigned long long aesl_llvm_cbe_924_count = 0;
  static  unsigned long long aesl_llvm_cbe_925_count = 0;
  static  unsigned long long aesl_llvm_cbe_926_count = 0;
  static  unsigned long long aesl_llvm_cbe_927_count = 0;
  static  unsigned long long aesl_llvm_cbe_928_count = 0;
  static  unsigned long long aesl_llvm_cbe_929_count = 0;
  static  unsigned long long aesl_llvm_cbe_930_count = 0;
  static  unsigned long long aesl_llvm_cbe_931_count = 0;
  static  unsigned long long aesl_llvm_cbe_932_count = 0;
  static  unsigned long long aesl_llvm_cbe_933_count = 0;
  static  unsigned long long aesl_llvm_cbe_934_count = 0;
  static  unsigned long long aesl_llvm_cbe_935_count = 0;
  static  unsigned long long aesl_llvm_cbe_936_count = 0;
  static  unsigned long long aesl_llvm_cbe_937_count = 0;
  static  unsigned long long aesl_llvm_cbe_938_count = 0;
  static  unsigned long long aesl_llvm_cbe_939_count = 0;
  static  unsigned long long aesl_llvm_cbe_940_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge17_count = 0;
  unsigned int llvm_cbe_storemerge17;
  unsigned int llvm_cbe_storemerge17__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  unsigned long long llvm_cbe_tmp__273;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  signed int *llvm_cbe_tmp__274;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
  unsigned int llvm_cbe_tmp__275;
  static  unsigned long long aesl_llvm_cbe_945_count = 0;
  static  unsigned long long aesl_llvm_cbe_946_count = 0;
  static  unsigned long long aesl_llvm_cbe_947_count = 0;
  static  unsigned long long aesl_llvm_cbe_948_count = 0;
  static  unsigned long long aesl_llvm_cbe_949_count = 0;
  static  unsigned long long aesl_llvm_cbe_950_count = 0;
  static  unsigned long long aesl_llvm_cbe_951_count = 0;
  static  unsigned long long aesl_llvm_cbe_952_count = 0;
  static  unsigned long long aesl_llvm_cbe_953_count = 0;
  static  unsigned long long aesl_llvm_cbe_954_count = 0;
  static  unsigned long long aesl_llvm_cbe_955_count = 0;
  static  unsigned long long aesl_llvm_cbe_956_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond11_count = 0;
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge25_count = 0;
  unsigned int llvm_cbe_storemerge25;
  unsigned int llvm_cbe_storemerge25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  unsigned int llvm_cbe_tmp__276;
  unsigned int llvm_cbe_tmp__276__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  unsigned long long llvm_cbe_tmp__277;
  unsigned long long llvm_cbe_tmp__277__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_960_count = 0;
  static  unsigned long long aesl_llvm_cbe_961_count = 0;
  unsigned int llvm_cbe_tmp__278;
  unsigned int llvm_cbe_tmp__278__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_962_count = 0;
  static  unsigned long long aesl_llvm_cbe_963_count = 0;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  unsigned int llvm_cbe_tmp__279;
  unsigned int llvm_cbe_tmp__279__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  unsigned int llvm_cbe_tmp__280;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  unsigned long long llvm_cbe_tmp__281;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
   char *llvm_cbe_tmp__282;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  unsigned char llvm_cbe_tmp__283;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  unsigned int llvm_cbe_tmp__284;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  unsigned long long llvm_cbe_tmp__285;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
  signed int *llvm_cbe_tmp__286;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  unsigned int llvm_cbe_tmp__287;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  unsigned long long llvm_cbe_tmp__288;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  signed int *llvm_cbe_tmp__289;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  unsigned int llvm_cbe_tmp__290;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  unsigned int llvm_cbe_tmp__291;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  unsigned int llvm_cbe_tmp__292;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  unsigned int llvm_cbe_tmp__293;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  unsigned long long llvm_cbe_tmp__294;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  unsigned int llvm_cbe_tmp__295;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  static  unsigned long long aesl_llvm_cbe_1008_count = 0;
  static  unsigned long long aesl_llvm_cbe_1009_count = 0;
  static  unsigned long long aesl_llvm_cbe_1010_count = 0;
  static  unsigned long long aesl_llvm_cbe_1011_count = 0;
  static  unsigned long long aesl_llvm_cbe_1012_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1013_count = 0;
  static  unsigned long long aesl_llvm_cbe_1014_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_poly_challenge\n");
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_init(%%struct.keccak_state* %%state) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_743_count);
  pqcrystals_dilithium_fips202_ref_shake256_init((l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_absorb(%%struct.keccak_state* %%state, i8* %%seed, i64 48) nounwind, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_744_count);
  pqcrystals_dilithium_fips202_ref_shake256_absorb((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_seed, 48ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",48ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_finalize(%%struct.keccak_state* %%state) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_745_count);
  pqcrystals_dilithium_fips202_ref_shake256_finalize((l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%0 = getelementptr inbounds [136 x i8]* %%buf, i64 0, i64 0, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_746_count);
  llvm_cbe_tmp__235 = ( char *)(&llvm_cbe_buf[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 136
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_squeezeblocks(i8* %%0, i64 1, %%struct.keccak_state* %%state) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_747_count);
  pqcrystals_dilithium_fips202_ref_shake256_squeezeblocks(( char *)llvm_cbe_tmp__235, 1ull, (l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 136)) fprintf(stderr, "%s:%d: warning: Read access out of array 'buf' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i8* %%0, align 16, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_764_count);
  llvm_cbe_tmp__236 = (unsigned char )*llvm_cbe_tmp__235;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__236);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i8 %%1 to i64, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_765_count);
  llvm_cbe_tmp__237 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__236&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__237);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [136 x i8]* %%buf, i64 0, i64 1, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_782_count);
  llvm_cbe_tmp__238 = ( char *)(&llvm_cbe_buf[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 136
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 136)) fprintf(stderr, "%s:%d: warning: Read access out of array 'buf' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8* %%3, align 1, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_783_count);
  llvm_cbe_tmp__239 = (unsigned char )*llvm_cbe_tmp__238;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__239);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = zext i8 %%4 to i64, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_784_count);
  llvm_cbe_tmp__240 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__239&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__240);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = shl nuw nsw i64 %%5, 8, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_785_count);
  llvm_cbe_tmp__241 = (unsigned long long )llvm_cbe_tmp__240 << 8ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__241);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = or i64 %%6, %%2, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_786_count);
  llvm_cbe_tmp__242 = (unsigned long long )llvm_cbe_tmp__241 | llvm_cbe_tmp__237;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__242);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [136 x i8]* %%buf, i64 0, i64 2, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_803_count);
  llvm_cbe_tmp__243 = ( char *)(&llvm_cbe_buf[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 136
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 136)) fprintf(stderr, "%s:%d: warning: Read access out of array 'buf' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i8* %%8, align 2, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_804_count);
  llvm_cbe_tmp__244 = (unsigned char )*llvm_cbe_tmp__243;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__244);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = zext i8 %%9 to i64, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_805_count);
  llvm_cbe_tmp__245 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__244&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__245);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = shl nuw nsw i64 %%10, 16, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_806_count);
  llvm_cbe_tmp__246 = (unsigned long long )llvm_cbe_tmp__245 << 16ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__246);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = or i64 %%11, %%7, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_807_count);
  llvm_cbe_tmp__247 = (unsigned long long )llvm_cbe_tmp__246 | llvm_cbe_tmp__242;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__247);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [136 x i8]* %%buf, i64 0, i64 3, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_824_count);
  llvm_cbe_tmp__248 = ( char *)(&llvm_cbe_buf[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 136
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )3ull) < 136)) fprintf(stderr, "%s:%d: warning: Read access out of array 'buf' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i8* %%13, align 1, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_825_count);
  llvm_cbe_tmp__249 = (unsigned char )*llvm_cbe_tmp__248;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__249);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = zext i8 %%14 to i64, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_826_count);
  llvm_cbe_tmp__250 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__249&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__250);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = shl nuw nsw i64 %%15, 24, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_827_count);
  llvm_cbe_tmp__251 = (unsigned long long )llvm_cbe_tmp__250 << 24ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__251);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = or i64 %%16, %%12, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_828_count);
  llvm_cbe_tmp__252 = (unsigned long long )llvm_cbe_tmp__251 | llvm_cbe_tmp__247;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__252);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds [136 x i8]* %%buf, i64 0, i64 4, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_845_count);
  llvm_cbe_tmp__253 = ( char *)(&llvm_cbe_buf[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 136
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )4ull) < 136)) fprintf(stderr, "%s:%d: warning: Read access out of array 'buf' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i8* %%18, align 4, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_846_count);
  llvm_cbe_tmp__254 = (unsigned char )*llvm_cbe_tmp__253;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__254);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = zext i8 %%19 to i64, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_847_count);
  llvm_cbe_tmp__255 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__254&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__255);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = shl nuw nsw i64 %%20, 32, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_848_count);
  llvm_cbe_tmp__256 = (unsigned long long )llvm_cbe_tmp__255 << 32ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__256);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = or i64 %%21, %%17, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_849_count);
  llvm_cbe_tmp__257 = (unsigned long long )llvm_cbe_tmp__256 | llvm_cbe_tmp__252;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__257);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds [136 x i8]* %%buf, i64 0, i64 5, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_866_count);
  llvm_cbe_tmp__258 = ( char *)(&llvm_cbe_buf[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 136
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )5ull) < 136)) fprintf(stderr, "%s:%d: warning: Read access out of array 'buf' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i8* %%23, align 1, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_867_count);
  llvm_cbe_tmp__259 = (unsigned char )*llvm_cbe_tmp__258;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__259);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = zext i8 %%24 to i64, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_868_count);
  llvm_cbe_tmp__260 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__259&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__260);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = shl nuw nsw i64 %%25, 40, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_869_count);
  llvm_cbe_tmp__261 = (unsigned long long )llvm_cbe_tmp__260 << 40ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__261);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = or i64 %%26, %%22, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_870_count);
  llvm_cbe_tmp__262 = (unsigned long long )llvm_cbe_tmp__261 | llvm_cbe_tmp__257;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__262);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds [136 x i8]* %%buf, i64 0, i64 6, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_887_count);
  llvm_cbe_tmp__263 = ( char *)(&llvm_cbe_buf[(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 136
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )6ull) < 136)) fprintf(stderr, "%s:%d: warning: Read access out of array 'buf' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i8* %%28, align 2, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_888_count);
  llvm_cbe_tmp__264 = (unsigned char )*llvm_cbe_tmp__263;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__264);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = zext i8 %%29 to i64, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_889_count);
  llvm_cbe_tmp__265 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__264&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__265);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = shl nuw nsw i64 %%30, 48, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_890_count);
  llvm_cbe_tmp__266 = (unsigned long long )llvm_cbe_tmp__265 << 48ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__266);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = or i64 %%31, %%27, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_891_count);
  llvm_cbe_tmp__267 = (unsigned long long )llvm_cbe_tmp__266 | llvm_cbe_tmp__262;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__267);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds [136 x i8]* %%buf, i64 0, i64 7, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_908_count);
  llvm_cbe_tmp__268 = ( char *)(&llvm_cbe_buf[(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 136
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )7ull) < 136)) fprintf(stderr, "%s:%d: warning: Read access out of array 'buf' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i8* %%33, align 1, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_909_count);
  llvm_cbe_tmp__269 = (unsigned char )*llvm_cbe_tmp__268;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__269);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = zext i8 %%34 to i64, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_910_count);
  llvm_cbe_tmp__270 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__269&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__270);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = shl nuw i64 %%35, 56, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_911_count);
  llvm_cbe_tmp__271 = (unsigned long long )llvm_cbe_tmp__270 << 56ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__271);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = or i64 %%36, %%32, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_912_count);
  llvm_cbe_tmp__272 = (unsigned long long )llvm_cbe_tmp__271 | llvm_cbe_tmp__267;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__272);
  llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__296;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__296:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge17 = phi i32 [ 0, %%.preheader6 ], [ %%41, %%38  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_storemerge17_count);
  llvm_cbe_storemerge17 = (unsigned int )llvm_cbe_storemerge17__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge17 = 0x%X",llvm_cbe_storemerge17);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__275);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = zext i32 %%storemerge17 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_941_count);
  llvm_cbe_tmp__273 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge17&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__273);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds %%struct.poly* %%c, i64 0, i32 0, i64 %%39, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_942_count);
  llvm_cbe_tmp__274 = (signed int *)(&llvm_cbe_c->field0[(((signed long long )llvm_cbe_tmp__273))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__273));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%40, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_943_count);
  *llvm_cbe_tmp__274 = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = add i32 %%storemerge17, 1, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_944_count);
  llvm_cbe_tmp__275 = (unsigned int )((unsigned int )(llvm_cbe_storemerge17&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__275&4294967295ull)));
  if (((llvm_cbe_tmp__275&4294967295U) == (256u&4294967295U))) {
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )207u;   /* for PHI node */
    llvm_cbe_tmp__276__PHI_TEMPORARY = (unsigned int )8u;   /* for PHI node */
    llvm_cbe_tmp__277__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__272;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge17__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__275;   /* for PHI node */
    goto llvm_cbe_tmp__296;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25 = phi i32 [ %%67, %%56 ], [ 207, %%38  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_storemerge25_count);
  llvm_cbe_storemerge25 = (unsigned int )llvm_cbe_storemerge25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%X",llvm_cbe_storemerge25);
printf("\n = 0x%X",llvm_cbe_tmp__295);
printf("\n = 0x%X",207u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = phi i32 [ %%50, %%56 ], [ 8, %%38  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_958_count);
  llvm_cbe_tmp__276 = (unsigned int )llvm_cbe_tmp__276__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__276);
printf("\n = 0x%X",llvm_cbe_tmp__280);
printf("\n = 0x%X",8u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = phi i64 [ %%66, %%56 ], [ %%37, %%38  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_959_count);
  llvm_cbe_tmp__277 = (unsigned long long )llvm_cbe_tmp__277__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__277);
printf("\n = 0x%I64X",llvm_cbe_tmp__294);
printf("\n = 0x%I64X",llvm_cbe_tmp__272);
}
  llvm_cbe_tmp__278__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__276;   /* for PHI node */
  goto llvm_cbe_tmp__297;

llvm_cbe_tmp__298:
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = zext i8 %%53 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_984_count);
  llvm_cbe_tmp__285 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__283&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__285);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds %%struct.poly* %%c, i64 0, i32 0, i64 %%57, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_985_count);
  llvm_cbe_tmp__286 = (signed int *)(&llvm_cbe_c->field0[(((signed long long )llvm_cbe_tmp__285))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__285));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i32* %%58, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_986_count);
  llvm_cbe_tmp__287 = (unsigned int )*llvm_cbe_tmp__286;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__287);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = zext i32 %%storemerge25 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_987_count);
  llvm_cbe_tmp__288 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge25&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__288);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = getelementptr inbounds %%struct.poly* %%c, i64 0, i32 0, i64 %%60, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_988_count);
  llvm_cbe_tmp__289 = (signed int *)(&llvm_cbe_c->field0[(((signed long long )llvm_cbe_tmp__288))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__288));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%59, i32* %%61, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_989_count);
  *llvm_cbe_tmp__289 = llvm_cbe_tmp__287;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__287);
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = trunc i64 %%43 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_990_count);
  llvm_cbe_tmp__290 = (unsigned int )((unsigned int )llvm_cbe_tmp__277&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__290);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = shl i32 %%62, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_991_count);
  llvm_cbe_tmp__291 = (unsigned int )llvm_cbe_tmp__290 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__291);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = and i32 %%63, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_992_count);
  llvm_cbe_tmp__292 = (unsigned int )llvm_cbe_tmp__291 & 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__292);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = sub i32 1, %%64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_993_count);
  llvm_cbe_tmp__293 = (unsigned int )((unsigned int )(1u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__292&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__293&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%65, i32* %%58, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_994_count);
  *llvm_cbe_tmp__286 = llvm_cbe_tmp__293;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__293);
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = lshr i64 %%43, 1, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_995_count);
  llvm_cbe_tmp__294 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__277&18446744073709551615ull)) >> ((unsigned long long )(1ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__294&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = add i32 %%storemerge25, 1, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_1000_count);
  llvm_cbe_tmp__295 = (unsigned int )((unsigned int )(llvm_cbe_storemerge25&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__295&4294967295ull)));
  if (((llvm_cbe_tmp__295&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__299;
  } else {
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__295;   /* for PHI node */
    llvm_cbe_tmp__276__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__280;   /* for PHI node */
    llvm_cbe_tmp__277__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__294;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__297:
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = phi i32 [ %%50, %%48 ], [ %%42, %%.preheader  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_961_count);
  llvm_cbe_tmp__278 = (unsigned int )llvm_cbe_tmp__278__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__278);
printf("\n = 0x%X",llvm_cbe_tmp__280);
printf("\n = 0x%X",llvm_cbe_tmp__276);
}
  if ((((unsigned int )llvm_cbe_tmp__278&4294967295U) > ((unsigned int )135u&4294967295U))) {
    goto llvm_cbe_tmp__300;
  } else {
    llvm_cbe_tmp__279__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__278;   /* for PHI node */
    goto llvm_cbe_tmp__301;
  }

llvm_cbe_tmp__301:
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = phi i32 [ 0, %%47 ], [ %%45, %%44 ], !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_969_count);
  llvm_cbe_tmp__279 = (unsigned int )llvm_cbe_tmp__279__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__279);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__278);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = add i32 %%49, 1, !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_970_count);
  llvm_cbe_tmp__280 = (unsigned int )((unsigned int )(llvm_cbe_tmp__279&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__280&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = zext i32 %%49 to i64, !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_974_count);
  llvm_cbe_tmp__281 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__279&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__281);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = getelementptr inbounds [136 x i8]* %%buf, i64 0, i64 %%51, !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_975_count);
  llvm_cbe_tmp__282 = ( char *)(&llvm_cbe_buf[(((signed long long )llvm_cbe_tmp__281))
#ifdef AESL_BC_SIM
 % 136
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__281));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__281) < 136)) fprintf(stderr, "%s:%d: warning: Read access out of array 'buf' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = load i8* %%52, align 1, !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_976_count);
  llvm_cbe_tmp__283 = (unsigned char )*llvm_cbe_tmp__282;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__283);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = zext i8 %%53 to i32, !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_977_count);
  llvm_cbe_tmp__284 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__283&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__284);
  if ((((unsigned int )llvm_cbe_tmp__284&4294967295U) > ((unsigned int )llvm_cbe_storemerge25&4294967295U))) {
    llvm_cbe_tmp__278__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__280;   /* for PHI node */
    goto llvm_cbe_tmp__297;
  } else {
    goto llvm_cbe_tmp__298;
  }

llvm_cbe_tmp__300:
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_squeezeblocks(i8* %%0, i64 1, %%struct.keccak_state* %%state) nounwind, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_poly_challenge  --> \n", ++aesl_llvm_cbe_964_count);
  pqcrystals_dilithium_fips202_ref_shake256_squeezeblocks(( char *)llvm_cbe_tmp__235, 1ull, (l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
}
  llvm_cbe_tmp__279__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__301;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__299:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_poly_challenge}\n");
  return;
}


void pqcrystals_dilithium3_ref_polyeta_pack( char *llvm_cbe_r, l_struct_OC_poly *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_1015_count = 0;
  static  unsigned long long aesl_llvm_cbe_1016_count = 0;
  static  unsigned long long aesl_llvm_cbe_1017_count = 0;
  static  unsigned long long aesl_llvm_cbe_1018_count = 0;
  static  unsigned long long aesl_llvm_cbe_1019_count = 0;
  static  unsigned long long aesl_llvm_cbe_1020_count = 0;
  static  unsigned long long aesl_llvm_cbe_1021_count = 0;
  static  unsigned long long aesl_llvm_cbe_1022_count = 0;
  static  unsigned long long aesl_llvm_cbe_1023_count = 0;
  static  unsigned long long aesl_llvm_cbe_1024_count = 0;
  static  unsigned long long aesl_llvm_cbe_1025_count = 0;
  static  unsigned long long aesl_llvm_cbe_1026_count = 0;
  static  unsigned long long aesl_llvm_cbe_1027_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
  unsigned int llvm_cbe_tmp__302;
  static  unsigned long long aesl_llvm_cbe_1029_count = 0;
  unsigned long long llvm_cbe_tmp__303;
  static  unsigned long long aesl_llvm_cbe_1030_count = 0;
  signed int *llvm_cbe_tmp__304;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  unsigned int llvm_cbe_tmp__305;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
  unsigned char llvm_cbe_tmp__306;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  unsigned char llvm_cbe_tmp__307;
  static  unsigned long long aesl_llvm_cbe_1034_count = 0;
  unsigned int llvm_cbe_tmp__308;
  static  unsigned long long aesl_llvm_cbe_1035_count = 0;
  unsigned long long llvm_cbe_tmp__309;
  static  unsigned long long aesl_llvm_cbe_1036_count = 0;
  signed int *llvm_cbe_tmp__310;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  unsigned int llvm_cbe_tmp__311;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  unsigned char llvm_cbe_tmp__312;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  unsigned char llvm_cbe_tmp__313;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  unsigned char llvm_cbe_tmp__314;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
  unsigned char llvm_cbe_tmp__315;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  unsigned long long llvm_cbe_tmp__316;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
   char *llvm_cbe_tmp__317;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  unsigned int llvm_cbe_tmp__318;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_polyeta_pack\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__319;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__319:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%18, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__318);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = shl i32 %%storemerge1, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1028_count);
  llvm_cbe_tmp__302 = (unsigned int )llvm_cbe_storemerge1 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__302);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1029_count);
  llvm_cbe_tmp__303 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__302&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__303);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1030_count);
  llvm_cbe_tmp__304 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__303))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__303));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%4, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1031_count);
  llvm_cbe_tmp__305 = (unsigned int )*llvm_cbe_tmp__304;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__305);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = trunc i32 %%5 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1032_count);
  llvm_cbe_tmp__306 = (unsigned char )((unsigned char )llvm_cbe_tmp__305&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__306);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sub i8 4, %%6, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1033_count);
  llvm_cbe_tmp__307 = (unsigned char )((unsigned char )(((unsigned char )(((unsigned char )4)&255ull)) - ((unsigned char )(llvm_cbe_tmp__306&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__307&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = or i32 %%2, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1034_count);
  llvm_cbe_tmp__308 = (unsigned int )llvm_cbe_tmp__302 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__308);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = zext i32 %%8 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1035_count);
  llvm_cbe_tmp__309 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__308&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__309);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%9, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1036_count);
  llvm_cbe_tmp__310 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__309))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__309));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i32* %%10, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1037_count);
  llvm_cbe_tmp__311 = (unsigned int )*llvm_cbe_tmp__310;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__311);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = trunc i32 %%11 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1038_count);
  llvm_cbe_tmp__312 = (unsigned char )((unsigned char )llvm_cbe_tmp__311&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__312);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sub i8 4, %%12, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1039_count);
  llvm_cbe_tmp__313 = (unsigned char )((unsigned char )(((unsigned char )(((unsigned char )4)&255ull)) - ((unsigned char )(llvm_cbe_tmp__312&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__313&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = shl i8 %%13, 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1040_count);
  llvm_cbe_tmp__314 = (unsigned char )((unsigned char )(llvm_cbe_tmp__313 << ((unsigned char )4)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__314);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = or i8 %%14, %%7, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1041_count);
  llvm_cbe_tmp__315 = (unsigned char )((unsigned char )(llvm_cbe_tmp__314 | llvm_cbe_tmp__307));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__315);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = zext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1042_count);
  llvm_cbe_tmp__316 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__316);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds i8* %%r, i64 %%16, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1043_count);
  llvm_cbe_tmp__317 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__316))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__316));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%15, i8* %%17, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1044_count);
  *llvm_cbe_tmp__317 = llvm_cbe_tmp__315;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__315);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i32 %%storemerge1, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_pack  --> \n", ++aesl_llvm_cbe_1045_count);
  llvm_cbe_tmp__318 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__318&4294967295ull)));
  if (((llvm_cbe_tmp__318&4294967295U) == (128u&4294967295U))) {
    goto llvm_cbe_tmp__320;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__318;   /* for PHI node */
    goto llvm_cbe_tmp__319;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__320:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_polyeta_pack}\n");
  return;
}


void pqcrystals_dilithium3_ref_polyeta_unpack(l_struct_OC_poly *llvm_cbe_r,  char *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_1054_count = 0;
  static  unsigned long long aesl_llvm_cbe_1055_count = 0;
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
  static  unsigned long long aesl_llvm_cbe_1058_count = 0;
  static  unsigned long long aesl_llvm_cbe_1059_count = 0;
  static  unsigned long long aesl_llvm_cbe_1060_count = 0;
  static  unsigned long long aesl_llvm_cbe_1061_count = 0;
  static  unsigned long long aesl_llvm_cbe_1062_count = 0;
  static  unsigned long long aesl_llvm_cbe_1063_count = 0;
  static  unsigned long long aesl_llvm_cbe_1064_count = 0;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
  static  unsigned long long aesl_llvm_cbe_1066_count = 0;
  static  unsigned long long aesl_llvm_cbe_1067_count = 0;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
  static  unsigned long long aesl_llvm_cbe_1070_count = 0;
  static  unsigned long long aesl_llvm_cbe_1071_count = 0;
  static  unsigned long long aesl_llvm_cbe_1072_count = 0;
  static  unsigned long long aesl_llvm_cbe_1073_count = 0;
  static  unsigned long long aesl_llvm_cbe_1074_count = 0;
  static  unsigned long long aesl_llvm_cbe_1075_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1076_count = 0;
  unsigned long long llvm_cbe_tmp__321;
  static  unsigned long long aesl_llvm_cbe_1077_count = 0;
   char *llvm_cbe_tmp__322;
  static  unsigned long long aesl_llvm_cbe_1078_count = 0;
  unsigned char llvm_cbe_tmp__323;
  static  unsigned long long aesl_llvm_cbe_1079_count = 0;
  unsigned int llvm_cbe_tmp__324;
  static  unsigned long long aesl_llvm_cbe_1080_count = 0;
  unsigned int llvm_cbe_tmp__325;
  static  unsigned long long aesl_llvm_cbe_1081_count = 0;
  unsigned int llvm_cbe_tmp__326;
  static  unsigned long long aesl_llvm_cbe_1082_count = 0;
  unsigned long long llvm_cbe_tmp__327;
  static  unsigned long long aesl_llvm_cbe_1083_count = 0;
  signed int *llvm_cbe_tmp__328;
  static  unsigned long long aesl_llvm_cbe_1084_count = 0;
  static  unsigned long long aesl_llvm_cbe_1085_count = 0;
  unsigned char llvm_cbe_tmp__329;
  static  unsigned long long aesl_llvm_cbe_1086_count = 0;
  unsigned int llvm_cbe_tmp__330;
  static  unsigned long long aesl_llvm_cbe_1087_count = 0;
  unsigned int llvm_cbe_tmp__331;
  static  unsigned long long aesl_llvm_cbe_1088_count = 0;
  unsigned int llvm_cbe_tmp__332;
  static  unsigned long long aesl_llvm_cbe_1089_count = 0;
  unsigned long long llvm_cbe_tmp__333;
  static  unsigned long long aesl_llvm_cbe_1090_count = 0;
  signed int *llvm_cbe_tmp__334;
  static  unsigned long long aesl_llvm_cbe_1091_count = 0;
  unsigned int llvm_cbe_tmp__335;
  static  unsigned long long aesl_llvm_cbe_1092_count = 0;
  static  unsigned long long aesl_llvm_cbe_1093_count = 0;
  unsigned int llvm_cbe_tmp__336;
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
  unsigned int llvm_cbe_tmp__337;
  static  unsigned long long aesl_llvm_cbe_1096_count = 0;
  static  unsigned long long aesl_llvm_cbe_1097_count = 0;
  static  unsigned long long aesl_llvm_cbe_1098_count = 0;
  static  unsigned long long aesl_llvm_cbe_1099_count = 0;
  static  unsigned long long aesl_llvm_cbe_1100_count = 0;
  static  unsigned long long aesl_llvm_cbe_1101_count = 0;
  static  unsigned long long aesl_llvm_cbe_1102_count = 0;
  static  unsigned long long aesl_llvm_cbe_1103_count = 0;
  static  unsigned long long aesl_llvm_cbe_1104_count = 0;
  static  unsigned long long aesl_llvm_cbe_1105_count = 0;
  static  unsigned long long aesl_llvm_cbe_1106_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1107_count = 0;
  static  unsigned long long aesl_llvm_cbe_1108_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_polyeta_unpack\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__338;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__338:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%18, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__337);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1076_count);
  llvm_cbe_tmp__321 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__321);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i8* %%a, i64 %%2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1077_count);
  llvm_cbe_tmp__322 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__321))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__321));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8* %%3, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1078_count);
  llvm_cbe_tmp__323 = (unsigned char )*llvm_cbe_tmp__322;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__323);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = zext i8 %%4 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1079_count);
  llvm_cbe_tmp__324 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__323&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__324);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = and i32 %%5, 15, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1080_count);
  llvm_cbe_tmp__325 = (unsigned int )llvm_cbe_tmp__324 & 15u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__325);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = shl i32 %%storemerge1, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1081_count);
  llvm_cbe_tmp__326 = (unsigned int )llvm_cbe_storemerge1 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__326);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i32 %%7 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1082_count);
  llvm_cbe_tmp__327 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__326&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__327);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1083_count);
  llvm_cbe_tmp__328 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__327))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__327));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%6, i32* %%9, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1084_count);
  *llvm_cbe_tmp__328 = llvm_cbe_tmp__325;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__325);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8* %%3, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1085_count);
  llvm_cbe_tmp__329 = (unsigned char )*llvm_cbe_tmp__322;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__329);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i8 %%10 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1086_count);
  llvm_cbe_tmp__330 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__329&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__330);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = lshr i32 %%11, 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1087_count);
  llvm_cbe_tmp__331 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__330&4294967295ull)) >> ((unsigned int )(4u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__331&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = or i32 %%7, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1088_count);
  llvm_cbe_tmp__332 = (unsigned int )llvm_cbe_tmp__326 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__332);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i32 %%13 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1089_count);
  llvm_cbe_tmp__333 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__332&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__333);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%14, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1090_count);
  llvm_cbe_tmp__334 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__333))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__333));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sub nsw i32 4, %%6, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1091_count);
  llvm_cbe_tmp__335 = (unsigned int )((unsigned int )(4u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__325&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__335&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%16, i32* %%9, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1092_count);
  *llvm_cbe_tmp__328 = llvm_cbe_tmp__335;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__335);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = sub nsw i32 4, %%12, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1093_count);
  llvm_cbe_tmp__336 = (unsigned int )((unsigned int )(4u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__331&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__336&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%17, i32* %%15, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1094_count);
  *llvm_cbe_tmp__334 = llvm_cbe_tmp__336;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__336);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i32 %%storemerge1, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyeta_unpack  --> \n", ++aesl_llvm_cbe_1095_count);
  llvm_cbe_tmp__337 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__337&4294967295ull)));
  if (((llvm_cbe_tmp__337&4294967295U) == (128u&4294967295U))) {
    goto llvm_cbe_tmp__339;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__337;   /* for PHI node */
    goto llvm_cbe_tmp__338;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__339:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_polyeta_unpack}\n");
  return;
}


void pqcrystals_dilithium3_ref_polyt1_pack( char *llvm_cbe_r, l_struct_OC_poly *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_1109_count = 0;
  static  unsigned long long aesl_llvm_cbe_1110_count = 0;
  static  unsigned long long aesl_llvm_cbe_1111_count = 0;
  static  unsigned long long aesl_llvm_cbe_1112_count = 0;
  static  unsigned long long aesl_llvm_cbe_1113_count = 0;
  static  unsigned long long aesl_llvm_cbe_1114_count = 0;
  static  unsigned long long aesl_llvm_cbe_1115_count = 0;
  static  unsigned long long aesl_llvm_cbe_1116_count = 0;
  static  unsigned long long aesl_llvm_cbe_1117_count = 0;
  static  unsigned long long aesl_llvm_cbe_1118_count = 0;
  static  unsigned long long aesl_llvm_cbe_1119_count = 0;
  static  unsigned long long aesl_llvm_cbe_1120_count = 0;
  static  unsigned long long aesl_llvm_cbe_1121_count = 0;
  static  unsigned long long aesl_llvm_cbe_1122_count = 0;
  static  unsigned long long aesl_llvm_cbe_1123_count = 0;
  static  unsigned long long aesl_llvm_cbe_1124_count = 0;
  static  unsigned long long aesl_llvm_cbe_1125_count = 0;
  static  unsigned long long aesl_llvm_cbe_1126_count = 0;
  static  unsigned long long aesl_llvm_cbe_1127_count = 0;
  static  unsigned long long aesl_llvm_cbe_1128_count = 0;
  static  unsigned long long aesl_llvm_cbe_1129_count = 0;
  static  unsigned long long aesl_llvm_cbe_1130_count = 0;
  static  unsigned long long aesl_llvm_cbe_1131_count = 0;
  static  unsigned long long aesl_llvm_cbe_1132_count = 0;
  static  unsigned long long aesl_llvm_cbe_1133_count = 0;
  static  unsigned long long aesl_llvm_cbe_1134_count = 0;
  static  unsigned long long aesl_llvm_cbe_1135_count = 0;
  static  unsigned long long aesl_llvm_cbe_1136_count = 0;
  static  unsigned long long aesl_llvm_cbe_1137_count = 0;
  static  unsigned long long aesl_llvm_cbe_1138_count = 0;
  static  unsigned long long aesl_llvm_cbe_1139_count = 0;
  static  unsigned long long aesl_llvm_cbe_1140_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1141_count = 0;
  unsigned int llvm_cbe_tmp__340;
  static  unsigned long long aesl_llvm_cbe_1142_count = 0;
  unsigned long long llvm_cbe_tmp__341;
  static  unsigned long long aesl_llvm_cbe_1143_count = 0;
  signed int *llvm_cbe_tmp__342;
  static  unsigned long long aesl_llvm_cbe_1144_count = 0;
  unsigned int llvm_cbe_tmp__343;
  static  unsigned long long aesl_llvm_cbe_1145_count = 0;
  unsigned char llvm_cbe_tmp__344;
  static  unsigned long long aesl_llvm_cbe_1146_count = 0;
  unsigned int llvm_cbe_tmp__345;
  static  unsigned long long aesl_llvm_cbe_1147_count = 0;
  unsigned long long llvm_cbe_tmp__346;
  static  unsigned long long aesl_llvm_cbe_1148_count = 0;
   char *llvm_cbe_tmp__347;
  static  unsigned long long aesl_llvm_cbe_1149_count = 0;
  static  unsigned long long aesl_llvm_cbe_1150_count = 0;
  unsigned int llvm_cbe_tmp__348;
  static  unsigned long long aesl_llvm_cbe_1151_count = 0;
  unsigned int llvm_cbe_tmp__349;
  static  unsigned long long aesl_llvm_cbe_1152_count = 0;
  unsigned int llvm_cbe_tmp__350;
  static  unsigned long long aesl_llvm_cbe_1153_count = 0;
  unsigned long long llvm_cbe_tmp__351;
  static  unsigned long long aesl_llvm_cbe_1154_count = 0;
  signed int *llvm_cbe_tmp__352;
  static  unsigned long long aesl_llvm_cbe_1155_count = 0;
  unsigned int llvm_cbe_tmp__353;
  static  unsigned long long aesl_llvm_cbe_1156_count = 0;
  unsigned int llvm_cbe_tmp__354;
  static  unsigned long long aesl_llvm_cbe_1157_count = 0;
  unsigned int llvm_cbe_tmp__355;
  static  unsigned long long aesl_llvm_cbe_1158_count = 0;
  unsigned char llvm_cbe_tmp__356;
  static  unsigned long long aesl_llvm_cbe_1159_count = 0;
  unsigned int llvm_cbe_tmp__357;
  static  unsigned long long aesl_llvm_cbe_1160_count = 0;
  unsigned long long llvm_cbe_tmp__358;
  static  unsigned long long aesl_llvm_cbe_1161_count = 0;
   char *llvm_cbe_tmp__359;
  static  unsigned long long aesl_llvm_cbe_1162_count = 0;
  static  unsigned long long aesl_llvm_cbe_1163_count = 0;
  unsigned int llvm_cbe_tmp__360;
  static  unsigned long long aesl_llvm_cbe_1164_count = 0;
  unsigned int llvm_cbe_tmp__361;
  static  unsigned long long aesl_llvm_cbe_1165_count = 0;
  unsigned int llvm_cbe_tmp__362;
  static  unsigned long long aesl_llvm_cbe_1166_count = 0;
  unsigned long long llvm_cbe_tmp__363;
  static  unsigned long long aesl_llvm_cbe_1167_count = 0;
  signed int *llvm_cbe_tmp__364;
  static  unsigned long long aesl_llvm_cbe_1168_count = 0;
  unsigned int llvm_cbe_tmp__365;
  static  unsigned long long aesl_llvm_cbe_1169_count = 0;
  unsigned int llvm_cbe_tmp__366;
  static  unsigned long long aesl_llvm_cbe_1170_count = 0;
  unsigned int llvm_cbe_tmp__367;
  static  unsigned long long aesl_llvm_cbe_1171_count = 0;
  unsigned char llvm_cbe_tmp__368;
  static  unsigned long long aesl_llvm_cbe_1172_count = 0;
  unsigned int llvm_cbe_tmp__369;
  static  unsigned long long aesl_llvm_cbe_1173_count = 0;
  unsigned long long llvm_cbe_tmp__370;
  static  unsigned long long aesl_llvm_cbe_1174_count = 0;
   char *llvm_cbe_tmp__371;
  static  unsigned long long aesl_llvm_cbe_1175_count = 0;
  static  unsigned long long aesl_llvm_cbe_1176_count = 0;
  unsigned int llvm_cbe_tmp__372;
  static  unsigned long long aesl_llvm_cbe_1177_count = 0;
  unsigned int llvm_cbe_tmp__373;
  static  unsigned long long aesl_llvm_cbe_1178_count = 0;
  unsigned int llvm_cbe_tmp__374;
  static  unsigned long long aesl_llvm_cbe_1179_count = 0;
  unsigned long long llvm_cbe_tmp__375;
  static  unsigned long long aesl_llvm_cbe_1180_count = 0;
  signed int *llvm_cbe_tmp__376;
  static  unsigned long long aesl_llvm_cbe_1181_count = 0;
  unsigned int llvm_cbe_tmp__377;
  static  unsigned long long aesl_llvm_cbe_1182_count = 0;
  unsigned int llvm_cbe_tmp__378;
  static  unsigned long long aesl_llvm_cbe_1183_count = 0;
  unsigned int llvm_cbe_tmp__379;
  static  unsigned long long aesl_llvm_cbe_1184_count = 0;
  unsigned char llvm_cbe_tmp__380;
  static  unsigned long long aesl_llvm_cbe_1185_count = 0;
  unsigned int llvm_cbe_tmp__381;
  static  unsigned long long aesl_llvm_cbe_1186_count = 0;
  unsigned long long llvm_cbe_tmp__382;
  static  unsigned long long aesl_llvm_cbe_1187_count = 0;
   char *llvm_cbe_tmp__383;
  static  unsigned long long aesl_llvm_cbe_1188_count = 0;
  static  unsigned long long aesl_llvm_cbe_1189_count = 0;
  unsigned int llvm_cbe_tmp__384;
  static  unsigned long long aesl_llvm_cbe_1190_count = 0;
  unsigned int llvm_cbe_tmp__385;
  static  unsigned long long aesl_llvm_cbe_1191_count = 0;
  unsigned char llvm_cbe_tmp__386;
  static  unsigned long long aesl_llvm_cbe_1192_count = 0;
  unsigned int llvm_cbe_tmp__387;
  static  unsigned long long aesl_llvm_cbe_1193_count = 0;
  unsigned long long llvm_cbe_tmp__388;
  static  unsigned long long aesl_llvm_cbe_1194_count = 0;
   char *llvm_cbe_tmp__389;
  static  unsigned long long aesl_llvm_cbe_1195_count = 0;
  static  unsigned long long aesl_llvm_cbe_1196_count = 0;
  unsigned int llvm_cbe_tmp__390;
  static  unsigned long long aesl_llvm_cbe_1197_count = 0;
  static  unsigned long long aesl_llvm_cbe_1198_count = 0;
  static  unsigned long long aesl_llvm_cbe_1199_count = 0;
  static  unsigned long long aesl_llvm_cbe_1200_count = 0;
  static  unsigned long long aesl_llvm_cbe_1201_count = 0;
  static  unsigned long long aesl_llvm_cbe_1202_count = 0;
  static  unsigned long long aesl_llvm_cbe_1203_count = 0;
  static  unsigned long long aesl_llvm_cbe_1204_count = 0;
  static  unsigned long long aesl_llvm_cbe_1205_count = 0;
  static  unsigned long long aesl_llvm_cbe_1206_count = 0;
  static  unsigned long long aesl_llvm_cbe_1207_count = 0;
  static  unsigned long long aesl_llvm_cbe_1208_count = 0;
  static  unsigned long long aesl_llvm_cbe_1209_count = 0;
  static  unsigned long long aesl_llvm_cbe_1210_count = 0;
  static  unsigned long long aesl_llvm_cbe_1211_count = 0;
  static  unsigned long long aesl_llvm_cbe_1212_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1213_count = 0;
  static  unsigned long long aesl_llvm_cbe_1214_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_polyt1_pack\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__391;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__391:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%52, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__390);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = shl i32 %%storemerge1, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1141_count);
  llvm_cbe_tmp__340 = (unsigned int )llvm_cbe_storemerge1 << 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__340);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1142_count);
  llvm_cbe_tmp__341 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__340&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__341);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1143_count);
  llvm_cbe_tmp__342 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__341))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__341));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%4, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1144_count);
  llvm_cbe_tmp__343 = (unsigned int )*llvm_cbe_tmp__342;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__343);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = trunc i32 %%5 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1145_count);
  llvm_cbe_tmp__344 = (unsigned char )((unsigned char )llvm_cbe_tmp__343&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__344);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = mul i32 %%storemerge1, 5, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1146_count);
  llvm_cbe_tmp__345 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) * ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__345&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i32 %%7 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1147_count);
  llvm_cbe_tmp__346 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__345&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__346);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds i8* %%r, i64 %%8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1148_count);
  llvm_cbe_tmp__347 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__346))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__346));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%6, i8* %%9, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1149_count);
  *llvm_cbe_tmp__347 = llvm_cbe_tmp__344;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__344);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i32* %%4, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1150_count);
  llvm_cbe_tmp__348 = (unsigned int )*llvm_cbe_tmp__342;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__348);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = lshr i32 %%10, 8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1151_count);
  llvm_cbe_tmp__349 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__348&4294967295ull)) >> ((unsigned int )(8u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__349&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = or i32 %%2, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1152_count);
  llvm_cbe_tmp__350 = (unsigned int )llvm_cbe_tmp__340 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__350);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = zext i32 %%12 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1153_count);
  llvm_cbe_tmp__351 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__350&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__351);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%13, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1154_count);
  llvm_cbe_tmp__352 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__351))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__351));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* %%14, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1155_count);
  llvm_cbe_tmp__353 = (unsigned int )*llvm_cbe_tmp__352;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__353);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = shl i32 %%15, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1156_count);
  llvm_cbe_tmp__354 = (unsigned int )llvm_cbe_tmp__353 << 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__354);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = or i32 %%16, %%11, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1157_count);
  llvm_cbe_tmp__355 = (unsigned int )llvm_cbe_tmp__354 | llvm_cbe_tmp__349;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__355);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = trunc i32 %%17 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1158_count);
  llvm_cbe_tmp__356 = (unsigned char )((unsigned char )llvm_cbe_tmp__355&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__356);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i32 %%7, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1159_count);
  llvm_cbe_tmp__357 = (unsigned int )((unsigned int )(llvm_cbe_tmp__345&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__357&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = zext i32 %%19 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1160_count);
  llvm_cbe_tmp__358 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__357&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__358);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds i8* %%r, i64 %%20, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1161_count);
  llvm_cbe_tmp__359 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__358))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__358));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%18, i8* %%21, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1162_count);
  *llvm_cbe_tmp__359 = llvm_cbe_tmp__356;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__356);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i32* %%14, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1163_count);
  llvm_cbe_tmp__360 = (unsigned int )*llvm_cbe_tmp__352;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__360);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = lshr i32 %%22, 6, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1164_count);
  llvm_cbe_tmp__361 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__360&4294967295ull)) >> ((unsigned int )(6u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__361&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = or i32 %%2, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1165_count);
  llvm_cbe_tmp__362 = (unsigned int )llvm_cbe_tmp__340 | 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__362);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = zext i32 %%24 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1166_count);
  llvm_cbe_tmp__363 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__362&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__363);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%25, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1167_count);
  llvm_cbe_tmp__364 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__363))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__363));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i32* %%26, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1168_count);
  llvm_cbe_tmp__365 = (unsigned int )*llvm_cbe_tmp__364;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__365);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = shl i32 %%27, 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1169_count);
  llvm_cbe_tmp__366 = (unsigned int )llvm_cbe_tmp__365 << 4u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__366);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = or i32 %%28, %%23, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1170_count);
  llvm_cbe_tmp__367 = (unsigned int )llvm_cbe_tmp__366 | llvm_cbe_tmp__361;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__367);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = trunc i32 %%29 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1171_count);
  llvm_cbe_tmp__368 = (unsigned char )((unsigned char )llvm_cbe_tmp__367&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__368);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add i32 %%7, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1172_count);
  llvm_cbe_tmp__369 = (unsigned int )((unsigned int )(llvm_cbe_tmp__345&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__369&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = zext i32 %%31 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1173_count);
  llvm_cbe_tmp__370 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__369&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__370);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds i8* %%r, i64 %%32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1174_count);
  llvm_cbe_tmp__371 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__370))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__370));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%30, i8* %%33, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1175_count);
  *llvm_cbe_tmp__371 = llvm_cbe_tmp__368;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__368);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i32* %%26, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1176_count);
  llvm_cbe_tmp__372 = (unsigned int )*llvm_cbe_tmp__364;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__372);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = lshr i32 %%34, 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1177_count);
  llvm_cbe_tmp__373 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__372&4294967295ull)) >> ((unsigned int )(4u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__373&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = or i32 %%2, 3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1178_count);
  llvm_cbe_tmp__374 = (unsigned int )llvm_cbe_tmp__340 | 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__374);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = zext i32 %%36 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1179_count);
  llvm_cbe_tmp__375 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__374&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__375);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%37, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1180_count);
  llvm_cbe_tmp__376 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__375))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__375));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i32* %%38, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1181_count);
  llvm_cbe_tmp__377 = (unsigned int )*llvm_cbe_tmp__376;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__377);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = shl i32 %%39, 6, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1182_count);
  llvm_cbe_tmp__378 = (unsigned int )llvm_cbe_tmp__377 << 6u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__378);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = or i32 %%40, %%35, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1183_count);
  llvm_cbe_tmp__379 = (unsigned int )llvm_cbe_tmp__378 | llvm_cbe_tmp__373;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__379);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = trunc i32 %%41 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1184_count);
  llvm_cbe_tmp__380 = (unsigned char )((unsigned char )llvm_cbe_tmp__379&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__380);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = add i32 %%7, 3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1185_count);
  llvm_cbe_tmp__381 = (unsigned int )((unsigned int )(llvm_cbe_tmp__345&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__381&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = zext i32 %%43 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1186_count);
  llvm_cbe_tmp__382 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__381&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__382);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds i8* %%r, i64 %%44, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1187_count);
  llvm_cbe_tmp__383 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__382))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__382));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%42, i8* %%45, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1188_count);
  *llvm_cbe_tmp__383 = llvm_cbe_tmp__380;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__380);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load i32* %%38, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1189_count);
  llvm_cbe_tmp__384 = (unsigned int )*llvm_cbe_tmp__376;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__384);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = lshr i32 %%46, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1190_count);
  llvm_cbe_tmp__385 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__384&4294967295ull)) >> ((unsigned int )(2u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__385&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = trunc i32 %%47 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1191_count);
  llvm_cbe_tmp__386 = (unsigned char )((unsigned char )llvm_cbe_tmp__385&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__386);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add i32 %%7, 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1192_count);
  llvm_cbe_tmp__387 = (unsigned int )((unsigned int )(llvm_cbe_tmp__345&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__387&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = zext i32 %%49 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1193_count);
  llvm_cbe_tmp__388 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__387&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__388);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds i8* %%r, i64 %%50, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1194_count);
  llvm_cbe_tmp__389 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__388))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__388));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%48, i8* %%51, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1195_count);
  *llvm_cbe_tmp__389 = llvm_cbe_tmp__386;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__386);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = add i32 %%storemerge1, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_pack  --> \n", ++aesl_llvm_cbe_1196_count);
  llvm_cbe_tmp__390 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__390&4294967295ull)));
  if (((llvm_cbe_tmp__390&4294967295U) == (64u&4294967295U))) {
    goto llvm_cbe_tmp__392;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__390;   /* for PHI node */
    goto llvm_cbe_tmp__391;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__392:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_polyt1_pack}\n");
  return;
}


void pqcrystals_dilithium3_ref_polyt1_unpack(l_struct_OC_poly *llvm_cbe_r,  char *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_1215_count = 0;
  static  unsigned long long aesl_llvm_cbe_1216_count = 0;
  static  unsigned long long aesl_llvm_cbe_1217_count = 0;
  static  unsigned long long aesl_llvm_cbe_1218_count = 0;
  static  unsigned long long aesl_llvm_cbe_1219_count = 0;
  static  unsigned long long aesl_llvm_cbe_1220_count = 0;
  static  unsigned long long aesl_llvm_cbe_1221_count = 0;
  static  unsigned long long aesl_llvm_cbe_1222_count = 0;
  static  unsigned long long aesl_llvm_cbe_1223_count = 0;
  static  unsigned long long aesl_llvm_cbe_1224_count = 0;
  static  unsigned long long aesl_llvm_cbe_1225_count = 0;
  static  unsigned long long aesl_llvm_cbe_1226_count = 0;
  static  unsigned long long aesl_llvm_cbe_1227_count = 0;
  static  unsigned long long aesl_llvm_cbe_1228_count = 0;
  static  unsigned long long aesl_llvm_cbe_1229_count = 0;
  static  unsigned long long aesl_llvm_cbe_1230_count = 0;
  static  unsigned long long aesl_llvm_cbe_1231_count = 0;
  static  unsigned long long aesl_llvm_cbe_1232_count = 0;
  static  unsigned long long aesl_llvm_cbe_1233_count = 0;
  static  unsigned long long aesl_llvm_cbe_1234_count = 0;
  static  unsigned long long aesl_llvm_cbe_1235_count = 0;
  static  unsigned long long aesl_llvm_cbe_1236_count = 0;
  static  unsigned long long aesl_llvm_cbe_1237_count = 0;
  static  unsigned long long aesl_llvm_cbe_1238_count = 0;
  static  unsigned long long aesl_llvm_cbe_1239_count = 0;
  static  unsigned long long aesl_llvm_cbe_1240_count = 0;
  static  unsigned long long aesl_llvm_cbe_1241_count = 0;
  static  unsigned long long aesl_llvm_cbe_1242_count = 0;
  static  unsigned long long aesl_llvm_cbe_1243_count = 0;
  static  unsigned long long aesl_llvm_cbe_1244_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1245_count = 0;
  unsigned int llvm_cbe_tmp__393;
  static  unsigned long long aesl_llvm_cbe_1246_count = 0;
  unsigned long long llvm_cbe_tmp__394;
  static  unsigned long long aesl_llvm_cbe_1247_count = 0;
   char *llvm_cbe_tmp__395;
  static  unsigned long long aesl_llvm_cbe_1248_count = 0;
  unsigned char llvm_cbe_tmp__396;
  static  unsigned long long aesl_llvm_cbe_1249_count = 0;
  unsigned int llvm_cbe_tmp__397;
  static  unsigned long long aesl_llvm_cbe_1250_count = 0;
  unsigned int llvm_cbe_tmp__398;
  static  unsigned long long aesl_llvm_cbe_1251_count = 0;
  unsigned long long llvm_cbe_tmp__399;
  static  unsigned long long aesl_llvm_cbe_1252_count = 0;
   char *llvm_cbe_tmp__400;
  static  unsigned long long aesl_llvm_cbe_1253_count = 0;
  unsigned char llvm_cbe_tmp__401;
  static  unsigned long long aesl_llvm_cbe_1254_count = 0;
  unsigned int llvm_cbe_tmp__402;
  static  unsigned long long aesl_llvm_cbe_1255_count = 0;
  unsigned int llvm_cbe_tmp__403;
  static  unsigned long long aesl_llvm_cbe_1256_count = 0;
  unsigned int llvm_cbe_tmp__404;
  static  unsigned long long aesl_llvm_cbe_1257_count = 0;
  unsigned int llvm_cbe_tmp__405;
  static  unsigned long long aesl_llvm_cbe_1258_count = 0;
  unsigned int llvm_cbe_tmp__406;
  static  unsigned long long aesl_llvm_cbe_1259_count = 0;
  unsigned long long llvm_cbe_tmp__407;
  static  unsigned long long aesl_llvm_cbe_1260_count = 0;
  signed int *llvm_cbe_tmp__408;
  static  unsigned long long aesl_llvm_cbe_1261_count = 0;
  static  unsigned long long aesl_llvm_cbe_1262_count = 0;
  unsigned char llvm_cbe_tmp__409;
  static  unsigned long long aesl_llvm_cbe_1263_count = 0;
  unsigned int llvm_cbe_tmp__410;
  static  unsigned long long aesl_llvm_cbe_1264_count = 0;
  unsigned int llvm_cbe_tmp__411;
  static  unsigned long long aesl_llvm_cbe_1265_count = 0;
  unsigned int llvm_cbe_tmp__412;
  static  unsigned long long aesl_llvm_cbe_1266_count = 0;
  unsigned long long llvm_cbe_tmp__413;
  static  unsigned long long aesl_llvm_cbe_1267_count = 0;
   char *llvm_cbe_tmp__414;
  static  unsigned long long aesl_llvm_cbe_1268_count = 0;
  unsigned char llvm_cbe_tmp__415;
  static  unsigned long long aesl_llvm_cbe_1269_count = 0;
  unsigned int llvm_cbe_tmp__416;
  static  unsigned long long aesl_llvm_cbe_1270_count = 0;
  unsigned int llvm_cbe_tmp__417;
  static  unsigned long long aesl_llvm_cbe_1271_count = 0;
  unsigned int llvm_cbe_tmp__418;
  static  unsigned long long aesl_llvm_cbe_1272_count = 0;
  unsigned int llvm_cbe_tmp__419;
  static  unsigned long long aesl_llvm_cbe_1273_count = 0;
  unsigned int llvm_cbe_tmp__420;
  static  unsigned long long aesl_llvm_cbe_1274_count = 0;
  unsigned long long llvm_cbe_tmp__421;
  static  unsigned long long aesl_llvm_cbe_1275_count = 0;
  signed int *llvm_cbe_tmp__422;
  static  unsigned long long aesl_llvm_cbe_1276_count = 0;
  static  unsigned long long aesl_llvm_cbe_1277_count = 0;
  unsigned char llvm_cbe_tmp__423;
  static  unsigned long long aesl_llvm_cbe_1278_count = 0;
  unsigned int llvm_cbe_tmp__424;
  static  unsigned long long aesl_llvm_cbe_1279_count = 0;
  unsigned int llvm_cbe_tmp__425;
  static  unsigned long long aesl_llvm_cbe_1280_count = 0;
  unsigned int llvm_cbe_tmp__426;
  static  unsigned long long aesl_llvm_cbe_1281_count = 0;
  unsigned long long llvm_cbe_tmp__427;
  static  unsigned long long aesl_llvm_cbe_1282_count = 0;
   char *llvm_cbe_tmp__428;
  static  unsigned long long aesl_llvm_cbe_1283_count = 0;
  unsigned char llvm_cbe_tmp__429;
  static  unsigned long long aesl_llvm_cbe_1284_count = 0;
  unsigned int llvm_cbe_tmp__430;
  static  unsigned long long aesl_llvm_cbe_1285_count = 0;
  unsigned int llvm_cbe_tmp__431;
  static  unsigned long long aesl_llvm_cbe_1286_count = 0;
  unsigned int llvm_cbe_tmp__432;
  static  unsigned long long aesl_llvm_cbe_1287_count = 0;
  unsigned int llvm_cbe_tmp__433;
  static  unsigned long long aesl_llvm_cbe_1288_count = 0;
  unsigned int llvm_cbe_tmp__434;
  static  unsigned long long aesl_llvm_cbe_1289_count = 0;
  unsigned long long llvm_cbe_tmp__435;
  static  unsigned long long aesl_llvm_cbe_1290_count = 0;
  signed int *llvm_cbe_tmp__436;
  static  unsigned long long aesl_llvm_cbe_1291_count = 0;
  static  unsigned long long aesl_llvm_cbe_1292_count = 0;
  unsigned char llvm_cbe_tmp__437;
  static  unsigned long long aesl_llvm_cbe_1293_count = 0;
  unsigned int llvm_cbe_tmp__438;
  static  unsigned long long aesl_llvm_cbe_1294_count = 0;
  unsigned int llvm_cbe_tmp__439;
  static  unsigned long long aesl_llvm_cbe_1295_count = 0;
  unsigned int llvm_cbe_tmp__440;
  static  unsigned long long aesl_llvm_cbe_1296_count = 0;
  unsigned long long llvm_cbe_tmp__441;
  static  unsigned long long aesl_llvm_cbe_1297_count = 0;
   char *llvm_cbe_tmp__442;
  static  unsigned long long aesl_llvm_cbe_1298_count = 0;
  unsigned char llvm_cbe_tmp__443;
  static  unsigned long long aesl_llvm_cbe_1299_count = 0;
  unsigned int llvm_cbe_tmp__444;
  static  unsigned long long aesl_llvm_cbe_1300_count = 0;
  unsigned int llvm_cbe_tmp__445;
  static  unsigned long long aesl_llvm_cbe_1301_count = 0;
  unsigned int llvm_cbe_tmp__446;
  static  unsigned long long aesl_llvm_cbe_1302_count = 0;
  unsigned int llvm_cbe_tmp__447;
  static  unsigned long long aesl_llvm_cbe_1303_count = 0;
  unsigned long long llvm_cbe_tmp__448;
  static  unsigned long long aesl_llvm_cbe_1304_count = 0;
  signed int *llvm_cbe_tmp__449;
  static  unsigned long long aesl_llvm_cbe_1305_count = 0;
  static  unsigned long long aesl_llvm_cbe_1306_count = 0;
  unsigned int llvm_cbe_tmp__450;
  static  unsigned long long aesl_llvm_cbe_1307_count = 0;
  static  unsigned long long aesl_llvm_cbe_1308_count = 0;
  static  unsigned long long aesl_llvm_cbe_1309_count = 0;
  static  unsigned long long aesl_llvm_cbe_1310_count = 0;
  static  unsigned long long aesl_llvm_cbe_1311_count = 0;
  static  unsigned long long aesl_llvm_cbe_1312_count = 0;
  static  unsigned long long aesl_llvm_cbe_1313_count = 0;
  static  unsigned long long aesl_llvm_cbe_1314_count = 0;
  static  unsigned long long aesl_llvm_cbe_1315_count = 0;
  static  unsigned long long aesl_llvm_cbe_1316_count = 0;
  static  unsigned long long aesl_llvm_cbe_1317_count = 0;
  static  unsigned long long aesl_llvm_cbe_1318_count = 0;
  static  unsigned long long aesl_llvm_cbe_1319_count = 0;
  static  unsigned long long aesl_llvm_cbe_1320_count = 0;
  static  unsigned long long aesl_llvm_cbe_1321_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1322_count = 0;
  static  unsigned long long aesl_llvm_cbe_1323_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_polyt1_unpack\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__451;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__451:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%59, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__450);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = mul i32 %%storemerge1, 5, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1245_count);
  llvm_cbe_tmp__393 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) * ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__393&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1246_count);
  llvm_cbe_tmp__394 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__393&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__394);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i8* %%a, i64 %%3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1247_count);
  llvm_cbe_tmp__395 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__394))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__394));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i8* %%4, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1248_count);
  llvm_cbe_tmp__396 = (unsigned char )*llvm_cbe_tmp__395;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__396);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i8 %%5 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1249_count);
  llvm_cbe_tmp__397 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__396&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__397);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i32 %%2, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1250_count);
  llvm_cbe_tmp__398 = (unsigned int )((unsigned int )(llvm_cbe_tmp__393&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__398&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i32 %%7 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1251_count);
  llvm_cbe_tmp__399 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__398&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__399);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds i8* %%a, i64 %%8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1252_count);
  llvm_cbe_tmp__400 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__399))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__399));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8* %%9, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1253_count);
  llvm_cbe_tmp__401 = (unsigned char )*llvm_cbe_tmp__400;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__401);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i8 %%10 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1254_count);
  llvm_cbe_tmp__402 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__401&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__402);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = shl nuw nsw i32 %%11, 8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1255_count);
  llvm_cbe_tmp__403 = (unsigned int )llvm_cbe_tmp__402 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__403);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = and i32 %%12, 768, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1256_count);
  llvm_cbe_tmp__404 = (unsigned int )llvm_cbe_tmp__403 & 768u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__404);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = or i32 %%13, %%6, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1257_count);
  llvm_cbe_tmp__405 = (unsigned int )llvm_cbe_tmp__404 | llvm_cbe_tmp__397;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__405);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = shl i32 %%storemerge1, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1258_count);
  llvm_cbe_tmp__406 = (unsigned int )llvm_cbe_storemerge1 << 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__406);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = zext i32 %%15 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1259_count);
  llvm_cbe_tmp__407 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__406&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__407);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%16, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1260_count);
  llvm_cbe_tmp__408 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__407))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__407));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%14, i32* %%17, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1261_count);
  *llvm_cbe_tmp__408 = llvm_cbe_tmp__405;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__405);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i8* %%9, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1262_count);
  llvm_cbe_tmp__409 = (unsigned char )*llvm_cbe_tmp__400;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__409);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = zext i8 %%18 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1263_count);
  llvm_cbe_tmp__410 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__409&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__410);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = lshr i32 %%19, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1264_count);
  llvm_cbe_tmp__411 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__410&4294967295ull)) >> ((unsigned int )(2u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__411&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add i32 %%2, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1265_count);
  llvm_cbe_tmp__412 = (unsigned int )((unsigned int )(llvm_cbe_tmp__393&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__412&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = zext i32 %%21 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1266_count);
  llvm_cbe_tmp__413 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__412&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__413);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds i8* %%a, i64 %%22, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1267_count);
  llvm_cbe_tmp__414 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__413))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__413));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i8* %%23, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1268_count);
  llvm_cbe_tmp__415 = (unsigned char )*llvm_cbe_tmp__414;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__415);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = zext i8 %%24 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1269_count);
  llvm_cbe_tmp__416 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__415&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__416);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = shl nuw nsw i32 %%25, 6, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1270_count);
  llvm_cbe_tmp__417 = (unsigned int )llvm_cbe_tmp__416 << 6u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__417);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = and i32 %%26, 960, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1271_count);
  llvm_cbe_tmp__418 = (unsigned int )llvm_cbe_tmp__417 & 960u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__418);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = or i32 %%27, %%20, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1272_count);
  llvm_cbe_tmp__419 = (unsigned int )llvm_cbe_tmp__418 | llvm_cbe_tmp__411;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__419);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = or i32 %%15, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1273_count);
  llvm_cbe_tmp__420 = (unsigned int )llvm_cbe_tmp__406 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__420);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = zext i32 %%29 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1274_count);
  llvm_cbe_tmp__421 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__420&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__421);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%30, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1275_count);
  llvm_cbe_tmp__422 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__421))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__421));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%28, i32* %%31, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1276_count);
  *llvm_cbe_tmp__422 = llvm_cbe_tmp__419;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__419);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load i8* %%23, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1277_count);
  llvm_cbe_tmp__423 = (unsigned char )*llvm_cbe_tmp__414;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__423);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = zext i8 %%32 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1278_count);
  llvm_cbe_tmp__424 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__423&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__424);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = lshr i32 %%33, 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1279_count);
  llvm_cbe_tmp__425 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__424&4294967295ull)) >> ((unsigned int )(4u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__425&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = add i32 %%2, 3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1280_count);
  llvm_cbe_tmp__426 = (unsigned int )((unsigned int )(llvm_cbe_tmp__393&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__426&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = zext i32 %%35 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1281_count);
  llvm_cbe_tmp__427 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__426&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__427);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds i8* %%a, i64 %%36, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1282_count);
  llvm_cbe_tmp__428 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__427))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__427));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i8* %%37, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1283_count);
  llvm_cbe_tmp__429 = (unsigned char )*llvm_cbe_tmp__428;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__429);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = zext i8 %%38 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1284_count);
  llvm_cbe_tmp__430 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__429&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__430);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = shl nuw nsw i32 %%39, 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1285_count);
  llvm_cbe_tmp__431 = (unsigned int )llvm_cbe_tmp__430 << 4u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__431);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = and i32 %%40, 1008, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1286_count);
  llvm_cbe_tmp__432 = (unsigned int )llvm_cbe_tmp__431 & 1008u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__432);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = or i32 %%41, %%34, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1287_count);
  llvm_cbe_tmp__433 = (unsigned int )llvm_cbe_tmp__432 | llvm_cbe_tmp__425;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__433);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = or i32 %%15, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1288_count);
  llvm_cbe_tmp__434 = (unsigned int )llvm_cbe_tmp__406 | 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__434);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = zext i32 %%43 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1289_count);
  llvm_cbe_tmp__435 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__434&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__435);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%44, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1290_count);
  llvm_cbe_tmp__436 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__435))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__435));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%42, i32* %%45, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1291_count);
  *llvm_cbe_tmp__436 = llvm_cbe_tmp__433;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__433);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load i8* %%37, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1292_count);
  llvm_cbe_tmp__437 = (unsigned char )*llvm_cbe_tmp__428;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__437);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = zext i8 %%46 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1293_count);
  llvm_cbe_tmp__438 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__437&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__438);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = lshr i32 %%47, 6, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1294_count);
  llvm_cbe_tmp__439 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__438&4294967295ull)) >> ((unsigned int )(6u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__439&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add i32 %%2, 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1295_count);
  llvm_cbe_tmp__440 = (unsigned int )((unsigned int )(llvm_cbe_tmp__393&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__440&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = zext i32 %%49 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1296_count);
  llvm_cbe_tmp__441 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__440&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__441);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds i8* %%a, i64 %%50, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1297_count);
  llvm_cbe_tmp__442 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__441))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__441));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load i8* %%51, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1298_count);
  llvm_cbe_tmp__443 = (unsigned char )*llvm_cbe_tmp__442;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__443);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = zext i8 %%52 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1299_count);
  llvm_cbe_tmp__444 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__443&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__444);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = shl nuw nsw i32 %%53, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1300_count);
  llvm_cbe_tmp__445 = (unsigned int )llvm_cbe_tmp__444 << 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__445);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = or i32 %%54, %%48, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1301_count);
  llvm_cbe_tmp__446 = (unsigned int )llvm_cbe_tmp__445 | llvm_cbe_tmp__439;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__446);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = or i32 %%15, 3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1302_count);
  llvm_cbe_tmp__447 = (unsigned int )llvm_cbe_tmp__406 | 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__447);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = zext i32 %%56 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1303_count);
  llvm_cbe_tmp__448 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__447&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__448);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%57, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1304_count);
  llvm_cbe_tmp__449 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__448))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__448));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%55, i32* %%58, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1305_count);
  *llvm_cbe_tmp__449 = llvm_cbe_tmp__446;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__446);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add i32 %%storemerge1, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt1_unpack  --> \n", ++aesl_llvm_cbe_1306_count);
  llvm_cbe_tmp__450 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__450&4294967295ull)));
  if (((llvm_cbe_tmp__450&4294967295U) == (64u&4294967295U))) {
    goto llvm_cbe_tmp__452;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__450;   /* for PHI node */
    goto llvm_cbe_tmp__451;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__452:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_polyt1_unpack}\n");
  return;
}


void pqcrystals_dilithium3_ref_polyt0_pack( char *llvm_cbe_r, l_struct_OC_poly *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_1324_count = 0;
  static  unsigned long long aesl_llvm_cbe_1325_count = 0;
  static  unsigned long long aesl_llvm_cbe_1326_count = 0;
  static  unsigned long long aesl_llvm_cbe_1327_count = 0;
  static  unsigned long long aesl_llvm_cbe_1328_count = 0;
  static  unsigned long long aesl_llvm_cbe_1329_count = 0;
  static  unsigned long long aesl_llvm_cbe_1330_count = 0;
  static  unsigned long long aesl_llvm_cbe_1331_count = 0;
  static  unsigned long long aesl_llvm_cbe_1332_count = 0;
  static  unsigned long long aesl_llvm_cbe_1333_count = 0;
  static  unsigned long long aesl_llvm_cbe_1334_count = 0;
  static  unsigned long long aesl_llvm_cbe_1335_count = 0;
  static  unsigned long long aesl_llvm_cbe_1336_count = 0;
  static  unsigned long long aesl_llvm_cbe_1337_count = 0;
  static  unsigned long long aesl_llvm_cbe_1338_count = 0;
  static  unsigned long long aesl_llvm_cbe_1339_count = 0;
  static  unsigned long long aesl_llvm_cbe_1340_count = 0;
  static  unsigned long long aesl_llvm_cbe_1341_count = 0;
  static  unsigned long long aesl_llvm_cbe_1342_count = 0;
  static  unsigned long long aesl_llvm_cbe_1343_count = 0;
  static  unsigned long long aesl_llvm_cbe_1344_count = 0;
  static  unsigned long long aesl_llvm_cbe_1345_count = 0;
  static  unsigned long long aesl_llvm_cbe_1346_count = 0;
  static  unsigned long long aesl_llvm_cbe_1347_count = 0;
  static  unsigned long long aesl_llvm_cbe_1348_count = 0;
  static  unsigned long long aesl_llvm_cbe_1349_count = 0;
  static  unsigned long long aesl_llvm_cbe_1350_count = 0;
  static  unsigned long long aesl_llvm_cbe_1351_count = 0;
  static  unsigned long long aesl_llvm_cbe_1352_count = 0;
  static  unsigned long long aesl_llvm_cbe_1353_count = 0;
  static  unsigned long long aesl_llvm_cbe_1354_count = 0;
  static  unsigned long long aesl_llvm_cbe_1355_count = 0;
  static  unsigned long long aesl_llvm_cbe_1356_count = 0;
  static  unsigned long long aesl_llvm_cbe_1357_count = 0;
  static  unsigned long long aesl_llvm_cbe_1358_count = 0;
  static  unsigned long long aesl_llvm_cbe_1359_count = 0;
  static  unsigned long long aesl_llvm_cbe_1360_count = 0;
  static  unsigned long long aesl_llvm_cbe_1361_count = 0;
  static  unsigned long long aesl_llvm_cbe_1362_count = 0;
  static  unsigned long long aesl_llvm_cbe_1363_count = 0;
  static  unsigned long long aesl_llvm_cbe_1364_count = 0;
  static  unsigned long long aesl_llvm_cbe_1365_count = 0;
  static  unsigned long long aesl_llvm_cbe_1366_count = 0;
  static  unsigned long long aesl_llvm_cbe_1367_count = 0;
  static  unsigned long long aesl_llvm_cbe_1368_count = 0;
  static  unsigned long long aesl_llvm_cbe_1369_count = 0;
  static  unsigned long long aesl_llvm_cbe_1370_count = 0;
  static  unsigned long long aesl_llvm_cbe_1371_count = 0;
  static  unsigned long long aesl_llvm_cbe_1372_count = 0;
  static  unsigned long long aesl_llvm_cbe_1373_count = 0;
  static  unsigned long long aesl_llvm_cbe_1374_count = 0;
  static  unsigned long long aesl_llvm_cbe_1375_count = 0;
  static  unsigned long long aesl_llvm_cbe_1376_count = 0;
  static  unsigned long long aesl_llvm_cbe_1377_count = 0;
  static  unsigned long long aesl_llvm_cbe_1378_count = 0;
  static  unsigned long long aesl_llvm_cbe_1379_count = 0;
  static  unsigned long long aesl_llvm_cbe_1380_count = 0;
  static  unsigned long long aesl_llvm_cbe_1381_count = 0;
  static  unsigned long long aesl_llvm_cbe_1382_count = 0;
  static  unsigned long long aesl_llvm_cbe_1383_count = 0;
  static  unsigned long long aesl_llvm_cbe_1384_count = 0;
  static  unsigned long long aesl_llvm_cbe_1385_count = 0;
  static  unsigned long long aesl_llvm_cbe_1386_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1387_count = 0;
  unsigned int llvm_cbe_tmp__453;
  static  unsigned long long aesl_llvm_cbe_1388_count = 0;
  unsigned long long llvm_cbe_tmp__454;
  static  unsigned long long aesl_llvm_cbe_1389_count = 0;
  signed int *llvm_cbe_tmp__455;
  static  unsigned long long aesl_llvm_cbe_1390_count = 0;
  unsigned int llvm_cbe_tmp__456;
  static  unsigned long long aesl_llvm_cbe_1391_count = 0;
  unsigned int llvm_cbe_tmp__457;
  static  unsigned long long aesl_llvm_cbe_1392_count = 0;
  unsigned int llvm_cbe_tmp__458;
  static  unsigned long long aesl_llvm_cbe_1393_count = 0;
  unsigned long long llvm_cbe_tmp__459;
  static  unsigned long long aesl_llvm_cbe_1394_count = 0;
  signed int *llvm_cbe_tmp__460;
  static  unsigned long long aesl_llvm_cbe_1395_count = 0;
  unsigned int llvm_cbe_tmp__461;
  static  unsigned long long aesl_llvm_cbe_1396_count = 0;
  unsigned int llvm_cbe_tmp__462;
  static  unsigned long long aesl_llvm_cbe_1397_count = 0;
  unsigned int llvm_cbe_tmp__463;
  static  unsigned long long aesl_llvm_cbe_1398_count = 0;
  unsigned long long llvm_cbe_tmp__464;
  static  unsigned long long aesl_llvm_cbe_1399_count = 0;
  signed int *llvm_cbe_tmp__465;
  static  unsigned long long aesl_llvm_cbe_1400_count = 0;
  unsigned int llvm_cbe_tmp__466;
  static  unsigned long long aesl_llvm_cbe_1401_count = 0;
  unsigned int llvm_cbe_tmp__467;
  static  unsigned long long aesl_llvm_cbe_1402_count = 0;
  unsigned int llvm_cbe_tmp__468;
  static  unsigned long long aesl_llvm_cbe_1403_count = 0;
  unsigned long long llvm_cbe_tmp__469;
  static  unsigned long long aesl_llvm_cbe_1404_count = 0;
  signed int *llvm_cbe_tmp__470;
  static  unsigned long long aesl_llvm_cbe_1405_count = 0;
  unsigned int llvm_cbe_tmp__471;
  static  unsigned long long aesl_llvm_cbe_1406_count = 0;
  unsigned int llvm_cbe_tmp__472;
  static  unsigned long long aesl_llvm_cbe_1407_count = 0;
  unsigned int llvm_cbe_tmp__473;
  static  unsigned long long aesl_llvm_cbe_1408_count = 0;
  unsigned long long llvm_cbe_tmp__474;
  static  unsigned long long aesl_llvm_cbe_1409_count = 0;
  signed int *llvm_cbe_tmp__475;
  static  unsigned long long aesl_llvm_cbe_1410_count = 0;
  unsigned int llvm_cbe_tmp__476;
  static  unsigned long long aesl_llvm_cbe_1411_count = 0;
  unsigned int llvm_cbe_tmp__477;
  static  unsigned long long aesl_llvm_cbe_1412_count = 0;
  unsigned int llvm_cbe_tmp__478;
  static  unsigned long long aesl_llvm_cbe_1413_count = 0;
  unsigned long long llvm_cbe_tmp__479;
  static  unsigned long long aesl_llvm_cbe_1414_count = 0;
  signed int *llvm_cbe_tmp__480;
  static  unsigned long long aesl_llvm_cbe_1415_count = 0;
  unsigned int llvm_cbe_tmp__481;
  static  unsigned long long aesl_llvm_cbe_1416_count = 0;
  unsigned int llvm_cbe_tmp__482;
  static  unsigned long long aesl_llvm_cbe_1417_count = 0;
  unsigned int llvm_cbe_tmp__483;
  static  unsigned long long aesl_llvm_cbe_1418_count = 0;
  unsigned long long llvm_cbe_tmp__484;
  static  unsigned long long aesl_llvm_cbe_1419_count = 0;
  signed int *llvm_cbe_tmp__485;
  static  unsigned long long aesl_llvm_cbe_1420_count = 0;
  unsigned int llvm_cbe_tmp__486;
  static  unsigned long long aesl_llvm_cbe_1421_count = 0;
  unsigned int llvm_cbe_tmp__487;
  static  unsigned long long aesl_llvm_cbe_1422_count = 0;
  unsigned int llvm_cbe_tmp__488;
  static  unsigned long long aesl_llvm_cbe_1423_count = 0;
  unsigned long long llvm_cbe_tmp__489;
  static  unsigned long long aesl_llvm_cbe_1424_count = 0;
  signed int *llvm_cbe_tmp__490;
  static  unsigned long long aesl_llvm_cbe_1425_count = 0;
  unsigned int llvm_cbe_tmp__491;
  static  unsigned long long aesl_llvm_cbe_1426_count = 0;
  unsigned int llvm_cbe_tmp__492;
  static  unsigned long long aesl_llvm_cbe_1427_count = 0;
  unsigned char llvm_cbe_tmp__493;
  static  unsigned long long aesl_llvm_cbe_1428_count = 0;
  unsigned int llvm_cbe_tmp__494;
  static  unsigned long long aesl_llvm_cbe_1429_count = 0;
  unsigned long long llvm_cbe_tmp__495;
  static  unsigned long long aesl_llvm_cbe_1430_count = 0;
   char *llvm_cbe_tmp__496;
  static  unsigned long long aesl_llvm_cbe_1431_count = 0;
  static  unsigned long long aesl_llvm_cbe_1432_count = 0;
  unsigned int llvm_cbe_tmp__497;
  static  unsigned long long aesl_llvm_cbe_1433_count = 0;
  unsigned char llvm_cbe_tmp__498;
  static  unsigned long long aesl_llvm_cbe_1434_count = 0;
  unsigned int llvm_cbe_tmp__499;
  static  unsigned long long aesl_llvm_cbe_1435_count = 0;
  unsigned long long llvm_cbe_tmp__500;
  static  unsigned long long aesl_llvm_cbe_1436_count = 0;
   char *llvm_cbe_tmp__501;
  static  unsigned long long aesl_llvm_cbe_1437_count = 0;
  unsigned char llvm_cbe_tmp__502;
  static  unsigned long long aesl_llvm_cbe_1438_count = 0;
  unsigned char llvm_cbe_tmp__503;
  static  unsigned long long aesl_llvm_cbe_1439_count = 0;
  unsigned char llvm_cbe_tmp__504;
  static  unsigned long long aesl_llvm_cbe_1440_count = 0;
  static  unsigned long long aesl_llvm_cbe_1441_count = 0;
  unsigned int llvm_cbe_tmp__505;
  static  unsigned long long aesl_llvm_cbe_1442_count = 0;
  unsigned char llvm_cbe_tmp__506;
  static  unsigned long long aesl_llvm_cbe_1443_count = 0;
  unsigned int llvm_cbe_tmp__507;
  static  unsigned long long aesl_llvm_cbe_1444_count = 0;
  unsigned long long llvm_cbe_tmp__508;
  static  unsigned long long aesl_llvm_cbe_1445_count = 0;
   char *llvm_cbe_tmp__509;
  static  unsigned long long aesl_llvm_cbe_1446_count = 0;
  static  unsigned long long aesl_llvm_cbe_1447_count = 0;
  unsigned int llvm_cbe_tmp__510;
  static  unsigned long long aesl_llvm_cbe_1448_count = 0;
  unsigned char llvm_cbe_tmp__511;
  static  unsigned long long aesl_llvm_cbe_1449_count = 0;
  unsigned int llvm_cbe_tmp__512;
  static  unsigned long long aesl_llvm_cbe_1450_count = 0;
  unsigned long long llvm_cbe_tmp__513;
  static  unsigned long long aesl_llvm_cbe_1451_count = 0;
   char *llvm_cbe_tmp__514;
  static  unsigned long long aesl_llvm_cbe_1452_count = 0;
  unsigned char llvm_cbe_tmp__515;
  static  unsigned long long aesl_llvm_cbe_1453_count = 0;
  unsigned char llvm_cbe_tmp__516;
  static  unsigned long long aesl_llvm_cbe_1454_count = 0;
  unsigned char llvm_cbe_tmp__517;
  static  unsigned long long aesl_llvm_cbe_1455_count = 0;
  static  unsigned long long aesl_llvm_cbe_1456_count = 0;
  unsigned int llvm_cbe_tmp__518;
  static  unsigned long long aesl_llvm_cbe_1457_count = 0;
  unsigned char llvm_cbe_tmp__519;
  static  unsigned long long aesl_llvm_cbe_1458_count = 0;
  unsigned int llvm_cbe_tmp__520;
  static  unsigned long long aesl_llvm_cbe_1459_count = 0;
  unsigned long long llvm_cbe_tmp__521;
  static  unsigned long long aesl_llvm_cbe_1460_count = 0;
   char *llvm_cbe_tmp__522;
  static  unsigned long long aesl_llvm_cbe_1461_count = 0;
  unsigned char llvm_cbe_tmp__523;
  static  unsigned long long aesl_llvm_cbe_1462_count = 0;
  unsigned char llvm_cbe_tmp__524;
  static  unsigned long long aesl_llvm_cbe_1463_count = 0;
  unsigned char llvm_cbe_tmp__525;
  static  unsigned long long aesl_llvm_cbe_1464_count = 0;
  static  unsigned long long aesl_llvm_cbe_1465_count = 0;
  unsigned int llvm_cbe_tmp__526;
  static  unsigned long long aesl_llvm_cbe_1466_count = 0;
  unsigned char llvm_cbe_tmp__527;
  static  unsigned long long aesl_llvm_cbe_1467_count = 0;
  unsigned int llvm_cbe_tmp__528;
  static  unsigned long long aesl_llvm_cbe_1468_count = 0;
  unsigned long long llvm_cbe_tmp__529;
  static  unsigned long long aesl_llvm_cbe_1469_count = 0;
   char *llvm_cbe_tmp__530;
  static  unsigned long long aesl_llvm_cbe_1470_count = 0;
  static  unsigned long long aesl_llvm_cbe_1471_count = 0;
  unsigned int llvm_cbe_tmp__531;
  static  unsigned long long aesl_llvm_cbe_1472_count = 0;
  unsigned char llvm_cbe_tmp__532;
  static  unsigned long long aesl_llvm_cbe_1473_count = 0;
  unsigned int llvm_cbe_tmp__533;
  static  unsigned long long aesl_llvm_cbe_1474_count = 0;
  unsigned long long llvm_cbe_tmp__534;
  static  unsigned long long aesl_llvm_cbe_1475_count = 0;
   char *llvm_cbe_tmp__535;
  static  unsigned long long aesl_llvm_cbe_1476_count = 0;
  unsigned char llvm_cbe_tmp__536;
  static  unsigned long long aesl_llvm_cbe_1477_count = 0;
  unsigned char llvm_cbe_tmp__537;
  static  unsigned long long aesl_llvm_cbe_1478_count = 0;
  unsigned char llvm_cbe_tmp__538;
  static  unsigned long long aesl_llvm_cbe_1479_count = 0;
  static  unsigned long long aesl_llvm_cbe_1480_count = 0;
  unsigned int llvm_cbe_tmp__539;
  static  unsigned long long aesl_llvm_cbe_1481_count = 0;
  unsigned char llvm_cbe_tmp__540;
  static  unsigned long long aesl_llvm_cbe_1482_count = 0;
  unsigned int llvm_cbe_tmp__541;
  static  unsigned long long aesl_llvm_cbe_1483_count = 0;
  unsigned long long llvm_cbe_tmp__542;
  static  unsigned long long aesl_llvm_cbe_1484_count = 0;
   char *llvm_cbe_tmp__543;
  static  unsigned long long aesl_llvm_cbe_1485_count = 0;
  static  unsigned long long aesl_llvm_cbe_1486_count = 0;
  unsigned int llvm_cbe_tmp__544;
  static  unsigned long long aesl_llvm_cbe_1487_count = 0;
  unsigned char llvm_cbe_tmp__545;
  static  unsigned long long aesl_llvm_cbe_1488_count = 0;
  unsigned int llvm_cbe_tmp__546;
  static  unsigned long long aesl_llvm_cbe_1489_count = 0;
  unsigned long long llvm_cbe_tmp__547;
  static  unsigned long long aesl_llvm_cbe_1490_count = 0;
   char *llvm_cbe_tmp__548;
  static  unsigned long long aesl_llvm_cbe_1491_count = 0;
  unsigned char llvm_cbe_tmp__549;
  static  unsigned long long aesl_llvm_cbe_1492_count = 0;
  unsigned char llvm_cbe_tmp__550;
  static  unsigned long long aesl_llvm_cbe_1493_count = 0;
  unsigned char llvm_cbe_tmp__551;
  static  unsigned long long aesl_llvm_cbe_1494_count = 0;
  static  unsigned long long aesl_llvm_cbe_1495_count = 0;
  unsigned int llvm_cbe_tmp__552;
  static  unsigned long long aesl_llvm_cbe_1496_count = 0;
  unsigned char llvm_cbe_tmp__553;
  static  unsigned long long aesl_llvm_cbe_1497_count = 0;
  unsigned int llvm_cbe_tmp__554;
  static  unsigned long long aesl_llvm_cbe_1498_count = 0;
  unsigned long long llvm_cbe_tmp__555;
  static  unsigned long long aesl_llvm_cbe_1499_count = 0;
   char *llvm_cbe_tmp__556;
  static  unsigned long long aesl_llvm_cbe_1500_count = 0;
  unsigned char llvm_cbe_tmp__557;
  static  unsigned long long aesl_llvm_cbe_1501_count = 0;
  unsigned char llvm_cbe_tmp__558;
  static  unsigned long long aesl_llvm_cbe_1502_count = 0;
  unsigned char llvm_cbe_tmp__559;
  static  unsigned long long aesl_llvm_cbe_1503_count = 0;
  static  unsigned long long aesl_llvm_cbe_1504_count = 0;
  unsigned int llvm_cbe_tmp__560;
  static  unsigned long long aesl_llvm_cbe_1505_count = 0;
  unsigned char llvm_cbe_tmp__561;
  static  unsigned long long aesl_llvm_cbe_1506_count = 0;
  unsigned int llvm_cbe_tmp__562;
  static  unsigned long long aesl_llvm_cbe_1507_count = 0;
  unsigned long long llvm_cbe_tmp__563;
  static  unsigned long long aesl_llvm_cbe_1508_count = 0;
   char *llvm_cbe_tmp__564;
  static  unsigned long long aesl_llvm_cbe_1509_count = 0;
  static  unsigned long long aesl_llvm_cbe_1510_count = 0;
  unsigned int llvm_cbe_tmp__565;
  static  unsigned long long aesl_llvm_cbe_1511_count = 0;
  unsigned char llvm_cbe_tmp__566;
  static  unsigned long long aesl_llvm_cbe_1512_count = 0;
  unsigned int llvm_cbe_tmp__567;
  static  unsigned long long aesl_llvm_cbe_1513_count = 0;
  unsigned long long llvm_cbe_tmp__568;
  static  unsigned long long aesl_llvm_cbe_1514_count = 0;
   char *llvm_cbe_tmp__569;
  static  unsigned long long aesl_llvm_cbe_1515_count = 0;
  unsigned char llvm_cbe_tmp__570;
  static  unsigned long long aesl_llvm_cbe_1516_count = 0;
  unsigned char llvm_cbe_tmp__571;
  static  unsigned long long aesl_llvm_cbe_1517_count = 0;
  unsigned char llvm_cbe_tmp__572;
  static  unsigned long long aesl_llvm_cbe_1518_count = 0;
  static  unsigned long long aesl_llvm_cbe_1519_count = 0;
  unsigned int llvm_cbe_tmp__573;
  static  unsigned long long aesl_llvm_cbe_1520_count = 0;
  unsigned char llvm_cbe_tmp__574;
  static  unsigned long long aesl_llvm_cbe_1521_count = 0;
  unsigned int llvm_cbe_tmp__575;
  static  unsigned long long aesl_llvm_cbe_1522_count = 0;
  unsigned long long llvm_cbe_tmp__576;
  static  unsigned long long aesl_llvm_cbe_1523_count = 0;
   char *llvm_cbe_tmp__577;
  static  unsigned long long aesl_llvm_cbe_1524_count = 0;
  static  unsigned long long aesl_llvm_cbe_1525_count = 0;
  unsigned int llvm_cbe_tmp__578;
  static  unsigned long long aesl_llvm_cbe_1526_count = 0;
  static  unsigned long long aesl_llvm_cbe_1527_count = 0;
  static  unsigned long long aesl_llvm_cbe_1528_count = 0;
  static  unsigned long long aesl_llvm_cbe_1529_count = 0;
  static  unsigned long long aesl_llvm_cbe_1530_count = 0;
  static  unsigned long long aesl_llvm_cbe_1531_count = 0;
  static  unsigned long long aesl_llvm_cbe_1532_count = 0;
  static  unsigned long long aesl_llvm_cbe_1533_count = 0;
  static  unsigned long long aesl_llvm_cbe_1534_count = 0;
  static  unsigned long long aesl_llvm_cbe_1535_count = 0;
  static  unsigned long long aesl_llvm_cbe_1536_count = 0;
  static  unsigned long long aesl_llvm_cbe_1537_count = 0;
  static  unsigned long long aesl_llvm_cbe_1538_count = 0;
  static  unsigned long long aesl_llvm_cbe_1539_count = 0;
  static  unsigned long long aesl_llvm_cbe_1540_count = 0;
  static  unsigned long long aesl_llvm_cbe_1541_count = 0;
  static  unsigned long long aesl_llvm_cbe_1542_count = 0;
  static  unsigned long long aesl_llvm_cbe_1543_count = 0;
  static  unsigned long long aesl_llvm_cbe_1544_count = 0;
  static  unsigned long long aesl_llvm_cbe_1545_count = 0;
  static  unsigned long long aesl_llvm_cbe_1546_count = 0;
  static  unsigned long long aesl_llvm_cbe_1547_count = 0;
  static  unsigned long long aesl_llvm_cbe_1548_count = 0;
  static  unsigned long long aesl_llvm_cbe_1549_count = 0;
  static  unsigned long long aesl_llvm_cbe_1550_count = 0;
  static  unsigned long long aesl_llvm_cbe_1551_count = 0;
  static  unsigned long long aesl_llvm_cbe_1552_count = 0;
  static  unsigned long long aesl_llvm_cbe_1553_count = 0;
  static  unsigned long long aesl_llvm_cbe_1554_count = 0;
  static  unsigned long long aesl_llvm_cbe_1555_count = 0;
  static  unsigned long long aesl_llvm_cbe_1556_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1557_count = 0;
  static  unsigned long long aesl_llvm_cbe_1558_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_polyt0_pack\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__579;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__579:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%127, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__578);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = shl i32 %%storemerge1, 3, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1387_count);
  llvm_cbe_tmp__453 = (unsigned int )llvm_cbe_storemerge1 << 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__453);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1388_count);
  llvm_cbe_tmp__454 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__453&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__454);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%3, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1389_count);
  llvm_cbe_tmp__455 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__454))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__454));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%4, align 4, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1390_count);
  llvm_cbe_tmp__456 = (unsigned int )*llvm_cbe_tmp__455;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__456);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sub nsw i32 4096, %%5, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1391_count);
  llvm_cbe_tmp__457 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__456&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__457&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = or i32 %%2, 1, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1392_count);
  llvm_cbe_tmp__458 = (unsigned int )llvm_cbe_tmp__453 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__458);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i32 %%7 to i64, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1393_count);
  llvm_cbe_tmp__459 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__458&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__459);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%8, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1394_count);
  llvm_cbe_tmp__460 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__459))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__459));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i32* %%9, align 4, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1395_count);
  llvm_cbe_tmp__461 = (unsigned int )*llvm_cbe_tmp__460;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__461);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sub nsw i32 4096, %%10, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1396_count);
  llvm_cbe_tmp__462 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__461&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__462&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = or i32 %%2, 2, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1397_count);
  llvm_cbe_tmp__463 = (unsigned int )llvm_cbe_tmp__453 | 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__463);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = zext i32 %%12 to i64, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1398_count);
  llvm_cbe_tmp__464 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__463&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__464);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%13, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1399_count);
  llvm_cbe_tmp__465 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__464))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__464));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* %%14, align 4, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1400_count);
  llvm_cbe_tmp__466 = (unsigned int )*llvm_cbe_tmp__465;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__466);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sub nsw i32 4096, %%15, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1401_count);
  llvm_cbe_tmp__467 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__466&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__467&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = or i32 %%2, 3, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1402_count);
  llvm_cbe_tmp__468 = (unsigned int )llvm_cbe_tmp__453 | 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__468);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = zext i32 %%17 to i64, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1403_count);
  llvm_cbe_tmp__469 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__468&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__469);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%18, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1404_count);
  llvm_cbe_tmp__470 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__469))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__469));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i32* %%19, align 4, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1405_count);
  llvm_cbe_tmp__471 = (unsigned int )*llvm_cbe_tmp__470;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__471);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sub nsw i32 4096, %%20, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1406_count);
  llvm_cbe_tmp__472 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__471&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__472&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = or i32 %%2, 4, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1407_count);
  llvm_cbe_tmp__473 = (unsigned int )llvm_cbe_tmp__453 | 4u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__473);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = zext i32 %%22 to i64, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1408_count);
  llvm_cbe_tmp__474 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__473&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__474);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%23, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1409_count);
  llvm_cbe_tmp__475 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__474))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__474));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i32* %%24, align 4, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1410_count);
  llvm_cbe_tmp__476 = (unsigned int )*llvm_cbe_tmp__475;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__476);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = sub nsw i32 4096, %%25, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1411_count);
  llvm_cbe_tmp__477 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__476&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__477&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = or i32 %%2, 5, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1412_count);
  llvm_cbe_tmp__478 = (unsigned int )llvm_cbe_tmp__453 | 5u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__478);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = zext i32 %%27 to i64, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1413_count);
  llvm_cbe_tmp__479 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__478&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__479);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%28, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1414_count);
  llvm_cbe_tmp__480 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__479))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__479));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i32* %%29, align 4, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1415_count);
  llvm_cbe_tmp__481 = (unsigned int )*llvm_cbe_tmp__480;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__481);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = sub nsw i32 4096, %%30, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1416_count);
  llvm_cbe_tmp__482 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__481&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__482&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = or i32 %%2, 6, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1417_count);
  llvm_cbe_tmp__483 = (unsigned int )llvm_cbe_tmp__453 | 6u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__483);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = zext i32 %%32 to i64, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1418_count);
  llvm_cbe_tmp__484 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__483&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__484);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%33, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1419_count);
  llvm_cbe_tmp__485 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__484))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__484));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i32* %%34, align 4, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1420_count);
  llvm_cbe_tmp__486 = (unsigned int )*llvm_cbe_tmp__485;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__486);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = sub nsw i32 4096, %%35, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1421_count);
  llvm_cbe_tmp__487 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__486&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__487&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = or i32 %%2, 7, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1422_count);
  llvm_cbe_tmp__488 = (unsigned int )llvm_cbe_tmp__453 | 7u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__488);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = zext i32 %%37 to i64, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1423_count);
  llvm_cbe_tmp__489 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__488&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__489);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%38, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1424_count);
  llvm_cbe_tmp__490 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__489))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__489));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i32* %%39, align 4, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1425_count);
  llvm_cbe_tmp__491 = (unsigned int )*llvm_cbe_tmp__490;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__491);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = sub nsw i32 4096, %%40, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1426_count);
  llvm_cbe_tmp__492 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__491&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__492&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = trunc i32 %%6 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1427_count);
  llvm_cbe_tmp__493 = (unsigned char )((unsigned char )llvm_cbe_tmp__457&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__493);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = mul i32 %%storemerge1, 13, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1428_count);
  llvm_cbe_tmp__494 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) * ((unsigned int )(13u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__494&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = zext i32 %%43 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1429_count);
  llvm_cbe_tmp__495 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__494&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__495);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds i8* %%r, i64 %%44, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1430_count);
  llvm_cbe_tmp__496 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__495))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__495));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%42, i8* %%45, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1431_count);
  *llvm_cbe_tmp__496 = llvm_cbe_tmp__493;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__493);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = lshr i32 %%6, 8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1432_count);
  llvm_cbe_tmp__497 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__457&4294967295ull)) >> ((unsigned int )(8u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__497&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = trunc i32 %%46 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1433_count);
  llvm_cbe_tmp__498 = (unsigned char )((unsigned char )llvm_cbe_tmp__497&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__498);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = add i32 %%43, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1434_count);
  llvm_cbe_tmp__499 = (unsigned int )((unsigned int )(llvm_cbe_tmp__494&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__499&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = zext i32 %%48 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1435_count);
  llvm_cbe_tmp__500 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__499&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__500);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds i8* %%r, i64 %%49, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1436_count);
  llvm_cbe_tmp__501 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__500))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__500));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = trunc i32 %%11 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1437_count);
  llvm_cbe_tmp__502 = (unsigned char )((unsigned char )llvm_cbe_tmp__462&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__502);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = shl i8 %%51, 5, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1438_count);
  llvm_cbe_tmp__503 = (unsigned char )((unsigned char )(llvm_cbe_tmp__502 << ((unsigned char )5)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__503);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = or i8 %%52, %%47, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1439_count);
  llvm_cbe_tmp__504 = (unsigned char )((unsigned char )(llvm_cbe_tmp__503 | llvm_cbe_tmp__498));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__504);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%53, i8* %%50, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1440_count);
  *llvm_cbe_tmp__501 = llvm_cbe_tmp__504;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__504);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = lshr i32 %%11, 3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1441_count);
  llvm_cbe_tmp__505 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__462&4294967295ull)) >> ((unsigned int )(3u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__505&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = trunc i32 %%54 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1442_count);
  llvm_cbe_tmp__506 = (unsigned char )((unsigned char )llvm_cbe_tmp__505&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__506);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = add i32 %%43, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1443_count);
  llvm_cbe_tmp__507 = (unsigned int )((unsigned int )(llvm_cbe_tmp__494&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__507&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = zext i32 %%56 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1444_count);
  llvm_cbe_tmp__508 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__507&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__508);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds i8* %%r, i64 %%57, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1445_count);
  llvm_cbe_tmp__509 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__508))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__508));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%55, i8* %%58, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1446_count);
  *llvm_cbe_tmp__509 = llvm_cbe_tmp__506;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__506);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = lshr i32 %%11, 11, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1447_count);
  llvm_cbe_tmp__510 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__462&4294967295ull)) >> ((unsigned int )(11u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__510&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = trunc i32 %%59 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1448_count);
  llvm_cbe_tmp__511 = (unsigned char )((unsigned char )llvm_cbe_tmp__510&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__511);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = add i32 %%43, 3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1449_count);
  llvm_cbe_tmp__512 = (unsigned int )((unsigned int )(llvm_cbe_tmp__494&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__512&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = zext i32 %%61 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1450_count);
  llvm_cbe_tmp__513 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__512&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__513);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds i8* %%r, i64 %%62, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1451_count);
  llvm_cbe_tmp__514 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__513))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__513));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = trunc i32 %%16 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1452_count);
  llvm_cbe_tmp__515 = (unsigned char )((unsigned char )llvm_cbe_tmp__467&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__515);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = shl i8 %%64, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1453_count);
  llvm_cbe_tmp__516 = (unsigned char )((unsigned char )(llvm_cbe_tmp__515 << ((unsigned char )2)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__516);
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = or i8 %%65, %%60, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1454_count);
  llvm_cbe_tmp__517 = (unsigned char )((unsigned char )(llvm_cbe_tmp__516 | llvm_cbe_tmp__511));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__517);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%66, i8* %%63, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1455_count);
  *llvm_cbe_tmp__514 = llvm_cbe_tmp__517;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__517);
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = lshr i32 %%16, 6, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1456_count);
  llvm_cbe_tmp__518 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__467&4294967295ull)) >> ((unsigned int )(6u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__518&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = trunc i32 %%67 to i8, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1457_count);
  llvm_cbe_tmp__519 = (unsigned char )((unsigned char )llvm_cbe_tmp__518&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__519);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = add i32 %%43, 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1458_count);
  llvm_cbe_tmp__520 = (unsigned int )((unsigned int )(llvm_cbe_tmp__494&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__520&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = zext i32 %%69 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1459_count);
  llvm_cbe_tmp__521 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__520&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__521);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = getelementptr inbounds i8* %%r, i64 %%70, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1460_count);
  llvm_cbe_tmp__522 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__521))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__521));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = trunc i32 %%21 to i8, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1461_count);
  llvm_cbe_tmp__523 = (unsigned char )((unsigned char )llvm_cbe_tmp__472&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__523);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = shl i8 %%72, 7, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1462_count);
  llvm_cbe_tmp__524 = (unsigned char )((unsigned char )(llvm_cbe_tmp__523 << ((unsigned char )7)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__524);
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = or i8 %%73, %%68, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1463_count);
  llvm_cbe_tmp__525 = (unsigned char )((unsigned char )(llvm_cbe_tmp__524 | llvm_cbe_tmp__519));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__525);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%74, i8* %%71, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1464_count);
  *llvm_cbe_tmp__522 = llvm_cbe_tmp__525;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__525);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = lshr i32 %%21, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1465_count);
  llvm_cbe_tmp__526 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__472&4294967295ull)) >> ((unsigned int )(1u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__526&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = trunc i32 %%75 to i8, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1466_count);
  llvm_cbe_tmp__527 = (unsigned char )((unsigned char )llvm_cbe_tmp__526&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__527);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = add i32 %%43, 5, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1467_count);
  llvm_cbe_tmp__528 = (unsigned int )((unsigned int )(llvm_cbe_tmp__494&4294967295ull)) + ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__528&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = zext i32 %%77 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1468_count);
  llvm_cbe_tmp__529 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__528&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__529);
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = getelementptr inbounds i8* %%r, i64 %%78, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1469_count);
  llvm_cbe_tmp__530 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__529))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__529));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%76, i8* %%79, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1470_count);
  *llvm_cbe_tmp__530 = llvm_cbe_tmp__527;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__527);
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = lshr i32 %%21, 9, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1471_count);
  llvm_cbe_tmp__531 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__472&4294967295ull)) >> ((unsigned int )(9u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__531&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = trunc i32 %%80 to i8, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1472_count);
  llvm_cbe_tmp__532 = (unsigned char )((unsigned char )llvm_cbe_tmp__531&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__532);
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = add i32 %%43, 6, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1473_count);
  llvm_cbe_tmp__533 = (unsigned int )((unsigned int )(llvm_cbe_tmp__494&4294967295ull)) + ((unsigned int )(6u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__533&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = zext i32 %%82 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1474_count);
  llvm_cbe_tmp__534 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__533&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__534);
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = getelementptr inbounds i8* %%r, i64 %%83, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1475_count);
  llvm_cbe_tmp__535 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__534))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__534));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = trunc i32 %%26 to i8, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1476_count);
  llvm_cbe_tmp__536 = (unsigned char )((unsigned char )llvm_cbe_tmp__477&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__536);
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = shl i8 %%85, 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1477_count);
  llvm_cbe_tmp__537 = (unsigned char )((unsigned char )(llvm_cbe_tmp__536 << ((unsigned char )4)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__537);
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = or i8 %%86, %%81, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1478_count);
  llvm_cbe_tmp__538 = (unsigned char )((unsigned char )(llvm_cbe_tmp__537 | llvm_cbe_tmp__532));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__538);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%87, i8* %%84, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1479_count);
  *llvm_cbe_tmp__535 = llvm_cbe_tmp__538;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__538);
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = lshr i32 %%26, 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1480_count);
  llvm_cbe_tmp__539 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__477&4294967295ull)) >> ((unsigned int )(4u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__539&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = trunc i32 %%88 to i8, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1481_count);
  llvm_cbe_tmp__540 = (unsigned char )((unsigned char )llvm_cbe_tmp__539&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__540);
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = add i32 %%43, 7, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1482_count);
  llvm_cbe_tmp__541 = (unsigned int )((unsigned int )(llvm_cbe_tmp__494&4294967295ull)) + ((unsigned int )(7u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__541&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = zext i32 %%90 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1483_count);
  llvm_cbe_tmp__542 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__541&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__542);
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = getelementptr inbounds i8* %%r, i64 %%91, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1484_count);
  llvm_cbe_tmp__543 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__542))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__542));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%89, i8* %%92, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1485_count);
  *llvm_cbe_tmp__543 = llvm_cbe_tmp__540;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__540);
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = lshr i32 %%26, 12, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1486_count);
  llvm_cbe_tmp__544 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__477&4294967295ull)) >> ((unsigned int )(12u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__544&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = trunc i32 %%93 to i8, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1487_count);
  llvm_cbe_tmp__545 = (unsigned char )((unsigned char )llvm_cbe_tmp__544&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__545);
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = add i32 %%43, 8, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1488_count);
  llvm_cbe_tmp__546 = (unsigned int )((unsigned int )(llvm_cbe_tmp__494&4294967295ull)) + ((unsigned int )(8u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__546&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = zext i32 %%95 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1489_count);
  llvm_cbe_tmp__547 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__546&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__547);
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = getelementptr inbounds i8* %%r, i64 %%96, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1490_count);
  llvm_cbe_tmp__548 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__547))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__547));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = trunc i32 %%31 to i8, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1491_count);
  llvm_cbe_tmp__549 = (unsigned char )((unsigned char )llvm_cbe_tmp__482&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__549);
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = shl i8 %%98, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1492_count);
  llvm_cbe_tmp__550 = (unsigned char )((unsigned char )(llvm_cbe_tmp__549 << ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__550);
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = or i8 %%99, %%94, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1493_count);
  llvm_cbe_tmp__551 = (unsigned char )((unsigned char )(llvm_cbe_tmp__550 | llvm_cbe_tmp__545));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__551);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%100, i8* %%97, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1494_count);
  *llvm_cbe_tmp__548 = llvm_cbe_tmp__551;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__551);
if (AESL_DEBUG_TRACE)
printf("\n  %%101 = lshr i32 %%31, 7, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1495_count);
  llvm_cbe_tmp__552 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__482&4294967295ull)) >> ((unsigned int )(7u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__552&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = trunc i32 %%101 to i8, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1496_count);
  llvm_cbe_tmp__553 = (unsigned char )((unsigned char )llvm_cbe_tmp__552&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__553);
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = add i32 %%43, 9, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1497_count);
  llvm_cbe_tmp__554 = (unsigned int )((unsigned int )(llvm_cbe_tmp__494&4294967295ull)) + ((unsigned int )(9u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__554&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = zext i32 %%103 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1498_count);
  llvm_cbe_tmp__555 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__554&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__555);
if (AESL_DEBUG_TRACE)
printf("\n  %%105 = getelementptr inbounds i8* %%r, i64 %%104, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1499_count);
  llvm_cbe_tmp__556 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__555))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__555));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = trunc i32 %%36 to i8, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1500_count);
  llvm_cbe_tmp__557 = (unsigned char )((unsigned char )llvm_cbe_tmp__487&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__557);
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = shl i8 %%106, 6, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1501_count);
  llvm_cbe_tmp__558 = (unsigned char )((unsigned char )(llvm_cbe_tmp__557 << ((unsigned char )6)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__558);
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = or i8 %%107, %%102, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1502_count);
  llvm_cbe_tmp__559 = (unsigned char )((unsigned char )(llvm_cbe_tmp__558 | llvm_cbe_tmp__553));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__559);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%108, i8* %%105, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1503_count);
  *llvm_cbe_tmp__556 = llvm_cbe_tmp__559;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__559);
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = lshr i32 %%36, 2, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1504_count);
  llvm_cbe_tmp__560 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__487&4294967295ull)) >> ((unsigned int )(2u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__560&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%110 = trunc i32 %%109 to i8, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1505_count);
  llvm_cbe_tmp__561 = (unsigned char )((unsigned char )llvm_cbe_tmp__560&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__561);
if (AESL_DEBUG_TRACE)
printf("\n  %%111 = add i32 %%43, 10, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1506_count);
  llvm_cbe_tmp__562 = (unsigned int )((unsigned int )(llvm_cbe_tmp__494&4294967295ull)) + ((unsigned int )(10u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__562&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%112 = zext i32 %%111 to i64, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1507_count);
  llvm_cbe_tmp__563 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__562&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__563);
if (AESL_DEBUG_TRACE)
printf("\n  %%113 = getelementptr inbounds i8* %%r, i64 %%112, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1508_count);
  llvm_cbe_tmp__564 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__563))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__563));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%110, i8* %%113, align 1, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1509_count);
  *llvm_cbe_tmp__564 = llvm_cbe_tmp__561;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__561);
if (AESL_DEBUG_TRACE)
printf("\n  %%114 = lshr i32 %%36, 10, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1510_count);
  llvm_cbe_tmp__565 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__487&4294967295ull)) >> ((unsigned int )(10u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__565&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%115 = trunc i32 %%114 to i8, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1511_count);
  llvm_cbe_tmp__566 = (unsigned char )((unsigned char )llvm_cbe_tmp__565&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__566);
if (AESL_DEBUG_TRACE)
printf("\n  %%116 = add i32 %%43, 11, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1512_count);
  llvm_cbe_tmp__567 = (unsigned int )((unsigned int )(llvm_cbe_tmp__494&4294967295ull)) + ((unsigned int )(11u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__567&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%117 = zext i32 %%116 to i64, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1513_count);
  llvm_cbe_tmp__568 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__567&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__568);
if (AESL_DEBUG_TRACE)
printf("\n  %%118 = getelementptr inbounds i8* %%r, i64 %%117, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1514_count);
  llvm_cbe_tmp__569 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__568))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__568));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%119 = trunc i32 %%41 to i8, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1515_count);
  llvm_cbe_tmp__570 = (unsigned char )((unsigned char )llvm_cbe_tmp__492&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__570);
if (AESL_DEBUG_TRACE)
printf("\n  %%120 = shl i8 %%119, 3, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1516_count);
  llvm_cbe_tmp__571 = (unsigned char )((unsigned char )(llvm_cbe_tmp__570 << ((unsigned char )3)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__571);
if (AESL_DEBUG_TRACE)
printf("\n  %%121 = or i8 %%120, %%115, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1517_count);
  llvm_cbe_tmp__572 = (unsigned char )((unsigned char )(llvm_cbe_tmp__571 | llvm_cbe_tmp__566));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__572);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%121, i8* %%118, align 1, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1518_count);
  *llvm_cbe_tmp__569 = llvm_cbe_tmp__572;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__572);
if (AESL_DEBUG_TRACE)
printf("\n  %%122 = lshr i32 %%41, 5, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1519_count);
  llvm_cbe_tmp__573 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__492&4294967295ull)) >> ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__573&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%123 = trunc i32 %%122 to i8, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1520_count);
  llvm_cbe_tmp__574 = (unsigned char )((unsigned char )llvm_cbe_tmp__573&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__574);
if (AESL_DEBUG_TRACE)
printf("\n  %%124 = add i32 %%43, 12, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1521_count);
  llvm_cbe_tmp__575 = (unsigned int )((unsigned int )(llvm_cbe_tmp__494&4294967295ull)) + ((unsigned int )(12u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__575&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%125 = zext i32 %%124 to i64, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1522_count);
  llvm_cbe_tmp__576 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__575&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__576);
if (AESL_DEBUG_TRACE)
printf("\n  %%126 = getelementptr inbounds i8* %%r, i64 %%125, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1523_count);
  llvm_cbe_tmp__577 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__576))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__576));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%123, i8* %%126, align 1, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1524_count);
  *llvm_cbe_tmp__577 = llvm_cbe_tmp__574;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__574);
if (AESL_DEBUG_TRACE)
printf("\n  %%127 = add i32 %%storemerge1, 1, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_pack  --> \n", ++aesl_llvm_cbe_1525_count);
  llvm_cbe_tmp__578 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__578&4294967295ull)));
  if (((llvm_cbe_tmp__578&4294967295U) == (32u&4294967295U))) {
    goto llvm_cbe_tmp__580;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__578;   /* for PHI node */
    goto llvm_cbe_tmp__579;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__580:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_polyt0_pack}\n");
  return;
}


void pqcrystals_dilithium3_ref_polyt0_unpack(l_struct_OC_poly *llvm_cbe_r,  char *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_1559_count = 0;
  static  unsigned long long aesl_llvm_cbe_1560_count = 0;
  static  unsigned long long aesl_llvm_cbe_1561_count = 0;
  static  unsigned long long aesl_llvm_cbe_1562_count = 0;
  static  unsigned long long aesl_llvm_cbe_1563_count = 0;
  static  unsigned long long aesl_llvm_cbe_1564_count = 0;
  static  unsigned long long aesl_llvm_cbe_1565_count = 0;
  static  unsigned long long aesl_llvm_cbe_1566_count = 0;
  static  unsigned long long aesl_llvm_cbe_1567_count = 0;
  static  unsigned long long aesl_llvm_cbe_1568_count = 0;
  static  unsigned long long aesl_llvm_cbe_1569_count = 0;
  static  unsigned long long aesl_llvm_cbe_1570_count = 0;
  static  unsigned long long aesl_llvm_cbe_1571_count = 0;
  static  unsigned long long aesl_llvm_cbe_1572_count = 0;
  static  unsigned long long aesl_llvm_cbe_1573_count = 0;
  static  unsigned long long aesl_llvm_cbe_1574_count = 0;
  static  unsigned long long aesl_llvm_cbe_1575_count = 0;
  static  unsigned long long aesl_llvm_cbe_1576_count = 0;
  static  unsigned long long aesl_llvm_cbe_1577_count = 0;
  static  unsigned long long aesl_llvm_cbe_1578_count = 0;
  static  unsigned long long aesl_llvm_cbe_1579_count = 0;
  static  unsigned long long aesl_llvm_cbe_1580_count = 0;
  static  unsigned long long aesl_llvm_cbe_1581_count = 0;
  static  unsigned long long aesl_llvm_cbe_1582_count = 0;
  static  unsigned long long aesl_llvm_cbe_1583_count = 0;
  static  unsigned long long aesl_llvm_cbe_1584_count = 0;
  static  unsigned long long aesl_llvm_cbe_1585_count = 0;
  static  unsigned long long aesl_llvm_cbe_1586_count = 0;
  static  unsigned long long aesl_llvm_cbe_1587_count = 0;
  static  unsigned long long aesl_llvm_cbe_1588_count = 0;
  static  unsigned long long aesl_llvm_cbe_1589_count = 0;
  static  unsigned long long aesl_llvm_cbe_1590_count = 0;
  static  unsigned long long aesl_llvm_cbe_1591_count = 0;
  static  unsigned long long aesl_llvm_cbe_1592_count = 0;
  static  unsigned long long aesl_llvm_cbe_1593_count = 0;
  static  unsigned long long aesl_llvm_cbe_1594_count = 0;
  static  unsigned long long aesl_llvm_cbe_1595_count = 0;
  static  unsigned long long aesl_llvm_cbe_1596_count = 0;
  static  unsigned long long aesl_llvm_cbe_1597_count = 0;
  static  unsigned long long aesl_llvm_cbe_1598_count = 0;
  static  unsigned long long aesl_llvm_cbe_1599_count = 0;
  static  unsigned long long aesl_llvm_cbe_1600_count = 0;
  static  unsigned long long aesl_llvm_cbe_1601_count = 0;
  static  unsigned long long aesl_llvm_cbe_1602_count = 0;
  static  unsigned long long aesl_llvm_cbe_1603_count = 0;
  static  unsigned long long aesl_llvm_cbe_1604_count = 0;
  static  unsigned long long aesl_llvm_cbe_1605_count = 0;
  static  unsigned long long aesl_llvm_cbe_1606_count = 0;
  static  unsigned long long aesl_llvm_cbe_1607_count = 0;
  static  unsigned long long aesl_llvm_cbe_1608_count = 0;
  static  unsigned long long aesl_llvm_cbe_1609_count = 0;
  static  unsigned long long aesl_llvm_cbe_1610_count = 0;
  static  unsigned long long aesl_llvm_cbe_1611_count = 0;
  static  unsigned long long aesl_llvm_cbe_1612_count = 0;
  static  unsigned long long aesl_llvm_cbe_1613_count = 0;
  static  unsigned long long aesl_llvm_cbe_1614_count = 0;
  static  unsigned long long aesl_llvm_cbe_1615_count = 0;
  static  unsigned long long aesl_llvm_cbe_1616_count = 0;
  static  unsigned long long aesl_llvm_cbe_1617_count = 0;
  static  unsigned long long aesl_llvm_cbe_1618_count = 0;
  static  unsigned long long aesl_llvm_cbe_1619_count = 0;
  static  unsigned long long aesl_llvm_cbe_1620_count = 0;
  static  unsigned long long aesl_llvm_cbe_1621_count = 0;
  static  unsigned long long aesl_llvm_cbe_1622_count = 0;
  static  unsigned long long aesl_llvm_cbe_1623_count = 0;
  static  unsigned long long aesl_llvm_cbe_1624_count = 0;
  static  unsigned long long aesl_llvm_cbe_1625_count = 0;
  static  unsigned long long aesl_llvm_cbe_1626_count = 0;
  static  unsigned long long aesl_llvm_cbe_1627_count = 0;
  static  unsigned long long aesl_llvm_cbe_1628_count = 0;
  static  unsigned long long aesl_llvm_cbe_1629_count = 0;
  static  unsigned long long aesl_llvm_cbe_1630_count = 0;
  static  unsigned long long aesl_llvm_cbe_1631_count = 0;
  static  unsigned long long aesl_llvm_cbe_1632_count = 0;
  static  unsigned long long aesl_llvm_cbe_1633_count = 0;
  static  unsigned long long aesl_llvm_cbe_1634_count = 0;
  static  unsigned long long aesl_llvm_cbe_1635_count = 0;
  static  unsigned long long aesl_llvm_cbe_1636_count = 0;
  static  unsigned long long aesl_llvm_cbe_1637_count = 0;
  static  unsigned long long aesl_llvm_cbe_1638_count = 0;
  static  unsigned long long aesl_llvm_cbe_1639_count = 0;
  static  unsigned long long aesl_llvm_cbe_1640_count = 0;
  static  unsigned long long aesl_llvm_cbe_1641_count = 0;
  static  unsigned long long aesl_llvm_cbe_1642_count = 0;
  static  unsigned long long aesl_llvm_cbe_1643_count = 0;
  static  unsigned long long aesl_llvm_cbe_1644_count = 0;
  static  unsigned long long aesl_llvm_cbe_1645_count = 0;
  static  unsigned long long aesl_llvm_cbe_1646_count = 0;
  static  unsigned long long aesl_llvm_cbe_1647_count = 0;
  static  unsigned long long aesl_llvm_cbe_1648_count = 0;
  static  unsigned long long aesl_llvm_cbe_1649_count = 0;
  static  unsigned long long aesl_llvm_cbe_1650_count = 0;
  static  unsigned long long aesl_llvm_cbe_1651_count = 0;
  static  unsigned long long aesl_llvm_cbe_1652_count = 0;
  static  unsigned long long aesl_llvm_cbe_1653_count = 0;
  static  unsigned long long aesl_llvm_cbe_1654_count = 0;
  static  unsigned long long aesl_llvm_cbe_1655_count = 0;
  static  unsigned long long aesl_llvm_cbe_1656_count = 0;
  static  unsigned long long aesl_llvm_cbe_1657_count = 0;
  static  unsigned long long aesl_llvm_cbe_1658_count = 0;
  static  unsigned long long aesl_llvm_cbe_1659_count = 0;
  static  unsigned long long aesl_llvm_cbe_1660_count = 0;
  static  unsigned long long aesl_llvm_cbe_1661_count = 0;
  static  unsigned long long aesl_llvm_cbe_1662_count = 0;
  static  unsigned long long aesl_llvm_cbe_1663_count = 0;
  static  unsigned long long aesl_llvm_cbe_1664_count = 0;
  static  unsigned long long aesl_llvm_cbe_1665_count = 0;
  static  unsigned long long aesl_llvm_cbe_1666_count = 0;
  static  unsigned long long aesl_llvm_cbe_1667_count = 0;
  static  unsigned long long aesl_llvm_cbe_1668_count = 0;
  static  unsigned long long aesl_llvm_cbe_1669_count = 0;
  static  unsigned long long aesl_llvm_cbe_1670_count = 0;
  static  unsigned long long aesl_llvm_cbe_1671_count = 0;
  static  unsigned long long aesl_llvm_cbe_1672_count = 0;
  static  unsigned long long aesl_llvm_cbe_1673_count = 0;
  static  unsigned long long aesl_llvm_cbe_1674_count = 0;
  static  unsigned long long aesl_llvm_cbe_1675_count = 0;
  static  unsigned long long aesl_llvm_cbe_1676_count = 0;
  static  unsigned long long aesl_llvm_cbe_1677_count = 0;
  static  unsigned long long aesl_llvm_cbe_1678_count = 0;
  static  unsigned long long aesl_llvm_cbe_1679_count = 0;
  static  unsigned long long aesl_llvm_cbe_1680_count = 0;
  static  unsigned long long aesl_llvm_cbe_1681_count = 0;
  static  unsigned long long aesl_llvm_cbe_1682_count = 0;
  static  unsigned long long aesl_llvm_cbe_1683_count = 0;
  static  unsigned long long aesl_llvm_cbe_1684_count = 0;
  static  unsigned long long aesl_llvm_cbe_1685_count = 0;
  static  unsigned long long aesl_llvm_cbe_1686_count = 0;
  static  unsigned long long aesl_llvm_cbe_1687_count = 0;
  static  unsigned long long aesl_llvm_cbe_1688_count = 0;
  static  unsigned long long aesl_llvm_cbe_1689_count = 0;
  static  unsigned long long aesl_llvm_cbe_1690_count = 0;
  static  unsigned long long aesl_llvm_cbe_1691_count = 0;
  static  unsigned long long aesl_llvm_cbe_1692_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1693_count = 0;
  unsigned int llvm_cbe_tmp__581;
  static  unsigned long long aesl_llvm_cbe_1694_count = 0;
  unsigned long long llvm_cbe_tmp__582;
  static  unsigned long long aesl_llvm_cbe_1695_count = 0;
   char *llvm_cbe_tmp__583;
  static  unsigned long long aesl_llvm_cbe_1696_count = 0;
  unsigned char llvm_cbe_tmp__584;
  static  unsigned long long aesl_llvm_cbe_1697_count = 0;
  unsigned int llvm_cbe_tmp__585;
  static  unsigned long long aesl_llvm_cbe_1698_count = 0;
  unsigned int llvm_cbe_tmp__586;
  static  unsigned long long aesl_llvm_cbe_1699_count = 0;
  unsigned long long llvm_cbe_tmp__587;
  static  unsigned long long aesl_llvm_cbe_1700_count = 0;
  signed int *llvm_cbe_tmp__588;
  static  unsigned long long aesl_llvm_cbe_1701_count = 0;
  static  unsigned long long aesl_llvm_cbe_1702_count = 0;
  unsigned int llvm_cbe_tmp__589;
  static  unsigned long long aesl_llvm_cbe_1703_count = 0;
  unsigned long long llvm_cbe_tmp__590;
  static  unsigned long long aesl_llvm_cbe_1704_count = 0;
   char *llvm_cbe_tmp__591;
  static  unsigned long long aesl_llvm_cbe_1705_count = 0;
  unsigned char llvm_cbe_tmp__592;
  static  unsigned long long aesl_llvm_cbe_1706_count = 0;
  unsigned int llvm_cbe_tmp__593;
  static  unsigned long long aesl_llvm_cbe_1707_count = 0;
  unsigned int llvm_cbe_tmp__594;
  static  unsigned long long aesl_llvm_cbe_1708_count = 0;
  unsigned int llvm_cbe_tmp__595;
  static  unsigned long long aesl_llvm_cbe_1709_count = 0;
  unsigned int llvm_cbe_tmp__596;
  static  unsigned long long aesl_llvm_cbe_1710_count = 0;
  static  unsigned long long aesl_llvm_cbe_1711_count = 0;
  unsigned char llvm_cbe_tmp__597;
  static  unsigned long long aesl_llvm_cbe_1712_count = 0;
  unsigned int llvm_cbe_tmp__598;
  static  unsigned long long aesl_llvm_cbe_1713_count = 0;
  unsigned int llvm_cbe_tmp__599;
  static  unsigned long long aesl_llvm_cbe_1714_count = 0;
  unsigned int llvm_cbe_tmp__600;
  static  unsigned long long aesl_llvm_cbe_1715_count = 0;
  unsigned long long llvm_cbe_tmp__601;
  static  unsigned long long aesl_llvm_cbe_1716_count = 0;
  signed int *llvm_cbe_tmp__602;
  static  unsigned long long aesl_llvm_cbe_1717_count = 0;
  static  unsigned long long aesl_llvm_cbe_1718_count = 0;
  unsigned int llvm_cbe_tmp__603;
  static  unsigned long long aesl_llvm_cbe_1719_count = 0;
  unsigned long long llvm_cbe_tmp__604;
  static  unsigned long long aesl_llvm_cbe_1720_count = 0;
   char *llvm_cbe_tmp__605;
  static  unsigned long long aesl_llvm_cbe_1721_count = 0;
  unsigned char llvm_cbe_tmp__606;
  static  unsigned long long aesl_llvm_cbe_1722_count = 0;
  unsigned int llvm_cbe_tmp__607;
  static  unsigned long long aesl_llvm_cbe_1723_count = 0;
  unsigned int llvm_cbe_tmp__608;
  static  unsigned long long aesl_llvm_cbe_1724_count = 0;
  unsigned int llvm_cbe_tmp__609;
  static  unsigned long long aesl_llvm_cbe_1725_count = 0;
  static  unsigned long long aesl_llvm_cbe_1726_count = 0;
  unsigned int llvm_cbe_tmp__610;
  static  unsigned long long aesl_llvm_cbe_1727_count = 0;
  unsigned long long llvm_cbe_tmp__611;
  static  unsigned long long aesl_llvm_cbe_1728_count = 0;
   char *llvm_cbe_tmp__612;
  static  unsigned long long aesl_llvm_cbe_1729_count = 0;
  unsigned char llvm_cbe_tmp__613;
  static  unsigned long long aesl_llvm_cbe_1730_count = 0;
  unsigned int llvm_cbe_tmp__614;
  static  unsigned long long aesl_llvm_cbe_1731_count = 0;
  unsigned int llvm_cbe_tmp__615;
  static  unsigned long long aesl_llvm_cbe_1732_count = 0;
  unsigned int llvm_cbe_tmp__616;
  static  unsigned long long aesl_llvm_cbe_1733_count = 0;
  unsigned int llvm_cbe_tmp__617;
  static  unsigned long long aesl_llvm_cbe_1734_count = 0;
  static  unsigned long long aesl_llvm_cbe_1735_count = 0;
  unsigned char llvm_cbe_tmp__618;
  static  unsigned long long aesl_llvm_cbe_1736_count = 0;
  unsigned int llvm_cbe_tmp__619;
  static  unsigned long long aesl_llvm_cbe_1737_count = 0;
  unsigned int llvm_cbe_tmp__620;
  static  unsigned long long aesl_llvm_cbe_1738_count = 0;
  unsigned int llvm_cbe_tmp__621;
  static  unsigned long long aesl_llvm_cbe_1739_count = 0;
  unsigned long long llvm_cbe_tmp__622;
  static  unsigned long long aesl_llvm_cbe_1740_count = 0;
  signed int *llvm_cbe_tmp__623;
  static  unsigned long long aesl_llvm_cbe_1741_count = 0;
  static  unsigned long long aesl_llvm_cbe_1742_count = 0;
  unsigned int llvm_cbe_tmp__624;
  static  unsigned long long aesl_llvm_cbe_1743_count = 0;
  unsigned long long llvm_cbe_tmp__625;
  static  unsigned long long aesl_llvm_cbe_1744_count = 0;
   char *llvm_cbe_tmp__626;
  static  unsigned long long aesl_llvm_cbe_1745_count = 0;
  unsigned char llvm_cbe_tmp__627;
  static  unsigned long long aesl_llvm_cbe_1746_count = 0;
  unsigned int llvm_cbe_tmp__628;
  static  unsigned long long aesl_llvm_cbe_1747_count = 0;
  unsigned int llvm_cbe_tmp__629;
  static  unsigned long long aesl_llvm_cbe_1748_count = 0;
  unsigned int llvm_cbe_tmp__630;
  static  unsigned long long aesl_llvm_cbe_1749_count = 0;
  unsigned int llvm_cbe_tmp__631;
  static  unsigned long long aesl_llvm_cbe_1750_count = 0;
  static  unsigned long long aesl_llvm_cbe_1751_count = 0;
  unsigned char llvm_cbe_tmp__632;
  static  unsigned long long aesl_llvm_cbe_1752_count = 0;
  unsigned int llvm_cbe_tmp__633;
  static  unsigned long long aesl_llvm_cbe_1753_count = 0;
  unsigned int llvm_cbe_tmp__634;
  static  unsigned long long aesl_llvm_cbe_1754_count = 0;
  unsigned int llvm_cbe_tmp__635;
  static  unsigned long long aesl_llvm_cbe_1755_count = 0;
  unsigned long long llvm_cbe_tmp__636;
  static  unsigned long long aesl_llvm_cbe_1756_count = 0;
  signed int *llvm_cbe_tmp__637;
  static  unsigned long long aesl_llvm_cbe_1757_count = 0;
  static  unsigned long long aesl_llvm_cbe_1758_count = 0;
  unsigned int llvm_cbe_tmp__638;
  static  unsigned long long aesl_llvm_cbe_1759_count = 0;
  unsigned long long llvm_cbe_tmp__639;
  static  unsigned long long aesl_llvm_cbe_1760_count = 0;
   char *llvm_cbe_tmp__640;
  static  unsigned long long aesl_llvm_cbe_1761_count = 0;
  unsigned char llvm_cbe_tmp__641;
  static  unsigned long long aesl_llvm_cbe_1762_count = 0;
  unsigned int llvm_cbe_tmp__642;
  static  unsigned long long aesl_llvm_cbe_1763_count = 0;
  unsigned int llvm_cbe_tmp__643;
  static  unsigned long long aesl_llvm_cbe_1764_count = 0;
  unsigned int llvm_cbe_tmp__644;
  static  unsigned long long aesl_llvm_cbe_1765_count = 0;
  static  unsigned long long aesl_llvm_cbe_1766_count = 0;
  unsigned int llvm_cbe_tmp__645;
  static  unsigned long long aesl_llvm_cbe_1767_count = 0;
  unsigned long long llvm_cbe_tmp__646;
  static  unsigned long long aesl_llvm_cbe_1768_count = 0;
   char *llvm_cbe_tmp__647;
  static  unsigned long long aesl_llvm_cbe_1769_count = 0;
  unsigned char llvm_cbe_tmp__648;
  static  unsigned long long aesl_llvm_cbe_1770_count = 0;
  unsigned int llvm_cbe_tmp__649;
  static  unsigned long long aesl_llvm_cbe_1771_count = 0;
  unsigned int llvm_cbe_tmp__650;
  static  unsigned long long aesl_llvm_cbe_1772_count = 0;
  unsigned int llvm_cbe_tmp__651;
  static  unsigned long long aesl_llvm_cbe_1773_count = 0;
  unsigned int llvm_cbe_tmp__652;
  static  unsigned long long aesl_llvm_cbe_1774_count = 0;
  static  unsigned long long aesl_llvm_cbe_1775_count = 0;
  unsigned char llvm_cbe_tmp__653;
  static  unsigned long long aesl_llvm_cbe_1776_count = 0;
  unsigned int llvm_cbe_tmp__654;
  static  unsigned long long aesl_llvm_cbe_1777_count = 0;
  unsigned int llvm_cbe_tmp__655;
  static  unsigned long long aesl_llvm_cbe_1778_count = 0;
  unsigned int llvm_cbe_tmp__656;
  static  unsigned long long aesl_llvm_cbe_1779_count = 0;
  unsigned long long llvm_cbe_tmp__657;
  static  unsigned long long aesl_llvm_cbe_1780_count = 0;
  signed int *llvm_cbe_tmp__658;
  static  unsigned long long aesl_llvm_cbe_1781_count = 0;
  static  unsigned long long aesl_llvm_cbe_1782_count = 0;
  unsigned int llvm_cbe_tmp__659;
  static  unsigned long long aesl_llvm_cbe_1783_count = 0;
  unsigned long long llvm_cbe_tmp__660;
  static  unsigned long long aesl_llvm_cbe_1784_count = 0;
   char *llvm_cbe_tmp__661;
  static  unsigned long long aesl_llvm_cbe_1785_count = 0;
  unsigned char llvm_cbe_tmp__662;
  static  unsigned long long aesl_llvm_cbe_1786_count = 0;
  unsigned int llvm_cbe_tmp__663;
  static  unsigned long long aesl_llvm_cbe_1787_count = 0;
  unsigned int llvm_cbe_tmp__664;
  static  unsigned long long aesl_llvm_cbe_1788_count = 0;
  unsigned int llvm_cbe_tmp__665;
  static  unsigned long long aesl_llvm_cbe_1789_count = 0;
  static  unsigned long long aesl_llvm_cbe_1790_count = 0;
  unsigned int llvm_cbe_tmp__666;
  static  unsigned long long aesl_llvm_cbe_1791_count = 0;
  unsigned long long llvm_cbe_tmp__667;
  static  unsigned long long aesl_llvm_cbe_1792_count = 0;
   char *llvm_cbe_tmp__668;
  static  unsigned long long aesl_llvm_cbe_1793_count = 0;
  unsigned char llvm_cbe_tmp__669;
  static  unsigned long long aesl_llvm_cbe_1794_count = 0;
  unsigned int llvm_cbe_tmp__670;
  static  unsigned long long aesl_llvm_cbe_1795_count = 0;
  unsigned int llvm_cbe_tmp__671;
  static  unsigned long long aesl_llvm_cbe_1796_count = 0;
  unsigned int llvm_cbe_tmp__672;
  static  unsigned long long aesl_llvm_cbe_1797_count = 0;
  unsigned int llvm_cbe_tmp__673;
  static  unsigned long long aesl_llvm_cbe_1798_count = 0;
  static  unsigned long long aesl_llvm_cbe_1799_count = 0;
  unsigned char llvm_cbe_tmp__674;
  static  unsigned long long aesl_llvm_cbe_1800_count = 0;
  unsigned int llvm_cbe_tmp__675;
  static  unsigned long long aesl_llvm_cbe_1801_count = 0;
  unsigned int llvm_cbe_tmp__676;
  static  unsigned long long aesl_llvm_cbe_1802_count = 0;
  unsigned int llvm_cbe_tmp__677;
  static  unsigned long long aesl_llvm_cbe_1803_count = 0;
  unsigned long long llvm_cbe_tmp__678;
  static  unsigned long long aesl_llvm_cbe_1804_count = 0;
  signed int *llvm_cbe_tmp__679;
  static  unsigned long long aesl_llvm_cbe_1805_count = 0;
  static  unsigned long long aesl_llvm_cbe_1806_count = 0;
  unsigned int llvm_cbe_tmp__680;
  static  unsigned long long aesl_llvm_cbe_1807_count = 0;
  unsigned long long llvm_cbe_tmp__681;
  static  unsigned long long aesl_llvm_cbe_1808_count = 0;
   char *llvm_cbe_tmp__682;
  static  unsigned long long aesl_llvm_cbe_1809_count = 0;
  unsigned char llvm_cbe_tmp__683;
  static  unsigned long long aesl_llvm_cbe_1810_count = 0;
  unsigned int llvm_cbe_tmp__684;
  static  unsigned long long aesl_llvm_cbe_1811_count = 0;
  unsigned int llvm_cbe_tmp__685;
  static  unsigned long long aesl_llvm_cbe_1812_count = 0;
  unsigned int llvm_cbe_tmp__686;
  static  unsigned long long aesl_llvm_cbe_1813_count = 0;
  unsigned int llvm_cbe_tmp__687;
  static  unsigned long long aesl_llvm_cbe_1814_count = 0;
  static  unsigned long long aesl_llvm_cbe_1815_count = 0;
  unsigned char llvm_cbe_tmp__688;
  static  unsigned long long aesl_llvm_cbe_1816_count = 0;
  unsigned int llvm_cbe_tmp__689;
  static  unsigned long long aesl_llvm_cbe_1817_count = 0;
  unsigned int llvm_cbe_tmp__690;
  static  unsigned long long aesl_llvm_cbe_1818_count = 0;
  unsigned int llvm_cbe_tmp__691;
  static  unsigned long long aesl_llvm_cbe_1819_count = 0;
  unsigned long long llvm_cbe_tmp__692;
  static  unsigned long long aesl_llvm_cbe_1820_count = 0;
  signed int *llvm_cbe_tmp__693;
  static  unsigned long long aesl_llvm_cbe_1821_count = 0;
  static  unsigned long long aesl_llvm_cbe_1822_count = 0;
  unsigned int llvm_cbe_tmp__694;
  static  unsigned long long aesl_llvm_cbe_1823_count = 0;
  unsigned long long llvm_cbe_tmp__695;
  static  unsigned long long aesl_llvm_cbe_1824_count = 0;
   char *llvm_cbe_tmp__696;
  static  unsigned long long aesl_llvm_cbe_1825_count = 0;
  unsigned char llvm_cbe_tmp__697;
  static  unsigned long long aesl_llvm_cbe_1826_count = 0;
  unsigned int llvm_cbe_tmp__698;
  static  unsigned long long aesl_llvm_cbe_1827_count = 0;
  unsigned int llvm_cbe_tmp__699;
  static  unsigned long long aesl_llvm_cbe_1828_count = 0;
  unsigned int llvm_cbe_tmp__700;
  static  unsigned long long aesl_llvm_cbe_1829_count = 0;
  static  unsigned long long aesl_llvm_cbe_1830_count = 0;
  unsigned int llvm_cbe_tmp__701;
  static  unsigned long long aesl_llvm_cbe_1831_count = 0;
  unsigned long long llvm_cbe_tmp__702;
  static  unsigned long long aesl_llvm_cbe_1832_count = 0;
   char *llvm_cbe_tmp__703;
  static  unsigned long long aesl_llvm_cbe_1833_count = 0;
  unsigned char llvm_cbe_tmp__704;
  static  unsigned long long aesl_llvm_cbe_1834_count = 0;
  unsigned int llvm_cbe_tmp__705;
  static  unsigned long long aesl_llvm_cbe_1835_count = 0;
  unsigned int llvm_cbe_tmp__706;
  static  unsigned long long aesl_llvm_cbe_1836_count = 0;
  unsigned int llvm_cbe_tmp__707;
  static  unsigned long long aesl_llvm_cbe_1837_count = 0;
  unsigned int llvm_cbe_tmp__708;
  static  unsigned long long aesl_llvm_cbe_1838_count = 0;
  static  unsigned long long aesl_llvm_cbe_1839_count = 0;
  unsigned char llvm_cbe_tmp__709;
  static  unsigned long long aesl_llvm_cbe_1840_count = 0;
  unsigned int llvm_cbe_tmp__710;
  static  unsigned long long aesl_llvm_cbe_1841_count = 0;
  unsigned int llvm_cbe_tmp__711;
  static  unsigned long long aesl_llvm_cbe_1842_count = 0;
  unsigned int llvm_cbe_tmp__712;
  static  unsigned long long aesl_llvm_cbe_1843_count = 0;
  unsigned long long llvm_cbe_tmp__713;
  static  unsigned long long aesl_llvm_cbe_1844_count = 0;
  signed int *llvm_cbe_tmp__714;
  static  unsigned long long aesl_llvm_cbe_1845_count = 0;
  static  unsigned long long aesl_llvm_cbe_1846_count = 0;
  unsigned int llvm_cbe_tmp__715;
  static  unsigned long long aesl_llvm_cbe_1847_count = 0;
  unsigned long long llvm_cbe_tmp__716;
  static  unsigned long long aesl_llvm_cbe_1848_count = 0;
   char *llvm_cbe_tmp__717;
  static  unsigned long long aesl_llvm_cbe_1849_count = 0;
  unsigned char llvm_cbe_tmp__718;
  static  unsigned long long aesl_llvm_cbe_1850_count = 0;
  unsigned int llvm_cbe_tmp__719;
  static  unsigned long long aesl_llvm_cbe_1851_count = 0;
  unsigned int llvm_cbe_tmp__720;
  static  unsigned long long aesl_llvm_cbe_1852_count = 0;
  unsigned int llvm_cbe_tmp__721;
  static  unsigned long long aesl_llvm_cbe_1853_count = 0;
  unsigned int llvm_cbe_tmp__722;
  static  unsigned long long aesl_llvm_cbe_1854_count = 0;
  static  unsigned long long aesl_llvm_cbe_1855_count = 0;
  unsigned int llvm_cbe_tmp__723;
  static  unsigned long long aesl_llvm_cbe_1856_count = 0;
  static  unsigned long long aesl_llvm_cbe_1857_count = 0;
  unsigned int llvm_cbe_tmp__724;
  static  unsigned long long aesl_llvm_cbe_1858_count = 0;
  static  unsigned long long aesl_llvm_cbe_1859_count = 0;
  unsigned int llvm_cbe_tmp__725;
  static  unsigned long long aesl_llvm_cbe_1860_count = 0;
  static  unsigned long long aesl_llvm_cbe_1861_count = 0;
  unsigned int llvm_cbe_tmp__726;
  static  unsigned long long aesl_llvm_cbe_1862_count = 0;
  static  unsigned long long aesl_llvm_cbe_1863_count = 0;
  unsigned int llvm_cbe_tmp__727;
  static  unsigned long long aesl_llvm_cbe_1864_count = 0;
  static  unsigned long long aesl_llvm_cbe_1865_count = 0;
  unsigned int llvm_cbe_tmp__728;
  static  unsigned long long aesl_llvm_cbe_1866_count = 0;
  static  unsigned long long aesl_llvm_cbe_1867_count = 0;
  unsigned int llvm_cbe_tmp__729;
  static  unsigned long long aesl_llvm_cbe_1868_count = 0;
  static  unsigned long long aesl_llvm_cbe_1869_count = 0;
  unsigned int llvm_cbe_tmp__730;
  static  unsigned long long aesl_llvm_cbe_1870_count = 0;
  static  unsigned long long aesl_llvm_cbe_1871_count = 0;
  static  unsigned long long aesl_llvm_cbe_1872_count = 0;
  static  unsigned long long aesl_llvm_cbe_1873_count = 0;
  static  unsigned long long aesl_llvm_cbe_1874_count = 0;
  static  unsigned long long aesl_llvm_cbe_1875_count = 0;
  static  unsigned long long aesl_llvm_cbe_1876_count = 0;
  static  unsigned long long aesl_llvm_cbe_1877_count = 0;
  static  unsigned long long aesl_llvm_cbe_1878_count = 0;
  static  unsigned long long aesl_llvm_cbe_1879_count = 0;
  static  unsigned long long aesl_llvm_cbe_1880_count = 0;
  static  unsigned long long aesl_llvm_cbe_1881_count = 0;
  static  unsigned long long aesl_llvm_cbe_1882_count = 0;
  static  unsigned long long aesl_llvm_cbe_1883_count = 0;
  static  unsigned long long aesl_llvm_cbe_1884_count = 0;
  static  unsigned long long aesl_llvm_cbe_1885_count = 0;
  static  unsigned long long aesl_llvm_cbe_1886_count = 0;
  static  unsigned long long aesl_llvm_cbe_1887_count = 0;
  static  unsigned long long aesl_llvm_cbe_1888_count = 0;
  static  unsigned long long aesl_llvm_cbe_1889_count = 0;
  static  unsigned long long aesl_llvm_cbe_1890_count = 0;
  static  unsigned long long aesl_llvm_cbe_1891_count = 0;
  static  unsigned long long aesl_llvm_cbe_1892_count = 0;
  static  unsigned long long aesl_llvm_cbe_1893_count = 0;
  static  unsigned long long aesl_llvm_cbe_1894_count = 0;
  static  unsigned long long aesl_llvm_cbe_1895_count = 0;
  static  unsigned long long aesl_llvm_cbe_1896_count = 0;
  static  unsigned long long aesl_llvm_cbe_1897_count = 0;
  static  unsigned long long aesl_llvm_cbe_1898_count = 0;
  static  unsigned long long aesl_llvm_cbe_1899_count = 0;
  static  unsigned long long aesl_llvm_cbe_1900_count = 0;
  static  unsigned long long aesl_llvm_cbe_1901_count = 0;
  static  unsigned long long aesl_llvm_cbe_1902_count = 0;
  static  unsigned long long aesl_llvm_cbe_1903_count = 0;
  static  unsigned long long aesl_llvm_cbe_1904_count = 0;
  static  unsigned long long aesl_llvm_cbe_1905_count = 0;
  static  unsigned long long aesl_llvm_cbe_1906_count = 0;
  static  unsigned long long aesl_llvm_cbe_1907_count = 0;
  static  unsigned long long aesl_llvm_cbe_1908_count = 0;
  static  unsigned long long aesl_llvm_cbe_1909_count = 0;
  static  unsigned long long aesl_llvm_cbe_1910_count = 0;
  static  unsigned long long aesl_llvm_cbe_1911_count = 0;
  static  unsigned long long aesl_llvm_cbe_1912_count = 0;
  static  unsigned long long aesl_llvm_cbe_1913_count = 0;
  static  unsigned long long aesl_llvm_cbe_1914_count = 0;
  static  unsigned long long aesl_llvm_cbe_1915_count = 0;
  static  unsigned long long aesl_llvm_cbe_1916_count = 0;
  static  unsigned long long aesl_llvm_cbe_1917_count = 0;
  static  unsigned long long aesl_llvm_cbe_1918_count = 0;
  static  unsigned long long aesl_llvm_cbe_1919_count = 0;
  static  unsigned long long aesl_llvm_cbe_1920_count = 0;
  static  unsigned long long aesl_llvm_cbe_1921_count = 0;
  static  unsigned long long aesl_llvm_cbe_1922_count = 0;
  static  unsigned long long aesl_llvm_cbe_1923_count = 0;
  static  unsigned long long aesl_llvm_cbe_1924_count = 0;
  static  unsigned long long aesl_llvm_cbe_1925_count = 0;
  static  unsigned long long aesl_llvm_cbe_1926_count = 0;
  static  unsigned long long aesl_llvm_cbe_1927_count = 0;
  static  unsigned long long aesl_llvm_cbe_1928_count = 0;
  static  unsigned long long aesl_llvm_cbe_1929_count = 0;
  static  unsigned long long aesl_llvm_cbe_1930_count = 0;
  static  unsigned long long aesl_llvm_cbe_1931_count = 0;
  static  unsigned long long aesl_llvm_cbe_1932_count = 0;
  static  unsigned long long aesl_llvm_cbe_1933_count = 0;
  static  unsigned long long aesl_llvm_cbe_1934_count = 0;
  static  unsigned long long aesl_llvm_cbe_1935_count = 0;
  static  unsigned long long aesl_llvm_cbe_1936_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1937_count = 0;
  static  unsigned long long aesl_llvm_cbe_1938_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_polyt0_unpack\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__731;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__731:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%151, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__730);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = mul i32 %%storemerge1, 13, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1693_count);
  llvm_cbe_tmp__581 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) * ((unsigned int )(13u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__581&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1694_count);
  llvm_cbe_tmp__582 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__581&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__582);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i8* %%a, i64 %%3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1695_count);
  llvm_cbe_tmp__583 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__582))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__582));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i8* %%4, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1696_count);
  llvm_cbe_tmp__584 = (unsigned char )*llvm_cbe_tmp__583;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__584);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i8 %%5 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1697_count);
  llvm_cbe_tmp__585 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__584&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__585);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = shl i32 %%storemerge1, 3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1698_count);
  llvm_cbe_tmp__586 = (unsigned int )llvm_cbe_storemerge1 << 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__586);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i32 %%7 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1699_count);
  llvm_cbe_tmp__587 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__586&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__587);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1700_count);
  llvm_cbe_tmp__588 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__587))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__587));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%6, i32* %%9, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1701_count);
  *llvm_cbe_tmp__588 = llvm_cbe_tmp__585;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__585);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i32 %%2, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1702_count);
  llvm_cbe_tmp__589 = (unsigned int )((unsigned int )(llvm_cbe_tmp__581&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__589&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i32 %%10 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1703_count);
  llvm_cbe_tmp__590 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__589&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__590);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds i8* %%a, i64 %%11, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1704_count);
  llvm_cbe_tmp__591 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__590))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__590));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i8* %%12, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1705_count);
  llvm_cbe_tmp__592 = (unsigned char )*llvm_cbe_tmp__591;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__592);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i8 %%13 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1706_count);
  llvm_cbe_tmp__593 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__592&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__593);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = shl nuw nsw i32 %%14, 8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1707_count);
  llvm_cbe_tmp__594 = (unsigned int )llvm_cbe_tmp__593 << 8u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__594);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = and i32 %%15, 7936, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1708_count);
  llvm_cbe_tmp__595 = (unsigned int )llvm_cbe_tmp__594 & 7936u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__595);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = or i32 %%16, %%6, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1709_count);
  llvm_cbe_tmp__596 = (unsigned int )llvm_cbe_tmp__595 | llvm_cbe_tmp__585;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__596);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%17, i32* %%9, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1710_count);
  *llvm_cbe_tmp__588 = llvm_cbe_tmp__596;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__596);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i8* %%12, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1711_count);
  llvm_cbe_tmp__597 = (unsigned char )*llvm_cbe_tmp__591;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__597);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = zext i8 %%18 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1712_count);
  llvm_cbe_tmp__598 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__597&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__598);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = lshr i32 %%19, 5, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1713_count);
  llvm_cbe_tmp__599 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__598&4294967295ull)) >> ((unsigned int )(5u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__599&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = or i32 %%7, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1714_count);
  llvm_cbe_tmp__600 = (unsigned int )llvm_cbe_tmp__586 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__600);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = zext i32 %%21 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1715_count);
  llvm_cbe_tmp__601 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__600&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__601);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%22, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1716_count);
  llvm_cbe_tmp__602 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__601))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__601));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%20, i32* %%23, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1717_count);
  *llvm_cbe_tmp__602 = llvm_cbe_tmp__599;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__599);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i32 %%2, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1718_count);
  llvm_cbe_tmp__603 = (unsigned int )((unsigned int )(llvm_cbe_tmp__581&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__603&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = zext i32 %%24 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1719_count);
  llvm_cbe_tmp__604 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__603&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__604);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds i8* %%a, i64 %%25, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1720_count);
  llvm_cbe_tmp__605 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__604))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__604));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i8* %%26, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1721_count);
  llvm_cbe_tmp__606 = (unsigned char )*llvm_cbe_tmp__605;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__606);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = zext i8 %%27 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1722_count);
  llvm_cbe_tmp__607 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__606&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__607);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = shl nuw nsw i32 %%28, 3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1723_count);
  llvm_cbe_tmp__608 = (unsigned int )llvm_cbe_tmp__607 << 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__608);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = or i32 %%29, %%20, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1724_count);
  llvm_cbe_tmp__609 = (unsigned int )llvm_cbe_tmp__608 | llvm_cbe_tmp__599;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__609);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%30, i32* %%23, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1725_count);
  *llvm_cbe_tmp__602 = llvm_cbe_tmp__609;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__609);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add i32 %%2, 3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1726_count);
  llvm_cbe_tmp__610 = (unsigned int )((unsigned int )(llvm_cbe_tmp__581&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__610&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = zext i32 %%31 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1727_count);
  llvm_cbe_tmp__611 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__610&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__611);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds i8* %%a, i64 %%32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1728_count);
  llvm_cbe_tmp__612 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__611))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__611));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i8* %%33, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1729_count);
  llvm_cbe_tmp__613 = (unsigned char )*llvm_cbe_tmp__612;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__613);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = zext i8 %%34 to i32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1730_count);
  llvm_cbe_tmp__614 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__613&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__614);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = shl nuw nsw i32 %%35, 11, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1731_count);
  llvm_cbe_tmp__615 = (unsigned int )llvm_cbe_tmp__614 << 11u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__615);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = and i32 %%36, 6144, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1732_count);
  llvm_cbe_tmp__616 = (unsigned int )llvm_cbe_tmp__615 & 6144u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__616);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = or i32 %%37, %%30, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1733_count);
  llvm_cbe_tmp__617 = (unsigned int )llvm_cbe_tmp__616 | llvm_cbe_tmp__609;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__617);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%38, i32* %%23, align 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1734_count);
  *llvm_cbe_tmp__602 = llvm_cbe_tmp__617;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__617);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i8* %%33, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1735_count);
  llvm_cbe_tmp__618 = (unsigned char )*llvm_cbe_tmp__612;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__618);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = zext i8 %%39 to i32, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1736_count);
  llvm_cbe_tmp__619 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__618&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__619);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = lshr i32 %%40, 2, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1737_count);
  llvm_cbe_tmp__620 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__619&4294967295ull)) >> ((unsigned int )(2u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__620&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = or i32 %%7, 2, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1738_count);
  llvm_cbe_tmp__621 = (unsigned int )llvm_cbe_tmp__586 | 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__621);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = zext i32 %%42 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1739_count);
  llvm_cbe_tmp__622 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__621&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__622);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%43, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1740_count);
  llvm_cbe_tmp__623 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__622))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__622));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%41, i32* %%44, align 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1741_count);
  *llvm_cbe_tmp__623 = llvm_cbe_tmp__620;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__620);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = add i32 %%2, 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1742_count);
  llvm_cbe_tmp__624 = (unsigned int )((unsigned int )(llvm_cbe_tmp__581&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__624&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = zext i32 %%45 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1743_count);
  llvm_cbe_tmp__625 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__624&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__625);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = getelementptr inbounds i8* %%a, i64 %%46, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1744_count);
  llvm_cbe_tmp__626 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__625))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__625));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load i8* %%47, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1745_count);
  llvm_cbe_tmp__627 = (unsigned char )*llvm_cbe_tmp__626;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__627);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = zext i8 %%48 to i32, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1746_count);
  llvm_cbe_tmp__628 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__627&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__628);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = shl nuw nsw i32 %%49, 6, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1747_count);
  llvm_cbe_tmp__629 = (unsigned int )llvm_cbe_tmp__628 << 6u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__629);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = and i32 %%50, 8128, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1748_count);
  llvm_cbe_tmp__630 = (unsigned int )llvm_cbe_tmp__629 & 8128u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__630);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = or i32 %%51, %%41, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1749_count);
  llvm_cbe_tmp__631 = (unsigned int )llvm_cbe_tmp__630 | llvm_cbe_tmp__620;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__631);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%52, i32* %%44, align 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1750_count);
  *llvm_cbe_tmp__623 = llvm_cbe_tmp__631;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__631);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = load i8* %%47, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1751_count);
  llvm_cbe_tmp__632 = (unsigned char )*llvm_cbe_tmp__626;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__632);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = zext i8 %%53 to i32, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1752_count);
  llvm_cbe_tmp__633 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__632&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__633);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = lshr i32 %%54, 7, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1753_count);
  llvm_cbe_tmp__634 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__633&4294967295ull)) >> ((unsigned int )(7u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__634&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = or i32 %%7, 3, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1754_count);
  llvm_cbe_tmp__635 = (unsigned int )llvm_cbe_tmp__586 | 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__635);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = zext i32 %%56 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1755_count);
  llvm_cbe_tmp__636 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__635&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__636);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%57, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1756_count);
  llvm_cbe_tmp__637 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__636))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__636));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%55, i32* %%58, align 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1757_count);
  *llvm_cbe_tmp__637 = llvm_cbe_tmp__634;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__634);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add i32 %%2, 5, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1758_count);
  llvm_cbe_tmp__638 = (unsigned int )((unsigned int )(llvm_cbe_tmp__581&4294967295ull)) + ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__638&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = zext i32 %%59 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1759_count);
  llvm_cbe_tmp__639 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__638&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__639);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = getelementptr inbounds i8* %%a, i64 %%60, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1760_count);
  llvm_cbe_tmp__640 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__639))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__639));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = load i8* %%61, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1761_count);
  llvm_cbe_tmp__641 = (unsigned char )*llvm_cbe_tmp__640;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__641);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = zext i8 %%62 to i32, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1762_count);
  llvm_cbe_tmp__642 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__641&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__642);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = shl nuw nsw i32 %%63, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1763_count);
  llvm_cbe_tmp__643 = (unsigned int )llvm_cbe_tmp__642 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__643);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = or i32 %%64, %%55, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1764_count);
  llvm_cbe_tmp__644 = (unsigned int )llvm_cbe_tmp__643 | llvm_cbe_tmp__634;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__644);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%65, i32* %%58, align 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1765_count);
  *llvm_cbe_tmp__637 = llvm_cbe_tmp__644;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__644);
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = add i32 %%2, 6, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1766_count);
  llvm_cbe_tmp__645 = (unsigned int )((unsigned int )(llvm_cbe_tmp__581&4294967295ull)) + ((unsigned int )(6u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__645&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = zext i32 %%66 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1767_count);
  llvm_cbe_tmp__646 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__645&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__646);
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = getelementptr inbounds i8* %%a, i64 %%67, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1768_count);
  llvm_cbe_tmp__647 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__646))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__646));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = load i8* %%68, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1769_count);
  llvm_cbe_tmp__648 = (unsigned char )*llvm_cbe_tmp__647;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__648);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = zext i8 %%69 to i32, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1770_count);
  llvm_cbe_tmp__649 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__648&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__649);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = shl nuw nsw i32 %%70, 9, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1771_count);
  llvm_cbe_tmp__650 = (unsigned int )llvm_cbe_tmp__649 << 9u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__650);
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = and i32 %%71, 7680, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1772_count);
  llvm_cbe_tmp__651 = (unsigned int )llvm_cbe_tmp__650 & 7680u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__651);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = or i32 %%72, %%65, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1773_count);
  llvm_cbe_tmp__652 = (unsigned int )llvm_cbe_tmp__651 | llvm_cbe_tmp__644;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__652);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%73, i32* %%58, align 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1774_count);
  *llvm_cbe_tmp__637 = llvm_cbe_tmp__652;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__652);
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = load i8* %%68, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1775_count);
  llvm_cbe_tmp__653 = (unsigned char )*llvm_cbe_tmp__647;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__653);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = zext i8 %%74 to i32, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1776_count);
  llvm_cbe_tmp__654 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__653&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__654);
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = lshr i32 %%75, 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1777_count);
  llvm_cbe_tmp__655 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__654&4294967295ull)) >> ((unsigned int )(4u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__655&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = or i32 %%7, 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1778_count);
  llvm_cbe_tmp__656 = (unsigned int )llvm_cbe_tmp__586 | 4u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__656);
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = zext i32 %%77 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1779_count);
  llvm_cbe_tmp__657 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__656&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__657);
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%78, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1780_count);
  llvm_cbe_tmp__658 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__657))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__657));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%76, i32* %%79, align 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1781_count);
  *llvm_cbe_tmp__658 = llvm_cbe_tmp__655;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__655);
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = add i32 %%2, 7, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1782_count);
  llvm_cbe_tmp__659 = (unsigned int )((unsigned int )(llvm_cbe_tmp__581&4294967295ull)) + ((unsigned int )(7u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__659&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = zext i32 %%80 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1783_count);
  llvm_cbe_tmp__660 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__659&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__660);
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = getelementptr inbounds i8* %%a, i64 %%81, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1784_count);
  llvm_cbe_tmp__661 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__660))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__660));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = load i8* %%82, align 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1785_count);
  llvm_cbe_tmp__662 = (unsigned char )*llvm_cbe_tmp__661;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__662);
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = zext i8 %%83 to i32, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1786_count);
  llvm_cbe_tmp__663 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__662&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__663);
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = shl nuw nsw i32 %%84, 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1787_count);
  llvm_cbe_tmp__664 = (unsigned int )llvm_cbe_tmp__663 << 4u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__664);
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = or i32 %%85, %%76, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1788_count);
  llvm_cbe_tmp__665 = (unsigned int )llvm_cbe_tmp__664 | llvm_cbe_tmp__655;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__665);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%86, i32* %%79, align 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1789_count);
  *llvm_cbe_tmp__658 = llvm_cbe_tmp__665;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__665);
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = add i32 %%2, 8, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1790_count);
  llvm_cbe_tmp__666 = (unsigned int )((unsigned int )(llvm_cbe_tmp__581&4294967295ull)) + ((unsigned int )(8u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__666&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = zext i32 %%87 to i64, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1791_count);
  llvm_cbe_tmp__667 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__666&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__667);
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = getelementptr inbounds i8* %%a, i64 %%88, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1792_count);
  llvm_cbe_tmp__668 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__667))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__667));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = load i8* %%89, align 1, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1793_count);
  llvm_cbe_tmp__669 = (unsigned char )*llvm_cbe_tmp__668;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__669);
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = zext i8 %%90 to i32, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1794_count);
  llvm_cbe_tmp__670 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__669&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__670);
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = shl nuw nsw i32 %%91, 12, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1795_count);
  llvm_cbe_tmp__671 = (unsigned int )llvm_cbe_tmp__670 << 12u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__671);
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = and i32 %%92, 4096, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1796_count);
  llvm_cbe_tmp__672 = (unsigned int )llvm_cbe_tmp__671 & 4096u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__672);
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = or i32 %%93, %%86, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1797_count);
  llvm_cbe_tmp__673 = (unsigned int )llvm_cbe_tmp__672 | llvm_cbe_tmp__665;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__673);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%94, i32* %%79, align 4, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1798_count);
  *llvm_cbe_tmp__658 = llvm_cbe_tmp__673;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__673);
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = load i8* %%89, align 1, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1799_count);
  llvm_cbe_tmp__674 = (unsigned char )*llvm_cbe_tmp__668;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__674);
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = zext i8 %%95 to i32, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1800_count);
  llvm_cbe_tmp__675 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__674&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__675);
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = lshr i32 %%96, 1, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1801_count);
  llvm_cbe_tmp__676 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__675&4294967295ull)) >> ((unsigned int )(1u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__676&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = or i32 %%7, 5, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1802_count);
  llvm_cbe_tmp__677 = (unsigned int )llvm_cbe_tmp__586 | 5u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__677);
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = zext i32 %%98 to i64, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1803_count);
  llvm_cbe_tmp__678 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__677&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__678);
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%99, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1804_count);
  llvm_cbe_tmp__679 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__678))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__678));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%97, i32* %%100, align 4, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1805_count);
  *llvm_cbe_tmp__679 = llvm_cbe_tmp__676;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__676);
if (AESL_DEBUG_TRACE)
printf("\n  %%101 = add i32 %%2, 9, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1806_count);
  llvm_cbe_tmp__680 = (unsigned int )((unsigned int )(llvm_cbe_tmp__581&4294967295ull)) + ((unsigned int )(9u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__680&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = zext i32 %%101 to i64, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1807_count);
  llvm_cbe_tmp__681 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__680&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__681);
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = getelementptr inbounds i8* %%a, i64 %%102, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1808_count);
  llvm_cbe_tmp__682 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__681))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__681));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = load i8* %%103, align 1, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1809_count);
  llvm_cbe_tmp__683 = (unsigned char )*llvm_cbe_tmp__682;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__683);
if (AESL_DEBUG_TRACE)
printf("\n  %%105 = zext i8 %%104 to i32, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1810_count);
  llvm_cbe_tmp__684 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__683&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__684);
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = shl nuw nsw i32 %%105, 7, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1811_count);
  llvm_cbe_tmp__685 = (unsigned int )llvm_cbe_tmp__684 << 7u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__685);
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = and i32 %%106, 8064, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1812_count);
  llvm_cbe_tmp__686 = (unsigned int )llvm_cbe_tmp__685 & 8064u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__686);
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = or i32 %%107, %%97, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1813_count);
  llvm_cbe_tmp__687 = (unsigned int )llvm_cbe_tmp__686 | llvm_cbe_tmp__676;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__687);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%108, i32* %%100, align 4, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1814_count);
  *llvm_cbe_tmp__679 = llvm_cbe_tmp__687;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__687);
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = load i8* %%103, align 1, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1815_count);
  llvm_cbe_tmp__688 = (unsigned char )*llvm_cbe_tmp__682;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__688);
if (AESL_DEBUG_TRACE)
printf("\n  %%110 = zext i8 %%109 to i32, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1816_count);
  llvm_cbe_tmp__689 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__688&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__689);
if (AESL_DEBUG_TRACE)
printf("\n  %%111 = lshr i32 %%110, 6, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1817_count);
  llvm_cbe_tmp__690 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__689&4294967295ull)) >> ((unsigned int )(6u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__690&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%112 = or i32 %%7, 6, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1818_count);
  llvm_cbe_tmp__691 = (unsigned int )llvm_cbe_tmp__586 | 6u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__691);
if (AESL_DEBUG_TRACE)
printf("\n  %%113 = zext i32 %%112 to i64, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1819_count);
  llvm_cbe_tmp__692 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__691&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__692);
if (AESL_DEBUG_TRACE)
printf("\n  %%114 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%113, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1820_count);
  llvm_cbe_tmp__693 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__692))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__692));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%111, i32* %%114, align 4, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1821_count);
  *llvm_cbe_tmp__693 = llvm_cbe_tmp__690;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__690);
if (AESL_DEBUG_TRACE)
printf("\n  %%115 = add i32 %%2, 10, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1822_count);
  llvm_cbe_tmp__694 = (unsigned int )((unsigned int )(llvm_cbe_tmp__581&4294967295ull)) + ((unsigned int )(10u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__694&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%116 = zext i32 %%115 to i64, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1823_count);
  llvm_cbe_tmp__695 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__694&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__695);
if (AESL_DEBUG_TRACE)
printf("\n  %%117 = getelementptr inbounds i8* %%a, i64 %%116, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1824_count);
  llvm_cbe_tmp__696 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__695))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__695));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%118 = load i8* %%117, align 1, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1825_count);
  llvm_cbe_tmp__697 = (unsigned char )*llvm_cbe_tmp__696;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__697);
if (AESL_DEBUG_TRACE)
printf("\n  %%119 = zext i8 %%118 to i32, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1826_count);
  llvm_cbe_tmp__698 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__697&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__698);
if (AESL_DEBUG_TRACE)
printf("\n  %%120 = shl nuw nsw i32 %%119, 2, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1827_count);
  llvm_cbe_tmp__699 = (unsigned int )llvm_cbe_tmp__698 << 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__699);
if (AESL_DEBUG_TRACE)
printf("\n  %%121 = or i32 %%120, %%111, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1828_count);
  llvm_cbe_tmp__700 = (unsigned int )llvm_cbe_tmp__699 | llvm_cbe_tmp__690;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__700);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%121, i32* %%114, align 4, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1829_count);
  *llvm_cbe_tmp__693 = llvm_cbe_tmp__700;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__700);
if (AESL_DEBUG_TRACE)
printf("\n  %%122 = add i32 %%2, 11, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1830_count);
  llvm_cbe_tmp__701 = (unsigned int )((unsigned int )(llvm_cbe_tmp__581&4294967295ull)) + ((unsigned int )(11u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__701&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%123 = zext i32 %%122 to i64, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1831_count);
  llvm_cbe_tmp__702 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__701&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__702);
if (AESL_DEBUG_TRACE)
printf("\n  %%124 = getelementptr inbounds i8* %%a, i64 %%123, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1832_count);
  llvm_cbe_tmp__703 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__702))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__702));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%125 = load i8* %%124, align 1, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1833_count);
  llvm_cbe_tmp__704 = (unsigned char )*llvm_cbe_tmp__703;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__704);
if (AESL_DEBUG_TRACE)
printf("\n  %%126 = zext i8 %%125 to i32, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1834_count);
  llvm_cbe_tmp__705 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__704&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__705);
if (AESL_DEBUG_TRACE)
printf("\n  %%127 = shl nuw nsw i32 %%126, 10, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1835_count);
  llvm_cbe_tmp__706 = (unsigned int )llvm_cbe_tmp__705 << 10u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__706);
if (AESL_DEBUG_TRACE)
printf("\n  %%128 = and i32 %%127, 7168, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1836_count);
  llvm_cbe_tmp__707 = (unsigned int )llvm_cbe_tmp__706 & 7168u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__707);
if (AESL_DEBUG_TRACE)
printf("\n  %%129 = or i32 %%128, %%121, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1837_count);
  llvm_cbe_tmp__708 = (unsigned int )llvm_cbe_tmp__707 | llvm_cbe_tmp__700;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__708);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%129, i32* %%114, align 4, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1838_count);
  *llvm_cbe_tmp__693 = llvm_cbe_tmp__708;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__708);
if (AESL_DEBUG_TRACE)
printf("\n  %%130 = load i8* %%124, align 1, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1839_count);
  llvm_cbe_tmp__709 = (unsigned char )*llvm_cbe_tmp__703;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__709);
if (AESL_DEBUG_TRACE)
printf("\n  %%131 = zext i8 %%130 to i32, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1840_count);
  llvm_cbe_tmp__710 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__709&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__710);
if (AESL_DEBUG_TRACE)
printf("\n  %%132 = lshr i32 %%131, 3, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1841_count);
  llvm_cbe_tmp__711 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__710&4294967295ull)) >> ((unsigned int )(3u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__711&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%133 = or i32 %%7, 7, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1842_count);
  llvm_cbe_tmp__712 = (unsigned int )llvm_cbe_tmp__586 | 7u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__712);
if (AESL_DEBUG_TRACE)
printf("\n  %%134 = zext i32 %%133 to i64, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1843_count);
  llvm_cbe_tmp__713 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__712&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__713);
if (AESL_DEBUG_TRACE)
printf("\n  %%135 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, i64 %%134, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1844_count);
  llvm_cbe_tmp__714 = (signed int *)(&llvm_cbe_r->field0[(((signed long long )llvm_cbe_tmp__713))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__713));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%132, i32* %%135, align 4, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1845_count);
  *llvm_cbe_tmp__714 = llvm_cbe_tmp__711;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__711);
if (AESL_DEBUG_TRACE)
printf("\n  %%136 = add i32 %%2, 12, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1846_count);
  llvm_cbe_tmp__715 = (unsigned int )((unsigned int )(llvm_cbe_tmp__581&4294967295ull)) + ((unsigned int )(12u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__715&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%137 = zext i32 %%136 to i64, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1847_count);
  llvm_cbe_tmp__716 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__715&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__716);
if (AESL_DEBUG_TRACE)
printf("\n  %%138 = getelementptr inbounds i8* %%a, i64 %%137, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1848_count);
  llvm_cbe_tmp__717 = ( char *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__716))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__716));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%139 = load i8* %%138, align 1, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1849_count);
  llvm_cbe_tmp__718 = (unsigned char )*llvm_cbe_tmp__717;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__718);
if (AESL_DEBUG_TRACE)
printf("\n  %%140 = zext i8 %%139 to i32, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1850_count);
  llvm_cbe_tmp__719 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__718&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__719);
if (AESL_DEBUG_TRACE)
printf("\n  %%141 = shl nuw nsw i32 %%140, 5, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1851_count);
  llvm_cbe_tmp__720 = (unsigned int )llvm_cbe_tmp__719 << 5u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__720);
if (AESL_DEBUG_TRACE)
printf("\n  %%142 = or i32 %%141, %%132, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1852_count);
  llvm_cbe_tmp__721 = (unsigned int )llvm_cbe_tmp__720 | llvm_cbe_tmp__711;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__721);
if (AESL_DEBUG_TRACE)
printf("\n  %%143 = sub nsw i32 4096, %%17, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1853_count);
  llvm_cbe_tmp__722 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__596&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__722&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%143, i32* %%9, align 4, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1854_count);
  *llvm_cbe_tmp__588 = llvm_cbe_tmp__722;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__722);
if (AESL_DEBUG_TRACE)
printf("\n  %%144 = sub nsw i32 4096, %%38, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1855_count);
  llvm_cbe_tmp__723 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__617&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__723&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%144, i32* %%23, align 4, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1856_count);
  *llvm_cbe_tmp__602 = llvm_cbe_tmp__723;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__723);
if (AESL_DEBUG_TRACE)
printf("\n  %%145 = sub nsw i32 4096, %%52, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1857_count);
  llvm_cbe_tmp__724 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__631&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__724&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%145, i32* %%44, align 4, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1858_count);
  *llvm_cbe_tmp__623 = llvm_cbe_tmp__724;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__724);
if (AESL_DEBUG_TRACE)
printf("\n  %%146 = sub nsw i32 4096, %%73, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1859_count);
  llvm_cbe_tmp__725 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__652&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__725&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%146, i32* %%58, align 4, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1860_count);
  *llvm_cbe_tmp__637 = llvm_cbe_tmp__725;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__725);
if (AESL_DEBUG_TRACE)
printf("\n  %%147 = sub nsw i32 4096, %%94, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1861_count);
  llvm_cbe_tmp__726 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__673&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__726&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%147, i32* %%79, align 4, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1862_count);
  *llvm_cbe_tmp__658 = llvm_cbe_tmp__726;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__726);
if (AESL_DEBUG_TRACE)
printf("\n  %%148 = sub nsw i32 4096, %%108, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1863_count);
  llvm_cbe_tmp__727 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__687&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__727&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%148, i32* %%100, align 4, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1864_count);
  *llvm_cbe_tmp__679 = llvm_cbe_tmp__727;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__727);
if (AESL_DEBUG_TRACE)
printf("\n  %%149 = sub nsw i32 4096, %%129, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1865_count);
  llvm_cbe_tmp__728 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__708&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__728&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%149, i32* %%114, align 4, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1866_count);
  *llvm_cbe_tmp__693 = llvm_cbe_tmp__728;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__728);
if (AESL_DEBUG_TRACE)
printf("\n  %%150 = sub nsw i32 4096, %%142, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1867_count);
  llvm_cbe_tmp__729 = (unsigned int )((unsigned int )(4096u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__721&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__729&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%150, i32* %%135, align 4, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1868_count);
  *llvm_cbe_tmp__714 = llvm_cbe_tmp__729;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__729);
if (AESL_DEBUG_TRACE)
printf("\n  %%151 = add i32 %%storemerge1, 1, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyt0_unpack  --> \n", ++aesl_llvm_cbe_1869_count);
  llvm_cbe_tmp__730 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__730&4294967295ull)));
  if (((llvm_cbe_tmp__730&4294967295U) == (32u&4294967295U))) {
    goto llvm_cbe_tmp__732;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__730;   /* for PHI node */
    goto llvm_cbe_tmp__731;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__732:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_polyt0_unpack}\n");
  return;
}


void pqcrystals_dilithium3_ref_polyz_pack( char *llvm_cbe_r, l_struct_OC_poly *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_1939_count = 0;
  static  unsigned long long aesl_llvm_cbe_1940_count = 0;
  static  unsigned long long aesl_llvm_cbe_1941_count = 0;
  static  unsigned long long aesl_llvm_cbe_1942_count = 0;
  static  unsigned long long aesl_llvm_cbe_1943_count = 0;
  static  unsigned long long aesl_llvm_cbe_1944_count = 0;
  static  unsigned long long aesl_llvm_cbe_1945_count = 0;
  static  unsigned long long aesl_llvm_cbe_1946_count = 0;
  static  unsigned long long aesl_llvm_cbe_1947_count = 0;
  static  unsigned long long aesl_llvm_cbe_1948_count = 0;
  static  unsigned long long aesl_llvm_cbe_1949_count = 0;
  static  unsigned long long aesl_llvm_cbe_1950_count = 0;
  static  unsigned long long aesl_llvm_cbe_1951_count = 0;
  static  unsigned long long aesl_llvm_cbe_1952_count = 0;
  static  unsigned long long aesl_llvm_cbe_1953_count = 0;
  static  unsigned long long aesl_llvm_cbe_1954_count = 0;
  static  unsigned long long aesl_llvm_cbe_1955_count = 0;
  static  unsigned long long aesl_llvm_cbe_1956_count = 0;
  static  unsigned long long aesl_llvm_cbe_1957_count = 0;
  static  unsigned long long aesl_llvm_cbe_1958_count = 0;
  static  unsigned long long aesl_llvm_cbe_1959_count = 0;
  static  unsigned long long aesl_llvm_cbe_1960_count = 0;
  static  unsigned long long aesl_llvm_cbe_1961_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1962_count = 0;
  unsigned int llvm_cbe_tmp__733;
  static  unsigned long long aesl_llvm_cbe_1963_count = 0;
  unsigned long long llvm_cbe_tmp__734;
  static  unsigned long long aesl_llvm_cbe_1964_count = 0;
  signed int *llvm_cbe_tmp__735;
  static  unsigned long long aesl_llvm_cbe_1965_count = 0;
  unsigned int llvm_cbe_tmp__736;
  static  unsigned long long aesl_llvm_cbe_1966_count = 0;
  unsigned int llvm_cbe_tmp__737;
  static  unsigned long long aesl_llvm_cbe_1967_count = 0;
  unsigned int llvm_cbe_tmp__738;
  static  unsigned long long aesl_llvm_cbe_1968_count = 0;
  unsigned long long llvm_cbe_tmp__739;
  static  unsigned long long aesl_llvm_cbe_1969_count = 0;
  signed int *llvm_cbe_tmp__740;
  static  unsigned long long aesl_llvm_cbe_1970_count = 0;
  unsigned int llvm_cbe_tmp__741;
  static  unsigned long long aesl_llvm_cbe_1971_count = 0;
  unsigned int llvm_cbe_tmp__742;
  static  unsigned long long aesl_llvm_cbe_1972_count = 0;
  unsigned char llvm_cbe_tmp__743;
  static  unsigned long long aesl_llvm_cbe_1973_count = 0;
  unsigned int llvm_cbe_tmp__744;
  static  unsigned long long aesl_llvm_cbe_1974_count = 0;
  unsigned long long llvm_cbe_tmp__745;
  static  unsigned long long aesl_llvm_cbe_1975_count = 0;
   char *llvm_cbe_tmp__746;
  static  unsigned long long aesl_llvm_cbe_1976_count = 0;
  static  unsigned long long aesl_llvm_cbe_1977_count = 0;
  unsigned int llvm_cbe_tmp__747;
  static  unsigned long long aesl_llvm_cbe_1978_count = 0;
  unsigned char llvm_cbe_tmp__748;
  static  unsigned long long aesl_llvm_cbe_1979_count = 0;
  unsigned int llvm_cbe_tmp__749;
  static  unsigned long long aesl_llvm_cbe_1980_count = 0;
  unsigned long long llvm_cbe_tmp__750;
  static  unsigned long long aesl_llvm_cbe_1981_count = 0;
   char *llvm_cbe_tmp__751;
  static  unsigned long long aesl_llvm_cbe_1982_count = 0;
  static  unsigned long long aesl_llvm_cbe_1983_count = 0;
  unsigned int llvm_cbe_tmp__752;
  static  unsigned long long aesl_llvm_cbe_1984_count = 0;
  unsigned char llvm_cbe_tmp__753;
  static  unsigned long long aesl_llvm_cbe_1985_count = 0;
  unsigned int llvm_cbe_tmp__754;
  static  unsigned long long aesl_llvm_cbe_1986_count = 0;
  unsigned long long llvm_cbe_tmp__755;
  static  unsigned long long aesl_llvm_cbe_1987_count = 0;
   char *llvm_cbe_tmp__756;
  static  unsigned long long aesl_llvm_cbe_1988_count = 0;
  unsigned char llvm_cbe_tmp__757;
  static  unsigned long long aesl_llvm_cbe_1989_count = 0;
  unsigned char llvm_cbe_tmp__758;
  static  unsigned long long aesl_llvm_cbe_1990_count = 0;
  unsigned char llvm_cbe_tmp__759;
  static  unsigned long long aesl_llvm_cbe_1991_count = 0;
  static  unsigned long long aesl_llvm_cbe_1992_count = 0;
  unsigned int llvm_cbe_tmp__760;
  static  unsigned long long aesl_llvm_cbe_1993_count = 0;
  unsigned char llvm_cbe_tmp__761;
  static  unsigned long long aesl_llvm_cbe_1994_count = 0;
  unsigned int llvm_cbe_tmp__762;
  static  unsigned long long aesl_llvm_cbe_1995_count = 0;
  unsigned long long llvm_cbe_tmp__763;
  static  unsigned long long aesl_llvm_cbe_1996_count = 0;
   char *llvm_cbe_tmp__764;
  static  unsigned long long aesl_llvm_cbe_1997_count = 0;
  static  unsigned long long aesl_llvm_cbe_1998_count = 0;
  unsigned int llvm_cbe_tmp__765;
  static  unsigned long long aesl_llvm_cbe_1999_count = 0;
  unsigned char llvm_cbe_tmp__766;
  static  unsigned long long aesl_llvm_cbe_2000_count = 0;
  unsigned int llvm_cbe_tmp__767;
  static  unsigned long long aesl_llvm_cbe_2001_count = 0;
  unsigned long long llvm_cbe_tmp__768;
  static  unsigned long long aesl_llvm_cbe_2002_count = 0;
   char *llvm_cbe_tmp__769;
  static  unsigned long long aesl_llvm_cbe_2003_count = 0;
  static  unsigned long long aesl_llvm_cbe_2004_count = 0;
  unsigned int llvm_cbe_tmp__770;
  static  unsigned long long aesl_llvm_cbe_2005_count = 0;
  static  unsigned long long aesl_llvm_cbe_2006_count = 0;
  static  unsigned long long aesl_llvm_cbe_2007_count = 0;
  static  unsigned long long aesl_llvm_cbe_2008_count = 0;
  static  unsigned long long aesl_llvm_cbe_2009_count = 0;
  static  unsigned long long aesl_llvm_cbe_2010_count = 0;
  static  unsigned long long aesl_llvm_cbe_2011_count = 0;
  static  unsigned long long aesl_llvm_cbe_2012_count = 0;
  static  unsigned long long aesl_llvm_cbe_2013_count = 0;
  static  unsigned long long aesl_llvm_cbe_2014_count = 0;
  static  unsigned long long aesl_llvm_cbe_2015_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_2016_count = 0;
  static  unsigned long long aesl_llvm_cbe_2017_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_polyz_pack\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__771;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__771:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%39, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__770);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = shl i32 %%storemerge1, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1962_count);
  llvm_cbe_tmp__733 = (unsigned int )llvm_cbe_storemerge1 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__733);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1963_count);
  llvm_cbe_tmp__734 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__733&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__734);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%3, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1964_count);
  llvm_cbe_tmp__735 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__734))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__734));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%4, align 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1965_count);
  llvm_cbe_tmp__736 = (unsigned int )*llvm_cbe_tmp__735;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__736);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = sub nsw i32 524288, %%5, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1966_count);
  llvm_cbe_tmp__737 = (unsigned int )((unsigned int )(524288u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__736&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__737&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = or i32 %%2, 1, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1967_count);
  llvm_cbe_tmp__738 = (unsigned int )llvm_cbe_tmp__733 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__738);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i32 %%7 to i64, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1968_count);
  llvm_cbe_tmp__739 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__738&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__739);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%8, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1969_count);
  llvm_cbe_tmp__740 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__739))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__739));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i32* %%9, align 4, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1970_count);
  llvm_cbe_tmp__741 = (unsigned int )*llvm_cbe_tmp__740;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__741);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sub nsw i32 524288, %%10, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1971_count);
  llvm_cbe_tmp__742 = (unsigned int )((unsigned int )(524288u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__741&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__742&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = trunc i32 %%6 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1972_count);
  llvm_cbe_tmp__743 = (unsigned char )((unsigned char )llvm_cbe_tmp__737&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__743);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = mul i32 %%storemerge1, 5, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1973_count);
  llvm_cbe_tmp__744 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) * ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__744&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i32 %%13 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1974_count);
  llvm_cbe_tmp__745 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__744&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__745);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds i8* %%r, i64 %%14, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1975_count);
  llvm_cbe_tmp__746 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__745))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__745));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%12, i8* %%15, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1976_count);
  *llvm_cbe_tmp__746 = llvm_cbe_tmp__743;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__743);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = lshr i32 %%6, 8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1977_count);
  llvm_cbe_tmp__747 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__737&4294967295ull)) >> ((unsigned int )(8u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__747&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = trunc i32 %%16 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1978_count);
  llvm_cbe_tmp__748 = (unsigned char )((unsigned char )llvm_cbe_tmp__747&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__748);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i32 %%13, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1979_count);
  llvm_cbe_tmp__749 = (unsigned int )((unsigned int )(llvm_cbe_tmp__744&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__749&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = zext i32 %%18 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1980_count);
  llvm_cbe_tmp__750 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__749&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__750);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds i8* %%r, i64 %%19, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1981_count);
  llvm_cbe_tmp__751 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__750))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__750));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%17, i8* %%20, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1982_count);
  *llvm_cbe_tmp__751 = llvm_cbe_tmp__748;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__748);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = lshr i32 %%6, 16, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1983_count);
  llvm_cbe_tmp__752 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__737&4294967295ull)) >> ((unsigned int )(16u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__752&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = trunc i32 %%21 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1984_count);
  llvm_cbe_tmp__753 = (unsigned char )((unsigned char )llvm_cbe_tmp__752&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__753);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add i32 %%13, 2, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1985_count);
  llvm_cbe_tmp__754 = (unsigned int )((unsigned int )(llvm_cbe_tmp__744&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__754&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = zext i32 %%23 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1986_count);
  llvm_cbe_tmp__755 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__754&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__755);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds i8* %%r, i64 %%24, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1987_count);
  llvm_cbe_tmp__756 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__755))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__755));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = trunc i32 %%11 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1988_count);
  llvm_cbe_tmp__757 = (unsigned char )((unsigned char )llvm_cbe_tmp__742&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__757);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = shl i8 %%26, 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1989_count);
  llvm_cbe_tmp__758 = (unsigned char )((unsigned char )(llvm_cbe_tmp__757 << ((unsigned char )4)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__758);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = or i8 %%27, %%22, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1990_count);
  llvm_cbe_tmp__759 = (unsigned char )((unsigned char )(llvm_cbe_tmp__758 | llvm_cbe_tmp__753));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__759);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%28, i8* %%25, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1991_count);
  *llvm_cbe_tmp__756 = llvm_cbe_tmp__759;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__759);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = lshr i32 %%11, 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1992_count);
  llvm_cbe_tmp__760 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__742&4294967295ull)) >> ((unsigned int )(4u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__760&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = trunc i32 %%29 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1993_count);
  llvm_cbe_tmp__761 = (unsigned char )((unsigned char )llvm_cbe_tmp__760&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__761);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add i32 %%13, 3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1994_count);
  llvm_cbe_tmp__762 = (unsigned int )((unsigned int )(llvm_cbe_tmp__744&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__762&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = zext i32 %%31 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1995_count);
  llvm_cbe_tmp__763 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__762&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__763);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds i8* %%r, i64 %%32, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1996_count);
  llvm_cbe_tmp__764 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__763))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__763));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%30, i8* %%33, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1997_count);
  *llvm_cbe_tmp__764 = llvm_cbe_tmp__761;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__761);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = lshr i32 %%11, 12, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1998_count);
  llvm_cbe_tmp__765 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__742&4294967295ull)) >> ((unsigned int )(12u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__765&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = trunc i32 %%34 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_1999_count);
  llvm_cbe_tmp__766 = (unsigned char )((unsigned char )llvm_cbe_tmp__765&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__766);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = add i32 %%13, 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_2000_count);
  llvm_cbe_tmp__767 = (unsigned int )((unsigned int )(llvm_cbe_tmp__744&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__767&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = zext i32 %%36 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_2001_count);
  llvm_cbe_tmp__768 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__767&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__768);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds i8* %%r, i64 %%37, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_2002_count);
  llvm_cbe_tmp__769 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__768))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__768));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%35, i8* %%38, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_2003_count);
  *llvm_cbe_tmp__769 = llvm_cbe_tmp__766;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__766);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add i32 %%storemerge1, 1, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyz_pack  --> \n", ++aesl_llvm_cbe_2004_count);
  llvm_cbe_tmp__770 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__770&4294967295ull)));
  if (((llvm_cbe_tmp__770&4294967295U) == (128u&4294967295U))) {
    goto llvm_cbe_tmp__772;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__770;   /* for PHI node */
    goto llvm_cbe_tmp__771;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__772:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_polyz_pack}\n");
  return;
}


void pqcrystals_dilithium3_ref_polyw1_pack( char *llvm_cbe_r, l_struct_OC_poly *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_2018_count = 0;
  static  unsigned long long aesl_llvm_cbe_2019_count = 0;
  static  unsigned long long aesl_llvm_cbe_2020_count = 0;
  static  unsigned long long aesl_llvm_cbe_2021_count = 0;
  static  unsigned long long aesl_llvm_cbe_2022_count = 0;
  static  unsigned long long aesl_llvm_cbe_2023_count = 0;
  static  unsigned long long aesl_llvm_cbe_2024_count = 0;
  static  unsigned long long aesl_llvm_cbe_2025_count = 0;
  static  unsigned long long aesl_llvm_cbe_2026_count = 0;
  static  unsigned long long aesl_llvm_cbe_2027_count = 0;
  static  unsigned long long aesl_llvm_cbe_2028_count = 0;
  static  unsigned long long aesl_llvm_cbe_2029_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2030_count = 0;
  unsigned int llvm_cbe_tmp__773;
  static  unsigned long long aesl_llvm_cbe_2031_count = 0;
  unsigned long long llvm_cbe_tmp__774;
  static  unsigned long long aesl_llvm_cbe_2032_count = 0;
  signed int *llvm_cbe_tmp__775;
  static  unsigned long long aesl_llvm_cbe_2033_count = 0;
  unsigned int llvm_cbe_tmp__776;
  static  unsigned long long aesl_llvm_cbe_2034_count = 0;
  unsigned int llvm_cbe_tmp__777;
  static  unsigned long long aesl_llvm_cbe_2035_count = 0;
  unsigned long long llvm_cbe_tmp__778;
  static  unsigned long long aesl_llvm_cbe_2036_count = 0;
  signed int *llvm_cbe_tmp__779;
  static  unsigned long long aesl_llvm_cbe_2037_count = 0;
  unsigned int llvm_cbe_tmp__780;
  static  unsigned long long aesl_llvm_cbe_2038_count = 0;
  unsigned int llvm_cbe_tmp__781;
  static  unsigned long long aesl_llvm_cbe_2039_count = 0;
  unsigned int llvm_cbe_tmp__782;
  static  unsigned long long aesl_llvm_cbe_2040_count = 0;
  unsigned char llvm_cbe_tmp__783;
  static  unsigned long long aesl_llvm_cbe_2041_count = 0;
  unsigned long long llvm_cbe_tmp__784;
  static  unsigned long long aesl_llvm_cbe_2042_count = 0;
   char *llvm_cbe_tmp__785;
  static  unsigned long long aesl_llvm_cbe_2043_count = 0;
  static  unsigned long long aesl_llvm_cbe_2044_count = 0;
  unsigned int llvm_cbe_tmp__786;
  static  unsigned long long aesl_llvm_cbe_2045_count = 0;
  static  unsigned long long aesl_llvm_cbe_2046_count = 0;
  static  unsigned long long aesl_llvm_cbe_2047_count = 0;
  static  unsigned long long aesl_llvm_cbe_2048_count = 0;
  static  unsigned long long aesl_llvm_cbe_2049_count = 0;
  static  unsigned long long aesl_llvm_cbe_2050_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_2051_count = 0;
  static  unsigned long long aesl_llvm_cbe_2052_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_polyw1_pack\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__787;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__787:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%15, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__786);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = shl i32 %%storemerge1, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_2030_count);
  llvm_cbe_tmp__773 = (unsigned int )llvm_cbe_storemerge1 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__773);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_2031_count);
  llvm_cbe_tmp__774 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__773&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__774);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%3, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_2032_count);
  llvm_cbe_tmp__775 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__774))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__774));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%4, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_2033_count);
  llvm_cbe_tmp__776 = (unsigned int )*llvm_cbe_tmp__775;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__776);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = or i32 %%2, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_2034_count);
  llvm_cbe_tmp__777 = (unsigned int )llvm_cbe_tmp__773 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__777);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = zext i32 %%6 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_2035_count);
  llvm_cbe_tmp__778 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__777&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__778);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.poly* %%a, i64 0, i32 0, i64 %%7, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_2036_count);
  llvm_cbe_tmp__779 = (signed int *)(&llvm_cbe_a->field0[(((signed long long )llvm_cbe_tmp__778))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__778));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i32* %%8, align 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_2037_count);
  llvm_cbe_tmp__780 = (unsigned int )*llvm_cbe_tmp__779;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__780);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = shl i32 %%9, 4, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_2038_count);
  llvm_cbe_tmp__781 = (unsigned int )llvm_cbe_tmp__780 << 4u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__781);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = or i32 %%10, %%5, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_2039_count);
  llvm_cbe_tmp__782 = (unsigned int )llvm_cbe_tmp__781 | llvm_cbe_tmp__776;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__782);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = trunc i32 %%11 to i8, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_2040_count);
  llvm_cbe_tmp__783 = (unsigned char )((unsigned char )llvm_cbe_tmp__782&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__783);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = zext i32 %%storemerge1 to i64, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_2041_count);
  llvm_cbe_tmp__784 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__784);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i8* %%r, i64 %%13, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_2042_count);
  llvm_cbe_tmp__785 = ( char *)(&llvm_cbe_r[(((signed long long )llvm_cbe_tmp__784))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__784));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%12, i8* %%14, align 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_2043_count);
  *llvm_cbe_tmp__785 = llvm_cbe_tmp__783;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__783);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add i32 %%storemerge1, 1, !dbg !14 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_polyw1_pack  --> \n", ++aesl_llvm_cbe_2044_count);
  llvm_cbe_tmp__786 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__786&4294967295ull)));
  if (((llvm_cbe_tmp__786&4294967295U) == (128u&4294967295U))) {
    goto llvm_cbe_tmp__788;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__786;   /* for PHI node */
    goto llvm_cbe_tmp__787;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__788:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_polyw1_pack}\n");
  return;
}

