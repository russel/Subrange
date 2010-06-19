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

TEST( GoogleTest , createDefaultTestEnum )
{
  Weekday a ;
  EXPECT_TRUE( a == monday ) ;
}

TEST( GoogleTest , assignTestEnum )
{
  Weekday a ( monday ) ;
  Weekday b ( tuesday ) ;
  a = b ;
  EXPECT_TRUE( a == b ) ;
}

TEST( GoogleTest , equalsTestEnum )
{
  Weekday a ( monday ) ;
  Weekday b ( monday ) ;
  EXPECT_TRUE( a == b ) ;
}

TEST( GoogleTest , notEqualsTestEnum )
{
  Weekday a ( monday ) ;
  Weekday b ( tuesday ) ;
  EXPECT_TRUE( a != b ) ;
}

TEST( GoogleTest , lessThanTestEnum )
{
  Weekday a ( monday ) ;
  Weekday b ( tuesday ) ;
  EXPECT_TRUE( a < b ) ;
  EXPECT_TRUE( ! ( a >= b ) ) ;
}

TEST( GoogleTest , lessThanEqualToTestEnum )
{
  Weekday a ( monday ) ;
  Weekday b ( monday ) ;
  EXPECT_TRUE( a <= b ) ;
  EXPECT_TRUE( ! ( a > b ) ) ;
}

TEST( GoogleTest , greaterThanTestEnum )
{
  Weekday a ( monday ) ;
  Weekday b ( tuesday ) ;
  EXPECT_TRUE( b > a ) ;
  EXPECT_TRUE( ! ( b <= a ) ) ;
}

TEST( GoogleTest , greaterThanEqualToTestEnum )
{
  Weekday a ( monday ) ;
  Weekday b ( monday ) ;
  EXPECT_TRUE( a >= b ) ;
  EXPECT_TRUE( ! ( a < b ) ) ;
}


typedef subrange::subrange<subrange::ordinal_range<short, 1, 99> > SubIntException ;

TEST( GoogleTest , createDefaultTestIntException )
{
  SubIntException a ;
  EXPECT_TRUE( a == 1 ) ;
}

TEST( GoogleTest , preincrementTestIntException )
{
  SubIntException a ( 9 ) ;
  ++a ;
  EXPECT_TRUE( a == 10 ) ;
}

TEST( GoogleTest , postincrementTestIntException )
{
  SubIntException a ( 9 ) ;
  a++ ;
  EXPECT_TRUE( a == 10 ) ;
}

TEST( GoogleTest , predecrementTestIntException )
{
  SubIntException a ( 9 ) ;
  --a ;
  EXPECT_TRUE( a == 8 ) ;
}

TEST( GoogleTest , postdecrementTestIntException )
{
  SubIntException a ( 9 ) ;
  a-- ;
  EXPECT_TRUE( a == 8 ) ;
}

TEST( GoogleTest , assignLiteralTestIntException )
{
  SubIntException a ( 9 ) ;
  a = 20 ;
  EXPECT_TRUE( a == 20 ) ;
  EXPECT_THROW( a = 200 , subrange::range_error ) ;
  EXPECT_THROW( a = -5 , subrange::range_error ) ;
}

TEST( GoogleTest , assignTestIntException )
{
  SubIntException a ( 9 ) ;
  SubIntException b ( 20 ) ;
  a = b ;
  EXPECT_TRUE( a == b ) ;
  EXPECT_TRUE( a == 20 ) ;
}

TEST( GoogleTest , addAssignTestIntException )
{
  SubIntException a ( 9 ) ;
  SubIntException b ( 20 ) ;
  a += b ;
  EXPECT_TRUE( a == 29 ) ;
  a += 10 ;
  EXPECT_TRUE( a == 39 ) ;
  a += -10 ;
  EXPECT_TRUE( a == 29 ) ;
  EXPECT_THROW( a += 200 , subrange::range_error ) ;
}

TEST( GoogleTest , subtractAssignTestIntException )
{
  SubIntException a ( 20 ) ;
  SubIntException b ( 9 ) ;
  a -= b ;
  EXPECT_TRUE( a == 11 ) ;
  a -= 5 ;
  EXPECT_TRUE( a == 6 ) ;
  a -= -5 ;
  EXPECT_TRUE( a == 11 ) ;
  EXPECT_THROW(b -= a, subrange::range_error) ;
}

TEST( GoogleTest , multiplyAssignTestIntException )
{
  SubIntException a ( 20 ) ;
  SubIntException b ( 3 ) ;
  a *= b ;
  EXPECT_TRUE( a == 60 ) ;
  EXPECT_THROW(a *= b, subrange::range_error) ;
}

TEST( GoogleTest , divideAssignTestIntException )
{
  SubIntException a ( 20 ) ;
  SubIntException b ( 3 ) ;
  a /= b ;
  EXPECT_TRUE( a == 6 ) ;
}

TEST( GoogleTest , remainderAssignTestIntException )
{
  SubIntException a ( 20 ) ;
  SubIntException b ( 3 ) ;
  a %= b ;
  EXPECT_TRUE( a == 2 ) ;
}

TEST( GoogleTest , xorAssignTestIntException )
{
  SubIntException a ( 0x12 ) ;
  SubIntException b ( 0x03 ) ;
  a ^= b ;
  EXPECT_TRUE( a == 0x11 ) ;
}

