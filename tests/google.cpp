//  Unit test for a subrange type template for C++
//
//  Copyright (c) 2010 Russel Winder
//
//  Distributed under the Boost Software License, Version 1.0.  See
//  http://www.boost.org/LICENSE_1_0.txt.

/**
 *  @file
 *
 *  A test program (using GoogleTest) for the <code>subrange</code> type.
 *
 *  <p>This is in serious need of extending with far more test cases.</p>
 *
 *  <p>Copyright (c) 2010  Russel Winder.</p>
 *
 *  @author Russel Winder
 *  @version 1.1
 *  @date 2010-06-19 17:10+01:00
 */

//  Seem to have to define these to avoid lots of warning messages.

#define GTEST_OS_WINDOWS 0
#define GTEST_OS_WINDOWS_MOBILE 0
#define GTEST_OS_SYMBIAN 0
#define GTEST_OS_CYGWIN 0
#define GTEST_OS_SOLARIS 0
#define GTEST_OS_AIX 0

#define GTEST_DONT_DEFINE_FAIL 0
#define GTEST_DONT_DEFINE_SUCCEED 0
#define GTEST_DONT_DEFINE_TEST 0

#include "gtest/gtest.h"

#include "subrange.hpp"

enum Day { monday , tuesday , wednesday , thursday , friday , saturday , sunday } ;

typedef subrange::subrange<subrange::ordinal_range<Day, monday, friday> > Weekday ;

TEST( GoogleTest , createDefaultTestEnum ) {
  Weekday a ;
  ASSERT_EQ ( monday , a ) ;
}

TEST( GoogleTest , assignTestEnum ) {
  Weekday a ( monday ) ;
  Weekday b ( tuesday ) ;
  a = b ;
  ASSERT_TRUE ( a == b ) ;
}

TEST( GoogleTest , equalsTestEnum ) {
  Weekday a ( monday ) ;
  Weekday b ( monday ) ;
  ASSERT_TRUE ( a == b ) ;
}

TEST( GoogleTest , notEqualsTestEnum ) {
  Weekday a ( monday ) ;
  Weekday b ( tuesday ) ;
  ASSERT_TRUE ( a != b ) ;
}

TEST( GoogleTest , lessThanTestEnum ) {
  Weekday a ( monday ) ;
  Weekday b ( tuesday ) ;
  EXPECT_TRUE ( a < b ) ;
  ASSERT_FALSE ( a >= b ) ;
}

TEST( GoogleTest , lessThanEqualToTestEnum ) {
  Weekday a ( monday ) ;
  Weekday b ( monday ) ;
  EXPECT_TRUE ( a <= b ) ;
  ASSERT_FALSE ( a > b ) ;
}

TEST( GoogleTest , greaterThanTestEnum ) {
  Weekday a ( monday ) ;
  Weekday b ( tuesday ) ;
  EXPECT_TRUE ( b > a ) ;
  ASSERT_FALSE ( b <= a ) ;
}

TEST( GoogleTest , greaterThanEqualToTestEnum ) {
  Weekday a ( monday ) ;
  Weekday b ( monday ) ;
  EXPECT_TRUE ( a >= b ) ;
  ASSERT_FALSE ( a < b ) ;
}


typedef subrange::subrange<subrange::ordinal_range<short, 1, 99> > SubIntException ;

TEST( GoogleTest , createDefaultTestIntException ) {
  SubIntException a ;
  ASSERT_EQ ( 1 , a ) ;
}

TEST( GoogleTest , preincrementTestIntException ) {
  SubIntException a ( 9 ) ;
  ++a ;
  ASSERT_EQ ( 10 , a ) ;
}

TEST( GoogleTest , postincrementTestIntException ) {
  SubIntException a ( 9 ) ;
  a++ ;
  ASSERT_EQ ( 10 , a ) ;
}

TEST( GoogleTest , predecrementTestIntException ) {
  SubIntException a ( 9 ) ;
  --a ;
  ASSERT_EQ ( 8 , a ) ;
}

TEST( GoogleTest , postdecrementTestIntException ) {
  SubIntException a ( 9 ) ;
  a-- ;
  ASSERT_EQ ( 8 , a ) ;
}

TEST( GoogleTest , assignLiteralTestIntException ) {
  SubIntException a ( 9 ) ;
  a = 20 ;
  ASSERT_EQ ( 20 , a ) ;
  EXPECT_THROW ( a = 200 , subrange::range_error ) ;
  ASSERT_THROW ( a = -5 , subrange::range_error ) ;
}

TEST( GoogleTest , assignTestIntException ) {
  SubIntException a ( 9 ) ;
  SubIntException b ( 20 ) ;
  a = b ;
  EXPECT_TRUE ( a == b ) ;
  ASSERT_EQ ( 20 , a ) ;
}

TEST( GoogleTest , addAssignTestIntException ) {
  SubIntException a ( 9 ) ;
  SubIntException b ( 20 ) ;
  a += b ;
  ASSERT_EQ ( 29 , a ) ;
  a += 10 ;
  ASSERT_EQ ( 39 , a ) ;
  a += -10 ;
  ASSERT_EQ ( 29 , a ) ;
  ASSERT_THROW ( a += 200 , subrange::range_error ) ;
}

TEST( GoogleTest , subtractAssignTestIntException ) {
  SubIntException a ( 20 ) ;
  SubIntException b ( 9 ) ;
  a -= b ;
  ASSERT_EQ ( 11 , a ) ;
  a -= 5 ;
  ASSERT_EQ ( 6 , a ) ;
  a -= -5 ;
  ASSERT_EQ ( 11 , a ) ;
  ASSERT_THROW ( b -= a , subrange::range_error ) ;
}

