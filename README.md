# Subrange

The subrange.hpp file contains various classes and templates that result in a realization of a constrained
value type, aka subrange type, called *subrange*.  The host type for the subrange (*value_type*), the
maximum value (*value_type min()*) and the minimum value (*value_type max()*) are captured in a traits class
and the arithmetic policy is captured in a policy class.  A template *ordinal_range* is provided for
generating the traits classes for ordinal types.  Traditionally a subrange has meant a slice of an ordinal
host type (integer types and enumerated types) but *subrange* also works for floating point types.
Unfortunately, because templates cannot take parameters of non-ordinal types, the programmer is responsible
for creating the traits classes for all floating point ranges.  An example traits class is:

    class float_1_99
     public :
      typedef float value_type;
      typedef subrange::range_error exception_type;
      static float min () { return 1.0; }
      static float max () { return 99.0; }
    };

The policy classes *exception_on_error*, *modulo_arithmetic*, *saturated_arithmetic* and *NaN_arithmetic*
are provided which should cover all policies actually needed.  *exception_on_error* uses the exception class
*range_error* if it needs to throw an exception.  Should a new policy be needed that any class that
implements

    typename RangeTraits::value_type checkValue(const typename RangeTraits::value_type proposed)

can be used.

Algol68, Pascal and Ada but not C++ (or Java) have the concept of a subrange type built in to the
language. So in Pascal, for example, you can write the following:

    type TwoDigitWholeNumber = 1..99;
    var t : TwoDigitWholeNumber;
    t = 21; // OK
    t = t * 8; // ERROR outside range 1..99

with any assignment to variable *t* that is not in the range 1..99 generating a runtime error.  Many
compilers allow the range checks to be switched off but using this facility is clearly a bad idea as it
subverts the whole point of the subrange type &mdash; even if all the unit tests pass!

*subrange* provides this subrange type facility in C++.  The class can be used with any host type that has a
total ordering, i.e. the integer types, the floating point types and enumerated types.  However the
arithmetic operations will only work for types that allow it (i.e. not enums since there is no automated
conversion from int to the enum symbols).  All assignment operations on the type are processed by the policy
class using the range specified in the traits class.  It is possible to specify a policy that ignores errors
but this would be somewhat not sensible.  So, using *subrange*, the above Pascal example can be encoded in
C++ as:

    typedef subrange::subrange&lt;subrange::ordinal_range&lt;short, 1, 99>> TwoDigitWholeNumber;
    TwoDigitWholeNumber t;
    t = 21; // OK
    t *= 8; // ERROR outside range 1..99

This type is a subrange type where the exception *subrange::range_error* is thrown on any bounds violation.
Policies for modulo arithmetic, saturated arithmetic and NaN arithmetic are provided, so:

    subrange::subrange&lt;subrange::ordinal_range&lt;short, 0, 8>, subrange::modulo_arithmetic> Modulo8;

is a type for modulo 8 arithmetic.

Implementation Note: Since values of the subrange type can always be converted to the host type, *subrange*
relies on the comparison operations (and arithmetic operations for appropriate host types) of the host type.
It does not provide these as part of its public interface, only the assignment operations are realized.  In
fact, if we were to try and implement them the compiler would find many ambiguous overloads and will not
compile the user code.

The contents of this file were inspired by the boost::CV::constrained_value type by Jeff Garland (part of
the Boost date-time package), the subrange_type by Brian Martin (see
http://aspn.activestate.com/ASPN/Mail/Message/boost/2042908 or
http://lists.boost.org/MailArchives/boost/msg62860.php), the range type by Maciej Sobczak (see
http://aspn.activestate.com/ASPN/Mail/Message/boost/2040057) and the CheckedInt type by Hubert Matthews
[Overload 58, Dec 2003].

This software is licenced using the Boost Software License - Version 1.0 - August 17th, 2003.
