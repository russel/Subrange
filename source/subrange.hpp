//  A subrange type template for C++
//
//  Copyright (c) 2005 Russel Winder
//
//  Distributed under the Boost Software License, Version 1.0.  Reproduced here from
//  http://www.boost.org/LICENSE_1_0.txt.
//
//  Boost Software License - Version 1.0 - August 17th, 2003
//
//  Permission is hereby granted, free of charge, to any person or organization obtaining a copy of
//  the software and accompanying documentation covered by this license (the "Software") to use,
//  reproduce, display, distribute, execute, and transmit the Software, and to prepare derivative
//  works of the Software, and to permit third-parties to whom the Software is furnished to do so,
//  all subject to the following:
//  
//  The copyright notices in the Software and this entire statement, including the above license
//  grant, this restriction and the following disclaimer, must be included in all copies of the
//  Software, in whole or in part, and all derivative works of the Software, unless such copies or
//  derivative works are solely in the form of machine-executable object code generated by a source
//  language processor.
//  
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE
//  AND NON-INFRINGEMENT. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE
//  SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#if ! defined(SUBRANGE_HPP)
#define SUBRANGE_HPP

/**
 *  @file
 *
 *  This file contains various classes and templates that result in a realization of a constrained
 *  value type, aka subrange type, called <code>subrange</code>.  The host type for the subrange
 *  (<code>value_type</code>), the maximum value (<code>value_type min()</code>) and the minimum
 *  value (<code>value_type max()</code>) are captured in a traits class and the arithmetic policy
 *  is captured in a policy class.  A template <code>ordinal_range</code> is provided for generating
 *  the traits classes for ordinal types.  Traditionally a subrange has meant a slice of an ordinal host
 *  type (integer types and enumerated types) but <code>subrange</code> also works for floating
 *  point types.  Unfortunately, because templates cannot take parameters of non-ordinal types, the
 *  programmer is responsible for creating the traits classes for all floating point ranges.  An
 *  example traits class is:
 *
 *  <pre>
 *      class float_1_99 
 *       public :
 *        typedef float value_type ;
 *        typedef subrange::range_error exception_type ;
 *        static float min () { return 1.0 ; }
 *        static float max () { return 99.0 ; }
 *      } ;
 *  </pre>
 *
 *  The policy classes <code>exception_on_error</code>, <code>modulo_arithmetic</code>,
 *  <code>saturated_arithmetic</code> and <code>NaN_arithmetic</code> are provided which should
 *  cover all policies actually needed.  <code>exception_on_error</code> uses the exception class
 *  <code>range_error</code> if it needs to throw an exception.  Should a new policy be needed that
 *  any class that implements
 *
 *  <pre>
 *      typename RangeTraits::value_type checkValue(const typename RangeTraits::value_type proposed)
 *  </pre>
 *
 *  can be used.</p>
 *
 *  <p>Algol68, Pascal and Ada but not C++ (or Java) have the concept of a subrange type built in to
 *  the language. So in Pascal, for example, you can write the following:
 *
 *  <pre>
 *      type TwoDigitWholeNumber = 1..99 ;
 *      var t : TwoDigitWholeNumber ;
 *      t = 21 ; // OK
 *      t = t * 8 ; // ERROR outside range 1..99
 *  </pre>
 *
 *  with any assignment to variable <code>t</code> that is not in the range 1..99 generating a
 *  runtime error.  Many compilers allow the range checks to be switched off but using this facility
 *  is clearly a bad idea as it subverts the whole point of the subrange type &mdash; even if all the
 *  unit tests pass!</p>
 *
 *  <p><code>subrange</code> provides this subrange type facility in C++.  The class can be used
 *  with any host type that has a total ordering, i.e. the integer types, the floating point types
 *  and enumerated types.  However the arithmetic operations will only work for types that allow it
 *  (i.e. not enums since there is no automated conversion from int to the enum symbols).  All
 *  assignment operations on the type are processed by the policy class using the range specified in
 *  the traits class.  It is possible to specify a policy that ignores errors but this would be
 *  somewhat not sensible.  So, using <code>subrange</code>, the above Pascal example can be encoded
 *  in C++ as:
 *
 *  <pre>
 *      typedef subrange::subrange&lt;subrange::ordinal_range&lt;short, 1, 99> > TwoDigitWholeNumber ;
 *      TwoDigitWholeNumber t ;
 *      t = 21 ; // OK
 *      t *= 8 ; // ERROR outside range 1..99
 *  </pre>
 *
 *  This type is a subrange type where the exception <code>subrange::range_error</code> is thrown on
 *  any bounds violation.  Policies for modulo arithmetic, saturated arithmetic and NaN arithmetic
 *  are provided, so:
 *
 *    <pre>
 *      subrange::subrange&lt;subrange::ordinal_range&lt;short, 0, 8>, subrange::modulo_arithmetic> Modulo8 ;
 *    </pre>
 *
 *  is a type for modulo 8 arithmetic.</p>
 *
 *  <p>Implementation Note: Since values of the subrange type can always be converted to the host
 *  type, <code>subrange</code> relies on the comparison operations (and arithmetic operations for
 *  appropriate host types) of the host type.  It does not provide these as part of its public
 *  interface, only the assignment operations are realized.  In fact, if we were to try and
 *  implement them the compiler would find many ambiguous overloads and will not compile the user
 *  code.</p>
 *
 *  <p>This software assumes that the Boost library is installed on your system.</p>  
 *
 *  <p>The contents of this file were inspired by the boost::CV::constrained_value type by Jeff
 *  Garland (part of the Boost date-time package), the subrange_type by Brian Martin (see
 *  http://aspn.activestate.com/ASPN/Mail/Message/boost/2042908 or
 *  http://lists.boost.org/MailArchives/boost/msg62860.php), the range type by Maciej Sobczak (see
 *  http://aspn.activestate.com/ASPN/Mail/Message/boost/2040057) and the CheckedInt type by Hubert
 *  Matthews [Overload 58, Dec 2003].</p>
 *
 *  <p>Copyright (c) 2005  Russel Winder.</p>
 *
 *  @author Russel Winder
 *  @version 1.0
 *  @date 2005-02-07 18:38
 */

