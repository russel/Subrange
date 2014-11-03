//  Unit test for a subrange type template for C++
//
//  Copyright © 2012–2014  Russel Winder
//
//  Distributed under the Boost Software License, Version 1.0.  See
//  http://www.boost.org/LICENSE_1_0.txt.

/**
 *  @file
 *
 *  A test program (using Catch) for the <code>subrange</code> type.
 *
 *  <p>This is in serious need of extending with far more test cases.</p>
 *
 *  <p>Copyright © 2012–2014  Russel Winder.</p>
 *
 *  @author Russel Winder
 *  @version 1.3
 *  @date 2014-11-03T11:14
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "subrange.hpp"

enum Day {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

typedef subrange::subrange<subrange::ordinal_range<Day, monday, friday>> Weekday;

TEST_CASE("create default test enum") {
  Weekday a;
  REQUIRE(a == monday);
}

TEST_CASE("assign test enum") {
  Weekday a {monday};
  Weekday b {tuesday};
  a = b;
  REQUIRE(a == b);
}

TEST_CASE("equals test enum") {
  Weekday a {monday};
  Weekday b {monday};
  REQUIRE(a == b);
}

TEST_CASE("not equals test enum") {
  Weekday a {monday};
  Weekday b {tuesday};
  REQUIRE(a != b);
}

TEST_CASE("less than test enum") {
  Weekday a {monday};
  Weekday b {tuesday};
  REQUIRE(a < b);
  REQUIRE(!(a >= b));
}

TEST_CASE("less than equal to test enum") {
  Weekday a {monday};
  Weekday b {monday};
  REQUIRE(a <= b);
  REQUIRE(!(a > b));
}

TEST_CASE("greater than test enum") {
  Weekday a {monday};
  Weekday b {tuesday};
  REQUIRE(b > a);
  REQUIRE(!(b <= a));
}

TEST_CASE("greater than equal to test enum") {
  Weekday a {monday};
  Weekday b {monday};
  REQUIRE(a >= b);
  REQUIRE(!(a < b));
}

typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>> SubIntException;

TEST_CASE("create default test int exception") {
  SubIntException a;
  REQUIRE(a == 1);
}

TEST_CASE("preincrement test int exception") {
  SubIntException a {9};
  ++a;
  REQUIRE(a == 10);
}

TEST_CASE("postincrement test int exception") {
  SubIntException a {9};
  a++;
  REQUIRE(a == 10);
}

TEST_CASE("predecrement test int exception") {
  SubIntException a {9};
  --a;
  REQUIRE(a == 8);
}

TEST_CASE("postdecrement test int exception") {
  SubIntException a {9};
  a--;
  REQUIRE(a == 8);
}

TEST_CASE("assign literal test int exception") {
  SubIntException a {9};
  a = 20;
  REQUIRE(a == 20);
  //THROWS_EXCEPTION(a = 200, subrange::range_error);
  //THROWS_EXCEPTION(a = -5, subrange::range_error);
}

TEST_CASE("assign test int exception") {
  SubIntException a {9};
  SubIntException b {20};
  a = b;
  REQUIRE(a == b);
  REQUIRE(a == 20);
}

TEST_CASE("add assign test int exception") {
  SubIntException a {9};
  SubIntException b {20};
  a += b;
  REQUIRE(a == 29);
  a += 10;
  REQUIRE(a == 39);
  a += -10;
  REQUIRE(a == 29);
  //THROWS_EXCEPTION(a += 200, subrange::range_error);
}

TEST_CASE("subtract assign test int exception") {
  SubIntException a {20};
  SubIntException b {9};
  a -= b;
  REQUIRE(a == 11);
  a -= 5;
  REQUIRE(a == 6);
  a -= -5;
  REQUIRE(a == 11);
  //THROWS_EXCEPTION(b -= a, subrange::range_error);
}

TEST_CASE("multiply assign test int exception") {
  SubIntException a {20};
  SubIntException b {3};
  a *= b;
  REQUIRE(a == 60);
  //THROWS_EXCEPTION(a *= b, subrange::range_error);
}

TEST_CASE("divide assign test int exception") {
  SubIntException a {20};
  SubIntException b {3};
  a /= b;
  REQUIRE(a == 6);
}

TEST_CASE("remainder assign test int exception") {
  SubIntException a {20};
  SubIntException b {3};
  a %= b;
  REQUIRE(a == 2);
}

TEST_CASE("xor assign test int exception") {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a ^= b;
  REQUIRE(a == 0x11);
}

TEST_CASE("and assign test int exception") {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a &= b;
  REQUIRE(a == 0x02);
}

TEST_CASE("or assign test int exception") {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a |= b;
  REQUIRE(a == 0x13);
}

TEST_CASE("shift left assign test int exception") {
  SubIntException a {0x12};
  a <<= 1;
  REQUIRE(a == 0x24);
}

TEST_CASE("shift right assign test int exception") {
  SubIntException a {0x12};
  a >>= 1;
  REQUIRE(a == 0x09);
}

TEST_CASE("add test int exception") {
  SubIntException a {9};
  SubIntException b {20};
  a = a + b;
  REQUIRE(a == 29);
  a = a + 10;
  REQUIRE(a == 39);
  a = a + -10;
  REQUIRE(a == 29);
  a = 10 + a;
  REQUIRE(a == 39);
  a = -10 + a;
  REQUIRE(a == 29);
}

TEST_CASE("subtract test int exception") {
  SubIntException a {20};
  SubIntException b {9};
  a = a - b;
  REQUIRE(a == 11);
}

TEST_CASE("multiply test int exception") {
  SubIntException a {20};
  SubIntException b {3};
  a = a * b;
  REQUIRE(a == 60);
}

TEST_CASE("divide test int exception") {
  SubIntException a {20};
  SubIntException b {3};
  a = a / b;
  REQUIRE(a == 6);
}

TEST_CASE("remainder test int exception") {
  SubIntException a {20};
  SubIntException b {3};
  a = a % b;
  REQUIRE(a == 2);
}

TEST_CASE("xor test int exception") {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a = a ^ b;
  REQUIRE(a == 0x11);
}

TEST_CASE("and test int exception") {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a = a & b;
  REQUIRE(a == 0x02);
}

TEST_CASE("or test int exception") {
  SubIntException a {0x12};
  SubIntException b {0x03};
  a = a | b;
  REQUIRE(a == 0x13);
}

TEST_CASE("shift left test int exception") {
  SubIntException a {0x12};
  a = a << 1;
  REQUIRE(a == 0x24);
  //THROWS_EXCEPTION(a = a << 3, subrange::range_error);
}

TEST_CASE("shift right test int exception") {
  SubIntException a {0x12};
  a = a >> 1;
  REQUIRE(a == 0x09);
  //THROWS_EXCEPTION(a = a >> 5, subrange::range_error);
}

TEST_CASE("equals test int exception") {
  SubIntException a {9};
  SubIntException b {9};
  REQUIRE(a == b);
}

TEST_CASE("not equals test int exception") {
  SubIntException a {9};
  SubIntException b {8};
  REQUIRE(a != b);
}

TEST_CASE("less than test int exception") {
  SubIntException a {8};
  SubIntException b {9};
  REQUIRE(a < b);
  REQUIRE(!(a >= b));
}

TEST_CASE("less than equal to test int exception") {
  SubIntException a {8};
  SubIntException b {8};
  REQUIRE(a <= b);
  REQUIRE(!(a > b));
}

TEST_CASE("greater than test int exception") {
  SubIntException a {8};
  SubIntException b {9};
  REQUIRE(b > a);
  REQUIRE(!(b <= a));
}

TEST_CASE("greater than equal to test int exception") {
  SubIntException a {8};
  SubIntException b {8};
  REQUIRE(a >= b);
  REQUIRE(!(a < b));
}

typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>, subrange::modulo_arithmetic> SubIntModulo;

TEST_CASE("create default test int modulo") {
  SubIntModulo a;
  REQUIRE(a == 1);
}

TEST_CASE("preincrement test int modulo") {
  SubIntModulo a {9};
  ++a;
  REQUIRE(a == 10);
}

TEST_CASE("postincrement test int modulo") {
  SubIntModulo a {9};
  a++;
  REQUIRE(a == 10);
}

TEST_CASE("predecrement test int modulo") {
  SubIntModulo a {9};
  --a;
  REQUIRE(a == 8);
}

TEST_CASE("postdecrement test int modulo") {
  SubIntModulo a {9};
  a--;
  REQUIRE(a == 8);
}

TEST_CASE("assign literal test int modulo") {
  SubIntModulo a {9};
  a = 20;
  REQUIRE(a == 20);
  a = 200;
  REQUIRE(a == 4);
  a = -5;
  REQUIRE(a == 93);
}

TEST_CASE("assign test int modulo") {
  SubIntModulo a {9};
  SubIntModulo b {20};
  a = b;
  REQUIRE(a == b);
  REQUIRE(a == 20);
}

TEST_CASE("add assign test int modulo") {
  SubIntModulo a {9};
  SubIntModulo b {20};
  a += b;
  REQUIRE(a == 29);
  a += 10;
  REQUIRE(a == 39);
  a += -10;
  REQUIRE(a == 29);
  a += 200;
  REQUIRE(a == 33);
}

TEST_CASE("subtract assign test int modulo") {
  SubIntModulo a {20};
  SubIntModulo b {9};
  a -= b;
  REQUIRE(a == 11);
  a -= 5;
  REQUIRE(a == 6);
  a -= -5;
  REQUIRE(a == 11);
  b -= a;
  REQUIRE(b == 96);
}

TEST_CASE("multiply assign test int modulo") {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a *= b;
  REQUIRE(a == 60);
  a *= b;
  REQUIRE(a == 82);
}

TEST_CASE("divide assign test int modulo") {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a /= b;
  REQUIRE(a == 6);
}

TEST_CASE("remainder assign test int modulo") {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a %= b;
  REQUIRE(a == 2);
}

TEST_CASE("xor assign test int modulo") {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a ^= b;
  REQUIRE(a == 0x11);
}

TEST_CASE("and assign test int modulo") {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a &= b;
  REQUIRE(a == 0x02);
}

TEST_CASE("or assign test int modulo") {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a |= b;
  REQUIRE(a == 0x13);
}

TEST_CASE("shift left assign test int modulo") {
  SubIntModulo a {0x12};
  a <<= 1;
  REQUIRE(a == 0x24);
}

TEST_CASE("shift right assign test int modulo") {
  SubIntModulo a {0x12};
  a >>= 1;
  REQUIRE(a == 0x09);
}

TEST_CASE("add test int modulo") {
  SubIntModulo a {9};
  SubIntModulo b {20};
  a = a + b;
  REQUIRE(a == 29);
  a = a + 10;
  REQUIRE(a == 39);
  a = a + -10;
  REQUIRE(a == 29);
  a = 10 + a;
  REQUIRE(a == 39);
  a = -10 + a;
  REQUIRE(a == 29);
}

TEST_CASE("subtract test int modulo") {
  SubIntModulo a {20};
  SubIntModulo b {9};
  a = a - b;
  REQUIRE(a == 11);
}

TEST_CASE("multiply test int modulo") {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a = a * b;
  REQUIRE(a == 60);
}

TEST_CASE("divide test int modulo") {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a = a / b;
  REQUIRE(a == 6);
}

TEST_CASE("remainder test int modulo") {
  SubIntModulo a {20};
  SubIntModulo b {3};
  a = a % b;
  REQUIRE(a == 2);
}

TEST_CASE("xor test int modulo") {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a = a ^ b;
  REQUIRE(a == 0x11);
}

TEST_CASE("and test int modulo") {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a = a & b;
  REQUIRE(a == 0x02);
}

TEST_CASE("or test int modulo") {
  SubIntModulo a {0x12};
  SubIntModulo b {0x03};
  a = a | b;
  REQUIRE(a == 0x13);
}

TEST_CASE("shift left test int modulo") {
  SubIntModulo a {0x12};
  a = a << 1;
  REQUIRE(a == 0x24);
  a = a << 3;
  REQUIRE(a == 92);
}

TEST_CASE("shift right test int modulo") {
  SubIntModulo a {0x12};
  a = a >> 1;
  REQUIRE(a == 0x09);
  a = a >> 5;
  REQUIRE(a == 98);
}

TEST_CASE("equals test int modulo") {
  SubIntModulo a {9};
  SubIntModulo b {9};
  REQUIRE(a == b);
}

TEST_CASE("not equals test int modulo") {
  SubIntModulo a {9};
  SubIntModulo b {8};
  REQUIRE(a != b);
}

TEST_CASE("less than test int modulo") {
  SubIntModulo a {8};
  SubIntModulo b {9};
  REQUIRE(a < b);
  REQUIRE(!(a >= b));
}

TEST_CASE("less than equal to test int modulo") {
  SubIntModulo a {8};
  SubIntModulo b {8};
  REQUIRE(a <= b);
  REQUIRE(!(a > b));
}

TEST_CASE("greater than test int modulo") {
  SubIntModulo a {8};
  SubIntModulo b {9};
  REQUIRE(b > a);
  REQUIRE(!(b <= a));
}

TEST_CASE("greater than equal to test int modulo") {
  SubIntModulo a {8};
  SubIntModulo b {8};
  REQUIRE(a >= b);
  REQUIRE(!(a < b));
}

typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>, subrange::saturated_arithmetic> SubIntSaturated;

TEST_CASE("create default test int saturated") {
  SubIntSaturated a;
  REQUIRE(a == 1);
}

TEST_CASE("preincrement test int saturated") {
  SubIntSaturated a {9};
  ++a;
  REQUIRE(a == 10);
}

TEST_CASE("postincrement test int saturated") {
  SubIntSaturated a {9};
  a++;
  REQUIRE(a == 10);
}

TEST_CASE("predecrement test int saturated") {
  SubIntSaturated a {9};
  --a;
  REQUIRE(a == 8);
}

TEST_CASE("postdecrement test int saturated") {
  SubIntSaturated a {9};
  a--;
  REQUIRE(a == 8);
}

TEST_CASE("assign literal test int saturated") {
  SubIntSaturated a {9};
  a = 20;
  REQUIRE(a == 20);
  a = 200;
  REQUIRE(a == 99);
  a = -5;
  REQUIRE(a == 1);
}

TEST_CASE("assign test int saturated") {
  SubIntSaturated a {9};
  SubIntSaturated b {20};
  a = b;
  REQUIRE(a == b);
  REQUIRE(a == 20);
}

TEST_CASE("add assign test int saturated") {
  SubIntSaturated a {9};
  SubIntSaturated b {20};
  a += b;
  REQUIRE(a == 29);
  a += 10;
  REQUIRE(a == 39);
  a += -10;
  REQUIRE(a == 29);
  a += 200;
  REQUIRE(a == 99);
}

TEST_CASE("subtract assign test int saturated") {
  SubIntSaturated a {20};
  SubIntSaturated b {9};
  a -= b;
  REQUIRE(a == 11);
  a -= 5;
  REQUIRE(a == 6);
  a -= -5;
  REQUIRE(a == 11);
  b -= a;
  REQUIRE(b == 1);
}

TEST_CASE("multiply assign test int saturated") {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a *= b;
  REQUIRE(a == 60);
  a *= b;
  REQUIRE(a == 99);
}

TEST_CASE("divide assign test int saturated") {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a /= b;
  REQUIRE(a == 6);
}

TEST_CASE("remainder assign test int saturated") {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a %= b;
  REQUIRE(a == 2);
}

TEST_CASE("xor assign test int saturated") {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a ^= b;
  REQUIRE(a == 0x11);
}

TEST_CASE("and assign test int saturated") {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a &= b;
  REQUIRE(a == 0x02);
}

TEST_CASE("or assign test int saturated") {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a |= b;
  REQUIRE(a == 0x13);
}

TEST_CASE("shift left assign test int saturated") {
  SubIntSaturated a {0x12};
  a <<= 1;
  REQUIRE(a == 0x24);
}

TEST_CASE("shift right assign test int saturated") {
  SubIntSaturated a {0x12};
  a >>= 1;
  REQUIRE(a == 0x09);
}

TEST_CASE("add test int saturated") {
  SubIntSaturated a {9};
  SubIntSaturated b {20};
  a = a + b;
  REQUIRE(a == 29);
  a = a + 10;
  REQUIRE(a == 39);
  a = a + -10;
  REQUIRE(a == 29);
  a = 10 + a;
  REQUIRE(a == 39);
  a = -10 + a;
  REQUIRE(a == 29);
}

TEST_CASE("subtract test int saturated") {
  SubIntSaturated a {20};
  SubIntSaturated b {9};
  a = a - b;
  REQUIRE(a == 11);
}

TEST_CASE("multiply test int saturated") {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a = a * b;
  REQUIRE(a == 60);
}

TEST_CASE("divide test int saturated") {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a = a / b;
  REQUIRE(a == 6);
}

TEST_CASE("remainder test int saturated") {
  SubIntSaturated a {20};
  SubIntSaturated b {3};
  a = a % b;
  REQUIRE(a == 2);
}

TEST_CASE("xor test int saturated") {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a = a ^ b;
  REQUIRE(a == 0x11);
}

TEST_CASE("and test int saturated") {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a = a & b;
  REQUIRE(a == 0x02);
}

TEST_CASE("or test int saturated") {
  SubIntSaturated a {0x12};
  SubIntSaturated b {0x03};
  a = a | b;
  REQUIRE(a == 0x13);
}

TEST_CASE("shift left test int saturated") {
  SubIntSaturated a {0x12};
  a = a << 1;
  REQUIRE(a == 0x24);
  a = a << 3;
  REQUIRE(a == 99);
}

TEST_CASE("shift right test int saturated") {
  SubIntSaturated a {0x12};
  a = a >> 1;
  REQUIRE(a == 0x09);
  a = a >> 5;
  REQUIRE(a == 1);
}

TEST_CASE("equals test int saturated") {
  SubIntSaturated a {9};
  SubIntSaturated b {9};
  REQUIRE(a == b);
}

TEST_CASE("not equals test int saturated") {
  SubIntSaturated a {9};
  SubIntSaturated b {8};
  REQUIRE(a != b);
}

TEST_CASE("less than test int saturated") {
  SubIntSaturated a {8};
  SubIntSaturated b {9};
  REQUIRE(a < b);
  REQUIRE(!(a >= b));
}

TEST_CASE("less than equal to test int saturated") {
  SubIntSaturated a {8};
  SubIntSaturated b {8};
  REQUIRE(a <= b);
  REQUIRE(!(a > b));
}

TEST_CASE("greater than test int saturated") {
  SubIntSaturated a {8};
  SubIntSaturated b {9};
  REQUIRE(b > a);
  REQUIRE(!(b <= a));
}

TEST_CASE("greater than equal to test int saturated") {
  SubIntSaturated a {8};
  SubIntSaturated b {8};
  REQUIRE(a >= b);
  REQUIRE(!(a < b));
}

typedef subrange::ordinal_range<short, 1, 99> RangeTraits;
typedef subrange::subrange<RangeTraits, subrange::NaN_arithmetic> SubIntNaN;

inline bool isNaN(const SubIntNaN & s) { return subrange::NaN_arithmetic<RangeTraits>::isNaN(s); }

TEST_CASE("create default test int NaN") {
  SubIntNaN a;
  REQUIRE(a == 1);
}

TEST_CASE("preincrement test int NaN") {
  SubIntNaN a {9};
  ++a;
  REQUIRE(a == 10);
}

TEST_CASE("postincrement test int NaN") {
  SubIntNaN a {9};
  a++;
  REQUIRE(a == 10);
}

TEST_CASE("predecrement test int NaN") {
  SubIntNaN a {9};
  --a;
  REQUIRE(a == 8);
}

TEST_CASE("postdecrement test int NaN") {
  SubIntNaN a {9};
  a--;
  REQUIRE(a == 8);
}

TEST_CASE("assign literal test int NaN") {
  SubIntNaN a {9};
  a = 20;
  REQUIRE(a == 20);
  a = 200;
  REQUIRE(isNaN(a));
  a = -5;
  REQUIRE(isNaN(a));
}

TEST_CASE("assign test int NaN") {
  SubIntNaN a {9};
  SubIntNaN b {20};
  a = b;
  REQUIRE(a == b);
  REQUIRE(a == 20);
}

TEST_CASE("add assign test int NaN") {
  SubIntNaN a {9};
  SubIntNaN b {20};
  a += b;
  REQUIRE(a == 29);
  a += 10;
  REQUIRE(a == 39);
  a += -10;
  REQUIRE(a == 29);
  a += 200;
  REQUIRE(isNaN(a));
}

TEST_CASE("subtract assign test int NaN") {
  SubIntNaN a {20};
  SubIntNaN b {9};
  a -= b;
  REQUIRE(a == 11);
  a -= 5;
  REQUIRE(a == 6);
  a -= -5;
  REQUIRE(a == 11);
  b -= a;
  REQUIRE(isNaN(b));
}

TEST_CASE("multiply assign test int NaN") {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a *= b;
  REQUIRE(a == 60);
  a *= b;
  REQUIRE(isNaN(a));
}

TEST_CASE("divide assign test int NaN") {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a /= b;
  REQUIRE(a == 6);
}

TEST_CASE("remainder assign test int NaN") {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a %= b;
  REQUIRE(a == 2);
}

TEST_CASE("xor assign test int NaN") {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a ^= b;
  REQUIRE(a == 0x11);
}

TEST_CASE("and assign test int NaN") {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a &= b;
  REQUIRE(a == 0x02);
}

TEST_CASE("or assign test int NaN") {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a |= b;
  REQUIRE(a == 0x13);
}

TEST_CASE("shift left assign test int NaN") {
  SubIntNaN a {0x12};
  a <<= 1;
  REQUIRE(a == 0x24);
}

TEST_CASE("shift right assign test int NaN") {
  SubIntNaN a {0x12};
  a >>= 1;
  REQUIRE(a == 0x09);
}

TEST_CASE("add test int NaN") {
  SubIntNaN a {9};
  SubIntNaN b {20};
  a = a + b;
  REQUIRE(a == 29);
  a = a + 10;
  REQUIRE(a == 39);
  a = a + -10;
  REQUIRE(a == 29);
  a = 10 + a;
  REQUIRE(a == 39);
  a = -10 + a;
  REQUIRE(a == 29);
}

TEST_CASE("subtract test int NaN") {
  SubIntNaN a {20};
  SubIntNaN b {9};
  a = a - b;
  REQUIRE(a == 11);
}

TEST_CASE("multiply test int NaN") {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a = a * b;
  REQUIRE(a == 60);
}

TEST_CASE("divide test int NaN") {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a = a / b;
  REQUIRE(a == 6);
}

TEST_CASE("remainder test int NaN") {
  SubIntNaN a {20};
  SubIntNaN b {3};
  a = a % b;
  REQUIRE(a == 2);
}

TEST_CASE("xor test int NaN") {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a = a ^ b;
  REQUIRE(a == 0x11);
}

TEST_CASE("and test int NaN") {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a = a & b;
  REQUIRE(a == 0x02);
}

TEST_CASE("or test int NaN") {
  SubIntNaN a {0x12};
  SubIntNaN b {0x03};
  a = a | b;
  REQUIRE(a == 0x13);
}

TEST_CASE("shift left test int NaN") {
  SubIntNaN a {0x12};
  a = a << 1;
  REQUIRE(a == 0x24);
  a = a << 3;
  REQUIRE(isNaN(a));
}

TEST_CASE("shift right test int NaN") {
  SubIntNaN a {0x12};
  a = a >> 1;
  REQUIRE(a == 0x09);
  a = a >> 5;
  REQUIRE(isNaN(a));
}

TEST_CASE("equals test int NaN") {
  SubIntNaN a {9};
  SubIntNaN b {9};
  REQUIRE(a == b);
}

TEST_CASE("not equals test int NaN") {
  SubIntNaN a {9};
  SubIntNaN b {8};
  REQUIRE(a != b);
}

TEST_CASE("less than test int NaN") {
  SubIntNaN a {8};
  SubIntNaN b {9};
  REQUIRE(a < b);
  REQUIRE(!(a >= b));
}

TEST_CASE("less than equal to test int NaN") {
  SubIntNaN a {8};
  SubIntNaN b {8};
  REQUIRE(a <= b);
  REQUIRE(!(a > b));
}

TEST_CASE("greater than test int NaN") {
  SubIntNaN a {8};
  SubIntNaN b {9};
  REQUIRE(b > a);
  REQUIRE(!(b <= a));
}

TEST_CASE("greater than equal to test int NaN") {
  SubIntNaN a {8};
  SubIntNaN b {8};
  REQUIRE(a >= b);
  REQUIRE(!(a < b));
}

//  Can't use any templates for defining floating point range traits as C++ forbids template parameters
//  that are not of ordinal type so we have to do that manually.

class float_range {
 public :
  typedef double value_type;
  typedef subrange::range_error exception_type;
  static double min () { return 1.0; }
  static double max () { return 99.0; }
};

typedef subrange::subrange<float_range> SubFloat;

TEST_CASE("create default test float") {
  SubFloat a;
  REQUIRE(a == 1.0);
}

TEST_CASE("preincrement test float") {
  SubFloat a {9.0};
  ++a;
  REQUIRE(a == 10.0);
}

TEST_CASE("postincrement test float") {
  SubFloat a {9.0};
  a++;
  REQUIRE(a == 10.0);
}

TEST_CASE("predecrement test float") {
  SubFloat a {9.0};
  --a;
  REQUIRE(a == 8.0);
}

TEST_CASE("postdecrement test float") {
  SubFloat a {9.0};
  a--;
  REQUIRE(a == 8.0);
}

TEST_CASE("assign literal test float") {
  SubFloat a {9.0};
  a = 20.0;
  REQUIRE(a == 20.0);
  //THROWS_EXCEPTION(a = 200.0, subrange::range_error);
  //THROWS_EXCEPTION(a = -5.0, subrange::range_error);
}

TEST_CASE("assign test float") {
  SubFloat a {9.0};
  SubFloat b {20.0};
  a = b;
  REQUIRE(a == b);
  REQUIRE(a == 20.0);
}

TEST_CASE("add assign test float") {
  SubFloat a {9.0};
  SubFloat b {20.0};
  a += b;
  REQUIRE(a == 29.0);
  a += 10;
  REQUIRE(a == 39.0);
  a += -10;
  REQUIRE(a == 29.0);
  //THROWS_EXCEPTION(a += 200.0, subrange::range_error);
}

TEST_CASE("subtract assign test float") {
  SubFloat a {20.0};
  SubFloat b {9.0};
  a -= b;
  REQUIRE(a == 11.0);
  a -= 5.0;
  REQUIRE(a == 6.0);
  a -= -5.0;
  REQUIRE(a == 11.0);
  //THROWS_EXCEPTION(b -= a, subrange::range_error);
}

TEST_CASE("multiply assign test float") {
  SubFloat a {20.0};
  SubFloat b {3.0};
  a *= b;
  REQUIRE(a == 60.0);
  //THROWS_EXCEPTION(a *= b, subrange::range_error);
}

TEST_CASE("divide assign test float") {
  SubFloat a {20.0};
  SubFloat b {4.0};
  a /= b;
  REQUIRE(a == 5.0);
}

TEST_CASE("add test float") {
  SubFloat a {9.0};
  SubFloat b {20.0};
  a = a + b;
  REQUIRE(a == 29.0);
  a = a + 10.0;
  REQUIRE(a == 39.0);
  a = a + -10.0;
  REQUIRE(a == 29.0);
  a = 10.0 + a;
  REQUIRE(a == 39.0);
  a = -10.0 + a;
  REQUIRE(a == 29.0);
}

TEST_CASE("subtract test float") {
  SubFloat a {20.0};
  SubFloat b {9.0};
  a = a - b;
  REQUIRE(a == 11.0);
}

TEST_CASE("multiply test float") {
  SubFloat a {20.0};
  SubFloat b {3.0};
  a = a * b;
  REQUIRE(a == 60.0);
}

TEST_CASE("divide test float") {
  SubFloat a {20.0};
  SubFloat b {4.0};
  a = a / b;
  REQUIRE(a == 5.0);
}

TEST_CASE("equals test float") {
  SubFloat a {9.0};
  SubFloat b {9.0};
  REQUIRE(a == b);
}

TEST_CASE("not equals test float") {
  SubFloat a {9.0};
  SubFloat b {8.0};
  REQUIRE(a != b);
}

TEST_CASE("less than test float") {
  SubFloat a {8.0};
  SubFloat b {9.0};
  REQUIRE(a < b);
  REQUIRE(!(a >= b));
}

TEST_CASE("less than equal to test float") {
  SubFloat a {8.0};
  SubFloat b {8.0};
  REQUIRE(a <= b);
  REQUIRE(!(a > b));
}

TEST_CASE("greater than test float") {
  SubFloat a {8.0};
  SubFloat b {9.0};
  REQUIRE(b > a);
  REQUIRE(!(b <= a));
}

TEST_CASE("greater than equal to test float") {
  SubFloat a {8.0};
  SubFloat b {8.0};
  REQUIRE(a >= b);
  REQUIRE(!(a < b));
}
