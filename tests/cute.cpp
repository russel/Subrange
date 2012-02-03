//  Unit test for a subrange type template for C++
//
//  Copyright (c) 2011 Russel Winder
//
//  Distributed under the Boost Software License, Version 1.0.  See
//  http://www.boost.org/LICENSE_1_0.txt.

/**
 *  @file
 *
 *  A test program (using CUTE) for the <code>subrange</code> type.
 *
 *  <p>This is in serious need of extending with far more test cases.</p>
 *
 *  <p>Copyright (c) 2011  Russel Winder.</p>
 *
 *  @author Russel Winder
 *  @version 1.0
 *  @date 2011-06-29 14:03+01:00
 */

#include "cute/cute.h"

#include "subrange.hpp"

enum Day { monday, tuesday, wednesday, thursday, friday, saturday, sunday } ;

typedef subrange::subrange<subrange::ordinal_range<Day, monday, friday> > Weekday ;

void createDefaultTestEnum() {
  Weekday a ;
  ASSERT_EQUAL(a , monday) ;
}

void assignTestEnum() {
  Weekday a (monday) ;
  Weekday b (tuesday) ;
  a = b ;
  ASSERT_EQUAL(a , b) ;
}

void equalsTestEnum() {
  Weekday a (monday) ;
  Weekday b (monday) ;
  ASSERT_EQUAL(a , b) ;
}

void notEqualsTestEnum() {
  Weekday a (monday) ;
  Weekday b (tuesday) ;
  ASSERT(a != b) ;
}

void lessThanTestEnum() {
  Weekday a (monday) ;
  Weekday b (tuesday) ;
  ASSERT(a < b) ;
  ASSERT(!(a >= b)) ;
}

void lessThanEqualToTestEnum() {
  Weekday a (monday) ;
  Weekday b (monday) ;
  ASSERT(a <= b) ;
  ASSERT(!(a > b)) ;
}

void greaterThanTestEnum() {
  Weekday a (monday) ;
  Weekday b (tuesday) ;
  ASSERT(b > a) ;
  ASSERT(!(b <= a)) ;
}

void greaterThanEqualToTestEnum() {
  Weekday a (monday) ;
  Weekday b (monday) ;
  ASSERT(a >= b) ;
  ASSERT(!(a < b)) ;
}


typedef subrange::subrange<subrange::ordinal_range<short, 1, 99> > SubIntException ;

void createDefaultTestIntException() {
  SubIntException a ;
  ASSERT_EQUAL(a , 1) ;
}

void preincrementTestIntException() {
  SubIntException a (9) ;
  ++a ;
  ASSERT_EQUAL(a , 10) ;
}

void postincrementTestIntException() {
  SubIntException a (9) ;
  a++ ;
  ASSERT_EQUAL(a , 10) ;
}

void predecrementTestIntException() {
  SubIntException a (9) ;
  --a ;
  ASSERT_EQUAL(a , 8) ;
}

void postdecrementTestIntException() {
  SubIntException a (9) ;
  a-- ;
  ASSERT_EQUAL(a , 8) ;
}

void assignLiteralTestIntException() {
  SubIntException a (9) ;
  a = 20 ;
  ASSERT_EQUAL(a , 20) ;
  //THROWS_EXCEPTION(a = 200, subrange::range_error) ;
  //THROWS_EXCEPTION(a = -5, subrange::range_error) ;
}

void assignTestIntException() {
  SubIntException a (9) ;
  SubIntException b (20) ;
  a = b ;
  ASSERT_EQUAL(a , b) ;
  ASSERT_EQUAL(a , 20) ;
}

void addAssignTestIntException() {
  SubIntException a (9) ;
  SubIntException b (20) ;
  a += b ;
  ASSERT_EQUAL(a , 29) ;
  a += 10 ;
  ASSERT_EQUAL(a , 39) ;
  a += -10 ;
  ASSERT_EQUAL(a , 29) ;
  //THROWS_EXCEPTION(a += 200, subrange::range_error) ;
}

void subtractAssignTestIntException() {
  SubIntException a (20) ;
  SubIntException b (9) ;
  a -= b ;
  ASSERT_EQUAL(a , 11) ;
  a -= 5 ;
  ASSERT_EQUAL(a , 6) ;
  a -= -5 ;
  ASSERT_EQUAL(a , 11) ;
  //THROWS_EXCEPTION(b -= a, subrange::range_error) ;
}

void multiplyAssignTestIntException() {
  SubIntException a (20) ;
  SubIntException b (3) ;
  a *= b ;
  ASSERT_EQUAL(a , 60) ;
  //THROWS_EXCEPTION(a *= b, subrange::range_error) ;
}

void divideAssignTestIntException() {
  SubIntException a (20) ;
  SubIntException b (3) ;
  a /= b ;
  ASSERT_EQUAL(a , 6) ;
}

void remainderAssignTestIntException() {
  SubIntException a (20) ;
  SubIntException b (3) ;
  a %= b ;
  ASSERT_EQUAL(a , 2) ;
}

void xorAssignTestIntException() {
  SubIntException a (0x12) ;
  SubIntException b (0x03) ;
  a ^= b ;
  ASSERT_EQUAL(a , 0x11) ;
}

void andAssignTestIntException() {
  SubIntException a (0x12) ;
  SubIntException b (0x03) ;
  a &= b ;
  ASSERT_EQUAL(a , 0x02) ;
}

