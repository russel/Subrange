//  Unit test for a subrange type template for C++
//
//  Copyright © 2011–2013 Russel Winder
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
 *  <p>Copyright © 2011–2013  Russel Winder.</p>
 *
 *  @author Russel Winder
 *  @version 1.2
 *  @date 2013-04-12T11:25+01:00
 */

#include "cute/cute.h"
#include "cute/ide_listener.h"
#include "cute/cute_runner.h"

#include "subrange.hpp"

enum Day {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

typedef subrange::subrange<subrange::ordinal_range<Day, monday, friday>> Weekday;

void createDefaultTestEnum() {
  Weekday a;
  ASSERT_EQUAL(a, monday);
}

void assignTestEnum() {
  Weekday a {monday};
  Weekday b {tuesday};
  a = b;
  ASSERT_EQUAL(a, b);
}

void equalsTestEnum() {
  Weekday a {monday};
  Weekday b {monday};
  ASSERT_EQUAL(a, b);
}

void notEqualsTestEnum() {
  Weekday a {monday};
  Weekday b {tuesday};
  ASSERT(a != b);
}

void lessThanTestEnum() {
  Weekday a {monday};
  Weekday b {tuesday};
  ASSERT(a < b);
  ASSERT(!(a >= b));
}

void lessThanEqualToTestEnum() {
  Weekday a {monday};
  Weekday b {monday};
  ASSERT(a <= b);
  ASSERT(!(a > b));
}

void greaterThanTestEnum() {
  Weekday a {monday};
  Weekday b {tuesday};
  ASSERT(b > a);
  ASSERT(!(b <= a));
}

void greaterThanEqualToTestEnum() {
  Weekday a {monday};
  Weekday b {monday};
  ASSERT(a >= b);
  ASSERT(!(a < b));
}


typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>> SubIntException;

void createDefaultTestIntException() {
  SubIntException a;
  ASSERT_EQUAL(a, 1);
}

void preincrementTestIntException() {
  SubIntException a {9};
  ++a;
  ASSERT_EQUAL(a, 10);
}

void postincrementTestIntException() {
  SubIntException a {9};
  a++;
  ASSERT_EQUAL(a, 10);
}

void predecrementTestIntException() {
  SubIntException a {9};
  --a;
  ASSERT_EQUAL(a, 8);
}

void postdecrementTestIntException() {
  SubIntException a {9};
  a--;
  ASSERT_EQUAL(a, 8);
}

void assignLiteralTestIntException() {
  SubIntException a {9};
  a = 20;
  ASSERT_EQUAL(a, 20);
  //THROWS_EXCEPTION(a = 200, subrange::range_error);
  //THROWS_EXCEPTION(a = -5, subrange::range_error);
}

void assignTestIntException() {
  SubIntException a {9};
  SubIntException b {20};
  a = b;
  ASSERT_EQUAL(a, b);
  ASSERT_EQUAL(a, 20);
}

void addAssignTestIntException() {
  SubIntException a {9};
  SubIntException b {20};
  a += b;
  ASSERT_EQUAL(a, 29);
  a += 10;
  ASSERT_EQUAL(a, 39);
  a += -10;
  ASSERT_EQUAL(a, 29);
  //THROWS_EXCEPTION(a += 200, subrange::range_error);
}

void subtractAssignTestIntException() {
  SubIntException a {20};
  SubIntException b {9};
  a -= b;
  ASSERT_EQUAL(a, 11);
  a -= 5;
  ASSERT_EQUAL(a, 6);
  a -= -5;
  ASSERT_EQUAL(a, 11);
  //THROWS_EXCEPTION(b -= a, subrange::range_error);
}

void multiplyAssignTestIntException() {
  SubIntException a {20};
  SubIntException b {3};
  a *= b;
  ASSERT_EQUAL(a, 60);
  //THROWS_EXCEPTION(a *= b, subrange::range_error);
}

void divideAssignTestIntException() {
  SubIntException a {20};
  SubIntException b {3};
  a /= b;
  ASSERT_EQUAL(a, 6);
}

void remainderAssignTestIntException() {
  SubIntException a {20};
  SubIntException b {3};
  a %= b;
  ASSERT_EQUAL(a, 2);
}

void xorAssignTestIntException() {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a ^= b;
  ASSERT_EQUAL(a, 0x11);
}

void andAssignTestIntException() {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a &= b;
  ASSERT_EQUAL(a, 0x02);
}

void orAssignTestIntException() {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a |= b;
  ASSERT_EQUAL(a, 0x13);
}

void shiftLeftAssignTestIntException() {
  SubIntException a {0x12};
  a <<= 1;
  ASSERT_EQUAL(a, 0x24);
}

void shiftRightAssignTestIntException() {
  SubIntException a {0x12};
  a >>= 1;
  ASSERT_EQUAL(a, 0x09);
}

void addTestIntException() {
  SubIntException a {9};
  SubIntException b {20};
  a = a + b;
  ASSERT_EQUAL(a, 29);
  a = a + 10;
  ASSERT_EQUAL(a, 39);
  a = a + -10;
  ASSERT_EQUAL(a, 29);
  a = 10 + a;
  ASSERT_EQUAL(a, 39);
  a = -10 + a;
  ASSERT_EQUAL(a, 29);
}

void subtractTestIntException() {
  SubIntException a {20};
  SubIntException b {9};
  a = a - b;
  ASSERT_EQUAL(a, 11);
}

void multiplyTestIntException() {
  SubIntException a {20};
  SubIntException b {3};
  a = a * b;
  ASSERT_EQUAL(a, 60);
}

void divideTestIntException() {
  SubIntException a {20};
  SubIntException b {3};
  a = a / b;
  ASSERT_EQUAL(a, 6);
}

void remainderTestIntException() {
  SubIntException a {20};
  SubIntException b {3};
  a = a % b;
  ASSERT_EQUAL(a, 2);
}

void xorTestIntException() {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a = a ^ b;
  ASSERT_EQUAL(a, 0x11);
}

void andTestIntException() {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a = a & b;
  ASSERT_EQUAL(a, 0x02);
}

void orTestIntException() {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a = a | b;
  ASSERT_EQUAL(a, 0x13);
}

void shiftLeftTestIntException() {
  SubIntException a {0x12};
  a = a << 1;
  ASSERT_EQUAL(a, 0x24);
  //THROWS_EXCEPTION( a = a << 3, subrange::range_error);
}

void shiftRightTestIntException() {
  SubIntException a {0x12};
  a = a >> 1;
  ASSERT_EQUAL(a, 0x09);
  //THROWS_EXCEPTION(a = a >> 5, subrange::range_error);
}

void equalsTestIntException() {
  SubIntException a {9};
  SubIntException b {9};
  ASSERT_EQUAL(a, b);
}

void notEqualsTestIntException() {
  SubIntException a {9};
  SubIntException b {8};
  ASSERT(a != b);
}

void lessThanTestIntException() {
  SubIntException a {8};
  SubIntException b {9};
  ASSERT(a < b);
  ASSERT(!(a >= b));
}

void lessThanEqualToTestIntException() {
  SubIntException a {8};
  SubIntException b {8};
  ASSERT(a <= b);
  ASSERT(!(a > b));
}

void greaterThanTestIntException() {
  SubIntException a {8};
  SubIntException b {9};
  ASSERT(b > a);
  ASSERT(!(b <= a));
}

void greaterThanEqualToTestIntException() {
  SubIntException a {8};
  SubIntException b {8};
  ASSERT(a >= b);
  ASSERT(!(a < b));
}

typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>, subrange::modulo_arithmetic> SubIntModulo;

void createDefaultTestIntModulo() {
  SubIntModulo a;
  ASSERT_EQUAL(a, 1);
}

void preincrementTestIntModulo() {
  SubIntModulo a {9};
  ++a;
  ASSERT_EQUAL(a, 10);
}

void postincrementTestIntModulo() {
  SubIntModulo a {9};
  a++;
  ASSERT_EQUAL(a, 10);
}

void predecrementTestIntModulo() {
  SubIntModulo a {9};
  --a;
  ASSERT_EQUAL(a, 8);
}

void postdecrementTestIntModulo() {
  SubIntModulo a {9};
  a--;
  ASSERT_EQUAL(a, 8);
}

void assignLiteralTestIntModulo() {
  SubIntModulo a {9};
  a = 20;
  ASSERT_EQUAL(a, 20);
  a = 200;
  ASSERT_EQUAL(a, 4);
  a = -5;
  ASSERT_EQUAL(a, 93);
}

void assignTestIntModulo() {
  SubIntModulo a {9};
  SubIntModulo b {20};
  a = b;
  ASSERT_EQUAL(a, b);
  ASSERT_EQUAL(a, 20);
}

void addAssignTestIntModulo() {
  SubIntModulo a {9};
  SubIntModulo b {20};
  a += b;
  ASSERT_EQUAL(a, 29);
  a += 10;
  ASSERT_EQUAL(a, 39);
  a += -10;
  ASSERT_EQUAL(a, 29);
  a += 200;
  ASSERT_EQUAL(a, 33);
}

void subtractAssignTestIntModulo() {
  SubIntModulo a {20};
  SubIntModulo b {9};
  a -= b;
  ASSERT_EQUAL(a, 11);
  a -= 5;
  ASSERT_EQUAL(a, 6);
  a -= -5;
  ASSERT_EQUAL(a, 11);
  b -= a;
  ASSERT_EQUAL(b, 96);
}

void multiplyAssignTestIntModulo() {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a *= b;
  ASSERT_EQUAL(a, 60);
  a *= b;
  ASSERT_EQUAL(a, 82);
}

void divideAssignTestIntModulo() {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a /= b;
  ASSERT_EQUAL(a, 6);
}

void remainderAssignTestIntModulo() {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a %= b;
  ASSERT_EQUAL(a, 2);
}

void xorAssignTestIntModulo() {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a ^= b;
  ASSERT_EQUAL(a, 0x11);
}

void andAssignTestIntModulo() {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a &= b;
  ASSERT_EQUAL(a, 0x02);
}

void orAssignTestIntModulo() {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a |= b;
  ASSERT_EQUAL(a, 0x13);
}

void shiftLeftAssignTestIntModulo() {
  SubIntModulo a {0x12};
  a <<= 1;
  ASSERT_EQUAL(a, 0x24);
}

void shiftRightAssignTestIntModulo() {
  SubIntModulo a {0x12};
  a >>= 1;
  ASSERT_EQUAL(a, 0x09);
}

void addTestIntModulo() {
  SubIntModulo a {9};
  SubIntModulo b {20};
  a = a + b;
  ASSERT_EQUAL(a, 29);
  a = a + 10;
  ASSERT_EQUAL(a, 39);
  a = a + -10;
  ASSERT_EQUAL(a, 29);
  a = 10 + a;
  ASSERT_EQUAL(a, 39);
  a = -10 + a;
  ASSERT_EQUAL(a, 29);
}

void subtractTestIntModulo() {
  SubIntModulo a {20};
  SubIntModulo b {9};
  a = a - b;
  ASSERT_EQUAL(a, 11);
}

void multiplyTestIntModulo() {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a = a * b;
  ASSERT_EQUAL(a, 60);
}

void divideTestIntModulo() {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a = a / b;
  ASSERT_EQUAL(a, 6);
}

void remainderTestIntModulo() {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a = a % b;
  ASSERT_EQUAL(a, 2);
}

void xorTestIntModulo() {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a = a ^ b;
  ASSERT_EQUAL(a, 0x11);
}

void andTestIntModulo() {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a = a & b;
  ASSERT_EQUAL(a, 0x02);
}

void orTestIntModulo() {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a = a | b;
  ASSERT_EQUAL(a, 0x13);
}

void shiftLeftTestIntModulo() {
  SubIntModulo a {0x12};
  a = a << 1;
  ASSERT_EQUAL(a, 0x24);
  a = a << 3;
  ASSERT_EQUAL(a, 92);
}

void shiftRightTestIntModulo() {
  SubIntModulo a {0x12};
  a = a >> 1;
  ASSERT_EQUAL(a, 0x09);
  a = a >> 5;
  ASSERT_EQUAL(a, 98);
}

void equalsTestIntModulo() {
  SubIntModulo a {9};
  SubIntModulo b {9};
  ASSERT_EQUAL(a, b);
}

void notEqualsTestIntModulo() {
  SubIntModulo a {9};
  SubIntModulo b {8};
  ASSERT(a != b);
}

void lessThanTestIntModulo() {
  SubIntModulo a {8};
  SubIntModulo b {9};
  ASSERT(a < b);
  ASSERT(!(a >= b));
}

void lessThanEqualToTestIntModulo() {
  SubIntModulo a {8};
  SubIntModulo b {8};
  ASSERT(a <= b);
  ASSERT(!(a > b));
}

void greaterThanTestIntModulo() {
  SubIntModulo a {8};
  SubIntModulo b {9};
  ASSERT(b > a);
  ASSERT(!(b <= a));
}

void greaterThanEqualToTestIntModulo() {
  SubIntModulo a {8};
  SubIntModulo b {8};
  ASSERT(a >= b);
  ASSERT(!(a < b));
}

typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>, subrange::saturated_arithmetic> SubIntSaturated;

void createDefaultTestIntSaturated() {
  SubIntSaturated a;
  ASSERT_EQUAL(a, 1);
}

void preincrementTestIntSaturated() {
  SubIntSaturated a {9};
  ++a;
  ASSERT_EQUAL(a, 10);
}

void postincrementTestIntSaturated() {
  SubIntSaturated a {9};
  a++;
  ASSERT_EQUAL(a, 10);
}

void predecrementTestIntSaturated() {
  SubIntSaturated a {9};
  --a;
  ASSERT_EQUAL(a, 8);
}

void postdecrementTestIntSaturated() {
  SubIntSaturated a {9};
  a--;
  ASSERT_EQUAL(a, 8);
}

void assignLiteralTestIntSaturated() {
  SubIntSaturated a {9};
  a = 20;
  ASSERT_EQUAL(a, 20);
  a = 200;
  ASSERT_EQUAL(a, 99);
  a = -5;
  ASSERT_EQUAL(a, 1);
}

void assignTestIntSaturated() {
  SubIntSaturated a {9};
  SubIntSaturated b {20};
  a = b;
  ASSERT_EQUAL(a, b);
  ASSERT_EQUAL(a, 20);
}

void addAssignTestIntSaturated() {
  SubIntSaturated a {9};
  SubIntSaturated b {20};
  a += b;
  ASSERT_EQUAL(a, 29);
  a += 10;
  ASSERT_EQUAL(a, 39);
  a += -10;
  ASSERT_EQUAL(a, 29);
  a += 200;
  ASSERT_EQUAL(a, 99);
}

void subtractAssignTestIntSaturated() {
  SubIntSaturated a {20};
  SubIntSaturated b {9};
  a -= b;
  ASSERT_EQUAL(a, 11);
  a -= 5;
  ASSERT_EQUAL(a, 6);
  a -= -5;
  ASSERT_EQUAL(a, 11);
  b -= a;
  ASSERT_EQUAL(b, 1);
}

void multiplyAssignTestIntSaturated() {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a *= b;
  ASSERT_EQUAL(a, 60);
  a *= b;
  ASSERT_EQUAL(a, 99);
}

void divideAssignTestIntSaturated() {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a /= b;
  ASSERT_EQUAL(a, 6);
}

void remainderAssignTestIntSaturated() {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a %= b;
  ASSERT_EQUAL(a, 2);
}

void xorAssignTestIntSaturated() {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a ^= b;
  ASSERT_EQUAL(a, 0x11);
}

void andAssignTestIntSaturated() {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a &= b;
  ASSERT_EQUAL(a, 0x02);
}

void orAssignTestIntSaturated() {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a |= b;
  ASSERT_EQUAL(a, 0x13);
}

void shiftLeftAssignTestIntSaturated() {
  SubIntSaturated a {0x12};
  a <<= 1;
  ASSERT_EQUAL(a, 0x24);
}

void shiftRightAssignTestIntSaturated() {
  SubIntSaturated a {0x12};
  a >>= 1;
  ASSERT_EQUAL(a, 0x09);
}

void addTestIntSaturated() {
  SubIntSaturated a {9};
  SubIntSaturated b {20};
  a = a + b;
  ASSERT_EQUAL(a, 29);
  a = a + 10;
  ASSERT_EQUAL(a, 39);
  a = a + -10;
  ASSERT_EQUAL(a, 29);
  a = 10 + a;
  ASSERT_EQUAL(a, 39);
  a = -10 + a;
  ASSERT_EQUAL(a, 29);
}

void subtractTestIntSaturated() {
  SubIntSaturated a {20};
  SubIntSaturated b {9};
  a = a - b;
  ASSERT_EQUAL(a, 11);
}

void multiplyTestIntSaturated() {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a = a * b;
  ASSERT_EQUAL(a, 60);
}

void divideTestIntSaturated() {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a = a / b;
  ASSERT_EQUAL(a, 6);
}

void remainderTestIntSaturated() {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a = a % b;
  ASSERT_EQUAL(a, 2);
}

void xorTestIntSaturated() {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a = a ^ b;
  ASSERT_EQUAL(a, 0x11);
}

void andTestIntSaturated() {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a = a & b;
  ASSERT_EQUAL(a, 0x02);
}

void orTestIntSaturated() {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a = a | b;
  ASSERT_EQUAL(a, 0x13);
}

void shiftLeftTestIntSaturated() {
  SubIntSaturated a {0x12};
  a = a << 1;
  ASSERT_EQUAL(a, 0x24);
  a = a << 3;
  ASSERT_EQUAL(a, 99);
}

void shiftRightTestIntSaturated() {
  SubIntSaturated a {0x12};
  a = a >> 1;
  ASSERT_EQUAL(a, 0x09);
  a = a >> 5;
  ASSERT_EQUAL(a, 1);
}

void equalsTestIntSaturated() {
  SubIntSaturated a {9};
  SubIntSaturated b {9};
  ASSERT_EQUAL(a, b);
}

void notEqualsTestIntSaturated() {
  SubIntSaturated a {9};
  SubIntSaturated b {8};
  ASSERT(a != b);
}

void lessThanTestIntSaturated() {
  SubIntSaturated a {8};
  SubIntSaturated b {9};
  ASSERT(a < b);
  ASSERT(!(a >= b));
}

void lessThanEqualToTestIntSaturated() {
  SubIntSaturated a {8};
  SubIntSaturated b {8};
  ASSERT(a <= b);
  ASSERT(!(a > b));
}

void greaterThanTestIntSaturated() {
  SubIntSaturated a {8};
  SubIntSaturated b {9};
  ASSERT(b > a);
  ASSERT(!(b <= a));
}

void greaterThanEqualToTestIntSaturated() {
  SubIntSaturated a {8};
  SubIntSaturated b {8};
  ASSERT(a >= b);
  ASSERT(!(a < b));
}

typedef subrange::ordinal_range<short, 1, 99> RangeTraits;
typedef subrange::subrange<RangeTraits, subrange::NaN_arithmetic> SubIntNaN;

inline bool isNaN(const SubIntNaN & s) { return subrange::NaN_arithmetic<RangeTraits>::isNaN(s); }

void createDefaultTestIntNaN() {
  SubIntNaN a;
  ASSERT_EQUAL(a, 1);
}

void preincrementTestIntNaN() {
  SubIntNaN a {9};
  ++a;
  ASSERT_EQUAL(a, 10);
}

void postincrementTestIntNaN() {
  SubIntNaN a {9};
  a++;
  ASSERT_EQUAL(a, 10);
}

void predecrementTestIntNaN() {
  SubIntNaN a {9};
  --a;
  ASSERT_EQUAL(a, 8);
}

void postdecrementTestIntNaN() {
  SubIntNaN a {9};
  a--;
  ASSERT_EQUAL(a, 8);
}

void assignLiteralTestIntNaN() {
  SubIntNaN a {9};
  a = 20;
  ASSERT_EQUAL(a, 20);
  a = 200;
  ASSERT(isNaN(a));
  a = -5;
  ASSERT(isNaN(a));
}

void assignTestIntNaN() {
  SubIntNaN a {9};
  SubIntNaN b {20};
  a = b;
  ASSERT_EQUAL(a, b);
  ASSERT_EQUAL(a, 20);
}

void addAssignTestIntNaN() {
  SubIntNaN a {9};
  SubIntNaN b {20};
  a += b;
  ASSERT_EQUAL(a, 29);
  a += 10;
  ASSERT_EQUAL(a, 39);
  a += -10;
  ASSERT_EQUAL(a, 29);
  a += 200;
  ASSERT(isNaN(a));
}

void subtractAssignTestIntNaN() {
  SubIntNaN a {20};
  SubIntNaN b {9};
  a -= b;
  ASSERT_EQUAL(a, 11);
  a -= 5;
  ASSERT_EQUAL(a, 6);
  a -= -5;
  ASSERT_EQUAL(a, 11);
  b -= a;
  ASSERT(isNaN(b));
}

void multiplyAssignTestIntNaN() {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a *= b;
  ASSERT_EQUAL(a, 60);
  a *= b;
  ASSERT(isNaN(a));
}

void divideAssignTestIntNaN() {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a /= b;
  ASSERT_EQUAL(a, 6);
}

void remainderAssignTestIntNaN() {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a %= b;
  ASSERT_EQUAL(a, 2);
}

void xorAssignTestIntNaN() {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a ^= b;
  ASSERT_EQUAL(a, 0x11);
}

void andAssignTestIntNaN() {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a &= b;
  ASSERT_EQUAL(a, 0x02);
}

void orAssignTestIntNaN() {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a |= b;
  ASSERT_EQUAL(a, 0x13);
}

void shiftLeftAssignTestIntNaN() {
  SubIntNaN a {0x12};
  a <<= 1;
  ASSERT_EQUAL(a, 0x24);
}

void shiftRightAssignTestIntNaN() {
  SubIntNaN a {0x12};
  a >>= 1;
  ASSERT_EQUAL(a, 0x09);
}

void addTestIntNaN() {
  SubIntNaN a {9};
  SubIntNaN b {20};
  a = a + b;
  ASSERT_EQUAL(a, 29);
  a = a + 10;
  ASSERT_EQUAL(a, 39);
  a = a + -10;
  ASSERT_EQUAL(a, 29);
  a = 10 + a;
  ASSERT_EQUAL(a, 39);
  a = -10 + a;
  ASSERT_EQUAL(a, 29);
}

void subtractTestIntNaN() {
  SubIntNaN a {20};
  SubIntNaN b {9};
  a = a - b;
  ASSERT_EQUAL(a, 11);
}

void multiplyTestIntNaN() {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a = a * b;
  ASSERT_EQUAL(a, 60);
}

void divideTestIntNaN() {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a = a / b;
  ASSERT_EQUAL(a, 6);
}

void remainderTestIntNaN() {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a = a % b;
  ASSERT_EQUAL(a, 2);
}

void xorTestIntNaN() {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a = a ^ b;
  ASSERT_EQUAL(a, 0x11);
}

void andTestIntNaN() {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a = a & b;
  ASSERT_EQUAL(a, 0x02);
}

void orTestIntNaN() {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a = a | b;
  ASSERT_EQUAL(a, 0x13);
}

void shiftLeftTestIntNaN() {
  SubIntNaN a {0x12};
  a = a << 1;
  ASSERT_EQUAL(a, 0x24);
  a = a << 3;
  ASSERT(isNaN(a));
}

void shiftRightTestIntNaN() {
  SubIntNaN a {0x12};
  a = a >> 1;
  ASSERT_EQUAL(a, 0x09);
  a = a >> 5;
  ASSERT(isNaN(a));
}

void equalsTestIntNaN() {
  SubIntNaN a {9};
  SubIntNaN b {9};
  ASSERT_EQUAL(a, b);
}

void notEqualsTestIntNaN() {
  SubIntNaN a {9};
  SubIntNaN b {8};
  ASSERT(a != b);
}

void lessThanTestIntNaN() {
  SubIntNaN a {8};
  SubIntNaN b {9};
  ASSERT(a < b);
  ASSERT(!(a >= b));
}

void lessThanEqualToTestIntNaN() {
  SubIntNaN a {8};
  SubIntNaN b {8};
  ASSERT(a <= b);
  ASSERT(!(a > b));
}

void greaterThanTestIntNaN() {
  SubIntNaN a {8};
  SubIntNaN b {9};
  ASSERT(b > a);
  ASSERT(!(b <= a));
}

void greaterThanEqualToTestIntNaN() {
  SubIntNaN a {8};
  SubIntNaN b {8};
  ASSERT(a >= b);
  ASSERT(!(a < b));
}

//  Can't use any templates for defining floating point range traits as C++ forbids template parameters
//  that are not of ordinal type so we haver to do that manually.

class float_range {
 public :
  typedef double value_type;
  typedef subrange::range_error exception_type;
  static double min () { return 1.0; }
  static double max () { return 99.0; }
};

typedef subrange::subrange<float_range> SubFloat;

void createDefaultTestFloat() {
  SubFloat a;
  ASSERT_EQUAL(a, 1.0);
}

void preincrementTestFloat() {
  SubFloat a {9.0};
  ++a;
  ASSERT_EQUAL(a, 10.0);
}

void postincrementTestFloat() {
  SubFloat a {9.0};
  a++;
  ASSERT_EQUAL(a, 10.0);
}

void predecrementTestFloat() {
  SubFloat a {9.0};
  --a;
  ASSERT_EQUAL(a, 8.0);
}

void postdecrementTestFloat() {
  SubFloat a {9.0};
  a--;
  ASSERT_EQUAL(a, 8.0);
}

void assignLiteralTestFloat() {
  SubFloat a {9.0};
  a = 20.0;
  ASSERT_EQUAL(a, 20.0);
  //THROWS_EXCEPTION(a = 200.0, subrange::range_error);
  //THROWS_EXCEPTION(a = -5.0, subrange::range_error);
}

void assignTestFloat() {
  SubFloat a {9.0};
  SubFloat b {20.0};
  a = b;
  ASSERT_EQUAL(a, b);
  ASSERT_EQUAL(a, 20.0);
}

void addAssignTestFloat() {
  SubFloat a {9.0};
  SubFloat b {20.0};
  a += b;
  ASSERT_EQUAL(a, 29.0);
  a += 10;
  ASSERT_EQUAL(a, 39.0);
  a += -10;
  ASSERT_EQUAL(a, 29.0);
  //THROWS_EXCEPTION(a += 200.0, subrange::range_error);
}

void subtractAssignTestFloat() {
  SubFloat a {20.0};
  SubFloat b {9.0};
  a -= b;
  ASSERT_EQUAL(a, 11.0);
  a -= 5.0;
  ASSERT_EQUAL(a, 6.0);
  a -= -5.0;
  ASSERT_EQUAL(a, 11.0);
  //THROWS_EXCEPTION(b -= a, subrange::range_error);
}

void multiplyAssignTestFloat() {
  SubFloat a {20.0};
  SubFloat b {3.0};
  a *= b;
  ASSERT_EQUAL(a, 60.0);
  //THROWS_EXCEPTION(a *= b, subrange::range_error);
}

void divideAssignTestFloat() {
  SubFloat a {20.0};
  SubFloat b {4.0};
  a /= b;
  ASSERT_EQUAL(a, 5.0);
}

void addTestFloat() {
  SubFloat a {9.0};
  SubFloat b {20.0};
  a = a + b;
  ASSERT_EQUAL(a, 29.0);
  a = a + 10.0;
  ASSERT_EQUAL(a, 39.0);
  a = a + -10.0;
  ASSERT_EQUAL(a, 29.0);
  a = 10.0 + a;
  ASSERT_EQUAL(a, 39.0);
  a = -10.0 + a;
  ASSERT_EQUAL(a, 29.0);
}

void subtractTestFloat() {
  SubFloat a {20.0};
  SubFloat b {9.0};
  a = a - b;
  ASSERT_EQUAL(a, 11.0);
}

void multiplyTestFloat() {
  SubFloat a {20.0};
  SubFloat b {3.0};
  a = a * b;
  ASSERT_EQUAL(a, 60.0);
}

void divideTestFloat() {
  SubFloat a {20.0};
  SubFloat b {4.0};
  a = a / b;
  ASSERT_EQUAL(a, 5.0);
}

void equalsTestFloat() {
  SubFloat a {9.0};
  SubFloat b {9.0};
  ASSERT_EQUAL(a, b);
}

void notEqualsTestFloat() {
  SubFloat a {9.0};
  SubFloat b {8.0};
  ASSERT(a != b);
}

void lessThanTestFloat() {
  SubFloat a {8.0};
  SubFloat b {9.0};
  ASSERT(a < b);
  ASSERT(!(a >= b));
}

void lessThanEqualToTestFloat() {
  SubFloat a {8.0};
  SubFloat b {8.0};
  ASSERT(a <= b);
  ASSERT(!(a > b));
}

void greaterThanTestFloat() {
  SubFloat a {8.0};
  SubFloat b {9.0};
  ASSERT(b > a);
  ASSERT(!(b <= a));
}

void greaterThanEqualToTestFloat() {
  SubFloat a {8.0};
  SubFloat b {8.0};
  ASSERT(a >= b);
  ASSERT(!(a < b));
}

int main() {
  cute::suite s;

  s.push_back(CUTE(createDefaultTestEnum));
  s.push_back(CUTE(assignTestEnum));
  s.push_back(CUTE(equalsTestEnum));
  s.push_back(CUTE(notEqualsTestEnum));
  s.push_back(CUTE(lessThanTestEnum));
  s.push_back(CUTE(lessThanEqualToTestEnum));
  s.push_back(CUTE(greaterThanTestEnum));
  s.push_back(CUTE(greaterThanEqualToTestEnum));

  s.push_back(CUTE(createDefaultTestIntException));
  s.push_back(CUTE(preincrementTestIntException));
  s.push_back(CUTE(postincrementTestIntException));
  s.push_back(CUTE(predecrementTestIntException));
  s.push_back(CUTE(postdecrementTestIntException));
  s.push_back(CUTE(assignLiteralTestIntException));
  s.push_back(CUTE(assignTestIntException));
  s.push_back(CUTE(addAssignTestIntException));
  s.push_back(CUTE(subtractAssignTestIntException));
  s.push_back(CUTE(multiplyAssignTestIntException));
  s.push_back(CUTE(divideAssignTestIntException));
  s.push_back(CUTE(remainderAssignTestIntException));
  s.push_back(CUTE(xorAssignTestIntException));
  s.push_back(CUTE(andAssignTestIntException));
  s.push_back(CUTE(orAssignTestIntException));
  s.push_back(CUTE(shiftLeftAssignTestIntException));
  s.push_back(CUTE(shiftRightAssignTestIntException));
  s.push_back(CUTE(addTestIntException));
  s.push_back(CUTE(subtractTestIntException));
  s.push_back(CUTE(multiplyTestIntException));
  s.push_back(CUTE(divideTestIntException));
  s.push_back(CUTE(remainderTestIntException));
  s.push_back(CUTE(xorTestIntException));
  s.push_back(CUTE(andTestIntException));
  s.push_back(CUTE(orTestIntException));
  s.push_back(CUTE(shiftLeftTestIntException));
  s.push_back(CUTE(shiftRightTestIntException));
  s.push_back(CUTE(equalsTestIntException));
  s.push_back(CUTE(notEqualsTestIntException));
  s.push_back(CUTE(lessThanTestIntException));
  s.push_back(CUTE(lessThanEqualToTestIntException));
  s.push_back(CUTE(greaterThanTestIntException));
  s.push_back(CUTE(greaterThanEqualToTestIntException));

  s.push_back(CUTE(createDefaultTestIntModulo));
  s.push_back(CUTE(preincrementTestIntModulo));
  s.push_back(CUTE(postincrementTestIntModulo));
  s.push_back(CUTE(predecrementTestIntModulo));
  s.push_back(CUTE(postdecrementTestIntModulo));
  s.push_back(CUTE(assignLiteralTestIntModulo));
  s.push_back(CUTE(assignTestIntModulo));
  s.push_back(CUTE(addAssignTestIntModulo));
  s.push_back(CUTE(subtractAssignTestIntModulo));
  s.push_back(CUTE(multiplyAssignTestIntModulo));
  s.push_back(CUTE(divideAssignTestIntModulo));
  s.push_back(CUTE(remainderAssignTestIntModulo));
  s.push_back(CUTE(xorAssignTestIntModulo));
  s.push_back(CUTE(andAssignTestIntModulo));
  s.push_back(CUTE(orAssignTestIntModulo));
  s.push_back(CUTE(shiftLeftAssignTestIntModulo));
  s.push_back(CUTE(shiftRightAssignTestIntModulo));
  s.push_back(CUTE(addTestIntModulo));
  s.push_back(CUTE(subtractTestIntModulo));
  s.push_back(CUTE(multiplyTestIntModulo));
  s.push_back(CUTE(divideTestIntModulo));
  s.push_back(CUTE(remainderTestIntModulo));
  s.push_back(CUTE(xorTestIntModulo));
  s.push_back(CUTE(andTestIntModulo));
  s.push_back(CUTE(orTestIntModulo));
  s.push_back(CUTE(shiftLeftTestIntModulo));
  s.push_back(CUTE(shiftRightTestIntModulo));
  s.push_back(CUTE(equalsTestIntModulo));
  s.push_back(CUTE(notEqualsTestIntModulo));
  s.push_back(CUTE(lessThanTestIntModulo));
  s.push_back(CUTE(lessThanEqualToTestIntModulo));
  s.push_back(CUTE(greaterThanTestIntModulo));
  s.push_back(CUTE(greaterThanEqualToTestIntModulo));

  s.push_back(CUTE(createDefaultTestIntSaturated));
  s.push_back(CUTE(preincrementTestIntSaturated));
  s.push_back(CUTE(postincrementTestIntSaturated));
  s.push_back(CUTE(predecrementTestIntSaturated));
  s.push_back(CUTE(postdecrementTestIntSaturated));
  s.push_back(CUTE(assignLiteralTestIntSaturated));
  s.push_back(CUTE(assignTestIntSaturated));
  s.push_back(CUTE(addAssignTestIntSaturated));
  s.push_back(CUTE(subtractAssignTestIntSaturated));
  s.push_back(CUTE(multiplyAssignTestIntSaturated));
  s.push_back(CUTE(divideAssignTestIntSaturated));
  s.push_back(CUTE(remainderAssignTestIntSaturated));
  s.push_back(CUTE(xorAssignTestIntSaturated));
  s.push_back(CUTE(andAssignTestIntSaturated));
  s.push_back(CUTE(orAssignTestIntSaturated));
  s.push_back(CUTE(shiftLeftAssignTestIntSaturated));
  s.push_back(CUTE(shiftRightAssignTestIntSaturated));
  s.push_back(CUTE(addTestIntSaturated));
  s.push_back(CUTE(subtractTestIntSaturated));
  s.push_back(CUTE(multiplyTestIntSaturated));
  s.push_back(CUTE(divideTestIntSaturated));
  s.push_back(CUTE(remainderTestIntSaturated));
  s.push_back(CUTE(xorTestIntSaturated));
  s.push_back(CUTE(andTestIntSaturated));
  s.push_back(CUTE(orTestIntSaturated));
  s.push_back(CUTE(shiftLeftTestIntSaturated));
  s.push_back(CUTE(shiftRightTestIntSaturated));
  s.push_back(CUTE(equalsTestIntSaturated));
  s.push_back(CUTE(notEqualsTestIntSaturated));
  s.push_back(CUTE(lessThanTestIntSaturated));
  s.push_back(CUTE(lessThanEqualToTestIntSaturated));
  s.push_back(CUTE(greaterThanTestIntSaturated));
  s.push_back(CUTE(greaterThanEqualToTestIntSaturated));

  s.push_back(CUTE(createDefaultTestIntNaN));
  s.push_back(CUTE(preincrementTestIntNaN));
  s.push_back(CUTE(postincrementTestIntNaN));
  s.push_back(CUTE(predecrementTestIntNaN));
  s.push_back(CUTE(postdecrementTestIntNaN));
  s.push_back(CUTE(assignLiteralTestIntNaN));
  s.push_back(CUTE(assignTestIntNaN));
  s.push_back(CUTE(addAssignTestIntNaN));
  s.push_back(CUTE(subtractAssignTestIntNaN));
  s.push_back(CUTE(multiplyAssignTestIntNaN));
  s.push_back(CUTE(divideAssignTestIntNaN));
  s.push_back(CUTE(remainderAssignTestIntNaN));
  s.push_back(CUTE(xorAssignTestIntNaN));
  s.push_back(CUTE(andAssignTestIntNaN));
  s.push_back(CUTE(orAssignTestIntNaN));
  s.push_back(CUTE(shiftLeftAssignTestIntNaN));
  s.push_back(CUTE(shiftRightAssignTestIntNaN));
  s.push_back(CUTE(addTestIntNaN));
  s.push_back(CUTE(subtractTestIntNaN));
  s.push_back(CUTE(multiplyTestIntNaN));
  s.push_back(CUTE(divideTestIntNaN));
  s.push_back(CUTE(remainderTestIntNaN));
  s.push_back(CUTE(xorTestIntNaN));
  s.push_back(CUTE(andTestIntNaN));
  s.push_back(CUTE(orTestIntNaN));
  s.push_back(CUTE(shiftLeftTestIntNaN));
  s.push_back(CUTE(shiftRightTestIntNaN));
  s.push_back(CUTE(equalsTestIntNaN));
  s.push_back(CUTE(notEqualsTestIntNaN));
  s.push_back(CUTE(lessThanTestIntNaN));
  s.push_back(CUTE(lessThanEqualToTestIntNaN));
  s.push_back(CUTE(greaterThanTestIntNaN));
  s.push_back(CUTE(greaterThanEqualToTestIntNaN));

  s.push_back(CUTE(createDefaultTestFloat));
  s.push_back(CUTE(preincrementTestFloat));
  s.push_back(CUTE(postincrementTestFloat));
  s.push_back(CUTE(predecrementTestFloat));
  s.push_back(CUTE(postdecrementTestFloat));
  s.push_back(CUTE(assignLiteralTestFloat));
  s.push_back(CUTE(assignTestFloat));
  s.push_back(CUTE(addAssignTestFloat));
  s.push_back(CUTE(subtractAssignTestFloat));
  s.push_back(CUTE(multiplyAssignTestFloat));
  s.push_back(CUTE(divideAssignTestFloat));
  s.push_back(CUTE(addTestFloat));
  s.push_back(CUTE(subtractTestFloat));
  s.push_back(CUTE(multiplyTestFloat));
  s.push_back(CUTE(divideTestFloat));
  s.push_back(CUTE(equalsTestFloat));
  s.push_back(CUTE(notEqualsTestFloat));
  s.push_back(CUTE(lessThanTestFloat));
  s.push_back(CUTE(lessThanEqualToTestFloat));
  s.push_back(CUTE(greaterThanTestFloat));
  s.push_back(CUTE(greaterThanEqualToTestFloat));

  cute::ide_listener listener;
  cute::makeRunner(listener)(s, "Subrange CUTE Tests");

  return 0;

}