TEST( GoogleTest , andAssignTestIntException )
{
  SubIntException a ( 0x12 ) ;
  SubIntException b ( 0x03 ) ;
  a &= b ;
  EXPECT_TRUE( a == 0x02 ) ;
}

TEST( GoogleTest , orAssignTestIntException )
{
  SubIntException a ( 0x12 ) ;
  SubIntException b ( 0x03 ) ;
  a |= b ;
  EXPECT_TRUE( a == 0x13 ) ;
}

TEST( GoogleTest , shiftLeftAssignTestIntException )
{
  SubIntException a ( 0x12 ) ;
  a <<= 1 ;
  EXPECT_TRUE( a == 0x24 ) ;
}

TEST( GoogleTest , shiftRightAssignTestIntException )
{
  SubIntException a ( 0x12 ) ;
  a >>= 1 ;
  EXPECT_TRUE( a == 0x09 ) ;
}

TEST( GoogleTest , addTestIntException )
{
  SubIntException a ( 9 ) ;
  SubIntException b ( 20 ) ;
  a = a + b ;
  EXPECT_TRUE( a == 29 ) ;
  a = a + 10 ;
  EXPECT_TRUE( a == 39 ) ;
  a = a + -10 ;
  EXPECT_TRUE( a == 29 ) ;
  a = 10 + a ;
  EXPECT_TRUE( a == 39 ) ;
  a = -10 + a ;
  EXPECT_TRUE( a == 29 ) ;
}

TEST( GoogleTest , subtractTestIntException )
{
  SubIntException a ( 20 ) ;
  SubIntException b ( 9 ) ;
  a = a - b ;
  EXPECT_TRUE( a == 11 ) ;
}

TEST( GoogleTest , multiplyTestIntException )
{
  SubIntException a ( 20 ) ;
  SubIntException b ( 3 ) ;
  a = a * b ;
  EXPECT_TRUE( a == 60 ) ;
}

TEST( GoogleTest , divideTestIntException )
{
  SubIntException a ( 20 ) ;
  SubIntException b ( 3 ) ;
  a = a / b ;
  EXPECT_TRUE( a == 6 ) ;
}

TEST( GoogleTest , remainderTestIntException )
{
  SubIntException a ( 20 ) ;
  SubIntException b ( 3 ) ;
  a = a % b ;
  EXPECT_TRUE( a == 2 ) ;
}

TEST( GoogleTest , xorTestIntException )
{
  SubIntException a ( 0x12 ) ;
  SubIntException b ( 0x03 ) ;
  a = a ^ b ;
  EXPECT_TRUE( a == 0x11 ) ;
}

TEST( GoogleTest , andTestIntException )
{
  SubIntException a ( 0x12 ) ;
  SubIntException b ( 0x03 ) ;
  a = a & b ;
  EXPECT_TRUE( a == 0x02 ) ;
}

TEST( GoogleTest , orTestIntException )
{
  SubIntException a ( 0x12 ) ;
  SubIntException b ( 0x03 ) ;
  a = a | b ;
  EXPECT_TRUE( a == 0x13 ) ;
}

TEST( GoogleTest , shiftLeftTestIntException )
{
  SubIntException a ( 0x12 ) ;
  a = a << 1 ;
  EXPECT_TRUE( a == 0x24 ) ;
  EXPECT_THROW( a = a << 3 , subrange::range_error ) ;
}

TEST( GoogleTest , shiftRightTestIntException )
{
  SubIntException a ( 0x12 ) ;
  a = a >> 1 ;
  EXPECT_TRUE( a == 0x09 ) ;
  EXPECT_THROW( a = a >> 5 , subrange::range_error ) ;
}

TEST( GoogleTest , equalsTestIntException )
{
  SubIntException a ( 9 ) ;
  SubIntException b ( 9 ) ;
  EXPECT_TRUE( a == b ) ;
}

TEST( GoogleTest , notEqualsTestIntException )
{
  SubIntException a ( 9 ) ;
  SubIntException b ( 8 ) ;
  EXPECT_TRUE( a != b ) ;
}

TEST( GoogleTest , lessThanTestIntException )
{
  SubIntException a ( 8 ) ;
  SubIntException b ( 9 ) ;
  EXPECT_TRUE( a < b ) ;
  EXPECT_TRUE( ! ( a >= b ) ) ;
}

TEST( GoogleTest , lessThanEqualToTestIntException )
{
  SubIntException a ( 8 ) ;
  SubIntException b ( 8 ) ;
  EXPECT_TRUE( a <= b ) ;
  EXPECT_TRUE( ! ( a > b ) ) ;
}

TEST( GoogleTest , greaterThanTestIntException )
{
  SubIntException a ( 8 ) ;
  SubIntException b ( 9 ) ;
  EXPECT_TRUE( b > a ) ;
  EXPECT_TRUE( ! ( b <= a ) ) ;
}

TEST( GoogleTest , greaterThanEqualToTestIntException )
{
  SubIntException a ( 8 ) ;
  SubIntException b ( 8 ) ;
  EXPECT_TRUE( a >= b ) ;
  EXPECT_TRUE( ! ( a < b ) ) ;
}

typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>, subrange::modulo_arithmetic> SubIntModulo ;

TEST( GoogleTest , createDefaultTestIntModulo )
{
  SubIntModulo a ;
  EXPECT_TRUE( a == 1 ) ;
}