void orAssignTestIntException() {
  SubIntException a (0x12) ;
  SubIntException b (0x03) ;
  a |= b ;
  ASSERT_EQUAL(a , 0x13) ;
}

void shiftLeftAssignTestIntException() {
  SubIntException a (0x12) ;
  a <<= 1 ;
  ASSERT_EQUAL(a , 0x24) ;
}

void shiftRightAssignTestIntException() {
  SubIntException a (0x12) ;
  a >>= 1 ;
  ASSERT_EQUAL(a , 0x09) ;
}

void addTestIntException() {
  SubIntException a (9) ;
  SubIntException b (20) ;
  a = a + b ;
  ASSERT_EQUAL(a , 29) ;
  a = a + 10 ;
  ASSERT_EQUAL(a , 39) ;
  a = a + -10 ;
  ASSERT_EQUAL(a , 29) ;
  a = 10 + a ;
  ASSERT_EQUAL(a , 39) ;
  a = -10 + a ;
  ASSERT_EQUAL(a , 29) ;
}

void subtractTestIntException() {
  SubIntException a (20) ;
  SubIntException b (9) ;
  a = a - b ;
  ASSERT_EQUAL(a , 11) ;
}

void multiplyTestIntException() {
  SubIntException a (20) ;
  SubIntException b (3) ;
  a = a * b ;
  ASSERT_EQUAL(a , 60) ;
}

void divideTestIntException() {
  SubIntException a (20) ;
  SubIntException b (3) ;
  a = a / b ;
  ASSERT_EQUAL(a , 6) ;
}

void remainderTestIntException() {
  SubIntException a (20) ;
  SubIntException b (3) ;
  a = a % b ;
  ASSERT_EQUAL(a , 2) ;
}

void xorTestIntException() {
  SubIntException a (0x12) ;
  SubIntException b (0x03) ;
  a = a ^ b ;
  ASSERT_EQUAL(a , 0x11) ;
}

void andTestIntException() {
  SubIntException a (0x12) ;
  SubIntException b (0x03) ;
  a = a & b ;
  ASSERT_EQUAL(a , 0x02) ;
}

void orTestIntException() {
  SubIntException a (0x12) ;
  SubIntException b (0x03) ;
  a = a | b ;
  ASSERT_EQUAL(a , 0x13) ;
}

void shiftLeftTestIntException() {
  SubIntException a (0x12) ;
  a = a << 1 ;
  ASSERT_EQUAL(a , 0x24) ;
  //THROWS_EXCEPTION( a = a << 3, subrange::range_error) ;
}

void shiftRightTestIntException() {
  SubIntException a (0x12) ;
  a = a >> 1 ;
  ASSERT_EQUAL(a , 0x09) ;
  //THROWS_EXCEPTION(a = a >> 5, subrange::range_error) ;
}

void equalsTestIntException() {
  SubIntException a (9) ;
  SubIntException b (9) ;
  ASSERT_EQUAL(a , b) ;
}

void notEqualsTestIntException() {
  SubIntException a (9) ;
  SubIntException b (8) ;
  ASSERT(a != b) ;
}

void lessThanTestIntException() {
  SubIntException a (8) ;
  SubIntException b (9) ;
  ASSERT(a < b) ;
  ASSERT(!(a >= b)) ;
}

void lessThanEqualToTestIntException() {
  SubIntException a (8) ;
  SubIntException b (8) ;
  ASSERT(a <= b) ;
  ASSERT(!(a > b)) ;
}

void greaterThanTestIntException() {
  SubIntException a (8) ;
  SubIntException b (9) ;
  ASSERT(b > a) ;
  ASSERT(!(b <= a)) ;
}

void greaterThanEqualToTestIntException() {
  SubIntException a (8) ;
  SubIntException b (8) ;
  ASSERT(a >= b) ;
  ASSERT(!(a < b)) ;
}

typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>, subrange::modulo_arithmetic> SubIntModulo ;

void createDefaultTestIntModulo() {
  SubIntModulo a ;
  ASSERT_EQUAL(a , 1) ;
}

void preincrementTestIntModulo() {
  SubIntModulo a (9) ;
  ++a ;
  ASSERT_EQUAL(a , 10) ;
}

void postincrementTestIntModulo() {
  SubIntModulo a (9) ;
  a++ ;
  ASSERT_EQUAL(a , 10) ;
}

void predecrementTestIntModulo() {
  SubIntModulo a (9) ;
  --a ;
  ASSERT_EQUAL(a , 8) ;
}

void postdecrementTestIntModulo() {
  SubIntModulo a (9) ;
  a-- ;
  ASSERT_EQUAL(a , 8) ;
}

void assignLiteralTestIntModulo() {
  SubIntModulo a (9) ;
  a = 20 ;
  ASSERT_EQUAL(a , 20) ;
  a = 200 ;
  ASSERT_EQUAL(a , 4) ;
  a = -5 ;
  ASSERT_EQUAL(a , 93) ;
}

void assignTestIntModulo() {
  SubIntModulo a (9) ;
  SubIntModulo b (20) ;
  a = b ;
  ASSERT_EQUAL(a , b) ;
  ASSERT_EQUAL(a , 20) ;
}

void addAssignTestIntModulo() {
  SubIntModulo a (9) ;
  SubIntModulo b (20) ;
  a += b ;
  ASSERT_EQUAL(a , 29) ;
  a += 10 ;
  ASSERT_EQUAL(a , 39) ;
  a += -10 ;
  ASSERT_EQUAL(a , 29) ;
  a += 200 ;
  ASSERT_EQUAL(a , 33) ;
}

void subtractAssignTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (9) ;
  a -= b ;
  ASSERT_EQUAL(a , 11) ;
  a -= 5 ;
  ASSERT_EQUAL(a , 6) ;
  a -= -5 ;
  ASSERT_EQUAL(a , 11) ;
  b -= a ;
  ASSERT_EQUAL(b , 96) ;
}

void multiplyAssignTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (3) ;
  a *= b ;
  ASSERT_EQUAL(a , 60) ;
  a *= b ;
  ASSERT_EQUAL(a , 82) ;
}

void divideAssignTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (3) ;
  a /= b ;
  ASSERT_EQUAL(a , 6) ;
}

void remainderAssignTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (3) ;
  a %= b ;
  ASSERT_EQUAL(a , 2) ;
}

void xorAssignTestIntModulo() {
  SubIntModulo a (0x12) ;
  SubIntModulo b (0x03) ;
  a ^= b ;
  ASSERT_EQUAL(a , 0x11) ;
}

void andAssignTestIntModulo() {
  SubIntModulo a (0x12) ;
  SubIntModulo b (0x03) ;
  a &= b ;
  ASSERT_EQUAL(a , 0x02) ;
}

void orAssignTestIntModulo() {
  SubIntModulo a (0x12) ;
  SubIntModulo b (0x03) ;
  a |= b ;
  ASSERT_EQUAL(a , 0x13) ;
}

void shiftLeftAssignTestIntModulo() {
  SubIntModulo a (0x12) ;
  a <<= 1 ;
  ASSERT_EQUAL(a , 0x24) ;
}

void shiftRightAssignTestIntModulo() {
  SubIntModulo a (0x12) ;
  a >>= 1 ;
  ASSERT_EQUAL(a , 0x09) ;
}

void addTestIntModulo() {
  SubIntModulo a (9) ;
  SubIntModulo b (20) ;
  a = a + b ;
  ASSERT_EQUAL(a , 29) ;
  a = a + 10 ;
  ASSERT_EQUAL(a , 39) ;
  a = a + -10 ;
  ASSERT_EQUAL(a , 29) ;
  a = 10 + a ;
  ASSERT_EQUAL(a , 39) ;
  a = -10 + a ;
  ASSERT_EQUAL(a , 29) ;
}

void subtractTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (9) ;
  a = a - b ;
  ASSERT_EQUAL(a , 11) ;
}

void multiplyTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (3) ;
  a = a * b ;
  ASSERT_EQUAL(a , 60) ;
}

void divideTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (3) ;
  a = a / b ;
  ASSERT_EQUAL(a , 6) ;
}

void remainderTestIntModulo() {
  SubIntModulo a (20) ;
  SubIntModulo b (3) ;
  a = a % b ;
  ASSERT_EQUAL(a , 2) ;
}

void xorTestIntModulo() {
  SubIntModulo a (0x12) ;
  SubIntModulo b (0x03) ;
  a = a ^ b ;
  ASSERT_EQUAL(a , 0x11) ;
}

void andTestIntModulo() {
  SubIntModulo a (0x12) ;
  SubIntModulo b (0x03) ;
  a = a & b ;
  ASSERT_EQUAL(a , 0x02) ;
}

void orTestIntModulo() {
  SubIntModulo a (0x12) ;
  SubIntModulo b (0x03) ;
  a = a | b ;
  ASSERT_EQUAL(a , 0x13) ;
}

void shiftLeftTestIntModulo() {
  SubIntModulo a (0x12) ;
  a = a << 1 ;
  ASSERT_EQUAL(a , 0x24) ;
  a = a << 3 ;
  ASSERT_EQUAL(a , 92) ;
}

void shiftRightTestIntModulo() {
  SubIntModulo a (0x12) ;
  a = a >> 1 ;
  ASSERT_EQUAL(a , 0x09) ;
  a = a >> 5 ;
  ASSERT_EQUAL(a , 98) ;
}

void equalsTestIntModulo() {
  SubIntModulo a (9) ;
  SubIntModulo b (9) ;
  ASSERT_EQUAL(a , b) ;
}

void notEqualsTestIntModulo() {
  SubIntModulo a (9) ;
  SubIntModulo b (8) ;
  ASSERT(a != b) ;
}

void lessThanTestIntModulo() {
  SubIntModulo a (8) ;
  SubIntModulo b (9) ;
  ASSERT(a < b) ;
  ASSERT(!(a >= b)) ;
}

void lessThanEqualToTestIntModulo() {
  SubIntModulo a (8) ;
  SubIntModulo b (8) ;
  ASSERT(a <= b) ;
  ASSERT(!(a > b)) ;
}

void greaterThanTestIntModulo() {
  SubIntModulo a (8) ;
  SubIntModulo b (9) ;
  ASSERT(b > a) ;
  ASSERT(!(b <= a)) ;
}

void greaterThanEqualToTestIntModulo() {
  SubIntModulo a (8) ;
  SubIntModulo b (8) ;
  ASSERT(a >= b) ;
  ASSERT(!(a < b)) ;
}

typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>, subrange::saturated_arithmetic> SubIntSaturated ;

void createDefaultTestIntSaturated() {
  SubIntSaturated a ;
  ASSERT_EQUAL(a , 1) ;
}

void preincrementTestIntSaturated() {
  SubIntSaturated a (9) ;
  ++a ;
  ASSERT_EQUAL(a , 10) ;
}

