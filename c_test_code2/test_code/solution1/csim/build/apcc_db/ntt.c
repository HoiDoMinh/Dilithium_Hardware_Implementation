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

/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void pqcrystals_dilithium3_ref_ntt(signed int *llvm_cbe_a);
signed int pqcrystals_dilithium3_ref_montgomery_reduce(signed long long );
void pqcrystals_dilithium3_ref_invntt_tomont(signed int *llvm_cbe_a);


/* Global Variable Definitions and Initialization */
static signed int aesl_internal_zetas[256] = { 0u, 25847u, 4292358402u, 4294448387u, 237124u, 4294189336u, 4294091048u, 466468u, 1826347u, 2353451u, 4294608045u, 4292875391u, 3119733u, 4292082441u, 3111497u, 2680103u, 2725464u, 1024112u, 4293887396u, 3585928u, 4294417808u, 4293847712u, 2619752u, 4292858747u, 4292849110u, 4291107559u, 4293567735u, 4291689624u, 1757237u, 4294947874u, 4010497u, 280005u, 2706023u, 95776u, 3077325u, 3530437u, 4293305603u, 4291375148u, 4292429780u, 3915439u, 4291106181u, 4291923580u, 3574422u, 4292099649u, 3539968u, 4294666829u, 2348700u, 4294427997u, 4293268029u, 4293323478u, 3505694u, 4291145561u, 3507263u, 4292826647u, 4293366876u, 3699596u, 811944u, 531354u, 954230u, 3881043u, 3900724u, 4292410416u, 2071892u, 4292169517u, 4291036901u, 4293438593u, 4291289551u, 4291926041u, 4293514845u, 3475950u, 2176455u, 4293382075u, 4293709685u, 1939314u, 4290883698u, 4293967094u, 4291777152u, 4291809966u, 4291334368u, 126922u, 3412210u, 4293983877u, 2147896u, 2715295u, 4291999651u, 4291273803u, 4294556269u, 4292490249u, 4294296194u, 4293738771u, 4294944315u, 4293659127u, 4294585309u, 1349076u, 1852771u, 4293536866u, 4291623913u, 264944u, 508951u, 3097992u, 44288u, 4293867198u, 904516u, 3958618u, 4291242954u, 4294958718u, 1653064u, 4291717568u, 2389356u, 4294756319u, 759969u, 4293650440u, 189548u, 4291414024u, 3159746u, 4293115894u, 4292557971u, 4294789856u, 1315589u, 1341330u, 1285669u, 4293382368u, 4294154564u, 4293527554u, 4291948194u, 4291086236u, 4291338327u, 3839961u, 2091667u, 3407706u, 2316500u, 3817976u, 4291624818u, 2244091u, 4292520863u, 4291404834u, 266997u, 2434439u, 4293731568u, 3513181u, 4291446944u, 4291207932u, 4293770070u, 4291773918u, 900702u, 1859098u, 909542u, 819034u, 495491u, 4293354122u, 4294924036u, 4294444796u, 4294311969u, 4291844854u, 2031748u, 3207046u, 4291410301u, 4294442198u, 4294198674u, 4291371458u, 342297u, 286988u, 4292529473u, 4108315u, 3437287u, 4291625019u, 1735879u, 203044u, 2842341u, 2691481u, 4292377146u, 1265009u, 4055324u, 1247620u, 2486353u, 1595974u, 4291200280u, 1250494u, 2635921u, 4291419024u, 4291973257u, 1869119u, 1903435u, 4293916326u, 4293634238u, 1237275u, 4291649086u, 4293537071u, 4294516196u, 1312455u, 3306115u, 4293004654u, 4293687635u, 1917081u, 4292420984u, 4293592493u, 1500165u, 777191u, 2235880u, 3406031u, 4294424884u, 4292135436u, 4293296120u, 4293120343u, 4292383003u, 4291243026u, 594136u, 4291190303u, 4292953688u, 2432395u, 2454455u, 4294802575u, 1957272u, 3369112u, 185531u, 4293759911u, 4291783870u, 162844u, 1616392u, 3014001u, 810149u, 1652634u, 4291273063u, 4293168189u, 4291928380u, 3523897u, 3866901u, 269760u, 2213111u, 4293991412u, 1717735u, 472078u, 4294540613u, 1723600u, 4293164206u, 1910376u, 4293299864u, 4293862963u, 4294706650u, 4291133403u, 4292028260u, 4292731311u, 4294546397u, 4292680969u, 183443u, 4293990405u, 1612842u, 4291421609u, 4294412880u, 3919660u, 4294918990u, 4293605087u, 3937738u, 1400424u, 4294121142u, 1976782u };


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