TEST( GoogleTest , preincrementTestIntModulo )
{
  SubIntModulo a ( 9 ) ;
  ++a ;
  EXPECT_TRUE( a == 10 ) ;
}

TEST( GoogleTest , postincrementTestIntModulo )
{
  SubIntModulo a ( 9 ) ;
  a++ ;
  EXPECT_TRUE( a == 10 ) ;
}

TEST( GoogleTest , predecrementTestIntModulo )
{
  SubIntModulo a ( 9 ) ;
  --a ;
  EXPECT_TRUE( a == 8 ) ;
}

TEST( GoogleTest , postdecrementTestIntModulo )
{
  SubIntModulo a ( 9 ) ;
  a-- ;
  EXPECT_TRUE( a == 8 ) ;
}

TEST( GoogleTest , assignLiteralTestIntModulo )
{
  SubIntModulo a ( 9 ) ;
  a = 20 ;
  EXPECT_TRUE( a == 20 ) ;
  a = 200 ;
  EXPECT_TRUE( a == 4 ) ;
  a = -5 ;
  EXPECT_TRUE( a == 93 ) ;
}

TEST( GoogleTest , assignTestIntModulo )
{
  SubIntModulo a ( 9 ) ;
  SubIntModulo b ( 20 ) ;
  a = b ;
  EXPECT_TRUE( a == b ) ;
  EXPECT_TRUE( a == 20 ) ;
}

TEST( GoogleTest , addAssignTestIntModulo )
{
  SubIntModulo a ( 9 ) ;
  SubIntModulo b ( 20 ) ;
  a += b ;
  EXPECT_TRUE( a == 29 ) ;
  a += 10 ;
  EXPECT_TRUE( a == 39 ) ;
  a += -10 ;
  EXPECT_TRUE( a == 29 ) ;
  a += 200 ;
  EXPECT_TRUE( a == 33 ) ;
}

TEST( GoogleTest , subtractAssignTestIntModulo )
{
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 9 ) ;
  a -= b ;
  EXPECT_TRUE( a == 11 ) ;
  a -= 5 ;
  EXPECT_TRUE( a == 6 ) ;
  a -= -5 ;
  EXPECT_TRUE( a == 11 ) ;
  b -= a ;
  EXPECT_TRUE( b == 96 ) ;
}

TEST( GoogleTest , multiplyAssignTestIntModulo )
{
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 3 ) ;
  a *= b ;
  EXPECT_TRUE( a == 60 ) ;
  a *= b ;
  EXPECT_TRUE( a == 82 ) ;
}

TEST( GoogleTest , divideAssignTestIntModulo )
{
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 3 ) ;
  a /= b ;
  EXPECT_TRUE( a == 6 ) ;
}

TEST( GoogleTest , remainderAssignTestIntModulo )
{
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 3 ) ;
  a %= b ;
  EXPECT_TRUE( a == 2 ) ;
}

TEST( GoogleTest , xorAssignTestIntModulo )
{
  SubIntModulo a ( 0x12 ) ;
  SubIntModulo b ( 0x03 ) ;
  a ^= b ;
  EXPECT_TRUE( a == 0x11 ) ;
}

TEST( GoogleTest , andAssignTestIntModulo )
{
  SubIntModulo a ( 0x12 ) ;
  SubIntModulo b ( 0x03 ) ;
  a &= b ;
  EXPECT_TRUE( a == 0x02 ) ;
}

TEST( GoogleTest , orAssignTestIntModulo )
{
  SubIntModulo a ( 0x12 ) ;
  SubIntModulo b ( 0x03 ) ;
  a |= b ;
  EXPECT_TRUE( a == 0x13 ) ;
}

TEST( GoogleTest , shiftLeftAssignTestIntModulo )
{
  SubIntModulo a ( 0x12 ) ;
  a <<= 1 ;
  EXPECT_TRUE( a == 0x24 ) ;
}

TEST( GoogleTest , shiftRightAssignTestIntModulo )
{
  SubIntModulo a ( 0x12 ) ;
  a >>= 1 ;
  EXPECT_TRUE( a == 0x09 ) ;
}

TEST( GoogleTest , addTestIntModulo )
{
  SubIntModulo a ( 9 ) ;
  SubIntModulo b ( 20 ) ;
  a = a + b ;
  EXPECT_TRUE( a == 29 ) ;
  a = a + 10 ;
  EXPECT_TRUE( a == 39 ) ;
  a = a + -10 ;
  EXPECT_TRUE( a == 29 ) ;
  a = 10 + a ;
  EXPECT_TRUE( a == 39 ) ;
  a = -10 + a ;
  EXPECT_TRUE( a == 29 ) ;
}

TEST( GoogleTest , subtractTestIntModulo )
{
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 9 ) ;
  a = a - b ;
  EXPECT_TRUE( a == 11 ) ;
}

TEST( GoogleTest , multiplyTestIntModulo )
{
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 3 ) ;
  a = a * b ;
  EXPECT_TRUE( a == 60 ) ;
}

TEST( GoogleTest , divideTestIntModulo )
{
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 3 ) ;
  a = a / b ;
  EXPECT_TRUE( a == 6 ) ;
}

TEST( GoogleTest , remainderTestIntModulo )
{
  SubIntModulo a ( 20 ) ;
  SubIntModulo b ( 3 ) ;
  a = a % b ;
  EXPECT_TRUE( a == 2 ) ;
}

