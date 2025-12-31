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
typedef struct l_struct_OC_keccak_state l_struct_OC_keccak_state;

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

struct l_struct_OC_keccak_state {
  signed long long field0[25];
  unsigned int field1;
};


/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int pqcrystals_dilithium3_ref_keypair( char *llvm_cbe_pk,  char *llvm_cbe_sk);
void randombytes( char *, signed long long );
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
signed int pqcrystals_dilithium3_ref_signature_internal( char *llvm_cbe_sig, signed long long *llvm_cbe_siglen,  char *llvm_cbe_m, signed long long llvm_cbe_mlen,  char *llvm_cbe_pre, signed long long llvm_cbe_prelen,  char *llvm_cbe_rnd,  char *llvm_cbe_sk);
void pqcrystals_dilithium3_ref_unpack_sk( char *,  char *,  char *, l_struct_OC_polyveck *, l_struct_OC_polyvecl *, l_struct_OC_polyveck *,  char *);
void pqcrystals_dilithium_fips202_ref_shake256_init(l_struct_OC_keccak_state *);
void pqcrystals_dilithium_fips202_ref_shake256_absorb(l_struct_OC_keccak_state *,  char *, signed long long );
void pqcrystals_dilithium_fips202_ref_shake256_finalize(l_struct_OC_keccak_state *);
void pqcrystals_dilithium_fips202_ref_shake256_squeeze( char *, signed long long , l_struct_OC_keccak_state *);
void pqcrystals_dilithium3_ref_polyveck_ntt(l_struct_OC_polyveck *);
void pqcrystals_dilithium3_ref_polyvecl_uniform_gamma1(l_struct_OC_polyvecl *,  char *, signed short );
void pqcrystals_dilithium3_ref_polyveck_decompose(l_struct_OC_polyveck *, l_struct_OC_polyveck *, l_struct_OC_polyveck *);
void pqcrystals_dilithium3_ref_polyveck_pack_w1( char *, l_struct_OC_polyveck *);
void pqcrystals_dilithium3_ref_poly_challenge(l_struct_OC_poly *,  char *);
void pqcrystals_dilithium3_ref_poly_ntt(l_struct_OC_poly *);
void pqcrystals_dilithium3_ref_polyvecl_pointwise_poly_montgomery(l_struct_OC_polyvecl *, l_struct_OC_poly *, l_struct_OC_polyvecl *);
void pqcrystals_dilithium3_ref_polyvecl_invntt_tomont(l_struct_OC_polyvecl *);
void pqcrystals_dilithium3_ref_polyvecl_add(l_struct_OC_polyvecl *, l_struct_OC_polyvecl *, l_struct_OC_polyvecl *);
void pqcrystals_dilithium3_ref_polyvecl_reduce(l_struct_OC_polyvecl *);
signed int pqcrystals_dilithium3_ref_polyvecl_chknorm(l_struct_OC_polyvecl *, signed int );
void pqcrystals_dilithium3_ref_polyveck_pointwise_poly_montgomery(l_struct_OC_polyveck *, l_struct_OC_poly *, l_struct_OC_polyveck *);
void pqcrystals_dilithium3_ref_polyveck_sub(l_struct_OC_polyveck *, l_struct_OC_polyveck *, l_struct_OC_polyveck *);
signed int pqcrystals_dilithium3_ref_polyveck_chknorm(l_struct_OC_polyveck *, signed int );
signed int pqcrystals_dilithium3_ref_polyveck_make_hint(l_struct_OC_polyveck *, l_struct_OC_polyveck *, l_struct_OC_polyveck *);
void pqcrystals_dilithium3_ref_pack_sig( char *,  char *, l_struct_OC_polyvecl *, l_struct_OC_polyveck *);
signed int pqcrystals_dilithium3_ref_signature( char *llvm_cbe_sig, signed long long *llvm_cbe_siglen,  char *llvm_cbe_m, signed long long llvm_cbe_mlen,  char *llvm_cbe_ctx, signed long long llvm_cbe_ctxlen,  char *llvm_cbe_sk);
signed int pqcrystals_dilithium3_ref( char *llvm_cbe_sm, signed long long *llvm_cbe_smlen,  char *llvm_cbe_m, signed long long llvm_cbe_mlen,  char *llvm_cbe_ctx, signed long long llvm_cbe_ctxlen,  char *llvm_cbe_sk);
signed int pqcrystals_dilithium3_ref_verify_internal( char *llvm_cbe_sig, signed long long llvm_cbe_siglen,  char *llvm_cbe_m, signed long long llvm_cbe_mlen,  char *llvm_cbe_pre, signed long long llvm_cbe_prelen,  char *llvm_cbe_pk);
void pqcrystals_dilithium3_ref_unpack_pk( char *, l_struct_OC_polyveck *,  char *);
signed int pqcrystals_dilithium3_ref_unpack_sig( char *, l_struct_OC_polyvecl *, l_struct_OC_polyveck *,  char *);
void pqcrystals_dilithium3_ref_polyveck_shiftl(l_struct_OC_polyveck *);
void pqcrystals_dilithium3_ref_polyveck_use_hint(l_struct_OC_polyveck *, l_struct_OC_polyveck *, l_struct_OC_polyveck *);
signed int pqcrystals_dilithium3_ref_verify( char *llvm_cbe_sig, signed long long llvm_cbe_siglen,  char *llvm_cbe_m, signed long long llvm_cbe_mlen,  char *llvm_cbe_ctx, signed long long llvm_cbe_ctxlen,  char *llvm_cbe_pk);
signed int pqcrystals_dilithium3_ref_open( char *llvm_cbe_m, signed long long *llvm_cbe_mlen,  char *llvm_cbe_sm, signed long long llvm_cbe_smlen,  char *llvm_cbe_ctx, signed long long llvm_cbe_ctxlen,  char *llvm_cbe_pk);


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