TEST( GoogleTest , multiplyAssignTestIntException ) {
  SubIntException a ( 20 ) ;
  SubIntException b ( 3 ) ;
  a *= b ;
  ASSERT_EQ ( 60 , a ) ;
  ASSERT_THROW ( a *= b , subrange::range_error ) ;
}

TEST( GoogleTest , divideAssignTestIntException ) {
  SubIntException a ( 20 ) ;
  SubIntException b ( 3 ) ;
  a /= b ;
  ASSERT_EQ ( 6 , a ) ;
}

TEST( GoogleTest , remainderAssignTestIntException ) {
  SubIntException a ( 20 ) ;
  SubIntException b ( 3 ) ;
  a %= b ;
  ASSERT_EQ ( 2 , a ) ;
}

TEST( GoogleTest , xorAssignTestIntException ) {
  SubIntException a ( 0x12 ) ;
  SubIntException b ( 0x03 ) ;
  a ^= b ;
  ASSERT_EQ ( 0x11 , a ) ;
}

TEST( GoogleTest , andAssignTestIntException ) {
  SubIntException a ( 0x12 ) ;
  SubIntException b ( 0x03 ) ;
  a &= b ;
  ASSERT_EQ ( 0x02 , a ) ;
}

TEST( GoogleTest , orAssignTestIntException ) {
  SubIntException a ( 0x12 ) ;
  SubIntException b ( 0x03 ) ;
  a |= b ;
  ASSERT_EQ ( 0x13 , a ) ;
}

TEST( GoogleTest , shiftLeftAssignTestIntException ) {
  SubIntException a ( 0x12 ) ;
  a <<= 1 ;
  ASSERT_EQ ( 0x24 , a ) ;
}

TEST( GoogleTest , shiftRightAssignTestIntException ) {
  SubIntException a ( 0x12 ) ;
  a >>= 1 ;
  ASSERT_EQ ( 0x09 , a ) ;
}

TEST( GoogleTest , addTestIntException ) {
  SubIntException a ( 9 ) ;
  SubIntException b ( 20 ) ;
  a = a + b ;
  ASSERT_EQ ( 29 , a ) ;
  a = a + 10 ;
  ASSERT_EQ ( 39 , a ) ;
  a = a + -10 ;
  ASSERT_EQ ( 29 , a ) ;
  a = 10 + a ;
  ASSERT_EQ ( 39 , a ) ;
  a = -10 + a ;
  ASSERT_EQ ( 29 , a ) ;
}

TEST( GoogleTest , subtractTestIntException ) {
  SubIntException a ( 20 ) ;
  SubIntException b ( 9 ) ;
  a = a - b ;
  ASSERT_EQ ( 11 , a ) ;
}

TEST( GoogleTest , multiplyTestIntException ) {
  SubIntException a ( 20 ) ;
  SubIntException b ( 3 ) ;
  a = a * b ;
  ASSERT_EQ ( 60 , a ) ;
}

TEST( GoogleTest , divideTestIntException ) {
  SubIntException a ( 20 ) ;
  SubIntException b ( 3 ) ;
  a = a / b ;
  ASSERT_EQ ( 6 , a ) ;
}

TEST( GoogleTest , remainderTestIntException ) {
  SubIntException a ( 20 ) ;
  SubIntException b ( 3 ) ;
  a = a % b ;
  ASSERT_EQ ( 2 , a ) ;
}

TEST( GoogleTest , xorTestIntException ) {
  SubIntException a ( 0x12 ) ;
  SubIntException b ( 0x03 ) ;
  a = a ^ b ;
  ASSERT_EQ ( 0x11 , a ) ;
}

TEST( GoogleTest , andTestIntException ) {
  SubIntException a ( 0x12 ) ;
  SubIntException b ( 0x03 ) ;
  a = a & b ;
  ASSERT_EQ ( 0x02 , a ) ;
}

TEST( GoogleTest , orTestIntException ) {
  SubIntException a ( 0x12 ) ;
  SubIntException b ( 0x03 ) ;
  a = a | b ;
  ASSERT_EQ ( 0x13 , a ) ;
}

TEST( GoogleTest , shiftLeftTestIntException ) {
  SubIntException a ( 0x12 ) ;
  a = a << 1 ;
  ASSERT_EQ ( 0x24 , a ) ;
  ASSERT_THROW( a = a << 3 , subrange::range_error ) ;
}

TEST( GoogleTest , shiftRightTestIntException ) {
  SubIntException a ( 0x12 ) ;
  a = a >> 1 ;
  ASSERT_EQ ( 0x09 , a ) ;
  ASSERT_THROW ( a = a >> 5 , subrange::range_error ) ;
}

TEST( GoogleTest , equalsTestIntException ) {
  SubIntException a ( 9 ) ;
  SubIntException b ( 9 ) ;
  ASSERT_EQ ( b , a ) ;
}

TEST( GoogleTest , notEqualsTestIntException ) {
  SubIntException a ( 9 ) ;
  SubIntException b ( 8 ) ;
  ASSERT_TRUE ( a != b ) ;
}

TEST( GoogleTest , lessThanTestIntException ) {
  SubIntException a ( 8 ) ;
  SubIntException b ( 9 ) ;
  ASSERT_TRUE ( a < b ) ;
  ASSERT_FALSE ( a >= b ) ;
}