TEST( GoogleTest , xorTestIntModulo )
{
  SubIntModulo a ( 0x12 ) ;
  SubIntModulo b ( 0x03 ) ;
  a = a ^ b ;
  EXPECT_TRUE( a == 0x11 ) ;
}

TEST( GoogleTest , andTestIntModulo )
{
  SubIntModulo a ( 0x12 ) ;
  SubIntModulo b ( 0x03 ) ;
  a = a & b ;
  EXPECT_TRUE( a == 0x02 ) ;
}

TEST( GoogleTest , orTestIntModulo )
{
  SubIntModulo a ( 0x12 ) ;
  SubIntModulo b ( 0x03 ) ;
  a = a | b ;
  EXPECT_TRUE( a == 0x13 ) ;
}

TEST( GoogleTest , shiftLeftTestIntModulo )
{
  SubIntModulo a ( 0x12 ) ;
  a = a << 1 ;
  EXPECT_TRUE( a == 0x24 ) ;
  a = a << 3 ;
  EXPECT_TRUE( a == 92 ) ;
}

TEST( GoogleTest , shiftRightTestIntModulo )
{
  SubIntModulo a ( 0x12 ) ;
  a = a >> 1 ;
  EXPECT_TRUE( a == 0x09 ) ;
  a = a >> 5 ;
  EXPECT_TRUE( a == 98 ) ;
}

TEST( GoogleTest , equalsTestIntModulo )
{
  SubIntModulo a ( 9 ) ;
  SubIntModulo b ( 9 ) ;
  EXPECT_TRUE( a == b ) ;
}

TEST( GoogleTest , notEqualsTestIntModulo )
{
  SubIntModulo a ( 9 ) ;
  SubIntModulo b ( 8 ) ;
  EXPECT_TRUE( a != b ) ;
}

TEST( GoogleTest , lessThanTestIntModulo )
{
  SubIntModulo a ( 8 ) ;
  SubIntModulo b ( 9 ) ;
  EXPECT_TRUE( a < b ) ;
  EXPECT_TRUE( ! ( a >= b ) ) ;
}

TEST( GoogleTest , lessThanEqualToTestIntModulo )
{
  SubIntModulo a ( 8 ) ;
  SubIntModulo b ( 8 ) ;
  EXPECT_TRUE( a <= b ) ;
  EXPECT_TRUE( ! ( a > b ) ) ;
}

TEST( GoogleTest , greaterThanTestIntModulo )
{
  SubIntModulo a ( 8 ) ;
  SubIntModulo b ( 9 ) ;
  EXPECT_TRUE( b > a ) ;
  EXPECT_TRUE( ! ( b <= a ) ) ;
}

TEST( GoogleTest , greaterThanEqualToTestIntModulo )
{
  SubIntModulo a ( 8 ) ;
  SubIntModulo b ( 8 ) ;
  EXPECT_TRUE( a >= b ) ;
  EXPECT_TRUE( ! ( a < b ) ) ;
}

typedef subrange::subrange<subrange::ordinal_range<short, 1, 99>, subrange::saturated_arithmetic> SubIntSaturated ;

TEST( GoogleTest , createDefaultTestIntSaturated )
{
  SubIntSaturated a ;
  EXPECT_TRUE( a == 1 ) ;
}

TEST( GoogleTest , preincrementTestIntSaturated )
{
  SubIntSaturated a ( 9 ) ;
  ++a ;
  EXPECT_TRUE( a == 10 ) ;
}

TEST( GoogleTest , postincrementTestIntSaturated )
{
  SubIntSaturated a ( 9 ) ;
  a++ ;
  EXPECT_TRUE( a == 10 ) ;
}

TEST( GoogleTest , predecrementTestIntSaturated )
{
  SubIntSaturated a ( 9 ) ;
  --a ;
  EXPECT_TRUE( a == 8 ) ;
}

TEST( GoogleTest , postdecrementTestIntSaturated )
{
  SubIntSaturated a ( 9 ) ;
  a-- ;
  EXPECT_TRUE( a == 8 ) ;
}

TEST( GoogleTest , assignLiteralTestIntSaturated )
{
  SubIntSaturated a ( 9 ) ;
  a = 20 ;
  EXPECT_TRUE( a == 20 ) ;
  a = 200 ;
  EXPECT_TRUE( a == 99 ) ;
  a = -5 ;
  EXPECT_TRUE( a == 1 ) ;
}

TEST( GoogleTest , assignTestIntSaturated )
{
  SubIntSaturated a ( 9 ) ;
  SubIntSaturated b ( 20 ) ;
  a = b ;
  EXPECT_TRUE( a == b ) ;
  EXPECT_TRUE( a == 20 ) ;
}

TEST( GoogleTest , addAssignTestIntSaturated )
{
  SubIntSaturated a ( 9 ) ;
  SubIntSaturated b ( 20 ) ;
  a += b ;
  EXPECT_TRUE( a == 29 ) ;
  a += 10 ;
  EXPECT_TRUE( a == 39 ) ;
  a += -10 ;
  EXPECT_TRUE( a == 29 ) ;
  a += 200 ;
  EXPECT_TRUE( a == 99 ) ;
}

