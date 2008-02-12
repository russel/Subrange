//  Unit test for a subrange type template for C++
//
//  Copyright (c) 2005 Russel Winder
//
//  Distributed under the Boost Software License, Version 1.0.  See
//  http://www.boost.org/LICENSE_1_0.txt.

/**
 *  @file
 *
 *  A test program (using Aeryn) for the <code>subrange</code> type.
 *
 *  <p>This is in serious need of extending with far more test cases.</p>
 *
 *  <p>Copyright (c) 2005  Russel Winder.</p>
 *
 *  @author Russel Winder
 *  @version 1.0
 *  @date 2005-01-06 09:05
 */

#include "aeryn/test_runner.hpp"
#include "aeryn/is_true.hpp"
#include "aeryn/test_failure.hpp"
#include "aeryn/throws_exception.hpp"
#include "aeryn/use_name.hpp"

#include "subrange.hpp"

enum Day { monday, tuesday, wednesday, thursday, friday, saturday, sunday } ;

typedef subrange::subrange<subrange::ordinal_range<Day, monday, friday> > Weekday ;

void createDefaultTestEnum() {
  Weekday a ;
  IS_TRUE(a == monday) ;
}

void assignTestEnum() {
  Weekday a (monday) ;
  Weekday b (tuesday) ;
  a = b ;
  IS_TRUE(a == b) ;
}

void equalsTestEnum() {
  Weekday a (monday) ;
  Weekday b (monday) ;
  IS_TRUE(a == b) ;
}

void notEqualsTestEnum() {
  Weekday a (monday) ;
  Weekday b (tuesday) ;
  IS_TRUE(a != b) ;
}

void lessThanTestEnum() {
  Weekday a (monday) ;
  Weekday b (tuesday) ;
  IS_TRUE(a < b) ;
  IS_TRUE(!(a >= b)) ;
}

void lessThanEqualToTestEnum() {
  Weekday a (monday) ;
  Weekday b (monday) ;
  IS_TRUE(a <= b) ;
  IS_TRUE(!(a > b)) ;
}

void greaterThanTestEnum() {
  Weekday a (monday) ;
  Weekday b (tuesday) ;
  IS_TRUE(b > a) ;
  IS_TRUE(!(b <= a)) ;
}

void greaterThanEqualToTestEnum() {
  Weekday a (monday) ;
  Weekday b (monday) ;
  IS_TRUE(a >= b) ;
  IS_TRUE(!(a < b)) ;
}


typedef subrange::subrange<subrange::ordinal_range<short, 1, 99> > SubIntException ;

void createDefaultTestIntException() {
  SubIntException a ;
  IS_TRUE(a == 1) ;
}

void preincrementTestIntException() {
  SubIntException a (9) ;
  ++a ;
  IS_TRUE(a == 10) ;
}

void postincrementTestIntException() {
  SubIntException a (9) ;
  a++ ;
  IS_TRUE(a == 10) ;
}

void predecrementTestIntException() {
  SubIntException a (9) ;
  --a ;
  IS_TRUE(a == 8) ;
}

void postdecrementTestIntException() {
  SubIntException a (9) ;
  a-- ;
  IS_TRUE(a == 8) ;
}

void assignLiteralTestIntException() {
  SubIntException a (9) ;
  a = 20 ;
  IS_TRUE(a == 20) ;
  THROWS_EXCEPTION(a = 200, subrange::range_error) ;
  THROWS_EXCEPTION(a = -5, subrange::range_error) ;
}

void assignTestIntException() {
  SubIntException a (9) ;
  SubIntException b (20) ;
  a = b ;
  IS_TRUE(a == b) ;
  IS_TRUE(a == 20) ;
}

void addAssignTestIntException() {
  SubIntException a (9) ;
  SubIntException b (20) ;
  a += b ;
  IS_TRUE(a == 29) ;
  a += 10 ;
  IS_TRUE(a == 39) ;
  a += -10 ;
  IS_TRUE(a == 29) ;
  THROWS_EXCEPTION(a += 200, subrange::range_error) ;
}

void subtractAssignTestIntException() {
  SubIntException a (20) ;
  SubIntException b (9) ;
  a -= b ;
  IS_TRUE(a == 11) ;
  a -= 5 ;
  IS_TRUE(a == 6) ;
  a -= -5 ;
  IS_TRUE(a == 11) ;
  THROWS_EXCEPTION(b -= a, subrange::range_error) ;
}

void multiplyAssignTestIntException() {
  SubIntException a (20) ;
  SubIntException b (3) ;
  a *= b ;
  IS_TRUE(a == 60) ;
  THROWS_EXCEPTION(a *= b, subrange::range_error) ;
}

