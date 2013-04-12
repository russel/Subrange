//  Unit test for a subrange type template for C++
//
//  Copyright (c) 2005, 2010, 2013 Russel Winder
//
//  Distributed under the Boost Software License, Version 1.0.  See
//  http://www.boost.org/LICENSE_1_0.txt.

/**
 *  @file
 *
 *  A test program (using Boost.Test) for the <code>subrange</code> type.
 *
 *  <p>This is in serious need of extending with far more test cases.</p>
 *
 *  <p>Copyright (c) 2005, 2010, 2013  Russel Winder.</p>
 *
 *  @author Russel Winder
 *  @version 1.3
 *  @date 2013-04-12T11:16+01:00
 */

#define BOOST_TEST_MODULE SubrangeTest_Boost
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include "subrange.hpp"

enum Day { monday, tuesday, wednesday, thursday, friday, saturday, sunday };

typedef subrange::subrange<subrange::ordinal_range<Day, monday, friday> > Weekday;

BOOST_AUTO_TEST_CASE(createDefaultTestEnum) {
  Weekday a;
  BOOST_REQUIRE_EQUAL(a, monday);
}

BOOST_AUTO_TEST_CASE(assignTestEnum) {
  Weekday a {monday};
  Weekday b {tuesday};
  a = b;
  BOOST_REQUIRE(a == b);
}

BOOST_AUTO_TEST_CASE(equalsTestEnum) {
  Weekday a {monday};
  Weekday b {monday};
  BOOST_REQUIRE(a == b);
}

BOOST_AUTO_TEST_CASE(notEqualsTestEnum) {
  Weekday a {monday};
  Weekday b {tuesday};
  BOOST_REQUIRE(a != b);
}

BOOST_AUTO_TEST_CASE(lessThanTestEnum) {
  Weekday a {monday};
  Weekday b {tuesday};
  BOOST_REQUIRE(a < b);
  BOOST_REQUIRE(!(a >= b));
}

BOOST_AUTO_TEST_CASE(lessThanEqualToTestEnum) {
  Weekday a {monday};
  Weekday b {monday};
  BOOST_REQUIRE(a <= b);
  BOOST_REQUIRE(!(a > b));
}

BOOST_AUTO_TEST_CASE(greaterThanTestEnum) {
  Weekday a {monday};
  Weekday b {tuesday};
  BOOST_REQUIRE(b > a);
  BOOST_REQUIRE(!(b <= a));
}

BOOST_AUTO_TEST_CASE(greaterThanEqualToTestEnum) {
  Weekday a {monday};
  Weekday b {monday};
  BOOST_REQUIRE(a >= b);
  BOOST_REQUIRE(!(a < b));
}


typedef subrange::subrange<subrange::ordinal_range<short, 1, 99> > SubIntException;

BOOST_AUTO_TEST_CASE(createDefaultTestIntException) {
  SubIntException a;
  BOOST_REQUIRE_EQUAL(a, 1);
}

BOOST_AUTO_TEST_CASE(preincrementTestIntException) {
  SubIntException a {9};
  ++a;
  BOOST_REQUIRE_EQUAL(a, 10);
}

BOOST_AUTO_TEST_CASE(postincrementTestIntException) {
  SubIntException a {9};
  a++;
  BOOST_REQUIRE_EQUAL(a, 10);
}

BOOST_AUTO_TEST_CASE(predecrementTestIntException) {
  SubIntException a {9};
  --a;
  BOOST_REQUIRE_EQUAL(a, 8);
}

BOOST_AUTO_TEST_CASE(postdecrementTestIntException) {
  SubIntException a {9};
  a--;
  BOOST_REQUIRE_EQUAL(a, 8);
}

BOOST_AUTO_TEST_CASE(assignLiteralTestIntException) {
  SubIntException a {9};
  a = 20;
  BOOST_REQUIRE_EQUAL(a, 20);
  BOOST_REQUIRE_THROW(a = 200, subrange::range_error);
  BOOST_REQUIRE_THROW(a = -5, subrange::range_error);
}

BOOST_AUTO_TEST_CASE(assignTestIntException) {
  SubIntException a {9};
  SubIntException b {20};
  a = b;
  BOOST_REQUIRE_EQUAL(a, b);
  BOOST_REQUIRE_EQUAL(a, 20);
}

BOOST_AUTO_TEST_CASE(addAssignTestIntException) {
  SubIntException a {9};
  SubIntException b {20};
  a += b;
  BOOST_REQUIRE_EQUAL(a, 29);
  a += 10;
  BOOST_REQUIRE_EQUAL(a, 39);
  a += -10;
  BOOST_REQUIRE_EQUAL(a, 29);
  BOOST_REQUIRE_THROW(a += 200, subrange::range_error);
}

BOOST_AUTO_TEST_CASE(subtractAssignTestIntException) {
  SubIntException a {20};
  SubIntException b {9};
  a -= b;
  BOOST_REQUIRE_EQUAL(a, 11);
  a -= 5;
  BOOST_REQUIRE_EQUAL(a, 6);
  a -= -5;
  BOOST_REQUIRE_EQUAL(a, 11);
  BOOST_REQUIRE_THROW (b -= a, subrange::range_error);
}

