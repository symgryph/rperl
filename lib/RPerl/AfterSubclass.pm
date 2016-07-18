# DEV NOTE: all code originally in RPerl.pm, moved here when filter() added, now called in code generated by filter()

# [[[ HEADER ]]]
package RPerl::AfterSubclass;
use strict;
use warnings;
our $VERSION = 0.003_000;

# [[[ INCLUDES ]]]
use RPerl::CompileUnit::Module::Class;
1;  # end of package


# [[[ HEADER ]]]
package RPerl;
use strict;
use warnings;

# [[[ INCLUDES ]]]
use File::Basename;

# [[[ INCLUDES SPECIAL ]]]
require RPerl::Config;
#use RPerl::Config;

#BEGIN { use Data::Dumper; print 'in RPerl::AfterSubclass, have @INC = ' . "\n" . Dumper(\@INC) . "\n"; }

#no magic;  # require data types, full declarations, other non-magic
# DEV NOTE, CORRELATION #rp008: circular dependency causes "subroutine FOO redefined" errors, solved by replacing use with require below
#use rperltypes;
require rperltypes;
#require rperloperations;
#require rperlrules;
require rperlnames;
#require rperlnamespaces;

# NEED ADD: use/require HelperFunctions*.pm here (not just in rperltypes.pm) to match dependency path of C++ code?

# [[[ CONSTANTS ]]]
#use constant TEST_CONSTANT => my string $TYPED_TEST_CONSTANT = 'Hello, world!';
use constant TEST_CONSTANT => 'Hello, world!';

# [[[ SUBROUTINES ]]]

sub package_to_namespace_root {
    ( my $package ) = @_;
#    print {*STDERR} 'in RPerl::package_to_namespace_root(), received $package = ' . $package . "\n";

    my $namespace_root = q{};
    my $package_split = [ ( split /::/, $package ) ];
    if ( ( defined $package_split->[0] ) and ( $package_split->[0] ne q{} ) ) {
        $namespace_root = $package_split->[0] . '::';
    }

#    print {*STDERR} 'in RPerl::package_to_namespace_root(), about to return $namespace_root = ' . $namespace_root . "\n";
    return $namespace_root;
}

sub filename_short_to_namespace_root_guess {
    ( my $filename_short ) = @_;
#    print {*STDERR} 'in RPerl::filename_short_to_namespace_root_guess(), received $filename_short = ' . $filename_short . "\n";
    # # DEV NOTE, CORRELATION #rp021: remove hard-coded fake 'rperl::' namespace?
    if ($filename_short eq 'rperl') { return 'rperl::'; }
    my $namespace_root = q{};
    ( my $filename_prefix, my $filename_path, my $filename_suffix ) = fileparse( $filename_short, qr/[.][^.]*/xms );
    # DEV NOTE: allow *.pl files to guess a namespace instead of empty string, both here and in filename_short_to_package_guess() below
    # due to Perl core and/or RPerl deps calls to 'use' or 'require' *.pl files, such as Config_git.pl and Config_heavy.pl
#    if ( $filename_suffix eq '.pm' ) {
    if ( ( $filename_suffix eq '.pm' ) or ( $filename_suffix eq '.pl' ) ) {
        my $filename_path_split;
        if ( $OSNAME eq 'MSWin32' ) {
            $filename_path_split = [ split /[\/\\]/, $filename_path ];
            #absolute paths cant go through here anymore, this was dropping the
            #first part of the package on some modules
            #shift @{$filename_path_split};    # discard leading drive letter
        }
        else {
            $filename_path_split = [ split /\//, $filename_path ];
        }

        # join then re-split in case there are no directories in path, only the *.pm filename
        my $namespace_root_split = [ split /::/, ( join '::', ( @{$filename_path_split}, $filename_prefix ) ) ];
        if ( $namespace_root_split->[0] eq '.' ) {
            shift @{$namespace_root_split};
        }
#        print {*STDERR} 'in RPerl::filename_short_to_namespace_root_guess(), have $namespace_root_split = ' . Dumper($namespace_root_split) . "\n";
        $namespace_root = $namespace_root_split->[0] . '::';
    }
#    print {*STDERR} 'in RPerl::filename_short_to_namespace_root_guess(), about to return $namespace_root = ' . $namespace_root . "\n";
    return $namespace_root;
}

sub filename_short_to_package_guess {
    ( my $filename_short ) = @_;
#    print {*STDERR} 'in RPerl::filename_short_to_package_guess(), received $filename_short = ' . $filename_short . "\n";
    my $package = q{};
    ( my $filename_prefix, my $filename_path, my $filename_suffix ) = fileparse( $filename_short, qr/[.][^.]*/xms );

#    print {*STDERR} 'in RPerl::filename_short_to_package_guess(), have $filename_prefix = ' . $filename_prefix . "\n";
#    print {*STDERR} 'in RPerl::filename_short_to_package_guess(), have $filename_path = ' . $filename_path . "\n";
#    print {*STDERR} 'in RPerl::filename_short_to_package_guess(), have $filename_suffix = ' . $filename_suffix . "\n";

#    if ( $filename_suffix eq '.pm' ) {
    if ( ( $filename_suffix eq '.pm' ) or ( $filename_suffix eq '.pl' ) ) {
        my $filename_path_split;
        if ( $OSNAME eq 'MSWin32' ) {
            $filename_path_split = [ split /\\/, $filename_path ];
            shift @{$filename_path_split};    # discard leading drive letter
        }
        else {
            $filename_path_split = [ split /\//, $filename_path ];
        }
        if ($filename_path_split->[0] eq '.') {
            shift @{$filename_path_split};
        }
#        print {*STDERR} 'in RPerl::filename_short_to_package_guess(), have $filename_path_split = ' . Dumper($filename_path_split) . "\n";
        $package = join '::', ( @{$filename_path_split}, $filename_prefix );
    }
#    print {*STDERR} 'in RPerl::filename_short_to_package_guess(), about to return $package = ' . $package . "\n";
    return $package;
}

1;  # end of package