TEST( GoogleTest , lessThanEqualToTestIntException ) {
  SubIntException a ( 8 ) ;
  SubIntException b ( 8 ) ;
  ASSERT_TRUE ( a <= b ) ;
  ASSERT_FALSE ( a > b ) ;
}

TEST( GoogleTest , greaterThanTestIntException ) {
  SubIntException a ( 8 ) ;
  SubIntException b ( 9 ) ;
  ASSERT_TRUE ( b > a ) ;
  ASSERT_TRUE ( ! ( b <= a ) ) ;
}

TEST( GoogleTest , greaterThanEqualToTestIntException ) {
  SubIntException a ( 8 ) ;
  SubIntException b ( 8 ) ;
  ASSERT_TRUE ( a >= b ) ;
  ASSERT_FALSE ( a < b ) ;
}


typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>, subrange::modulo_arithmetic> SubIntModulo ;

TEST( GoogleTest , createDefaultTestIntModulo ) {
  SubIntModulo a ;
  ASSERT_EQ ( 1 , a ) ;
}

TEST( GoogleTest , preincrementTestIntModulo ) {
  SubIntModulo a ( 9 ) ;
  ++a ;
  ASSERT_EQ ( 10 , a ) ;
}

TEST( GoogleTest , postincrementTestIntModulo ) {
  SubIntModulo a ( 9 ) ;
  a++ ;
  ASSERT_EQ ( 10 , a ) ;
}

TEST( GoogleTest , predecrementTestIntModulo ) {
  SubIntModulo a ( 9 ) ;
  --a ;
  ASSERT_EQ ( 8 , a ) ;
}

TEST( GoogleTest , postdecrementTestIntModulo ) {
  SubIntModulo a ( 9 ) ;
  a-- ;
  ASSERT_EQ ( 8 , a ) ;
}

TEST( GoogleTest , assignLiteralTestIntModulo ) {
  SubIntModulo a ( 9 ) ;
  a = 20 ;
  ASSERT_EQ ( 20 , a ) ;
  a = 200 ;
  ASSERT_EQ ( 4 , a ) ;
  a = -5 ;
  ASSERT_EQ ( 93 , a ) ;
}

TEST( GoogleTest , assignTestIntModulo ) {
  SubIntModulo a ( 9 ) ;
  SubIntModulo b ( 20 ) ;
  a = b ;
  ASSERT_EQ ( b , a ) ;
  ASSERT_EQ ( 20 , a ) ;
}

TEST( GoogleTest , addAssignTestIntModulo ) {
  SubIntModulo a ( 9 ) ;
  SubIntModulo b ( 20 ) ;
  a += b ;
  ASSERT_EQ ( 29 , a ) ;
  a += 10 ;
  ASSERT_EQ ( 39 , a ) ;
  a += -10 ;
  ASSERT_EQ ( 29 , a ) ;
  a += 200 ;
  ASSERT_EQ ( 33 , a ) ;
}

TEST( GoogleTest , subtractAssignTestIntModulo ) {
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 9 ) ;
  a -= b ;
  ASSERT_EQ ( 11 , a ) ;
  a -= 5 ;
  ASSERT_EQ ( 6 , a ) ;
  a -= -5 ;
  ASSERT_EQ ( 11 , a ) ;
  b -= a ;
  ASSERT_EQ ( 96 , b ) ;
}

TEST( GoogleTest , multiplyAssignTestIntModulo ) {
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 3 ) ;
  a *= b ;
  ASSERT_EQ ( 60 , a ) ;
  a *= b ;
  ASSERT_EQ ( 82 , a ) ;
}

TEST( GoogleTest , divideAssignTestIntModulo ) {
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 3 ) ;
  a /= b ;
  ASSERT_EQ ( 6 , a ) ;
}

TEST( GoogleTest , remainderAssignTestIntModulo ) {
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 3 ) ;
  a %= b ;
  ASSERT_EQ ( 2 , a ) ;
}

TEST( GoogleTest , xorAssignTestIntModulo ) {
  SubIntModulo a ( 0x12 ) ;
  SubIntModulo b ( 0x03 ) ;
  a ^= b ;
  ASSERT_EQ ( 0x11 , a ) ;
}

TEST( GoogleTest , andAssignTestIntModulo ) {
  SubIntModulo a ( 0x12 ) ;
  SubIntModulo b ( 0x03 ) ;
  a &= b ;
  ASSERT_EQ ( 0x02 , a ) ;
}

TEST( GoogleTest , orAssignTestIntModulo ) {
  SubIntModulo a ( 0x12 ) ;
  SubIntModulo b ( 0x03 ) ;
  a |= b ;
  ASSERT_EQ ( 0x13 , a ) ;
}

TEST( GoogleTest , shiftLeftAssignTestIntModulo ) {
  SubIntModulo a ( 0x12 ) ;
  a <<= 1 ;
  ASSERT_EQ ( 0x24 , a ) ;
}

TEST( GoogleTest , shiftRightAssignTestIntModulo ) {
  SubIntModulo a ( 0x12 ) ;
  a >>= 1 ;
  ASSERT_EQ ( 0x09 , a ) ;
}

TEST( GoogleTest , addTestIntModulo ) {
  SubIntModulo a ( 9 ) ;
  SubIntModulo b ( 20 ) ;
  a = a + b ;
  ASSERT_EQ ( 29 , a ) ;
  a = a + 10 ;
  ASSERT_EQ ( 39 , a ) ;
  a = a + -10 ;
  ASSERT_EQ ( 29 , a ) ;
  a = 10 + a ;
  ASSERT_EQ ( 39 , a ) ;
  a = -10 + a ;
  ASSERT_EQ ( 29 , a ) ;
}