void postincrementTestIntSaturated() {
  SubIntSaturated a (9) ;
  a++ ;
  ASSERT_EQUAL(a , 10) ;
}

void predecrementTestIntSaturated() {
  SubIntSaturated a (9) ;
  --a ;
  ASSERT_EQUAL(a , 8) ;
}

void postdecrementTestIntSaturated() {
  SubIntSaturated a (9) ;
  a-- ;
  ASSERT_EQUAL(a , 8) ;
}

void assignLiteralTestIntSaturated() {
  SubIntSaturated a (9) ;
  a = 20 ;
  ASSERT_EQUAL(a , 20) ;
  a = 200 ;
  ASSERT_EQUAL(a , 99) ;
  a = -5 ;
  ASSERT_EQUAL(a , 1) ;
}

void assignTestIntSaturated() {
  SubIntSaturated a (9) ;
  SubIntSaturated b (20) ;
  a = b ;
  ASSERT_EQUAL(a , b) ;
  ASSERT_EQUAL(a , 20) ;
}

void addAssignTestIntSaturated() {
  SubIntSaturated a (9) ;
  SubIntSaturated b (20) ;
  a += b ;
  ASSERT_EQUAL(a , 29) ;
  a += 10 ;
  ASSERT_EQUAL(a , 39) ;
  a += -10 ;
  ASSERT_EQUAL(a , 29) ;
  a += 200 ;
  ASSERT_EQUAL(a , 99) ;
}

void subtractAssignTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (9) ;
  a -= b ;
  ASSERT_EQUAL(a , 11) ;
  a -= 5 ;
  ASSERT_EQUAL(a , 6) ;
  a -= -5 ;
  ASSERT_EQUAL(a , 11) ;
  b -= a ;
  ASSERT_EQUAL(b , 1) ;
}

void multiplyAssignTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (3) ;
  a *= b ;
  ASSERT_EQUAL(a , 60) ;
  a *= b ;
  ASSERT_EQUAL(a , 99) ;
}

void divideAssignTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (3) ;
  a /= b ;
  ASSERT_EQUAL(a , 6) ;
}

void remainderAssignTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (3) ;
  a %= b ;
  ASSERT_EQUAL(a , 2) ;
}

void xorAssignTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  SubIntSaturated b (0x03) ;
  a ^= b ;
  ASSERT_EQUAL(a , 0x11) ;
}

void andAssignTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  SubIntSaturated b (0x03) ;
  a &= b ;
  ASSERT_EQUAL(a , 0x02) ;
}

void orAssignTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  SubIntSaturated b (0x03) ;
  a |= b ;
  ASSERT_EQUAL(a , 0x13) ;
}

void shiftLeftAssignTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  a <<= 1 ;
  ASSERT_EQUAL(a , 0x24) ;
}

void shiftRightAssignTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  a >>= 1 ;
  ASSERT_EQUAL(a , 0x09) ;
}

void addTestIntSaturated() {
  SubIntSaturated a (9) ;
  SubIntSaturated b (20) ;
  a = a + b ;
  ASSERT_EQUAL(a , 29) ;
  a = a + 10 ;
  ASSERT_EQUAL(a , 39) ;
  a = a + -10 ;
  ASSERT_EQUAL(a , 29) ;
  a = 10 + a ;
  ASSERT_EQUAL(a , 39) ;
  a = -10 + a ;
  ASSERT_EQUAL(a , 29) ;
}

void subtractTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (9) ;
  a = a - b ;
  ASSERT_EQUAL(a , 11) ;
}

void multiplyTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (3) ;
  a = a * b ;
  ASSERT_EQUAL(a , 60) ;
}

void divideTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (3) ;
  a = a / b ;
  ASSERT_EQUAL(a , 6) ;
}

void remainderTestIntSaturated() {
  SubIntSaturated a (20) ;
  SubIntSaturated b (3) ;
  a = a % b ;
  ASSERT_EQUAL(a , 2) ;
}

void xorTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  SubIntSaturated b (0x03) ;
  a = a ^ b ;
  ASSERT_EQUAL(a , 0x11) ;
}

void andTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  SubIntSaturated b (0x03) ;
  a = a & b ;
  ASSERT_EQUAL(a , 0x02) ;
}

void orTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  SubIntSaturated b (0x03) ;
  a = a | b ;
  ASSERT_EQUAL(a , 0x13) ;
}

void shiftLeftTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  a = a << 1 ;
  ASSERT_EQUAL(a , 0x24) ;
  a = a << 3 ;
  ASSERT_EQUAL(a , 99) ;
}

void shiftRightTestIntSaturated() {
  SubIntSaturated a (0x12) ;
  a = a >> 1 ;
  ASSERT_EQUAL(a , 0x09) ;
  a = a >> 5 ;
  ASSERT_EQUAL(a , 1) ;
}

void equalsTestIntSaturated() {
  SubIntSaturated a (9) ;
  SubIntSaturated b (9) ;
  ASSERT_EQUAL(a , b) ;
}

void notEqualsTestIntSaturated() {
  SubIntSaturated a (9) ;
  SubIntSaturated b (8) ;
  ASSERT(a != b) ;
}

void lessThanTestIntSaturated() {
  SubIntSaturated a (8) ;
  SubIntSaturated b (9) ;
  ASSERT(a < b) ;
  ASSERT(!(a >= b)) ;
}

void lessThanEqualToTestIntSaturated() {
  SubIntSaturated a (8) ;
  SubIntSaturated b (8) ;
  ASSERT(a <= b) ;
  ASSERT(!(a > b)) ;
}