BOOST_AUTO_TEST_CASE(multiplyAssignTestIntException) {
  SubIntException a {20};
  SubIntException b {3};
  a *= b;
  BOOST_REQUIRE_EQUAL(a, 60);
  BOOST_REQUIRE_THROW (a *= b, subrange::range_error);
}

BOOST_AUTO_TEST_CASE(divideAssignTestIntException) {
  SubIntException a {20};
  SubIntException b {3};
  a /= b;
  BOOST_REQUIRE_EQUAL(a, 6);
}

BOOST_AUTO_TEST_CASE(remainderAssignTestIntException) {
  SubIntException a {20};
  SubIntException b {3};
  a %= b;
  BOOST_REQUIRE_EQUAL(a, 2);
}

BOOST_AUTO_TEST_CASE(xorAssignTestIntException) {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a ^= b;
  BOOST_REQUIRE_EQUAL(a, 0x11);
}

BOOST_AUTO_TEST_CASE(andAssignTestIntException) {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a &= b;
  BOOST_REQUIRE_EQUAL(a, 0x02);
}

BOOST_AUTO_TEST_CASE(orAssignTestIntException) {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a |= b;
  BOOST_REQUIRE_EQUAL(a, 0x13);
}

BOOST_AUTO_TEST_CASE(shiftLeftAssignTestIntException) {
  SubIntException a {0x12};
  a <<= 1;
  BOOST_REQUIRE_EQUAL(a, 0x24);
}

BOOST_AUTO_TEST_CASE(shiftRightAssignTestIntException) {
  SubIntException a {0x12};
  a >>= 1;
  BOOST_REQUIRE_EQUAL(a, 0x09);
}

BOOST_AUTO_TEST_CASE(addTestIntException) {
  SubIntException a {9};
  SubIntException b {20};
  a = a + b;
  BOOST_REQUIRE_EQUAL(a, 29);
  a = a + 10;
  BOOST_REQUIRE_EQUAL(a, 39);
  a = a + -10;
  BOOST_REQUIRE_EQUAL(a, 29);
  a = 10 + a;
  BOOST_REQUIRE_EQUAL(a, 39);
  a = -10 + a;
  BOOST_REQUIRE_EQUAL(a, 29);
}

BOOST_AUTO_TEST_CASE(subtractTestIntException) {
  SubIntException a {20};
  SubIntException b {9};
  a = a - b;
  BOOST_REQUIRE_EQUAL(a, 11);
}

BOOST_AUTO_TEST_CASE(multiplyTestIntException) {
  SubIntException a {20};
  SubIntException b {3};
  a = a * b;
  BOOST_REQUIRE_EQUAL(a, 60);
}

BOOST_AUTO_TEST_CASE(divideTestIntException) {
  SubIntException a {20};
  SubIntException b {3};
  a = a / b;
  BOOST_REQUIRE_EQUAL(a, 6);
}

BOOST_AUTO_TEST_CASE(remainderTestIntException) {
  SubIntException a {20};
  SubIntException b {3};
  a = a % b;
  BOOST_REQUIRE_EQUAL(a, 2);
}

BOOST_AUTO_TEST_CASE(xorTestIntException) {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a = a ^ b;
  BOOST_REQUIRE_EQUAL(a, 0x11);
}

BOOST_AUTO_TEST_CASE(andTestIntException) {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a = a & b;
  BOOST_REQUIRE_EQUAL(a, 0x02);
}

BOOST_AUTO_TEST_CASE(orTestIntException) {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a = a | b;
  BOOST_REQUIRE_EQUAL(a, 0x13);
}

BOOST_AUTO_TEST_CASE(shiftLeftTestIntException) {
  SubIntException a {0x12};
  a = a << 1;
  BOOST_REQUIRE_EQUAL(a, 0x24);
  BOOST_REQUIRE_THROW(a = a << 3, subrange::range_error);
}

BOOST_AUTO_TEST_CASE(shiftRightTestIntException) {
  SubIntException a {0x12};
  a = a >> 1;
  BOOST_REQUIRE_EQUAL(a, 0x09);
  BOOST_REQUIRE_THROW(a = a >> 5, subrange::range_error);
}

BOOST_AUTO_TEST_CASE(equalsTestIntException) {
  SubIntException a {9};
  SubIntException b {9};
  BOOST_REQUIRE_EQUAL(a, b);
}

BOOST_AUTO_TEST_CASE(notEqualsTestIntException) {
  SubIntException a {9};
  SubIntException b {8};
  BOOST_REQUIRE(a != b);
}

BOOST_AUTO_TEST_CASE(lessThanTestIntException) {
  SubIntException a {8};
  SubIntException b {9};
  BOOST_REQUIRE(a < b);
  BOOST_REQUIRE(!(a >= b));
}

BOOST_AUTO_TEST_CASE(lessThanEqualToTestIntException) {
  SubIntException a {8};
  SubIntException b {8};
  BOOST_REQUIRE(a <= b);
  BOOST_REQUIRE(!(a > b));
}