TEST( GoogleTest , subtractAssignTestIntSaturated )
{
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 9 ) ;
  a -= b ;
  EXPECT_TRUE( a == 11 ) ;
  a -= 5 ;
  EXPECT_TRUE( a == 6 ) ;
  a -= -5 ;
  EXPECT_TRUE( a == 11 ) ;
  b -= a ;
  EXPECT_TRUE( b == 1 ) ;
}

TEST( GoogleTest , multiplyAssignTestIntSaturated )
{
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 3 ) ;
  a *= b ;
  EXPECT_TRUE( a == 60 ) ;
  a *= b ;
  EXPECT_TRUE( a == 99 ) ;
}

TEST( GoogleTest , divideAssignTestIntSaturated )
{
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 3 ) ;
  a /= b ;
  EXPECT_TRUE( a == 6 ) ;
}

TEST( GoogleTest , remainderAssignTestIntSaturated )
{
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 3 ) ;
  a %= b ;
  EXPECT_TRUE( a == 2 ) ;
}

TEST( GoogleTest , xorAssignTestIntSaturated )
{
  SubIntSaturated a ( 0x12 ) ;
  SubIntSaturated b ( 0x03 ) ;
  a ^= b ;
  EXPECT_TRUE( a == 0x11 ) ;
}

TEST( GoogleTest , andAssignTestIntSaturated )
{
  SubIntSaturated a ( 0x12 ) ;
  SubIntSaturated b ( 0x03 ) ;
  a &= b ;
  EXPECT_TRUE( a == 0x02 ) ;
}

TEST( GoogleTest , orAssignTestIntSaturated )
{
  SubIntSaturated a ( 0x12 ) ;
  SubIntSaturated b ( 0x03 ) ;
  a |= b ;
  EXPECT_TRUE( a == 0x13 ) ;
}

TEST( GoogleTest , shiftLeftAssignTestIntSaturated )
{
  SubIntSaturated a ( 0x12 ) ;
  a <<= 1 ;
  EXPECT_TRUE( a == 0x24 ) ;
}

TEST( GoogleTest , shiftRightAssignTestIntSaturated )
{
  SubIntSaturated a ( 0x12 ) ;
  a >>= 1 ;
  EXPECT_TRUE( a == 0x09 ) ;
}

TEST( GoogleTest , addTestIntSaturated )
{
  SubIntSaturated a ( 9 ) ;
  SubIntSaturated b ( 20 ) ;
  a = a + b ;
  EXPECT_TRUE( a == 29 ) ;
  a = a + 10 ;
  EXPECT_TRUE( a == 39 ) ;
  a = a + -10 ;
  EXPECT_TRUE( a == 29 ) ;
  a = 10 + a ;
  EXPECT_TRUE( a == 39 ) ;
  a = -10 + a ;
  EXPECT_TRUE( a == 29 ) ;
}

TEST( GoogleTest , subtractTestIntSaturated )
{
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 9 ) ;
  a = a - b ;
  EXPECT_TRUE( a == 11 ) ;
}

TEST( GoogleTest , multiplyTestIntSaturated )
{
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 3 ) ;
  a = a * b ;
  EXPECT_TRUE( a == 60 ) ;
}

TEST( GoogleTest , divideTestIntSaturated )
{
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 3 ) ;
  a = a / b ;
  EXPECT_TRUE( a == 6 ) ;
}

TEST( GoogleTest , remainderTestIntSaturated )
{
  SubIntSaturated a ( 20 ) ;
  SubIntSaturated b ( 3 ) ;
  a = a % b ;
  EXPECT_TRUE( a == 2 ) ;
}

TEST( GoogleTest , xorTestIntSaturated )
{
  SubIntSaturated a ( 0x12 ) ;
  SubIntSaturated b ( 0x03 ) ;
  a = a ^ b ;
  EXPECT_TRUE( a == 0x11 ) ;
}

TEST( GoogleTest , andTestIntSaturated )
{
  SubIntSaturated a ( 0x12 ) ;
  SubIntSaturated b ( 0x03 ) ;
  a = a & b ;
  EXPECT_TRUE( a == 0x02 ) ;
}

TEST( GoogleTest , orTestIntSaturated )
{
  SubIntSaturated a ( 0x12 ) ;
  SubIntSaturated b ( 0x03 ) ;
  a = a | b ;
  EXPECT_TRUE( a == 0x13 ) ;
}

TEST( GoogleTest , shiftLeftTestIntSaturated )
{
  SubIntSaturated a ( 0x12 ) ;
  a = a << 1 ;
  EXPECT_TRUE( a == 0x24 ) ;
  a = a << 3 ;
  EXPECT_TRUE( a == 99 ) ;
}

TEST( GoogleTest , shiftRightTestIntSaturated )
{
  SubIntSaturated a ( 0x12 ) ;
  a = a >> 1 ;
  EXPECT_TRUE( a == 0x09 ) ;
  a = a >> 5 ;
  EXPECT_TRUE( a == 1 ) ;
}

TEST( GoogleTest , equalsTestIntSaturated )
{
  SubIntSaturated a ( 9 ) ;
  SubIntSaturated b ( 9 ) ;
  EXPECT_TRUE( a == b ) ;
}

TEST( GoogleTest , notEqualsTestIntSaturated )
{
  SubIntSaturated a ( 9 ) ;
  SubIntSaturated b ( 8 ) ;
  EXPECT_TRUE( a != b ) ;
}

