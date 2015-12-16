using std::cout;  using std::cerr;  using std::endl;

#ifndef __CPP__INCLUDED__RPerl__DataType__GMPInteger_cpp
#define __CPP__INCLUDED__RPerl__DataType__GMPInteger_cpp 0.001_000

// [[[ INCLUDES ]]]
#include <RPerl/DataType/GMPInteger.h>		// -> NULL (relies on native C type)
#include <RPerl/Operation/Expression/Operator/GMPFunctions.cpp>  // -> GMPFunctions.h
// DEV NOTE, CORRELATION #rp12: the only actual includes-level dependency between any of the RPerl core data types should be String.cpp to avoid
// error: ‘XS_pack_string’ was not declared in this scope
#include <RPerl/DataType/String.cpp>  // -> String.h

// NEED FIX: update #rp12 above???  need XS_pack_integer() for retval of gmp_integer_to_integer()
#include <RPerl/DataType/Integer.cpp>  // -> Integer.h

// [[[ TYPE-CHECKING ]]]
// [[[ TYPE-CHECKING ]]]
// [[[ TYPE-CHECKING ]]]

void gmp_integer_CHECK(SV* possible_gmp_integer)
{
    if ( not( SvOK(possible_gmp_integer) ) ) { croak( "\nERROR EGIV00, TYPE-CHECKING MISMATCH, CPPOPS_PERLTYPES & CPPOPS_CPPTYPES:\ngmp_integer value expected but undefined/null value found,\ncroaking" ); }
    if ( not( SvHROKp(possible_gmp_integer) ) ) { croak( "\nERROR EGIV01, TYPE-CHECKING MISMATCH, CPPOPS_PERLTYPES & CPPOPS_CPPTYPES:\ngmp_integer value expected but non-hashref value found,\ncroaking" ); }

    HV* possible_gmp_integer_deref = (HV*)SvRV(possible_gmp_integer);

    if (not hv_exists(possible_gmp_integer_deref, (const char*) "value", (U32) 5)) {
        croak("\nERROR EGIV02, MISSING HASH ENTRY, CPPOPS_PERLTYPES & CPPOPS_CPPTYPES:\ngmp_integer object in hash entry expected at key 'value' but no hash entry exists,\ncroaking");
    }

    SV** possible_gmp_integer_value_ptr = hv_fetch(possible_gmp_integer_deref, (const char*) "value", (U32) 5, (I32) 0);

    if (possible_gmp_integer_value_ptr == NULL) {
        croak("\nERROR EGIV03, MISSING HASH ENTRY, CPPOPS_PERLTYPES & CPPOPS_CPPTYPES:\nhash entry expected at key 'value' but no hash entry defined,\ncroaking");
    }

    // DEV NOTE: PERLTYPES gmp_integer is a wrapper around PERLTYPES Math::BigInt::GMP, which is a wrapper around C gmp_integer,
    // so we can directly access the underlying C gmp_integer, nice!
//    gmp_integer possible_gmp_integer_value = *possible_gmp_integer_value_ptr;
//    gmp_get_signed_integer(possible_gmp_integer_value);
//    gmp_get_signed_integer(*possible_gmp_integer_value_ptr);

    // NEED FIX: is this the only way to check if the variable is actually a gmp_integer type?
    // I'm assuming the static types of C/C++ will give a compiler and/or runtime error on one of the two preceding lines of code if our var is not really a gmp_integer...
}