void divideAssignTestIntException() {
  SubIntException a (20) ;
  SubIntException b (3) ;
  a /= b ;
  IS_TRUE(a == 6) ;
}

void remainderAssignTestIntException() {
  SubIntException a (20) ;
  SubIntException b (3) ;
  a %= b ;
  IS_TRUE(a == 2) ;
}

void xorAssignTestIntException() {
  SubIntException a (0x12) ;
  SubIntException b (0x03) ;
  a ^= b ;
  IS_TRUE(a == 0x11) ;
}

void andAssignTestIntException() {
  SubIntException a (0x12) ;
  SubIntException b (0x03) ;
  a &= b ;
  IS_TRUE(a == 0x02) ;
}

void orAssignTestIntException() {
  SubIntException a (0x12) ;
  SubIntException b (0x03) ;
  a |= b ;
  IS_TRUE(a == 0x13) ;
}

void shiftLeftAssignTestIntException() {
  SubIntException a (0x12) ;
  a <<= 1 ;
  IS_TRUE(a == 0x24) ;
}

void shiftRightAssignTestIntException() {
  SubIntException a (0x12) ;
  a >>= 1 ;
  IS_TRUE(a == 0x09) ;
}

void addTestIntException() {
  SubIntException a (9) ;
  SubIntException b (20) ;
  a = a + b ;
  IS_TRUE(a == 29) ;
  a = a + 10 ;
  IS_TRUE(a == 39) ;
  a = a + -10 ;
  IS_TRUE(a == 29) ;
  a = 10 + a ;
  IS_TRUE(a == 39) ;
  a = -10 + a ;
  IS_TRUE(a == 29) ;
}

void subtractTestIntException() {
  SubIntException a (20) ;
  SubIntException b (9) ;
  a = a - b ;
  IS_TRUE(a == 11) ;
}

void multiplyTestIntException() {
  SubIntException a (20) ;
  SubIntException b (3) ;
  a = a * b ;
  IS_TRUE(a == 60) ;
}

void divideTestIntException() {
  SubIntException a (20) ;
  SubIntException b (3) ;
  a = a / b ;
  IS_TRUE(a == 6) ;
}

void remainderTestIntException() {
  SubIntException a (20) ;
  SubIntException b (3) ;
  a = a % b ;
  IS_TRUE(a == 2) ;
}

void xorTestIntException() {
  SubIntException a (0x12) ;
  SubIntException b (0x03) ;
  a = a ^ b ;
  IS_TRUE(a == 0x11) ;
}

void andTestIntException() {
  SubIntException a (0x12) ;
  SubIntException b (0x03) ;
  a = a & b ;
  IS_TRUE(a == 0x02) ;
}

void orTestIntException() {
  SubIntException a (0x12) ;
  SubIntException b (0x03) ;
  a = a | b ;
  IS_TRUE(a == 0x13) ;
}

void shiftLeftTestIntException() {
  SubIntException a (0x12) ;
  a = a << 1 ;
  IS_TRUE(a == 0x24) ;
  THROWS_EXCEPTION( a = a << 3, subrange::range_error) ;
}

void shiftRightTestIntException() {
  SubIntException a (0x12) ;
  a = a >> 1 ;
  IS_TRUE(a == 0x09) ;
  THROWS_EXCEPTION(a = a >> 5, subrange::range_error) ;
}

void equalsTestIntException() {
  SubIntException a (9) ;
  SubIntException b (9) ;
  IS_TRUE(a == b) ;
}

void notEqualsTestIntException() {
  SubIntException a (9) ;
  SubIntException b (8) ;
  IS_TRUE(a != b) ;
}

void lessThanTestIntException() {
  SubIntException a (8) ;
  SubIntException b (9) ;
  IS_TRUE(a < b) ;
  IS_TRUE(!(a >= b)) ;
}

void lessThanEqualToTestIntException() {
  SubIntException a (8) ;
  SubIntException b (8) ;
  IS_TRUE(a <= b) ;
  IS_TRUE(!(a > b)) ;
}

void greaterThanTestIntException() {
  SubIntException a (8) ;
  SubIntException b (9) ;
  IS_TRUE(b > a) ;
  IS_TRUE(!(b <= a)) ;
}

void greaterThanEqualToTestIntException() {
  SubIntException a (8) ;
  SubIntException b (8) ;
  IS_TRUE(a >= b) ;
  IS_TRUE(!(a < b)) ;
}

typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>, subrange::modulo_arithmetic> SubIntModulo ;