void pqcrystals_dilithium3_ref_ntt(signed int *llvm_cbe_a) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge5_count = 0;
  unsigned int llvm_cbe_storemerge5;
  unsigned int llvm_cbe_storemerge5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  unsigned int llvm_cbe_tmp__1;
  unsigned int llvm_cbe_tmp__1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned int llvm_cbe_storemerge14;
  unsigned int llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  unsigned int llvm_cbe_tmp__2;
  unsigned int llvm_cbe_tmp__2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  unsigned long long llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  signed int *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge23_count = 0;
  unsigned int llvm_cbe_storemerge23;
  unsigned int llvm_cbe_storemerge23__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  unsigned long long llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  signed int *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  unsigned long long llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned long long llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned long long llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  signed int *llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2_2e_lcssa_count = 0;
  unsigned int llvm_cbe_storemerge2_2e_lcssa;
  unsigned int llvm_cbe_storemerge2_2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_ntt\n");
  llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned int )128u;   /* for PHI node */
  llvm_cbe_tmp__1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge5 = phi i32 [ 128, %%0 ], [ %%29, %%28  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_storemerge5_count);
  llvm_cbe_storemerge5 = (unsigned int )llvm_cbe_storemerge5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge5 = 0x%X",llvm_cbe_storemerge5);
printf("\n = 0x%X",128u);
printf("\n = 0x%X",llvm_cbe_tmp__24);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = phi i32 [ 0, %%0 ], [ %%4, %%28  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__1 = (unsigned int )llvm_cbe_tmp__1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__3);
}
  llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__1;   /* for PHI node */
  goto llvm_cbe_tmp__25;