TEST( GoogleTest , lessThanTestIntSaturated )
{
  SubIntSaturated a ( 8 ) ;
  SubIntSaturated b ( 9 ) ;
  EXPECT_TRUE( a < b ) ;
  EXPECT_TRUE( ! ( a >= b ) ) ;
}

TEST( GoogleTest , lessThanEqualToTestIntSaturated )
{
  SubIntSaturated a ( 8 ) ;
  SubIntSaturated b ( 8 ) ;
  EXPECT_TRUE( a <= b ) ;
  EXPECT_TRUE( ! ( a > b ) ) ;
}

TEST( GoogleTest , greaterThanTestIntSaturated )
{
  SubIntSaturated a ( 8 ) ;
  SubIntSaturated b ( 9 ) ;
  EXPECT_TRUE( b > a ) ;
  EXPECT_TRUE( ! ( b <= a ) ) ;
}

TEST( GoogleTest , greaterThanEqualToTestIntSaturated )
{
  SubIntSaturated a ( 8 ) ;
  SubIntSaturated b ( 8 ) ;
  EXPECT_TRUE( a >= b ) ;
  EXPECT_TRUE( ! ( a < b ) ) ;
}

typedef subrange::ordinal_range<short, 1, 99> RangeTraits ;
typedef subrange::subrange<RangeTraits, subrange::NaN_arithmetic> SubIntNaN ;

inline bool isNaN(const SubIntNaN & s) { return subrange::NaN_arithmetic<RangeTraits>::isNaN(s) ; }

TEST( GoogleTest , createDefaultTestIntNaN )
{
  SubIntNaN a ;
  EXPECT_TRUE( a == 1 ) ;
}

TEST( GoogleTest , preincrementTestIntNaN )
{
  SubIntNaN a ( 9 ) ;
  ++a ;
  EXPECT_TRUE( a == 10 ) ;
}

TEST( GoogleTest , postincrementTestIntNaN )
{
  SubIntNaN a ( 9 ) ;
  a++ ;
  EXPECT_TRUE( a == 10 ) ;
}

TEST( GoogleTest , predecrementTestIntNaN )
{
  SubIntNaN a ( 9 ) ;
  --a ;
  EXPECT_TRUE( a == 8 ) ;
}

TEST( GoogleTest , postdecrementTestIntNaN )
{
  SubIntNaN a ( 9 ) ;
  a-- ;
  EXPECT_TRUE( a == 8 ) ;
}

TEST( GoogleTest , assignLiteralTestIntNaN )
{
  SubIntNaN a ( 9 ) ;
  a = 20 ;
  EXPECT_TRUE( a == 20 ) ;
  a = 200 ;
  EXPECT_TRUE( isNaN ( a ) ) ;
  a = -5 ;
  EXPECT_TRUE( isNaN ( a ) ) ;
}

TEST( GoogleTest , assignTestIntNaN )
{
  SubIntNaN a ( 9 ) ;
  SubIntNaN b ( 20 ) ;
  a = b ;
  EXPECT_TRUE( a == b ) ;
  EXPECT_TRUE( a == 20 ) ;
}

TEST( GoogleTest , addAssignTestIntNaN )
{
  SubIntNaN a ( 9 ) ;
  SubIntNaN b ( 20 ) ;
  a += b ;
  EXPECT_TRUE( a == 29 ) ;
  a += 10 ;
  EXPECT_TRUE( a == 39 ) ;
  a += -10 ;
  EXPECT_TRUE( a == 29 ) ;
  a += 200 ;
  EXPECT_TRUE( isNaN ( a ) ) ;
}

TEST( GoogleTest , subtractAssignTestIntNaN )
{
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 9 ) ;
  a -= b ;
  EXPECT_TRUE( a == 11 ) ;
  a -= 5 ;
  EXPECT_TRUE( a == 6 ) ;
  a -= -5 ;
  EXPECT_TRUE( a == 11 ) ;
  b -= a ;
  EXPECT_TRUE( isNaN ( b ) ) ;
}

TEST( GoogleTest , multiplyAssignTestIntNaN )
{
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 3 ) ;
  a *= b ;
  EXPECT_TRUE( a == 60 ) ;
  a *= b ;
  EXPECT_TRUE( isNaN ( a ) ) ;
}

TEST( GoogleTest , divideAssignTestIntNaN )
{
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 3 ) ;
  a /= b ;
  EXPECT_TRUE( a == 6 ) ;
}

TEST( GoogleTest , remainderAssignTestIntNaN )
{
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 3 ) ;
  a %= b ;
  EXPECT_TRUE( a == 2 ) ;
}

TEST( GoogleTest , xorAssignTestIntNaN )
{
  SubIntNaN a ( 0x12 ) ;
  SubIntNaN b ( 0x03 ) ;
  a ^= b ;
  EXPECT_TRUE( a == 0x11 ) ;
}

TEST( GoogleTest , andAssignTestIntNaN )
{
  SubIntNaN a ( 0x12 ) ;
  SubIntNaN b ( 0x03 ) ;
  a &= b ;
  EXPECT_TRUE( a == 0x02 ) ;
}

TEST( GoogleTest , orAssignTestIntNaN )
{
  SubIntNaN a ( 0x12 ) ;
  SubIntNaN b ( 0x03 ) ;
  a |= b ;
  EXPECT_TRUE( a == 0x13 ) ;
}

TEST( GoogleTest , shiftLeftAssignTestIntNaN )
{
  SubIntNaN a ( 0x12 ) ;
  a <<= 1 ;
  EXPECT_TRUE( a == 0x24 ) ;
}