void createDefaultTestIntModulo() {
  SubIntModulo a ;
  IS_TRUE(a == 1) ;
}

void preincrementTestIntModulo() {
  SubIntModulo a (9) ;
  ++a ;
  IS_TRUE(a == 10) ;
}

void postincrementTestIntModulo() {
  SubIntModulo a (9) ;
  a++ ;
  IS_TRUE(a == 10) ;
}

void predecrementTestIntModulo() {
  SubIntModulo a (9) ;
  --a ;
  IS_TRUE(a == 8) ;
}

void postdecrementTestIntModulo() {
  SubIntModulo a (9) ;
  a-- ;
  IS_TRUE(a == 8) ;
}

void assignLiteralTestIntModulo() {
  SubIntModulo a (9) ;
  a = 20 ;
  IS_TRUE(a == 20) ;
  a = 200 ;
  IS_TRUE(a == 4) ;
  a = -5 ;
  IS_TRUE(a == 93) ;
}

void assignTestIntModulo() {
  SubIntModulo a (9) ;
  SubIntModulo b (20) ;
  a = b ;
  IS_TRUE(a == b) ;
  IS_TRUE(a == 20) ;
}

void addAssignTestIntModulo() {
  SubIntModulo a (9) ;
  SubIntModulo b (20) ;
  a += b ;
  IS_TRUE(a == 29) ;
  a += 10 ;
  IS_TRUE(a == 39) ;
  a += -10 ;
  IS_TRUE(a == 29) ;
  a += 200 ;
  IS_TRUE(a == 33) ;
}

void subtractAssignTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (9) ;
  a -= b ;
  IS_TRUE(a == 11) ;
  a -= 5 ;
  IS_TRUE(a == 6) ;
  a -= -5 ;
  IS_TRUE(a == 11) ;
  b -= a ;
  IS_TRUE(b == 96) ;
}

void multiplyAssignTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (3) ;
  a *= b ;
  IS_TRUE(a == 60) ;
  a *= b ;
  IS_TRUE(a == 82) ;
}

void divideAssignTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (3) ;
  a /= b ;
  IS_TRUE(a == 6) ;
}

void remainderAssignTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (3) ;
  a %= b ;
  IS_TRUE(a == 2) ;
}

void xorAssignTestIntModulo() {
  SubIntModulo a (0x12) ;
  SubIntModulo b (0x03) ;
  a ^= b ;
  IS_TRUE(a == 0x11) ;
}

void andAssignTestIntModulo() {
  SubIntModulo a (0x12) ;
  SubIntModulo b (0x03) ;
  a &= b ;
  IS_TRUE(a == 0x02) ;
}

void orAssignTestIntModulo() {
  SubIntModulo a (0x12) ;
  SubIntModulo b (0x03) ;
  a |= b ;
  IS_TRUE(a == 0x13) ;
}

void shiftLeftAssignTestIntModulo() {
  SubIntModulo a (0x12) ;
  a <<= 1 ;
  IS_TRUE(a == 0x24) ;
}

void shiftRightAssignTestIntModulo() {
  SubIntModulo a (0x12) ;
  a >>= 1 ;
  IS_TRUE(a == 0x09) ;
}

void addTestIntModulo() {
  SubIntModulo a (9) ;
  SubIntModulo b (20) ;
  a = a + b ;
  IS_TRUE(a == 29) ;
  a = a + 10 ;
  IS_TRUE(a == 39) ;
  a = a + -10 ;
  IS_TRUE(a == 29) ;
  a = 10 + a ;
  IS_TRUE(a == 39) ;
  a = -10 + a ;
  IS_TRUE(a == 29) ;
}

void subtractTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (9) ;
  a = a - b ;
  IS_TRUE(a == 11) ;
}

void multiplyTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (3) ;
  a = a * b ;
  IS_TRUE(a == 60) ;
}

void divideTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (3) ;
  a = a / b ;
  IS_TRUE(a == 6) ;
}

void remainderTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (3) ;
  a = a % b ;
  IS_TRUE(a == 2) ;
}

void xorTestIntModulo() {
  SubIntModulo a (0x12) ;
  SubIntModulo b (0x03) ;
  a = a ^ b ;
  IS_TRUE(a == 0x11) ;
}

void andTestIntModulo() {
  SubIntModulo a (0x12) ;
  SubIntModulo b (0x03) ;
  a = a & b ;
  IS_TRUE(a == 0x02) ;
}

void orTestIntModulo() {
  SubIntModulo a (0x12) ;
  SubIntModulo b (0x03) ;
  a = a | b ;
  IS_TRUE(a == 0x13) ;
}