void gmp_integer_CHECKTRACE(SV* possible_gmp_integer, const char* variable_name, const char* subroutine_name)
{
    if ( not( SvOK(possible_gmp_integer) ) ) { croak( "\nERROR EGIV00, TYPE-CHECKING MISMATCH, CPPOPS_PERLTYPES & CPPOPS_CPPTYPES:\ngmp_integer value expected but undefined/null value found,\nin variable %s from subroutine %s,\ncroaking", variable_name, subroutine_name ); }
    if ( not( SvHROKp(possible_gmp_integer) ) ) { croak( "\nERROR EGIV01, TYPE-CHECKING MISMATCH, CPPOPS_PERLTYPES & CPPOPS_CPPTYPES:\ngmp_integer value expected but non-hashref value found,\nin variable %s from subroutine %s,\ncroaking", variable_name, subroutine_name ); }

    HV* possible_gmp_integer_deref = (HV*)SvRV(possible_gmp_integer);

    if (not hv_exists(possible_gmp_integer_deref, (const char*) "value", (U32) 5)) {
        croak("\nERROR EGIV02, MISSING HASH ENTRY, CPPOPS_PERLTYPES & CPPOPS_CPPTYPES:\ngmp_integer object in hash entry expected at key 'value' but no hash entry exists,\nin variable %s from subroutine %s,\ncroaking", variable_name, subroutine_name );
    }

    SV** possible_gmp_integer_value_ptr = hv_fetch(possible_gmp_integer_deref, (const char*) "value", (U32) 5, (I32) 0);

    if (possible_gmp_integer_value_ptr == NULL) {
        croak("\nERROR EGIV03, MISSING HASH ENTRY, CPPOPS_PERLTYPES & CPPOPS_CPPTYPES:\nhash entry expected at key 'value' but no hash entry defined,\nin variable %s from subroutine %s,\ncroaking", variable_name, subroutine_name );
    }

    // DEV NOTE: PERLTYPES gmp_integer is a wrapper around PERLTYPES Math::BigInt::GMP, which is a wrapper around C gmp_integer,
    // so we can directly access the underlying C gmp_integer, nice!
//    gmp_get_signed_integer(*possible_gmp_integer_value_ptr);

    // NEED FIX: is this the only way to check if the variable is actually a gmp_integer type?
    // I'm assuming the static types of C/C++ will give a compiler and/or runtime error on one of the two preceding lines of code if our var is not really a gmp_integer...
}

// [[[ TYPEMAP PACK/UNPACK FOR __CPP__TYPES ]]]
// [[[ TYPEMAP PACK/UNPACK FOR __CPP__TYPES ]]]
// [[[ TYPEMAP PACK/UNPACK FOR __CPP__TYPES ]]]

# ifdef __CPP__TYPES

/* DISABLE RETVAL VERSION
// convert from (Perl SV containing reference to (Perl HV containing reference to C gmp_integer)) to (C gmp_integer_retval)
gmp_integer_retval XS_unpack_gmp_integer_retval(SV* input_sv)
{
    fprintf(stderr, "in CPPOPS_CPPTYPES XS_unpack_gmp_integer_retval(), top of subroutine\n");
//  gmp_integer_CHECK(input_sv);
//    gmp_integer_CHECKTRACE(input_sv, "input_sv", "XS_unpack_gmp_integer_retval()");

    gmp_integer_retval output_gmp_integer_retval;

    gmp_integer_rawptr FOO = sv_to_gmp_integer_rawptr(input_sv);
    gmp_integer BAR;
    BAR[1] = *FOO[1];
    output_gmp_integer_retval = (gmp_integer_retval) BAR;

    cerr << "in CPPOPS_CPPTYPES XS_unpack_gmp_integer_retval(), have gmp_get_signed_integer(output_gmp_integer_retval) = " <<
            gmp_get_signed_integer(output_gmp_integer_retval.gmp_integer_unretval()) << endl;

    fprintf(stderr, "in CPPOPS_CPPTYPES XS_unpack_gmp_integer_retval(), bottom of subroutine\n");

    return output_gmp_integer_retval;
}
*/

/* FIX OR REPLACE
// convert from (Perl SV containing reference to (Perl HV containing reference to C gmp_integer)) to (C gmp_integer_retval)
gmp_integer_rawptr XS_unpack_gmp_integer_rawptr(SV* input_sv)
{
    fprintf(stderr, "in CPPOPS_CPPTYPES XS_unpack_gmp_integer_rawptr(), top of subroutine\n");
//  gmp_integer_CHECK(input_sv);
//    gmp_integer_CHECKTRACE(input_sv, "input_sv", "XS_unpack_gmp_integer_rawptr()");

    gmp_integer_rawptr output_gmp_integer_rawptr;

    gmp_integer_rawptr FOO = sv_to_gmp_integer_rawptr(input_sv);

    cerr << "in CPPOPS_CPPTYPES XS_unpack_gmp_integer_rawptr(), have gmp_get_signed_integer(*output_gmp_integer_rawptr) = " <<
            gmp_get_signed_integer(*output_gmp_integer_rawptr) << endl;

    fprintf(stderr, "in CPPOPS_CPPTYPES XS_unpack_gmp_integer_rawptr(), bottom of subroutine\n");

    return output_gmp_integer_rawptr;
}
*/