TEST( GoogleTest , shiftRightAssignTestIntNaN )
{
  SubIntNaN a ( 0x12 ) ;
  a >>= 1 ;
  EXPECT_TRUE( a == 0x09 ) ;
}

TEST( GoogleTest , addTestIntNaN )
{
  SubIntNaN a ( 9 ) ;
  SubIntNaN b ( 20 ) ;
  a = a + b ;
  EXPECT_TRUE( a == 29 ) ;
  a = a + 10 ;
  EXPECT_TRUE( a == 39 ) ;
  a = a + -10 ;
  EXPECT_TRUE( a == 29 ) ;
  a = 10 + a ;
  EXPECT_TRUE( a == 39 ) ;
  a = -10 + a ;
  EXPECT_TRUE( a == 29 ) ;
}

TEST( GoogleTest , subtractTestIntNaN )
{
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 9 ) ;
  a = a - b ;
  EXPECT_TRUE( a == 11 ) ;
}

TEST( GoogleTest , multiplyTestIntNaN )
{
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 3 ) ;
  a = a * b ;
  EXPECT_TRUE( a == 60 ) ;
}

TEST( GoogleTest , divideTestIntNaN )
{
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 3 ) ;
  a = a / b ;
  EXPECT_TRUE( a == 6 ) ;
}

TEST( GoogleTest , remainderTestIntNaN )
{
  SubIntNaN a ( 20 ) ;
  SubIntNaN b ( 3 ) ;
  a = a % b ;
  EXPECT_TRUE( a == 2 ) ;
}

TEST( GoogleTest , xorTestIntNaN )
{
  SubIntNaN a ( 0x12 ) ;
  SubIntNaN b ( 0x03 ) ;
  a = a ^ b ;
  EXPECT_TRUE( a == 0x11 ) ;
}

TEST( GoogleTest , andTestIntNaN )
{
  SubIntNaN a ( 0x12 ) ;
  SubIntNaN b ( 0x03 ) ;
  a = a & b ;
  EXPECT_TRUE( a == 0x02 ) ;
}

TEST( GoogleTest , orTestIntNaN )
{
  SubIntNaN a ( 0x12 ) ;
  SubIntNaN b ( 0x03 ) ;
  a = a | b ;
  EXPECT_TRUE( a == 0x13 ) ;
}

TEST( GoogleTest , shiftLeftTestIntNaN )
{
  SubIntNaN a ( 0x12 ) ;
  a = a << 1 ;
  EXPECT_TRUE( a == 0x24 ) ;
  a = a << 3 ;
  EXPECT_TRUE( isNaN ( a ) ) ;
}

TEST( GoogleTest , shiftRightTestIntNaN )
{
  SubIntNaN a ( 0x12 ) ;
  a = a >> 1 ;
  EXPECT_TRUE( a == 0x09 ) ;
  a = a >> 5 ;
  EXPECT_TRUE( isNaN ( a ) ) ;
}

TEST( GoogleTest , equalsTestIntNaN )
{
  SubIntNaN a ( 9 ) ;
  SubIntNaN b ( 9 ) ;
  EXPECT_TRUE( a == b ) ;
}

TEST( GoogleTest , notEqualsTestIntNaN )
{
  SubIntNaN a ( 9 ) ;
  SubIntNaN b ( 8 ) ;
  EXPECT_TRUE( a != b ) ;
}

TEST( GoogleTest , lessThanTestIntNaN )
{
  SubIntNaN a ( 8 ) ;
  SubIntNaN b ( 9 ) ;
  EXPECT_TRUE( a < b ) ;
  EXPECT_TRUE( ! ( a >= b ) ) ;
}

TEST( GoogleTest , lessThanEqualToTestIntNaN )
{
  SubIntNaN a ( 8 ) ;
  SubIntNaN b ( 8 ) ;
  EXPECT_TRUE( a <= b ) ;
  EXPECT_TRUE( ! ( a > b ) ) ;
}

TEST( GoogleTest , greaterThanTestIntNaN )
{
  SubIntNaN a ( 8 ) ;
  SubIntNaN b ( 9 ) ;
  EXPECT_TRUE( b > a ) ;
  EXPECT_TRUE( ! ( b <= a ) ) ;
}