void shiftLeftTestIntModulo() {
  SubIntModulo a (0x12) ;
  a = a << 1 ;
  IS_TRUE(a == 0x24) ;
  a = a << 3 ;
  IS_TRUE(a == 92) ;
}

void shiftRightTestIntModulo() {
  SubIntModulo a (0x12) ;
  a = a >> 1 ;
  IS_TRUE(a == 0x09) ;
  a = a >> 5 ;
  IS_TRUE(a == 98) ;
}

void equalsTestIntModulo() {
  SubIntModulo a (9) ;
  SubIntModulo b (9) ;
  IS_TRUE(a == b) ;
}

void notEqualsTestIntModulo() {
  SubIntModulo a (9) ;
  SubIntModulo b (8) ;
  IS_TRUE(a != b) ;
}

void lessThanTestIntModulo() {
  SubIntModulo a (8) ;
  SubIntModulo b (9) ;
  IS_TRUE(a < b) ;
  IS_TRUE(!(a >= b)) ;
}

void lessThanEqualToTestIntModulo() {
  SubIntModulo a (8) ;
  SubIntModulo b (8) ;
  IS_TRUE(a <= b) ;
  IS_TRUE(!(a > b)) ;
}

void greaterThanTestIntModulo() {
  SubIntModulo a (8) ;
  SubIntModulo b (9) ;
  IS_TRUE(b > a) ;
  IS_TRUE(!(b <= a)) ;
}

void greaterThanEqualToTestIntModulo() {
  SubIntModulo a (8) ;
  SubIntModulo b (8) ;
  IS_TRUE(a >= b) ;
  IS_TRUE(!(a < b)) ;
}

typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>, subrange::saturated_arithmetic> SubIntSaturated ;

void createDefaultTestIntSaturated() {
  SubIntSaturated a ;
  IS_TRUE(a == 1) ;
}

void preincrementTestIntSaturated() {
  SubIntSaturated a (9) ;
  ++a ;
  IS_TRUE(a == 10) ;
}

void postincrementTestIntSaturated() {
  SubIntSaturated a (9) ;
  a++ ;
  IS_TRUE(a == 10) ;
}

void predecrementTestIntSaturated() {
  SubIntSaturated a (9) ;
  --a ;
  IS_TRUE(a == 8) ;
}

void postdecrementTestIntSaturated() {
  SubIntSaturated a (9) ;
  a-- ;
  IS_TRUE(a == 8) ;
}

void assignLiteralTestIntSaturated() {
  SubIntSaturated a (9) ;
  a = 20 ;
  IS_TRUE(a == 20) ;
  a = 200 ;
  IS_TRUE(a == 99) ;
  a = -5 ;
  IS_TRUE(a == 1) ;
}

void assignTestIntSaturated() {
  SubIntSaturated a (9) ;
  SubIntSaturated b (20) ;
  a = b ;
  IS_TRUE(a == b) ;
  IS_TRUE(a == 20) ;
}

void addAssignTestIntSaturated() {
  SubIntSaturated a (9) ;
  SubIntSaturated b (20) ;
  a += b ;
  IS_TRUE(a == 29) ;
  a += 10 ;
  IS_TRUE(a == 39) ;
  a += -10 ;
  IS_TRUE(a == 29) ;
  a += 200 ;
  IS_TRUE(a == 99) ;
}

void subtractAssignTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (9) ;
  a -= b ;
  IS_TRUE(a == 11) ;
  a -= 5 ;
  IS_TRUE(a == 6) ;
  a -= -5 ;
  IS_TRUE(a == 11) ;
  b -= a ;
  IS_TRUE(b == 1) ;
}

void multiplyAssignTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (3) ;
  a *= b ;
  IS_TRUE(a == 60) ;
  a *= b ;
  IS_TRUE(a == 99) ;
}

void divideAssignTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (3) ;
  a /= b ;
  IS_TRUE(a == 6) ;
}

void remainderAssignTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (3) ;
  a %= b ;
  IS_TRUE(a == 2) ;
}

void xorAssignTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  SubIntSaturated b (0x03) ;
  a ^= b ;
  IS_TRUE(a == 0x11) ;
}

void andAssignTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  SubIntSaturated b (0x03) ;
  a &= b ;
  IS_TRUE(a == 0x02) ;
}

void orAssignTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  SubIntSaturated b (0x03) ;
  a |= b ;
  IS_TRUE(a == 0x13) ;
}

void shiftLeftAssignTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  a <<= 1 ;
  IS_TRUE(a == 0x24) ;
}

void shiftRightAssignTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  a >>= 1 ;
  IS_TRUE(a == 0x09) ;
}