BOOST_AUTO_TEST_CASE(greaterThanTestIntException) {
  SubIntException a {8};
  SubIntException b {9};
  BOOST_REQUIRE(b > a);
  BOOST_REQUIRE(!(b <= a));
}

BOOST_AUTO_TEST_CASE(greaterThanEqualToTestIntException) {
  SubIntException a {8};
  SubIntException b {8};
  BOOST_REQUIRE(a >= b);
  BOOST_REQUIRE(!(a < b));
}


typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>, subrange::modulo_arithmetic> SubIntModulo;

BOOST_AUTO_TEST_CASE(createDefaultTestIntModulo) {
  SubIntModulo a;
  BOOST_REQUIRE_EQUAL(a, 1);
}

BOOST_AUTO_TEST_CASE(preincrementTestIntModulo) {
  SubIntModulo a {9};
  ++a;
  BOOST_REQUIRE_EQUAL(a, 10);
}

BOOST_AUTO_TEST_CASE(postincrementTestIntModulo) {
  SubIntModulo a {9};
  a++;
  BOOST_REQUIRE_EQUAL(a, 10);
}

BOOST_AUTO_TEST_CASE(predecrementTestIntModulo) {
  SubIntModulo a {9};
  --a;
  BOOST_REQUIRE_EQUAL(a, 8);
}

BOOST_AUTO_TEST_CASE(postdecrementTestIntModulo) {
  SubIntModulo a {9};
  a--;
  BOOST_REQUIRE_EQUAL(a, 8);
}

BOOST_AUTO_TEST_CASE(assignLiteralTestIntModulo) {
  SubIntModulo a {9};
  a = 20;
  BOOST_REQUIRE_EQUAL(a, 20);
  a = 200;
  BOOST_REQUIRE_EQUAL(a, 4);
  a = -5;
  BOOST_REQUIRE_EQUAL(a, 93);
}

BOOST_AUTO_TEST_CASE(assignTestIntModulo) {
  SubIntModulo a {9};
  SubIntModulo b {20};
  a = b;
  BOOST_REQUIRE_EQUAL(a, b);
  BOOST_REQUIRE_EQUAL(a, 20);
}

BOOST_AUTO_TEST_CASE(addAssignTestIntModulo) {
  SubIntModulo a {9};
  SubIntModulo b {20};
  a += b;
  BOOST_REQUIRE_EQUAL(a, 29);
  a += 10;
  BOOST_REQUIRE_EQUAL(a, 39);
  a += -10;
  BOOST_REQUIRE_EQUAL(a, 29);
  a += 200;
  BOOST_REQUIRE_EQUAL(a, 33);
}

BOOST_AUTO_TEST_CASE(subtractAssignTestIntModulo) {
  SubIntModulo a {20};
  SubIntModulo b {9};
  a -= b;
  BOOST_REQUIRE_EQUAL(a, 11);
  a -= 5;
  BOOST_REQUIRE_EQUAL(a, 6);
  a -= -5;
  BOOST_REQUIRE_EQUAL(a, 11);
  b -= a;
  BOOST_REQUIRE(b == 96);
}

BOOST_AUTO_TEST_CASE(multiplyAssignTestIntModulo) {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a *= b;
  BOOST_REQUIRE_EQUAL(a, 60);
  a *= b;
  BOOST_REQUIRE_EQUAL(a, 82);
}

BOOST_AUTO_TEST_CASE(divideAssignTestIntModulo) {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a /= b;
  BOOST_REQUIRE_EQUAL(a, 6);
}

BOOST_AUTO_TEST_CASE(remainderAssignTestIntModulo) {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a %= b;
  BOOST_REQUIRE_EQUAL(a, 2);
}

BOOST_AUTO_TEST_CASE(xorAssignTestIntModulo) {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a ^= b;
  BOOST_REQUIRE_EQUAL(a, 0x11);
}

BOOST_AUTO_TEST_CASE(andAssignTestIntModulo) {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a &= b;
  BOOST_REQUIRE_EQUAL(a, 0x02);
}

BOOST_AUTO_TEST_CASE(orAssignTestIntModulo) {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a |= b;
  BOOST_REQUIRE_EQUAL(a, 0x13);
}

BOOST_AUTO_TEST_CASE(shiftLeftAssignTestIntModulo) {
  SubIntModulo a {0x12};
  a <<= 1;
  BOOST_REQUIRE_EQUAL(a, 0x24);
}

BOOST_AUTO_TEST_CASE(shiftRightAssignTestIntModulo) {
  SubIntModulo a {0x12};
  a >>= 1;
  BOOST_REQUIRE_EQUAL(a, 0x09);
}

BOOST_AUTO_TEST_CASE(addTestIntModulo) {
  SubIntModulo a {9};
  SubIntModulo b {20};
  a = a + b;
  BOOST_REQUIRE_EQUAL(a, 29);
  a = a + 10;
  BOOST_REQUIRE_EQUAL(a, 39);
  a = a + -10;
  BOOST_REQUIRE_EQUAL(a, 29);
  a = 10 + a;
  BOOST_REQUIRE_EQUAL(a, 39);
  a = -10 + a;
  BOOST_REQUIRE_EQUAL(a, 29);
}