#include <limits>

#include <boost/type_traits.hpp>
#include <boost/utility/enable_if.hpp>

namespace subrange {

/**
 *  An exception type for use as and when needed.
 */
class range_error : public std::exception { } ;

/**
 *  A class template for generating traits classes for ranges of ordinal types.  As it is not
 *  possible to have template parameters for non-ordinal types, the programmer wanting subranges of
 *  non-ordinal types will have to explicitly define the traits class.  Pity but...
 */
template<typename HostType, HostType minimum, HostType maximum, typename ExceptionType = range_error>
class ordinal_range {
 public:
  static_assert(minimum <= maximum, "Minimum must be less than or equal to manimum.") ;
  typedef HostType value_type ;
  typedef ExceptionType exception_type ;
  static value_type min () { return minimum ; }
  static value_type max () { return maximum ; }
} ;

/**
 *  A template policy class specifying that an exception be thrown on any range bounds error.
 */
template<typename RangeTraits>
class exception_on_error {
 public:
  static typename RangeTraits::value_type checkValue(const typename RangeTraits::value_type proposed) {
    if ( ((proposed + 1) < (RangeTraits::min() + 1)) || (proposed > RangeTraits::max()) ) { throw typename RangeTraits::exception_type () ; }
    return proposed ;
  }
} ;
  
/**
 *  A template policy class specifying modulo arithmetic (aka wraparound arithmetic).
 */
template<typename RangeTraits>
class modulo_arithmetic {
 public:
  static typename RangeTraits::value_type checkValue(typename RangeTraits::value_type proposed) {
    while ( (proposed + 1) < (RangeTraits::min() + 1) ) { proposed += RangeTraits::max() - RangeTraits::min() ; }
    while ( proposed > RangeTraits::max() ) { proposed -= RangeTraits::max() - RangeTraits::min() ; }
    return proposed ;
  }
} ;
  
/**
 *  A template policy class specifying saturated arithmetic.
 */
template<typename RangeTraits>
class saturated_arithmetic {
 public:
  static typename RangeTraits::value_type checkValue(const typename RangeTraits::value_type proposed) {
    return
     (proposed + 1) < (RangeTraits::min() + 1) ? RangeTraits::min() :
     proposed > RangeTraits::max() ? RangeTraits::max() :
     proposed ;
  }
} ;
  
/**
 *  A template policy class specifying arithmetic using NaN for any value not in the range.
 */
template <typename RangeTraits>
class NaN_arithmetic {
public:
	static typename RangeTraits::value_type plusNaN() { return std::numeric_limits<typename RangeTraits::value_type>::max() ; }
	static typename RangeTraits::value_type minusNaN() { return std::numeric_limits<typename RangeTraits::value_type>::min() ; }
	static bool isNaN(const typename RangeTraits::value_type v) { return v == plusNaN() || v == minusNaN() ; }
	static typename RangeTraits::value_type checkValue(const typename RangeTraits::value_type proposed) {
    return
     (proposed + 1) < (RangeTraits::min() + 1) ? minusNaN() :
     proposed > RangeTraits::max() ? plusNaN() :
     proposed ;
	}
} ;

/**
 *  The version of <code>subrange</ocde> used for host types that do not support arithmetic ---
 *  probably just enumerated types.
 */
template<class RangeTraits, template<class> class ArithmeticPolicy = exception_on_error, typename TemplateSelectionType = void>
class subrange {
 public :
  typedef typename RangeTraits::value_type value_type ;
  static value_type min () { return RangeTraits::min() ; }
  static value_type max () { return RangeTraits::max() ; }
 private :
  value_type value ;
 public:
  subrange() : value(min()) { }
  explicit subrange(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(v) ; }
  operator value_type() const { return value ; }
  subrange & operator=(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(v) ; return *this; }   
} ;

/**
 *  A specialization of <code>subrange</code> for use with integral host types.
 */
template<class RangeTraits, template<class> class ArithmeticPolicy>
class subrange<RangeTraits, ArithmeticPolicy, typename boost::enable_if<boost::is_integral<typename RangeTraits::value_type> >::type> {
 public:
  typedef typename RangeTraits::value_type value_type ;
  static value_type min () { return RangeTraits::min() ; }
  static value_type max () { return RangeTraits::max() ; }
 private :
  value_type value ;
 public:
  subrange() : value(min()) { }
  explicit subrange(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(v) ; }
  operator value_type() const { return value ; }
  subrange & operator=(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(v) ; return *this ; }   
  subrange & operator+=(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(value + v) ; return *this ; }
  subrange & operator-=(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(value - v) ; return *this ; }
  subrange & operator*=(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(value * v) ; return *this ; }
  subrange & operator/=(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(value / v) ; return *this ; }
  subrange & operator%=(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(value % v) ; return *this ; }
  subrange & operator^=(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(value ^ v) ; return *this ; }
  subrange & operator&=(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(value & v) ; return *this ; }
  subrange & operator|=(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(value | v) ; return *this ; }
  subrange & operator<<=(const int v) { value = ArithmeticPolicy<RangeTraits>::checkValue(value << v) ; return *this ; }
  subrange & operator>>=(const int v) { value = ArithmeticPolicy<RangeTraits>::checkValue(value >> v) ; return *this ; }
  subrange operator++() { *this += 1 ; return *this ; }
  subrange operator++(int) { subrange returnValue (*this) ; ++*this ; return returnValue ; }
  subrange operator--() { *this -= 1 ; return *this ; }
  subrange operator--(int) { subrange returnValue (*this) ; --*this ; return returnValue ; }
} ;

/**
 *  A specialization of <code>subrange</code> for use with floating point host types.
 */
template<class RangeTraits, template<class> class ArithmeticPolicy>
class subrange<RangeTraits, ArithmeticPolicy, typename boost::enable_if<boost::is_float<typename RangeTraits::value_type> >::type> {
 public:
  typedef typename RangeTraits::value_type value_type ;
  static value_type min () { return RangeTraits::min() ; }
  static value_type max () { return RangeTraits::max() ; }
 private :
  value_type value ;
 public:
  subrange() : value(min()) { }
  explicit subrange(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(v) ; }
  operator value_type() const { return value ; }
  subrange & operator=(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(v) ; return *this ; }   
  subrange & operator+=(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(value + v) ; return *this ; }
  subrange & operator-=(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(value - v) ; return *this ; }
  subrange & operator*=(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(value * v) ; return *this ; }
  subrange & operator/=(const value_type v) { value = ArithmeticPolicy<RangeTraits>::checkValue(value / v) ; return *this ; }
  subrange operator++() { *this += 1 ; return *this ; }
  subrange operator++(int) { subrange returnValue (*this) ; ++*this ; return returnValue ; }
  subrange operator--() { *this -= 1 ; return *this ; }
  subrange operator--(int) { subrange returnValue (*this) ; --*this ; return returnValue ; }
} ;

} // namespace subrange

#endif /* ! defined(SUBRANGE_HPP) */