/* NEED FIX AND TEST
// convert from (C gmp_integer_retval) to (Perl SV containing reference to (Perl HV containing reference to C gmp_integer))
void XS_pack_gmp_integer_retval(SV* output_hv_ref, gmp_integer_retval input_gmp_integer_retval)
{
//  fprintf(stderr, "in CPPOPS_CPPTYPES XS_pack_gmp_integer(), top of subroutine\n");

    HV* output_hv = newHV();  // initialize output hash to empty
    SV* temp_sv_pointer;

/ *
    hv_store(output_hv, (const char*) "value", (U32) 5, &input_gmp_integer, (U32)0);

    temp_sv_pointer = newSVrv(output_hv_ref, NULL);   // upgrade output stack SV to an RV
    SvREFCNT_dec(temp_sv_pointer);       // discard temporary pointer
    SvRV(output_hv_ref) = (SV*)output_hv;      // make output stack RV pointer at our output HV
* /

//  fprintf(stderr, "in CPPOPS_CPPTYPES XS_pack_gmp_integer(), bottom of subroutine\n");
}
*/

/* FIX OR REPLACE
//mpz_t* sv_to_mpz_t(SV* input_sv)
gmp_integer_rawptr sv_to_gmp_integer_rawptr(SV* input_sv)
{
    cout << "in GMPInteger.cpp sv_to_gmp_integer_rawptr(), top of subroutine" << endl;
    MAGIC* mg;
    cout << "in GMPInteger.cpp sv_to_gmp_integer_rawptr(), after declaration of MAGIC* mg" << endl;
    if (!sv_derived_from(input_sv, "Math::BigInt::GMP")) {
        croak("not of type Math::BigInt::GMP");
    }
    mg = SvMAGIC(SvRV(input_sv));
    cout << "in GMPInteger.cpp sv_to_gmp_integer_rawptr(), have input_sv = " << input_sv << endl;
    cout << "in GMPInteger.cpp sv_to_gmp_integer_rawptr(), have SvRV(input_sv) = " << SvRV(input_sv) << endl;
    cout << "in GMPInteger.cpp sv_to_gmp_integer_rawptr(), have SvMAGIC(SvRV(input_sv)) = " << SvMAGIC(SvRV(input_sv)) << endl;
    cout << "in GMPInteger.cpp sv_to_gmp_integer_rawptr(), after setting mg = SvMAGIC(SvRV(input_sv))" << endl;
    cout << "in GMPInteger.cpp sv_to_gmp_integer_rawptr(), have mg = " << mg << endl;
//    gmp_integer_rawptr retval = (gmp_integer_rawptr) mg->mg_ptr;
    gmp_integer_rawptr retval;
    cout << "in GMPInteger.cpp sv_to_gmp_integer_rawptr(), after declaration of gmp_integer_rawptr retval" << endl;
    cout << "in GMPInteger.cpp sv_to_gmp_integer_rawptr(), have mg->mg_ptr = " << mg->mg_ptr << endl;
    retval = (gmp_integer_rawptr) mg->mg_ptr;
//    retval = mg->mg_ptr;
    cout << "in GMPInteger.cpp sv_to_gmp_integer_rawptr(), after initializing gmp_integer_rawptr retval = (gmp_integer_rawptr) mg->mg_ptr;" << endl;
    return retval;
//    return (gmp_integer_rawptr) mg->mg_ptr;
}
*/