BOOST_AUTO_TEST_CASE(subtractTestIntModulo) {
  SubIntModulo a {20};
  SubIntModulo b {9};
  a = a - b;
  BOOST_REQUIRE_EQUAL(a, 11);
}

BOOST_AUTO_TEST_CASE(multiplyTestIntModulo) {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a = a * b;
  BOOST_REQUIRE_EQUAL(a, 60);
}

BOOST_AUTO_TEST_CASE(divideTestIntModulo) {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a = a / b;
  BOOST_REQUIRE_EQUAL(a, 6);
}

BOOST_AUTO_TEST_CASE(remainderTestIntModulo) {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a = a % b;
  BOOST_REQUIRE_EQUAL(a, 2);
}

BOOST_AUTO_TEST_CASE(xorTestIntModulo) {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a = a ^ b;
  BOOST_REQUIRE_EQUAL(a, 0x11);
}

BOOST_AUTO_TEST_CASE(andTestIntModulo) {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a = a & b;
  BOOST_REQUIRE_EQUAL(a, 0x02);
}

BOOST_AUTO_TEST_CASE(orTestIntModulo) {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a = a | b;
  BOOST_REQUIRE_EQUAL(a, 0x13);
}

BOOST_AUTO_TEST_CASE(shiftLeftTestIntModulo) {
  SubIntModulo a {0x12};
  a = a << 1;
  BOOST_REQUIRE_EQUAL(a, 0x24);
  a = a << 3;
  BOOST_REQUIRE_EQUAL(a, 92);
}

BOOST_AUTO_TEST_CASE(shiftRightTestIntModulo) {
  SubIntModulo a {0x12};
  a = a >> 1;
  BOOST_REQUIRE_EQUAL(a, 0x09);
  a = a >> 5;
  BOOST_REQUIRE_EQUAL(a, 98);
}

BOOST_AUTO_TEST_CASE(equalsTestIntModulo) {
  SubIntModulo a {9};
  SubIntModulo b {9};
  BOOST_REQUIRE_EQUAL(a, b);
}

BOOST_AUTO_TEST_CASE(notEqualsTestIntModulo) {
  SubIntModulo a {9};
  SubIntModulo b {8};
  BOOST_REQUIRE(a != b);
}

BOOST_AUTO_TEST_CASE(lessThanTestIntModulo) {
  SubIntModulo a {8};
  SubIntModulo b {9};
  BOOST_REQUIRE(a < b);
  BOOST_REQUIRE(!(a >= b));
}

BOOST_AUTO_TEST_CASE(lessThanEqualToTestIntModulo) {
  SubIntModulo a {8};
  SubIntModulo b {8};
  BOOST_REQUIRE(a <= b);
  BOOST_REQUIRE(!(a > b));
}

BOOST_AUTO_TEST_CASE(greaterThanTestIntModulo) {
  SubIntModulo a {8};
  SubIntModulo b {9};
  BOOST_REQUIRE(b > a);
  BOOST_REQUIRE(!(b <= a));
}

BOOST_AUTO_TEST_CASE(greaterThanEqualToTestIntModulo) {
  SubIntModulo a {8};
  SubIntModulo b {8};
  BOOST_REQUIRE(a >= b);
  BOOST_REQUIRE(!(a < b));
}

typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>, subrange::saturated_arithmetic> SubIntSaturated;

BOOST_AUTO_TEST_CASE(createDefaultTestIntSaturated) {
  SubIntSaturated a;
  BOOST_REQUIRE_EQUAL(a, 1);
}

BOOST_AUTO_TEST_CASE(preincrementTestIntSaturated) {
  SubIntSaturated a {9};
  ++a;
  BOOST_REQUIRE_EQUAL(a, 10);
}

BOOST_AUTO_TEST_CASE(postincrementTestIntSaturated) {
  SubIntSaturated a {9};
  a++;
  BOOST_REQUIRE_EQUAL(a, 10);
}

BOOST_AUTO_TEST_CASE(predecrementTestIntSaturated) {
  SubIntSaturated a {9};
  --a;
  BOOST_REQUIRE_EQUAL(a, 8);
}

BOOST_AUTO_TEST_CASE(postdecrementTestIntSaturated) {
  SubIntSaturated a {9};
  a--;
  BOOST_REQUIRE_EQUAL(a, 8);
}

BOOST_AUTO_TEST_CASE(assignLiteralTestIntSaturated) {
  SubIntSaturated a {9};
  a = 20;
  BOOST_REQUIRE_EQUAL(a, 20);
  a = 200;
  BOOST_REQUIRE_EQUAL(a, 99);
  a = -5;
  BOOST_REQUIRE_EQUAL(a, 1);
}

BOOST_AUTO_TEST_CASE(assignTestIntSaturated) {
  SubIntSaturated a {9};
  SubIntSaturated b {20};
  a = b;
  BOOST_REQUIRE_EQUAL(a, b);
  BOOST_REQUIRE_EQUAL(a, 20);
}

