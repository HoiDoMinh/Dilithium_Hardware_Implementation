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
typedef struct l_struct_OC_polyveck l_struct_OC_polyveck;
typedef struct l_struct_OC_poly l_struct_OC_poly;
typedef struct l_struct_OC_polyvecl l_struct_OC_polyvecl;

/* Structure contents */
struct l_struct_OC_poly {
  signed int field0[256];
};

struct l_struct_OC_polyveck {
  l_struct_OC_poly field0[6];
};

struct l_struct_OC_polyvecl {
  l_struct_OC_poly field0[5];
};


/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void pqcrystals_dilithium3_ref_pack_pk( char *llvm_cbe_pk,  char *llvm_cbe_rho, l_struct_OC_polyveck *llvm_cbe_t1);
void pqcrystals_dilithium3_ref_polyt1_pack( char *, l_struct_OC_poly *);
void pqcrystals_dilithium3_ref_unpack_pk( char *llvm_cbe_rho, l_struct_OC_polyveck *llvm_cbe_t1,  char *llvm_cbe_pk);
void pqcrystals_dilithium3_ref_polyt1_unpack(l_struct_OC_poly *,  char *);
void pqcrystals_dilithium3_ref_pack_sk( char *llvm_cbe_sk,  char *llvm_cbe_rho,  char *llvm_cbe_tr,  char *llvm_cbe_key, l_struct_OC_polyveck *llvm_cbe_t0, l_struct_OC_polyvecl *llvm_cbe_s1, l_struct_OC_polyveck *llvm_cbe_s2);
void pqcrystals_dilithium3_ref_polyeta_pack( char *, l_struct_OC_poly *);
void pqcrystals_dilithium3_ref_polyt0_pack( char *, l_struct_OC_poly *);
void pqcrystals_dilithium3_ref_unpack_sk( char *llvm_cbe_rho,  char *llvm_cbe_tr,  char *llvm_cbe_key, l_struct_OC_polyveck *llvm_cbe_t0, l_struct_OC_polyvecl *llvm_cbe_s1, l_struct_OC_polyveck *llvm_cbe_s2,  char *llvm_cbe_sk);
void pqcrystals_dilithium3_ref_polyeta_unpack(l_struct_OC_poly *,  char *);
void pqcrystals_dilithium3_ref_polyt0_unpack(l_struct_OC_poly *,  char *);
void pqcrystals_dilithium3_ref_pack_sig( char *llvm_cbe_sig,  char *llvm_cbe_c, l_struct_OC_polyvecl *llvm_cbe_z, l_struct_OC_polyveck *llvm_cbe_h);
void pqcrystals_dilithium3_ref_polyz_pack( char *, l_struct_OC_poly *);
signed int pqcrystals_dilithium3_ref_unpack_sig( char *llvm_cbe_c, l_struct_OC_polyvecl *llvm_cbe_z, l_struct_OC_polyveck *llvm_cbe_h,  char *llvm_cbe_sig);
void pqcrystals_dilithium3_ref_polyz_unpack(l_struct_OC_poly *,  char *);


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

