#!/usr/bin/perl

# [[[ PREPROCESSOR ]]]
# <<< GENERATE_ERROR: "P185a, CODE GENERATOR, ABSTRACT SYNTAX TO" >>>
# <<< GENERATE_ERROR: "included package or class name '_MyClass_Bad' must not start with an underscore, forbidden by C++ specification as a reserved identifier" >>>

# [[[ HEADER ]]]
use RPerl;
use strict;
use warnings;
our $VERSION = 0.001_000;

# [[[ CRITICS ]]]
## no critic qw(ProhibitUselessNoCritic ProhibitMagicNumbers RequireCheckedSyscalls)  # USER DEFAULT 1: allow numeric values & print operator

# [[[ INCLUDES ]]]
use _MyClass_Bad;

# [[[ SUBROUTINES ]]]
sub _foo_subroutine_in_main {
    { my void $RETURN_TYPE };
    print 'Howdy from _foo_subroutine_in_main()...', "\n";
    return;
}

# [[[ OPERATIONS ]]]
print 'Hello, World!', "\n";
_foo_subroutine_in_main();