BOOST_AUTO_TEST_CASE(addAssignTestIntSaturated) {
  SubIntSaturated a {9};
  SubIntSaturated b {20};
  a += b;
  BOOST_REQUIRE_EQUAL(a, 29);
  a += 10;
  BOOST_REQUIRE_EQUAL(a, 39);
  a += -10;
  BOOST_REQUIRE_EQUAL(a, 29);
  a += 200;
  BOOST_REQUIRE_EQUAL(a, 99);
}

BOOST_AUTO_TEST_CASE(subtractAssignTestIntSaturated) {
  SubIntSaturated a {20};
  SubIntSaturated b {9};
  a -= b;
  BOOST_REQUIRE_EQUAL(a, 11);
  a -= 5;
  BOOST_REQUIRE_EQUAL(a, 6);
  a -= -5;
  BOOST_REQUIRE_EQUAL(a, 11);
  b -= a;
  BOOST_REQUIRE(b == 1);
}

BOOST_AUTO_TEST_CASE(multiplyAssignTestIntSaturated) {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a *= b;
  BOOST_REQUIRE_EQUAL(a, 60);
  a *= b;
  BOOST_REQUIRE_EQUAL(a, 99);
}

BOOST_AUTO_TEST_CASE(divideAssignTestIntSaturated) {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a /= b;
  BOOST_REQUIRE_EQUAL(a, 6);
}

BOOST_AUTO_TEST_CASE(remainderAssignTestIntSaturated) {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a %= b;
  BOOST_REQUIRE_EQUAL(a, 2);
}

BOOST_AUTO_TEST_CASE(xorAssignTestIntSaturated) {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a ^= b;
  BOOST_REQUIRE_EQUAL(a, 0x11);
}

BOOST_AUTO_TEST_CASE(andAssignTestIntSaturated) {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a &= b;
  BOOST_REQUIRE_EQUAL(a, 0x02);
}

BOOST_AUTO_TEST_CASE(orAssignTestIntSaturated) {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a |= b;
  BOOST_REQUIRE_EQUAL(a, 0x13);
}

BOOST_AUTO_TEST_CASE(shiftLeftAssignTestIntSaturated) {
  SubIntSaturated a {0x12};
  a <<= 1;
  BOOST_REQUIRE_EQUAL(a, 0x24);
}

BOOST_AUTO_TEST_CASE(shiftRightAssignTestIntSaturated) {
  SubIntSaturated a {0x12};
  a >>= 1;
  BOOST_REQUIRE_EQUAL(a, 0x09);
}

BOOST_AUTO_TEST_CASE(addTestIntSaturated) {
  SubIntSaturated a {9};
  SubIntSaturated b {20};
  a = a + b;
  BOOST_REQUIRE_EQUAL(a, 29);
  a = a + 10;
  BOOST_REQUIRE_EQUAL(a, 39);
  a = a + -10;
  BOOST_REQUIRE_EQUAL(a, 29);
  a = 10 + a;
  BOOST_REQUIRE_EQUAL(a, 39);
  a = -10 + a;
  BOOST_REQUIRE_EQUAL(a, 29);
}

BOOST_AUTO_TEST_CASE(subtractTestIntSaturated) {
  SubIntSaturated a {20};
  SubIntSaturated b {9};
  a = a - b;
  BOOST_REQUIRE_EQUAL(a, 11);
}

BOOST_AUTO_TEST_CASE(multiplyTestIntSaturated) {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a = a * b;
  BOOST_REQUIRE_EQUAL(a, 60);
}

BOOST_AUTO_TEST_CASE(divideTestIntSaturated) {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a = a / b;
  BOOST_REQUIRE_EQUAL(a, 6);
}

BOOST_AUTO_TEST_CASE(remainderTestIntSaturated) {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a = a % b;
  BOOST_REQUIRE_EQUAL(a, 2);
}

BOOST_AUTO_TEST_CASE(xorTestIntSaturated) {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a = a ^ b;
  BOOST_REQUIRE_EQUAL(a, 0x11);
}

BOOST_AUTO_TEST_CASE(andTestIntSaturated) {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a = a & b;
  BOOST_REQUIRE_EQUAL(a, 0x02);
}

BOOST_AUTO_TEST_CASE(orTestIntSaturated) {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a = a | b;
  BOOST_REQUIRE_EQUAL(a, 0x13);
}

BOOST_AUTO_TEST_CASE(shiftLeftTestIntSaturated) {
  SubIntSaturated a {0x12};
  a = a << 1;
  BOOST_REQUIRE_EQUAL(a, 0x24);
  a = a << 3;
  BOOST_REQUIRE_EQUAL(a, 99);
}

BOOST_AUTO_TEST_CASE(shiftRightTestIntSaturated) {
  SubIntSaturated a {0x12};
  a = a >> 1;
  BOOST_REQUIRE_EQUAL(a, 0x09);
  a = a >> 5;
  BOOST_REQUIRE_EQUAL(a, 1);
}

BOOST_AUTO_TEST_CASE(equalsTestIntSaturated) {
  SubIntSaturated a {9};
  SubIntSaturated b {9};
  BOOST_REQUIRE_EQUAL(a, b);
}

BOOST_AUTO_TEST_CASE(notEqualsTestIntSaturated) {
  SubIntSaturated a {9};
  SubIntSaturated b {8};
  BOOST_REQUIRE(a != b);
}