void pqcrystals_dilithium3_ref_pack_pk( char *llvm_cbe_pk,  char *llvm_cbe_rho, l_struct_OC_polyveck *llvm_cbe_t1) {
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
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
   char *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
   char *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__4;
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
   char *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
   char *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__8;
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
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
   char *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__10;
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
   char *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__12;
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
  static  unsigned long long aesl_llvm_cbe_storemerge4_count = 0;
  unsigned int llvm_cbe_storemerge4;
  unsigned int llvm_cbe_storemerge4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  unsigned long long llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
   char *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  unsigned char llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
   char *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_pack_pk\n");
  llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__18;

llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds i8* %%pk, i64 32, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__1 = ( char *)(&llvm_cbe_pk[(((signed long long )32ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.polyveck* %%t1, i64 0, i32 0, i64 0, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__2 = (l_struct_OC_poly *)(&llvm_cbe_t1->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt1_pack(i8* %%1, %%struct.poly* %%2) nounwind, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_29_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt1_pack(( char *)llvm_cbe_tmp__1, (l_struct_OC_poly *)llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i8* %%pk, i64 352, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__3 = ( char *)(&llvm_cbe_pk[(((signed long long )352ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.polyveck* %%t1, i64 0, i32 0, i64 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__4 = (l_struct_OC_poly *)(&llvm_cbe_t1->field0[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt1_pack(i8* %%3, %%struct.poly* %%4) nounwind, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_41_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt1_pack(( char *)llvm_cbe_tmp__3, (l_struct_OC_poly *)llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds i8* %%pk, i64 672, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__5 = ( char *)(&llvm_cbe_pk[(((signed long long )672ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.polyveck* %%t1, i64 0, i32 0, i64 2, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__6 = (l_struct_OC_poly *)(&llvm_cbe_t1->field0[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt1_pack(i8* %%5, %%struct.poly* %%6) nounwind, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_53_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt1_pack(( char *)llvm_cbe_tmp__5, (l_struct_OC_poly *)llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i8* %%pk, i64 992, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__7 = ( char *)(&llvm_cbe_pk[(((signed long long )992ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.polyveck* %%t1, i64 0, i32 0, i64 3, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__8 = (l_struct_OC_poly *)(&llvm_cbe_t1->field0[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt1_pack(i8* %%7, %%struct.poly* %%8) nounwind, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_65_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt1_pack(( char *)llvm_cbe_tmp__7, (l_struct_OC_poly *)llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds i8* %%pk, i64 1312, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__9 = ( char *)(&llvm_cbe_pk[(((signed long long )1312ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.polyveck* %%t1, i64 0, i32 0, i64 4, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__10 = (l_struct_OC_poly *)(&llvm_cbe_t1->field0[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt1_pack(i8* %%9, %%struct.poly* %%10) nounwind, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_77_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt1_pack(( char *)llvm_cbe_tmp__9, (l_struct_OC_poly *)llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds i8* %%pk, i64 1632, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__11 = ( char *)(&llvm_cbe_pk[(((signed long long )1632ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.polyveck* %%t1, i64 0, i32 0, i64 5, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__12 = (l_struct_OC_poly *)(&llvm_cbe_t1->field0[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt1_pack(i8* %%11, %%struct.poly* %%12) nounwind, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_89_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt1_pack(( char *)llvm_cbe_tmp__11, (l_struct_OC_poly *)llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_pack_pk}\n");
  return;
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__18:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4 = phi i32 [ 0, %%0 ], [ %%18, %%13  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_storemerge4_count);
  llvm_cbe_storemerge4 = (unsigned int )llvm_cbe_storemerge4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%X",llvm_cbe_storemerge4);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__17);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i32 %%storemerge4 to i64, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__13 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge4&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds i8* %%rho, i64 %%14, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_101_count);
  llvm_cbe_tmp__14 = ( char *)(&llvm_cbe_rho[(((signed long long )llvm_cbe_tmp__13))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__13));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i8* %%15, align 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__15 = (unsigned char )*llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds i8* %%pk, i64 %%14, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__16 = ( char *)(&llvm_cbe_pk[(((signed long long )llvm_cbe_tmp__13))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__13));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%16, i8* %%17, align 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_104_count);
  *llvm_cbe_tmp__16 = llvm_cbe_tmp__15;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i32 %%storemerge4, 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_pk  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )(llvm_cbe_storemerge4&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__17&4294967295ull)));
  if (((llvm_cbe_tmp__17&4294967295U) == (32u&4294967295U))) {
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__17;   /* for PHI node */
    goto llvm_cbe_tmp__18;
  }

  } while (1); /* end of syntactic loop '' */
}


void pqcrystals_dilithium3_ref_unpack_pk( char *llvm_cbe_rho, l_struct_OC_polyveck *llvm_cbe_t1,  char *llvm_cbe_pk) {
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
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
   char *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
   char *llvm_cbe_tmp__22;
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
  l_struct_OC_poly *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
   char *llvm_cbe_tmp__24;
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
  l_struct_OC_poly *llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
   char *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
   char *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
   char *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge4_count = 0;
  unsigned int llvm_cbe_storemerge4;
  unsigned int llvm_cbe_storemerge4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  unsigned long long llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
   char *llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  unsigned char llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
   char *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_unpack_pk\n");
  llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__36;

llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.polyveck* %%t1, i64 0, i32 0, i64 0, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__19 = (l_struct_OC_poly *)(&llvm_cbe_t1->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds i8* %%pk, i64 32, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__20 = ( char *)(&llvm_cbe_pk[(((signed long long )32ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt1_unpack(%%struct.poly* %%1, i8* %%2) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_144_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt1_unpack((l_struct_OC_poly *)llvm_cbe_tmp__19, ( char *)llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.polyveck* %%t1, i64 0, i32 0, i64 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__21 = (l_struct_OC_poly *)(&llvm_cbe_t1->field0[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i8* %%pk, i64 352, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__22 = ( char *)(&llvm_cbe_pk[(((signed long long )352ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt1_unpack(%%struct.poly* %%3, i8* %%4) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_156_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt1_unpack((l_struct_OC_poly *)llvm_cbe_tmp__21, ( char *)llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.polyveck* %%t1, i64 0, i32 0, i64 2, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_166_count);
  llvm_cbe_tmp__23 = (l_struct_OC_poly *)(&llvm_cbe_t1->field0[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds i8* %%pk, i64 672, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__24 = ( char *)(&llvm_cbe_pk[(((signed long long )672ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt1_unpack(%%struct.poly* %%5, i8* %%6) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_168_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt1_unpack((l_struct_OC_poly *)llvm_cbe_tmp__23, ( char *)llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.polyveck* %%t1, i64 0, i32 0, i64 3, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__25 = (l_struct_OC_poly *)(&llvm_cbe_t1->field0[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i8* %%pk, i64 992, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__26 = ( char *)(&llvm_cbe_pk[(((signed long long )992ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt1_unpack(%%struct.poly* %%7, i8* %%8) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_180_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt1_unpack((l_struct_OC_poly *)llvm_cbe_tmp__25, ( char *)llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.polyveck* %%t1, i64 0, i32 0, i64 4, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_190_count);
  llvm_cbe_tmp__27 = (l_struct_OC_poly *)(&llvm_cbe_t1->field0[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i8* %%pk, i64 1312, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_191_count);
  llvm_cbe_tmp__28 = ( char *)(&llvm_cbe_pk[(((signed long long )1312ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt1_unpack(%%struct.poly* %%9, i8* %%10) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_192_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt1_unpack((l_struct_OC_poly *)llvm_cbe_tmp__27, ( char *)llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.polyveck* %%t1, i64 0, i32 0, i64 5, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_202_count);
  llvm_cbe_tmp__29 = (l_struct_OC_poly *)(&llvm_cbe_t1->field0[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds i8* %%pk, i64 1632, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__30 = ( char *)(&llvm_cbe_pk[(((signed long long )1632ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt1_unpack(%%struct.poly* %%11, i8* %%12) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_204_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt1_unpack((l_struct_OC_poly *)llvm_cbe_tmp__29, ( char *)llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_unpack_pk}\n");
  return;
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__36:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4 = phi i32 [ 0, %%0 ], [ %%18, %%13  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_storemerge4_count);
  llvm_cbe_storemerge4 = (unsigned int )llvm_cbe_storemerge4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%X",llvm_cbe_storemerge4);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__35);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i32 %%storemerge4 to i64, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_215_count);
  llvm_cbe_tmp__31 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge4&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds i8* %%pk, i64 %%14, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__32 = ( char *)(&llvm_cbe_pk[(((signed long long )llvm_cbe_tmp__31))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__31));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i8* %%15, align 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_217_count);
  llvm_cbe_tmp__33 = (unsigned char )*llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds i8* %%rho, i64 %%14, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_218_count);
  llvm_cbe_tmp__34 = ( char *)(&llvm_cbe_rho[(((signed long long )llvm_cbe_tmp__31))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__31));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%16, i8* %%17, align 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_219_count);
  *llvm_cbe_tmp__34 = llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i32 %%storemerge4, 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_pk  --> \n", ++aesl_llvm_cbe_220_count);
  llvm_cbe_tmp__35 = (unsigned int )((unsigned int )(llvm_cbe_storemerge4&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__35&4294967295ull)));
  if (((llvm_cbe_tmp__35&4294967295U) == (32u&4294967295U))) {
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__35;   /* for PHI node */
    goto llvm_cbe_tmp__36;
  }

  } while (1); /* end of syntactic loop '' */
}


void pqcrystals_dilithium3_ref_pack_sk( char *llvm_cbe_sk,  char *llvm_cbe_rho,  char *llvm_cbe_tr,  char *llvm_cbe_key, l_struct_OC_polyveck *llvm_cbe_t0, l_struct_OC_polyvecl *llvm_cbe_s1, l_struct_OC_polyveck *llvm_cbe_s2) {
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
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge19_count = 0;
  unsigned int llvm_cbe_storemerge19;
  unsigned int llvm_cbe_storemerge19__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  unsigned long long llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
   char *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  unsigned char llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
   char *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond21_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge118_count = 0;
  unsigned int llvm_cbe_storemerge118;
  unsigned int llvm_cbe_storemerge118__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  unsigned long long llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
   char *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  unsigned char llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe__2e_sum9_count = 0;
  unsigned long long llvm_cbe__2e_sum9;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
   char *llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_exitcond20_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
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
   char *llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
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
   char *llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
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
   char *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
   char *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
   char *llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
   char *llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__58;
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
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
   char *llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__60;
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
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
   char *llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
   char *llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__64;
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
   char *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__66;
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
  static  unsigned long long aesl_llvm_cbe_659_count = 0;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  static  unsigned long long aesl_llvm_cbe_666_count = 0;
  static  unsigned long long aesl_llvm_cbe_667_count = 0;
  static  unsigned long long aesl_llvm_cbe_668_count = 0;
  static  unsigned long long aesl_llvm_cbe_669_count = 0;
  static  unsigned long long aesl_llvm_cbe_670_count = 0;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
   char *llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  static  unsigned long long aesl_llvm_cbe_684_count = 0;
  static  unsigned long long aesl_llvm_cbe_685_count = 0;
  static  unsigned long long aesl_llvm_cbe_686_count = 0;
  static  unsigned long long aesl_llvm_cbe_687_count = 0;
  static  unsigned long long aesl_llvm_cbe_688_count = 0;
  static  unsigned long long aesl_llvm_cbe_689_count = 0;
  static  unsigned long long aesl_llvm_cbe_690_count = 0;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
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
   char *llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
   char *llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__72;
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
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
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
   char *llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
   char *llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__76;
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
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
   char *llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
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
   char *llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
  static  unsigned long long aesl_llvm_cbe_869_count = 0;
  static  unsigned long long aesl_llvm_cbe_870_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge216_count = 0;
  unsigned int llvm_cbe_storemerge216;
  unsigned int llvm_cbe_storemerge216__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
  unsigned long long llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
   char *llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
  unsigned char llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe__2e_sum8_count = 0;
  unsigned long long llvm_cbe__2e_sum8;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
   char *llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  unsigned int llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;
  static  unsigned long long aesl_llvm_cbe_910_count = 0;
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
  static  unsigned long long aesl_llvm_cbe_912_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_925_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_pack_sk\n");
  llvm_cbe_storemerge19__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__86;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__86:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge19 = phi i32 [ 0, %%0 ], [ %%6, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_storemerge19_count);
  llvm_cbe_storemerge19 = (unsigned int )llvm_cbe_storemerge19__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge19 = 0x%X",llvm_cbe_storemerge19);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__41);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%storemerge19 to i64, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_281_count);
  llvm_cbe_tmp__37 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge19&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i8* %%rho, i64 %%2, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_282_count);
  llvm_cbe_tmp__38 = ( char *)(&llvm_cbe_rho[(((signed long long )llvm_cbe_tmp__37))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__37));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8* %%3, align 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_283_count);
  llvm_cbe_tmp__39 = (unsigned char )*llvm_cbe_tmp__38;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds i8* %%sk, i64 %%2, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_284_count);
  llvm_cbe_tmp__40 = ( char *)(&llvm_cbe_sk[(((signed long long )llvm_cbe_tmp__37))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__37));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%4, i8* %%5, align 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_285_count);
  *llvm_cbe_tmp__40 = llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i32 %%storemerge19, 1, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_286_count);
  llvm_cbe_tmp__41 = (unsigned int )((unsigned int )(llvm_cbe_storemerge19&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__41&4294967295ull)));
  if (((llvm_cbe_tmp__41&4294967295U) == (32u&4294967295U))) {
    llvm_cbe_storemerge118__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader17;
  } else {
    llvm_cbe_storemerge19__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__41;   /* for PHI node */
    goto llvm_cbe_tmp__86;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader17' to make GCC happy */
llvm_cbe__2e_preheader17:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge118 = phi i32 [ %%11, %%.preheader17 ], [ 0, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_storemerge118_count);
  llvm_cbe_storemerge118 = (unsigned int )llvm_cbe_storemerge118__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge118 = 0x%X",llvm_cbe_storemerge118);
printf("\n = 0x%X",llvm_cbe_tmp__46);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = zext i32 %%storemerge118 to i64, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_313_count);
  llvm_cbe_tmp__42 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge118&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i8* %%key, i64 %%7, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_314_count);
  llvm_cbe_tmp__43 = ( char *)(&llvm_cbe_key[(((signed long long )llvm_cbe_tmp__42))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__42));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i8* %%8, align 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_315_count);
  llvm_cbe_tmp__44 = (unsigned char )*llvm_cbe_tmp__43;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum9 = add i64 %%7, 32, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe__2e_sum9_count);
  llvm_cbe__2e_sum9 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__42&18446744073709551615ull)) + ((unsigned long long )(32ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum9 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum9&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i8* %%sk, i64 %%.sum9, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_316_count);
  llvm_cbe_tmp__45 = ( char *)(&llvm_cbe_sk[(((signed long long )llvm_cbe__2e_sum9))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum9 = 0x%I64X",((signed long long )llvm_cbe__2e_sum9));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%9, i8* %%10, align 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_317_count);
  *llvm_cbe_tmp__45 = llvm_cbe_tmp__44;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i32 %%storemerge118, 1, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_318_count);
  llvm_cbe_tmp__46 = (unsigned int )((unsigned int )(llvm_cbe_storemerge118&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__46&4294967295ull)));
  if (((llvm_cbe_tmp__46&4294967295U) == (32u&4294967295U))) {
    llvm_cbe_storemerge216__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader15;
  } else {
    llvm_cbe_storemerge118__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__46;   /* for PHI node */
    goto llvm_cbe__2e_preheader17;
  }

  } while (1); /* end of syntactic loop '.preheader17' */
llvm_cbe__2e_preheader13:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds i8* %%sk, i64 128, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_369_count);
  llvm_cbe_tmp__47 = ( char *)(&llvm_cbe_sk[(((signed long long )128ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 0, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_370_count);
  llvm_cbe_tmp__48 = (l_struct_OC_poly *)(&llvm_cbe_s1->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_pack(i8* %%12, %%struct.poly* %%13) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_371_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_pack(( char *)llvm_cbe_tmp__47, (l_struct_OC_poly *)llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i8* %%sk, i64 256, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_397_count);
  llvm_cbe_tmp__49 = ( char *)(&llvm_cbe_sk[(((signed long long )256ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_398_count);
  llvm_cbe_tmp__50 = (l_struct_OC_poly *)(&llvm_cbe_s1->field0[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_pack(i8* %%14, %%struct.poly* %%15) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_399_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_pack(( char *)llvm_cbe_tmp__49, (l_struct_OC_poly *)llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds i8* %%sk, i64 384, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_425_count);
  llvm_cbe_tmp__51 = ( char *)(&llvm_cbe_sk[(((signed long long )384ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 2, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_426_count);
  llvm_cbe_tmp__52 = (l_struct_OC_poly *)(&llvm_cbe_s1->field0[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_pack(i8* %%16, %%struct.poly* %%17) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_427_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_pack(( char *)llvm_cbe_tmp__51, (l_struct_OC_poly *)llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds i8* %%sk, i64 512, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_453_count);
  llvm_cbe_tmp__53 = ( char *)(&llvm_cbe_sk[(((signed long long )512ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 3, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_454_count);
  llvm_cbe_tmp__54 = (l_struct_OC_poly *)(&llvm_cbe_s1->field0[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_pack(i8* %%18, %%struct.poly* %%19) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_455_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_pack(( char *)llvm_cbe_tmp__53, (l_struct_OC_poly *)llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds i8* %%sk, i64 640, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_481_count);
  llvm_cbe_tmp__55 = ( char *)(&llvm_cbe_sk[(((signed long long )640ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 4, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_482_count);
  llvm_cbe_tmp__56 = (l_struct_OC_poly *)(&llvm_cbe_s1->field0[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_pack(i8* %%20, %%struct.poly* %%21) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_483_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_pack(( char *)llvm_cbe_tmp__55, (l_struct_OC_poly *)llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds i8* %%sk, i64 768, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_533_count);
  llvm_cbe_tmp__57 = ( char *)(&llvm_cbe_sk[(((signed long long )768ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds %%struct.polyveck* %%s2, i64 0, i32 0, i64 0, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_534_count);
  llvm_cbe_tmp__58 = (l_struct_OC_poly *)(&llvm_cbe_s2->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_pack(i8* %%22, %%struct.poly* %%23) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_535_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_pack(( char *)llvm_cbe_tmp__57, (l_struct_OC_poly *)llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds i8* %%sk, i64 896, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_561_count);
  llvm_cbe_tmp__59 = ( char *)(&llvm_cbe_sk[(((signed long long )896ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.polyveck* %%s2, i64 0, i32 0, i64 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_562_count);
  llvm_cbe_tmp__60 = (l_struct_OC_poly *)(&llvm_cbe_s2->field0[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_pack(i8* %%24, %%struct.poly* %%25) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_563_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_pack(( char *)llvm_cbe_tmp__59, (l_struct_OC_poly *)llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds i8* %%sk, i64 1024, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_589_count);
  llvm_cbe_tmp__61 = ( char *)(&llvm_cbe_sk[(((signed long long )1024ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.polyveck* %%s2, i64 0, i32 0, i64 2, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_590_count);
  llvm_cbe_tmp__62 = (l_struct_OC_poly *)(&llvm_cbe_s2->field0[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_pack(i8* %%26, %%struct.poly* %%27) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_591_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_pack(( char *)llvm_cbe_tmp__61, (l_struct_OC_poly *)llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds i8* %%sk, i64 1152, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_617_count);
  llvm_cbe_tmp__63 = ( char *)(&llvm_cbe_sk[(((signed long long )1152ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds %%struct.polyveck* %%s2, i64 0, i32 0, i64 3, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_618_count);
  llvm_cbe_tmp__64 = (l_struct_OC_poly *)(&llvm_cbe_s2->field0[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_pack(i8* %%28, %%struct.poly* %%29) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_619_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_pack(( char *)llvm_cbe_tmp__63, (l_struct_OC_poly *)llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds i8* %%sk, i64 1280, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_645_count);
  llvm_cbe_tmp__65 = ( char *)(&llvm_cbe_sk[(((signed long long )1280ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds %%struct.polyveck* %%s2, i64 0, i32 0, i64 4, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_646_count);
  llvm_cbe_tmp__66 = (l_struct_OC_poly *)(&llvm_cbe_s2->field0[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_pack(i8* %%30, %%struct.poly* %%31) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_647_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_pack(( char *)llvm_cbe_tmp__65, (l_struct_OC_poly *)llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds i8* %%sk, i64 1408, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_673_count);
  llvm_cbe_tmp__67 = ( char *)(&llvm_cbe_sk[(((signed long long )1408ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds %%struct.polyveck* %%s2, i64 0, i32 0, i64 5, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_674_count);
  llvm_cbe_tmp__68 = (l_struct_OC_poly *)(&llvm_cbe_s2->field0[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_pack(i8* %%32, %%struct.poly* %%33) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_675_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_pack(( char *)llvm_cbe_tmp__67, (l_struct_OC_poly *)llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds i8* %%sk, i64 1536, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_725_count);
  llvm_cbe_tmp__69 = ( char *)(&llvm_cbe_sk[(((signed long long )1536ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds %%struct.polyveck* %%t0, i64 0, i32 0, i64 0, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_726_count);
  llvm_cbe_tmp__70 = (l_struct_OC_poly *)(&llvm_cbe_t0->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt0_pack(i8* %%34, %%struct.poly* %%35) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_727_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt0_pack(( char *)llvm_cbe_tmp__69, (l_struct_OC_poly *)llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds i8* %%sk, i64 1952, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_753_count);
  llvm_cbe_tmp__71 = ( char *)(&llvm_cbe_sk[(((signed long long )1952ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds %%struct.polyveck* %%t0, i64 0, i32 0, i64 1, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_754_count);
  llvm_cbe_tmp__72 = (l_struct_OC_poly *)(&llvm_cbe_t0->field0[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt0_pack(i8* %%36, %%struct.poly* %%37) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_755_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt0_pack(( char *)llvm_cbe_tmp__71, (l_struct_OC_poly *)llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds i8* %%sk, i64 2368, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_781_count);
  llvm_cbe_tmp__73 = ( char *)(&llvm_cbe_sk[(((signed long long )2368ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds %%struct.polyveck* %%t0, i64 0, i32 0, i64 2, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_782_count);
  llvm_cbe_tmp__74 = (l_struct_OC_poly *)(&llvm_cbe_t0->field0[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt0_pack(i8* %%38, %%struct.poly* %%39) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_783_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt0_pack(( char *)llvm_cbe_tmp__73, (l_struct_OC_poly *)llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds i8* %%sk, i64 2784, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_809_count);
  llvm_cbe_tmp__75 = ( char *)(&llvm_cbe_sk[(((signed long long )2784ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds %%struct.polyveck* %%t0, i64 0, i32 0, i64 3, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_810_count);
  llvm_cbe_tmp__76 = (l_struct_OC_poly *)(&llvm_cbe_t0->field0[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt0_pack(i8* %%40, %%struct.poly* %%41) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_811_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt0_pack(( char *)llvm_cbe_tmp__75, (l_struct_OC_poly *)llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds i8* %%sk, i64 3200, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_837_count);
  llvm_cbe_tmp__77 = ( char *)(&llvm_cbe_sk[(((signed long long )3200ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds %%struct.polyveck* %%t0, i64 0, i32 0, i64 4, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_838_count);
  llvm_cbe_tmp__78 = (l_struct_OC_poly *)(&llvm_cbe_t0->field0[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt0_pack(i8* %%42, %%struct.poly* %%43) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_839_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt0_pack(( char *)llvm_cbe_tmp__77, (l_struct_OC_poly *)llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds i8* %%sk, i64 3616, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_865_count);
  llvm_cbe_tmp__79 = ( char *)(&llvm_cbe_sk[(((signed long long )3616ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds %%struct.polyveck* %%t0, i64 0, i32 0, i64 5, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_866_count);
  llvm_cbe_tmp__80 = (l_struct_OC_poly *)(&llvm_cbe_t0->field0[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt0_pack(i8* %%44, %%struct.poly* %%45) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_867_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt0_pack(( char *)llvm_cbe_tmp__79, (l_struct_OC_poly *)llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_pack_sk}\n");
  return;
  do {     /* Syntactic loop '.preheader15' to make GCC happy */
llvm_cbe__2e_preheader15:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge216 = phi i32 [ %%50, %%.preheader15 ], [ 0, %%.preheader17  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_storemerge216_count);
  llvm_cbe_storemerge216 = (unsigned int )llvm_cbe_storemerge216__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge216 = 0x%X",llvm_cbe_storemerge216);
printf("\n = 0x%X",llvm_cbe_tmp__85);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = zext i32 %%storemerge216 to i64, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_894_count);
  llvm_cbe_tmp__81 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge216&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = getelementptr inbounds i8* %%tr, i64 %%46, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_895_count);
  llvm_cbe_tmp__82 = ( char *)(&llvm_cbe_tr[(((signed long long )llvm_cbe_tmp__81))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__81));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load i8* %%47, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_896_count);
  llvm_cbe_tmp__83 = (unsigned char )*llvm_cbe_tmp__82;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum8 = add i64 %%46, 64, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe__2e_sum8_count);
  llvm_cbe__2e_sum8 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__81&18446744073709551615ull)) + ((unsigned long long )(64ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum8 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum8&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds i8* %%sk, i64 %%.sum8, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_897_count);
  llvm_cbe_tmp__84 = ( char *)(&llvm_cbe_sk[(((signed long long )llvm_cbe__2e_sum8))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum8 = 0x%I64X",((signed long long )llvm_cbe__2e_sum8));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%48, i8* %%49, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_898_count);
  *llvm_cbe_tmp__84 = llvm_cbe_tmp__83;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = add i32 %%storemerge216, 1, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sk  --> \n", ++aesl_llvm_cbe_899_count);
  llvm_cbe_tmp__85 = (unsigned int )((unsigned int )(llvm_cbe_storemerge216&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__85&4294967295ull)));
  if (((llvm_cbe_tmp__85&4294967295U) == (64u&4294967295U))) {
    goto llvm_cbe__2e_preheader13;
  } else {
    llvm_cbe_storemerge216__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__85;   /* for PHI node */
    goto llvm_cbe__2e_preheader15;
  }

  } while (1); /* end of syntactic loop '.preheader15' */
}


void pqcrystals_dilithium3_ref_unpack_sk( char *llvm_cbe_rho,  char *llvm_cbe_tr,  char *llvm_cbe_key, l_struct_OC_polyveck *llvm_cbe_t0, l_struct_OC_polyvecl *llvm_cbe_s1, l_struct_OC_polyveck *llvm_cbe_s2,  char *llvm_cbe_sk) {
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
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  static  unsigned long long aesl_llvm_cbe_960_count = 0;
  static  unsigned long long aesl_llvm_cbe_961_count = 0;
  static  unsigned long long aesl_llvm_cbe_962_count = 0;
  static  unsigned long long aesl_llvm_cbe_963_count = 0;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge19_count = 0;
  unsigned int llvm_cbe_storemerge19;
  unsigned int llvm_cbe_storemerge19__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  unsigned long long llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
   char *llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
  unsigned char llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
   char *llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
  unsigned int llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond21_count = 0;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge118_count = 0;
  unsigned int llvm_cbe_storemerge118;
  unsigned int llvm_cbe_storemerge118__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1008_count = 0;
  unsigned long long llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe__2e_sum9_count = 0;
  unsigned long long llvm_cbe__2e_sum9;
  static  unsigned long long aesl_llvm_cbe_1009_count = 0;
   char *llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_1010_count = 0;
  unsigned char llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_1011_count = 0;
   char *llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_1012_count = 0;
  static  unsigned long long aesl_llvm_cbe_1013_count = 0;
  unsigned int llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_1014_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
  static  unsigned long long aesl_llvm_cbe_1029_count = 0;
  static  unsigned long long aesl_llvm_cbe_1030_count = 0;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  static  unsigned long long aesl_llvm_cbe_1034_count = 0;
  static  unsigned long long aesl_llvm_cbe_1035_count = 0;
  static  unsigned long long aesl_llvm_cbe_1036_count = 0;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond20_count = 0;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;
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
  l_struct_OC_poly *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
   char *llvm_cbe_tmp__98;
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
  static  unsigned long long aesl_llvm_cbe_1076_count = 0;
  static  unsigned long long aesl_llvm_cbe_1077_count = 0;
  static  unsigned long long aesl_llvm_cbe_1078_count = 0;
  static  unsigned long long aesl_llvm_cbe_1079_count = 0;
  static  unsigned long long aesl_llvm_cbe_1080_count = 0;
  static  unsigned long long aesl_llvm_cbe_1081_count = 0;
  static  unsigned long long aesl_llvm_cbe_1082_count = 0;
  static  unsigned long long aesl_llvm_cbe_1083_count = 0;
  static  unsigned long long aesl_llvm_cbe_1084_count = 0;
  static  unsigned long long aesl_llvm_cbe_1085_count = 0;
  static  unsigned long long aesl_llvm_cbe_1086_count = 0;
  static  unsigned long long aesl_llvm_cbe_1087_count = 0;
  static  unsigned long long aesl_llvm_cbe_1088_count = 0;
  static  unsigned long long aesl_llvm_cbe_1089_count = 0;
  static  unsigned long long aesl_llvm_cbe_1090_count = 0;
  static  unsigned long long aesl_llvm_cbe_1091_count = 0;
  static  unsigned long long aesl_llvm_cbe_1092_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_1093_count = 0;
   char *llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_1107_count = 0;
  static  unsigned long long aesl_llvm_cbe_1108_count = 0;
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
  l_struct_OC_poly *llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_1121_count = 0;
   char *llvm_cbe_tmp__102;
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
  static  unsigned long long aesl_llvm_cbe_1141_count = 0;
  static  unsigned long long aesl_llvm_cbe_1142_count = 0;
  static  unsigned long long aesl_llvm_cbe_1143_count = 0;
  static  unsigned long long aesl_llvm_cbe_1144_count = 0;
  static  unsigned long long aesl_llvm_cbe_1145_count = 0;
  static  unsigned long long aesl_llvm_cbe_1146_count = 0;
  static  unsigned long long aesl_llvm_cbe_1147_count = 0;
  static  unsigned long long aesl_llvm_cbe_1148_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_1149_count = 0;
   char *llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_1150_count = 0;
  static  unsigned long long aesl_llvm_cbe_1151_count = 0;
  static  unsigned long long aesl_llvm_cbe_1152_count = 0;
  static  unsigned long long aesl_llvm_cbe_1153_count = 0;
  static  unsigned long long aesl_llvm_cbe_1154_count = 0;
  static  unsigned long long aesl_llvm_cbe_1155_count = 0;
  static  unsigned long long aesl_llvm_cbe_1156_count = 0;
  static  unsigned long long aesl_llvm_cbe_1157_count = 0;
  static  unsigned long long aesl_llvm_cbe_1158_count = 0;
  static  unsigned long long aesl_llvm_cbe_1159_count = 0;
  static  unsigned long long aesl_llvm_cbe_1160_count = 0;
  static  unsigned long long aesl_llvm_cbe_1161_count = 0;
  static  unsigned long long aesl_llvm_cbe_1162_count = 0;
  static  unsigned long long aesl_llvm_cbe_1163_count = 0;
  static  unsigned long long aesl_llvm_cbe_1164_count = 0;
  static  unsigned long long aesl_llvm_cbe_1165_count = 0;
  static  unsigned long long aesl_llvm_cbe_1166_count = 0;
  static  unsigned long long aesl_llvm_cbe_1167_count = 0;
  static  unsigned long long aesl_llvm_cbe_1168_count = 0;
  static  unsigned long long aesl_llvm_cbe_1169_count = 0;
  static  unsigned long long aesl_llvm_cbe_1170_count = 0;
  static  unsigned long long aesl_llvm_cbe_1171_count = 0;
  static  unsigned long long aesl_llvm_cbe_1172_count = 0;
  static  unsigned long long aesl_llvm_cbe_1173_count = 0;
  static  unsigned long long aesl_llvm_cbe_1174_count = 0;
  static  unsigned long long aesl_llvm_cbe_1175_count = 0;
  static  unsigned long long aesl_llvm_cbe_1176_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_1177_count = 0;
   char *llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_1178_count = 0;
  static  unsigned long long aesl_llvm_cbe_1179_count = 0;
  static  unsigned long long aesl_llvm_cbe_1180_count = 0;
  static  unsigned long long aesl_llvm_cbe_1181_count = 0;
  static  unsigned long long aesl_llvm_cbe_1182_count = 0;
  static  unsigned long long aesl_llvm_cbe_1183_count = 0;
  static  unsigned long long aesl_llvm_cbe_1184_count = 0;
  static  unsigned long long aesl_llvm_cbe_1185_count = 0;
  static  unsigned long long aesl_llvm_cbe_1186_count = 0;
  static  unsigned long long aesl_llvm_cbe_1187_count = 0;
  static  unsigned long long aesl_llvm_cbe_1188_count = 0;
  static  unsigned long long aesl_llvm_cbe_1189_count = 0;
  static  unsigned long long aesl_llvm_cbe_1190_count = 0;
  static  unsigned long long aesl_llvm_cbe_1191_count = 0;
  static  unsigned long long aesl_llvm_cbe_1192_count = 0;
  static  unsigned long long aesl_llvm_cbe_1193_count = 0;
  static  unsigned long long aesl_llvm_cbe_1194_count = 0;
  static  unsigned long long aesl_llvm_cbe_1195_count = 0;
  static  unsigned long long aesl_llvm_cbe_1196_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_1213_count = 0;
  static  unsigned long long aesl_llvm_cbe_1214_count = 0;
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
  l_struct_OC_poly *llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_1229_count = 0;
   char *llvm_cbe_tmp__108;
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
  static  unsigned long long aesl_llvm_cbe_1245_count = 0;
  static  unsigned long long aesl_llvm_cbe_1246_count = 0;
  static  unsigned long long aesl_llvm_cbe_1247_count = 0;
  static  unsigned long long aesl_llvm_cbe_1248_count = 0;
  static  unsigned long long aesl_llvm_cbe_1249_count = 0;
  static  unsigned long long aesl_llvm_cbe_1250_count = 0;
  static  unsigned long long aesl_llvm_cbe_1251_count = 0;
  static  unsigned long long aesl_llvm_cbe_1252_count = 0;
  static  unsigned long long aesl_llvm_cbe_1253_count = 0;
  static  unsigned long long aesl_llvm_cbe_1254_count = 0;
  static  unsigned long long aesl_llvm_cbe_1255_count = 0;
  static  unsigned long long aesl_llvm_cbe_1256_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_1257_count = 0;
   char *llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_1258_count = 0;
  static  unsigned long long aesl_llvm_cbe_1259_count = 0;
  static  unsigned long long aesl_llvm_cbe_1260_count = 0;
  static  unsigned long long aesl_llvm_cbe_1261_count = 0;
  static  unsigned long long aesl_llvm_cbe_1262_count = 0;
  static  unsigned long long aesl_llvm_cbe_1263_count = 0;
  static  unsigned long long aesl_llvm_cbe_1264_count = 0;
  static  unsigned long long aesl_llvm_cbe_1265_count = 0;
  static  unsigned long long aesl_llvm_cbe_1266_count = 0;
  static  unsigned long long aesl_llvm_cbe_1267_count = 0;
  static  unsigned long long aesl_llvm_cbe_1268_count = 0;
  static  unsigned long long aesl_llvm_cbe_1269_count = 0;
  static  unsigned long long aesl_llvm_cbe_1270_count = 0;
  static  unsigned long long aesl_llvm_cbe_1271_count = 0;
  static  unsigned long long aesl_llvm_cbe_1272_count = 0;
  static  unsigned long long aesl_llvm_cbe_1273_count = 0;
  static  unsigned long long aesl_llvm_cbe_1274_count = 0;
  static  unsigned long long aesl_llvm_cbe_1275_count = 0;
  static  unsigned long long aesl_llvm_cbe_1276_count = 0;
  static  unsigned long long aesl_llvm_cbe_1277_count = 0;
  static  unsigned long long aesl_llvm_cbe_1278_count = 0;
  static  unsigned long long aesl_llvm_cbe_1279_count = 0;
  static  unsigned long long aesl_llvm_cbe_1280_count = 0;
  static  unsigned long long aesl_llvm_cbe_1281_count = 0;
  static  unsigned long long aesl_llvm_cbe_1282_count = 0;
  static  unsigned long long aesl_llvm_cbe_1283_count = 0;
  static  unsigned long long aesl_llvm_cbe_1284_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_1285_count = 0;
   char *llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_1286_count = 0;
  static  unsigned long long aesl_llvm_cbe_1287_count = 0;
  static  unsigned long long aesl_llvm_cbe_1288_count = 0;
  static  unsigned long long aesl_llvm_cbe_1289_count = 0;
  static  unsigned long long aesl_llvm_cbe_1290_count = 0;
  static  unsigned long long aesl_llvm_cbe_1291_count = 0;
  static  unsigned long long aesl_llvm_cbe_1292_count = 0;
  static  unsigned long long aesl_llvm_cbe_1293_count = 0;
  static  unsigned long long aesl_llvm_cbe_1294_count = 0;
  static  unsigned long long aesl_llvm_cbe_1295_count = 0;
  static  unsigned long long aesl_llvm_cbe_1296_count = 0;
  static  unsigned long long aesl_llvm_cbe_1297_count = 0;
  static  unsigned long long aesl_llvm_cbe_1298_count = 0;
  static  unsigned long long aesl_llvm_cbe_1299_count = 0;
  static  unsigned long long aesl_llvm_cbe_1300_count = 0;
  static  unsigned long long aesl_llvm_cbe_1301_count = 0;
  static  unsigned long long aesl_llvm_cbe_1302_count = 0;
  static  unsigned long long aesl_llvm_cbe_1303_count = 0;
  static  unsigned long long aesl_llvm_cbe_1304_count = 0;
  static  unsigned long long aesl_llvm_cbe_1305_count = 0;
  static  unsigned long long aesl_llvm_cbe_1306_count = 0;
  static  unsigned long long aesl_llvm_cbe_1307_count = 0;
  static  unsigned long long aesl_llvm_cbe_1308_count = 0;
  static  unsigned long long aesl_llvm_cbe_1309_count = 0;
  static  unsigned long long aesl_llvm_cbe_1310_count = 0;
  static  unsigned long long aesl_llvm_cbe_1311_count = 0;
  static  unsigned long long aesl_llvm_cbe_1312_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_1313_count = 0;
   char *llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_1314_count = 0;
  static  unsigned long long aesl_llvm_cbe_1315_count = 0;
  static  unsigned long long aesl_llvm_cbe_1316_count = 0;
  static  unsigned long long aesl_llvm_cbe_1317_count = 0;
  static  unsigned long long aesl_llvm_cbe_1318_count = 0;
  static  unsigned long long aesl_llvm_cbe_1319_count = 0;
  static  unsigned long long aesl_llvm_cbe_1320_count = 0;
  static  unsigned long long aesl_llvm_cbe_1321_count = 0;
  static  unsigned long long aesl_llvm_cbe_1322_count = 0;
  static  unsigned long long aesl_llvm_cbe_1323_count = 0;
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
  l_struct_OC_poly *llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_1341_count = 0;
   char *llvm_cbe_tmp__116;
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
  l_struct_OC_poly *llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_1369_count = 0;
   char *llvm_cbe_tmp__118;
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
  static  unsigned long long aesl_llvm_cbe_1387_count = 0;
  static  unsigned long long aesl_llvm_cbe_1388_count = 0;
  static  unsigned long long aesl_llvm_cbe_1389_count = 0;
  static  unsigned long long aesl_llvm_cbe_1390_count = 0;
  static  unsigned long long aesl_llvm_cbe_1391_count = 0;
  static  unsigned long long aesl_llvm_cbe_1392_count = 0;
  static  unsigned long long aesl_llvm_cbe_1393_count = 0;
  static  unsigned long long aesl_llvm_cbe_1394_count = 0;
  static  unsigned long long aesl_llvm_cbe_1395_count = 0;
  static  unsigned long long aesl_llvm_cbe_1396_count = 0;
  static  unsigned long long aesl_llvm_cbe_1397_count = 0;
  static  unsigned long long aesl_llvm_cbe_1398_count = 0;
  static  unsigned long long aesl_llvm_cbe_1399_count = 0;
  static  unsigned long long aesl_llvm_cbe_1400_count = 0;
  static  unsigned long long aesl_llvm_cbe_1401_count = 0;
  static  unsigned long long aesl_llvm_cbe_1402_count = 0;
  static  unsigned long long aesl_llvm_cbe_1403_count = 0;
  static  unsigned long long aesl_llvm_cbe_1404_count = 0;
  static  unsigned long long aesl_llvm_cbe_1405_count = 0;
  static  unsigned long long aesl_llvm_cbe_1406_count = 0;
  static  unsigned long long aesl_llvm_cbe_1407_count = 0;
  static  unsigned long long aesl_llvm_cbe_1408_count = 0;
  static  unsigned long long aesl_llvm_cbe_1409_count = 0;
  static  unsigned long long aesl_llvm_cbe_1410_count = 0;
  static  unsigned long long aesl_llvm_cbe_1411_count = 0;
  static  unsigned long long aesl_llvm_cbe_1412_count = 0;
  static  unsigned long long aesl_llvm_cbe_1413_count = 0;
  static  unsigned long long aesl_llvm_cbe_1414_count = 0;
  static  unsigned long long aesl_llvm_cbe_1415_count = 0;
  static  unsigned long long aesl_llvm_cbe_1416_count = 0;
  static  unsigned long long aesl_llvm_cbe_1417_count = 0;
  static  unsigned long long aesl_llvm_cbe_1418_count = 0;
  static  unsigned long long aesl_llvm_cbe_1419_count = 0;
  static  unsigned long long aesl_llvm_cbe_1420_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_1421_count = 0;
   char *llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_1422_count = 0;
  static  unsigned long long aesl_llvm_cbe_1423_count = 0;
  static  unsigned long long aesl_llvm_cbe_1424_count = 0;
  static  unsigned long long aesl_llvm_cbe_1425_count = 0;
  static  unsigned long long aesl_llvm_cbe_1426_count = 0;
  static  unsigned long long aesl_llvm_cbe_1427_count = 0;
  static  unsigned long long aesl_llvm_cbe_1428_count = 0;
  static  unsigned long long aesl_llvm_cbe_1429_count = 0;
  static  unsigned long long aesl_llvm_cbe_1430_count = 0;
  static  unsigned long long aesl_llvm_cbe_1431_count = 0;
  static  unsigned long long aesl_llvm_cbe_1432_count = 0;
  static  unsigned long long aesl_llvm_cbe_1433_count = 0;
  static  unsigned long long aesl_llvm_cbe_1434_count = 0;
  static  unsigned long long aesl_llvm_cbe_1435_count = 0;
  static  unsigned long long aesl_llvm_cbe_1436_count = 0;
  static  unsigned long long aesl_llvm_cbe_1437_count = 0;
  static  unsigned long long aesl_llvm_cbe_1438_count = 0;
  static  unsigned long long aesl_llvm_cbe_1439_count = 0;
  static  unsigned long long aesl_llvm_cbe_1440_count = 0;
  static  unsigned long long aesl_llvm_cbe_1441_count = 0;
  static  unsigned long long aesl_llvm_cbe_1442_count = 0;
  static  unsigned long long aesl_llvm_cbe_1443_count = 0;
  static  unsigned long long aesl_llvm_cbe_1444_count = 0;
  static  unsigned long long aesl_llvm_cbe_1445_count = 0;
  static  unsigned long long aesl_llvm_cbe_1446_count = 0;
  static  unsigned long long aesl_llvm_cbe_1447_count = 0;
  static  unsigned long long aesl_llvm_cbe_1448_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_1449_count = 0;
   char *llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_1450_count = 0;
  static  unsigned long long aesl_llvm_cbe_1451_count = 0;
  static  unsigned long long aesl_llvm_cbe_1452_count = 0;
  static  unsigned long long aesl_llvm_cbe_1453_count = 0;
  static  unsigned long long aesl_llvm_cbe_1454_count = 0;
  static  unsigned long long aesl_llvm_cbe_1455_count = 0;
  static  unsigned long long aesl_llvm_cbe_1456_count = 0;
  static  unsigned long long aesl_llvm_cbe_1457_count = 0;
  static  unsigned long long aesl_llvm_cbe_1458_count = 0;
  static  unsigned long long aesl_llvm_cbe_1459_count = 0;
  static  unsigned long long aesl_llvm_cbe_1460_count = 0;
  static  unsigned long long aesl_llvm_cbe_1461_count = 0;
  static  unsigned long long aesl_llvm_cbe_1462_count = 0;
  static  unsigned long long aesl_llvm_cbe_1463_count = 0;
  static  unsigned long long aesl_llvm_cbe_1464_count = 0;
  static  unsigned long long aesl_llvm_cbe_1465_count = 0;
  static  unsigned long long aesl_llvm_cbe_1466_count = 0;
  static  unsigned long long aesl_llvm_cbe_1467_count = 0;
  static  unsigned long long aesl_llvm_cbe_1468_count = 0;
  static  unsigned long long aesl_llvm_cbe_1469_count = 0;
  static  unsigned long long aesl_llvm_cbe_1470_count = 0;
  static  unsigned long long aesl_llvm_cbe_1471_count = 0;
  static  unsigned long long aesl_llvm_cbe_1472_count = 0;
  static  unsigned long long aesl_llvm_cbe_1473_count = 0;
  static  unsigned long long aesl_llvm_cbe_1474_count = 0;
  static  unsigned long long aesl_llvm_cbe_1475_count = 0;
  static  unsigned long long aesl_llvm_cbe_1476_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_1477_count = 0;
   char *llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_1478_count = 0;
  static  unsigned long long aesl_llvm_cbe_1479_count = 0;
  static  unsigned long long aesl_llvm_cbe_1480_count = 0;
  static  unsigned long long aesl_llvm_cbe_1481_count = 0;
  static  unsigned long long aesl_llvm_cbe_1482_count = 0;
  static  unsigned long long aesl_llvm_cbe_1483_count = 0;
  static  unsigned long long aesl_llvm_cbe_1484_count = 0;
  static  unsigned long long aesl_llvm_cbe_1485_count = 0;
  static  unsigned long long aesl_llvm_cbe_1486_count = 0;
  static  unsigned long long aesl_llvm_cbe_1487_count = 0;
  static  unsigned long long aesl_llvm_cbe_1488_count = 0;
  static  unsigned long long aesl_llvm_cbe_1489_count = 0;
  static  unsigned long long aesl_llvm_cbe_1490_count = 0;
  static  unsigned long long aesl_llvm_cbe_1491_count = 0;
  static  unsigned long long aesl_llvm_cbe_1492_count = 0;
  static  unsigned long long aesl_llvm_cbe_1493_count = 0;
  static  unsigned long long aesl_llvm_cbe_1494_count = 0;
  static  unsigned long long aesl_llvm_cbe_1495_count = 0;
  static  unsigned long long aesl_llvm_cbe_1496_count = 0;
  static  unsigned long long aesl_llvm_cbe_1497_count = 0;
  static  unsigned long long aesl_llvm_cbe_1498_count = 0;
  static  unsigned long long aesl_llvm_cbe_1499_count = 0;
  static  unsigned long long aesl_llvm_cbe_1500_count = 0;
  static  unsigned long long aesl_llvm_cbe_1501_count = 0;
  static  unsigned long long aesl_llvm_cbe_1502_count = 0;
  static  unsigned long long aesl_llvm_cbe_1503_count = 0;
  static  unsigned long long aesl_llvm_cbe_1504_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_1505_count = 0;
   char *llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_1506_count = 0;
  static  unsigned long long aesl_llvm_cbe_1507_count = 0;
  static  unsigned long long aesl_llvm_cbe_1508_count = 0;
  static  unsigned long long aesl_llvm_cbe_1509_count = 0;
  static  unsigned long long aesl_llvm_cbe_1510_count = 0;
  static  unsigned long long aesl_llvm_cbe_1511_count = 0;
  static  unsigned long long aesl_llvm_cbe_1512_count = 0;
  static  unsigned long long aesl_llvm_cbe_1513_count = 0;
  static  unsigned long long aesl_llvm_cbe_1514_count = 0;
  static  unsigned long long aesl_llvm_cbe_1515_count = 0;
  static  unsigned long long aesl_llvm_cbe_1516_count = 0;
  static  unsigned long long aesl_llvm_cbe_1517_count = 0;
  static  unsigned long long aesl_llvm_cbe_1518_count = 0;
  static  unsigned long long aesl_llvm_cbe_1519_count = 0;
  static  unsigned long long aesl_llvm_cbe_1520_count = 0;
  static  unsigned long long aesl_llvm_cbe_1521_count = 0;
  static  unsigned long long aesl_llvm_cbe_1522_count = 0;
  static  unsigned long long aesl_llvm_cbe_1523_count = 0;
  static  unsigned long long aesl_llvm_cbe_1524_count = 0;
  static  unsigned long long aesl_llvm_cbe_1525_count = 0;
  static  unsigned long long aesl_llvm_cbe_1526_count = 0;
  static  unsigned long long aesl_llvm_cbe_1527_count = 0;
  static  unsigned long long aesl_llvm_cbe_1528_count = 0;
  static  unsigned long long aesl_llvm_cbe_1529_count = 0;
  static  unsigned long long aesl_llvm_cbe_1530_count = 0;
  static  unsigned long long aesl_llvm_cbe_1531_count = 0;
  static  unsigned long long aesl_llvm_cbe_1532_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_1533_count = 0;
   char *llvm_cbe_tmp__128;
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
  static  unsigned long long aesl_llvm_cbe_1557_count = 0;
  static  unsigned long long aesl_llvm_cbe_1558_count = 0;
  static  unsigned long long aesl_llvm_cbe_1559_count = 0;
  static  unsigned long long aesl_llvm_cbe_1560_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_1561_count = 0;
   char *llvm_cbe_tmp__130;
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
  static  unsigned long long aesl_llvm_cbe_storemerge216_count = 0;
  unsigned int llvm_cbe_storemerge216;
  unsigned int llvm_cbe_storemerge216__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1589_count = 0;
  unsigned long long llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe__2e_sum8_count = 0;
  unsigned long long llvm_cbe__2e_sum8;
  static  unsigned long long aesl_llvm_cbe_1590_count = 0;
   char *llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_1591_count = 0;
  unsigned char llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_1592_count = 0;
   char *llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_1593_count = 0;
  static  unsigned long long aesl_llvm_cbe_1594_count = 0;
  unsigned int llvm_cbe_tmp__135;
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
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1620_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_unpack_sk\n");
  llvm_cbe_storemerge19__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__136;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__136:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge19 = phi i32 [ 0, %%0 ], [ %%6, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_storemerge19_count);
  llvm_cbe_storemerge19 = (unsigned int )llvm_cbe_storemerge19__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge19 = 0x%X",llvm_cbe_storemerge19);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__91);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%storemerge19 to i64, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_976_count);
  llvm_cbe_tmp__87 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge19&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i8* %%sk, i64 %%2, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_977_count);
  llvm_cbe_tmp__88 = ( char *)(&llvm_cbe_sk[(((signed long long )llvm_cbe_tmp__87))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__87));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8* %%3, align 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_978_count);
  llvm_cbe_tmp__89 = (unsigned char )*llvm_cbe_tmp__88;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds i8* %%rho, i64 %%2, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_979_count);
  llvm_cbe_tmp__90 = ( char *)(&llvm_cbe_rho[(((signed long long )llvm_cbe_tmp__87))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__87));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%4, i8* %%5, align 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_980_count);
  *llvm_cbe_tmp__90 = llvm_cbe_tmp__89;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i32 %%storemerge19, 1, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_981_count);
  llvm_cbe_tmp__91 = (unsigned int )((unsigned int )(llvm_cbe_storemerge19&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__91&4294967295ull)));
  if (((llvm_cbe_tmp__91&4294967295U) == (32u&4294967295U))) {
    llvm_cbe_storemerge118__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader17;
  } else {
    llvm_cbe_storemerge19__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__91;   /* for PHI node */
    goto llvm_cbe_tmp__136;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader17' to make GCC happy */
llvm_cbe__2e_preheader17:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge118 = phi i32 [ %%11, %%.preheader17 ], [ 0, %%1  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_storemerge118_count);
  llvm_cbe_storemerge118 = (unsigned int )llvm_cbe_storemerge118__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge118 = 0x%X",llvm_cbe_storemerge118);
printf("\n = 0x%X",llvm_cbe_tmp__96);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = zext i32 %%storemerge118 to i64, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1008_count);
  llvm_cbe_tmp__92 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge118&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__92);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum9 = add i64 %%7, 32, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe__2e_sum9_count);
  llvm_cbe__2e_sum9 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__92&18446744073709551615ull)) + ((unsigned long long )(32ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum9 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum9&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i8* %%sk, i64 %%.sum9, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1009_count);
  llvm_cbe_tmp__93 = ( char *)(&llvm_cbe_sk[(((signed long long )llvm_cbe__2e_sum9))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum9 = 0x%I64X",((signed long long )llvm_cbe__2e_sum9));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i8* %%8, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1010_count);
  llvm_cbe_tmp__94 = (unsigned char )*llvm_cbe_tmp__93;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i8* %%key, i64 %%7, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1011_count);
  llvm_cbe_tmp__95 = ( char *)(&llvm_cbe_key[(((signed long long )llvm_cbe_tmp__92))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__92));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%9, i8* %%10, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1012_count);
  *llvm_cbe_tmp__95 = llvm_cbe_tmp__94;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i32 %%storemerge118, 1, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1013_count);
  llvm_cbe_tmp__96 = (unsigned int )((unsigned int )(llvm_cbe_storemerge118&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__96&4294967295ull)));
  if (((llvm_cbe_tmp__96&4294967295U) == (32u&4294967295U))) {
    llvm_cbe_storemerge216__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader15;
  } else {
    llvm_cbe_storemerge118__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__96;   /* for PHI node */
    goto llvm_cbe__2e_preheader17;
  }

  } while (1); /* end of syntactic loop '.preheader17' */
llvm_cbe__2e_preheader13:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 0, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1064_count);
  llvm_cbe_tmp__97 = (l_struct_OC_poly *)(&llvm_cbe_s1->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds i8* %%sk, i64 128, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1065_count);
  llvm_cbe_tmp__98 = ( char *)(&llvm_cbe_sk[(((signed long long )128ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_unpack(%%struct.poly* %%12, i8* %%13) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1066_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_unpack((l_struct_OC_poly *)llvm_cbe_tmp__97, ( char *)llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 1, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1092_count);
  llvm_cbe_tmp__99 = (l_struct_OC_poly *)(&llvm_cbe_s1->field0[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds i8* %%sk, i64 256, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1093_count);
  llvm_cbe_tmp__100 = ( char *)(&llvm_cbe_sk[(((signed long long )256ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_unpack(%%struct.poly* %%14, i8* %%15) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1094_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_unpack((l_struct_OC_poly *)llvm_cbe_tmp__99, ( char *)llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 2, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1120_count);
  llvm_cbe_tmp__101 = (l_struct_OC_poly *)(&llvm_cbe_s1->field0[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds i8* %%sk, i64 384, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1121_count);
  llvm_cbe_tmp__102 = ( char *)(&llvm_cbe_sk[(((signed long long )384ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_unpack(%%struct.poly* %%16, i8* %%17) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1122_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_unpack((l_struct_OC_poly *)llvm_cbe_tmp__101, ( char *)llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 3, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1148_count);
  llvm_cbe_tmp__103 = (l_struct_OC_poly *)(&llvm_cbe_s1->field0[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds i8* %%sk, i64 512, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1149_count);
  llvm_cbe_tmp__104 = ( char *)(&llvm_cbe_sk[(((signed long long )512ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_unpack(%%struct.poly* %%18, i8* %%19) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1150_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_unpack((l_struct_OC_poly *)llvm_cbe_tmp__103, ( char *)llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds %%struct.polyvecl* %%s1, i64 0, i32 0, i64 4, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1176_count);
  llvm_cbe_tmp__105 = (l_struct_OC_poly *)(&llvm_cbe_s1->field0[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds i8* %%sk, i64 640, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1177_count);
  llvm_cbe_tmp__106 = ( char *)(&llvm_cbe_sk[(((signed long long )640ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_unpack(%%struct.poly* %%20, i8* %%21) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1178_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_unpack((l_struct_OC_poly *)llvm_cbe_tmp__105, ( char *)llvm_cbe_tmp__106);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.polyveck* %%s2, i64 0, i32 0, i64 0, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1228_count);
  llvm_cbe_tmp__107 = (l_struct_OC_poly *)(&llvm_cbe_s2->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds i8* %%sk, i64 768, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1229_count);
  llvm_cbe_tmp__108 = ( char *)(&llvm_cbe_sk[(((signed long long )768ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_unpack(%%struct.poly* %%22, i8* %%23) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1230_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_unpack((l_struct_OC_poly *)llvm_cbe_tmp__107, ( char *)llvm_cbe_tmp__108);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.polyveck* %%s2, i64 0, i32 0, i64 1, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1256_count);
  llvm_cbe_tmp__109 = (l_struct_OC_poly *)(&llvm_cbe_s2->field0[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds i8* %%sk, i64 896, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1257_count);
  llvm_cbe_tmp__110 = ( char *)(&llvm_cbe_sk[(((signed long long )896ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_unpack(%%struct.poly* %%24, i8* %%25) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1258_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_unpack((l_struct_OC_poly *)llvm_cbe_tmp__109, ( char *)llvm_cbe_tmp__110);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.polyveck* %%s2, i64 0, i32 0, i64 2, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1284_count);
  llvm_cbe_tmp__111 = (l_struct_OC_poly *)(&llvm_cbe_s2->field0[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds i8* %%sk, i64 1024, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1285_count);
  llvm_cbe_tmp__112 = ( char *)(&llvm_cbe_sk[(((signed long long )1024ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_unpack(%%struct.poly* %%26, i8* %%27) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1286_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_unpack((l_struct_OC_poly *)llvm_cbe_tmp__111, ( char *)llvm_cbe_tmp__112);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds %%struct.polyveck* %%s2, i64 0, i32 0, i64 3, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1312_count);
  llvm_cbe_tmp__113 = (l_struct_OC_poly *)(&llvm_cbe_s2->field0[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds i8* %%sk, i64 1152, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1313_count);
  llvm_cbe_tmp__114 = ( char *)(&llvm_cbe_sk[(((signed long long )1152ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_unpack(%%struct.poly* %%28, i8* %%29) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1314_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_unpack((l_struct_OC_poly *)llvm_cbe_tmp__113, ( char *)llvm_cbe_tmp__114);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct.polyveck* %%s2, i64 0, i32 0, i64 4, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1340_count);
  llvm_cbe_tmp__115 = (l_struct_OC_poly *)(&llvm_cbe_s2->field0[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds i8* %%sk, i64 1280, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1341_count);
  llvm_cbe_tmp__116 = ( char *)(&llvm_cbe_sk[(((signed long long )1280ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_unpack(%%struct.poly* %%30, i8* %%31) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1342_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_unpack((l_struct_OC_poly *)llvm_cbe_tmp__115, ( char *)llvm_cbe_tmp__116);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds %%struct.polyveck* %%s2, i64 0, i32 0, i64 5, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1368_count);
  llvm_cbe_tmp__117 = (l_struct_OC_poly *)(&llvm_cbe_s2->field0[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds i8* %%sk, i64 1408, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1369_count);
  llvm_cbe_tmp__118 = ( char *)(&llvm_cbe_sk[(((signed long long )1408ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyeta_unpack(%%struct.poly* %%32, i8* %%33) nounwind, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1370_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyeta_unpack((l_struct_OC_poly *)llvm_cbe_tmp__117, ( char *)llvm_cbe_tmp__118);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds %%struct.polyveck* %%t0, i64 0, i32 0, i64 0, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1420_count);
  llvm_cbe_tmp__119 = (l_struct_OC_poly *)(&llvm_cbe_t0->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds i8* %%sk, i64 1536, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1421_count);
  llvm_cbe_tmp__120 = ( char *)(&llvm_cbe_sk[(((signed long long )1536ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt0_unpack(%%struct.poly* %%34, i8* %%35) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1422_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt0_unpack((l_struct_OC_poly *)llvm_cbe_tmp__119, ( char *)llvm_cbe_tmp__120);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds %%struct.polyveck* %%t0, i64 0, i32 0, i64 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1448_count);
  llvm_cbe_tmp__121 = (l_struct_OC_poly *)(&llvm_cbe_t0->field0[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds i8* %%sk, i64 1952, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1449_count);
  llvm_cbe_tmp__122 = ( char *)(&llvm_cbe_sk[(((signed long long )1952ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt0_unpack(%%struct.poly* %%36, i8* %%37) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1450_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt0_unpack((l_struct_OC_poly *)llvm_cbe_tmp__121, ( char *)llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds %%struct.polyveck* %%t0, i64 0, i32 0, i64 2, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1476_count);
  llvm_cbe_tmp__123 = (l_struct_OC_poly *)(&llvm_cbe_t0->field0[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds i8* %%sk, i64 2368, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1477_count);
  llvm_cbe_tmp__124 = ( char *)(&llvm_cbe_sk[(((signed long long )2368ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt0_unpack(%%struct.poly* %%38, i8* %%39) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1478_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt0_unpack((l_struct_OC_poly *)llvm_cbe_tmp__123, ( char *)llvm_cbe_tmp__124);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds %%struct.polyveck* %%t0, i64 0, i32 0, i64 3, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1504_count);
  llvm_cbe_tmp__125 = (l_struct_OC_poly *)(&llvm_cbe_t0->field0[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr inbounds i8* %%sk, i64 2784, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1505_count);
  llvm_cbe_tmp__126 = ( char *)(&llvm_cbe_sk[(((signed long long )2784ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt0_unpack(%%struct.poly* %%40, i8* %%41) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1506_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt0_unpack((l_struct_OC_poly *)llvm_cbe_tmp__125, ( char *)llvm_cbe_tmp__126);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds %%struct.polyveck* %%t0, i64 0, i32 0, i64 4, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1532_count);
  llvm_cbe_tmp__127 = (l_struct_OC_poly *)(&llvm_cbe_t0->field0[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds i8* %%sk, i64 3200, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1533_count);
  llvm_cbe_tmp__128 = ( char *)(&llvm_cbe_sk[(((signed long long )3200ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt0_unpack(%%struct.poly* %%42, i8* %%43) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1534_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt0_unpack((l_struct_OC_poly *)llvm_cbe_tmp__127, ( char *)llvm_cbe_tmp__128);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds %%struct.polyveck* %%t0, i64 0, i32 0, i64 5, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1560_count);
  llvm_cbe_tmp__129 = (l_struct_OC_poly *)(&llvm_cbe_t0->field0[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds i8* %%sk, i64 3616, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1561_count);
  llvm_cbe_tmp__130 = ( char *)(&llvm_cbe_sk[(((signed long long )3616ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyt0_unpack(%%struct.poly* %%44, i8* %%45) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1562_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyt0_unpack((l_struct_OC_poly *)llvm_cbe_tmp__129, ( char *)llvm_cbe_tmp__130);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_unpack_sk}\n");
  return;
  do {     /* Syntactic loop '.preheader15' to make GCC happy */
llvm_cbe__2e_preheader15:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge216 = phi i32 [ %%50, %%.preheader15 ], [ 0, %%.preheader17  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_storemerge216_count);
  llvm_cbe_storemerge216 = (unsigned int )llvm_cbe_storemerge216__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge216 = 0x%X",llvm_cbe_storemerge216);
printf("\n = 0x%X",llvm_cbe_tmp__135);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = zext i32 %%storemerge216 to i64, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1589_count);
  llvm_cbe_tmp__131 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge216&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__131);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum8 = add i64 %%46, 64, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe__2e_sum8_count);
  llvm_cbe__2e_sum8 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__131&18446744073709551615ull)) + ((unsigned long long )(64ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum8 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum8&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = getelementptr inbounds i8* %%sk, i64 %%.sum8, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1590_count);
  llvm_cbe_tmp__132 = ( char *)(&llvm_cbe_sk[(((signed long long )llvm_cbe__2e_sum8))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum8 = 0x%I64X",((signed long long )llvm_cbe__2e_sum8));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load i8* %%47, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1591_count);
  llvm_cbe_tmp__133 = (unsigned char )*llvm_cbe_tmp__132;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__133);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds i8* %%tr, i64 %%46, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1592_count);
  llvm_cbe_tmp__134 = ( char *)(&llvm_cbe_tr[(((signed long long )llvm_cbe_tmp__131))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__131));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%48, i8* %%49, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1593_count);
  *llvm_cbe_tmp__134 = llvm_cbe_tmp__133;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__133);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = add i32 %%storemerge216, 1, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sk  --> \n", ++aesl_llvm_cbe_1594_count);
  llvm_cbe_tmp__135 = (unsigned int )((unsigned int )(llvm_cbe_storemerge216&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__135&4294967295ull)));
  if (((llvm_cbe_tmp__135&4294967295U) == (64u&4294967295U))) {
    goto llvm_cbe__2e_preheader13;
  } else {
    llvm_cbe_storemerge216__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__135;   /* for PHI node */
    goto llvm_cbe__2e_preheader15;
  }

  } while (1); /* end of syntactic loop '.preheader15' */
}


void pqcrystals_dilithium3_ref_pack_sig( char *llvm_cbe_sig,  char *llvm_cbe_c, l_struct_OC_polyvecl *llvm_cbe_z, l_struct_OC_polyveck *llvm_cbe_h) {
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
   char *llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_1668_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__138;
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
   char *llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_1687_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_1688_count = 0;
  static  unsigned long long aesl_llvm_cbe_1689_count = 0;
  static  unsigned long long aesl_llvm_cbe_1690_count = 0;
  static  unsigned long long aesl_llvm_cbe_1691_count = 0;
  static  unsigned long long aesl_llvm_cbe_1692_count = 0;
  static  unsigned long long aesl_llvm_cbe_1693_count = 0;
  static  unsigned long long aesl_llvm_cbe_1694_count = 0;
  static  unsigned long long aesl_llvm_cbe_1695_count = 0;
  static  unsigned long long aesl_llvm_cbe_1696_count = 0;
  static  unsigned long long aesl_llvm_cbe_1697_count = 0;
  static  unsigned long long aesl_llvm_cbe_1698_count = 0;
  static  unsigned long long aesl_llvm_cbe_1699_count = 0;
  static  unsigned long long aesl_llvm_cbe_1700_count = 0;
  static  unsigned long long aesl_llvm_cbe_1701_count = 0;
  static  unsigned long long aesl_llvm_cbe_1702_count = 0;
  static  unsigned long long aesl_llvm_cbe_1703_count = 0;
  static  unsigned long long aesl_llvm_cbe_1704_count = 0;
  static  unsigned long long aesl_llvm_cbe_1705_count = 0;
   char *llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_1706_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_1707_count = 0;
  static  unsigned long long aesl_llvm_cbe_1708_count = 0;
  static  unsigned long long aesl_llvm_cbe_1709_count = 0;
  static  unsigned long long aesl_llvm_cbe_1710_count = 0;
  static  unsigned long long aesl_llvm_cbe_1711_count = 0;
  static  unsigned long long aesl_llvm_cbe_1712_count = 0;
  static  unsigned long long aesl_llvm_cbe_1713_count = 0;
  static  unsigned long long aesl_llvm_cbe_1714_count = 0;
  static  unsigned long long aesl_llvm_cbe_1715_count = 0;
  static  unsigned long long aesl_llvm_cbe_1716_count = 0;
  static  unsigned long long aesl_llvm_cbe_1717_count = 0;
  static  unsigned long long aesl_llvm_cbe_1718_count = 0;
  static  unsigned long long aesl_llvm_cbe_1719_count = 0;
  static  unsigned long long aesl_llvm_cbe_1720_count = 0;
  static  unsigned long long aesl_llvm_cbe_1721_count = 0;
  static  unsigned long long aesl_llvm_cbe_1722_count = 0;
  static  unsigned long long aesl_llvm_cbe_1723_count = 0;
  static  unsigned long long aesl_llvm_cbe_1724_count = 0;
   char *llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_1725_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_1726_count = 0;
  static  unsigned long long aesl_llvm_cbe_1727_count = 0;
  static  unsigned long long aesl_llvm_cbe_1728_count = 0;
  static  unsigned long long aesl_llvm_cbe_1729_count = 0;
  static  unsigned long long aesl_llvm_cbe_1730_count = 0;
  static  unsigned long long aesl_llvm_cbe_1731_count = 0;
  static  unsigned long long aesl_llvm_cbe_1732_count = 0;
  static  unsigned long long aesl_llvm_cbe_1733_count = 0;
  static  unsigned long long aesl_llvm_cbe_1734_count = 0;
  static  unsigned long long aesl_llvm_cbe_1735_count = 0;
  static  unsigned long long aesl_llvm_cbe_1736_count = 0;
  static  unsigned long long aesl_llvm_cbe_1737_count = 0;
  static  unsigned long long aesl_llvm_cbe_1738_count = 0;
  static  unsigned long long aesl_llvm_cbe_1739_count = 0;
  static  unsigned long long aesl_llvm_cbe_1740_count = 0;
  static  unsigned long long aesl_llvm_cbe_1741_count = 0;
  static  unsigned long long aesl_llvm_cbe_1742_count = 0;
  static  unsigned long long aesl_llvm_cbe_1743_count = 0;
   char *llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_1744_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_1745_count = 0;
  static  unsigned long long aesl_llvm_cbe_1746_count = 0;
  static  unsigned long long aesl_llvm_cbe_1747_count = 0;
  static  unsigned long long aesl_llvm_cbe_1748_count = 0;
  static  unsigned long long aesl_llvm_cbe_1749_count = 0;
  static  unsigned long long aesl_llvm_cbe_1750_count = 0;
  static  unsigned long long aesl_llvm_cbe_1751_count = 0;
  static  unsigned long long aesl_llvm_cbe_1752_count = 0;
  static  unsigned long long aesl_llvm_cbe_1753_count = 0;
  static  unsigned long long aesl_llvm_cbe_1754_count = 0;
  static  unsigned long long aesl_llvm_cbe_1755_count = 0;
  static  unsigned long long aesl_llvm_cbe_1756_count = 0;
  static  unsigned long long aesl_llvm_cbe_1757_count = 0;
  static  unsigned long long aesl_llvm_cbe_1758_count = 0;
  static  unsigned long long aesl_llvm_cbe_1759_count = 0;
  static  unsigned long long aesl_llvm_cbe_1760_count = 0;
  static  unsigned long long aesl_llvm_cbe_1761_count = 0;
  static  unsigned long long aesl_llvm_cbe_1762_count = 0;
  static  unsigned long long aesl_llvm_cbe_1763_count = 0;
  static  unsigned long long aesl_llvm_cbe_1764_count = 0;
  static  unsigned long long aesl_llvm_cbe_1765_count = 0;
  static  unsigned long long aesl_llvm_cbe_1766_count = 0;
  static  unsigned long long aesl_llvm_cbe_1767_count = 0;
  static  unsigned long long aesl_llvm_cbe_1768_count = 0;
  static  unsigned long long aesl_llvm_cbe_1769_count = 0;
  static  unsigned long long aesl_llvm_cbe_1770_count = 0;
  static  unsigned long long aesl_llvm_cbe_1771_count = 0;
  static  unsigned long long aesl_llvm_cbe_1772_count = 0;
  static  unsigned long long aesl_llvm_cbe_1773_count = 0;
  static  unsigned long long aesl_llvm_cbe_1774_count = 0;
  static  unsigned long long aesl_llvm_cbe_1775_count = 0;
  static  unsigned long long aesl_llvm_cbe_1776_count = 0;
  static  unsigned long long aesl_llvm_cbe_scevgep_count = 0;
   char *llvm_cbe_scevgep;
  static  unsigned long long aesl_llvm_cbe_1777_count = 0;
   char *llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_1778_count = 0;
  static  unsigned long long aesl_llvm_cbe_1779_count = 0;
  static  unsigned long long aesl_llvm_cbe_1780_count = 0;
  static  unsigned long long aesl_llvm_cbe_1781_count = 0;
  static  unsigned long long aesl_llvm_cbe_1782_count = 0;
  static  unsigned long long aesl_llvm_cbe_1783_count = 0;
  static  unsigned long long aesl_llvm_cbe_1784_count = 0;
  static  unsigned long long aesl_llvm_cbe_1785_count = 0;
  static  unsigned long long aesl_llvm_cbe_1786_count = 0;
  static  unsigned long long aesl_llvm_cbe_1787_count = 0;
  static  unsigned long long aesl_llvm_cbe_1788_count = 0;
  static  unsigned long long aesl_llvm_cbe_1789_count = 0;
  static  unsigned long long aesl_llvm_cbe_1790_count = 0;
  static  unsigned long long aesl_llvm_cbe_1791_count = 0;
  static  unsigned long long aesl_llvm_cbe_1792_count = 0;
  static  unsigned long long aesl_llvm_cbe_1793_count = 0;
  static  unsigned long long aesl_llvm_cbe_1794_count = 0;
  static  unsigned long long aesl_llvm_cbe_1795_count = 0;
  static  unsigned long long aesl_llvm_cbe_1796_count = 0;
  static  unsigned long long aesl_llvm_cbe_1797_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge16_count = 0;
  unsigned int llvm_cbe_storemerge16;
  unsigned int llvm_cbe_storemerge16__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1798_count = 0;
  unsigned long long llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_1799_count = 0;
   char *llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_1800_count = 0;
  unsigned char llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_1801_count = 0;
   char *llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_1802_count = 0;
  static  unsigned long long aesl_llvm_cbe_1803_count = 0;
  unsigned int llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_1804_count = 0;
  static  unsigned long long aesl_llvm_cbe_1805_count = 0;
  static  unsigned long long aesl_llvm_cbe_1806_count = 0;
  static  unsigned long long aesl_llvm_cbe_1807_count = 0;
  static  unsigned long long aesl_llvm_cbe_1808_count = 0;
  static  unsigned long long aesl_llvm_cbe_1809_count = 0;
  static  unsigned long long aesl_llvm_cbe_1810_count = 0;
  static  unsigned long long aesl_llvm_cbe_1811_count = 0;
  static  unsigned long long aesl_llvm_cbe_1812_count = 0;
  static  unsigned long long aesl_llvm_cbe_1813_count = 0;
  static  unsigned long long aesl_llvm_cbe_1814_count = 0;
  static  unsigned long long aesl_llvm_cbe_1815_count = 0;
  static  unsigned long long aesl_llvm_cbe_1816_count = 0;
  static  unsigned long long aesl_llvm_cbe_1817_count = 0;
  static  unsigned long long aesl_llvm_cbe_1818_count = 0;
  static  unsigned long long aesl_llvm_cbe_1819_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond20_count = 0;
  static  unsigned long long aesl_llvm_cbe_1820_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge49_count = 0;
  unsigned int llvm_cbe_storemerge49;
  unsigned int llvm_cbe_storemerge49__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1821_count = 0;
  unsigned int llvm_cbe_tmp__153;
  unsigned int llvm_cbe_tmp__153__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1822_count = 0;
  unsigned long long llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_1823_count = 0;
  signed int *llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_1824_count = 0;
  unsigned int llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_1825_count = 0;
  static  unsigned long long aesl_llvm_cbe_1826_count = 0;
  static  unsigned long long aesl_llvm_cbe_1827_count = 0;
  unsigned char llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_1828_count = 0;
  unsigned int llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_1829_count = 0;
  static  unsigned long long aesl_llvm_cbe_1830_count = 0;
  static  unsigned long long aesl_llvm_cbe_1831_count = 0;
  static  unsigned long long aesl_llvm_cbe_1832_count = 0;
  unsigned long long llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe__2e_sum5_count = 0;
  unsigned long long llvm_cbe__2e_sum5;
  static  unsigned long long aesl_llvm_cbe_1833_count = 0;
   char *llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_1834_count = 0;
  static  unsigned long long aesl_llvm_cbe_1835_count = 0;
  static  unsigned long long aesl_llvm_cbe_1836_count = 0;
  unsigned int llvm_cbe_tmp__161;
  unsigned int llvm_cbe_tmp__161__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1837_count = 0;
  unsigned int llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_1838_count = 0;
  static  unsigned long long aesl_llvm_cbe_1839_count = 0;
  static  unsigned long long aesl_llvm_cbe_1840_count = 0;
  static  unsigned long long aesl_llvm_cbe_1841_count = 0;
  static  unsigned long long aesl_llvm_cbe_1842_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1843_count = 0;
  static  unsigned long long aesl_llvm_cbe_1844_count = 0;
  unsigned char llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_1845_count = 0;
   char *llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_1846_count = 0;
  static  unsigned long long aesl_llvm_cbe_1847_count = 0;
  static  unsigned long long aesl_llvm_cbe_1848_count = 0;
  static  unsigned long long aesl_llvm_cbe_1849_count = 0;
  static  unsigned long long aesl_llvm_cbe_1850_count = 0;
  static  unsigned long long aesl_llvm_cbe_1851_count = 0;
  static  unsigned long long aesl_llvm_cbe_1852_count = 0;
  static  unsigned long long aesl_llvm_cbe_1853_count = 0;
  static  unsigned long long aesl_llvm_cbe_1854_count = 0;
  static  unsigned long long aesl_llvm_cbe_1855_count = 0;
  static  unsigned long long aesl_llvm_cbe_1856_count = 0;
  static  unsigned long long aesl_llvm_cbe_1857_count = 0;
  static  unsigned long long aesl_llvm_cbe_1858_count = 0;
  static  unsigned long long aesl_llvm_cbe_1859_count = 0;
  static  unsigned long long aesl_llvm_cbe_1860_count = 0;
  static  unsigned long long aesl_llvm_cbe_1861_count = 0;
  static  unsigned long long aesl_llvm_cbe_1862_count = 0;
  static  unsigned long long aesl_llvm_cbe_1863_count = 0;
  static  unsigned long long aesl_llvm_cbe_1864_count = 0;
  static  unsigned long long aesl_llvm_cbe_1865_count = 0;
  static  unsigned long long aesl_llvm_cbe_1866_count = 0;
  static  unsigned long long aesl_llvm_cbe_1867_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge49_2e_1_count = 0;
  unsigned int llvm_cbe_storemerge49_2e_1;
  unsigned int llvm_cbe_storemerge49_2e_1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1868_count = 0;
  unsigned int llvm_cbe_tmp__165;
  unsigned int llvm_cbe_tmp__165__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1869_count = 0;
  unsigned long long llvm_cbe_tmp__166;
  static  unsigned long long aesl_llvm_cbe_1870_count = 0;
  signed int *llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_1871_count = 0;
  unsigned int llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_1872_count = 0;
  static  unsigned long long aesl_llvm_cbe_1873_count = 0;
  static  unsigned long long aesl_llvm_cbe_1874_count = 0;
  unsigned char llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_1875_count = 0;
  unsigned int llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_1876_count = 0;
  static  unsigned long long aesl_llvm_cbe_1877_count = 0;
  static  unsigned long long aesl_llvm_cbe_1878_count = 0;
  static  unsigned long long aesl_llvm_cbe_1879_count = 0;
  unsigned long long llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe__2e_sum5_2e_1_count = 0;
  unsigned long long llvm_cbe__2e_sum5_2e_1;
  static  unsigned long long aesl_llvm_cbe_1880_count = 0;
   char *llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_1881_count = 0;
  static  unsigned long long aesl_llvm_cbe_1882_count = 0;
  static  unsigned long long aesl_llvm_cbe_1883_count = 0;
  unsigned int llvm_cbe_tmp__173;
  unsigned int llvm_cbe_tmp__173__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1884_count = 0;
  unsigned int llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_1885_count = 0;
  static  unsigned long long aesl_llvm_cbe_1886_count = 0;
  static  unsigned long long aesl_llvm_cbe_1887_count = 0;
  static  unsigned long long aesl_llvm_cbe_1888_count = 0;
  static  unsigned long long aesl_llvm_cbe_1889_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_2e_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_1890_count = 0;
  static  unsigned long long aesl_llvm_cbe_1891_count = 0;
  unsigned char llvm_cbe_tmp__175;
  static  unsigned long long aesl_llvm_cbe_1892_count = 0;
   char *llvm_cbe_tmp__176;
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
  static  unsigned long long aesl_llvm_cbe_storemerge49_2e_2_count = 0;
  unsigned int llvm_cbe_storemerge49_2e_2;
  unsigned int llvm_cbe_storemerge49_2e_2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1915_count = 0;
  unsigned int llvm_cbe_tmp__177;
  unsigned int llvm_cbe_tmp__177__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1916_count = 0;
  unsigned long long llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_1917_count = 0;
  signed int *llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_1918_count = 0;
  unsigned int llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_1919_count = 0;
  static  unsigned long long aesl_llvm_cbe_1920_count = 0;
  static  unsigned long long aesl_llvm_cbe_1921_count = 0;
  unsigned char llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_1922_count = 0;
  unsigned int llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_1923_count = 0;
  static  unsigned long long aesl_llvm_cbe_1924_count = 0;
  static  unsigned long long aesl_llvm_cbe_1925_count = 0;
  static  unsigned long long aesl_llvm_cbe_1926_count = 0;
  unsigned long long llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe__2e_sum5_2e_2_count = 0;
  unsigned long long llvm_cbe__2e_sum5_2e_2;
  static  unsigned long long aesl_llvm_cbe_1927_count = 0;
   char *llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_1928_count = 0;
  static  unsigned long long aesl_llvm_cbe_1929_count = 0;
  static  unsigned long long aesl_llvm_cbe_1930_count = 0;
  unsigned int llvm_cbe_tmp__185;
  unsigned int llvm_cbe_tmp__185__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1931_count = 0;
  unsigned int llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_1932_count = 0;
  static  unsigned long long aesl_llvm_cbe_1933_count = 0;
  static  unsigned long long aesl_llvm_cbe_1934_count = 0;
  static  unsigned long long aesl_llvm_cbe_1935_count = 0;
  static  unsigned long long aesl_llvm_cbe_1936_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_2e_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_1937_count = 0;
  static  unsigned long long aesl_llvm_cbe_1938_count = 0;
  unsigned char llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_1939_count = 0;
   char *llvm_cbe_tmp__188;
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
  static  unsigned long long aesl_llvm_cbe_storemerge49_2e_3_count = 0;
  unsigned int llvm_cbe_storemerge49_2e_3;
  unsigned int llvm_cbe_storemerge49_2e_3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1962_count = 0;
  unsigned int llvm_cbe_tmp__189;
  unsigned int llvm_cbe_tmp__189__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1963_count = 0;
  unsigned long long llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_1964_count = 0;
  signed int *llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_1965_count = 0;
  unsigned int llvm_cbe_tmp__192;
  static  unsigned long long aesl_llvm_cbe_1966_count = 0;
  static  unsigned long long aesl_llvm_cbe_1967_count = 0;
  static  unsigned long long aesl_llvm_cbe_1968_count = 0;
  unsigned char llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_1969_count = 0;
  unsigned int llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_1970_count = 0;
  static  unsigned long long aesl_llvm_cbe_1971_count = 0;
  static  unsigned long long aesl_llvm_cbe_1972_count = 0;
  static  unsigned long long aesl_llvm_cbe_1973_count = 0;
  unsigned long long llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe__2e_sum5_2e_3_count = 0;
  unsigned long long llvm_cbe__2e_sum5_2e_3;
  static  unsigned long long aesl_llvm_cbe_1974_count = 0;
   char *llvm_cbe_tmp__196;
  static  unsigned long long aesl_llvm_cbe_1975_count = 0;
  static  unsigned long long aesl_llvm_cbe_1976_count = 0;
  static  unsigned long long aesl_llvm_cbe_1977_count = 0;
  unsigned int llvm_cbe_tmp__197;
  unsigned int llvm_cbe_tmp__197__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1978_count = 0;
  unsigned int llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe_1979_count = 0;
  static  unsigned long long aesl_llvm_cbe_1980_count = 0;
  static  unsigned long long aesl_llvm_cbe_1981_count = 0;
  static  unsigned long long aesl_llvm_cbe_1982_count = 0;
  static  unsigned long long aesl_llvm_cbe_1983_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_2e_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_1984_count = 0;
  static  unsigned long long aesl_llvm_cbe_1985_count = 0;
  unsigned char llvm_cbe_tmp__199;
  static  unsigned long long aesl_llvm_cbe_1986_count = 0;
   char *llvm_cbe_tmp__200;
  static  unsigned long long aesl_llvm_cbe_1987_count = 0;
  static  unsigned long long aesl_llvm_cbe_1988_count = 0;
  static  unsigned long long aesl_llvm_cbe_1989_count = 0;
  static  unsigned long long aesl_llvm_cbe_1990_count = 0;
  static  unsigned long long aesl_llvm_cbe_1991_count = 0;
  static  unsigned long long aesl_llvm_cbe_1992_count = 0;
  static  unsigned long long aesl_llvm_cbe_1993_count = 0;
  static  unsigned long long aesl_llvm_cbe_1994_count = 0;
  static  unsigned long long aesl_llvm_cbe_1995_count = 0;
  static  unsigned long long aesl_llvm_cbe_1996_count = 0;
  static  unsigned long long aesl_llvm_cbe_1997_count = 0;
  static  unsigned long long aesl_llvm_cbe_1998_count = 0;
  static  unsigned long long aesl_llvm_cbe_1999_count = 0;
  static  unsigned long long aesl_llvm_cbe_2000_count = 0;
  static  unsigned long long aesl_llvm_cbe_2001_count = 0;
  static  unsigned long long aesl_llvm_cbe_2002_count = 0;
  static  unsigned long long aesl_llvm_cbe_2003_count = 0;
  static  unsigned long long aesl_llvm_cbe_2004_count = 0;
  static  unsigned long long aesl_llvm_cbe_2005_count = 0;
  static  unsigned long long aesl_llvm_cbe_2006_count = 0;
  static  unsigned long long aesl_llvm_cbe_2007_count = 0;
  static  unsigned long long aesl_llvm_cbe_2008_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge49_2e_4_count = 0;
  unsigned int llvm_cbe_storemerge49_2e_4;
  unsigned int llvm_cbe_storemerge49_2e_4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2009_count = 0;
  unsigned int llvm_cbe_tmp__201;
  unsigned int llvm_cbe_tmp__201__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2010_count = 0;
  unsigned long long llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe_2011_count = 0;
  signed int *llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_2012_count = 0;
  unsigned int llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_2013_count = 0;
  static  unsigned long long aesl_llvm_cbe_2014_count = 0;
  static  unsigned long long aesl_llvm_cbe_2015_count = 0;
  unsigned char llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_2016_count = 0;
  unsigned int llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_2017_count = 0;
  static  unsigned long long aesl_llvm_cbe_2018_count = 0;
  static  unsigned long long aesl_llvm_cbe_2019_count = 0;
  static  unsigned long long aesl_llvm_cbe_2020_count = 0;
  unsigned long long llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe__2e_sum5_2e_4_count = 0;
  unsigned long long llvm_cbe__2e_sum5_2e_4;
  static  unsigned long long aesl_llvm_cbe_2021_count = 0;
   char *llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_2022_count = 0;
  static  unsigned long long aesl_llvm_cbe_2023_count = 0;
  static  unsigned long long aesl_llvm_cbe_2024_count = 0;
  unsigned int llvm_cbe_tmp__209;
  unsigned int llvm_cbe_tmp__209__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2025_count = 0;
  unsigned int llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe_2026_count = 0;
  static  unsigned long long aesl_llvm_cbe_2027_count = 0;
  static  unsigned long long aesl_llvm_cbe_2028_count = 0;
  static  unsigned long long aesl_llvm_cbe_2029_count = 0;
  static  unsigned long long aesl_llvm_cbe_2030_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_2e_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_2031_count = 0;
  static  unsigned long long aesl_llvm_cbe_2032_count = 0;
  unsigned char llvm_cbe_tmp__211;
  static  unsigned long long aesl_llvm_cbe_2033_count = 0;
   char *llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe_2034_count = 0;
  static  unsigned long long aesl_llvm_cbe_2035_count = 0;
  static  unsigned long long aesl_llvm_cbe_2036_count = 0;
  static  unsigned long long aesl_llvm_cbe_2037_count = 0;
  static  unsigned long long aesl_llvm_cbe_2038_count = 0;
  static  unsigned long long aesl_llvm_cbe_2039_count = 0;
  static  unsigned long long aesl_llvm_cbe_2040_count = 0;
  static  unsigned long long aesl_llvm_cbe_2041_count = 0;
  static  unsigned long long aesl_llvm_cbe_2042_count = 0;
  static  unsigned long long aesl_llvm_cbe_2043_count = 0;
  static  unsigned long long aesl_llvm_cbe_2044_count = 0;
  static  unsigned long long aesl_llvm_cbe_2045_count = 0;
  static  unsigned long long aesl_llvm_cbe_2046_count = 0;
  static  unsigned long long aesl_llvm_cbe_2047_count = 0;
  static  unsigned long long aesl_llvm_cbe_2048_count = 0;
  static  unsigned long long aesl_llvm_cbe_2049_count = 0;
  static  unsigned long long aesl_llvm_cbe_2050_count = 0;
  static  unsigned long long aesl_llvm_cbe_2051_count = 0;
  static  unsigned long long aesl_llvm_cbe_2052_count = 0;
  static  unsigned long long aesl_llvm_cbe_2053_count = 0;
  static  unsigned long long aesl_llvm_cbe_2054_count = 0;
  static  unsigned long long aesl_llvm_cbe_2055_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge49_2e_5_count = 0;
  unsigned int llvm_cbe_storemerge49_2e_5;
  unsigned int llvm_cbe_storemerge49_2e_5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2056_count = 0;
  unsigned int llvm_cbe_tmp__213;
  unsigned int llvm_cbe_tmp__213__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2057_count = 0;
  unsigned long long llvm_cbe_tmp__214;
  static  unsigned long long aesl_llvm_cbe_2058_count = 0;
  signed int *llvm_cbe_tmp__215;
  static  unsigned long long aesl_llvm_cbe_2059_count = 0;
  unsigned int llvm_cbe_tmp__216;
  static  unsigned long long aesl_llvm_cbe_2060_count = 0;
  static  unsigned long long aesl_llvm_cbe_2061_count = 0;
  static  unsigned long long aesl_llvm_cbe_2062_count = 0;
  unsigned char llvm_cbe_tmp__217;
  static  unsigned long long aesl_llvm_cbe_2063_count = 0;
  unsigned int llvm_cbe_tmp__218;
  static  unsigned long long aesl_llvm_cbe_2064_count = 0;
  static  unsigned long long aesl_llvm_cbe_2065_count = 0;
  static  unsigned long long aesl_llvm_cbe_2066_count = 0;
  static  unsigned long long aesl_llvm_cbe_2067_count = 0;
  unsigned long long llvm_cbe_tmp__219;
  static  unsigned long long aesl_llvm_cbe__2e_sum5_2e_5_count = 0;
  unsigned long long llvm_cbe__2e_sum5_2e_5;
  static  unsigned long long aesl_llvm_cbe_2068_count = 0;
   char *llvm_cbe_tmp__220;
  static  unsigned long long aesl_llvm_cbe_2069_count = 0;
  static  unsigned long long aesl_llvm_cbe_2070_count = 0;
  static  unsigned long long aesl_llvm_cbe_2071_count = 0;
  unsigned int llvm_cbe_tmp__221;
  unsigned int llvm_cbe_tmp__221__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2072_count = 0;
  unsigned int llvm_cbe_tmp__222;
  static  unsigned long long aesl_llvm_cbe_2073_count = 0;
  static  unsigned long long aesl_llvm_cbe_2074_count = 0;
  static  unsigned long long aesl_llvm_cbe_2075_count = 0;
  static  unsigned long long aesl_llvm_cbe_2076_count = 0;
  static  unsigned long long aesl_llvm_cbe_2077_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_2e_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_2078_count = 0;
  static  unsigned long long aesl_llvm_cbe_2079_count = 0;
  unsigned char llvm_cbe_tmp__223;
  static  unsigned long long aesl_llvm_cbe_2080_count = 0;
   char *llvm_cbe_tmp__224;
  static  unsigned long long aesl_llvm_cbe_2081_count = 0;
  static  unsigned long long aesl_llvm_cbe_2082_count = 0;
  static  unsigned long long aesl_llvm_cbe_2083_count = 0;
  static  unsigned long long aesl_llvm_cbe_2084_count = 0;
  static  unsigned long long aesl_llvm_cbe_2085_count = 0;
  static  unsigned long long aesl_llvm_cbe_2086_count = 0;
  static  unsigned long long aesl_llvm_cbe_2087_count = 0;
  static  unsigned long long aesl_llvm_cbe_2088_count = 0;
  static  unsigned long long aesl_llvm_cbe_2089_count = 0;
  static  unsigned long long aesl_llvm_cbe_2090_count = 0;
  static  unsigned long long aesl_llvm_cbe_2091_count = 0;
  static  unsigned long long aesl_llvm_cbe_2092_count = 0;
  static  unsigned long long aesl_llvm_cbe_2093_count = 0;
  static  unsigned long long aesl_llvm_cbe_2094_count = 0;
  static  unsigned long long aesl_llvm_cbe_2095_count = 0;
  static  unsigned long long aesl_llvm_cbe_2096_count = 0;
  static  unsigned long long aesl_llvm_cbe_2097_count = 0;
  static  unsigned long long aesl_llvm_cbe_2098_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_pack_sig\n");
  llvm_cbe_storemerge16__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__225;

llvm_cbe__2e_preheader14:
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds i8* %%sig, i64 48, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1667_count);
  llvm_cbe_tmp__137 = ( char *)(&llvm_cbe_sig[(((signed long long )48ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.polyvecl* %%z, i64 0, i32 0, i64 0, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1668_count);
  llvm_cbe_tmp__138 = (l_struct_OC_poly *)(&llvm_cbe_z->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyz_pack(i8* %%1, %%struct.poly* %%2) nounwind, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1669_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyz_pack(( char *)llvm_cbe_tmp__137, (l_struct_OC_poly *)llvm_cbe_tmp__138);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i8* %%sig, i64 688, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1686_count);
  llvm_cbe_tmp__139 = ( char *)(&llvm_cbe_sig[(((signed long long )688ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.polyvecl* %%z, i64 0, i32 0, i64 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1687_count);
  llvm_cbe_tmp__140 = (l_struct_OC_poly *)(&llvm_cbe_z->field0[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyz_pack(i8* %%3, %%struct.poly* %%4) nounwind, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1688_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyz_pack(( char *)llvm_cbe_tmp__139, (l_struct_OC_poly *)llvm_cbe_tmp__140);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds i8* %%sig, i64 1328, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1705_count);
  llvm_cbe_tmp__141 = ( char *)(&llvm_cbe_sig[(((signed long long )1328ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.polyvecl* %%z, i64 0, i32 0, i64 2, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1706_count);
  llvm_cbe_tmp__142 = (l_struct_OC_poly *)(&llvm_cbe_z->field0[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyz_pack(i8* %%5, %%struct.poly* %%6) nounwind, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1707_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyz_pack(( char *)llvm_cbe_tmp__141, (l_struct_OC_poly *)llvm_cbe_tmp__142);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i8* %%sig, i64 1968, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1724_count);
  llvm_cbe_tmp__143 = ( char *)(&llvm_cbe_sig[(((signed long long )1968ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.polyvecl* %%z, i64 0, i32 0, i64 3, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1725_count);
  llvm_cbe_tmp__144 = (l_struct_OC_poly *)(&llvm_cbe_z->field0[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyz_pack(i8* %%7, %%struct.poly* %%8) nounwind, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1726_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyz_pack(( char *)llvm_cbe_tmp__143, (l_struct_OC_poly *)llvm_cbe_tmp__144);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds i8* %%sig, i64 2608, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1743_count);
  llvm_cbe_tmp__145 = ( char *)(&llvm_cbe_sig[(((signed long long )2608ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.polyvecl* %%z, i64 0, i32 0, i64 4, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1744_count);
  llvm_cbe_tmp__146 = (l_struct_OC_poly *)(&llvm_cbe_z->field0[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyz_pack(i8* %%9, %%struct.poly* %%10) nounwind, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1745_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyz_pack(( char *)llvm_cbe_tmp__145, (l_struct_OC_poly *)llvm_cbe_tmp__146);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%scevgep = getelementptr i8* %%sig, i64 324 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_scevgep_count);
  llvm_cbe_scevgep = ( char *)(&llvm_cbe_sig[(((signed long long )3248ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = call i8* @memset(i8* %%scevgep, i32 0, i64 61 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1777_count);
  ( char *)memset(( char *)llvm_cbe_scevgep, 0u, 61ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",61ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__147);
}
  llvm_cbe_storemerge49__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__153__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__226;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__225:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge16 = phi i32 [ 0, %%0 ], [ %%17, %%12  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_storemerge16_count);
  llvm_cbe_storemerge16 = (unsigned int )llvm_cbe_storemerge16__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge16 = 0x%X",llvm_cbe_storemerge16);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__152);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = zext i32 %%storemerge16 to i64, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1798_count);
  llvm_cbe_tmp__148 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge16&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__148);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i8* %%c, i64 %%13, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1799_count);
  llvm_cbe_tmp__149 = ( char *)(&llvm_cbe_c[(((signed long long )llvm_cbe_tmp__148))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__148));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i8* %%14, align 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1800_count);
  llvm_cbe_tmp__150 = (unsigned char )*llvm_cbe_tmp__149;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__150);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds i8* %%sig, i64 %%13, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1801_count);
  llvm_cbe_tmp__151 = ( char *)(&llvm_cbe_sig[(((signed long long )llvm_cbe_tmp__148))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__148));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%15, i8* %%16, align 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1802_count);
  *llvm_cbe_tmp__151 = llvm_cbe_tmp__150;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__150);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add i32 %%storemerge16, 1, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1803_count);
  llvm_cbe_tmp__152 = (unsigned int )((unsigned int )(llvm_cbe_storemerge16&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__152&4294967295ull)));
  if (((llvm_cbe_tmp__152&4294967295U) == (48u&4294967295U))) {
    goto llvm_cbe__2e_preheader14;
  } else {
    llvm_cbe_storemerge16__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__152;   /* for PHI node */
    goto llvm_cbe_tmp__225;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__226:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge49 = phi i32 [ 0, %%.preheader14 ], [ %%31, %%29  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_storemerge49_count);
  llvm_cbe_storemerge49 = (unsigned int )llvm_cbe_storemerge49__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge49 = 0x%X",llvm_cbe_storemerge49);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__162);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = phi i32 [ 0, %%.preheader14 ], [ %%30, %%29  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1821_count);
  llvm_cbe_tmp__153 = (unsigned int )llvm_cbe_tmp__153__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__153);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__161);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = zext i32 %%storemerge49 to i64, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1822_count);
  llvm_cbe_tmp__154 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge49&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__154);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.polyveck* %%h, i64 0, i32 0, i64 0, i32 0, i64 %%20, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1823_count);
  llvm_cbe_tmp__155 = (signed int *)(&llvm_cbe_h->field0[(((signed long long )0ull))].field0[(((signed long long )llvm_cbe_tmp__154))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__154));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i32* %%21, align 4, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1824_count);
  llvm_cbe_tmp__156 = (unsigned int )*llvm_cbe_tmp__155;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__156);
  if (((llvm_cbe_tmp__156&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__161__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__153;   /* for PHI node */
    goto llvm_cbe_tmp__227;
  } else {
    goto llvm_cbe_tmp__228;
  }

llvm_cbe_tmp__227:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = phi i32 [ %%26, %%24 ], [ %%19, %%18  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1836_count);
  llvm_cbe_tmp__161 = (unsigned int )llvm_cbe_tmp__161__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__161);
printf("\n = 0x%X",llvm_cbe_tmp__158);
printf("\n = 0x%X",llvm_cbe_tmp__153);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add i32 %%storemerge49, 1, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1837_count);
  llvm_cbe_tmp__162 = (unsigned int )((unsigned int )(llvm_cbe_storemerge49&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__162&4294967295ull)));
  if (((llvm_cbe_tmp__162&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe__2e_preheader_2e_1;
  } else {
    llvm_cbe_storemerge49__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__162;   /* for PHI node */
    llvm_cbe_tmp__153__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__161;   /* for PHI node */
    goto llvm_cbe_tmp__226;
  }

llvm_cbe_tmp__228:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = trunc i32 %%storemerge49 to i8, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1827_count);
  llvm_cbe_tmp__157 = (unsigned char )((unsigned char )llvm_cbe_storemerge49&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__157);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i32 %%19, 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1828_count);
  llvm_cbe_tmp__158 = (unsigned int )((unsigned int )(llvm_cbe_tmp__153&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__158&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = zext i32 %%19 to i64, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1832_count);
  llvm_cbe_tmp__159 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__153&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__159);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum5 = add i64 %%27, 3248, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe__2e_sum5_count);
  llvm_cbe__2e_sum5 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__159&18446744073709551615ull)) + ((unsigned long long )(3248ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum5 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum5&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds i8* %%sig, i64 %%.sum5, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1833_count);
  llvm_cbe_tmp__160 = ( char *)(&llvm_cbe_sig[(((signed long long )llvm_cbe__2e_sum5))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum5 = 0x%I64X",((signed long long )llvm_cbe__2e_sum5));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%25, i8* %%28, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1834_count);
  *llvm_cbe_tmp__160 = llvm_cbe_tmp__157;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__157);
  llvm_cbe_tmp__161__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__158;   /* for PHI node */
  goto llvm_cbe_tmp__227;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader_2e_1:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = trunc i32 %%30 to i8, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1844_count);
  llvm_cbe_tmp__163 = (unsigned char )((unsigned char )llvm_cbe_tmp__161&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__163);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds i8* %%sig, i64 3303, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1845_count);
  llvm_cbe_tmp__164 = ( char *)(&llvm_cbe_sig[(((signed long long )3303ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%32, i8* %%33, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1846_count);
  *llvm_cbe_tmp__164 = llvm_cbe_tmp__163;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__163);
  llvm_cbe_storemerge49_2e_1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__165__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__161;   /* for PHI node */
  goto llvm_cbe_tmp__229;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__229:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge49.1 = phi i32 [ 0, %%.preheader.1 ], [ %%47, %%45  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_storemerge49_2e_1_count);
  llvm_cbe_storemerge49_2e_1 = (unsigned int )llvm_cbe_storemerge49_2e_1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge49.1 = 0x%X",llvm_cbe_storemerge49_2e_1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__174);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = phi i32 [ %%30, %%.preheader.1 ], [ %%46, %%45  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1868_count);
  llvm_cbe_tmp__165 = (unsigned int )llvm_cbe_tmp__165__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__165);
printf("\n = 0x%X",llvm_cbe_tmp__161);
printf("\n = 0x%X",llvm_cbe_tmp__173);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = zext i32 %%storemerge49.1 to i64, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1869_count);
  llvm_cbe_tmp__166 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge49_2e_1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__166);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds %%struct.polyveck* %%h, i64 0, i32 0, i64 1, i32 0, i64 %%36, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1870_count);
  llvm_cbe_tmp__167 = (signed int *)(&llvm_cbe_h->field0[(((signed long long )1ull))].field0[(((signed long long )llvm_cbe_tmp__166))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__166));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i32* %%37, align 4, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1871_count);
  llvm_cbe_tmp__168 = (unsigned int )*llvm_cbe_tmp__167;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__168);
  if (((llvm_cbe_tmp__168&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__173__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__165;   /* for PHI node */
    goto llvm_cbe_tmp__230;
  } else {
    goto llvm_cbe_tmp__231;
  }

llvm_cbe_tmp__230:
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = phi i32 [ %%42, %%40 ], [ %%35, %%34  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1883_count);
  llvm_cbe_tmp__173 = (unsigned int )llvm_cbe_tmp__173__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__173);
printf("\n = 0x%X",llvm_cbe_tmp__170);
printf("\n = 0x%X",llvm_cbe_tmp__165);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = add i32 %%storemerge49.1, 1, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1884_count);
  llvm_cbe_tmp__174 = (unsigned int )((unsigned int )(llvm_cbe_storemerge49_2e_1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__174&4294967295ull)));
  if (((llvm_cbe_tmp__174&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe__2e_preheader_2e_2;
  } else {
    llvm_cbe_storemerge49_2e_1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__174;   /* for PHI node */
    llvm_cbe_tmp__165__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__173;   /* for PHI node */
    goto llvm_cbe_tmp__229;
  }

llvm_cbe_tmp__231:
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = trunc i32 %%storemerge49.1 to i8, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1874_count);
  llvm_cbe_tmp__169 = (unsigned char )((unsigned char )llvm_cbe_storemerge49_2e_1&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__169);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add i32 %%35, 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1875_count);
  llvm_cbe_tmp__170 = (unsigned int )((unsigned int )(llvm_cbe_tmp__165&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__170&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = zext i32 %%35 to i64, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1879_count);
  llvm_cbe_tmp__171 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__165&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__171);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum5.1 = add i64 %%43, 3248, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe__2e_sum5_2e_1_count);
  llvm_cbe__2e_sum5_2e_1 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__171&18446744073709551615ull)) + ((unsigned long long )(3248ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum5.1 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum5_2e_1&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds i8* %%sig, i64 %%.sum5.1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1880_count);
  llvm_cbe_tmp__172 = ( char *)(&llvm_cbe_sig[(((signed long long )llvm_cbe__2e_sum5_2e_1))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum5.1 = 0x%I64X",((signed long long )llvm_cbe__2e_sum5_2e_1));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%41, i8* %%44, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1881_count);
  *llvm_cbe_tmp__172 = llvm_cbe_tmp__169;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__169);
  llvm_cbe_tmp__173__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__170;   /* for PHI node */
  goto llvm_cbe_tmp__230;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader_2e_2:
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = trunc i32 %%46 to i8, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1891_count);
  llvm_cbe_tmp__175 = (unsigned char )((unsigned char )llvm_cbe_tmp__173&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__175);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds i8* %%sig, i64 3304, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1892_count);
  llvm_cbe_tmp__176 = ( char *)(&llvm_cbe_sig[(((signed long long )3304ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%48, i8* %%49, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1893_count);
  *llvm_cbe_tmp__176 = llvm_cbe_tmp__175;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__175);
  llvm_cbe_storemerge49_2e_2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__177__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__173;   /* for PHI node */
  goto llvm_cbe_tmp__232;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__232:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge49.2 = phi i32 [ 0, %%.preheader.2 ], [ %%63, %%61  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_storemerge49_2e_2_count);
  llvm_cbe_storemerge49_2e_2 = (unsigned int )llvm_cbe_storemerge49_2e_2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge49.2 = 0x%X",llvm_cbe_storemerge49_2e_2);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__186);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = phi i32 [ %%46, %%.preheader.2 ], [ %%62, %%61  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1915_count);
  llvm_cbe_tmp__177 = (unsigned int )llvm_cbe_tmp__177__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__177);
printf("\n = 0x%X",llvm_cbe_tmp__173);
printf("\n = 0x%X",llvm_cbe_tmp__185);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = zext i32 %%storemerge49.2 to i64, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1916_count);
  llvm_cbe_tmp__178 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge49_2e_2&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__178);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds %%struct.polyveck* %%h, i64 0, i32 0, i64 2, i32 0, i64 %%52, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1917_count);
  llvm_cbe_tmp__179 = (signed int *)(&llvm_cbe_h->field0[(((signed long long )2ull))].field0[(((signed long long )llvm_cbe_tmp__178))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__178));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load i32* %%53, align 4, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1918_count);
  llvm_cbe_tmp__180 = (unsigned int )*llvm_cbe_tmp__179;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__180);
  if (((llvm_cbe_tmp__180&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__185__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__177;   /* for PHI node */
    goto llvm_cbe_tmp__233;
  } else {
    goto llvm_cbe_tmp__234;
  }

llvm_cbe_tmp__233:
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = phi i32 [ %%58, %%56 ], [ %%51, %%50  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1930_count);
  llvm_cbe_tmp__185 = (unsigned int )llvm_cbe_tmp__185__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__185);
printf("\n = 0x%X",llvm_cbe_tmp__182);
printf("\n = 0x%X",llvm_cbe_tmp__177);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = add i32 %%storemerge49.2, 1, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1931_count);
  llvm_cbe_tmp__186 = (unsigned int )((unsigned int )(llvm_cbe_storemerge49_2e_2&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__186&4294967295ull)));
  if (((llvm_cbe_tmp__186&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe__2e_preheader_2e_3;
  } else {
    llvm_cbe_storemerge49_2e_2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__186;   /* for PHI node */
    llvm_cbe_tmp__177__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__185;   /* for PHI node */
    goto llvm_cbe_tmp__232;
  }

llvm_cbe_tmp__234:
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = trunc i32 %%storemerge49.2 to i8, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1921_count);
  llvm_cbe_tmp__181 = (unsigned char )((unsigned char )llvm_cbe_storemerge49_2e_2&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__181);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = add i32 %%51, 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1922_count);
  llvm_cbe_tmp__182 = (unsigned int )((unsigned int )(llvm_cbe_tmp__177&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__182&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = zext i32 %%51 to i64, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1926_count);
  llvm_cbe_tmp__183 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__177&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__183);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum5.2 = add i64 %%59, 3248, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe__2e_sum5_2e_2_count);
  llvm_cbe__2e_sum5_2e_2 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__183&18446744073709551615ull)) + ((unsigned long long )(3248ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum5.2 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum5_2e_2&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = getelementptr inbounds i8* %%sig, i64 %%.sum5.2, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1927_count);
  llvm_cbe_tmp__184 = ( char *)(&llvm_cbe_sig[(((signed long long )llvm_cbe__2e_sum5_2e_2))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum5.2 = 0x%I64X",((signed long long )llvm_cbe__2e_sum5_2e_2));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%57, i8* %%60, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1928_count);
  *llvm_cbe_tmp__184 = llvm_cbe_tmp__181;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__181);
  llvm_cbe_tmp__185__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__182;   /* for PHI node */
  goto llvm_cbe_tmp__233;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader_2e_3:
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = trunc i32 %%62 to i8, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1938_count);
  llvm_cbe_tmp__187 = (unsigned char )((unsigned char )llvm_cbe_tmp__185&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__187);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = getelementptr inbounds i8* %%sig, i64 3305, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1939_count);
  llvm_cbe_tmp__188 = ( char *)(&llvm_cbe_sig[(((signed long long )3305ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%64, i8* %%65, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1940_count);
  *llvm_cbe_tmp__188 = llvm_cbe_tmp__187;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__187);
  llvm_cbe_storemerge49_2e_3__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__189__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__185;   /* for PHI node */
  goto llvm_cbe_tmp__235;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__235:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge49.3 = phi i32 [ 0, %%.preheader.3 ], [ %%79, %%77  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_storemerge49_2e_3_count);
  llvm_cbe_storemerge49_2e_3 = (unsigned int )llvm_cbe_storemerge49_2e_3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge49.3 = 0x%X",llvm_cbe_storemerge49_2e_3);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__198);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = phi i32 [ %%62, %%.preheader.3 ], [ %%78, %%77  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1962_count);
  llvm_cbe_tmp__189 = (unsigned int )llvm_cbe_tmp__189__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__189);
printf("\n = 0x%X",llvm_cbe_tmp__185);
printf("\n = 0x%X",llvm_cbe_tmp__197);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = zext i32 %%storemerge49.3 to i64, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1963_count);
  llvm_cbe_tmp__190 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge49_2e_3&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__190);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = getelementptr inbounds %%struct.polyveck* %%h, i64 0, i32 0, i64 3, i32 0, i64 %%68, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1964_count);
  llvm_cbe_tmp__191 = (signed int *)(&llvm_cbe_h->field0[(((signed long long )3ull))].field0[(((signed long long )llvm_cbe_tmp__190))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__190));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = load i32* %%69, align 4, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1965_count);
  llvm_cbe_tmp__192 = (unsigned int )*llvm_cbe_tmp__191;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__192);
  if (((llvm_cbe_tmp__192&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__197__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__189;   /* for PHI node */
    goto llvm_cbe_tmp__236;
  } else {
    goto llvm_cbe_tmp__237;
  }

llvm_cbe_tmp__236:
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = phi i32 [ %%74, %%72 ], [ %%67, %%66  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1977_count);
  llvm_cbe_tmp__197 = (unsigned int )llvm_cbe_tmp__197__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__197);
printf("\n = 0x%X",llvm_cbe_tmp__194);
printf("\n = 0x%X",llvm_cbe_tmp__189);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = add i32 %%storemerge49.3, 1, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1978_count);
  llvm_cbe_tmp__198 = (unsigned int )((unsigned int )(llvm_cbe_storemerge49_2e_3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__198&4294967295ull)));
  if (((llvm_cbe_tmp__198&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe__2e_preheader_2e_4;
  } else {
    llvm_cbe_storemerge49_2e_3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__198;   /* for PHI node */
    llvm_cbe_tmp__189__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__197;   /* for PHI node */
    goto llvm_cbe_tmp__235;
  }

llvm_cbe_tmp__237:
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = trunc i32 %%storemerge49.3 to i8, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1968_count);
  llvm_cbe_tmp__193 = (unsigned char )((unsigned char )llvm_cbe_storemerge49_2e_3&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__193);
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = add i32 %%67, 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1969_count);
  llvm_cbe_tmp__194 = (unsigned int )((unsigned int )(llvm_cbe_tmp__189&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__194&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = zext i32 %%67 to i64, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1973_count);
  llvm_cbe_tmp__195 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__189&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__195);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum5.3 = add i64 %%75, 3248, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe__2e_sum5_2e_3_count);
  llvm_cbe__2e_sum5_2e_3 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__195&18446744073709551615ull)) + ((unsigned long long )(3248ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum5.3 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum5_2e_3&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = getelementptr inbounds i8* %%sig, i64 %%.sum5.3, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1974_count);
  llvm_cbe_tmp__196 = ( char *)(&llvm_cbe_sig[(((signed long long )llvm_cbe__2e_sum5_2e_3))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum5.3 = 0x%I64X",((signed long long )llvm_cbe__2e_sum5_2e_3));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%73, i8* %%76, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1975_count);
  *llvm_cbe_tmp__196 = llvm_cbe_tmp__193;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__193);
  llvm_cbe_tmp__197__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__194;   /* for PHI node */
  goto llvm_cbe_tmp__236;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader_2e_4:
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = trunc i32 %%78 to i8, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1985_count);
  llvm_cbe_tmp__199 = (unsigned char )((unsigned char )llvm_cbe_tmp__197&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__199);
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = getelementptr inbounds i8* %%sig, i64 3306, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1986_count);
  llvm_cbe_tmp__200 = ( char *)(&llvm_cbe_sig[(((signed long long )3306ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%80, i8* %%81, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_1987_count);
  *llvm_cbe_tmp__200 = llvm_cbe_tmp__199;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__199);
  llvm_cbe_storemerge49_2e_4__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__201__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__197;   /* for PHI node */
  goto llvm_cbe_tmp__238;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__238:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge49.4 = phi i32 [ 0, %%.preheader.4 ], [ %%95, %%93  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_storemerge49_2e_4_count);
  llvm_cbe_storemerge49_2e_4 = (unsigned int )llvm_cbe_storemerge49_2e_4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge49.4 = 0x%X",llvm_cbe_storemerge49_2e_4);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__210);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = phi i32 [ %%78, %%.preheader.4 ], [ %%94, %%93  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2009_count);
  llvm_cbe_tmp__201 = (unsigned int )llvm_cbe_tmp__201__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__201);
printf("\n = 0x%X",llvm_cbe_tmp__197);
printf("\n = 0x%X",llvm_cbe_tmp__209);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = zext i32 %%storemerge49.4 to i64, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2010_count);
  llvm_cbe_tmp__202 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge49_2e_4&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__202);
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = getelementptr inbounds %%struct.polyveck* %%h, i64 0, i32 0, i64 4, i32 0, i64 %%84, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2011_count);
  llvm_cbe_tmp__203 = (signed int *)(&llvm_cbe_h->field0[(((signed long long )4ull))].field0[(((signed long long )llvm_cbe_tmp__202))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__202));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = load i32* %%85, align 4, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2012_count);
  llvm_cbe_tmp__204 = (unsigned int )*llvm_cbe_tmp__203;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__204);
  if (((llvm_cbe_tmp__204&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__209__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__201;   /* for PHI node */
    goto llvm_cbe_tmp__239;
  } else {
    goto llvm_cbe_tmp__240;
  }

llvm_cbe_tmp__239:
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = phi i32 [ %%90, %%88 ], [ %%83, %%82  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2024_count);
  llvm_cbe_tmp__209 = (unsigned int )llvm_cbe_tmp__209__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__209);
printf("\n = 0x%X",llvm_cbe_tmp__206);
printf("\n = 0x%X",llvm_cbe_tmp__201);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = add i32 %%storemerge49.4, 1, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2025_count);
  llvm_cbe_tmp__210 = (unsigned int )((unsigned int )(llvm_cbe_storemerge49_2e_4&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__210&4294967295ull)));
  if (((llvm_cbe_tmp__210&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe__2e_preheader_2e_5;
  } else {
    llvm_cbe_storemerge49_2e_4__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__210;   /* for PHI node */
    llvm_cbe_tmp__201__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__209;   /* for PHI node */
    goto llvm_cbe_tmp__238;
  }

llvm_cbe_tmp__240:
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = trunc i32 %%storemerge49.4 to i8, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2015_count);
  llvm_cbe_tmp__205 = (unsigned char )((unsigned char )llvm_cbe_storemerge49_2e_4&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__205);
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = add i32 %%83, 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2016_count);
  llvm_cbe_tmp__206 = (unsigned int )((unsigned int )(llvm_cbe_tmp__201&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__206&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = zext i32 %%83 to i64, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2020_count);
  llvm_cbe_tmp__207 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__201&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__207);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum5.4 = add i64 %%91, 3248, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe__2e_sum5_2e_4_count);
  llvm_cbe__2e_sum5_2e_4 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__207&18446744073709551615ull)) + ((unsigned long long )(3248ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum5.4 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum5_2e_4&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = getelementptr inbounds i8* %%sig, i64 %%.sum5.4, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2021_count);
  llvm_cbe_tmp__208 = ( char *)(&llvm_cbe_sig[(((signed long long )llvm_cbe__2e_sum5_2e_4))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum5.4 = 0x%I64X",((signed long long )llvm_cbe__2e_sum5_2e_4));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%89, i8* %%92, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2022_count);
  *llvm_cbe_tmp__208 = llvm_cbe_tmp__205;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__205);
  llvm_cbe_tmp__209__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__206;   /* for PHI node */
  goto llvm_cbe_tmp__239;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader_2e_5:
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = trunc i32 %%94 to i8, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2032_count);
  llvm_cbe_tmp__211 = (unsigned char )((unsigned char )llvm_cbe_tmp__209&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__211);
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = getelementptr inbounds i8* %%sig, i64 3307, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2033_count);
  llvm_cbe_tmp__212 = ( char *)(&llvm_cbe_sig[(((signed long long )3307ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%96, i8* %%97, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2034_count);
  *llvm_cbe_tmp__212 = llvm_cbe_tmp__211;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__211);
  llvm_cbe_storemerge49_2e_5__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__213__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__209;   /* for PHI node */
  goto llvm_cbe_tmp__241;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__241:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge49.5 = phi i32 [ 0, %%.preheader.5 ], [ %%111, %%109  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_storemerge49_2e_5_count);
  llvm_cbe_storemerge49_2e_5 = (unsigned int )llvm_cbe_storemerge49_2e_5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge49.5 = 0x%X",llvm_cbe_storemerge49_2e_5);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__222);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = phi i32 [ %%94, %%.preheader.5 ], [ %%110, %%109  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2056_count);
  llvm_cbe_tmp__213 = (unsigned int )llvm_cbe_tmp__213__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__213);
printf("\n = 0x%X",llvm_cbe_tmp__209);
printf("\n = 0x%X",llvm_cbe_tmp__221);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = zext i32 %%storemerge49.5 to i64, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2057_count);
  llvm_cbe_tmp__214 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge49_2e_5&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__214);
if (AESL_DEBUG_TRACE)
printf("\n  %%101 = getelementptr inbounds %%struct.polyveck* %%h, i64 0, i32 0, i64 5, i32 0, i64 %%100, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2058_count);
  llvm_cbe_tmp__215 = (signed int *)(&llvm_cbe_h->field0[(((signed long long )5ull))].field0[(((signed long long )llvm_cbe_tmp__214))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__214));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = load i32* %%101, align 4, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2059_count);
  llvm_cbe_tmp__216 = (unsigned int )*llvm_cbe_tmp__215;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__216);
  if (((llvm_cbe_tmp__216&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__221__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__213;   /* for PHI node */
    goto llvm_cbe_tmp__242;
  } else {
    goto llvm_cbe_tmp__243;
  }

llvm_cbe_tmp__242:
if (AESL_DEBUG_TRACE)
printf("\n  %%110 = phi i32 [ %%106, %%104 ], [ %%99, %%98  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2071_count);
  llvm_cbe_tmp__221 = (unsigned int )llvm_cbe_tmp__221__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__221);
printf("\n = 0x%X",llvm_cbe_tmp__218);
printf("\n = 0x%X",llvm_cbe_tmp__213);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%111 = add i32 %%storemerge49.5, 1, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2072_count);
  llvm_cbe_tmp__222 = (unsigned int )((unsigned int )(llvm_cbe_storemerge49_2e_5&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__222&4294967295ull)));
  if (((llvm_cbe_tmp__222&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__244;
  } else {
    llvm_cbe_storemerge49_2e_5__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__222;   /* for PHI node */
    llvm_cbe_tmp__213__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__221;   /* for PHI node */
    goto llvm_cbe_tmp__241;
  }

llvm_cbe_tmp__243:
if (AESL_DEBUG_TRACE)
printf("\n  %%105 = trunc i32 %%storemerge49.5 to i8, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2062_count);
  llvm_cbe_tmp__217 = (unsigned char )((unsigned char )llvm_cbe_storemerge49_2e_5&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__217);
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = add i32 %%99, 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2063_count);
  llvm_cbe_tmp__218 = (unsigned int )((unsigned int )(llvm_cbe_tmp__213&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__218&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = zext i32 %%99 to i64, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2067_count);
  llvm_cbe_tmp__219 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__213&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__219);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum5.5 = add i64 %%107, 3248, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe__2e_sum5_2e_5_count);
  llvm_cbe__2e_sum5_2e_5 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__219&18446744073709551615ull)) + ((unsigned long long )(3248ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum5.5 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum5_2e_5&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = getelementptr inbounds i8* %%sig, i64 %%.sum5.5, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2068_count);
  llvm_cbe_tmp__220 = ( char *)(&llvm_cbe_sig[(((signed long long )llvm_cbe__2e_sum5_2e_5))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum5.5 = 0x%I64X",((signed long long )llvm_cbe__2e_sum5_2e_5));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%105, i8* %%108, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2069_count);
  *llvm_cbe_tmp__220 = llvm_cbe_tmp__217;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__217);
  llvm_cbe_tmp__221__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__218;   /* for PHI node */
  goto llvm_cbe_tmp__242;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__244:
if (AESL_DEBUG_TRACE)
printf("\n  %%113 = trunc i32 %%110 to i8, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2079_count);
  llvm_cbe_tmp__223 = (unsigned char )((unsigned char )llvm_cbe_tmp__221&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__223);
if (AESL_DEBUG_TRACE)
printf("\n  %%114 = getelementptr inbounds i8* %%sig, i64 3308, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2080_count);
  llvm_cbe_tmp__224 = ( char *)(&llvm_cbe_sig[(((signed long long )3308ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%113, i8* %%114, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_pack_sig  --> \n", ++aesl_llvm_cbe_2081_count);
  *llvm_cbe_tmp__224 = llvm_cbe_tmp__223;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__223);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_pack_sig}\n");
  return;
}


signed int pqcrystals_dilithium3_ref_unpack_sig( char *llvm_cbe_c, l_struct_OC_polyvecl *llvm_cbe_z, l_struct_OC_polyveck *llvm_cbe_h,  char *llvm_cbe_sig) {
  static  unsigned long long aesl_llvm_cbe_2099_count = 0;
  static  unsigned long long aesl_llvm_cbe_2100_count = 0;
  static  unsigned long long aesl_llvm_cbe_2101_count = 0;
  static  unsigned long long aesl_llvm_cbe_2102_count = 0;
  static  unsigned long long aesl_llvm_cbe_2103_count = 0;
  static  unsigned long long aesl_llvm_cbe_2104_count = 0;
  static  unsigned long long aesl_llvm_cbe_2105_count = 0;
  static  unsigned long long aesl_llvm_cbe_2106_count = 0;
  static  unsigned long long aesl_llvm_cbe_2107_count = 0;
  static  unsigned long long aesl_llvm_cbe_2108_count = 0;
  static  unsigned long long aesl_llvm_cbe_2109_count = 0;
  static  unsigned long long aesl_llvm_cbe_2110_count = 0;
  static  unsigned long long aesl_llvm_cbe_2111_count = 0;
  static  unsigned long long aesl_llvm_cbe_2112_count = 0;
  static  unsigned long long aesl_llvm_cbe_2113_count = 0;
  static  unsigned long long aesl_llvm_cbe_2114_count = 0;
  static  unsigned long long aesl_llvm_cbe_2115_count = 0;
  static  unsigned long long aesl_llvm_cbe_2116_count = 0;
  static  unsigned long long aesl_llvm_cbe_2117_count = 0;
  static  unsigned long long aesl_llvm_cbe_2118_count = 0;
  static  unsigned long long aesl_llvm_cbe_2119_count = 0;
  static  unsigned long long aesl_llvm_cbe_2120_count = 0;
  static  unsigned long long aesl_llvm_cbe_2121_count = 0;
  static  unsigned long long aesl_llvm_cbe_2122_count = 0;
  static  unsigned long long aesl_llvm_cbe_2123_count = 0;
  static  unsigned long long aesl_llvm_cbe_2124_count = 0;
  static  unsigned long long aesl_llvm_cbe_2125_count = 0;
  static  unsigned long long aesl_llvm_cbe_2126_count = 0;
  static  unsigned long long aesl_llvm_cbe_2127_count = 0;
  static  unsigned long long aesl_llvm_cbe_2128_count = 0;
  static  unsigned long long aesl_llvm_cbe_2129_count = 0;
  static  unsigned long long aesl_llvm_cbe_2130_count = 0;
  static  unsigned long long aesl_llvm_cbe_2131_count = 0;
  static  unsigned long long aesl_llvm_cbe_2132_count = 0;
  static  unsigned long long aesl_llvm_cbe_2133_count = 0;
  static  unsigned long long aesl_llvm_cbe_2134_count = 0;
  static  unsigned long long aesl_llvm_cbe_2135_count = 0;
  static  unsigned long long aesl_llvm_cbe_2136_count = 0;
  static  unsigned long long aesl_llvm_cbe_2137_count = 0;
  static  unsigned long long aesl_llvm_cbe_2138_count = 0;
  static  unsigned long long aesl_llvm_cbe_2139_count = 0;
  static  unsigned long long aesl_llvm_cbe_2140_count = 0;
  static  unsigned long long aesl_llvm_cbe_2141_count = 0;
  static  unsigned long long aesl_llvm_cbe_2142_count = 0;
  static  unsigned long long aesl_llvm_cbe_2143_count = 0;
  static  unsigned long long aesl_llvm_cbe_2144_count = 0;
  static  unsigned long long aesl_llvm_cbe_2145_count = 0;
  static  unsigned long long aesl_llvm_cbe_2146_count = 0;
  static  unsigned long long aesl_llvm_cbe_2147_count = 0;
  static  unsigned long long aesl_llvm_cbe_2148_count = 0;
  static  unsigned long long aesl_llvm_cbe_2149_count = 0;
  static  unsigned long long aesl_llvm_cbe_2150_count = 0;
  static  unsigned long long aesl_llvm_cbe_2151_count = 0;
  static  unsigned long long aesl_llvm_cbe_2152_count = 0;
  static  unsigned long long aesl_llvm_cbe_2153_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_2154_count = 0;
   char *llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_2155_count = 0;
  static  unsigned long long aesl_llvm_cbe_2156_count = 0;
  static  unsigned long long aesl_llvm_cbe_2157_count = 0;
  static  unsigned long long aesl_llvm_cbe_2158_count = 0;
  static  unsigned long long aesl_llvm_cbe_2159_count = 0;
  static  unsigned long long aesl_llvm_cbe_2160_count = 0;
  static  unsigned long long aesl_llvm_cbe_2161_count = 0;
  static  unsigned long long aesl_llvm_cbe_2162_count = 0;
  static  unsigned long long aesl_llvm_cbe_2163_count = 0;
  static  unsigned long long aesl_llvm_cbe_2164_count = 0;
  static  unsigned long long aesl_llvm_cbe_2165_count = 0;
  static  unsigned long long aesl_llvm_cbe_2166_count = 0;
  static  unsigned long long aesl_llvm_cbe_2167_count = 0;
  static  unsigned long long aesl_llvm_cbe_2168_count = 0;
  static  unsigned long long aesl_llvm_cbe_2169_count = 0;
  static  unsigned long long aesl_llvm_cbe_2170_count = 0;
  static  unsigned long long aesl_llvm_cbe_2171_count = 0;
  static  unsigned long long aesl_llvm_cbe_2172_count = 0;
  static  unsigned long long aesl_llvm_cbe_2173_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_2174_count = 0;
   char *llvm_cbe_tmp__248;
  static  unsigned long long aesl_llvm_cbe_2175_count = 0;
  static  unsigned long long aesl_llvm_cbe_2176_count = 0;
  static  unsigned long long aesl_llvm_cbe_2177_count = 0;
  static  unsigned long long aesl_llvm_cbe_2178_count = 0;
  static  unsigned long long aesl_llvm_cbe_2179_count = 0;
  static  unsigned long long aesl_llvm_cbe_2180_count = 0;
  static  unsigned long long aesl_llvm_cbe_2181_count = 0;
  static  unsigned long long aesl_llvm_cbe_2182_count = 0;
  static  unsigned long long aesl_llvm_cbe_2183_count = 0;
  static  unsigned long long aesl_llvm_cbe_2184_count = 0;
  static  unsigned long long aesl_llvm_cbe_2185_count = 0;
  static  unsigned long long aesl_llvm_cbe_2186_count = 0;
  static  unsigned long long aesl_llvm_cbe_2187_count = 0;
  static  unsigned long long aesl_llvm_cbe_2188_count = 0;
  static  unsigned long long aesl_llvm_cbe_2189_count = 0;
  static  unsigned long long aesl_llvm_cbe_2190_count = 0;
  static  unsigned long long aesl_llvm_cbe_2191_count = 0;
  static  unsigned long long aesl_llvm_cbe_2192_count = 0;
  static  unsigned long long aesl_llvm_cbe_2193_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__249;
  static  unsigned long long aesl_llvm_cbe_2194_count = 0;
   char *llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_2195_count = 0;
  static  unsigned long long aesl_llvm_cbe_2196_count = 0;
  static  unsigned long long aesl_llvm_cbe_2197_count = 0;
  static  unsigned long long aesl_llvm_cbe_2198_count = 0;
  static  unsigned long long aesl_llvm_cbe_2199_count = 0;
  static  unsigned long long aesl_llvm_cbe_2200_count = 0;
  static  unsigned long long aesl_llvm_cbe_2201_count = 0;
  static  unsigned long long aesl_llvm_cbe_2202_count = 0;
  static  unsigned long long aesl_llvm_cbe_2203_count = 0;
  static  unsigned long long aesl_llvm_cbe_2204_count = 0;
  static  unsigned long long aesl_llvm_cbe_2205_count = 0;
  static  unsigned long long aesl_llvm_cbe_2206_count = 0;
  static  unsigned long long aesl_llvm_cbe_2207_count = 0;
  static  unsigned long long aesl_llvm_cbe_2208_count = 0;
  static  unsigned long long aesl_llvm_cbe_2209_count = 0;
  static  unsigned long long aesl_llvm_cbe_2210_count = 0;
  static  unsigned long long aesl_llvm_cbe_2211_count = 0;
  static  unsigned long long aesl_llvm_cbe_2212_count = 0;
  static  unsigned long long aesl_llvm_cbe_2213_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__251;
  static  unsigned long long aesl_llvm_cbe_2214_count = 0;
   char *llvm_cbe_tmp__252;
  static  unsigned long long aesl_llvm_cbe_2215_count = 0;
  static  unsigned long long aesl_llvm_cbe_2216_count = 0;
  static  unsigned long long aesl_llvm_cbe_2217_count = 0;
  static  unsigned long long aesl_llvm_cbe_2218_count = 0;
  static  unsigned long long aesl_llvm_cbe_2219_count = 0;
  static  unsigned long long aesl_llvm_cbe_2220_count = 0;
  static  unsigned long long aesl_llvm_cbe_2221_count = 0;
  static  unsigned long long aesl_llvm_cbe_2222_count = 0;
  static  unsigned long long aesl_llvm_cbe_2223_count = 0;
  static  unsigned long long aesl_llvm_cbe_2224_count = 0;
  static  unsigned long long aesl_llvm_cbe_2225_count = 0;
  static  unsigned long long aesl_llvm_cbe_2226_count = 0;
  static  unsigned long long aesl_llvm_cbe_2227_count = 0;
  static  unsigned long long aesl_llvm_cbe_2228_count = 0;
  static  unsigned long long aesl_llvm_cbe_2229_count = 0;
  static  unsigned long long aesl_llvm_cbe_2230_count = 0;
  static  unsigned long long aesl_llvm_cbe_2231_count = 0;
  static  unsigned long long aesl_llvm_cbe_2232_count = 0;
  static  unsigned long long aesl_llvm_cbe_2233_count = 0;
  l_struct_OC_poly *llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe_2234_count = 0;
   char *llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_2235_count = 0;
  static  unsigned long long aesl_llvm_cbe_2236_count = 0;
  static  unsigned long long aesl_llvm_cbe_2237_count = 0;
  static  unsigned long long aesl_llvm_cbe_2238_count = 0;
  static  unsigned long long aesl_llvm_cbe_2239_count = 0;
  static  unsigned long long aesl_llvm_cbe_2240_count = 0;
  static  unsigned long long aesl_llvm_cbe_2241_count = 0;
  static  unsigned long long aesl_llvm_cbe_2242_count = 0;
  static  unsigned long long aesl_llvm_cbe_2243_count = 0;
  static  unsigned long long aesl_llvm_cbe_2244_count = 0;
  static  unsigned long long aesl_llvm_cbe_2245_count = 0;
  static  unsigned long long aesl_llvm_cbe_2246_count = 0;
  static  unsigned long long aesl_llvm_cbe_2247_count = 0;
  static  unsigned long long aesl_llvm_cbe_2248_count = 0;
  static  unsigned long long aesl_llvm_cbe_2249_count = 0;
  static  unsigned long long aesl_llvm_cbe_2250_count = 0;
  static  unsigned long long aesl_llvm_cbe_2251_count = 0;
  static  unsigned long long aesl_llvm_cbe_2252_count = 0;
  static  unsigned long long aesl_llvm_cbe_2253_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge24_count = 0;
  unsigned int llvm_cbe_storemerge24;
  unsigned int llvm_cbe_storemerge24__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2254_count = 0;
  unsigned long long llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_2255_count = 0;
   char *llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe_2256_count = 0;
  unsigned char llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_2257_count = 0;
   char *llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_2258_count = 0;
  static  unsigned long long aesl_llvm_cbe_2259_count = 0;
  unsigned int llvm_cbe_tmp__259;
  static  unsigned long long aesl_llvm_cbe_2260_count = 0;
  static  unsigned long long aesl_llvm_cbe_2261_count = 0;
  static  unsigned long long aesl_llvm_cbe_2262_count = 0;
  static  unsigned long long aesl_llvm_cbe_2263_count = 0;
  static  unsigned long long aesl_llvm_cbe_2264_count = 0;
  static  unsigned long long aesl_llvm_cbe_2265_count = 0;
  static  unsigned long long aesl_llvm_cbe_2266_count = 0;
  static  unsigned long long aesl_llvm_cbe_2267_count = 0;
  static  unsigned long long aesl_llvm_cbe_2268_count = 0;
  static  unsigned long long aesl_llvm_cbe_2269_count = 0;
  static  unsigned long long aesl_llvm_cbe_2270_count = 0;
  static  unsigned long long aesl_llvm_cbe_2271_count = 0;
  static  unsigned long long aesl_llvm_cbe_2272_count = 0;
  static  unsigned long long aesl_llvm_cbe_2273_count = 0;
  static  unsigned long long aesl_llvm_cbe_2274_count = 0;
  static  unsigned long long aesl_llvm_cbe_2275_count = 0;
  static  unsigned long long aesl_llvm_cbe_2276_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond30_count = 0;
  static  unsigned long long aesl_llvm_cbe_2277_count = 0;
  static  unsigned long long aesl_llvm_cbe_2278_count = 0;
  unsigned int llvm_cbe_tmp__260;
  unsigned int llvm_cbe_tmp__260__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge2_count = 0;
  unsigned int llvm_cbe_storemerge2;
  unsigned int llvm_cbe_storemerge2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2279_count = 0;
  static  unsigned long long aesl_llvm_cbe_2280_count = 0;
  static  unsigned long long aesl_llvm_cbe_2281_count = 0;
  static  unsigned long long aesl_llvm_cbe_2282_count = 0;
  static  unsigned long long aesl_llvm_cbe_2283_count = 0;
  static  unsigned long long aesl_llvm_cbe_2284_count = 0;
  static  unsigned long long aesl_llvm_cbe_2285_count = 0;
  static  unsigned long long aesl_llvm_cbe_2286_count = 0;
  static  unsigned long long aesl_llvm_cbe_2287_count = 0;
  static  unsigned long long aesl_llvm_cbe_2288_count = 0;
  static  unsigned long long aesl_llvm_cbe_2289_count = 0;
  static  unsigned long long aesl_llvm_cbe_2290_count = 0;
  static  unsigned long long aesl_llvm_cbe_2291_count = 0;
  static  unsigned long long aesl_llvm_cbe_2292_count = 0;
  static  unsigned long long aesl_llvm_cbe_2293_count = 0;
  static  unsigned long long aesl_llvm_cbe_2294_count = 0;
  static  unsigned long long aesl_llvm_cbe_2295_count = 0;
  static  unsigned long long aesl_llvm_cbe_2296_count = 0;
  static  unsigned long long aesl_llvm_cbe_2297_count = 0;
  static  unsigned long long aesl_llvm_cbe_2298_count = 0;
  static  unsigned long long aesl_llvm_cbe_2299_count = 0;
  static  unsigned long long aesl_llvm_cbe_2300_count = 0;
  static  unsigned long long aesl_llvm_cbe_2301_count = 0;
  static  unsigned long long aesl_llvm_cbe_2302_count = 0;
  static  unsigned long long aesl_llvm_cbe_2303_count = 0;
  static  unsigned long long aesl_llvm_cbe_2304_count = 0;
  static  unsigned long long aesl_llvm_cbe_2305_count = 0;
  static  unsigned long long aesl_llvm_cbe_2306_count = 0;
  static  unsigned long long aesl_llvm_cbe_2307_count = 0;
  static  unsigned long long aesl_llvm_cbe_2308_count = 0;
  static  unsigned long long aesl_llvm_cbe_2309_count = 0;
  static  unsigned long long aesl_llvm_cbe_2310_count = 0;
  static  unsigned long long aesl_llvm_cbe_2311_count = 0;
  unsigned long long llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_2312_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge416_count = 0;
  unsigned int llvm_cbe_storemerge416;
  unsigned int llvm_cbe_storemerge416__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2313_count = 0;
  unsigned long long llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_2314_count = 0;
  signed int *llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_2315_count = 0;
  static  unsigned long long aesl_llvm_cbe_2316_count = 0;
  unsigned int llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe_2317_count = 0;
  static  unsigned long long aesl_llvm_cbe_2318_count = 0;
  static  unsigned long long aesl_llvm_cbe_2319_count = 0;
  static  unsigned long long aesl_llvm_cbe_2320_count = 0;
  static  unsigned long long aesl_llvm_cbe_2321_count = 0;
  static  unsigned long long aesl_llvm_cbe_2322_count = 0;
  static  unsigned long long aesl_llvm_cbe_2323_count = 0;
  static  unsigned long long aesl_llvm_cbe_2324_count = 0;
  static  unsigned long long aesl_llvm_cbe_2325_count = 0;
  static  unsigned long long aesl_llvm_cbe_2326_count = 0;
  static  unsigned long long aesl_llvm_cbe_2327_count = 0;
  static  unsigned long long aesl_llvm_cbe_2328_count = 0;
  static  unsigned long long aesl_llvm_cbe_2329_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_2330_count = 0;
  static  unsigned long long aesl_llvm_cbe_2331_count = 0;
  unsigned int llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_2332_count = 0;
  unsigned long long llvm_cbe_tmp__266;
  static  unsigned long long aesl_llvm_cbe__2e_sum6_count = 0;
  unsigned long long llvm_cbe__2e_sum6;
  static  unsigned long long aesl_llvm_cbe_2333_count = 0;
   char *llvm_cbe_tmp__267;
  static  unsigned long long aesl_llvm_cbe_2334_count = 0;
  unsigned char llvm_cbe_tmp__268;
  static  unsigned long long aesl_llvm_cbe_2335_count = 0;
  unsigned int llvm_cbe_tmp__269;
  static  unsigned long long aesl_llvm_cbe_2336_count = 0;
  static  unsigned long long aesl_llvm_cbe_2337_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_2338_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge5_count = 0;
  unsigned int llvm_cbe_storemerge5;
  unsigned int llvm_cbe_storemerge5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2339_count = 0;
  static  unsigned long long aesl_llvm_cbe_2340_count = 0;
  static  unsigned long long aesl_llvm_cbe_2341_count = 0;
  static  unsigned long long aesl_llvm_cbe_2342_count = 0;
  static  unsigned long long aesl_llvm_cbe_2343_count = 0;
  static  unsigned long long aesl_llvm_cbe_2344_count = 0;
  static  unsigned long long aesl_llvm_cbe_2345_count = 0;
  static  unsigned long long aesl_llvm_cbe_2346_count = 0;
  static  unsigned long long aesl_llvm_cbe_2347_count = 0;
  static  unsigned long long aesl_llvm_cbe_2348_count = 0;
  static  unsigned long long aesl_llvm_cbe_2349_count = 0;
  static  unsigned long long aesl_llvm_cbe_2350_count = 0;
  static  unsigned long long aesl_llvm_cbe_2351_count = 0;
  unsigned char llvm_cbe_tmp__270;
  static  unsigned long long aesl_llvm_cbe_2352_count = 0;
  unsigned int llvm_cbe_tmp__271;
  static  unsigned long long aesl_llvm_cbe_2353_count = 0;
  static  unsigned long long aesl_llvm_cbe_2354_count = 0;
  static  unsigned long long aesl_llvm_cbe_2355_count = 0;
  static  unsigned long long aesl_llvm_cbe_2356_count = 0;
  static  unsigned long long aesl_llvm_cbe_2357_count = 0;
  unsigned long long llvm_cbe_tmp__272;
  static  unsigned long long aesl_llvm_cbe__2e_sum8_count = 0;
  unsigned long long llvm_cbe__2e_sum8;
  static  unsigned long long aesl_llvm_cbe_2358_count = 0;
   char *llvm_cbe_tmp__273;
  static  unsigned long long aesl_llvm_cbe_2359_count = 0;
  unsigned char llvm_cbe_tmp__274;
  static  unsigned long long aesl_llvm_cbe_2360_count = 0;
  unsigned int llvm_cbe_tmp__275;
  static  unsigned long long aesl_llvm_cbe_2361_count = 0;
  unsigned long long llvm_cbe_tmp__276;
  static  unsigned long long aesl_llvm_cbe__2e_sum9_count = 0;
  unsigned long long llvm_cbe__2e_sum9;
  static  unsigned long long aesl_llvm_cbe_2362_count = 0;
   char *llvm_cbe_tmp__277;
  static  unsigned long long aesl_llvm_cbe_2363_count = 0;
  unsigned char llvm_cbe_tmp__278;
  static  unsigned long long aesl_llvm_cbe_2364_count = 0;
  static  unsigned long long aesl_llvm_cbe_2365_count = 0;
  static  unsigned long long aesl_llvm_cbe_2366_count = 0;
  unsigned long long llvm_cbe_tmp__279;
  static  unsigned long long aesl_llvm_cbe__2e_sum7_count = 0;
  unsigned long long llvm_cbe__2e_sum7;
  static  unsigned long long aesl_llvm_cbe_2367_count = 0;
   char *llvm_cbe_tmp__280;
  static  unsigned long long aesl_llvm_cbe_2368_count = 0;
  unsigned char llvm_cbe_tmp__281;
  static  unsigned long long aesl_llvm_cbe_2369_count = 0;
  unsigned long long llvm_cbe_tmp__282;
  static  unsigned long long aesl_llvm_cbe_2370_count = 0;
  signed int *llvm_cbe_tmp__283;
  static  unsigned long long aesl_llvm_cbe_2371_count = 0;
  static  unsigned long long aesl_llvm_cbe_2372_count = 0;
  unsigned int llvm_cbe_tmp__284;
  static  unsigned long long aesl_llvm_cbe_2373_count = 0;
  static  unsigned long long aesl_llvm_cbe_2374_count = 0;
  static  unsigned long long aesl_llvm_cbe_2375_count = 0;
  static  unsigned long long aesl_llvm_cbe_2376_count = 0;
  static  unsigned long long aesl_llvm_cbe_2377_count = 0;
  static  unsigned long long aesl_llvm_cbe_2378_count = 0;
  static  unsigned long long aesl_llvm_cbe_2379_count = 0;
  static  unsigned long long aesl_llvm_cbe_2380_count = 0;
  unsigned int llvm_cbe_tmp__285;
  static  unsigned long long aesl_llvm_cbe_2381_count = 0;
  static  unsigned long long aesl_llvm_cbe_2382_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2383_count = 0;
  static  unsigned long long aesl_llvm_cbe_2384_count = 0;
  static  unsigned long long aesl_llvm_cbe_2385_count = 0;
  static  unsigned long long aesl_llvm_cbe_2386_count = 0;
  static  unsigned long long aesl_llvm_cbe_2387_count = 0;
  static  unsigned long long aesl_llvm_cbe_2388_count = 0;
  static  unsigned long long aesl_llvm_cbe_2389_count = 0;
  static  unsigned long long aesl_llvm_cbe_2390_count = 0;
  static  unsigned long long aesl_llvm_cbe_2391_count = 0;
  static  unsigned long long aesl_llvm_cbe_2392_count = 0;
  static  unsigned long long aesl_llvm_cbe_2393_count = 0;
  static  unsigned long long aesl_llvm_cbe_2394_count = 0;
  static  unsigned long long aesl_llvm_cbe_2395_count = 0;
  static  unsigned long long aesl_llvm_cbe_2396_count = 0;
  static  unsigned long long aesl_llvm_cbe_2397_count = 0;
  unsigned long long llvm_cbe_tmp__286;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_2398_count = 0;
   char *llvm_cbe_tmp__287;
  static  unsigned long long aesl_llvm_cbe_2399_count = 0;
  unsigned char llvm_cbe_tmp__288;
  static  unsigned long long aesl_llvm_cbe_2400_count = 0;
  static  unsigned long long aesl_llvm_cbe_2401_count = 0;
  unsigned int llvm_cbe_tmp__289;
  static  unsigned long long aesl_llvm_cbe_2402_count = 0;
  static  unsigned long long aesl_llvm_cbe_2403_count = 0;
  static  unsigned long long aesl_llvm_cbe_2404_count = 0;
  unsigned int llvm_cbe_tmp__290;
  unsigned int llvm_cbe_tmp__290__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_2405_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_unpack_sig\n");
  llvm_cbe_storemerge24__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__291;

llvm_cbe__2e_preheader22:
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.polyvecl* %%z, i64 0, i32 0, i64 0, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2153_count);
  llvm_cbe_tmp__245 = (l_struct_OC_poly *)(&llvm_cbe_z->field0[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds i8* %%sig, i64 48, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2154_count);
  llvm_cbe_tmp__246 = ( char *)(&llvm_cbe_sig[(((signed long long )48ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyz_unpack(%%struct.poly* %%1, i8* %%2) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2155_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyz_unpack((l_struct_OC_poly *)llvm_cbe_tmp__245, ( char *)llvm_cbe_tmp__246);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.polyvecl* %%z, i64 0, i32 0, i64 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2173_count);
  llvm_cbe_tmp__247 = (l_struct_OC_poly *)(&llvm_cbe_z->field0[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i8* %%sig, i64 688, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2174_count);
  llvm_cbe_tmp__248 = ( char *)(&llvm_cbe_sig[(((signed long long )688ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyz_unpack(%%struct.poly* %%3, i8* %%4) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2175_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyz_unpack((l_struct_OC_poly *)llvm_cbe_tmp__247, ( char *)llvm_cbe_tmp__248);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.polyvecl* %%z, i64 0, i32 0, i64 2, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2193_count);
  llvm_cbe_tmp__249 = (l_struct_OC_poly *)(&llvm_cbe_z->field0[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds i8* %%sig, i64 1328, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2194_count);
  llvm_cbe_tmp__250 = ( char *)(&llvm_cbe_sig[(((signed long long )1328ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyz_unpack(%%struct.poly* %%5, i8* %%6) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2195_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyz_unpack((l_struct_OC_poly *)llvm_cbe_tmp__249, ( char *)llvm_cbe_tmp__250);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.polyvecl* %%z, i64 0, i32 0, i64 3, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2213_count);
  llvm_cbe_tmp__251 = (l_struct_OC_poly *)(&llvm_cbe_z->field0[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i8* %%sig, i64 1968, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2214_count);
  llvm_cbe_tmp__252 = ( char *)(&llvm_cbe_sig[(((signed long long )1968ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyz_unpack(%%struct.poly* %%7, i8* %%8) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2215_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyz_unpack((l_struct_OC_poly *)llvm_cbe_tmp__251, ( char *)llvm_cbe_tmp__252);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.polyvecl* %%z, i64 0, i32 0, i64 4, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2233_count);
  llvm_cbe_tmp__253 = (l_struct_OC_poly *)(&llvm_cbe_z->field0[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i8* %%sig, i64 2608, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2234_count);
  llvm_cbe_tmp__254 = ( char *)(&llvm_cbe_sig[(((signed long long )2608ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @pqcrystals_dilithium3_ref_polyz_unpack(%%struct.poly* %%9, i8* %%10) nounwind, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2235_count);
   /*tail*/ pqcrystals_dilithium3_ref_polyz_unpack((l_struct_OC_poly *)llvm_cbe_tmp__253, ( char *)llvm_cbe_tmp__254);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_tmp__260__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__292;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__291:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge24 = phi i32 [ 0, %%0 ], [ %%16, %%11  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_storemerge24_count);
  llvm_cbe_storemerge24 = (unsigned int )llvm_cbe_storemerge24__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge24 = 0x%X",llvm_cbe_storemerge24);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__259);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = zext i32 %%storemerge24 to i64, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2254_count);
  llvm_cbe_tmp__255 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge24&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__255);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds i8* %%sig, i64 %%12, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2255_count);
  llvm_cbe_tmp__256 = ( char *)(&llvm_cbe_sig[(((signed long long )llvm_cbe_tmp__255))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__255));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i8* %%13, align 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2256_count);
  llvm_cbe_tmp__257 = (unsigned char )*llvm_cbe_tmp__256;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__257);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds i8* %%c, i64 %%12, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2257_count);
  llvm_cbe_tmp__258 = ( char *)(&llvm_cbe_c[(((signed long long )llvm_cbe_tmp__255))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__255));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%14, i8* %%15, align 1, !dbg !9 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2258_count);
  *llvm_cbe_tmp__258 = llvm_cbe_tmp__257;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__257);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i32 %%storemerge24, 1, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2259_count);
  llvm_cbe_tmp__259 = (unsigned int )((unsigned int )(llvm_cbe_storemerge24&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__259&4294967295ull)));
  if (((llvm_cbe_tmp__259&4294967295U) == (48u&4294967295U))) {
    goto llvm_cbe__2e_preheader22;
  } else {
    llvm_cbe_storemerge24__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__259;   /* for PHI node */
    goto llvm_cbe_tmp__291;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__292:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = phi i32 [ %%34, %%54 ], [ 0, %%.preheader22  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2278_count);
  llvm_cbe_tmp__260 = (unsigned int )llvm_cbe_tmp__260__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__260);
printf("\n = 0x%X",llvm_cbe_tmp__271);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2 = phi i32 [ %%55, %%54 ], [ 0, %%.preheader22  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_storemerge2_count);
  llvm_cbe_storemerge2 = (unsigned int )llvm_cbe_storemerge2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2 = 0x%X",llvm_cbe_storemerge2);
printf("\n = 0x%X",llvm_cbe_tmp__285);
printf("\n = 0x%X",0u);
}
  if ((((unsigned int )llvm_cbe_storemerge2&4294967295U) < ((unsigned int )6u&4294967295U))) {
    goto llvm_cbe__2e_preheader15;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__260;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

llvm_cbe_tmp__293:
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = add i32 %%storemerge2, 1, !dbg !12 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2380_count);
  llvm_cbe_tmp__285 = (unsigned int )((unsigned int )(llvm_cbe_storemerge2&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__285&4294967295ull)));
  llvm_cbe_tmp__260__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__271;   /* for PHI node */
  llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__285;   /* for PHI node */
  goto llvm_cbe_tmp__292;

  do {     /* Syntactic loop '.preheader12' to make GCC happy */
llvm_cbe__2e_preheader12:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge5 = phi i32 [ %%53, %%47 ], [ %%18, %%25  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_storemerge5_count);
  llvm_cbe_storemerge5 = (unsigned int )llvm_cbe_storemerge5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge5 = 0x%X",llvm_cbe_storemerge5);
printf("\n = 0x%X",llvm_cbe_tmp__284);
printf("\n = 0x%X",llvm_cbe_tmp__260);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i8* %%28, align 1, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2351_count);
  llvm_cbe_tmp__270 = (unsigned char )*llvm_cbe_tmp__267;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__270);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = zext i8 %%33 to i32, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2352_count);
  llvm_cbe_tmp__271 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__270&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__271);
  if ((((unsigned int )llvm_cbe_storemerge5&4294967295U) < ((unsigned int )llvm_cbe_tmp__271&4294967295U))) {
    goto llvm_cbe_tmp__294;
  } else {
    goto llvm_cbe_tmp__293;
  }

llvm_cbe_tmp__295:
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = zext i32 %%storemerge5 to i64, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2366_count);
  llvm_cbe_tmp__279 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge5&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__279);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum7 = add i64 %%48, 3248, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe__2e_sum7_count);
  llvm_cbe__2e_sum7 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__279&18446744073709551615ull)) + ((unsigned long long )(3248ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum7 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum7&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = getelementptr inbounds i8* %%sig, i64 %%.sum7, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2367_count);
  llvm_cbe_tmp__280 = ( char *)(&llvm_cbe_sig[(((signed long long )llvm_cbe__2e_sum7))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum7 = 0x%I64X",((signed long long )llvm_cbe__2e_sum7));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = load i8* %%49, align 1, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2368_count);
  llvm_cbe_tmp__281 = (unsigned char )*llvm_cbe_tmp__280;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__281);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = zext i8 %%50 to i64, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2369_count);
  llvm_cbe_tmp__282 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__281&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__282);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = getelementptr inbounds %%struct.polyveck* %%h, i64 0, i32 0, i64 %%20, i32 0, i64 %%51, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2370_count);
  llvm_cbe_tmp__283 = (signed int *)(&llvm_cbe_h->field0[(((signed long long )llvm_cbe_tmp__261))].field0[(((signed long long )llvm_cbe_tmp__282))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__261));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__282));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1, i32* %%52, align 4, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2371_count);
  *llvm_cbe_tmp__283 = 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1u);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = add i32 %%storemerge5, 1, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2372_count);
  llvm_cbe_tmp__284 = (unsigned int )((unsigned int )(llvm_cbe_storemerge5&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__284&4294967295ull)));
  llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__284;   /* for PHI node */
  goto llvm_cbe__2e_preheader12;

llvm_cbe_tmp__294:
  if ((((unsigned int )llvm_cbe_storemerge5&4294967295U) > ((unsigned int )llvm_cbe_tmp__260&4294967295U))) {
    goto llvm_cbe_tmp__296;
  } else {
    goto llvm_cbe_tmp__295;
  }

llvm_cbe_tmp__296:
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = zext i32 %%storemerge5 to i64, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2357_count);
  llvm_cbe_tmp__272 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge5&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__272);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum8 = add i64 %%39, 3248, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe__2e_sum8_count);
  llvm_cbe__2e_sum8 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__272&18446744073709551615ull)) + ((unsigned long long )(3248ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum8 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum8&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds i8* %%sig, i64 %%.sum8, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2358_count);
  llvm_cbe_tmp__273 = ( char *)(&llvm_cbe_sig[(((signed long long )llvm_cbe__2e_sum8))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum8 = 0x%I64X",((signed long long )llvm_cbe__2e_sum8));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = load i8* %%40, align 1, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2359_count);
  llvm_cbe_tmp__274 = (unsigned char )*llvm_cbe_tmp__273;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__274);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add i32 %%storemerge5, -1, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2360_count);
  llvm_cbe_tmp__275 = (unsigned int )((unsigned int )(llvm_cbe_storemerge5&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__275&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = zext i32 %%42 to i64, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2361_count);
  llvm_cbe_tmp__276 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__275&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__276);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum9 = add i64 %%43, 3248, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe__2e_sum9_count);
  llvm_cbe__2e_sum9 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__276&18446744073709551615ull)) + ((unsigned long long )(3248ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum9 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum9&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds i8* %%sig, i64 %%.sum9, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2362_count);
  llvm_cbe_tmp__277 = ( char *)(&llvm_cbe_sig[(((signed long long )llvm_cbe__2e_sum9))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum9 = 0x%I64X",((signed long long )llvm_cbe__2e_sum9));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i8* %%44, align 1, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2363_count);
  llvm_cbe_tmp__278 = (unsigned char )*llvm_cbe_tmp__277;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__278);
  if ((((unsigned char )llvm_cbe_tmp__274&255U) > ((unsigned char )llvm_cbe_tmp__278&255U))) {
    goto llvm_cbe_tmp__295;
  } else {
    llvm_cbe_tmp__290__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

  } while (1); /* end of syntactic loop '.preheader12' */
llvm_cbe_tmp__297:
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i32 %%storemerge2, 55, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2331_count);
  llvm_cbe_tmp__265 = (unsigned int )((unsigned int )(llvm_cbe_storemerge2&4294967295ull)) + ((unsigned int )(55u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__265&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = zext i32 %%26 to i64, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2332_count);
  llvm_cbe_tmp__266 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__265&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__266);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum6 = add i64 %%27, 3248, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe__2e_sum6_count);
  llvm_cbe__2e_sum6 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__266&18446744073709551615ull)) + ((unsigned long long )(3248ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum6 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum6&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds i8* %%sig, i64 %%.sum6, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2333_count);
  llvm_cbe_tmp__267 = ( char *)(&llvm_cbe_sig[(((signed long long )llvm_cbe__2e_sum6))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum6 = 0x%I64X",((signed long long )llvm_cbe__2e_sum6));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i8* %%28, align 1, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2334_count);
  llvm_cbe_tmp__268 = (unsigned char )*llvm_cbe_tmp__267;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__268);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = zext i8 %%29 to i32, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2335_count);
  llvm_cbe_tmp__269 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__268&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__269);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = or i1 %%31, %%32, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )(((((unsigned int )llvm_cbe_tmp__269&4294967295U) < ((unsigned int )llvm_cbe_tmp__260&4294967295U)) | (((unsigned char )llvm_cbe_tmp__268&255U) > ((unsigned char )((unsigned char )55)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
  if (llvm_cbe_or_2e_cond) {
    llvm_cbe_tmp__290__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__260;   /* for PHI node */
    goto llvm_cbe__2e_preheader12;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__298:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge416 = phi i32 [ 0, %%.preheader15 ], [ %%24, %%21  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_storemerge416_count);
  llvm_cbe_storemerge416 = (unsigned int )llvm_cbe_storemerge416__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge416 = 0x%X",llvm_cbe_storemerge416);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__264);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = zext i32 %%storemerge416 to i64, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2313_count);
  llvm_cbe_tmp__262 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge416&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__262);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds %%struct.polyveck* %%h, i64 0, i32 0, i64 %%20, i32 0, i64 %%22, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2314_count);
  llvm_cbe_tmp__263 = (signed int *)(&llvm_cbe_h->field0[(((signed long long )llvm_cbe_tmp__261))].field0[(((signed long long )llvm_cbe_tmp__262))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__261));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__262));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%23, align 4, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2315_count);
  *llvm_cbe_tmp__263 = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i32 %%storemerge416, 1, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2316_count);
  llvm_cbe_tmp__264 = (unsigned int )((unsigned int )(llvm_cbe_storemerge416&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__264&4294967295ull)));
  if (((llvm_cbe_tmp__264&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__297;
  } else {
    llvm_cbe_storemerge416__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__264;   /* for PHI node */
    goto llvm_cbe_tmp__298;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader15:
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = zext i32 %%storemerge2 to i64, !dbg !10 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2311_count);
  llvm_cbe_tmp__261 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge2&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__261);
  llvm_cbe_storemerge416__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__298;

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ %%62, %%57 ], [ %%18, %%17  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",llvm_cbe_tmp__289);
printf("\n = 0x%X",llvm_cbe_tmp__260);
}
  if ((((unsigned int )llvm_cbe_storemerge3&4294967295U) < ((unsigned int )55u&4294967295U))) {
    goto llvm_cbe_tmp__299;
  } else {
    llvm_cbe_tmp__290__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

llvm_cbe_tmp__299:
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = zext i32 %%storemerge3 to i64, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2397_count);
  llvm_cbe_tmp__286 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge3&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__286);
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%58, 3248, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__286&18446744073709551615ull)) + ((unsigned long long )(3248ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = getelementptr inbounds i8* %%sig, i64 %%.sum, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2398_count);
  llvm_cbe_tmp__287 = ( char *)(&llvm_cbe_sig[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = load i8* %%59, align 1, !dbg !11 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2399_count);
  llvm_cbe_tmp__288 = (unsigned char )*llvm_cbe_tmp__287;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__288);
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = add i32 %%storemerge3, 1, !dbg !13 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2401_count);
  llvm_cbe_tmp__289 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__289&4294967295ull)));
  if (((llvm_cbe_tmp__288&255U) == (((unsigned char )0)&255U))) {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__289;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_tmp__290__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = phi i32 [ 0, %%.preheader ], [ 1, %%57 ], [ 1, %%38 ], [ 1, %%25  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_unpack_sig  --> \n", ++aesl_llvm_cbe_2404_count);
  llvm_cbe_tmp__290 = (unsigned int )llvm_cbe_tmp__290__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__290);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",1u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_unpack_sig}\n");
  return llvm_cbe_tmp__290;
}