void greaterThanTestIntSaturated() {
  SubIntSaturated a (8) ;
  SubIntSaturated b (9) ;
  ASSERT(b > a) ;
  ASSERT(!(b <= a)) ;
}

void greaterThanEqualToTestIntSaturated() {
  SubIntSaturated a (8) ;
  SubIntSaturated b (8) ;
  ASSERT(a >= b) ;
  ASSERT(!(a < b)) ;
}

typedef subrange::ordinal_range<short, 1, 99> RangeTraits ;
typedef subrange::subrange<RangeTraits, subrange::NaN_arithmetic> SubIntNaN ;

inline bool isNaN(const SubIntNaN & s) { return subrange::NaN_arithmetic<RangeTraits>::isNaN(s) ; }

void createDefaultTestIntNaN() {
  SubIntNaN a ;
  ASSERT_EQUAL(a , 1) ;
}

void preincrementTestIntNaN() {
  SubIntNaN a (9) ;
  ++a ;
  ASSERT_EQUAL(a , 10) ;
}

void postincrementTestIntNaN() {
  SubIntNaN a (9) ;
  a++ ;
  ASSERT_EQUAL(a , 10) ;
}

void predecrementTestIntNaN() {
  SubIntNaN a (9) ;
  --a ;
  ASSERT_EQUAL(a , 8) ;
}

void postdecrementTestIntNaN() {
  SubIntNaN a (9) ;
  a-- ;
  ASSERT_EQUAL(a , 8) ;
}

void assignLiteralTestIntNaN() {
  SubIntNaN a (9) ;
  a = 20 ;
  ASSERT_EQUAL(a , 20) ;
  a = 200 ;
  ASSERT(isNaN(a)) ;
  a = -5 ;
  ASSERT(isNaN(a)) ;
}

void assignTestIntNaN() {
  SubIntNaN a (9) ;
  SubIntNaN b (20) ;
  a = b ;
  ASSERT_EQUAL(a , b) ;
  ASSERT_EQUAL(a , 20) ;
}

void addAssignTestIntNaN() {
  SubIntNaN a (9) ;
  SubIntNaN b (20) ;
  a += b ;
  ASSERT_EQUAL(a , 29) ;
  a += 10 ;
  ASSERT_EQUAL(a , 39) ;
  a += -10 ;
  ASSERT_EQUAL(a , 29) ;
  a += 200 ;
  ASSERT(isNaN(a)) ;
}

void subtractAssignTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (9) ;
  a -= b ;
  ASSERT_EQUAL(a , 11) ;
  a -= 5 ;
  ASSERT_EQUAL(a , 6) ;
  a -= -5 ;
  ASSERT_EQUAL(a , 11) ;
  b -= a ;
  ASSERT(isNaN(b)) ;
}

void multiplyAssignTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (3) ;
  a *= b ;
  ASSERT_EQUAL(a , 60) ;
  a *= b ;
  ASSERT(isNaN(a)) ;
}

void divideAssignTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (3) ;
  a /= b ;
  ASSERT_EQUAL(a , 6) ;
}

void remainderAssignTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (3) ;
  a %= b ;
  ASSERT_EQUAL(a , 2) ;
}

void xorAssignTestIntNaN() {
  SubIntNaN a (0x12) ;
  SubIntNaN b (0x03) ;
  a ^= b ;
  ASSERT_EQUAL(a , 0x11) ;
}

void andAssignTestIntNaN() {
  SubIntNaN a (0x12) ;
  SubIntNaN b (0x03) ;
  a &= b ;
  ASSERT_EQUAL(a , 0x02) ;
}

void orAssignTestIntNaN() {
  SubIntNaN a (0x12) ;
  SubIntNaN b (0x03) ;
  a |= b ;
  ASSERT_EQUAL(a , 0x13) ;
}

void shiftLeftAssignTestIntNaN() {
  SubIntNaN a (0x12) ;
  a <<= 1 ;
  ASSERT_EQUAL(a , 0x24) ;
}

void shiftRightAssignTestIntNaN() {
  SubIntNaN a (0x12) ;
  a >>= 1 ;
  ASSERT_EQUAL(a , 0x09) ;
}

void addTestIntNaN() {
  SubIntNaN a (9) ;
  SubIntNaN b (20) ;
  a = a + b ;
  ASSERT_EQUAL(a , 29) ;
  a = a + 10 ;
  ASSERT_EQUAL(a , 39) ;
  a = a + -10 ;
  ASSERT_EQUAL(a , 29) ;
  a = 10 + a ;
  ASSERT_EQUAL(a , 39) ;
  a = -10 + a ;
  ASSERT_EQUAL(a , 29) ;
}

void subtractTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (9) ;
  a = a - b ;
  ASSERT_EQUAL(a , 11) ;
}

void multiplyTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (3) ;
  a = a * b ;
  ASSERT_EQUAL(a , 60) ;
}

void divideTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (3) ;
  a = a / b ;
  ASSERT_EQUAL(a , 6) ;
}

void remainderTestIntNaN() {
  SubIntNaN a (20) ;
  SubIntNaN b (3) ;
  a = a % b ;
  ASSERT_EQUAL(a , 2) ;
}

void xorTestIntNaN() {
  SubIntNaN a (0x12) ;
  SubIntNaN b (0x03) ;
  a = a ^ b ;
  ASSERT_EQUAL(a , 0x11) ;
}