BOOST_AUTO_TEST_CASE(lessThanTestIntSaturated) {
  SubIntSaturated a {8};
  SubIntSaturated b {9};
  BOOST_REQUIRE(a < b);
  BOOST_REQUIRE(!(a >= b));
}

BOOST_AUTO_TEST_CASE(lessThanEqualToTestIntSaturated) {
  SubIntSaturated a {8};
  SubIntSaturated b {8};
  BOOST_REQUIRE(a <= b);
  BOOST_REQUIRE(!(a > b));
}

BOOST_AUTO_TEST_CASE(greaterThanTestIntSaturated) {
  SubIntSaturated a {8};
  SubIntSaturated b {9};
  BOOST_REQUIRE(b > a);
  BOOST_REQUIRE(!(b <= a));
}

BOOST_AUTO_TEST_CASE(greaterThanEqualToTestIntSaturated) {
  SubIntSaturated a {8};
  SubIntSaturated b {8};
  BOOST_REQUIRE(a >= b);
  BOOST_REQUIRE(!(a < b));
}


typedef subrange::ordinal_range<short, 1, 99> RangeTraits;
typedef subrange::subrange<RangeTraits, subrange::NaN_arithmetic> SubIntNaN;

inline bool isNaN(const SubIntNaN & s) { return subrange::NaN_arithmetic<RangeTraits>::isNaN(s); }

BOOST_AUTO_TEST_CASE(createDefaultTestIntNaN) {
  SubIntNaN a;
  BOOST_REQUIRE_EQUAL(a, 1);
}

BOOST_AUTO_TEST_CASE(preincrementTestIntNaN) {
  SubIntNaN a {9};
  ++a;
  BOOST_REQUIRE_EQUAL(a, 10);
}

BOOST_AUTO_TEST_CASE(postincrementTestIntNaN) {
  SubIntNaN a {9};
  a++;
  BOOST_REQUIRE_EQUAL(a, 10);
}

BOOST_AUTO_TEST_CASE(predecrementTestIntNaN) {
  SubIntNaN a {9};
  --a;
  BOOST_REQUIRE_EQUAL(a, 8);
}

BOOST_AUTO_TEST_CASE(postdecrementTestIntNaN) {
  SubIntNaN a {9};
  a--;
  BOOST_REQUIRE_EQUAL(a, 8);
}

BOOST_AUTO_TEST_CASE(assignLiteralTestIntNaN) {
  SubIntNaN a {9};
  a = 20;
  BOOST_REQUIRE_EQUAL(a, 20);
  a = 200;
  BOOST_REQUIRE(isNaN(a));
  a = -5;
  BOOST_REQUIRE(isNaN(a));
}

BOOST_AUTO_TEST_CASE(assignTestIntNaN) {
  SubIntNaN a {9};
  SubIntNaN b {20};
  a = b;
  BOOST_REQUIRE_EQUAL(a, b);
  BOOST_REQUIRE_EQUAL(a, 20);
}

BOOST_AUTO_TEST_CASE(addAssignTestIntNaN) {
  SubIntNaN a {9};
  SubIntNaN b {20};
  a += b;
  BOOST_REQUIRE_EQUAL(a, 29);
  a += 10;
  BOOST_REQUIRE_EQUAL(a, 39);
  a += -10;
  BOOST_REQUIRE_EQUAL(a, 29);
  a += 200;
  BOOST_REQUIRE(isNaN(a));
}

BOOST_AUTO_TEST_CASE(subtractAssignTestIntNaN) {
  SubIntNaN a {20};
  SubIntNaN b {9};
  a -= b;
  BOOST_REQUIRE_EQUAL(a, 11);
  a -= 5;
  BOOST_REQUIRE_EQUAL(a, 6);
  a -= -5;
  BOOST_REQUIRE_EQUAL(a, 11);
  b -= a;
  BOOST_REQUIRE(isNaN(b));
}

BOOST_AUTO_TEST_CASE(multiplyAssignTestIntNaN) {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a *= b;
  BOOST_REQUIRE_EQUAL(a, 60);
  a *= b;
  BOOST_REQUIRE(isNaN(a));
}

BOOST_AUTO_TEST_CASE(divideAssignTestIntNaN) {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a /= b;
  BOOST_REQUIRE_EQUAL(a, 6);
}

BOOST_AUTO_TEST_CASE(remainderAssignTestIntNaN) {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a %= b;
  BOOST_REQUIRE_EQUAL(a, 2);
}

BOOST_AUTO_TEST_CASE(xorAssignTestIntNaN) {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a ^= b;
  BOOST_REQUIRE_EQUAL(a, 0x11);
}

BOOST_AUTO_TEST_CASE(andAssignTestIntNaN) {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a &= b;
  BOOST_REQUIRE_EQUAL(a, 0x02);
}

BOOST_AUTO_TEST_CASE(orAssignTestIntNaN) {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a |= b;
  BOOST_REQUIRE_EQUAL(a, 0x13);
}

BOOST_AUTO_TEST_CASE(shiftLeftAssignTestIntNaN) {
  SubIntNaN a {0x12};
  a <<= 1;
  BOOST_REQUIRE_EQUAL(a, 0x24);
}