TEST( GoogleTest , subtractTestIntModulo ) {
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 9 ) ;
  a = a - b ;
  ASSERT_EQ ( 11 , a ) ;
}

TEST( GoogleTest , multiplyTestIntModulo ) {
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 3 ) ;
  a = a * b ;
  ASSERT_EQ ( 60 , a ) ;
}

TEST( GoogleTest , divideTestIntModulo ) {
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 3 ) ;
  a = a / b ;
  ASSERT_EQ ( 6 , a ) ;
}

TEST( GoogleTest , remainderTestIntModulo ) {
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 3 ) ;
  a = a % b ;
  ASSERT_EQ ( 2 , a ) ;
}

TEST( GoogleTest , xorTestIntModulo ) {
  SubIntModulo a ( 0x12 ) ;
  SubIntModulo b ( 0x03 ) ;
  a = a ^ b ;
  ASSERT_EQ ( 0x11 , a ) ;
}

TEST( GoogleTest , andTestIntModulo ) {
  SubIntModulo a ( 0x12 ) ;
  SubIntModulo b ( 0x03 ) ;
  a = a & b ;
  ASSERT_EQ ( 0x02 , a ) ;
}

TEST( GoogleTest , orTestIntModulo ) {
  SubIntModulo a ( 0x12 ) ;
  SubIntModulo b ( 0x03 ) ;
  a = a | b ;
  ASSERT_EQ ( 0x13 , a ) ;
}

TEST( GoogleTest , shiftLeftTestIntModulo ) {
  SubIntModulo a ( 0x12 ) ;
  a = a << 1 ;
  ASSERT_EQ ( 0x24 , a ) ;
  a = a << 3 ;
  ASSERT_EQ ( 92 , a ) ;
}

TEST( GoogleTest , shiftRightTestIntModulo ) {
  SubIntModulo a ( 0x12 ) ;
  a = a >> 1 ;
  ASSERT_EQ ( 0x09 , a ) ;
  a = a >> 5 ;
  ASSERT_EQ ( 98 , a ) ;
}

TEST( GoogleTest , equalsTestIntModulo ) {
  SubIntModulo a ( 9 ) ;
  SubIntModulo b ( 9 ) ;
  ASSERT_EQ ( b , a ) ;
}

TEST( GoogleTest , notEqualsTestIntModulo ) {
  SubIntModulo a ( 9 ) ;
  SubIntModulo b ( 8 ) ;
  ASSERT_TRUE ( a != b ) ;
}

TEST( GoogleTest , lessThanTestIntModulo ) {
  SubIntModulo a ( 8 ) ;
  SubIntModulo b ( 9 ) ;
  ASSERT_TRUE ( a < b ) ;
  ASSERT_FALSE ( a >= b ) ;
}

TEST( GoogleTest , lessThanEqualToTestIntModulo ) {
  SubIntModulo a ( 8 ) ;
  SubIntModulo b ( 8 ) ;
  ASSERT_TRUE ( a <= b ) ;
  ASSERT_FALSE ( a > b ) ;
}

TEST( GoogleTest , greaterThanTestIntModulo ) {
  SubIntModulo a ( 8 ) ;
  SubIntModulo b ( 9 ) ;
  ASSERT_TRUE ( b > a ) ;
  ASSERT_FALSE ( b <= a ) ;
}

TEST( GoogleTest , greaterThanEqualToTestIntModulo ) {
  SubIntModulo a ( 8 ) ;
  SubIntModulo b ( 8 ) ;
  ASSERT_TRUE ( a >= b ) ;
  ASSERT_FALSE ( a < b ) ;
}


typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>, subrange::saturated_arithmetic> SubIntSaturated ;

TEST( GoogleTest , createDefaultTestIntSaturated ) {
  SubIntSaturated a ;
  ASSERT_EQ ( 1 , a ) ;
}

TEST( GoogleTest , preincrementTestIntSaturated ) {
  SubIntSaturated a ( 9 ) ;
  ++a ;
  ASSERT_EQ ( 10 , a ) ;
}

TEST( GoogleTest , postincrementTestIntSaturated ) {
  SubIntSaturated a ( 9 ) ;
  a++ ;
  ASSERT_EQ ( 10 , a ) ;
}

TEST( GoogleTest , predecrementTestIntSaturated ) {
  SubIntSaturated a ( 9 ) ;
  --a ;
  ASSERT_EQ ( 8 , a ) ;
}

TEST( GoogleTest , postdecrementTestIntSaturated ) {
  SubIntSaturated a ( 9 ) ;
  a-- ;
  ASSERT_EQ ( 8 , a ) ;
}

TEST( GoogleTest , assignLiteralTestIntSaturated ) {
  SubIntSaturated a ( 9 ) ;
  a = 20 ;
  ASSERT_EQ ( 20 , a ) ;
  a = 200 ;
  ASSERT_EQ ( 99 , a ) ;
  a = -5 ;
  ASSERT_EQ ( 1 , a ) ;
}

TEST( GoogleTest , assignTestIntSaturated ) {
  SubIntSaturated a ( 9 ) ;
  SubIntSaturated b ( 20 ) ;
  a = b ;
  ASSERT_EQ ( b , a ) ;
  ASSERT_EQ ( 20 , a ) ;
}