// UPGRADE TO PROPER MACROS, TYPE NAMES, ETC.
mpz_t * mpz_from_sv_nofail (SV *sv)
{
  MAGIC *mg;

  if (!sv_derived_from(sv, "Math::BigInt::GMP"))
    croak("not of type Math::BigInt::GMP");

  mg = SvMAGIC(SvRV(sv));

  return (mpz_t *)mg->mg_ptr;
}

// DELETE AFTER TESTING FINISHED
void _my_mul(SV * bi_rop, SV * bi_op, SV * si, SV * rop_sign, SV * op_sign) {
     mpz_t *t1, *t2;

     sv_setpv(rop_sign, SvPV_nolen(op_sign));

     t1 = mpz_from_sv_nofail(bi_rop);
     t2 = mpz_from_sv_nofail(bi_op);

     mpz_abs(*t2, *t2);
     mpz_mul_si(*t1, *t2, abs(SvIV(si)));

     if(SvIV(si) < 0) {
       if(strEQ(SvPV_nolen(op_sign), "-")) sv_setpv(rop_sign, "+");
       else sv_setpv(rop_sign, "-");
     }
}







# endif

// [[[ BOOLIFY ]]]
// [[[ BOOLIFY ]]]
// [[[ BOOLIFY ]]]

# ifdef __PERL__TYPES

SV* gmp_integer_to_bool(SV* input_gmp_integer) {
//  gmp_integer_CHECK(input_gmp_integer);
    gmp_integer_CHECKTRACE(input_gmp_integer, "input_gmp_integer", "gmp_integer_to_bool()");
    // NEED ADD CODE
}

# elif defined __CPP__TYPES

bool gmp_integer_to_bool(gmp_integer input_gmp_integer) {
    if (gmp_get_signed_integer(input_gmp_integer) == 0) { return 0; }
    else { return 1; }
}

# endif

// [[[ UNSIGNED INTEGERIFY ]]]
// [[[ UNSIGNED INTEGERIFY ]]]
// [[[ UNSIGNED INTEGERIFY ]]]

# ifdef __PERL__TYPES

SV* gmp_integer_to_unsigned_integer(SV* input_gmp_integer) {
//  gmp_integer_CHECK(input_gmp_integer);
    gmp_integer_CHECKTRACE(input_gmp_integer, "input_gmp_integer", "gmp_integer_to_unsigned_integer()");
    // NEED ADD CODE
}

# elif defined __CPP__TYPES

unsigned_integer gmp_integer_to_unsigned_integer(gmp_integer input_gmp_integer) {
    return abs(gmp_get_signed_integer(input_gmp_integer));
}

# endif

// [[[ INTEGERIFY ]]]
// [[[ INTEGERIFY ]]]
// [[[ INTEGERIFY ]]]

# ifdef __PERL__TYPES

/* DISABLED
SV* gmp_integer_to_integer(SV* input_gmp_integer) {
//  gmp_integer_CHECK(input_gmp_integer);
    gmp_integer_CHECKTRACE(input_gmp_integer, "input_gmp_integer", "gmp_integer_to_integer()");
    // NEED ADD CODE
}
*/

# elif defined __CPP__TYPES

//integer gmp_integer_to_integer(gmp_integer_rawptr input_gmp_integer_rawptr) {
//    return gmp_get_signed_integer(*input_gmp_integer_rawptr);
//}
//integer gmp_integer_to_integer(gmp_integer_retval input_gmp_integer_retval) {
//    return gmp_get_signed_integer(input_gmp_integer_retval.gmp_integer_unretval());
//}

/* GOOD STAND-ALONE
integer gmp_integer_to_integer(SV* input_sv_rawptr) {
     cout << "in gmp_integer_to_integer(), top of subroutine..." << endl;

     gmp_integer_rawptr tmp_gmp_integer_rawptr;

     tmp_gmp_integer_rawptr = mpz_from_sv_nofail(input_sv_rawptr);

     integer retval = gmp_get_signed_integer(*tmp_gmp_integer_rawptr);
     cout << "in gmp_integer_to_integer(), have retval = " << retval << endl;
     cout << "in gmp_integer_to_integer(), bottom of subroutine..." << endl;

     return retval;
}
*/