void andTestIntNaN() {
  SubIntNaN a (0x12) ;
  SubIntNaN b (0x03) ;
  a = a & b ;
  ASSERT_EQUAL(a , 0x02) ;
}

void orTestIntNaN() {
  SubIntNaN a (0x12) ;
  SubIntNaN b (0x03) ;
  a = a | b ;
  ASSERT_EQUAL(a , 0x13) ;
}

void shiftLeftTestIntNaN() {
  SubIntNaN a (0x12) ;
  a = a << 1 ;
  ASSERT_EQUAL(a , 0x24) ;
  a = a << 3 ;
  ASSERT(isNaN(a)) ;
}

void shiftRightTestIntNaN() {
  SubIntNaN a (0x12) ;
  a = a >> 1 ;
  ASSERT_EQUAL(a , 0x09) ;
  a = a >> 5 ;
  ASSERT(isNaN(a)) ;
}

void equalsTestIntNaN() {
  SubIntNaN a (9) ;
  SubIntNaN b (9) ;
  ASSERT_EQUAL(a , b) ;
}

void notEqualsTestIntNaN() {
  SubIntNaN a (9) ;
  SubIntNaN b (8) ;
  ASSERT(a != b) ;
}

void lessThanTestIntNaN() {
  SubIntNaN a (8) ;
  SubIntNaN b (9) ;
  ASSERT(a < b) ;
  ASSERT(!(a >= b)) ;
}

void lessThanEqualToTestIntNaN() {
  SubIntNaN a (8) ;
  SubIntNaN b (8) ;
  ASSERT(a <= b) ;
  ASSERT(!(a > b)) ;
}

void greaterThanTestIntNaN() {
  SubIntNaN a (8) ;
  SubIntNaN b (9) ;
  ASSERT(b > a) ;
  ASSERT(!(b <= a)) ;
}

void greaterThanEqualToTestIntNaN() {
  SubIntNaN a (8) ;
  SubIntNaN b (8) ;
  ASSERT(a >= b) ;
  ASSERT(!(a < b)) ;
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
  ASSERT_EQUAL(a , 1.0) ;
}

void preincrementTestFloat() {
  SubFloat a (9.0) ;
  ++a ;
  ASSERT_EQUAL(a , 10.0) ;
}

void postincrementTestFloat() {
  SubFloat a (9.0) ;
  a++ ;
  ASSERT_EQUAL(a , 10.0) ;
}

void predecrementTestFloat() {
  SubFloat a (9.0) ;
  --a ;
  ASSERT_EQUAL(a , 8.0) ;
}

void postdecrementTestFloat() {
  SubFloat a (9.0) ;
  a-- ;
  ASSERT_EQUAL(a , 8.0) ;
}

void assignLiteralTestFloat() {
  SubFloat a (9.0) ;
  a = 20.0 ;
  ASSERT_EQUAL(a , 20.0) ;
  //THROWS_EXCEPTION(a = 200.0, subrange::range_error) ;
  //THROWS_EXCEPTION(a = -5.0, subrange::range_error) ;
}

void assignTestFloat() {
  SubFloat a (9.0) ;
  SubFloat b (20.0) ;
  a = b ;
  ASSERT_EQUAL(a , b) ;
  ASSERT_EQUAL(a , 20.0) ;
}

void addAssignTestFloat() {
  SubFloat a (9.0) ;
  SubFloat b (20.0) ;
  a += b ;
  ASSERT_EQUAL(a , 29.0) ;
  a += 10 ;
  ASSERT_EQUAL(a , 39.0) ;
  a += -10 ;
  ASSERT_EQUAL(a , 29.0) ;
  //THROWS_EXCEPTION(a += 200.0, subrange::range_error) ;
}

void subtractAssignTestFloat() {
  SubFloat a (20.0) ;
  SubFloat b (9.0) ;
  a -= b ;
  ASSERT_EQUAL(a , 11.0) ;
  a -= 5.0 ;
  ASSERT_EQUAL(a , 6.0) ;
  a -= -5.0 ;
  ASSERT_EQUAL(a , 11.0) ;
  //THROWS_EXCEPTION(b -= a, subrange::range_error) ;
}

void multiplyAssignTestFloat() {
  SubFloat a (20.0) ;
  SubFloat b (3.0) ;
  a *= b ;
  ASSERT_EQUAL(a , 60.0) ;
  //THROWS_EXCEPTION(a *= b, subrange::range_error) ;
}

void divideAssignTestFloat() {
  SubFloat a (20.0) ;
  SubFloat b (4.0) ;
  a /= b ;
  ASSERT_EQUAL(a , 5.0) ;
}

void addTestFloat() {
  SubFloat a (9.0) ;
  SubFloat b (20.0) ;
  a = a + b ;
  ASSERT_EQUAL(a , 29.0) ;
  a = a + 10.0 ;
  ASSERT_EQUAL(a , 39.0) ;
  a = a + -10.0 ;
  ASSERT_EQUAL(a , 29.0) ;
  a = 10.0 + a ;
  ASSERT_EQUAL(a , 39.0) ;
  a = -10.0 + a ;
  ASSERT_EQUAL(a , 29.0) ;
}

void subtractTestFloat() {
  SubFloat a (20.0) ;
  SubFloat b (9.0) ;
  a = a - b ;
  ASSERT_EQUAL(a , 11.0) ;
}

void multiplyTestFloat() {
  SubFloat a (20.0) ;
  SubFloat b (3.0) ;
  a = a * b ;
  ASSERT_EQUAL(a , 60.0) ;
}