TEST( GoogleTest , addAssignTestIntSaturated ) {
  SubIntSaturated a ( 9 ) ;
  SubIntSaturated b ( 20 ) ;
  a += b ;
  ASSERT_EQ ( 29 , a ) ;
  a += 10 ;
  ASSERT_EQ ( 39 , a ) ;
  a += -10 ;
  ASSERT_EQ ( 29 , a ) ;
  a += 200 ;
  ASSERT_EQ ( 99 , a ) ;
}

TEST( GoogleTest , subtractAssignTestIntSaturated ) {
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 9 ) ;
  a -= b ;
  ASSERT_EQ ( 11 , a ) ;
  a -= 5 ;
  ASSERT_EQ ( 6 , a ) ;
  a -= -5 ;
  ASSERT_EQ ( 11 , a ) ;
  b -= a ;
  ASSERT_EQ ( 1 , b ) ;
}

TEST( GoogleTest , multiplyAssignTestIntSaturated ) {
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 3 ) ;
  a *= b ;
  ASSERT_EQ ( 60 , a ) ;
  a *= b ;
  ASSERT_EQ ( 99 , a ) ;
}

TEST( GoogleTest , divideAssignTestIntSaturated ) {
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 3 ) ;
  a /= b ;
  ASSERT_EQ ( 6 , a ) ;
}

TEST( GoogleTest , remainderAssignTestIntSaturated ) {
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 3 ) ;
  a %= b ;
  ASSERT_EQ ( 2 , a ) ;
}

TEST( GoogleTest , xorAssignTestIntSaturated ) {
  SubIntSaturated a ( 0x12 ) ;
  SubIntSaturated b ( 0x03 ) ;
  a ^= b ;
  ASSERT_EQ ( 0x11 , a ) ;
}

TEST( GoogleTest , andAssignTestIntSaturated ) {
  SubIntSaturated a ( 0x12 ) ;
  SubIntSaturated b ( 0x03 ) ;
  a &= b ;
  ASSERT_EQ ( 0x02 , a ) ;
}

TEST( GoogleTest , orAssignTestIntSaturated ) {
  SubIntSaturated a ( 0x12 ) ;
  SubIntSaturated b ( 0x03 ) ;
  a |= b ;
  ASSERT_EQ ( 0x13 , a ) ;
}

TEST( GoogleTest , shiftLeftAssignTestIntSaturated ) {
  SubIntSaturated a ( 0x12 ) ;
  a <<= 1 ;
  ASSERT_EQ ( 0x24 , a ) ;
}

TEST( GoogleTest , shiftRightAssignTestIntSaturated ) {
  SubIntSaturated a ( 0x12 ) ;
  a >>= 1 ;
  ASSERT_EQ ( 0x09 , a ) ;
}

TEST( GoogleTest , addTestIntSaturated ) {
  SubIntSaturated a ( 9 ) ;
  SubIntSaturated b ( 20 ) ;
  a = a + b ;
  ASSERT_EQ ( 29 , a ) ;
  a = a + 10 ;
  ASSERT_EQ ( 39 , a ) ;
  a = a + -10 ;
  ASSERT_EQ ( 29 , a ) ;
  a = 10 + a ;
  ASSERT_EQ ( 39 , a ) ;
  a = -10 + a ;
  ASSERT_EQ ( 29 , a ) ;
}

TEST( GoogleTest , subtractTestIntSaturated ) {
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 9 ) ;
  a = a - b ;
  ASSERT_EQ ( 11 , a ) ;
}

TEST( GoogleTest , multiplyTestIntSaturated ) {
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 3 ) ;
  a = a * b ;
  ASSERT_EQ ( 60 , a ) ;
}

TEST( GoogleTest , divideTestIntSaturated ) {
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 3 ) ;
  a = a / b ;
  ASSERT_EQ ( 6 , a ) ;
}

TEST( GoogleTest , remainderTestIntSaturated ) {
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 3 ) ;
  a = a % b ;
  ASSERT_EQ ( 2 , a ) ;
}

TEST( GoogleTest , xorTestIntSaturated ) {
  SubIntSaturated a ( 0x12 ) ;
  SubIntSaturated b ( 0x03 ) ;
  a = a ^ b ;
  ASSERT_EQ ( 0x11 , a ) ;
}

TEST( GoogleTest , andTestIntSaturated ) {
  SubIntSaturated a ( 0x12 ) ;
  SubIntSaturated b ( 0x03 ) ;
  a = a & b ;
  ASSERT_EQ ( 0x02 , a ) ;
}

TEST( GoogleTest , orTestIntSaturated ) {
  SubIntSaturated a ( 0x12 ) ;
  SubIntSaturated b ( 0x03 ) ;
  a = a | b ;
  ASSERT_EQ ( 0x13 , a ) ;
}

TEST( GoogleTest , shiftLeftTestIntSaturated ) {
  SubIntSaturated a ( 0x12 ) ;
  a = a << 1 ;
  ASSERT_EQ ( 0x24 , a ) ;
  a = a << 3 ;
  ASSERT_EQ ( 99 , a ) ;
}

TEST( GoogleTest , shiftRightTestIntSaturated ) {
  SubIntSaturated a ( 0x12 ) ;
  a = a >> 1 ;
  ASSERT_EQ ( 0x09 , a ) ;
  a = a >> 5 ;
  ASSERT_EQ ( 1 , a ) ;
}

TEST( GoogleTest , equalsTestIntSaturated ) {
  SubIntSaturated a ( 9 ) ;
  SubIntSaturated b ( 9 ) ;
  ASSERT_EQ ( b , a ) ;
}