BOOST_AUTO_TEST_CASE(shiftRightAssignTestIntNaN) {
  SubIntNaN a {0x12};
  a >>= 1;
  BOOST_REQUIRE_EQUAL(a, 0x09);
}

BOOST_AUTO_TEST_CASE(addTestIntNaN) {
  SubIntNaN a {9};
  SubIntNaN b {20};
  a = a + b;
  BOOST_REQUIRE_EQUAL(a, 29);
  a = a + 10;
  BOOST_REQUIRE_EQUAL(a, 39);
  a = a + -10;
  BOOST_REQUIRE_EQUAL(a, 29);
  a = 10 + a;
  BOOST_REQUIRE_EQUAL(a, 39);
  a = -10 + a;
  BOOST_REQUIRE_EQUAL(a, 29);
}

BOOST_AUTO_TEST_CASE(subtractTestIntNaN) {
  SubIntNaN a {20};
  SubIntNaN b {9};
  a = a - b;
  BOOST_REQUIRE_EQUAL(a, 11);
}

BOOST_AUTO_TEST_CASE(multiplyTestIntNaN) {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a = a * b;
  BOOST_REQUIRE_EQUAL(a, 60);
}

BOOST_AUTO_TEST_CASE(divideTestIntNaN) {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a = a / b;
  BOOST_REQUIRE_EQUAL(a, 6);
}

BOOST_AUTO_TEST_CASE(remainderTestIntNaN) {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a = a % b;
  BOOST_REQUIRE_EQUAL(a, 2);
}

BOOST_AUTO_TEST_CASE(xorTestIntNaN) {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a = a ^ b;
  BOOST_REQUIRE_EQUAL(a, 0x11);
}

BOOST_AUTO_TEST_CASE(andTestIntNaN) {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a = a & b;
  BOOST_REQUIRE_EQUAL(a, 0x02);
}

BOOST_AUTO_TEST_CASE(orTestIntNaN) {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a = a | b;
  BOOST_REQUIRE_EQUAL(a, 0x13);
}

BOOST_AUTO_TEST_CASE(shiftLeftTestIntNaN) {
  SubIntNaN a {0x12};
  a = a << 1;
  BOOST_REQUIRE_EQUAL(a, 0x24);
  a = a << 3;
  BOOST_REQUIRE(isNaN(a));
}

BOOST_AUTO_TEST_CASE(shiftRightTestIntNaN) {
  SubIntNaN a {0x12};
  a = a >> 1;
  BOOST_REQUIRE_EQUAL(a, 0x09);
  a = a >> 5;
  BOOST_REQUIRE(isNaN(a));
}

BOOST_AUTO_TEST_CASE(equalsTestIntNaN) {
  SubIntNaN a {9};
  SubIntNaN b {9};
  BOOST_REQUIRE_EQUAL(a, b);
}

BOOST_AUTO_TEST_CASE(notEqualsTestIntNaN) {
  SubIntNaN a {9};
  SubIntNaN b {8};
  BOOST_REQUIRE(a != b);
}

BOOST_AUTO_TEST_CASE(lessThanTestIntNaN) {
  SubIntNaN a {8};
  SubIntNaN b {9};
  BOOST_REQUIRE(a < b);
  BOOST_REQUIRE(!(a >= b));
}

BOOST_AUTO_TEST_CASE(lessThanEqualToTestIntNaN) {
  SubIntNaN a {8};
  SubIntNaN b {8};
  BOOST_REQUIRE(a <= b);
  BOOST_REQUIRE(!(a > b));
}

BOOST_AUTO_TEST_CASE(greaterThanTestIntNaN) {
  SubIntNaN a {8};
  SubIntNaN b {9};
  BOOST_REQUIRE(b > a);
  BOOST_REQUIRE(!(b <= a));
}

BOOST_AUTO_TEST_CASE(greaterThanEqualToTestIntNaN) {
  SubIntNaN a {8};
  SubIntNaN b {8};
  BOOST_REQUIRE(a >= b);
  BOOST_REQUIRE(!(a < b));
}

//  Can't use any templates for defining floating point range traits as C++ forbids template parameters
//  that are not of ordinal type so we haver to do that manually.

class float_range {
 public :
  typedef double value_type;
  typedef subrange::range_error exception_type;
  static double min() { return 1.0; }
  static double max() { return 99.0; }
};

typedef subrange::subrange<float_range> SubFloat;

BOOST_AUTO_TEST_CASE(createDefaultTestFloat) {
  SubFloat a;
  BOOST_REQUIRE_EQUAL(a, 1.0);
}

BOOST_AUTO_TEST_CASE(preincrementTestFloat) {
  SubFloat a {9.0};
  ++a;
  BOOST_REQUIRE_EQUAL(a, 10.0);
}

BOOST_AUTO_TEST_CASE(postincrementTestFloat) {
  SubFloat a {9.0};
  a++;
  BOOST_REQUIRE_EQUAL(a, 10.0);
}

BOOST_AUTO_TEST_CASE(predecrementTestFloat) {
  SubFloat a {9.0};
  --a;
  BOOST_REQUIRE_EQUAL(a, 8.0);
}