signed int pqcrystals_dilithium3_ref_keypair( char *llvm_cbe_pk,  char *llvm_cbe_sk) {
  static  unsigned long long aesl_llvm_cbe_seedbuf_count = 0;
   char llvm_cbe_seedbuf[128];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_tr_count = 0;
   char llvm_cbe_tr[64];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_mat_count = 0;
  l_struct_OC_polyvecl llvm_cbe_mat[6];    /* Address-exposed local */
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
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
   char *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
   char *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
   char *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
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
   char *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  l_struct_OC_polyvecl *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned int llvm_cbe_tmp__6;
  unsigned int llvm_cbe_tmp__6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  signed int *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  signed int *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned int llvm_cbe_tmp__12;
  unsigned int llvm_cbe_tmp__12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned long long llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  signed int *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  signed int *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned int llvm_cbe_tmp__18;
  unsigned int llvm_cbe_tmp__18__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  signed int *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  signed int *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned int llvm_cbe_tmp__24;
  unsigned int llvm_cbe_tmp__24__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  unsigned long long llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  signed int *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  signed int *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  unsigned int llvm_cbe_tmp__30;
  unsigned int llvm_cbe_tmp__30__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  signed int *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  signed int *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
   char *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_keypair\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [128 x i8]* %%seedbuf, i64 0, i64 0, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_14_count);
  llvm_cbe_tmp__1 = ( char *)(&llvm_cbe_seedbuf[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 128
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @randombytes(i8* %%1, i64 32) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_15_count);
  randombytes(( char *)llvm_cbe_tmp__1, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds [128 x i8]* %%seedbuf, i64 0, i64 32, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__2 = ( char *)(&llvm_cbe_seedbuf[(((signed long long )32ull))
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
printf("\n  store i8 6, i8* %%2, align 16, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_17_count);
  *llvm_cbe_tmp__2 = ((unsigned char )6);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )6));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [128 x i8]* %%seedbuf, i64 0, i64 33, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__3 = ( char *)(&llvm_cbe_seedbuf[(((signed long long )33ull))
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
printf("\n  store i8 5, i8* %%3, align 1, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_19_count);
  *llvm_cbe_tmp__3 = ((unsigned char )5);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )5));
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256(i8* %%1, i64 128, i8* %%1, i64 34) nounwind, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_20_count);
  pqcrystals_dilithium_fips202_ref_shake256(( char *)llvm_cbe_tmp__1, 128ull, ( char *)llvm_cbe_tmp__1, 34ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",128ull);
printf("\nArgument  = 0x%I64X",34ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [128 x i8]* %%seedbuf, i64 0, i64 96, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__4 = ( char *)(&llvm_cbe_seedbuf[(((signed long long )96ull))
#ifdef AESL_BC_SIM
 % 128
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [6 x %%struct.polyvecl]* %%mat, i64 0, i64 0, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__5 = (l_struct_OC_polyvecl *)(&llvm_cbe_mat[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvec_matrix_expand(%%struct.polyvecl* %%5, i8* %%1) nounwind, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_34_count);
  pqcrystals_dilithium3_ref_polyvec_matrix_expand((l_struct_OC_polyvecl *)llvm_cbe_tmp__5, ( char *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvecl_uniform_eta(%%struct.polyvecl* %%s1, i8* %%2, i16 zeroext 0) nounwind, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_35_count);
  pqcrystals_dilithium3_ref_polyvecl_uniform_eta((l_struct_OC_polyvecl *)(&llvm_cbe_s1), ( char *)llvm_cbe_tmp__2, ((unsigned short )0));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned short )0));
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_uniform_eta(%%struct.polyveck* %%s2, i8* %%2, i16 zeroext 5) nounwind, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_36_count);
  pqcrystals_dilithium3_ref_polyveck_uniform_eta((l_struct_OC_polyveck *)(&llvm_cbe_s2), ( char *)llvm_cbe_tmp__2, ((unsigned short )5));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned short )5));
}
  llvm_cbe_tmp__6__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_memcpy;

  do {     /* Syntactic loop 'memcpy' to make GCC happy */
llvm_cbe_memcpy:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = phi i32 [ 0, %%0 ], [ %%7, %%memcpy ], !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__6 = (unsigned int )llvm_cbe_tmp__6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__6);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__7);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i32 %%6, 1, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__7 = (unsigned int )((unsigned int )(llvm_cbe_tmp__6&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__7&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sext i32 %%6 to i64, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__8 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.polyvecl* %%s1hat, i64 0, i32 0, i64 0, i32 0, i64 %%8, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__9 = (signed int *)(&llvm_cbe_s1hat.field0[(((signed long long )0ull))].field0[(((signed long long )llvm_cbe_tmp__8))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 0, i32 0, i64 %%8, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__10 = (signed int *)(&llvm_cbe_s1.field0[(((signed long long )0ull))].field0[(((signed long long )llvm_cbe_tmp__8))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i32* %%10, align 4, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__11 = (unsigned int )*llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%11, i32* %%9, align 4, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_44_count);
  *llvm_cbe_tmp__9 = llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__11);
  if (((llvm_cbe_tmp__6&4294967295U) == (255u&4294967295U))) {
    llvm_cbe_tmp__12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_memcpy1;
  } else {
    llvm_cbe_tmp__6__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__7;   /* for PHI node */
    goto llvm_cbe_memcpy;
  }

  } while (1); /* end of syntactic loop 'memcpy' */
  do {     /* Syntactic loop 'memcpy1' to make GCC happy */
llvm_cbe_memcpy1:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = phi i32 [ %%14, %%memcpy1 ], [ 0, %%memcpy ], !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__12 = (unsigned int )llvm_cbe_tmp__12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__12);
printf("\n = 0x%X",llvm_cbe_tmp__13);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add i32 %%13, 1, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__13 = (unsigned int )((unsigned int )(llvm_cbe_tmp__12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__13&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = sext i32 %%13 to i64, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__14 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.polyvecl* %%s1hat, i64 0, i32 0, i64 1, i32 0, i64 %%15, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__15 = (signed int *)(&llvm_cbe_s1hat.field0[(((signed long long )1ull))].field0[(((signed long long )llvm_cbe_tmp__14))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__14));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 1, i32 0, i64 %%15, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__16 = (signed int *)(&llvm_cbe_s1.field0[(((signed long long )1ull))].field0[(((signed long long )llvm_cbe_tmp__14))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__14));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i32* %%17, align 4, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__17 = (unsigned int )*llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%18, i32* %%16, align 4, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_53_count);
  *llvm_cbe_tmp__15 = llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
  if (((llvm_cbe_tmp__12&4294967295U) == (255u&4294967295U))) {
    llvm_cbe_tmp__18__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_memcpy2;
  } else {
    llvm_cbe_tmp__12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__13;   /* for PHI node */
    goto llvm_cbe_memcpy1;
  }

  } while (1); /* end of syntactic loop 'memcpy1' */
  do {     /* Syntactic loop 'memcpy2' to make GCC happy */
llvm_cbe_memcpy2:
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = phi i32 [ %%21, %%memcpy2 ], [ 0, %%memcpy1 ], !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__18 = (unsigned int )llvm_cbe_tmp__18__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__18);
printf("\n = 0x%X",llvm_cbe_tmp__19);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add i32 %%20, 1, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__19 = (unsigned int )((unsigned int )(llvm_cbe_tmp__18&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__19&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = sext i32 %%20 to i64, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__20 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds %%struct.polyvecl* %%s1hat, i64 0, i32 0, i64 2, i32 0, i64 %%22, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__21 = (signed int *)(&llvm_cbe_s1hat.field0[(((signed long long )2ull))].field0[(((signed long long )llvm_cbe_tmp__20))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__20));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 2, i32 0, i64 %%22, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__22 = (signed int *)(&llvm_cbe_s1.field0[(((signed long long )2ull))].field0[(((signed long long )llvm_cbe_tmp__20))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__20));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i32* %%24, align 4, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__23 = (unsigned int )*llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%25, i32* %%23, align 4, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_62_count);
  *llvm_cbe_tmp__21 = llvm_cbe_tmp__23;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
  if (((llvm_cbe_tmp__18&4294967295U) == (255u&4294967295U))) {
    llvm_cbe_tmp__24__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_memcpy3;
  } else {
    llvm_cbe_tmp__18__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__19;   /* for PHI node */
    goto llvm_cbe_memcpy2;
  }

  } while (1); /* end of syntactic loop 'memcpy2' */
  do {     /* Syntactic loop 'memcpy3' to make GCC happy */
llvm_cbe_memcpy3:
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = phi i32 [ %%28, %%memcpy3 ], [ 0, %%memcpy2 ], !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__24 = (unsigned int )llvm_cbe_tmp__24__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__24);
printf("\n = 0x%X",llvm_cbe_tmp__25);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i32 %%27, 1, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__25 = (unsigned int )((unsigned int )(llvm_cbe_tmp__24&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__25&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = sext i32 %%27 to i64, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__26 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct.polyvecl* %%s1hat, i64 0, i32 0, i64 3, i32 0, i64 %%29, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__27 = (signed int *)(&llvm_cbe_s1hat.field0[(((signed long long )3ull))].field0[(((signed long long )llvm_cbe_tmp__26))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__26));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 3, i32 0, i64 %%29, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__28 = (signed int *)(&llvm_cbe_s1.field0[(((signed long long )3ull))].field0[(((signed long long )llvm_cbe_tmp__26))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__26));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load i32* %%31, align 4, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__29 = (unsigned int )*llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%32, i32* %%30, align 4, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_71_count);
  *llvm_cbe_tmp__27 = llvm_cbe_tmp__29;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
  if (((llvm_cbe_tmp__24&4294967295U) == (255u&4294967295U))) {
    llvm_cbe_tmp__30__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_memcpy4;
  } else {
    llvm_cbe_tmp__24__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__25;   /* for PHI node */
    goto llvm_cbe_memcpy3;
  }

  } while (1); /* end of syntactic loop 'memcpy3' */
  do {     /* Syntactic loop 'memcpy4' to make GCC happy */
llvm_cbe_memcpy4:
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = phi i32 [ %%35, %%memcpy4 ], [ 0, %%memcpy3 ], !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__30 = (unsigned int )llvm_cbe_tmp__30__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__30);
printf("\n = 0x%X",llvm_cbe_tmp__31);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = add i32 %%34, 1, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__31 = (unsigned int )((unsigned int )(llvm_cbe_tmp__30&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__31&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = sext i32 %%34 to i64, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__32 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds %%struct.polyvecl* %%s1hat, i64 0, i32 0, i64 4, i32 0, i64 %%36, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__33 = (signed int *)(&llvm_cbe_s1hat.field0[(((signed long long )4ull))].field0[(((signed long long )llvm_cbe_tmp__32))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__32));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 4, i32 0, i64 %%36, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__34 = (signed int *)(&llvm_cbe_s1.field0[(((signed long long )4ull))].field0[(((signed long long )llvm_cbe_tmp__32))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__32));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i32* %%38, align 4, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__35 = (unsigned int )*llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%39, i32* %%37, align 4, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_80_count);
  *llvm_cbe_tmp__33 = llvm_cbe_tmp__35;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
  if (((llvm_cbe_tmp__30&4294967295U) == (255u&4294967295U))) {
    goto llvm_cbe_tmp__37;
  } else {
    llvm_cbe_tmp__30__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__31;   /* for PHI node */
    goto llvm_cbe_memcpy4;
  }

  } while (1); /* end of syntactic loop 'memcpy4' */
llvm_cbe_tmp__37:
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvecl_ntt(%%struct.polyvecl* %%s1hat) nounwind, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_83_count);
  pqcrystals_dilithium3_ref_polyvecl_ntt((l_struct_OC_polyvecl *)(&llvm_cbe_s1hat));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvec_matrix_pointwise_montgomery(%%struct.polyveck* %%t1, %%struct.polyvecl* %%5, %%struct.polyvecl* %%s1hat) nounwind, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_84_count);
  pqcrystals_dilithium3_ref_polyvec_matrix_pointwise_montgomery((l_struct_OC_polyveck *)(&llvm_cbe_t1), (l_struct_OC_polyvecl *)llvm_cbe_tmp__5, (l_struct_OC_polyvecl *)(&llvm_cbe_s1hat));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_reduce(%%struct.polyveck* %%t1) nounwind, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_85_count);
  pqcrystals_dilithium3_ref_polyveck_reduce((l_struct_OC_polyveck *)(&llvm_cbe_t1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_invntt_tomont(%%struct.polyveck* %%t1) nounwind, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_86_count);
  pqcrystals_dilithium3_ref_polyveck_invntt_tomont((l_struct_OC_polyveck *)(&llvm_cbe_t1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_add(%%struct.polyveck* %%t1, %%struct.polyveck* %%t1, %%struct.polyveck* %%s2) nounwind, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_87_count);
  pqcrystals_dilithium3_ref_polyveck_add((l_struct_OC_polyveck *)(&llvm_cbe_t1), (l_struct_OC_polyveck *)(&llvm_cbe_t1), (l_struct_OC_polyveck *)(&llvm_cbe_s2));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_caddq(%%struct.polyveck* %%t1) nounwind, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_88_count);
  pqcrystals_dilithium3_ref_polyveck_caddq((l_struct_OC_polyveck *)(&llvm_cbe_t1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_power2round(%%struct.polyveck* %%t1, %%struct.polyveck* %%t0, %%struct.polyveck* %%t1) nounwind, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_89_count);
  pqcrystals_dilithium3_ref_polyveck_power2round((l_struct_OC_polyveck *)(&llvm_cbe_t1), (l_struct_OC_polyveck *)(&llvm_cbe_t0), (l_struct_OC_polyveck *)(&llvm_cbe_t1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_pack_pk(i8* %%pk, i8* %%1, %%struct.polyveck* %%t1) nounwind, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_90_count);
  pqcrystals_dilithium3_ref_pack_pk(( char *)llvm_cbe_pk, ( char *)llvm_cbe_tmp__1, (l_struct_OC_polyveck *)(&llvm_cbe_t1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds [64 x i8]* %%tr, i64 0, i64 0, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__36 = ( char *)(&llvm_cbe_tr[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 64
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256(i8* %%42, i64 64, i8* %%pk, i64 1952) nounwind, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_92_count);
  pqcrystals_dilithium_fips202_ref_shake256(( char *)llvm_cbe_tmp__36, 64ull, ( char *)llvm_cbe_pk, 1952ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",64ull);
printf("\nArgument  = 0x%I64X",1952ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_pack_sk(i8* %%sk, i8* %%1, i8* %%42, i8* %%4, %%struct.polyveck* %%t0, %%struct.polyvecl* %%s1, %%struct.polyveck* %%s2) nounwind, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_keypair  --> \n", ++aesl_llvm_cbe_93_count);
  pqcrystals_dilithium3_ref_pack_sk(( char *)llvm_cbe_sk, ( char *)llvm_cbe_tmp__1, ( char *)llvm_cbe_tmp__36, ( char *)llvm_cbe_tmp__4, (l_struct_OC_polyveck *)(&llvm_cbe_t0), (l_struct_OC_polyvecl *)(&llvm_cbe_s1), (l_struct_OC_polyveck *)(&llvm_cbe_s2));
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_keypair}\n");
  return 0u;
}


signed int pqcrystals_dilithium3_ref_signature_internal( char *llvm_cbe_sig, signed long long *llvm_cbe_siglen,  char *llvm_cbe_m, signed long long llvm_cbe_mlen,  char *llvm_cbe_pre, signed long long llvm_cbe_prelen,  char *llvm_cbe_rnd,  char *llvm_cbe_sk) {
  static  unsigned long long aesl_llvm_cbe_seedbuf_count = 0;
   char llvm_cbe_seedbuf[256];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_mat_count = 0;
  l_struct_OC_polyvecl llvm_cbe_mat[6];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_s1_count = 0;
  l_struct_OC_polyvecl llvm_cbe_s1;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_y_count = 0;
  l_struct_OC_polyvecl llvm_cbe_y;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_z_count = 0;
  l_struct_OC_polyvecl llvm_cbe_z;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_t0_count = 0;
  l_struct_OC_polyveck llvm_cbe_t0;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_s2_count = 0;
  l_struct_OC_polyveck llvm_cbe_s2;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_w1_count = 0;
  l_struct_OC_polyveck llvm_cbe_w1;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_w0_count = 0;
  l_struct_OC_polyveck llvm_cbe_w0;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_h_count = 0;
  l_struct_OC_polyveck llvm_cbe_h;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_cp_count = 0;
  l_struct_OC_poly llvm_cbe_cp;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_state_count = 0;
  l_struct_OC_keccak_state llvm_cbe_state;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
   char *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
   char *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
   char *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
   char *llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
   char *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  l_struct_OC_polyvecl *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  unsigned short llvm_cbe_tmp__44;
  unsigned short llvm_cbe_tmp__44__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  unsigned short llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  unsigned int llvm_cbe_tmp__46;
  unsigned int llvm_cbe_tmp__46__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  unsigned long long llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  signed int *llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  signed int *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  unsigned int llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  unsigned int llvm_cbe_tmp__52;
  unsigned int llvm_cbe_tmp__52__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  unsigned long long llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  signed int *llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  signed int *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  unsigned int llvm_cbe_tmp__58;
  unsigned int llvm_cbe_tmp__58__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  unsigned long long llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  signed int *llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  signed int *llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  unsigned int llvm_cbe_tmp__64;
  unsigned int llvm_cbe_tmp__64__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  unsigned int llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  unsigned long long llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  signed int *llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  signed int *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  unsigned int llvm_cbe_tmp__70;
  unsigned int llvm_cbe_tmp__70__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  unsigned int llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  unsigned long long llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  signed int *llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  signed int *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  unsigned int llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  unsigned int llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  unsigned int llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  unsigned int llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_signature_internal\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [256 x i8]* %%seedbuf, i64 0, i64 0, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__38 = ( char *)(&llvm_cbe_seedbuf[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds [256 x i8]* %%seedbuf, i64 0, i64 32, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__39 = ( char *)(&llvm_cbe_seedbuf[(((signed long long )32ull))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [256 x i8]* %%seedbuf, i64 0, i64 96, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__40 = ( char *)(&llvm_cbe_seedbuf[(((signed long long )96ull))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [256 x i8]* %%seedbuf, i64 0, i64 128, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__41 = ( char *)(&llvm_cbe_seedbuf[(((signed long long )128ull))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [256 x i8]* %%seedbuf, i64 0, i64 192, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__42 = ( char *)(&llvm_cbe_seedbuf[(((signed long long )192ull))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_unpack_sk(i8* %%1, i8* %%2, i8* %%3, %%struct.polyveck* %%t0, %%struct.polyvecl* %%s1, %%struct.polyveck* %%s2, i8* %%sk) nounwind, !dbg !8 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_155_count);
  pqcrystals_dilithium3_ref_unpack_sk(( char *)llvm_cbe_tmp__38, ( char *)llvm_cbe_tmp__39, ( char *)llvm_cbe_tmp__40, (l_struct_OC_polyveck *)(&llvm_cbe_t0), (l_struct_OC_polyvecl *)(&llvm_cbe_s1), (l_struct_OC_polyveck *)(&llvm_cbe_s2), ( char *)llvm_cbe_sk);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_init(%%struct.keccak_state* %%state) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_156_count);
  pqcrystals_dilithium_fips202_ref_shake256_init((l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_absorb(%%struct.keccak_state* %%state, i8* %%2, i64 64) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_157_count);
  pqcrystals_dilithium_fips202_ref_shake256_absorb((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_tmp__39, 64ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",64ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_absorb(%%struct.keccak_state* %%state, i8* %%pre, i64 %%prelen) nounwind, !dbg !8 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_158_count);
  pqcrystals_dilithium_fips202_ref_shake256_absorb((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_pre, llvm_cbe_prelen);
if (AESL_DEBUG_TRACE) {
printf("\nArgument prelen = 0x%I64X",llvm_cbe_prelen);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_absorb(%%struct.keccak_state* %%state, i8* %%m, i64 %%mlen) nounwind, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_159_count);
  pqcrystals_dilithium_fips202_ref_shake256_absorb((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_m, llvm_cbe_mlen);
if (AESL_DEBUG_TRACE) {
printf("\nArgument mlen = 0x%I64X",llvm_cbe_mlen);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_finalize(%%struct.keccak_state* %%state) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_160_count);
  pqcrystals_dilithium_fips202_ref_shake256_finalize((l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_squeeze(i8* %%4, i64 64, %%struct.keccak_state* %%state) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_161_count);
  pqcrystals_dilithium_fips202_ref_shake256_squeeze(( char *)llvm_cbe_tmp__41, 64ull, (l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",64ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_init(%%struct.keccak_state* %%state) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_162_count);
  pqcrystals_dilithium_fips202_ref_shake256_init((l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_absorb(%%struct.keccak_state* %%state, i8* %%3, i64 32) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_163_count);
  pqcrystals_dilithium_fips202_ref_shake256_absorb((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_tmp__40, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_absorb(%%struct.keccak_state* %%state, i8* %%rnd, i64 32) nounwind, !dbg !8 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_164_count);
  pqcrystals_dilithium_fips202_ref_shake256_absorb((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_rnd, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_absorb(%%struct.keccak_state* %%state, i8* %%4, i64 64) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_165_count);
  pqcrystals_dilithium_fips202_ref_shake256_absorb((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_tmp__41, 64ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",64ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_finalize(%%struct.keccak_state* %%state) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_166_count);
  pqcrystals_dilithium_fips202_ref_shake256_finalize((l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_squeeze(i8* %%5, i64 64, %%struct.keccak_state* %%state) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_167_count);
  pqcrystals_dilithium_fips202_ref_shake256_squeeze(( char *)llvm_cbe_tmp__42, 64ull, (l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",64ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds [6 x %%struct.polyvecl]* %%mat, i64 0, i64 0, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_168_count);
  llvm_cbe_tmp__43 = (l_struct_OC_polyvecl *)(&llvm_cbe_mat[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvec_matrix_expand(%%struct.polyvecl* %%6, i8* %%1) nounwind, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_169_count);
  pqcrystals_dilithium3_ref_polyvec_matrix_expand((l_struct_OC_polyvecl *)llvm_cbe_tmp__43, ( char *)llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvecl_ntt(%%struct.polyvecl* %%s1) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_170_count);
  pqcrystals_dilithium3_ref_polyvecl_ntt((l_struct_OC_polyvecl *)(&llvm_cbe_s1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_ntt(%%struct.polyveck* %%s2) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_171_count);
  pqcrystals_dilithium3_ref_polyveck_ntt((l_struct_OC_polyveck *)(&llvm_cbe_s2));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_ntt(%%struct.polyveck* %%t0) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_172_count);
  pqcrystals_dilithium3_ref_polyveck_ntt((l_struct_OC_polyveck *)(&llvm_cbe_t0));
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_tmp__44__PHI_TEMPORARY = (unsigned short )((unsigned short )0);   /* for PHI node */
  goto llvm_cbe_tmp__80;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__80:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = phi i16 [ 0, %%0 ], [ %%9, %%.backedge ], !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_174_count);
  llvm_cbe_tmp__44 = (unsigned short )llvm_cbe_tmp__44__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__44);
printf("\n = 0x%X",((unsigned short )0));
printf("\n = 0x%X",llvm_cbe_tmp__45);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i16 %%8, 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__45 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__44&65535ull)) + ((unsigned short )(((unsigned short )1)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__45&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvecl_uniform_gamma1(%%struct.polyvecl* %%y, i8* %%5, i16 zeroext %%8) nounwind, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_178_count);
  pqcrystals_dilithium3_ref_polyvecl_uniform_gamma1((l_struct_OC_polyvecl *)(&llvm_cbe_y), ( char *)llvm_cbe_tmp__42, llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__44);
}
  llvm_cbe_tmp__46__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_memcpy;

llvm_cbe__2e_backedge:
  llvm_cbe_tmp__44__PHI_TEMPORARY = (unsigned short )llvm_cbe_tmp__45;   /* for PHI node */
  goto llvm_cbe_tmp__80;

llvm_cbe_tmp__81:
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvecl_ntt(%%struct.polyvecl* %%z) nounwind, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_225_count);
  pqcrystals_dilithium3_ref_polyvecl_ntt((l_struct_OC_polyvecl *)(&llvm_cbe_z));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvec_matrix_pointwise_montgomery(%%struct.polyveck* %%w1, %%struct.polyvecl* %%6, %%struct.polyvecl* %%z) nounwind, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_226_count);
  pqcrystals_dilithium3_ref_polyvec_matrix_pointwise_montgomery((l_struct_OC_polyveck *)(&llvm_cbe_w1), (l_struct_OC_polyvecl *)llvm_cbe_tmp__43, (l_struct_OC_polyvecl *)(&llvm_cbe_z));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_reduce(%%struct.polyveck* %%w1) nounwind, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_227_count);
  pqcrystals_dilithium3_ref_polyveck_reduce((l_struct_OC_polyveck *)(&llvm_cbe_w1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_invntt_tomont(%%struct.polyveck* %%w1) nounwind, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_228_count);
  pqcrystals_dilithium3_ref_polyveck_invntt_tomont((l_struct_OC_polyveck *)(&llvm_cbe_w1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_caddq(%%struct.polyveck* %%w1) nounwind, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_229_count);
  pqcrystals_dilithium3_ref_polyveck_caddq((l_struct_OC_polyveck *)(&llvm_cbe_w1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_decompose(%%struct.polyveck* %%w1, %%struct.polyveck* %%w0, %%struct.polyveck* %%w1) nounwind, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_230_count);
  pqcrystals_dilithium3_ref_polyveck_decompose((l_struct_OC_polyveck *)(&llvm_cbe_w1), (l_struct_OC_polyveck *)(&llvm_cbe_w0), (l_struct_OC_polyveck *)(&llvm_cbe_w1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_pack_w1(i8* %%sig, %%struct.polyveck* %%w1) nounwind, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_231_count);
  pqcrystals_dilithium3_ref_polyveck_pack_w1(( char *)llvm_cbe_sig, (l_struct_OC_polyveck *)(&llvm_cbe_w1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_init(%%struct.keccak_state* %%state) nounwind, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_232_count);
  pqcrystals_dilithium_fips202_ref_shake256_init((l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_absorb(%%struct.keccak_state* %%state, i8* %%4, i64 64) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_233_count);
  pqcrystals_dilithium_fips202_ref_shake256_absorb((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_tmp__41, 64ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",64ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_absorb(%%struct.keccak_state* %%state, i8* %%sig, i64 768) nounwind, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_234_count);
  pqcrystals_dilithium_fips202_ref_shake256_absorb((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_sig, 768ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",768ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_finalize(%%struct.keccak_state* %%state) nounwind, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_235_count);
  pqcrystals_dilithium_fips202_ref_shake256_finalize((l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_squeeze(i8* %%sig, i64 48, %%struct.keccak_state* %%state) nounwind, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_236_count);
  pqcrystals_dilithium_fips202_ref_shake256_squeeze(( char *)llvm_cbe_sig, 48ull, (l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",48ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_poly_challenge(%%struct.poly* %%cp, i8* %%sig) nounwind, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_237_count);
  pqcrystals_dilithium3_ref_poly_challenge((l_struct_OC_poly *)(&llvm_cbe_cp), ( char *)llvm_cbe_sig);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_poly_ntt(%%struct.poly* %%cp) nounwind, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_238_count);
  pqcrystals_dilithium3_ref_poly_ntt((l_struct_OC_poly *)(&llvm_cbe_cp));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvecl_pointwise_poly_montgomery(%%struct.polyvecl* %%z, %%struct.poly* %%cp, %%struct.polyvecl* %%s1) nounwind, !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_239_count);
  pqcrystals_dilithium3_ref_polyvecl_pointwise_poly_montgomery((l_struct_OC_polyvecl *)(&llvm_cbe_z), (l_struct_OC_poly *)(&llvm_cbe_cp), (l_struct_OC_polyvecl *)(&llvm_cbe_s1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvecl_invntt_tomont(%%struct.polyvecl* %%z) nounwind, !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_240_count);
  pqcrystals_dilithium3_ref_polyvecl_invntt_tomont((l_struct_OC_polyvecl *)(&llvm_cbe_z));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvecl_add(%%struct.polyvecl* %%z, %%struct.polyvecl* %%z, %%struct.polyvecl* %%y) nounwind, !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_241_count);
  pqcrystals_dilithium3_ref_polyvecl_add((l_struct_OC_polyvecl *)(&llvm_cbe_z), (l_struct_OC_polyvecl *)(&llvm_cbe_z), (l_struct_OC_polyvecl *)(&llvm_cbe_y));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvecl_reduce(%%struct.polyvecl* %%z) nounwind, !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_242_count);
  pqcrystals_dilithium3_ref_polyvecl_reduce((l_struct_OC_polyvecl *)(&llvm_cbe_z));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = call i32 @pqcrystals_dilithium3_ref_polyvecl_chknorm(%%struct.polyvecl* %%z, i32 524092) nounwind, !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_243_count);
  llvm_cbe_tmp__76 = (unsigned int )pqcrystals_dilithium3_ref_polyvecl_chknorm((l_struct_OC_polyvecl *)(&llvm_cbe_z), 524092u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",524092u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__76);
}
  if (((llvm_cbe_tmp__76&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__82;
  } else {
    goto llvm_cbe__2e_backedge;
  }

  do {     /* Syntactic loop 'memcpy4' to make GCC happy */
llvm_cbe_memcpy4:
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = phi i32 [ %%39, %%memcpy4 ], [ 0, %%memcpy3 ], !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__70 = (unsigned int )llvm_cbe_tmp__70__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__70);
printf("\n = 0x%X",llvm_cbe_tmp__71);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add i32 %%38, 1, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_217_count);
  llvm_cbe_tmp__71 = (unsigned int )((unsigned int )(llvm_cbe_tmp__70&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__71&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = sext i32 %%38 to i64, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_218_count);
  llvm_cbe_tmp__72 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds %%struct.polyvecl* %%z, i64 0, i32 0, i64 4, i32 0, i64 %%40, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_219_count);
  llvm_cbe_tmp__73 = (signed int *)(&llvm_cbe_z.field0[(((signed long long )4ull))].field0[(((signed long long )llvm_cbe_tmp__72))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__72));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds %%struct.polyvecl* %%y, i64 0, i32 0, i64 4, i32 0, i64 %%40, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_220_count);
  llvm_cbe_tmp__74 = (signed int *)(&llvm_cbe_y.field0[(((signed long long )4ull))].field0[(((signed long long )llvm_cbe_tmp__72))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__72));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load i32* %%42, align 4, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_221_count);
  llvm_cbe_tmp__75 = (unsigned int )*llvm_cbe_tmp__74;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%43, i32* %%41, align 4, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_222_count);
  *llvm_cbe_tmp__73 = llvm_cbe_tmp__75;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
  if (((llvm_cbe_tmp__70&4294967295U) == (255u&4294967295U))) {
    goto llvm_cbe_tmp__81;
  } else {
    llvm_cbe_tmp__70__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__71;   /* for PHI node */
    goto llvm_cbe_memcpy4;
  }

  } while (1); /* end of syntactic loop 'memcpy4' */
  do {     /* Syntactic loop 'memcpy3' to make GCC happy */
llvm_cbe_memcpy3:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = phi i32 [ %%32, %%memcpy3 ], [ 0, %%memcpy2 ], !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__64 = (unsigned int )llvm_cbe_tmp__64__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__64);
printf("\n = 0x%X",llvm_cbe_tmp__65);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add i32 %%31, 1, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_208_count);
  llvm_cbe_tmp__65 = (unsigned int )((unsigned int )(llvm_cbe_tmp__64&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__65&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = sext i32 %%31 to i64, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_209_count);
  llvm_cbe_tmp__66 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds %%struct.polyvecl* %%z, i64 0, i32 0, i64 3, i32 0, i64 %%33, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__67 = (signed int *)(&llvm_cbe_z.field0[(((signed long long )3ull))].field0[(((signed long long )llvm_cbe_tmp__66))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds %%struct.polyvecl* %%y, i64 0, i32 0, i64 3, i32 0, i64 %%33, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__68 = (signed int *)(&llvm_cbe_y.field0[(((signed long long )3ull))].field0[(((signed long long )llvm_cbe_tmp__66))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i32* %%35, align 4, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__69 = (unsigned int )*llvm_cbe_tmp__68;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%36, i32* %%34, align 4, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_213_count);
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
  do {     /* Syntactic loop 'memcpy2' to make GCC happy */
llvm_cbe_memcpy2:
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = phi i32 [ %%25, %%memcpy2 ], [ 0, %%memcpy1 ], !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_198_count);
  llvm_cbe_tmp__58 = (unsigned int )llvm_cbe_tmp__58__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__58);
printf("\n = 0x%X",llvm_cbe_tmp__59);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i32 %%24, 1, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_199_count);
  llvm_cbe_tmp__59 = (unsigned int )((unsigned int )(llvm_cbe_tmp__58&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__59&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = sext i32 %%24 to i64, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_200_count);
  llvm_cbe_tmp__60 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.polyvecl* %%z, i64 0, i32 0, i64 2, i32 0, i64 %%26, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__61 = (signed int *)(&llvm_cbe_z.field0[(((signed long long )2ull))].field0[(((signed long long )llvm_cbe_tmp__60))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__60));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds %%struct.polyvecl* %%y, i64 0, i32 0, i64 2, i32 0, i64 %%26, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_202_count);
  llvm_cbe_tmp__62 = (signed int *)(&llvm_cbe_y.field0[(((signed long long )2ull))].field0[(((signed long long )llvm_cbe_tmp__60))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__60));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i32* %%28, align 4, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__63 = (unsigned int )*llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%29, i32* %%27, align 4, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_204_count);
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
  do {     /* Syntactic loop 'memcpy1' to make GCC happy */
llvm_cbe_memcpy1:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = phi i32 [ %%18, %%memcpy1 ], [ 0, %%memcpy ], !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_189_count);
  llvm_cbe_tmp__52 = (unsigned int )llvm_cbe_tmp__52__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__52);
printf("\n = 0x%X",llvm_cbe_tmp__53);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i32 %%17, 1, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_190_count);
  llvm_cbe_tmp__53 = (unsigned int )((unsigned int )(llvm_cbe_tmp__52&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__53&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sext i32 %%17 to i64, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_191_count);
  llvm_cbe_tmp__54 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct.polyvecl* %%z, i64 0, i32 0, i64 1, i32 0, i64 %%19, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_192_count);
  llvm_cbe_tmp__55 = (signed int *)(&llvm_cbe_z.field0[(((signed long long )1ull))].field0[(((signed long long )llvm_cbe_tmp__54))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__54));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.polyvecl* %%y, i64 0, i32 0, i64 1, i32 0, i64 %%19, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_193_count);
  llvm_cbe_tmp__56 = (signed int *)(&llvm_cbe_y.field0[(((signed long long )1ull))].field0[(((signed long long )llvm_cbe_tmp__54))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__54));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i32* %%21, align 4, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_194_count);
  llvm_cbe_tmp__57 = (unsigned int )*llvm_cbe_tmp__56;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%22, i32* %%20, align 4, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_195_count);
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
  do {     /* Syntactic loop 'memcpy' to make GCC happy */
llvm_cbe_memcpy:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = phi i32 [ 0, %%7 ], [ %%11, %%memcpy ], !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__46 = (unsigned int )llvm_cbe_tmp__46__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__46);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__47);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i32 %%10, 1, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_181_count);
  llvm_cbe_tmp__47 = (unsigned int )((unsigned int )(llvm_cbe_tmp__46&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__47&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sext i32 %%10 to i64, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__48 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.polyvecl* %%z, i64 0, i32 0, i64 0, i32 0, i64 %%12, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_183_count);
  llvm_cbe_tmp__49 = (signed int *)(&llvm_cbe_z.field0[(((signed long long )0ull))].field0[(((signed long long )llvm_cbe_tmp__48))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__48));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.polyvecl* %%y, i64 0, i32 0, i64 0, i32 0, i64 %%12, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__50 = (signed int *)(&llvm_cbe_y.field0[(((signed long long )0ull))].field0[(((signed long long )llvm_cbe_tmp__48))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__48));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* %%14, align 4, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__51 = (unsigned int )*llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%15, i32* %%13, align 4, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_186_count);
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
llvm_cbe_tmp__82:
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_pointwise_poly_montgomery(%%struct.polyveck* %%h, %%struct.poly* %%cp, %%struct.polyveck* %%s2) nounwind, !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_247_count);
  pqcrystals_dilithium3_ref_polyveck_pointwise_poly_montgomery((l_struct_OC_polyveck *)(&llvm_cbe_h), (l_struct_OC_poly *)(&llvm_cbe_cp), (l_struct_OC_polyveck *)(&llvm_cbe_s2));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_invntt_tomont(%%struct.polyveck* %%h) nounwind, !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_248_count);
  pqcrystals_dilithium3_ref_polyveck_invntt_tomont((l_struct_OC_polyveck *)(&llvm_cbe_h));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_sub(%%struct.polyveck* %%w0, %%struct.polyveck* %%w0, %%struct.polyveck* %%h) nounwind, !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_249_count);
  pqcrystals_dilithium3_ref_polyveck_sub((l_struct_OC_polyveck *)(&llvm_cbe_w0), (l_struct_OC_polyveck *)(&llvm_cbe_w0), (l_struct_OC_polyveck *)(&llvm_cbe_h));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_reduce(%%struct.polyveck* %%w0) nounwind, !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_250_count);
  pqcrystals_dilithium3_ref_polyveck_reduce((l_struct_OC_polyveck *)(&llvm_cbe_w0));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = call i32 @pqcrystals_dilithium3_ref_polyveck_chknorm(%%struct.polyveck* %%w0, i32 261692) nounwind, !dbg !19 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_251_count);
  llvm_cbe_tmp__77 = (unsigned int )pqcrystals_dilithium3_ref_polyveck_chknorm((l_struct_OC_polyveck *)(&llvm_cbe_w0), 261692u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",261692u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__77);
}
  if (((llvm_cbe_tmp__77&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__83;
  } else {
    goto llvm_cbe__2e_backedge;
  }

llvm_cbe_tmp__83:
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_pointwise_poly_montgomery(%%struct.polyveck* %%h, %%struct.poly* %%cp, %%struct.polyveck* %%t0) nounwind, !dbg !20 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_254_count);
  pqcrystals_dilithium3_ref_polyveck_pointwise_poly_montgomery((l_struct_OC_polyveck *)(&llvm_cbe_h), (l_struct_OC_poly *)(&llvm_cbe_cp), (l_struct_OC_polyveck *)(&llvm_cbe_t0));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_invntt_tomont(%%struct.polyveck* %%h) nounwind, !dbg !20 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_255_count);
  pqcrystals_dilithium3_ref_polyveck_invntt_tomont((l_struct_OC_polyveck *)(&llvm_cbe_h));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_reduce(%%struct.polyveck* %%h) nounwind, !dbg !20 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_256_count);
  pqcrystals_dilithium3_ref_polyveck_reduce((l_struct_OC_polyveck *)(&llvm_cbe_h));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = call i32 @pqcrystals_dilithium3_ref_polyveck_chknorm(%%struct.polyveck* %%h, i32 261888) nounwind, !dbg !20 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_257_count);
  llvm_cbe_tmp__78 = (unsigned int )pqcrystals_dilithium3_ref_polyveck_chknorm((l_struct_OC_polyveck *)(&llvm_cbe_h), 261888u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",261888u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__78);
}
  if (((llvm_cbe_tmp__78&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__84;
  } else {
    goto llvm_cbe__2e_backedge;
  }

llvm_cbe_tmp__84:
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_add(%%struct.polyveck* %%w0, %%struct.polyveck* %%w0, %%struct.polyveck* %%h) nounwind, !dbg !20 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_260_count);
  pqcrystals_dilithium3_ref_polyveck_add((l_struct_OC_polyveck *)(&llvm_cbe_w0), (l_struct_OC_polyveck *)(&llvm_cbe_w0), (l_struct_OC_polyveck *)(&llvm_cbe_h));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = call i32 @pqcrystals_dilithium3_ref_polyveck_make_hint(%%struct.polyveck* %%h, %%struct.polyveck* %%w0, %%struct.polyveck* %%w1) nounwind, !dbg !20 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_261_count);
  llvm_cbe_tmp__79 = (unsigned int )pqcrystals_dilithium3_ref_polyveck_make_hint((l_struct_OC_polyveck *)(&llvm_cbe_h), (l_struct_OC_polyveck *)(&llvm_cbe_w0), (l_struct_OC_polyveck *)(&llvm_cbe_w1));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__79);
}
  if ((((unsigned int )llvm_cbe_tmp__79&4294967295U) > ((unsigned int )55u&4294967295U))) {
    goto llvm_cbe__2e_backedge;
  } else {
    goto llvm_cbe_tmp__85;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__85:
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_pack_sig(i8* %%sig, i8* %%sig, %%struct.polyvecl* %%z, %%struct.polyveck* %%h) nounwind, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_266_count);
  pqcrystals_dilithium3_ref_pack_sig(( char *)llvm_cbe_sig, ( char *)llvm_cbe_sig, (l_struct_OC_polyvecl *)(&llvm_cbe_z), (l_struct_OC_polyveck *)(&llvm_cbe_h));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 3309, i64* %%siglen, align 8, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature_internal  --> \n", ++aesl_llvm_cbe_267_count);
  *llvm_cbe_siglen = 3309ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 3309ull);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_signature_internal}\n");
  return 0u;
}


signed int pqcrystals_dilithium3_ref_signature( char *llvm_cbe_sig, signed long long *llvm_cbe_siglen,  char *llvm_cbe_m, signed long long llvm_cbe_mlen,  char *llvm_cbe_ctx, signed long long llvm_cbe_ctxlen,  char *llvm_cbe_sk) {
  static  unsigned long long aesl_llvm_cbe_pre_count = 0;
   char llvm_cbe_pre[257];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_rnd_count = 0;
   char llvm_cbe_rnd[32];    /* Address-exposed local */
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
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
   char *llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  unsigned char llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
   char *llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2_count = 0;
  unsigned long long llvm_cbe_storemerge2;
  unsigned long long llvm_cbe_storemerge2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
   char *llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  unsigned char llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  unsigned long long llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
   char *llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  unsigned long long llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
   char *llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  unsigned long long llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  unsigned int llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_signature\n");
  if ((((unsigned long long )llvm_cbe_ctxlen&18446744073709551615ULL) > ((unsigned long long )255ull&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe_tmp__97;
  } else {
    goto llvm_cbe_tmp__98;
  }

llvm_cbe_tmp__98:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [257 x i8]* %%pre, i64 0, i64 0, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_290_count);
  llvm_cbe_tmp__86 = ( char *)(&llvm_cbe_pre[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 257
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 257 && "Write access out of array 'pre' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%3, align 16, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_291_count);
  *llvm_cbe_tmp__86 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = trunc i64 %%ctxlen to i8, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_292_count);
  llvm_cbe_tmp__87 = (unsigned char )((unsigned char )llvm_cbe_ctxlen&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [257 x i8]* %%pre, i64 0, i64 1, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_293_count);
  llvm_cbe_tmp__88 = ( char *)(&llvm_cbe_pre[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 257
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 257 && "Write access out of array 'pre' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%4, i8* %%5, align 1, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_294_count);
  *llvm_cbe_tmp__88 = llvm_cbe_tmp__87;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__87);
  if (((llvm_cbe_ctxlen&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2 = phi i64 [ %%11, %%.lr.ph ], [ 0, %%2  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_storemerge2_count);
  llvm_cbe_storemerge2 = (unsigned long long )llvm_cbe_storemerge2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2 = 0x%I64X",llvm_cbe_storemerge2);
printf("\n = 0x%I64X",llvm_cbe_tmp__93);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i8* %%ctx, i64 %%storemerge2, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_302_count);
  llvm_cbe_tmp__89 = ( char *)(&llvm_cbe_ctx[(((signed long long )llvm_cbe_storemerge2))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2 = 0x%I64X",((signed long long )llvm_cbe_storemerge2));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i8* %%7, align 1, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_303_count);
  llvm_cbe_tmp__90 = (unsigned char )*llvm_cbe_tmp__89;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i64 %%storemerge2, 2, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_304_count);
  llvm_cbe_tmp__91 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge2&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__91&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [257 x i8]* %%pre, i64 0, i64 %%9, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_305_count);
  llvm_cbe_tmp__92 = ( char *)(&llvm_cbe_pre[(((signed long long )llvm_cbe_tmp__91))
#ifdef AESL_BC_SIM
 % 257
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__91));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__91) < 257 && "Write access out of array 'pre' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%8, i8* %%10, align 1, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_306_count);
  *llvm_cbe_tmp__92 = llvm_cbe_tmp__90;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i64 %%storemerge2, 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_307_count);
  llvm_cbe_tmp__93 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge2&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__93&18446744073709551615ull)));
  if (((llvm_cbe_tmp__93&18446744073709551615ULL) == (llvm_cbe_ctxlen&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__93;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [32 x i8]* %%rnd, i64 0, i64 0, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_314_count);
  llvm_cbe_tmp__94 = ( char *)(&llvm_cbe_rnd[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @randombytes(i8* %%12, i64 32) nounwind, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_315_count);
  randombytes(( char *)llvm_cbe_tmp__94, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add i64 %%ctxlen, 2, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_316_count);
  llvm_cbe_tmp__95 = (unsigned long long )((unsigned long long )(llvm_cbe_ctxlen&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__95&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = call i32 @pqcrystals_dilithium3_ref_signature_internal(i8* %%sig, i64* %%siglen, i8* %%m, i64 %%mlen, i8* %%3, i64 %%13, i8* %%12, i8* %%sk), !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_317_count);
  pqcrystals_dilithium3_ref_signature_internal(( char *)llvm_cbe_sig, (signed long long *)llvm_cbe_siglen, ( char *)llvm_cbe_m, llvm_cbe_mlen, ( char *)llvm_cbe_tmp__86, llvm_cbe_tmp__95, ( char *)llvm_cbe_tmp__94, ( char *)llvm_cbe_sk);
if (AESL_DEBUG_TRACE) {
printf("\nArgument mlen = 0x%I64X",llvm_cbe_mlen);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__95);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__96);
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__97;

llvm_cbe_tmp__97:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%._crit_edge ], [ -1, %%0  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_signature  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",4294967295u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_signature}\n");
  return llvm_cbe_storemerge1;
}


signed int pqcrystals_dilithium3_ref( char *llvm_cbe_sm, signed long long *llvm_cbe_smlen,  char *llvm_cbe_m, signed long long llvm_cbe_mlen,  char *llvm_cbe_ctx, signed long long llvm_cbe_ctxlen,  char *llvm_cbe_sk) {
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  unsigned long long llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  unsigned long long llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_2e_neg2_count = 0;
  unsigned long long llvm_cbe_storemerge_2e_neg2;
  unsigned long long llvm_cbe_storemerge_2e_neg2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  unsigned long long llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
   char *llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  unsigned char llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  unsigned long long llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
   char *llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  unsigned long long llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_2e_neg_count = 0;
  unsigned long long llvm_cbe_storemerge_2e_neg;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
   char *llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  unsigned int llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  unsigned long long llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  unsigned long long llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref\n");
  if (((llvm_cbe_mlen&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add i64 %%mlen, -1, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_348_count);
  llvm_cbe_tmp__99 = (unsigned long long )((unsigned long long )(llvm_cbe_mlen&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__99&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add i64 %%mlen, 3308, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_349_count);
  llvm_cbe_tmp__100 = (unsigned long long )((unsigned long long )(llvm_cbe_mlen&18446744073709551615ull)) + ((unsigned long long )(3308ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__100&18446744073709551615ull)));
  llvm_cbe_storemerge_2e_neg2__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__111;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__111:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge.neg2 = phi i64 [ 0, %%.lr.ph ], [ %%storemerge.neg, %%4  for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_storemerge_2e_neg2_count);
  llvm_cbe_storemerge_2e_neg2 = (unsigned long long )llvm_cbe_storemerge_2e_neg2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge.neg2 = 0x%I64X",llvm_cbe_storemerge_2e_neg2);
printf("\n = 0x%I64X",0ull);
printf("\nstoremerge.neg = 0x%I64X",llvm_cbe_storemerge_2e_neg);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ 0, %%.lr.ph ], [ %%10, %%4  for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__106);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add i64 %%2, %%storemerge.neg2, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_351_count);
  llvm_cbe_tmp__101 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__99&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge_2e_neg2&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__101&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds i8* %%m, i64 %%5, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__102 = ( char *)(&llvm_cbe_m[(((signed long long )llvm_cbe_tmp__101))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__101));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i8* %%6, align 1, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_353_count);
  llvm_cbe_tmp__103 = (unsigned char )*llvm_cbe_tmp__102;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__103);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i64 %%3, %%storemerge.neg2, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_354_count);
  llvm_cbe_tmp__104 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__100&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge_2e_neg2&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__104&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds i8* %%sm, i64 %%8, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_355_count);
  llvm_cbe_tmp__105 = ( char *)(&llvm_cbe_sm[(((signed long long )llvm_cbe_tmp__104))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__104));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%7, i8* %%9, align 1, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_356_count);
  *llvm_cbe_tmp__105 = llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__103);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i64 %%storemerge1, 1, !dbg !8 for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_357_count);
  llvm_cbe_tmp__106 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__106&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge.neg = xor i64 %%storemerge1, - for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_storemerge_2e_neg_count);
  llvm_cbe_storemerge_2e_neg = (unsigned long long )llvm_cbe_storemerge1 ^ 18446744073709551615ull;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge.neg = 0x%I64X\n", llvm_cbe_storemerge_2e_neg);
  if (((llvm_cbe_tmp__106&18446744073709551615ULL) == (llvm_cbe_mlen&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge_2e_neg2__PHI_TEMPORARY = (unsigned long long )llvm_cbe_storemerge_2e_neg;   /* for PHI node */
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__106;   /* for PHI node */
    goto llvm_cbe_tmp__111;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds i8* %%sm, i64 3309, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_364_count);
  llvm_cbe_tmp__107 = ( char *)(&llvm_cbe_sm[(((signed long long )3309ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = tail call i32 @pqcrystals_dilithium3_ref_signature(i8* %%sm, i64* %%smlen, i8* %%11, i64 %%mlen, i8* %%ctx, i64 %%ctxlen, i8* %%sk), !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_365_count);
  llvm_cbe_tmp__108 = (unsigned int ) /*tail*/ pqcrystals_dilithium3_ref_signature(( char *)llvm_cbe_sm, (signed long long *)llvm_cbe_smlen, ( char *)llvm_cbe_tmp__107, llvm_cbe_mlen, ( char *)llvm_cbe_ctx, llvm_cbe_ctxlen, ( char *)llvm_cbe_sk);
if (AESL_DEBUG_TRACE) {
printf("\nArgument mlen = 0x%I64X",llvm_cbe_mlen);
printf("\nArgument ctxlen = 0x%I64X",llvm_cbe_ctxlen);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__108);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i64* %%smlen, align 8, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_368_count);
  llvm_cbe_tmp__109 = (unsigned long long )*llvm_cbe_smlen;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add i64 %%13, %%mlen, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_369_count);
  llvm_cbe_tmp__110 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__109&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_mlen&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__110&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%14, i64* %%smlen, align 8, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref  --> \n", ++aesl_llvm_cbe_370_count);
  *llvm_cbe_smlen = llvm_cbe_tmp__110;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__110);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref}\n");
  return llvm_cbe_tmp__108;
}


signed int pqcrystals_dilithium3_ref_verify_internal( char *llvm_cbe_sig, signed long long llvm_cbe_siglen,  char *llvm_cbe_m, signed long long llvm_cbe_mlen,  char *llvm_cbe_pre, signed long long llvm_cbe_prelen,  char *llvm_cbe_pk) {
  static  unsigned long long aesl_llvm_cbe_buf_count = 0;
   char llvm_cbe_buf[768];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_rho_count = 0;
   char llvm_cbe_rho[32];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_mu_count = 0;
   char llvm_cbe_mu[64];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_c_count = 0;
   char llvm_cbe_c[48];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_c2_count = 0;
   char llvm_cbe_c2[48];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_cp_count = 0;
  l_struct_OC_poly llvm_cbe_cp;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_mat_count = 0;
  l_struct_OC_polyvecl llvm_cbe_mat[6];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_z_count = 0;
  l_struct_OC_polyvecl llvm_cbe_z;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_t1_count = 0;
  l_struct_OC_polyveck llvm_cbe_t1;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_w1_count = 0;
  l_struct_OC_polyveck llvm_cbe_w1;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_h_count = 0;
  l_struct_OC_polyveck llvm_cbe_h;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_state_count = 0;
  l_struct_OC_keccak_state llvm_cbe_state;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
   char *llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
   char *llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  unsigned int llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  unsigned int llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
   char *llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  l_struct_OC_polyvecl *llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
   char *llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
   char *llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned int llvm_cbe_storemerge;
  unsigned int llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  unsigned long long llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
   char *llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  unsigned char llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
   char *llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  unsigned char llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  unsigned int llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  unsigned int llvm_cbe_tmp__126;
  unsigned int llvm_cbe_tmp__126__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_verify_internal\n");
  if (((llvm_cbe_siglen&18446744073709551615ULL) == (3309ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__127;
  } else {
    llvm_cbe_tmp__126__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

llvm_cbe_tmp__127:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [32 x i8]* %%rho, i64 0, i64 0, !dbg !8 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_401_count);
  llvm_cbe_tmp__112 = ( char *)(&llvm_cbe_rho[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_unpack_pk(i8* %%3, %%struct.polyveck* %%t1, i8* %%pk) nounwind, !dbg !8 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_402_count);
  pqcrystals_dilithium3_ref_unpack_pk(( char *)llvm_cbe_tmp__112, (l_struct_OC_polyveck *)(&llvm_cbe_t1), ( char *)llvm_cbe_pk);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [48 x i8]* %%c, i64 0, i64 0, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_403_count);
  llvm_cbe_tmp__113 = ( char *)(&llvm_cbe_c[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i32 @pqcrystals_dilithium3_ref_unpack_sig(i8* %%4, %%struct.polyvecl* %%z, %%struct.polyveck* %%h, i8* %%sig) nounwind, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_404_count);
  llvm_cbe_tmp__114 = (unsigned int )pqcrystals_dilithium3_ref_unpack_sig(( char *)llvm_cbe_tmp__113, (l_struct_OC_polyvecl *)(&llvm_cbe_z), (l_struct_OC_polyveck *)(&llvm_cbe_h), ( char *)llvm_cbe_sig);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__114);
}
  if (((llvm_cbe_tmp__114&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__128;
  } else {
    llvm_cbe_tmp__126__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

llvm_cbe_tmp__128:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call i32 @pqcrystals_dilithium3_ref_polyvecl_chknorm(%%struct.polyvecl* %%z, i32 524092) nounwind, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_407_count);
  llvm_cbe_tmp__115 = (unsigned int )pqcrystals_dilithium3_ref_polyvecl_chknorm((l_struct_OC_polyvecl *)(&llvm_cbe_z), 524092u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",524092u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__115);
}
  if (((llvm_cbe_tmp__115&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__129;
  } else {
    llvm_cbe_tmp__126__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

llvm_cbe_tmp__129:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [64 x i8]* %%mu, i64 0, i64 0, !dbg !8 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_410_count);
  llvm_cbe_tmp__116 = ( char *)(&llvm_cbe_mu[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 64
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256(i8* %%11, i64 64, i8* %%pk, i64 1952) nounwind, !dbg !8 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_411_count);
  pqcrystals_dilithium_fips202_ref_shake256(( char *)llvm_cbe_tmp__116, 64ull, ( char *)llvm_cbe_pk, 1952ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",64ull);
printf("\nArgument  = 0x%I64X",1952ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_init(%%struct.keccak_state* %%state) nounwind, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_412_count);
  pqcrystals_dilithium_fips202_ref_shake256_init((l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_absorb(%%struct.keccak_state* %%state, i8* %%11, i64 64) nounwind, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_413_count);
  pqcrystals_dilithium_fips202_ref_shake256_absorb((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_tmp__116, 64ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",64ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_absorb(%%struct.keccak_state* %%state, i8* %%pre, i64 %%prelen) nounwind, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_414_count);
  pqcrystals_dilithium_fips202_ref_shake256_absorb((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_pre, llvm_cbe_prelen);
if (AESL_DEBUG_TRACE) {
printf("\nArgument prelen = 0x%I64X",llvm_cbe_prelen);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_absorb(%%struct.keccak_state* %%state, i8* %%m, i64 %%mlen) nounwind, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_415_count);
  pqcrystals_dilithium_fips202_ref_shake256_absorb((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_m, llvm_cbe_mlen);
if (AESL_DEBUG_TRACE) {
printf("\nArgument mlen = 0x%I64X",llvm_cbe_mlen);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_finalize(%%struct.keccak_state* %%state) nounwind, !dbg !15 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_416_count);
  pqcrystals_dilithium_fips202_ref_shake256_finalize((l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_squeeze(i8* %%11, i64 64, %%struct.keccak_state* %%state) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_417_count);
  pqcrystals_dilithium_fips202_ref_shake256_squeeze(( char *)llvm_cbe_tmp__116, 64ull, (l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",64ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_poly_challenge(%%struct.poly* %%cp, i8* %%4) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_418_count);
  pqcrystals_dilithium3_ref_poly_challenge((l_struct_OC_poly *)(&llvm_cbe_cp), ( char *)llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [6 x %%struct.polyvecl]* %%mat, i64 0, i64 0, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_419_count);
  llvm_cbe_tmp__117 = (l_struct_OC_polyvecl *)(&llvm_cbe_mat[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvec_matrix_expand(%%struct.polyvecl* %%12, i8* %%3) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_420_count);
  pqcrystals_dilithium3_ref_polyvec_matrix_expand((l_struct_OC_polyvecl *)llvm_cbe_tmp__117, ( char *)llvm_cbe_tmp__112);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvecl_ntt(%%struct.polyvecl* %%z) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_421_count);
  pqcrystals_dilithium3_ref_polyvecl_ntt((l_struct_OC_polyvecl *)(&llvm_cbe_z));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyvec_matrix_pointwise_montgomery(%%struct.polyveck* %%w1, %%struct.polyvecl* %%12, %%struct.polyvecl* %%z) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_422_count);
  pqcrystals_dilithium3_ref_polyvec_matrix_pointwise_montgomery((l_struct_OC_polyveck *)(&llvm_cbe_w1), (l_struct_OC_polyvecl *)llvm_cbe_tmp__117, (l_struct_OC_polyvecl *)(&llvm_cbe_z));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_poly_ntt(%%struct.poly* %%cp) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_423_count);
  pqcrystals_dilithium3_ref_poly_ntt((l_struct_OC_poly *)(&llvm_cbe_cp));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_shiftl(%%struct.polyveck* %%t1) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_424_count);
  pqcrystals_dilithium3_ref_polyveck_shiftl((l_struct_OC_polyveck *)(&llvm_cbe_t1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_ntt(%%struct.polyveck* %%t1) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_425_count);
  pqcrystals_dilithium3_ref_polyveck_ntt((l_struct_OC_polyveck *)(&llvm_cbe_t1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_pointwise_poly_montgomery(%%struct.polyveck* %%t1, %%struct.poly* %%cp, %%struct.polyveck* %%t1) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_426_count);
  pqcrystals_dilithium3_ref_polyveck_pointwise_poly_montgomery((l_struct_OC_polyveck *)(&llvm_cbe_t1), (l_struct_OC_poly *)(&llvm_cbe_cp), (l_struct_OC_polyveck *)(&llvm_cbe_t1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_sub(%%struct.polyveck* %%w1, %%struct.polyveck* %%w1, %%struct.polyveck* %%t1) nounwind, !dbg !16 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_427_count);
  pqcrystals_dilithium3_ref_polyveck_sub((l_struct_OC_polyveck *)(&llvm_cbe_w1), (l_struct_OC_polyveck *)(&llvm_cbe_w1), (l_struct_OC_polyveck *)(&llvm_cbe_t1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_reduce(%%struct.polyveck* %%w1) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_428_count);
  pqcrystals_dilithium3_ref_polyveck_reduce((l_struct_OC_polyveck *)(&llvm_cbe_w1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_invntt_tomont(%%struct.polyveck* %%w1) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_429_count);
  pqcrystals_dilithium3_ref_polyveck_invntt_tomont((l_struct_OC_polyveck *)(&llvm_cbe_w1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_caddq(%%struct.polyveck* %%w1) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_430_count);
  pqcrystals_dilithium3_ref_polyveck_caddq((l_struct_OC_polyveck *)(&llvm_cbe_w1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_use_hint(%%struct.polyveck* %%w1, %%struct.polyveck* %%w1, %%struct.polyveck* %%h) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_431_count);
  pqcrystals_dilithium3_ref_polyveck_use_hint((l_struct_OC_polyveck *)(&llvm_cbe_w1), (l_struct_OC_polyveck *)(&llvm_cbe_w1), (l_struct_OC_polyveck *)(&llvm_cbe_h));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [768 x i8]* %%buf, i64 0, i64 0, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_432_count);
  llvm_cbe_tmp__118 = ( char *)(&llvm_cbe_buf[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 768
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium3_ref_polyveck_pack_w1(i8* %%13, %%struct.polyveck* %%w1) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_433_count);
  pqcrystals_dilithium3_ref_polyveck_pack_w1(( char *)llvm_cbe_tmp__118, (l_struct_OC_polyveck *)(&llvm_cbe_w1));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_init(%%struct.keccak_state* %%state) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_434_count);
  pqcrystals_dilithium_fips202_ref_shake256_init((l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_absorb(%%struct.keccak_state* %%state, i8* %%11, i64 64) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_435_count);
  pqcrystals_dilithium_fips202_ref_shake256_absorb((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_tmp__116, 64ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",64ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_absorb(%%struct.keccak_state* %%state, i8* %%13, i64 768) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_436_count);
  pqcrystals_dilithium_fips202_ref_shake256_absorb((l_struct_OC_keccak_state *)(&llvm_cbe_state), ( char *)llvm_cbe_tmp__118, 768ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",768ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_finalize(%%struct.keccak_state* %%state) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_437_count);
  pqcrystals_dilithium_fips202_ref_shake256_finalize((l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds [48 x i8]* %%c2, i64 0, i64 0, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_438_count);
  llvm_cbe_tmp__119 = ( char *)(&llvm_cbe_c2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @pqcrystals_dilithium_fips202_ref_shake256_squeeze(i8* %%14, i64 48, %%struct.keccak_state* %%state) nounwind, !dbg !17 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_439_count);
  pqcrystals_dilithium_fips202_ref_shake256_squeeze(( char *)llvm_cbe_tmp__119, 48ull, (l_struct_OC_keccak_state *)(&llvm_cbe_state));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",48ull);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__130;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__130:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i32 [ 0, %%10 ], [ %%24, %%17  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned int )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__125);
}
  if ((((unsigned int )llvm_cbe_storemerge&4294967295U) < ((unsigned int )48u&4294967295U))) {
    goto llvm_cbe_tmp__131;
  } else {
    llvm_cbe_tmp__126__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

llvm_cbe_tmp__131:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = zext i32 %%storemerge to i64, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_448_count);
  llvm_cbe_tmp__120 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__120);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds [48 x i8]* %%c, i64 0, i64 %%18, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_449_count);
  llvm_cbe_tmp__121 = ( char *)(&llvm_cbe_c[(((signed long long )llvm_cbe_tmp__120))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__120));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__120) < 48)) fprintf(stderr, "%s:%d: warning: Read access out of array 'c' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i8* %%19, align 1, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_450_count);
  llvm_cbe_tmp__122 = (unsigned char )*llvm_cbe_tmp__121;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds [48 x i8]* %%c2, i64 0, i64 %%18, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_451_count);
  llvm_cbe_tmp__123 = ( char *)(&llvm_cbe_c2[(((signed long long )llvm_cbe_tmp__120))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__120));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__120) < 48)) fprintf(stderr, "%s:%d: warning: Read access out of array 'c2' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i8* %%21, align 1, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_452_count);
  llvm_cbe_tmp__124 = (unsigned char )*llvm_cbe_tmp__123;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__124);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i32 %%storemerge, 1, !dbg !18 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_454_count);
  llvm_cbe_tmp__125 = (unsigned int )((unsigned int )(llvm_cbe_storemerge&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__125&4294967295ull)));
  if (((llvm_cbe_tmp__122&255U) == (llvm_cbe_tmp__124&255U))) {
    llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__125;   /* for PHI node */
    goto llvm_cbe_tmp__130;
  } else {
    llvm_cbe_tmp__126__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = phi i32 [ -1, %%0 ], [ -1, %%2 ], [ -1, %%7 ], [ 0, %%15 ], [ -1, %%17  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify_internal  --> \n", ++aesl_llvm_cbe_457_count);
  llvm_cbe_tmp__126 = (unsigned int )llvm_cbe_tmp__126__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__126);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",4294967295u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_verify_internal}\n");
  return llvm_cbe_tmp__126;
}


signed int pqcrystals_dilithium3_ref_verify( char *llvm_cbe_sig, signed long long llvm_cbe_siglen,  char *llvm_cbe_m, signed long long llvm_cbe_mlen,  char *llvm_cbe_ctx, signed long long llvm_cbe_ctxlen,  char *llvm_cbe_pk) {
  static  unsigned long long aesl_llvm_cbe_pre_count = 0;
   char llvm_cbe_pre[257];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
   char *llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  unsigned char llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
   char *llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2_count = 0;
  unsigned long long llvm_cbe_storemerge2;
  unsigned long long llvm_cbe_storemerge2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
   char *llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  unsigned char llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  unsigned long long llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
   char *llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  unsigned long long llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  unsigned long long llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  unsigned int llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_verify\n");
  if ((((unsigned long long )llvm_cbe_ctxlen&18446744073709551615ULL) > ((unsigned long long )255ull&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe_tmp__142;
  } else {
    goto llvm_cbe_tmp__143;
  }

llvm_cbe_tmp__143:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [257 x i8]* %%pre, i64 0, i64 0, !dbg !8 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify  --> \n", ++aesl_llvm_cbe_479_count);
  llvm_cbe_tmp__132 = ( char *)(&llvm_cbe_pre[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 257
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 257 && "Write access out of array 'pre' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%3, align 16, !dbg !8 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify  --> \n", ++aesl_llvm_cbe_480_count);
  *llvm_cbe_tmp__132 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = trunc i64 %%ctxlen to i8, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify  --> \n", ++aesl_llvm_cbe_481_count);
  llvm_cbe_tmp__133 = (unsigned char )((unsigned char )llvm_cbe_ctxlen&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__133);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [257 x i8]* %%pre, i64 0, i64 1, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify  --> \n", ++aesl_llvm_cbe_482_count);
  llvm_cbe_tmp__134 = ( char *)(&llvm_cbe_pre[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 257
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 257 && "Write access out of array 'pre' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%4, i8* %%5, align 1, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify  --> \n", ++aesl_llvm_cbe_483_count);
  *llvm_cbe_tmp__134 = llvm_cbe_tmp__133;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__133);
  if (((llvm_cbe_ctxlen&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2 = phi i64 [ %%11, %%.lr.ph ], [ 0, %%2  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify  --> \n", ++aesl_llvm_cbe_storemerge2_count);
  llvm_cbe_storemerge2 = (unsigned long long )llvm_cbe_storemerge2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2 = 0x%I64X",llvm_cbe_storemerge2);
printf("\n = 0x%I64X",llvm_cbe_tmp__139);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i8* %%ctx, i64 %%storemerge2, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify  --> \n", ++aesl_llvm_cbe_491_count);
  llvm_cbe_tmp__135 = ( char *)(&llvm_cbe_ctx[(((signed long long )llvm_cbe_storemerge2))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2 = 0x%I64X",((signed long long )llvm_cbe_storemerge2));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i8* %%7, align 1, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify  --> \n", ++aesl_llvm_cbe_492_count);
  llvm_cbe_tmp__136 = (unsigned char )*llvm_cbe_tmp__135;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__136);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i64 %%storemerge2, 2, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify  --> \n", ++aesl_llvm_cbe_493_count);
  llvm_cbe_tmp__137 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge2&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__137&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [257 x i8]* %%pre, i64 0, i64 %%9, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify  --> \n", ++aesl_llvm_cbe_494_count);
  llvm_cbe_tmp__138 = ( char *)(&llvm_cbe_pre[(((signed long long )llvm_cbe_tmp__137))
#ifdef AESL_BC_SIM
 % 257
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__137));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__137) < 257 && "Write access out of array 'pre' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%8, i8* %%10, align 1, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify  --> \n", ++aesl_llvm_cbe_495_count);
  *llvm_cbe_tmp__138 = llvm_cbe_tmp__136;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__136);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i64 %%storemerge2, 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify  --> \n", ++aesl_llvm_cbe_496_count);
  llvm_cbe_tmp__139 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge2&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__139&18446744073709551615ull)));
  if (((llvm_cbe_tmp__139&18446744073709551615ULL) == (llvm_cbe_ctxlen&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__139;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i64 %%ctxlen, 2, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify  --> \n", ++aesl_llvm_cbe_503_count);
  llvm_cbe_tmp__140 = (unsigned long long )((unsigned long long )(llvm_cbe_ctxlen&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__140&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = call i32 @pqcrystals_dilithium3_ref_verify_internal(i8* %%sig, i64 %%siglen, i8* %%m, i64 %%mlen, i8* %%3, i64 %%12, i8* %%pk), !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify  --> \n", ++aesl_llvm_cbe_504_count);
  llvm_cbe_tmp__141 = (unsigned int )pqcrystals_dilithium3_ref_verify_internal(( char *)llvm_cbe_sig, llvm_cbe_siglen, ( char *)llvm_cbe_m, llvm_cbe_mlen, ( char *)llvm_cbe_tmp__132, llvm_cbe_tmp__140, ( char *)llvm_cbe_pk);
if (AESL_DEBUG_TRACE) {
printf("\nArgument siglen = 0x%I64X",llvm_cbe_siglen);
printf("\nArgument mlen = 0x%I64X",llvm_cbe_mlen);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__140);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__141);
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__141;   /* for PHI node */
  goto llvm_cbe_tmp__142;

llvm_cbe_tmp__142:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%13, %%._crit_edge ], [ -1, %%0  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_verify  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__141);
printf("\n = 0x%X",4294967295u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_verify}\n");
  return llvm_cbe_storemerge1;
}


signed int pqcrystals_dilithium3_ref_open( char *llvm_cbe_m, signed long long *llvm_cbe_mlen,  char *llvm_cbe_sm, signed long long llvm_cbe_smlen,  char *llvm_cbe_ctx, signed long long llvm_cbe_ctxlen,  char *llvm_cbe_pk) {
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  unsigned long long llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
   char *llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  unsigned int llvm_cbe_tmp__146;
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
  unsigned long long llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge5_count = 0;
  unsigned long long llvm_cbe_storemerge5;
  unsigned long long llvm_cbe_storemerge5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  unsigned long long llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
   char *llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  unsigned char llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
   char *llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  unsigned long long llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  unsigned long long llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
   char *llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2_count = 0;
  unsigned int llvm_cbe_storemerge2;
  unsigned int llvm_cbe_storemerge2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_open\n");
  if ((((unsigned long long )llvm_cbe_smlen&18446744073709551615ULL) < ((unsigned long long )3309ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__155;
  } else {
    goto llvm_cbe_tmp__156;
  }

llvm_cbe_tmp__156:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add i64 %%smlen, -3309, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_531_count);
  llvm_cbe_tmp__144 = (unsigned long long )((unsigned long long )(llvm_cbe_smlen&18446744073709551615ull)) + ((unsigned long long )(18446744073709548307ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__144&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%3, i64* %%mlen, align 8, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_532_count);
  *llvm_cbe_mlen = llvm_cbe_tmp__144;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__144);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i8* %%sm, i64 3309, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_533_count);
  llvm_cbe_tmp__145 = ( char *)(&llvm_cbe_sm[(((signed long long )3309ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i32 @pqcrystals_dilithium3_ref_verify(i8* %%sm, i64 3309, i8* %%4, i64 %%3, i8* %%ctx, i64 %%ctxlen, i8* %%pk), !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_534_count);
  llvm_cbe_tmp__146 = (unsigned int ) /*tail*/ pqcrystals_dilithium3_ref_verify(( char *)llvm_cbe_sm, 3309ull, ( char *)llvm_cbe_tmp__145, llvm_cbe_tmp__144, ( char *)llvm_cbe_ctx, llvm_cbe_ctxlen, ( char *)llvm_cbe_pk);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",3309ull);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__144);
printf("\nArgument ctxlen = 0x%I64X",llvm_cbe_ctxlen);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__146);
}
  if (((llvm_cbe_tmp__146&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe_tmp__155;
  }

llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i64* %%mlen, align 8, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_544_count);
  llvm_cbe_tmp__147 = (unsigned long long )*llvm_cbe_mlen;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__147);
  if (((llvm_cbe_tmp__147&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit4;
  } else {
    llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph6;
  }

  do {     /* Syntactic loop '.lr.ph6' to make GCC happy */
llvm_cbe__2e_lr_2e_ph6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge5 = phi i64 [ %%13, %%.lr.ph6 ], [ 0, %%.preheader  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_storemerge5_count);
  llvm_cbe_storemerge5 = (unsigned long long )llvm_cbe_storemerge5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge5 = 0x%I64X",llvm_cbe_storemerge5);
printf("\n = 0x%I64X",llvm_cbe_tmp__152);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i64 %%storemerge5, 3309, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_547_count);
  llvm_cbe_tmp__148 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge5&18446744073709551615ull)) + ((unsigned long long )(3309ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__148&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i8* %%sm, i64 %%9, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_548_count);
  llvm_cbe_tmp__149 = ( char *)(&llvm_cbe_sm[(((signed long long )llvm_cbe_tmp__148))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__148));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i8* %%10, align 1, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_549_count);
  llvm_cbe_tmp__150 = (unsigned char )*llvm_cbe_tmp__149;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__150);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds i8* %%m, i64 %%storemerge5, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_550_count);
  llvm_cbe_tmp__151 = ( char *)(&llvm_cbe_m[(((signed long long )llvm_cbe_storemerge5))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge5 = 0x%I64X",((signed long long )llvm_cbe_storemerge5));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%11, i8* %%12, align 1, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_551_count);
  *llvm_cbe_tmp__151 = llvm_cbe_tmp__150;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__150);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add i64 %%storemerge5, 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_552_count);
  llvm_cbe_tmp__152 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge5&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__152&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%mlen, align 8, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_561_count);
  llvm_cbe_tmp__153 = (unsigned long long )*llvm_cbe_mlen;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__153);
  if ((((unsigned long long )llvm_cbe_tmp__152&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__153&18446744073709551615ULL))) {
    llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__152;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph6;
  } else {
    goto llvm_cbe__2e_loopexit4;
  }

  } while (1); /* end of syntactic loop '.lr.ph6' */
llvm_cbe_tmp__155:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%mlen, align 8, !dbg !7 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_564_count);
  *llvm_cbe_mlen = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
  if (((llvm_cbe_smlen&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = call i8* @memset(i8* %%m, i32 0, i64 %%smlen for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_575_count);
  ( char *)memset(( char *)llvm_cbe_m, 0u, llvm_cbe_smlen);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument smlen = 0x%I64X",llvm_cbe_smlen);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__154);
}
  goto llvm_cbe__2e_loopexit;

llvm_cbe__2e_loopexit:
  llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
  goto llvm_cbe_tmp__157;

llvm_cbe__2e_loopexit4:
  llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__157;

llvm_cbe_tmp__157:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2 = phi i32 [ -1, %%.loopexit ], [ 0, %%.loopexit4  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_open  --> \n", ++aesl_llvm_cbe_storemerge2_count);
  llvm_cbe_storemerge2 = (unsigned int )llvm_cbe_storemerge2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2 = 0x%X",llvm_cbe_storemerge2);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_open}\n");
  return llvm_cbe_storemerge2;
}