TEST( GoogleTest , notEqualsTestIntSaturated ) {
  SubIntSaturated a ( 9 ) ;
  SubIntSaturated b ( 8 ) ;
  ASSERT_TRUE ( a != b ) ;
}

TEST( GoogleTest , lessThanTestIntSaturated ) {
  SubIntSaturated a ( 8 ) ;
  SubIntSaturated b ( 9 ) ;
  ASSERT_TRUE ( a < b ) ;
  ASSERT_FALSE ( a >= b ) ;
}

TEST( GoogleTest , lessThanEqualToTestIntSaturated ) {
  SubIntSaturated a ( 8 ) ;
  SubIntSaturated b ( 8 ) ;
  ASSERT_TRUE ( a <= b ) ;
  ASSERT_FALSE ( a > b ) ;
}

TEST( GoogleTest , greaterThanTestIntSaturated ) {
  SubIntSaturated a ( 8 ) ;
  SubIntSaturated b ( 9 ) ;
  ASSERT_TRUE ( b > a ) ;
  ASSERT_FALSE ( b <= a ) ;
}

TEST( GoogleTest , greaterThanEqualToTestIntSaturated ) {
  SubIntSaturated a ( 8 ) ;
  SubIntSaturated b ( 8 ) ;
  ASSERT_TRUE ( a >= b ) ;
  ASSERT_FALSE ( a < b ) ;
}


typedef subrange::ordinal_range<short, 1, 99> RangeTraits ;
typedef subrange::subrange<RangeTraits, subrange::NaN_arithmetic> SubIntNaN ;

inline bool isNaN(const SubIntNaN & s) { return subrange::NaN_arithmetic<RangeTraits>::isNaN(s) ; }

TEST( GoogleTest , createDefaultTestIntNaN ) {
  SubIntNaN a ;
  ASSERT_EQ ( 1 , a ) ;
}

TEST( GoogleTest , preincrementTestIntNaN ) {
  SubIntNaN a ( 9 ) ;
  ++a ;
  ASSERT_EQ ( 10 , a ) ;
}

TEST( GoogleTest , postincrementTestIntNaN ) {
  SubIntNaN a ( 9 ) ;
  a++ ;
  ASSERT_EQ ( 10 , a ) ;
}

TEST( GoogleTest , predecrementTestIntNaN ) {
  SubIntNaN a ( 9 ) ;
  --a ;
  ASSERT_EQ ( 8 , a ) ;
}

TEST( GoogleTest , postdecrementTestIntNaN ) {
  SubIntNaN a ( 9 ) ;
  a-- ;
  ASSERT_EQ ( 8 , a ) ;
}

TEST( GoogleTest , assignLiteralTestIntNaN ) {
  SubIntNaN a ( 9 ) ;
  a = 20 ;
  ASSERT_EQ ( 20 , a ) ;
  a = 200 ;
  ASSERT_TRUE ( isNaN ( a ) ) ;
  a = -5 ;
  ASSERT_TRUE ( isNaN ( a ) ) ;
}

TEST( GoogleTest , assignTestIntNaN ) {
  SubIntNaN a ( 9 ) ;
  SubIntNaN b ( 20 ) ;
  a = b ;
  ASSERT_EQ ( b , a ) ;
  ASSERT_EQ ( 20 , a ) ;
}

TEST( GoogleTest , addAssignTestIntNaN ) {
  SubIntNaN a ( 9 ) ;
  SubIntNaN b ( 20 ) ;
  a += b ;
  ASSERT_EQ ( 29 , a ) ;
  a += 10 ;
  ASSERT_EQ ( 39 , a ) ;
  a += -10 ;
  ASSERT_EQ ( 29 , a ) ;
  a += 200 ;
  ASSERT_TRUE ( isNaN ( a ) ) ;
}

TEST( GoogleTest , subtractAssignTestIntNaN ) {
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 9 ) ;
  a -= b ;
  ASSERT_EQ ( 11 , a ) ;
  a -= 5 ;
  ASSERT_EQ ( 6 , a ) ;
  a -= -5 ;
  ASSERT_EQ ( 11 , a ) ;
  b -= a ;
  ASSERT_TRUE ( isNaN ( b ) ) ;
}

TEST( GoogleTest , multiplyAssignTestIntNaN ) {
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 3 ) ;
  a *= b ;
  ASSERT_EQ ( 60 , a ) ;
  a *= b ;
  ASSERT_TRUE ( isNaN ( a ) ) ;
}

TEST( GoogleTest , divideAssignTestIntNaN ) {
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 3 ) ;
  a /= b ;
  ASSERT_EQ ( 6 , a ) ;
}

TEST( GoogleTest , remainderAssignTestIntNaN ) {
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 3 ) ;
  a %= b ;
  ASSERT_EQ ( 2 , a ) ;
}

TEST( GoogleTest , xorAssignTestIntNaN ) {
  SubIntNaN a ( 0x12 ) ;
  SubIntNaN b ( 0x03 ) ;
  a ^= b ;
  ASSERT_EQ ( 0x11 , a ) ;
}

TEST( GoogleTest , andAssignTestIntNaN ) {
  SubIntNaN a ( 0x12 ) ;
  SubIntNaN b ( 0x03 ) ;
  a &= b ;
  ASSERT_EQ ( 0x02 , a ) ;
}

TEST( GoogleTest , orAssignTestIntNaN ) {
  SubIntNaN a ( 0x12 ) ;
  SubIntNaN b ( 0x03 ) ;
  a |= b ;
  ASSERT_EQ ( 0x13 , a ) ;
}