BOOST_AUTO_TEST_CASE(postdecrementTestFloat) {
  SubFloat a {9.0};
  a--;
  BOOST_REQUIRE_EQUAL(a, 8.0);
}

BOOST_AUTO_TEST_CASE(assignLiteralTestFloat) {
  SubFloat a {9.0};
  a = 20.0;
  BOOST_REQUIRE_EQUAL(a, 20.0);
  BOOST_REQUIRE_THROW(a = 200.0, subrange::range_error);
  BOOST_REQUIRE_THROW(a = -5.0, subrange::range_error);
}

BOOST_AUTO_TEST_CASE(assignTestFloat) {
  SubFloat a {9.0};
  SubFloat b {20.0};
  a = b;
  BOOST_REQUIRE_EQUAL(a, b);
  BOOST_REQUIRE_EQUAL(a, 20.0);
}

BOOST_AUTO_TEST_CASE(addAssignTestFloat) {
  SubFloat a {9.0};
  SubFloat b {20.0};
  a += b;
  BOOST_REQUIRE_EQUAL(a, 29.0);
  a += 10;
  BOOST_REQUIRE_EQUAL(a, 39.0);
  a += -10;
  BOOST_REQUIRE_EQUAL(a, 29.0);
  BOOST_REQUIRE_THROW(a += 200.0, subrange::range_error);
}

BOOST_AUTO_TEST_CASE(subtractAssignTestFloat) {
  SubFloat a {20.0};
  SubFloat b {9.0};
  a -= b;
  BOOST_REQUIRE_EQUAL(a, 11.0);
  a -= 5.0;
  BOOST_REQUIRE_EQUAL(a, 6.0);
  a -= -5.0;
  BOOST_REQUIRE_EQUAL(a, 11.0);
  BOOST_REQUIRE_THROW(b -= a, subrange::range_error);
}

BOOST_AUTO_TEST_CASE(multiplyAssignTestFloat) {
  SubFloat a {20.0};
  SubFloat b {3.0};
  a *= b;
  BOOST_REQUIRE_EQUAL(a, 60.0);
  BOOST_REQUIRE_THROW(a *= b, subrange::range_error);
}

BOOST_AUTO_TEST_CASE(divideAssignTestFloat) {
  SubFloat a {20.0};
  SubFloat b {4.0};
  a /= b;
  BOOST_REQUIRE_EQUAL(a, 5.0);
}

BOOST_AUTO_TEST_CASE(addTestFloat) {
  SubFloat a {9.0};
  SubFloat b {20.0};
  a = a + b;
  BOOST_REQUIRE_EQUAL(a, 29.0);
  a = a + 10.0;
  BOOST_REQUIRE_EQUAL(a, 39.0);
  a = a + -10.0;
  BOOST_REQUIRE_EQUAL(a, 29.0);
  a = 10.0 + a;
  BOOST_REQUIRE_EQUAL(a, 39.0);
  a = -10.0 + a;
  BOOST_REQUIRE_EQUAL(a, 29.0);
}

BOOST_AUTO_TEST_CASE(subtractTestFloat) {
  SubFloat a {20.0};
  SubFloat b {9.0};
  a = a - b;
  BOOST_REQUIRE_EQUAL(a, 11.0);
}

BOOST_AUTO_TEST_CASE(multiplyTestFloat) {
  SubFloat a {20.0};
  SubFloat b {3.0};
  a = a * b;
  BOOST_REQUIRE_EQUAL(a, 60.0);
}

BOOST_AUTO_TEST_CASE(divideTestFloat) {
  SubFloat a {20.0};
  SubFloat b {4.0};
  a = a / b;
  BOOST_REQUIRE_EQUAL(a, 5.0);
}

BOOST_AUTO_TEST_CASE(equalsTestFloat) {
  SubFloat a {9.0};
  SubFloat b {9.0};
  BOOST_REQUIRE_EQUAL(a, b);
}

BOOST_AUTO_TEST_CASE(notEqualsTestFloat) {
  SubFloat a {9.0};
  SubFloat b {8.0};
  BOOST_REQUIRE(a != b);
}

BOOST_AUTO_TEST_CASE(lessThanTestFloat) {
  SubFloat a {8.0};
  SubFloat b {9.0};
  BOOST_REQUIRE(a < b);
  BOOST_REQUIRE(!(a >= b));
}

BOOST_AUTO_TEST_CASE(lessThanEqualToTestFloat) {
  SubFloat a {8.0};
  SubFloat b {8.0};
  BOOST_REQUIRE(a <= b);
  BOOST_REQUIRE(!(a > b));
}

BOOST_AUTO_TEST_CASE(greaterThanTestFloat) {
  SubFloat a {8.0};
  SubFloat b {9.0};
  BOOST_REQUIRE(b > a);
  BOOST_REQUIRE(!(b <= a));
}

BOOST_AUTO_TEST_CASE(greaterThanEqualToTestFloat) {
  SubFloat a {8.0};
  SubFloat b {8.0};
  BOOST_REQUIRE(a >= b);
  BOOST_REQUIRE(!(a < b));
}