TEST( GoogleTest , greaterThanEqualToTestIntNaN )
{
  SubIntNaN a ( 8 ) ;
  SubIntNaN b ( 8 ) ;
  EXPECT_TRUE( a >= b ) ;
  EXPECT_TRUE( ! ( a < b ) ) ;
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

TEST( GoogleTest , createDefaultTestFloat )
{
  SubFloat a ;
  EXPECT_TRUE( a == 1.0 ) ;
}

TEST( GoogleTest , preincrementTestFloat )
{
  SubFloat a ( 9.0 ) ;
  ++a ;
  EXPECT_TRUE( a == 10.0 ) ;
}

TEST( GoogleTest , postincrementTestFloat )
{
  SubFloat a ( 9.0 ) ;
  a++ ;
  EXPECT_TRUE( a == 10.0 ) ;
}

TEST( GoogleTest , predecrementTestFloat )
{
  SubFloat a ( 9.0 ) ;
  --a ;
  EXPECT_TRUE( a == 8.0 ) ;
}

TEST( GoogleTest , postdecrementTestFloat )
{
  SubFloat a ( 9.0 ) ;
  a-- ;
  EXPECT_TRUE( a == 8.0 ) ;
}

TEST( GoogleTest , assignLiteralTestFloat )
{
  SubFloat a ( 9.0 ) ;
  a = 20.0 ;
  EXPECT_TRUE( a == 20.0 ) ;
  EXPECT_THROW( a = 200.0 , subrange::range_error ) ;
  EXPECT_THROW( a = -5.0 , subrange::range_error ) ;
}

TEST( GoogleTest , assignTestFloat )
{
  SubFloat a ( 9.0 ) ;
  SubFloat b ( 20.0 ) ;
  a = b ;
  EXPECT_TRUE( a == b ) ;
  EXPECT_TRUE( a == 20.0 ) ;
}

TEST( GoogleTest , addAssignTestFloat )
{
  SubFloat a ( 9.0 ) ;
  SubFloat b ( 20.0 ) ;
  a += b ;
  EXPECT_TRUE( a == 29.0 ) ;
  a += 10 ;
  EXPECT_TRUE( a == 39.0 ) ;
  a += -10 ;
  EXPECT_TRUE( a == 29.0 ) ;
  EXPECT_THROW( a += 200.0 , subrange::range_error ) ;
}

TEST( GoogleTest , subtractAssignTestFloat )
{
  SubFloat a ( 20.0 ) ;
  SubFloat b ( 9.0 ) ;
  a -= b ;
  EXPECT_TRUE( a == 11.0 ) ;
  a -= 5.0 ;
  EXPECT_TRUE( a == 6.0 ) ;
  a -= -5.0 ;
  EXPECT_TRUE( a == 11.0 ) ;
  EXPECT_THROW( b -= a , subrange::range_error ) ;
}

TEST( GoogleTest , multiplyAssignTestFloat )
{
  SubFloat a ( 20.0 ) ;
  SubFloat b ( 3.0 ) ;
  a *= b ;
  EXPECT_TRUE( a == 60.0 ) ;
  EXPECT_THROW( a *= b , subrange::range_error ) ;
}

TEST( GoogleTest , divideAssignTestFloat )
{
  SubFloat a ( 20.0 ) ;
  SubFloat b ( 4.0 ) ;
  a /= b ;
  EXPECT_TRUE( a == 5.0 ) ;
}

TEST( GoogleTest , addTestFloat )
{
  SubFloat a ( 9.0 ) ;
  SubFloat b ( 20.0 ) ;
  a = a + b ;
  EXPECT_TRUE( a == 29.0 ) ;
  a = a + 10.0 ;
  EXPECT_TRUE( a == 39.0 ) ;
  a = a + -10.0 ;
  EXPECT_TRUE( a == 29.0 ) ;
  a = 10.0 + a ;
  EXPECT_TRUE( a == 39.0 ) ;
  a = -10.0 + a ;
  EXPECT_TRUE( a == 29.0 ) ;
}

TEST( GoogleTest , subtractTestFloat )
{
  SubFloat a ( 20.0 ) ;
  SubFloat b ( 9.0 ) ;
  a = a - b ;
  EXPECT_TRUE( a == 11.0 ) ;
}

TEST( GoogleTest , multiplyTestFloat )
{
  SubFloat a ( 20.0 ) ;
  SubFloat b ( 3.0 ) ;
  a = a * b ;
  EXPECT_TRUE( a == 60.0 ) ;
}

TEST( GoogleTest , divideTestFloat )
{
  SubFloat a ( 20.0 ) ;
  SubFloat b ( 4.0 ) ;
  a = a / b ;
  EXPECT_TRUE( a == 5.0 ) ;
}

TEST( GoogleTest , equalsTestFloat )
{
  SubFloat a ( 9.0 ) ;
  SubFloat b ( 9.0 ) ;
  EXPECT_TRUE( a == b ) ;
}

TEST( GoogleTest , notEqualsTestFloat )
{
  SubFloat a ( 9.0 ) ;
  SubFloat b ( 8.0 ) ;
  EXPECT_TRUE( a != b ) ;
}

TEST( GoogleTest , lessThanTestFloat )
{
  SubFloat a ( 8.0 ) ;
  SubFloat b ( 9.0 ) ;
  EXPECT_TRUE( a < b ) ;
  EXPECT_TRUE( ! ( a >= b ) ) ;
}

TEST( GoogleTest , lessThanEqualToTestFloat )
{
  SubFloat a ( 8.0 ) ;
  SubFloat b ( 8.0 ) ;
  EXPECT_TRUE( a <= b ) ;
  EXPECT_TRUE( ! ( a > b ) ) ;
}

TEST( GoogleTest , greaterThanTestFloat )
{
  SubFloat a ( 8.0 ) ;
  SubFloat b ( 9.0 ) ;
  EXPECT_TRUE( b > a ) ;
  EXPECT_TRUE( ! ( b <= a ) ) ;
}

TEST( GoogleTest , greaterThanEqualToTestFloat )
{
  SubFloat a ( 8.0 ) ;
  SubFloat b ( 8.0 ) ;
  EXPECT_TRUE( a >= b ) ;
  EXPECT_TRUE( ! ( a < b ) ) ;
}

int main ( int argc , char ** argv ) {
  ::testing::InitGoogleTest ( &argc , argv ) ;
  return RUN_ALL_TESTS( ) ;
}