void addTestIntSaturated() {
  SubIntSaturated a (9) ;
  SubIntSaturated b (20) ;
  a = a + b ;
  IS_TRUE(a == 29) ;
  a = a + 10 ;
  IS_TRUE(a == 39) ;
  a = a + -10 ;
  IS_TRUE(a == 29) ;
  a = 10 + a ;
  IS_TRUE(a == 39) ;
  a = -10 + a ;
  IS_TRUE(a == 29) ;
}

void subtractTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (9) ;
  a = a - b ;
  IS_TRUE(a == 11) ;
}

void multiplyTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (3) ;
  a = a * b ;
  IS_TRUE(a == 60) ;
}

void divideTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (3) ;
  a = a / b ;
  IS_TRUE(a == 6) ;
}

void remainderTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (3) ;
  a = a % b ;
  IS_TRUE(a == 2) ;
}

void xorTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  SubIntSaturated b (0x03) ;
  a = a ^ b ;
  IS_TRUE(a == 0x11) ;
}

void andTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  SubIntSaturated b (0x03) ;
  a = a & b ;
  IS_TRUE(a == 0x02) ;
}

void orTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  SubIntSaturated b (0x03) ;
  a = a | b ;
  IS_TRUE(a == 0x13) ;
}

void shiftLeftTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  a = a << 1 ;
  IS_TRUE(a == 0x24) ;
  a = a << 3 ;
  IS_TRUE(a == 99) ;
}

void shiftRightTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  a = a >> 1 ;
  IS_TRUE(a == 0x09) ;
  a = a >> 5 ;
  IS_TRUE(a == 1) ;
}

void equalsTestIntSaturated() {
  SubIntSaturated a (9) ;
  SubIntSaturated b (9) ;
  IS_TRUE(a == b) ;
}

void notEqualsTestIntSaturated() {
  SubIntSaturated a (9) ;
  SubIntSaturated b (8) ;
  IS_TRUE(a != b) ;
}

void lessThanTestIntSaturated() {
  SubIntSaturated a (8) ;
  SubIntSaturated b (9) ;
  IS_TRUE(a < b) ;
  IS_TRUE(!(a >= b)) ;
}

void lessThanEqualToTestIntSaturated() {
  SubIntSaturated a (8) ;
  SubIntSaturated b (8) ;
  IS_TRUE(a <= b) ;
  IS_TRUE(!(a > b)) ;
}

void greaterThanTestIntSaturated() {
  SubIntSaturated a (8) ;
  SubIntSaturated b (9) ;
  IS_TRUE(b > a) ;
  IS_TRUE(!(b <= a)) ;
}

void greaterThanEqualToTestIntSaturated() {
  SubIntSaturated a (8) ;
  SubIntSaturated b (8) ;
  IS_TRUE(a >= b) ;
  IS_TRUE(!(a < b)) ;
}

typedef subrange::ordinal_range<short, 1, 99> RangeTraits ;
typedef subrange::subrange<RangeTraits, subrange::NaN_arithmetic> SubIntNaN ;

inline bool isNaN(const SubIntNaN & s) { return subrange::NaN_arithmetic<RangeTraits>::isNaN(s) ; }

void createDefaultTestIntNaN() {
  SubIntNaN a ;
  IS_TRUE(a == 1) ;
}

void preincrementTestIntNaN() {
  SubIntNaN a (9) ;
  ++a ;
  IS_TRUE(a == 10) ;
}

void postincrementTestIntNaN() {
  SubIntNaN a (9) ;
  a++ ;
  IS_TRUE(a == 10) ;
}

void predecrementTestIntNaN() {
  SubIntNaN a (9) ;
  --a ;
  IS_TRUE(a == 8) ;
}

void postdecrementTestIntNaN() {
  SubIntNaN a (9) ;
  a-- ;
  IS_TRUE(a == 8) ;
}

void assignLiteralTestIntNaN() {
  SubIntNaN a (9) ;
  a = 20 ;
  IS_TRUE(a == 20) ;
  a = 200 ;
  IS_TRUE(isNaN(a)) ;
  a = -5 ;
  IS_TRUE(isNaN(a)) ;
}

void assignTestIntNaN() {
  SubIntNaN a (9) ;
  SubIntNaN b (20) ;
  a = b ;
  IS_TRUE(a == b) ;
  IS_TRUE(a == 20) ;
}

void addAssignTestIntNaN() {
  SubIntNaN a (9) ;
  SubIntNaN b (20) ;
  a += b ;
  IS_TRUE(a == 29) ;
  a += 10 ;
  IS_TRUE(a == 39) ;
  a += -10 ;
  IS_TRUE(a == 29) ;
  a += 200 ;
  IS_TRUE(isNaN(a)) ;
}

void subtractAssignTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (9) ;
  a -= b ;
  IS_TRUE(a == 11) ;
  a -= 5 ;
  IS_TRUE(a == 6) ;
  a -= -5 ;
  IS_TRUE(a == 11) ;
  b -= a ;
  IS_TRUE(isNaN(b)) ;
}

void multiplyAssignTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (3) ;
  a *= b ;
  IS_TRUE(a == 60) ;
  a *= b ;
  IS_TRUE(isNaN(a)) ;
}

void divideAssignTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (3) ;
  a /= b ;
  IS_TRUE(a == 6) ;
}

void remainderAssignTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (3) ;
  a %= b ;
  IS_TRUE(a == 2) ;
}

void xorAssignTestIntNaN() {
  SubIntNaN a (0x12) ;
  SubIntNaN b (0x03) ;
  a ^= b ;
  IS_TRUE(a == 0x11) ;
}

void andAssignTestIntNaN() {
  SubIntNaN a (0x12) ;
  SubIntNaN b (0x03) ;
  a &= b ;
  IS_TRUE(a == 0x02) ;
}

void orAssignTestIntNaN() {
  SubIntNaN a (0x12) ;
  SubIntNaN b (0x03) ;
  a |= b ;
  IS_TRUE(a == 0x13) ;
}

void shiftLeftAssignTestIntNaN() {
  SubIntNaN a (0x12) ;
  a <<= 1 ;
  IS_TRUE(a == 0x24) ;
}

void shiftRightAssignTestIntNaN() {
  SubIntNaN a (0x12) ;
  a >>= 1 ;
  IS_TRUE(a == 0x09) ;
}

void addTestIntNaN() {
  SubIntNaN a (9) ;
  SubIntNaN b (20) ;
  a = a + b ;
  IS_TRUE(a == 29) ;
  a = a + 10 ;
  IS_TRUE(a == 39) ;
  a = a + -10 ;
  IS_TRUE(a == 29) ;
  a = 10 + a ;
  IS_TRUE(a == 39) ;
  a = -10 + a ;
  IS_TRUE(a == 29) ;
}

void subtractTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (9) ;
  a = a - b ;
  IS_TRUE(a == 11) ;
}

void multiplyTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (3) ;
  a = a * b ;
  IS_TRUE(a == 60) ;
}

void divideTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (3) ;
  a = a / b ;
  IS_TRUE(a == 6) ;
}

void remainderTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (3) ;
  a = a % b ;
  IS_TRUE(a == 2) ;
}

void xorTestIntNaN() {
  SubIntNaN a (0x12) ;
  SubIntNaN b (0x03) ;
  a = a ^ b ;
  IS_TRUE(a == 0x11) ;
}

void andTestIntNaN() {
  SubIntNaN a (0x12) ;
  SubIntNaN b (0x03) ;
  a = a & b ;
  IS_TRUE(a == 0x02) ;
}

void orTestIntNaN() {
  SubIntNaN a (0x12) ;
  SubIntNaN b (0x03) ;
  a = a | b ;
  IS_TRUE(a == 0x13) ;
}

void shiftLeftTestIntNaN() {
  SubIntNaN a (0x12) ;
  a = a << 1 ;
  IS_TRUE(a == 0x24) ;
  a = a << 3 ;
  IS_TRUE(isNaN(a)) ;
}

void shiftRightTestIntNaN() {
  SubIntNaN a (0x12) ;
  a = a >> 1 ;
  IS_TRUE(a == 0x09) ;
  a = a >> 5 ;
  IS_TRUE(isNaN(a)) ;
}

void equalsTestIntNaN() {
  SubIntNaN a (9) ;
  SubIntNaN b (9) ;
  IS_TRUE(a == b) ;
}

void notEqualsTestIntNaN() {
  SubIntNaN a (9) ;
  SubIntNaN b (8) ;
  IS_TRUE(a != b) ;
}

void lessThanTestIntNaN() {
  SubIntNaN a (8) ;
  SubIntNaN b (9) ;
  IS_TRUE(a < b) ;
  IS_TRUE(!(a >= b)) ;
}

void lessThanEqualToTestIntNaN() {
  SubIntNaN a (8) ;
  SubIntNaN b (8) ;
  IS_TRUE(a <= b) ;
  IS_TRUE(!(a > b)) ;
}

void greaterThanTestIntNaN() {
  SubIntNaN a (8) ;
  SubIntNaN b (9) ;
  IS_TRUE(b > a) ;
  IS_TRUE(!(b <= a)) ;
}