TEST( GoogleTest , shiftLeftAssignTestIntNaN ) {
  SubIntNaN a ( 0x12 ) ;
  a <<= 1 ;
  ASSERT_EQ ( 0x24 , a ) ;
}

TEST( GoogleTest , shiftRightAssignTestIntNaN ) {
  SubIntNaN a ( 0x12 ) ;
  a >>= 1 ;
  ASSERT_EQ ( 0x09 , a ) ;
}

TEST( GoogleTest , addTestIntNaN ) {
  SubIntNaN a ( 9 ) ;
  SubIntNaN b ( 20 ) ;
  a = a + b ;
  ASSERT_EQ ( 29 , a ) ;
  a = a + 10 ;
  ASSERT_EQ ( 39 , a ) ;
  a = a + -10 ;
  ASSERT_EQ ( 29 , a ) ;
  a = 10 + a ;
  ASSERT_EQ ( 39 , a ) ;
  a = -10 + a ;
  ASSERT_EQ ( 29 , a ) ;
}

TEST( GoogleTest , subtractTestIntNaN ) {
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 9 ) ;
  a = a - b ;
  ASSERT_EQ ( 11 , a ) ;
}

TEST( GoogleTest , multiplyTestIntNaN ) {
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 3 ) ;
  a = a * b ;
  ASSERT_EQ ( 60 , a ) ;
}

TEST( GoogleTest , divideTestIntNaN ) {
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 3 ) ;
  a = a / b ;
  ASSERT_EQ ( 6 , a ) ;
}

TEST( GoogleTest , remainderTestIntNaN ) {
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 3 ) ;
  a = a % b ;
  ASSERT_EQ ( 2 , a ) ;
}

TEST( GoogleTest , xorTestIntNaN ) {
  SubIntNaN a ( 0x12 ) ;
  SubIntNaN b ( 0x03 ) ;
  a = a ^ b ;
  ASSERT_EQ ( 0x11 , a ) ;
}

TEST( GoogleTest , andTestIntNaN ) {
  SubIntNaN a ( 0x12 ) ;
  SubIntNaN b ( 0x03 ) ;
  a = a & b ;
  ASSERT_EQ ( 0x02 , a ) ;
}

TEST( GoogleTest , orTestIntNaN ) {
  SubIntNaN a ( 0x12 ) ;
  SubIntNaN b ( 0x03 ) ;
  a = a | b ;
  ASSERT_EQ ( 0x13 , a ) ;
}

TEST( GoogleTest , shiftLeftTestIntNaN ) {
  SubIntNaN a ( 0x12 ) ;
  a = a << 1 ;
  ASSERT_EQ ( 0x24 , a ) ;
  a = a << 3 ;
  ASSERT_TRUE ( isNaN ( a ) ) ;
}

TEST( GoogleTest , shiftRightTestIntNaN ) {
  SubIntNaN a ( 0x12 ) ;
  a = a >> 1 ;
  ASSERT_EQ ( 0x09 , a ) ;
  a = a >> 5 ;
  ASSERT_TRUE ( isNaN ( a ) ) ;
}

TEST( GoogleTest , equalsTestIntNaN ) {
  SubIntNaN a ( 9 ) ;
  SubIntNaN b ( 9 ) ;
  ASSERT_EQ ( b , a ) ;
}

TEST( GoogleTest , notEqualsTestIntNaN ) {
  SubIntNaN a ( 9 ) ;
  SubIntNaN b ( 8 ) ;
  ASSERT_TRUE ( a != b ) ;
}

TEST( GoogleTest , lessThanTestIntNaN ) {
  SubIntNaN a ( 8 ) ;
  SubIntNaN b ( 9 ) ;
  ASSERT_TRUE ( a < b ) ;
  ASSERT_FALSE ( a >= b ) ;
}

TEST( GoogleTest , lessThanEqualToTestIntNaN ) {
  SubIntNaN a ( 8 ) ;
  SubIntNaN b ( 8 ) ;
  ASSERT_TRUE ( a <= b ) ;
  ASSERT_FALSE ( a > b ) ;
}

TEST( GoogleTest , greaterThanTestIntNaN ) {
  SubIntNaN a ( 8 ) ;
  SubIntNaN b ( 9 ) ;
  ASSERT_TRUE ( b > a ) ;
  ASSERT_FALSE ( b <= a ) ;
}

TEST( GoogleTest , greaterThanEqualToTestIntNaN ) {
  SubIntNaN a ( 8 ) ;
  SubIntNaN b ( 8 ) ;
  ASSERT_TRUE ( a >= b ) ;
  ASSERT_FALSE ( a < b ) ;
}


//  Can't use any templates for defining floating point range traits as C++ forbids template parameters
//  that are not of ordinal type so we haver to do that manually.
 
class float_range {
 public :
  typedef double value_type ;
  typedef subrange::range_error exception_type ;
  static double min ( ) { return 1.0 ; }
  static double max ( ) { return 99.0 ; }
} ;

typedef subrange::subrange<float_range> SubFloat ;

TEST( GoogleTest , createDefaultTestFloat ) {
  SubFloat a ;
  ASSERT_EQ ( 1.0 , a ) ;
}

TEST( GoogleTest , preincrementTestFloat ) {
  SubFloat a ( 9.0 ) ;
  ++a ;
  ASSERT_EQ ( 10.0 , a ) ;
}

TEST( GoogleTest , postincrementTestFloat ) {
  SubFloat a ( 9.0 ) ;
  a++ ;
  ASSERT_EQ ( 10.0 , a ) ;
}