llvm_cbe_tmp__26:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = lshr i32 %%storemerge5, 1, !dbg !5 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_storemerge5&4294967295ull)) >> ((unsigned int )(1u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__24&4294967295ull)));
  if (((llvm_cbe_tmp__24&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__27;
  } else {
    llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__24;   /* for PHI node */
    llvm_cbe_tmp__1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__3;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__25:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i32 [ 0, %%.preheader ], [ %%26, %%._crit_edge  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned int )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%X",llvm_cbe_storemerge14);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__23);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = phi i32 [ %%1, %%.preheader ], [ %%4, %%._crit_edge  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_22_count);
  llvm_cbe_tmp__2 = (unsigned int )llvm_cbe_tmp__2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__2);
printf("\n = 0x%X",llvm_cbe_tmp__1);
printf("\n = 0x%X",llvm_cbe_tmp__3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add i32 %%3, 1, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__3 = (unsigned int )((unsigned int )(llvm_cbe_tmp__2&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__3&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = zext i32 %%4 to i64, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__4 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__3&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds [256 x i32]* @aesl_internal_zetas, i64 0, i64 %%5, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__5 = (signed int *)(&aesl_internal_zetas[(((signed long long )llvm_cbe_tmp__4))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__4));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__4) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_zetas' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i32* %%6, align 4, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__6 = (unsigned int )*llvm_cbe_tmp__5;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i32 %%storemerge14, %%storemerge5, !dbg !5 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__7 = (unsigned int )((unsigned int )(llvm_cbe_storemerge14&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge5&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__7&4294967295ull)));
  if ((((unsigned int )llvm_cbe_storemerge14&4294967295U) < ((unsigned int )llvm_cbe_tmp__7&4294967295U))) {
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe_storemerge2_2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge14;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2.lcssa = phi i32 [ %%storemerge14, %%2 ], [ %%8, %%11  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_storemerge2_2e_lcssa_count);
  llvm_cbe_storemerge2_2e_lcssa = (unsigned int )llvm_cbe_storemerge2_2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2.lcssa = 0x%X",llvm_cbe_storemerge2_2e_lcssa);
printf("\nstoremerge14 = 0x%X",llvm_cbe_storemerge14);
printf("\n = 0x%X",llvm_cbe_tmp__7);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i32 %%storemerge2.lcssa, %%storemerge5, !dbg !5 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__23 = (unsigned int )((unsigned int )(llvm_cbe_storemerge2_2e_lcssa&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge5&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__23&4294967295ull)));
  if ((((unsigned int )llvm_cbe_tmp__23&4294967295U) < ((unsigned int )256u&4294967295U))) {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__23;   /* for PHI node */
    llvm_cbe_tmp__2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__3;   /* for PHI node */
    goto llvm_cbe_tmp__25;
  } else {
    goto llvm_cbe_tmp__26;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__28:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23 = phi i32 [ %%storemerge14, %%.lr.ph ], [ %%25, %%11  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_storemerge23_count);
  llvm_cbe_storemerge23 = (unsigned int )llvm_cbe_storemerge23__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%X",llvm_cbe_storemerge23);
printf("\nstoremerge14 = 0x%X",llvm_cbe_storemerge14);
printf("\n = 0x%X",llvm_cbe_tmp__22);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i32 %%storemerge23, %%storemerge5, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__9 = (unsigned int )((unsigned int )(llvm_cbe_storemerge23&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge5&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__9&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = zext i32 %%12 to i64, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__10 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__9&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i32* %%a, i64 %%13, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__11 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__10))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__10));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* %%14, align 4, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__12 = (unsigned int )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i32 %%15 to i64, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__13 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = mul nsw i64 %%16, %%10, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__14 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__13&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__8&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__14&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = tail call i32 @pqcrystals_dilithium3_ref_montgomery_reduce(i64 %%17) nounwind, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__15 = (unsigned int ) /*tail*/ pqcrystals_dilithium3_ref_montgomery_reduce(llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__14);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__15);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = zext i32 %%storemerge23 to i64, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__16 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge23&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds i32* %%a, i64 %%19, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__17 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__16))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__16));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i32* %%20, align 4, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__18 = (unsigned int )*llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = sub nsw i32 %%21, %%18, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__19 = (unsigned int )((unsigned int )(llvm_cbe_tmp__18&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__15&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__19&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%22, i32* %%14, align 4, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_51_count);
  *llvm_cbe_tmp__11 = llvm_cbe_tmp__19;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i32* %%20, align 4, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__20 = (unsigned int )*llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add nsw i32 %%23, %%18, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_53_count);
  llvm_cbe_tmp__21 = (unsigned int )((unsigned int )(llvm_cbe_tmp__20&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__15&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__21&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%24, i32* %%20, align 4, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_54_count);
  *llvm_cbe_tmp__17 = llvm_cbe_tmp__21;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i32 %%storemerge23, 1, !dbg !5 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__22 = (unsigned int )((unsigned int )(llvm_cbe_storemerge23&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__22&4294967295ull)));
  if (((llvm_cbe_tmp__22&4294967295U) == (llvm_cbe_tmp__7&4294967295U))) {
    llvm_cbe_storemerge2_2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__7;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__22;   /* for PHI node */
    goto llvm_cbe_tmp__28;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sext i32 %%7 to i64, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_ntt  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__8 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__8);
  llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge14;   /* for PHI node */
  goto llvm_cbe_tmp__28;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__27:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_ntt}\n");
  return;
}