void greaterThanEqualToTestIntNaN() {
  SubIntNaN a (8) ;
  SubIntNaN b (8) ;
  IS_TRUE(a >= b) ;
  IS_TRUE(!(a < b)) ;
}

//  Can't use any templates for defining floating point range traits as C++ forbids template parameters
//  that are not of ordinal type so we haver to do that manually.
 
class float_range {
 public :
  typedef double value_type ;
  typedef subrange::range_error exception_type ;
  static double min () { return 1.0 ; }
  static double max () { return 99.0 ; }
} ;

typedef subrange::subrange<float_range> SubFloat ;

void createDefaultTestFloat() {
  SubFloat a ;
  IS_TRUE(a == 1.0) ;
}

void preincrementTestFloat() {
  SubFloat a (9.0) ;
  ++a ;
  IS_TRUE(a == 10.0) ;
}

void postincrementTestFloat() {
  SubFloat a (9.0) ;
  a++ ;
  IS_TRUE(a == 10.0) ;
}

void predecrementTestFloat() {
  SubFloat a (9.0) ;
  --a ;
  IS_TRUE(a == 8.0) ;
}

void postdecrementTestFloat() {
  SubFloat a (9.0) ;
  a-- ;
  IS_TRUE(a == 8.0) ;
}

void assignLiteralTestFloat() {
  SubFloat a (9.0) ;
  a = 20.0 ;
  IS_TRUE(a == 20.0) ;
  THROWS_EXCEPTION(a = 200.0, subrange::range_error) ;
  THROWS_EXCEPTION(a = -5.0, subrange::range_error) ;
}

void assignTestFloat() {
  SubFloat a (9.0) ;
  SubFloat b (20.0) ;
  a = b ;
  IS_TRUE(a == b) ;
  IS_TRUE(a == 20.0) ;
}

void addAssignTestFloat() {
  SubFloat a (9.0) ;
  SubFloat b (20.0) ;
  a += b ;
  IS_TRUE(a == 29.0) ;
  a += 10 ;
  IS_TRUE(a == 39.0) ;
  a += -10 ;
  IS_TRUE(a == 29.0) ;
  THROWS_EXCEPTION(a += 200.0, subrange::range_error) ;
}

void subtractAssignTestFloat() {
  SubFloat a (20.0) ;
  SubFloat b (9.0) ;
  a -= b ;
  IS_TRUE(a == 11.0) ;
  a -= 5.0 ;
  IS_TRUE(a == 6.0) ;
  a -= -5.0 ;
  IS_TRUE(a == 11.0) ;
  THROWS_EXCEPTION(b -= a, subrange::range_error) ;
}

void multiplyAssignTestFloat() {
  SubFloat a (20.0) ;
  SubFloat b (3.0) ;
  a *= b ;
  IS_TRUE(a == 60.0) ;
  THROWS_EXCEPTION(a *= b, subrange::range_error) ;
}

void divideAssignTestFloat() {
  SubFloat a (20.0) ;
  SubFloat b (4.0) ;
  a /= b ;
  IS_TRUE(a == 5.0) ;
}

void addTestFloat() {
  SubFloat a (9.0) ;
  SubFloat b (20.0) ;
  a = a + b ;
  IS_TRUE(a == 29.0) ;
  a = a + 10.0 ;
  IS_TRUE(a == 39.0) ;
  a = a + -10.0 ;
  IS_TRUE(a == 29.0) ;
  a = 10.0 + a ;
  IS_TRUE(a == 39.0) ;
  a = -10.0 + a ;
  IS_TRUE(a == 29.0) ;
}

void subtractTestFloat() {
  SubFloat a (20.0) ;
  SubFloat b (9.0) ;
  a = a - b ;
  IS_TRUE(a == 11.0) ;
}

void multiplyTestFloat() {
  SubFloat a (20.0) ;
  SubFloat b (3.0) ;
  a = a * b ;
  IS_TRUE(a == 60.0) ;
}

void divideTestFloat() {
  SubFloat a (20.0) ;
  SubFloat b (4.0) ;
  a = a / b ;
  IS_TRUE(a == 5.0) ;
}

void equalsTestFloat() {
  SubFloat a (9.0) ;
  SubFloat b (9.0) ;
  IS_TRUE(a == b) ;
}

void notEqualsTestFloat() {
  SubFloat a (9.0) ;
  SubFloat b (8.0) ;
  IS_TRUE(a != b) ;
}

void lessThanTestFloat() {
  SubFloat a (8.0) ;
  SubFloat b (9.0) ;
  IS_TRUE(a < b) ;
  IS_TRUE(!(a >= b)) ;
}

