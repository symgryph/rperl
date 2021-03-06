# [[[ PREPROCESSOR ]]]
# <<< PARSE_ERROR: 'ECOPAPL03' >>>
# <<< PARSE_ERROR: 'Subroutine empty_method redefined' >>>

# [[[ HEADER ]]]
use RPerl;
package RPerl::Test::Module::Class_01_Bad_00;
use strict;
use warnings;
our $VERSION = 0.001_000;

# [[[ OO INHERITANCE ]]]
use parent qw(RPerl::Test);
use RPerl::Test;

# [[[ CRITICS ]]]
## no critic qw(ProhibitMultiplePackages ProhibitReusedNames ProhibitPackageVars)  # USER DEFAULT 8: allow additional packages

# [[[ OO PROPERTIES ]]]
our hashref $properties
    = { empty_property => my integer $TYPED_empty_property = 2 };

# [[[ SUBROUTINES & OO METHODS ]]]
sub empty_method { { my void::method $RETURN_TYPE }; return 2; }

1;    # end of class


# [[[ ADDITIONAL CLASSES ]]]

# [[[ HEADER ]]]
use RPerl;
package Class_01_Bad_00;
use strict;
use warnings;
our $VERSION = 0.001_000;

# [[[ OO INHERITANCE ]]]
use parent qw(RPerl::Test::Module::Class_01_Bad_00);
require RPerl::Test::Module::Class_01_Bad_00;

# [[[ OO PROPERTIES ]]]
our hashref $properties = $RPerl::Test::Module::Class_01_Bad_00::VERSION;

1;    # end of class