void pqcrystals_dilithium3_ref_invntt_tomont(signed int *llvm_cbe_a) {
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_storemerge8_count = 0;
  unsigned int llvm_cbe_storemerge8;
  unsigned int llvm_cbe_storemerge8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  unsigned int llvm_cbe_tmp__29;
  unsigned int llvm_cbe_tmp__29__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge27_count = 0;
  unsigned int llvm_cbe_storemerge27;
  unsigned int llvm_cbe_storemerge27__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned int llvm_cbe_tmp__30;
  unsigned int llvm_cbe_tmp__30__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  signed int *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned int llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned long long llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge35_count = 0;
  unsigned int llvm_cbe_storemerge35;
  unsigned int llvm_cbe_storemerge35__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  unsigned long long llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  signed int *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  unsigned int llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  unsigned long long llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  signed int *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned long long llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned long long llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  unsigned int llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned int llvm_cbe_tmp__51;
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
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond9_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_2e_lcssa_count = 0;
  unsigned int llvm_cbe_storemerge3_2e_lcssa;
  unsigned int llvm_cbe_storemerge3_2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  unsigned int llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned int llvm_cbe_storemerge14;
  unsigned int llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  unsigned long long llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  signed int *llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  unsigned long long llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  unsigned long long llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  unsigned int llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @pqcrystals_dilithium3_ref_invntt_tomont\n");
  llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  llvm_cbe_tmp__29__PHI_TEMPORARY = (unsigned int )256u;   /* for PHI node */
  goto llvm_cbe__2e_preheader6;

  do {     /* Syntactic loop '.preheader6' to make GCC happy */
llvm_cbe__2e_preheader6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8 = phi i32 [ 1, %%0 ], [ %%30, %%29  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_storemerge8_count);
  llvm_cbe_storemerge8 = (unsigned int )llvm_cbe_storemerge8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",llvm_cbe_tmp__53);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = phi i32 [ 256, %%0 ], [ %%4, %%29  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__29 = (unsigned int )llvm_cbe_tmp__29__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__29);
printf("\n = 0x%X",256u);
printf("\n = 0x%X",llvm_cbe_tmp__31);
}
  llvm_cbe_storemerge27__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__30__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__29;   /* for PHI node */
  goto llvm_cbe_tmp__61;

llvm_cbe_tmp__62:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = shl i32 %%storemerge8, 1, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__53 = (unsigned int )llvm_cbe_storemerge8 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__53);
  if ((((unsigned int )llvm_cbe_tmp__53&4294967295U) < ((unsigned int )256u&4294967295U))) {
    llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__53;   /* for PHI node */
    llvm_cbe_tmp__29__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__31;   /* for PHI node */
    goto llvm_cbe__2e_preheader6;
  } else {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__61:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge27 = phi i32 [ 0, %%.preheader6 ], [ %%27, %%._crit_edge  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_storemerge27_count);
  llvm_cbe_storemerge27 = (unsigned int )llvm_cbe_storemerge27__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge27 = 0x%X",llvm_cbe_storemerge27);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__52);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = phi i32 [ %%1, %%.preheader6 ], [ %%4, %%._crit_edge  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__30 = (unsigned int )llvm_cbe_tmp__30__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__30);
printf("\n = 0x%X",llvm_cbe_tmp__29);
printf("\n = 0x%X",llvm_cbe_tmp__31);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add i32 %%3, -1, !dbg !5 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__31 = (unsigned int )((unsigned int )(llvm_cbe_tmp__30&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__31&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = zext i32 %%4 to i64, !dbg !5 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_112_count);
  llvm_cbe_tmp__32 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__31&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds [256 x i32]* @aesl_internal_zetas, i64 0, i64 %%5, !dbg !5 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_113_count);
  llvm_cbe_tmp__33 = (signed int *)(&aesl_internal_zetas[(((signed long long )llvm_cbe_tmp__32))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__32));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__32) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_zetas' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i32* %%6, align 4, !dbg !5 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__34 = (unsigned int )*llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sub nsw i32 0, %%7, !dbg !5 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__35 = (unsigned int )-(llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__35&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i32 %%storemerge27, %%storemerge8, !dbg !5 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__36 = (unsigned int )((unsigned int )(llvm_cbe_storemerge27&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge8&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__36&4294967295ull)));
  if ((((unsigned int )llvm_cbe_storemerge27&4294967295U) < ((unsigned int )llvm_cbe_tmp__36&4294967295U))) {
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe_storemerge3_2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge27;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3.lcssa = phi i32 [ %%storemerge27, %%2 ], [ %%9, %%12  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_storemerge3_2e_lcssa_count);
  llvm_cbe_storemerge3_2e_lcssa = (unsigned int )llvm_cbe_storemerge3_2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3.lcssa = 0x%X",llvm_cbe_storemerge3_2e_lcssa);
printf("\nstoremerge27 = 0x%X",llvm_cbe_storemerge27);
printf("\n = 0x%X",llvm_cbe_tmp__36);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add i32 %%storemerge3.lcssa, %%storemerge8, !dbg !5 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_159_count);
  llvm_cbe_tmp__52 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3_2e_lcssa&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge8&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__52&4294967295ull)));
  if ((((unsigned int )llvm_cbe_tmp__52&4294967295U) < ((unsigned int )256u&4294967295U))) {
    llvm_cbe_storemerge27__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__52;   /* for PHI node */
    llvm_cbe_tmp__30__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__31;   /* for PHI node */
    goto llvm_cbe_tmp__61;
  } else {
    goto llvm_cbe_tmp__62;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__63:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge35 = phi i32 [ %%storemerge27, %%.lr.ph ], [ %%26, %%12  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_storemerge35_count);
  llvm_cbe_storemerge35 = (unsigned int )llvm_cbe_storemerge35__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge35 = 0x%X",llvm_cbe_storemerge35);
printf("\nstoremerge27 = 0x%X",llvm_cbe_storemerge27);
printf("\n = 0x%X",llvm_cbe_tmp__51);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = zext i32 %%storemerge35 to i64, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_124_count);
  llvm_cbe_tmp__38 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge35&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i32* %%a, i64 %%13, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__39 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__38))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__38));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* %%14, align 4, !dbg !3 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__40 = (unsigned int )*llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i32 %%storemerge35, %%storemerge8, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__41 = (unsigned int )((unsigned int )(llvm_cbe_storemerge35&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge8&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__41&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = zext i32 %%16 to i64, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__42 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__41&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds i32* %%a, i64 %%17, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_132_count);
  llvm_cbe_tmp__43 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__42))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__42));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i32* %%18, align 4, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_133_count);
  llvm_cbe_tmp__44 = (unsigned int )*llvm_cbe_tmp__43;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add nsw i32 %%19, %%15, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_134_count);
  llvm_cbe_tmp__45 = (unsigned int )((unsigned int )(llvm_cbe_tmp__44&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__40&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__45&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%20, i32* %%14, align 4, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_135_count);
  *llvm_cbe_tmp__39 = llvm_cbe_tmp__45;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i32* %%18, align 4, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__46 = (unsigned int )*llvm_cbe_tmp__43;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = sub nsw i32 %%15, %%21, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__47 = (unsigned int )((unsigned int )(llvm_cbe_tmp__40&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__46&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__47&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%22, i32* %%18, align 4, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_138_count);
  *llvm_cbe_tmp__43 = llvm_cbe_tmp__47;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sext i32 %%22 to i64, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__48 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = mul nsw i64 %%23, %%11, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__49 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__48&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__37&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__49&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = tail call i32 @pqcrystals_dilithium3_ref_montgomery_reduce(i64 %%24) nounwind, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__50 = (unsigned int ) /*tail*/ pqcrystals_dilithium3_ref_montgomery_reduce(llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__49);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__50);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%25, i32* %%18, align 4, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_142_count);
  *llvm_cbe_tmp__43 = llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i32 %%storemerge35, 1, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__51 = (unsigned int )((unsigned int )(llvm_cbe_storemerge35&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__51&4294967295ull)));
  if (((llvm_cbe_tmp__51&4294967295U) == (llvm_cbe_tmp__36&4294967295U))) {
    llvm_cbe_storemerge3_2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__36;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge35__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__51;   /* for PHI node */
    goto llvm_cbe_tmp__63;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%8 to i64, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__37 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__37);
  llvm_cbe_storemerge35__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge27;   /* for PHI node */
  goto llvm_cbe_tmp__63;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader6' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i32 [ %%38, %%.preheader ], [ 0, %%29  for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned int )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%X",llvm_cbe_storemerge14);