void lessThanEqualToTestFloat() {
  SubFloat a (8.0) ;
  SubFloat b (8.0) ;
  IS_TRUE(a <= b) ;
  IS_TRUE(!(a > b)) ;
}

void greaterThanTestFloat() {
  SubFloat a (8.0) ;
  SubFloat b (9.0) ;
  IS_TRUE(b > a) ;
  IS_TRUE(!(b <= a)) ;
}

void greaterThanEqualToTestFloat() {
  SubFloat a (8.0) ;
  SubFloat b (8.0) ;
  IS_TRUE(a >= b) ;
  IS_TRUE(!(a < b)) ;
}

int main ( ) {
  using namespace Aeryn ;
  TestRunner testRunner ;  

  testRunner.Add ( TestCase ( USE_NAME ( createDefaultTestEnum ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( assignTestEnum ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( equalsTestEnum ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( notEqualsTestEnum ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( lessThanTestEnum ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( lessThanEqualToTestEnum ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( greaterThanTestEnum ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( greaterThanEqualToTestEnum ) ) ) ;

  testRunner.Add ( TestCase ( USE_NAME ( createDefaultTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( preincrementTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( postincrementTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( predecrementTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( postdecrementTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( assignLiteralTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( assignTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( addAssignTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( subtractAssignTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( multiplyAssignTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( divideAssignTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( remainderAssignTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( xorAssignTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( andAssignTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( orAssignTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftLeftAssignTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftRightAssignTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( addTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( subtractTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( multiplyTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( divideTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( remainderTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( xorTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( andTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( orTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftLeftTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftRightTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( equalsTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( notEqualsTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( lessThanTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( lessThanEqualToTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( greaterThanTestIntException ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( greaterThanEqualToTestIntException ) ) ) ;

  testRunner.Add ( TestCase ( USE_NAME ( createDefaultTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( preincrementTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( postincrementTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( predecrementTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( postdecrementTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( assignLiteralTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( assignTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( addAssignTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( subtractAssignTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( multiplyAssignTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( divideAssignTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( remainderAssignTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( xorAssignTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( andAssignTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( orAssignTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftLeftAssignTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftRightAssignTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( addTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( subtractTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( multiplyTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( divideTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( remainderTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( xorTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( andTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( orTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftLeftTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftRightTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( equalsTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( notEqualsTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( lessThanTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( lessThanEqualToTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( greaterThanTestIntModulo ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( greaterThanEqualToTestIntModulo ) ) ) ;

  testRunner.Add ( TestCase ( USE_NAME ( createDefaultTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( preincrementTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( postincrementTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( predecrementTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( postdecrementTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( assignLiteralTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( assignTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( addAssignTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( subtractAssignTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( multiplyAssignTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( divideAssignTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( remainderAssignTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( xorAssignTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( andAssignTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( orAssignTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftLeftAssignTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftRightAssignTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( addTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( subtractTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( multiplyTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( divideTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( remainderTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( xorTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( andTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( orTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftLeftTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftRightTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( equalsTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( notEqualsTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( lessThanTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( lessThanEqualToTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( greaterThanTestIntSaturated ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( greaterThanEqualToTestIntSaturated ) ) ) ;

  testRunner.Add ( TestCase ( USE_NAME ( createDefaultTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( preincrementTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( postincrementTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( predecrementTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( postdecrementTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( assignLiteralTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( assignTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( addAssignTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( subtractAssignTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( multiplyAssignTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( divideAssignTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( remainderAssignTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( xorAssignTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( andAssignTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( orAssignTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftLeftAssignTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftRightAssignTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( addTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( subtractTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( multiplyTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( divideTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( remainderTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( xorTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( andTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( orTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftLeftTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( shiftRightTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( equalsTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( notEqualsTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( lessThanTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( lessThanEqualToTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( greaterThanTestIntNaN ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( greaterThanEqualToTestIntNaN ) ) ) ;

  testRunner.Add ( TestCase ( USE_NAME ( createDefaultTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( preincrementTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( postincrementTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( predecrementTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( postdecrementTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( assignLiteralTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( assignTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( addAssignTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( subtractAssignTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( multiplyAssignTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( divideAssignTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( addTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( subtractTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( multiplyTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( divideTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( equalsTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( notEqualsTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( lessThanTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( lessThanEqualToTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( greaterThanTestFloat ) ) ) ;
  testRunner.Add ( TestCase ( USE_NAME ( greaterThanEqualToTestFloat ) ) ) ;

  return testRunner.Run ( ) ;
}