// START HERE: GET THIS TO WORK!!!
// START HERE: GET THIS TO WORK!!!
// START HERE: GET THIS TO WORK!!!

/* NEED THIS TO WORK!
gmp_integer_rawptr XS_unpack_gmp_integer_rawptr(SV* input_sv_rawptr) {
    cout << "in XS_unpack_gmp_integer_rawptr(), top of subroutine..." << endl;

    gmp_integer_rawptr tmp_gmp_integer_rawptr;

    tmp_gmp_integer_rawptr = mpz_from_sv_nofail(input_sv_rawptr);
    cout << "in XS_unpack_gmp_integer_rawptr(), bottom of subroutine..." << endl;

    return tmp_gmp_integer_rawptr;
}

integer gmp_integer_to_integer(gmp_integer_rawptr input_gmp_integer_rawptr) {
     cout << "in gmp_integer_to_integer(), top of subroutine..." << endl;

     integer retval = gmp_get_signed_integer(*input_gmp_integer_rawptr);
     cout << "in gmp_integer_to_integer(), have retval = " << retval << endl;
     cout << "in gmp_integer_to_integer(), bottom of subroutine..." << endl;

     return retval;
}
*/


# endif

// [[[ NUMBERIFY ]]]
// [[[ NUMBERIFY ]]]
// [[[ NUMBERIFY ]]]

# ifdef __PERL__TYPES

SV* gmp_integer_to_number(SV* input_gmp_integer) {
//  gmp_integer_CHECK(input_gmp_integer);
    gmp_integer_CHECKTRACE(input_gmp_integer, "input_gmp_integer", "gmp_integer_to_number()");
    // NEED ADD CODE
}

# elif defined __CPP__TYPES

number gmp_integer_to_number(gmp_integer input_gmp_integer) {
    return (double) gmp_get_signed_integer(input_gmp_integer);
}

# endif

// [[[ CHARIFY ]]]
// [[[ CHARIFY ]]]
// [[[ CHARIFY ]]]

# ifdef __PERL__TYPES

SV* gmp_integer_to_char(SV* input_gmp_integer) {
//  gmp_integer_CHECK(input_gmp_integer);
    gmp_integer_CHECKTRACE(input_gmp_integer, "input_gmp_integer", "gmp_integer_to_char()");
    // NEED ADD CODE
}

# elif defined __CPP__TYPES

// DEV NOTE, CORRELATION #rp10: shim CPPTYPES sub
char gmp_integer_to_char(gmp_integer input_gmp_integer) {
    return gmp_integer_to_string_CPPTYPES(input_gmp_integer).at(0);
}

# endif

// [[[ STRINGIFY ]]]
// [[[ STRINGIFY ]]]
// [[[ STRINGIFY ]]]

# ifdef __PERL__TYPES

SV* gmp_integer_to_string(SV* input_gmp_integer) {
//	gmp_integer_CHECK(input_gmp_integer);
	gmp_integer_CHECKTRACE(input_gmp_integer, "input_gmp_integer", "gmp_integer_to_string()");
	// NEED ADD CODE
}

# elif defined __CPP__TYPES

// DEV NOTE, CORRELATION #rp10: shim CPPTYPES sub
string gmp_integer_to_string(gmp_integer input_gmp_integer) {
    return gmp_integer_to_string_CPPTYPES(input_gmp_integer);
}

# endif