void divideTestFloat() {
  SubFloat a (20.0) ;
  SubFloat b (4.0) ;
  a = a / b ;
  ASSERT_EQUAL(a , 5.0) ;
}

void equalsTestFloat() {
  SubFloat a (9.0) ;
  SubFloat b (9.0) ;
  ASSERT_EQUAL(a , b) ;
}

void notEqualsTestFloat() {
  SubFloat a (9.0) ;
  SubFloat b (8.0) ;
  ASSERT(a != b) ;
}

void lessThanTestFloat() {
  SubFloat a (8.0) ;
  SubFloat b (9.0) ;
  ASSERT(a < b) ;
  ASSERT(!(a >= b)) ;
}

void lessThanEqualToTestFloat() {
  SubFloat a (8.0) ;
  SubFloat b (8.0) ;
  ASSERT(a <= b) ;
  ASSERT(!(a > b)) ;
}

void greaterThanTestFloat() {
  SubFloat a (8.0) ;
  SubFloat b (9.0) ;
  ASSERT(b > a) ;
  ASSERT(!(b <= a)) ;
}

void greaterThanEqualToTestFloat() {
  SubFloat a (8.0) ;
  SubFloat b (8.0) ;
  ASSERT(a >= b) ;
  ASSERT(!(a < b)) ;
}

