/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of eval_9_d115.xs. Do not edit this file, edit eval_9_d115.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "eval_9_d115.xs"

#define __INLINE_CPP_STANDARD_HEADERS 1
#define __INLINE_CPP_NAMESPACE_STD 1

#define __INLINE_CPP 1
#ifndef bool
#include <iostream>
#endif
extern "C" {
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "INLINE.h"
}
#ifdef bool
#undef bool
#include <iostream>
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <vector>
#include <unordered_map>
# 1 "/home/wbraswell/austin_perl_mongers/rperl/rperl-latest/lib/RPerl/_Inline/build/eval_9_d115/Filters31408.c"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "/home/wbraswell/austin_perl_mongers/rperl/rperl-latest/lib/RPerl/_Inline/build/eval_9_d115/Filters31408.c"



# 1 "/home/wbraswell/austin_perl_mongers/rperl/rperl-latest/lib/RPerl/HelperFunctions.h" 1



# 1 "/home/wbraswell/austin_perl_mongers/rperl/rperl-latest/lib/rperltypes_mode.h" 1
# 5 "/home/wbraswell/austin_perl_mongers/rperl/rperl-latest/lib/RPerl/HelperFunctions.h" 2
# 41 "/home/wbraswell/austin_perl_mongers/rperl/rperl-latest/lib/RPerl/HelperFunctions.h"
int RPerl_SvIOKp(SV* input_sv);
int RPerl_SvNOKp(SV* input_sv);
int RPerl_SvPOKp(SV* input_sv);
int RPerl_SvAROKp(SV* input_av_ref);
int RPerl_SvHROKp(SV* input_hv_ref);

void RPerl_object_property_init(SV* initee);
char* RPerl_DUMPER__perl_from_c(SV* dumpee);





int RPerl__HelperFunctions__MODE_ID() { int retval = 2; return(retval); }
# 5 "/home/wbraswell/austin_perl_mongers/rperl/rperl-latest/lib/RPerl/_Inline/build/eval_9_d115/Filters31408.c" 2


int RPerl_SvIOKp(SV* input_sv) { return(SvIOKp(input_sv)); }
int RPerl_SvNOKp(SV* input_sv) { return(SvNOKp(input_sv)); }
int RPerl_SvPOKp(SV* input_sv) { return(SvPOKp(input_sv)); }
int RPerl_SvAROKp(SV* input_av_ref) { return((SvROK(input_av_ref) && (SvTYPE(SvRV(input_av_ref)) == SVt_PVAV))); }
int RPerl_SvHROKp(SV* input_hv_ref) { return((SvROK(input_hv_ref) && (SvTYPE(SvRV(input_hv_ref)) == SVt_PVHV))); }


void RPerl_object_property_init(SV* initee)
{
 dSP;
 PUSHMARK(SP);
 XPUSHs(initee);
 PUTBACK;
 call_pv("Dumper", G_SCALAR);

}

char* RPerl_DUMPER__perl_from_c(SV* dumpee)
{
        dSP;
        int retcnt;
        char* retval;

        ENTER;
        SAVETMPS;
        PUSHMARK(SP); XPUSHs(dumpee); PUTBACK;
        retcnt = call_pv("RPerl::DUMPER", G_SCALAR);
        SPAGAIN;
        if (retcnt != 1) { croak("RPerl::DUMPER(dumpee) return count is %d, expected 1, croaking", retcnt); }
        retval = POPp; PUTBACK;

        LEAVE;

        return retval;
}

#line 104 "eval_9_d115.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)    S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage        S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 246 "eval_9_d115.c"

XS_EUPXS(XS_main_RPerl_SvIOKp); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_main_RPerl_SvIOKp)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "input_sv");
    {
	SV *	input_sv = ST(0)
;
	int	RETVAL;
	dXSTARG;

	RETVAL = RPerl_SvIOKp(input_sv);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_main_RPerl_SvNOKp); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_main_RPerl_SvNOKp)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "input_sv");
    {
	SV *	input_sv = ST(0)
;
	int	RETVAL;
	dXSTARG;

	RETVAL = RPerl_SvNOKp(input_sv);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_main_RPerl_SvPOKp); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_main_RPerl_SvPOKp)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "input_sv");
    {
	SV *	input_sv = ST(0)
;
	int	RETVAL;
	dXSTARG;

	RETVAL = RPerl_SvPOKp(input_sv);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_main_RPerl_SvAROKp); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_main_RPerl_SvAROKp)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "input_av_ref");
    {
	SV *	input_av_ref = ST(0)
;
	int	RETVAL;
	dXSTARG;

	RETVAL = RPerl_SvAROKp(input_av_ref);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_main_RPerl_SvHROKp); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_main_RPerl_SvHROKp)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "input_hv_ref");
    {
	SV *	input_hv_ref = ST(0)
;
	int	RETVAL;
	dXSTARG;

	RETVAL = RPerl_SvHROKp(input_hv_ref);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_main_RPerl_object_property_init); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_main_RPerl_object_property_init)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "initee");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	initee = ST(0)
;
#line 122 "eval_9_d115.xs"
	I32 *	__temp_markstack_ptr;
#line 356 "eval_9_d115.c"
#line 124 "eval_9_d115.xs"
	__temp_markstack_ptr = PL_markstack_ptr++;
	RPerl_object_property_init(initee);
        if (PL_markstack_ptr != __temp_markstack_ptr) {
          /* truly void, because dXSARGS not invoked */
          PL_markstack_ptr = __temp_markstack_ptr;
          XSRETURN_EMPTY; /* return empty stack */
        }
        /* must have used dXSARGS; list context implied */
        return; /* assume stack size is correct */
#line 367 "eval_9_d115.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_main_RPerl_DUMPER__perl_from_c); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_main_RPerl_DUMPER__perl_from_c)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "dumpee");
    {
	SV *	dumpee = ST(0)
;
	char *	RETVAL;
	dXSTARG;

	RETVAL = RPerl_DUMPER__perl_from_c(dumpee);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_main_RPerl__HelperFunctions__MODE_ID); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_main_RPerl__HelperFunctions__MODE_ID)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	int	RETVAL;
	dXSTARG;

	RETVAL = RPerl__HelperFunctions__MODE_ID();
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_eval_9_d115); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_eval_9_d115)
{
    dVAR; dXSARGS;
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK;

        newXS("main::RPerl_SvIOKp", XS_main_RPerl_SvIOKp, file);
        newXS("main::RPerl_SvNOKp", XS_main_RPerl_SvNOKp, file);
        newXS("main::RPerl_SvPOKp", XS_main_RPerl_SvPOKp, file);
        newXS("main::RPerl_SvAROKp", XS_main_RPerl_SvAROKp, file);
        newXS("main::RPerl_SvHROKp", XS_main_RPerl_SvHROKp, file);
        newXS("main::RPerl_object_property_init", XS_main_RPerl_object_property_init, file);
        newXS("main::RPerl_DUMPER__perl_from_c", XS_main_RPerl_DUMPER__perl_from_c, file);
        newXS("main::RPerl__HelperFunctions__MODE_ID", XS_main_RPerl__HelperFunctions__MODE_ID, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