/* DISABLED
// DEV NOTE, CORRELATION #rp09: must use return type 'string' instead of 'std::string' for proper typemap pack/unpack function name alignment;
// can cause silent failure, falling back to __PERL__TYPES implementation and NOT failure of tests!
// DEV NOTE, CORRELATION #rp10: the real CPPTYPES sub (below) is called by the wrapper PERLTYPES sub and shim CPPTYPES subs (above), moved outside #ifdef blocks
string gmp_integer_to_string_CPPTYPES(gmp_integer input_gmp_integer)
{
//    fprintf(stderr, "in CPPOPS_CPPTYPES gmp_integer_to_string_CPPTYPES(), top of subroutine, received unformatted input_gmp_integer = %d\n", input_gmp_integer);
//    fprintf(stderr, "in CPPOPS_CPPTYPES gmp_integer_to_string_CPPTYPES()...\n");

    std::ostringstream output_stream;
    output_stream.precision(std::numeric_limits<double>::digits10);
    output_stream << gmp_get_signed_integer(input_gmp_integer);

    // DEV NOTE: disable old stringify w/out underscores
//  return(output_stream.str());

    string output_string = output_stream.str();
//    fprintf(stderr, "in CPPOPS_CPPTYPES gmp_integer_to_string_CPPTYPES(), have output_string = %s\n", output_string.c_str());

    bool is_negative = 0;
    if (input_gmp_integer < 0) { is_negative = 1; }

    std::reverse(output_string.begin(), output_string.end());

//    fprintf(stderr, "in CPPOPS_CPPTYPES gmp_integer_to_string_CPPTYPES(), have reversed output_string = %s\n", output_string.c_str());
    if (is_negative) { output_string.pop_back(); }  // remove negative sign

    string output_string_underscores = "";
    for(std::string::size_type i = 0; i < output_string.size(); ++i) {
//        fprintf(stderr, "in CPPOPS_CPPTYPES gmp_integer_to_string_CPPTYPES(), inside output_string underscore loop, have i = %d, output_string[i] = %c\n", (int)i, output_string[i]);
        output_string_underscores += output_string[i];
        if (((i % 3) == 2) && (i > 0) && (i != (output_string.size() - 1))) {
//            fprintf(stderr, "in CPPOPS_CPPTYPES gmp_integer_to_string_CPPTYPES(), AND UNDERSCORE \n");
            output_string_underscores += '_';
        }
    }

//    fprintf(stderr, "in CPPOPS_CPPTYPES gmp_integer_to_string_CPPTYPES(), have reversed output_string_underscores = %s\n", output_string_underscores.c_str());

    std::reverse(output_string_underscores.begin(), output_string_underscores.end());

    if (output_string_underscores == "") {
        output_string_underscores = "0";
    }

//    fprintf(stderr, "in CPPOPS_CPPTYPES gmp_integer_to_string_CPPTYPES(), have unreversed output_string_underscores = %s\n", output_string_underscores.c_str());

    if (is_negative) { output_string_underscores = '-' + output_string_underscores; }

    return output_string_underscores;
}
*/

// [[[ TYPE TESTING ]]]
// [[[ TYPE TESTING ]]]
// [[[ TYPE TESTING ]]]

# ifdef __PERL__TYPES

SV* gmp_integer__typetest0() {
    // NEED ADD CODE
}

SV* gmp_integer__typetest1(SV* lucky_gmp_integer) {
//	gmp_integer_CHECK(lucky_gmp_integer);
	gmp_integer_CHECKTRACE(lucky_gmp_integer, "lucky_gmp_integer", "gmp_integer__typetest1()");
    // NEED ADD CODE
}

# elif defined __CPP__TYPES

//gmp_integer gmp_integer__typetest0() {
string gmp_integer__typetest0() {
	gmp_integer retval;
	gmp_init(retval);
	gmp_set_signed_integer(retval, (21 / 7) + RPerl__DataType__GMPInteger__MODE_ID());
//fprintf(stderr, "in CPPOPS_CPPTYPES gmp_integer__typetest0(), have retval = %d\n", retval);
	return gmp_get_string(retval);
}

//gmp_integer gmp_integer__typetest1(gmp_integer lucky_gmp_integer) {
string gmp_integer__typetest1(gmp_integer lucky_gmp_integer) {
//fprintf(stderr, "in CPPOPS_CPPTYPES gmp_integer__typetest1(), received lucky_gmp_integer = %d\n", lucky_gmp_integer);
	gmp_integer retval;
	gmp_set_signed_integer(retval, (gmp_get_signed_integer(lucky_gmp_integer) * 2) + RPerl__DataType__GMPInteger__MODE_ID());
//	return retval;
	return gmp_get_string(retval);
}

# endif

#endif