printf("\n = 0x%X",llvm_cbe_tmp__60);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = zext i32 %%storemerge14 to i64, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__54 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge14&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds i32* %%a, i64 %%32, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__55 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__54))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__54));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i32* %%33, align 4, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__56 = (unsigned int )*llvm_cbe_tmp__55;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = sext i32 %%34 to i64, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__57 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = mul nsw i64 %%35, 41978, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__58 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__57&18446744073709551615ull)) * ((unsigned long long )(41978ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__58&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = tail call i32 @pqcrystals_dilithium3_ref_montgomery_reduce(i64 %%36) nounwind, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__59 = (unsigned int ) /*tail*/ pqcrystals_dilithium3_ref_montgomery_reduce(llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__58);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__59);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%37, i32* %%33, align 4, !dbg !4 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_181_count);
  *llvm_cbe_tmp__55 = llvm_cbe_tmp__59;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = add i32 %%storemerge14, 1, !dbg !6 for 0x%I64xth hint within @pqcrystals_dilithium3_ref_invntt_tomont  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__60 = (unsigned int )((unsigned int )(llvm_cbe_storemerge14&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__60&4294967295ull)));
  if (((llvm_cbe_tmp__60&4294967295U) == (256u&4294967295U))) {
    goto llvm_cbe_tmp__64;
  } else {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__60;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__64:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @pqcrystals_dilithium3_ref_invntt_tomont}\n");
  return;
}