int main ( ) {

  cute::test tests[] = {
    CUTE ( createDefaultTestEnum ) ,
    CUTE ( assignTestEnum ) ,
    CUTE ( equalsTestEnum ) ,
    CUTE ( notEqualsTestEnum ) ,
    CUTE ( lessThanTestEnum ) ,
    CUTE ( lessThanEqualToTestEnum ) ,
    CUTE ( greaterThanTestEnum ) ,
    CUTE ( greaterThanEqualToTestEnum ) ,
    
    CUTE ( createDefaultTestIntException ) ,
    CUTE ( preincrementTestIntException ) ,
    CUTE ( postincrementTestIntException ) ,
    CUTE ( predecrementTestIntException ) ,
    CUTE ( postdecrementTestIntException ) ,
    CUTE ( assignLiteralTestIntException ) ,
    CUTE ( assignTestIntException ) ,
    CUTE ( addAssignTestIntException ) ,
    CUTE ( subtractAssignTestIntException ) ,
    CUTE ( multiplyAssignTestIntException ) ,
    CUTE ( divideAssignTestIntException ) ,
    CUTE ( remainderAssignTestIntException ) ,
    CUTE ( xorAssignTestIntException ) ,
    CUTE ( andAssignTestIntException ) ,
    CUTE ( orAssignTestIntException ) ,
    CUTE ( shiftLeftAssignTestIntException ) ,
    CUTE ( shiftRightAssignTestIntException ) ,
    CUTE ( addTestIntException ) ,
    CUTE ( subtractTestIntException ) ,
    CUTE ( multiplyTestIntException ) ,
    CUTE ( divideTestIntException ) ,
    CUTE ( remainderTestIntException ) ,
    CUTE ( xorTestIntException ) ,
    CUTE ( andTestIntException ) ,
    CUTE ( orTestIntException ) ,
    CUTE ( shiftLeftTestIntException ) ,
    CUTE ( shiftRightTestIntException ) ,
    CUTE ( equalsTestIntException ) ,
    CUTE ( notEqualsTestIntException ) ,
    CUTE ( lessThanTestIntException ) ,
    CUTE ( lessThanEqualToTestIntException ) ,
    CUTE ( greaterThanTestIntException ) ,
    CUTE ( greaterThanEqualToTestIntException ) ,
    
    CUTE ( createDefaultTestIntModulo ) ,
    CUTE ( preincrementTestIntModulo ) ,
    CUTE ( postincrementTestIntModulo ) ,
    CUTE ( predecrementTestIntModulo ) ,
    CUTE ( postdecrementTestIntModulo ) ,
    CUTE ( assignLiteralTestIntModulo ) ,
    CUTE ( assignTestIntModulo ) ,
    CUTE ( addAssignTestIntModulo ) ,
    CUTE ( subtractAssignTestIntModulo ) ,
    CUTE ( multiplyAssignTestIntModulo ) ,
    CUTE ( divideAssignTestIntModulo ) ,
    CUTE ( remainderAssignTestIntModulo ) ,
    CUTE ( xorAssignTestIntModulo ) ,
    CUTE ( andAssignTestIntModulo ) ,
    CUTE ( orAssignTestIntModulo ) ,
    CUTE ( shiftLeftAssignTestIntModulo ) ,
    CUTE ( shiftRightAssignTestIntModulo ) ,
    CUTE ( addTestIntModulo ) ,
    CUTE ( subtractTestIntModulo ) ,
    CUTE ( multiplyTestIntModulo ) ,
    CUTE ( divideTestIntModulo ) ,
    CUTE ( remainderTestIntModulo ) ,
    CUTE ( xorTestIntModulo ) ,
    CUTE ( andTestIntModulo ) ,
    CUTE ( orTestIntModulo ) ,
    CUTE ( shiftLeftTestIntModulo ) ,
    CUTE ( shiftRightTestIntModulo ) ,
    CUTE ( equalsTestIntModulo ) ,
    CUTE ( notEqualsTestIntModulo ) ,
    CUTE ( lessThanTestIntModulo ) ,
    CUTE ( lessThanEqualToTestIntModulo ) ,
    CUTE ( greaterThanTestIntModulo ) ,
    CUTE ( greaterThanEqualToTestIntModulo ) ,
    
    CUTE ( createDefaultTestIntSaturated ) ,
    CUTE ( preincrementTestIntSaturated ) ,
    CUTE ( postincrementTestIntSaturated ) ,
    CUTE ( predecrementTestIntSaturated ) ,
    CUTE ( postdecrementTestIntSaturated ) ,
    CUTE ( assignLiteralTestIntSaturated ) ,
    CUTE ( assignTestIntSaturated ) ,
    CUTE ( addAssignTestIntSaturated ) ,
    CUTE ( subtractAssignTestIntSaturated ) ,
    CUTE ( multiplyAssignTestIntSaturated ) ,
    CUTE ( divideAssignTestIntSaturated ) ,
    CUTE ( remainderAssignTestIntSaturated ) ,
    CUTE ( xorAssignTestIntSaturated ) ,
    CUTE ( andAssignTestIntSaturated ) ,
    CUTE ( orAssignTestIntSaturated ) ,
    CUTE ( shiftLeftAssignTestIntSaturated ) ,
    CUTE ( shiftRightAssignTestIntSaturated ) ,
    CUTE ( addTestIntSaturated ) ,
    CUTE ( subtractTestIntSaturated ) ,
    CUTE ( multiplyTestIntSaturated ) ,
    CUTE ( divideTestIntSaturated ) ,
    CUTE ( remainderTestIntSaturated ) ,
    CUTE ( xorTestIntSaturated ) ,
    CUTE ( andTestIntSaturated ) ,
    CUTE ( orTestIntSaturated ) ,
    CUTE ( shiftLeftTestIntSaturated ) ,
    CUTE ( shiftRightTestIntSaturated ) ,
    CUTE ( equalsTestIntSaturated ) ,
    CUTE ( notEqualsTestIntSaturated ) ,
    CUTE ( lessThanTestIntSaturated ) ,
    CUTE ( lessThanEqualToTestIntSaturated ) ,
    CUTE ( greaterThanTestIntSaturated ) ,
    CUTE ( greaterThanEqualToTestIntSaturated ) ,
    
    CUTE ( createDefaultTestIntNaN ) ,
    CUTE ( preincrementTestIntNaN ) ,
    CUTE ( postincrementTestIntNaN ) ,
    CUTE ( predecrementTestIntNaN ) ,
    CUTE ( postdecrementTestIntNaN ) ,
    CUTE ( assignLiteralTestIntNaN ) ,
    CUTE ( assignTestIntNaN ) ,
    CUTE ( addAssignTestIntNaN ) ,
    CUTE ( subtractAssignTestIntNaN ) ,
    CUTE ( multiplyAssignTestIntNaN ) ,
    CUTE ( divideAssignTestIntNaN ) ,
    CUTE ( remainderAssignTestIntNaN ) ,
    CUTE ( xorAssignTestIntNaN ) ,
    CUTE ( andAssignTestIntNaN ) ,
    CUTE ( orAssignTestIntNaN ) ,
    CUTE ( shiftLeftAssignTestIntNaN ) ,
    CUTE ( shiftRightAssignTestIntNaN ) ,
    CUTE ( addTestIntNaN ) ,
    CUTE ( subtractTestIntNaN ) ,
    CUTE ( multiplyTestIntNaN ) ,
    CUTE ( divideTestIntNaN ) ,
    CUTE ( remainderTestIntNaN ) ,
    CUTE ( xorTestIntNaN ) ,
    CUTE ( andTestIntNaN ) ,
    CUTE ( orTestIntNaN ) ,
    CUTE ( shiftLeftTestIntNaN ) ,
    CUTE ( shiftRightTestIntNaN ) ,
    CUTE ( equalsTestIntNaN ) ,
    CUTE ( notEqualsTestIntNaN ) ,
    CUTE ( lessThanTestIntNaN ) ,
    CUTE ( lessThanEqualToTestIntNaN ) ,
    CUTE ( greaterThanTestIntNaN ) ,
    CUTE ( greaterThanEqualToTestIntNaN ) ,
    
    CUTE ( createDefaultTestFloat ) ,
    CUTE ( preincrementTestFloat ) ,
    CUTE ( postincrementTestFloat ) ,
    CUTE ( predecrementTestFloat ) ,
    CUTE ( postdecrementTestFloat ) ,
    CUTE ( assignLiteralTestFloat ) ,
    CUTE ( assignTestFloat ) ,
    CUTE ( addAssignTestFloat ) ,
    CUTE ( subtractAssignTestFloat ) ,
    CUTE ( multiplyAssignTestFloat ) ,
    CUTE ( divideAssignTestFloat ) ,
    CUTE ( addTestFloat ) ,
    CUTE ( subtractTestFloat ) ,
    CUTE ( multiplyTestFloat ) ,
    CUTE ( divideTestFloat ) ,
    CUTE ( equalsTestFloat ) ,
    CUTE ( notEqualsTestFloat ) ,
    CUTE ( lessThanTestFloat ) ,
    CUTE ( lessThanEqualToTestFloat ) ,
    CUTE ( greaterThanTestFloat ) ,
    CUTE ( greaterThanEqualToTestFloat )
  } ;
  cute::runner<cute::ide_listener> run ;
  cute::suite s ( tests , tests + ( sizeof(tests) / sizeof(tests[0]) ) ) ;
  return run ( s , "suite" ) ;
}