TEST( GoogleTest , predecrementTestFloat ) {
  SubFloat a ( 9.0 ) ;
  --a ;
  ASSERT_EQ ( 8.0 , a ) ;
}

TEST( GoogleTest , postdecrementTestFloat ) {
  SubFloat a ( 9.0 ) ;
  a-- ;
  ASSERT_EQ ( 8.0 , a ) ;
}

TEST( GoogleTest , assignLiteralTestFloat ) {
  SubFloat a ( 9.0 ) ;
  a = 20.0 ;
  ASSERT_EQ ( 20.0 , a ) ;
  ASSERT_THROW ( a = 200.0 , subrange::range_error ) ;
  ASSERT_THROW ( a = -5.0 , subrange::range_error ) ;
}

TEST( GoogleTest , assignTestFloat ) {
  SubFloat a ( 9.0 ) ;
  SubFloat b ( 20.0 ) ;
  a = b ;
  ASSERT_EQ ( b , a ) ;
  ASSERT_EQ ( 20.0 , a ) ;
}

TEST( GoogleTest , addAssignTestFloat ) {
  SubFloat a ( 9.0 ) ;
  SubFloat b ( 20.0 ) ;
  a += b ;
  ASSERT_EQ ( 29.0 , a ) ;
  a += 10 ;
  ASSERT_EQ ( 39.0 , a ) ;
  a += -10 ;
  ASSERT_EQ ( 29.0 , a ) ;
  ASSERT_THROW ( a += 200.0 , subrange::range_error ) ;
}

TEST( GoogleTest , subtractAssignTestFloat ) {
  SubFloat a ( 20.0 ) ;
  SubFloat b ( 9.0 ) ;
  a -= b ;
  ASSERT_EQ ( 11.0 , a ) ;
  a -= 5.0 ;
  ASSERT_EQ ( 6.0 , a ) ;
  a -= -5.0 ;
  ASSERT_EQ ( 11.0 , a ) ;
  ASSERT_THROW ( b -= a , subrange::range_error ) ;
}

TEST( GoogleTest , multiplyAssignTestFloat ) {
  SubFloat a ( 20.0 ) ;
  SubFloat b ( 3.0 ) ;
  a *= b ;
  ASSERT_EQ ( 60.0 , a ) ;
  ASSERT_THROW ( a *= b , subrange::range_error ) ;
}

TEST( GoogleTest , divideAssignTestFloat ) {
  SubFloat a ( 20.0 ) ;
  SubFloat b ( 4.0 ) ;
  a /= b ;
  ASSERT_EQ ( 5.0 , a ) ;
}

TEST( GoogleTest , addTestFloat ) {
  SubFloat a ( 9.0 ) ;
  SubFloat b ( 20.0 ) ;
  a = a + b ;
  ASSERT_EQ ( 29.0 , a ) ;
  a = a + 10.0 ;
  ASSERT_EQ ( 39.0 , a ) ;
  a = a + -10.0 ;
  ASSERT_EQ ( 29.0 , a ) ;
  a = 10.0 + a ;
  ASSERT_EQ ( 39.0 , a ) ;
  a = -10.0 + a ;
  ASSERT_EQ ( 29.0 , a ) ;
}

TEST( GoogleTest , subtractTestFloat ) {
  SubFloat a ( 20.0 ) ;
  SubFloat b ( 9.0 ) ;
  a = a - b ;
  ASSERT_EQ ( 11.0 , a ) ;
}

TEST( GoogleTest , multiplyTestFloat ) {
  SubFloat a ( 20.0 ) ;
  SubFloat b ( 3.0 ) ;
  a = a * b ;
  ASSERT_EQ ( 60.0 , a ) ;
}

TEST( GoogleTest , divideTestFloat ) {
  SubFloat a ( 20.0 ) ;
  SubFloat b ( 4.0 ) ;
  a = a / b ;
  ASSERT_EQ ( 5.0 , a ) ;
}

TEST( GoogleTest , equalsTestFloat ) {
  SubFloat a ( 9.0 ) ;
  SubFloat b ( 9.0 ) ;
  ASSERT_EQ ( b , a ) ;
}

TEST( GoogleTest , notEqualsTestFloat ) {
  SubFloat a ( 9.0 ) ;
  SubFloat b ( 8.0 ) ;
  ASSERT_TRUE ( a != b ) ;
}

TEST( GoogleTest , lessThanTestFloat ) {
  SubFloat a ( 8.0 ) ;
  SubFloat b ( 9.0 ) ;
  EXPECT_TRUE ( a < b ) ;
  ASSERT_FALSE ( a >= b ) ;
}

TEST( GoogleTest , lessThanEqualToTestFloat ) {
  SubFloat a ( 8.0 ) ;
  SubFloat b ( 8.0 ) ;
  EXPECT_TRUE ( a <= b ) ;
  ASSERT_FALSE ( a > b ) ;
}

TEST( GoogleTest , greaterThanTestFloat ) {
  SubFloat a ( 8.0 ) ;
  SubFloat b ( 9.0 ) ;
  EXPECT_TRUE ( b > a ) ;
  ASSERT_FALSE ( b <= a ) ;
}

TEST( GoogleTest , greaterThanEqualToTestFloat ) {
  SubFloat a ( 8.0 ) ;
  SubFloat b ( 8.0 ) ;
  EXPECT_TRUE ( a >= b ) ;
  ASSERT_FALSE ( a < b ) ;
}


int main ( int argc , char ** argv ) {
  ::testing::InitGoogleTest ( &argc , argv ) ;
  return RUN_ALL_TESTS( ) ;
}
