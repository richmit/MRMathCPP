// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      mjr_math_ivl.cpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Unit tests for mjr::math::ivl.@EOL
 @std       C++20
 @copyright
  @parblock
  Copyright (c) 2024, Mitchell Jay Richling <http://www.mitchr.me/> All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

  1. Redistributions of source code must retain the above copyright notice, this list of conditions, and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions, and the following disclaimer in the documentation
     and/or other materials provided with the distribution.

  3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software
     without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
  DAMAGE.
  @endparblock
*/
/*******************************************************************************************************************************************************.H.E.**/
/** @cond exj */

#include <gtest/gtest.h>

#include "MRMathIVL.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_wrapCC, TYP_Int) {
  EXPECT_EQ(mjr::math::ivl::wrapCC(-44, 10), 0);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-43, 10), 1);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-42, 10), 2);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-41, 10), 3);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-40, 10), 4);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-39, 10), 5);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-38, 10), 6);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-37, 10), 7);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-36, 10), 8);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-35, 10), 9);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-34, 10), 10);

  EXPECT_EQ(mjr::math::ivl::wrapCC(-33, 10), 0);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-32, 10), 1);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-31, 10), 2);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-30, 10), 3);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-29, 10), 4);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-28, 10), 5);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-27, 10), 6);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-26, 10), 7);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-25, 10), 8);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-24, 10), 9);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-23, 10), 10);

  EXPECT_EQ(mjr::math::ivl::wrapCC(-22, 10), 0);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-21, 10), 1);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-20, 10), 2);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-19, 10), 3);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-18, 10), 4);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-17, 10), 5);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-16, 10), 6);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-15, 10), 7);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-14, 10), 8);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-13, 10), 9);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-12, 10), 10);

  EXPECT_EQ(mjr::math::ivl::wrapCC(-11, 10), 0);
  EXPECT_EQ(mjr::math::ivl::wrapCC(-10, 10), 1);
  EXPECT_EQ(mjr::math::ivl::wrapCC( -9, 10), 2);
  EXPECT_EQ(mjr::math::ivl::wrapCC( -8, 10), 3);
  EXPECT_EQ(mjr::math::ivl::wrapCC( -7, 10), 4);
  EXPECT_EQ(mjr::math::ivl::wrapCC( -6, 10), 5);
  EXPECT_EQ(mjr::math::ivl::wrapCC( -5, 10), 6);
  EXPECT_EQ(mjr::math::ivl::wrapCC( -4, 10), 7);
  EXPECT_EQ(mjr::math::ivl::wrapCC( -3, 10), 8);
  EXPECT_EQ(mjr::math::ivl::wrapCC( -2, 10), 9);
  EXPECT_EQ(mjr::math::ivl::wrapCC( -1, 10), 10);

  EXPECT_EQ(mjr::math::ivl::wrapCC(  0, 10), 0);
  EXPECT_EQ(mjr::math::ivl::wrapCC(  1, 10), 1);
  EXPECT_EQ(mjr::math::ivl::wrapCC(  2, 10), 2);
  EXPECT_EQ(mjr::math::ivl::wrapCC(  3, 10), 3);
  EXPECT_EQ(mjr::math::ivl::wrapCC(  4, 10), 4);
  EXPECT_EQ(mjr::math::ivl::wrapCC(  5, 10), 5);
  EXPECT_EQ(mjr::math::ivl::wrapCC(  6, 10), 6);
  EXPECT_EQ(mjr::math::ivl::wrapCC(  7, 10), 7);
  EXPECT_EQ(mjr::math::ivl::wrapCC(  8, 10), 8);
  EXPECT_EQ(mjr::math::ivl::wrapCC(  9, 10), 9);
  EXPECT_EQ(mjr::math::ivl::wrapCC( 10, 10), 10);

  EXPECT_EQ(mjr::math::ivl::wrapCC( 11, 10), 0);
  EXPECT_EQ(mjr::math::ivl::wrapCC( 12, 10), 1);
  EXPECT_EQ(mjr::math::ivl::wrapCC( 13, 10), 2);
  EXPECT_EQ(mjr::math::ivl::wrapCC( 14, 10), 3);
  EXPECT_EQ(mjr::math::ivl::wrapCC( 15, 10), 4);
  EXPECT_EQ(mjr::math::ivl::wrapCC( 16, 10), 5);
  EXPECT_EQ(mjr::math::ivl::wrapCC( 17, 10), 6);
  EXPECT_EQ(mjr::math::ivl::wrapCC( 18, 10), 7);
  EXPECT_EQ(mjr::math::ivl::wrapCC( 19, 10), 8);
  EXPECT_EQ(mjr::math::ivl::wrapCC( 20, 10), 9);

  EXPECT_EQ(mjr::math::ivl::wrapCC( 21, 10), 10);
  EXPECT_EQ(mjr::math::ivl::wrapCC( 22, 10), 0);

  { // Integer Tests
    int k=-44;
    for(int j=0; j<10; j++) {
      for(int i=0; i<=10; i++) {
        EXPECT_EQ(mjr::math::ivl::wrapCC(k, 10), i);
        k++;
      }
    }
  }

  { // Long Tests
    long k=-44;
    for(long j=0; j<10; j++) {
      for(long i=0; i<=10; i++) {
        EXPECT_EQ(mjr::math::ivl::wrapCC(k, 10L), i);
        k++;
      }
    }
  }

  { // Unsigned Long Tests
    unsigned long k=0;
    for(unsigned long j=0; j<10; j++) {
      for(unsigned long i=0; i<=10; i++) {
        EXPECT_EQ(mjr::math::ivl::wrapCC(k, 10UL), i);
        k++;
      }
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_wrapCC, TYP_Float) {
  EXPECT_NEAR(mjr::math::ivl::wrapCC(-20.0, 10.0), 0.0, 1.0e-5); // Ambigious case -- we always return 0
  EXPECT_NEAR(mjr::math::ivl::wrapCC(-19.0, 10.0), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(-18.0, 10.0), 2.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(-17.0, 10.0), 3.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(-16.0, 10.0), 4.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(-15.0, 10.0), 5.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(-14.0, 10.0), 6.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(-13.0, 10.0), 7.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(-12.0, 10.0), 8.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(-11.0, 10.0), 9.0, 1.0e-5);

  EXPECT_NEAR(mjr::math::ivl::wrapCC(-10.0, 10.0), 0.0, 1.0e-5); // Ambigious case -- we always return 0
  EXPECT_NEAR(mjr::math::ivl::wrapCC( -9.0, 10.0), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( -8.0, 10.0), 2.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( -7.0, 10.0), 3.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( -6.0, 10.0), 4.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( -5.0, 10.0), 5.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( -4.0, 10.0), 6.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( -3.0, 10.0), 7.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( -2.0, 10.0), 8.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( -1.0, 10.0), 9.0, 1.0e-5);

  EXPECT_NEAR(mjr::math::ivl::wrapCC(  0.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(  1.0, 10.0), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(  2.0, 10.0), 2.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(  3.0, 10.0), 3.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(  4.0, 10.0), 4.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(  5.0, 10.0), 5.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(  6.0, 10.0), 6.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(  7.0, 10.0), 7.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(  8.0, 10.0), 8.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC(  9.0, 10.0), 9.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 10.0, 10.0), 10.0, 1.0e-5);

  EXPECT_NEAR(mjr::math::ivl::wrapCC( 11.0, 10.0), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 12.0, 10.0), 2.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 13.0, 10.0), 3.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 14.0, 10.0), 4.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 15.0, 10.0), 5.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 16.0, 10.0), 6.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 17.0, 10.0), 7.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 18.0, 10.0), 8.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 19.0, 10.0), 9.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 20.0, 10.0), 0.0, 1.0e-5); // Ambigious case -- we always return 0

  EXPECT_NEAR(mjr::math::ivl::wrapCC( 21.0, 10.0), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 22.0, 10.0), 2.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 23.0, 10.0), 3.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 24.0, 10.0), 4.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 25.0, 10.0), 5.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 26.0, 10.0), 6.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 27.0, 10.0), 7.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 28.0, 10.0), 8.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 29.0, 10.0), 9.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCC( 30.0, 10.0), 0.0, 1.0e-5); // Ambigious case -- we always return 0

  //  MJR COVERAGE NOTE mjr_math_ivl.cpp: Add coverage for non-integer reals.
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_wrapCO, TYP_Int) {

  EXPECT_EQ(mjr::math::ivl::wrapCO(-50, 10), 0);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-49, 10), 1);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-48, 10), 2);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-47, 10), 3);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-46, 10), 4);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-45, 10), 5);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-44, 10), 6);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-43, 10), 7);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-42, 10), 8);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-41, 10), 9);

  EXPECT_EQ(mjr::math::ivl::wrapCO(-40, 10), 0);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-39, 10), 1);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-38, 10), 2);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-37, 10), 3);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-36, 10), 4);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-35, 10), 5);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-34, 10), 6);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-33, 10), 7);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-32, 10), 8);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-31, 10), 9);

  EXPECT_EQ(mjr::math::ivl::wrapCO(-30, 10), 0);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-29, 10), 1);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-28, 10), 2);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-27, 10), 3);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-26, 10), 4);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-25, 10), 5);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-24, 10), 6);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-23, 10), 7);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-22, 10), 8);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-21, 10), 9);

  EXPECT_EQ(mjr::math::ivl::wrapCO(-20, 10), 0);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-19, 10), 1);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-18, 10), 2);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-17, 10), 3);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-16, 10), 4);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-15, 10), 5);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-14, 10), 6);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-13, 10), 7);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-12, 10), 8);
  EXPECT_EQ(mjr::math::ivl::wrapCO(-11, 10), 9);

  EXPECT_EQ(mjr::math::ivl::wrapCO(-10, 10), 0);
  EXPECT_EQ(mjr::math::ivl::wrapCO( -9, 10), 1);
  EXPECT_EQ(mjr::math::ivl::wrapCO( -8, 10), 2);
  EXPECT_EQ(mjr::math::ivl::wrapCO( -7, 10), 3);
  EXPECT_EQ(mjr::math::ivl::wrapCO( -6, 10), 4);
  EXPECT_EQ(mjr::math::ivl::wrapCO( -5, 10), 5);
  EXPECT_EQ(mjr::math::ivl::wrapCO( -4, 10), 6);
  EXPECT_EQ(mjr::math::ivl::wrapCO( -3, 10), 7);
  EXPECT_EQ(mjr::math::ivl::wrapCO( -2, 10), 8);
  EXPECT_EQ(mjr::math::ivl::wrapCO( -1, 10), 9);

  EXPECT_EQ(mjr::math::ivl::wrapCO(  0, 10), 0);
  EXPECT_EQ(mjr::math::ivl::wrapCO(  1, 10), 1);
  EXPECT_EQ(mjr::math::ivl::wrapCO(  2, 10), 2);
  EXPECT_EQ(mjr::math::ivl::wrapCO(  3, 10), 3);
  EXPECT_EQ(mjr::math::ivl::wrapCO(  4, 10), 4);
  EXPECT_EQ(mjr::math::ivl::wrapCO(  5, 10), 5);
  EXPECT_EQ(mjr::math::ivl::wrapCO(  6, 10), 6);
  EXPECT_EQ(mjr::math::ivl::wrapCO(  7, 10), 7);
  EXPECT_EQ(mjr::math::ivl::wrapCO(  8, 10), 8);
  EXPECT_EQ(mjr::math::ivl::wrapCO(  9, 10), 9);

  EXPECT_EQ(mjr::math::ivl::wrapCO( 10, 10), 0);
  EXPECT_EQ(mjr::math::ivl::wrapCO( 11, 10), 1);
  EXPECT_EQ(mjr::math::ivl::wrapCO( 12, 10), 2);
  EXPECT_EQ(mjr::math::ivl::wrapCO( 13, 10), 3);
  EXPECT_EQ(mjr::math::ivl::wrapCO( 14, 10), 4);
  EXPECT_EQ(mjr::math::ivl::wrapCO( 15, 10), 5);
  EXPECT_EQ(mjr::math::ivl::wrapCO( 16, 10), 6);
  EXPECT_EQ(mjr::math::ivl::wrapCO( 17, 10), 7);
  EXPECT_EQ(mjr::math::ivl::wrapCO( 18, 10), 8);
  EXPECT_EQ(mjr::math::ivl::wrapCO( 19, 10), 9);

  EXPECT_EQ(mjr::math::ivl::wrapCO( 20, 10), 0);
  EXPECT_EQ(mjr::math::ivl::wrapCO( 21, 10), 1);
  EXPECT_EQ(mjr::math::ivl::wrapCO( 22, 10), 2);

  { // Integer Tests
    int k=-50;
    for(int j=0; j<10; j++) {
      for(int i=0; i<10; i++) {
        EXPECT_EQ(mjr::math::ivl::wrapCO(k, 10), i);
        k++;
      }
    }
  }

  { // Long Tests
    long k=-50;
    for(long j=0; j<10; j++) {
      for(long i=0; i<10; i++) {
        EXPECT_EQ(mjr::math::ivl::wrapCO(k, 10L), i);
        k++;
      }
    }
  }

  { // Unsigned Long Tests
    unsigned long k=0;
    for(unsigned long j=0; j<10; j++) {
      for(unsigned long i=0; i<10; i++) {
        EXPECT_EQ(mjr::math::ivl::wrapCO(k, 10UL), i);
        k++;
      }
    }
  }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_wrapCO_and_wrapCC, TYP_Int) {
  for(int j=2; j<100; j++) 
    for(int i=-1000; i<1000; i++) 
      EXPECT_EQ(mjr::math::ivl::wrapCO(i, j), mjr::math::ivl::wrapCC(i, j-1));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_wrapCO, TYP_Float) {

  EXPECT_NEAR(mjr::math::ivl::wrapCO(-20.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(-19.0, 10.0), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(-18.0, 10.0), 2.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(-17.0, 10.0), 3.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(-16.0, 10.0), 4.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(-15.0, 10.0), 5.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(-14.0, 10.0), 6.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(-13.0, 10.0), 7.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(-12.0, 10.0), 8.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(-11.0, 10.0), 9.0, 1.0e-5);

  EXPECT_NEAR(mjr::math::ivl::wrapCO(-10.0, 10.0), 0.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::ivl::wrapCO( -9.0, 10.0), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( -8.0, 10.0), 2.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( -7.0, 10.0), 3.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( -6.0, 10.0), 4.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( -5.0, 10.0), 5.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( -4.0, 10.0), 6.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( -3.0, 10.0), 7.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( -2.0, 10.0), 8.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( -1.0, 10.0), 9.0, 1.0e-5);

  EXPECT_NEAR(mjr::math::ivl::wrapCO(  0.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(  1.0, 10.0), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(  2.0, 10.0), 2.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(  3.0, 10.0), 3.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(  4.0, 10.0), 4.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(  5.0, 10.0), 5.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(  6.0, 10.0), 6.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(  7.0, 10.0), 7.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(  8.0, 10.0), 8.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO(  9.0, 10.0), 9.0, 1.0e-5);

  EXPECT_NEAR(mjr::math::ivl::wrapCO( 10.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 11.0, 10.0), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 12.0, 10.0), 2.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 13.0, 10.0), 3.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 14.0, 10.0), 4.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 15.0, 10.0), 5.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 16.0, 10.0), 6.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 17.0, 10.0), 7.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 18.0, 10.0), 8.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 19.0, 10.0), 9.0, 1.0e-5);

  EXPECT_NEAR(mjr::math::ivl::wrapCO( 20.0, 10.0), 0.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 21.0, 10.0), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 22.0, 10.0), 2.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 23.0, 10.0), 3.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 24.0, 10.0), 4.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 25.0, 10.0), 5.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 26.0, 10.0), 6.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 27.0, 10.0), 7.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 28.0, 10.0), 8.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 29.0, 10.0), 9.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::wrapCO( 30.0, 10.0), 0.0, 1.0e-5); 

  { // Non-integer doubles
    double k=-40.0;
    for(double j=0; j<10; j++) {
      for(double i=0; i<10; i++) {
        for(double s=0; s<0.9; s+=0.1) {
          EXPECT_NEAR(mjr::math::ivl::wrapCO(k+s, 10.0), i+s, 1.0e-5);
        }
        k++;
      }
    }
  }

  { // SP floats
    float k=-40.0;
    for(float j=0; j<10; j++) {
      for(float i=0; i<10; i++) {
        EXPECT_NEAR(mjr::math::ivl::wrapCO(k, 10.0f), i, 1.0e-5);
        k++;
      }
    }
  }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_clamp, TYP_Int) {
  EXPECT_EQ(mjr::math::ivl::clamp(-13, 10), 0);
  EXPECT_EQ(mjr::math::ivl::clamp(-12, 10), 0);

  EXPECT_EQ(mjr::math::ivl::clamp(-11, 10), 0);
  EXPECT_EQ(mjr::math::ivl::clamp(-10, 10), 0);
  EXPECT_EQ(mjr::math::ivl::clamp( -9, 10), 0);
  EXPECT_EQ(mjr::math::ivl::clamp( -8, 10), 0);
  EXPECT_EQ(mjr::math::ivl::clamp( -7, 10), 0);
  EXPECT_EQ(mjr::math::ivl::clamp( -6, 10), 0);
  EXPECT_EQ(mjr::math::ivl::clamp( -5, 10), 0);
  EXPECT_EQ(mjr::math::ivl::clamp( -4, 10), 0);
  EXPECT_EQ(mjr::math::ivl::clamp( -3, 10), 0);
  EXPECT_EQ(mjr::math::ivl::clamp( -2, 10), 0);
  EXPECT_EQ(mjr::math::ivl::clamp( -1, 10), 0);

  EXPECT_EQ(mjr::math::ivl::clamp(  0, 10), 0);
  EXPECT_EQ(mjr::math::ivl::clamp(  1, 10), 1);
  EXPECT_EQ(mjr::math::ivl::clamp(  2, 10), 2);
  EXPECT_EQ(mjr::math::ivl::clamp(  3, 10), 3);
  EXPECT_EQ(mjr::math::ivl::clamp(  4, 10), 4);
  EXPECT_EQ(mjr::math::ivl::clamp(  5, 10), 5);
  EXPECT_EQ(mjr::math::ivl::clamp(  6, 10), 6);
  EXPECT_EQ(mjr::math::ivl::clamp(  7, 10), 7);
  EXPECT_EQ(mjr::math::ivl::clamp(  8, 10), 8);
  EXPECT_EQ(mjr::math::ivl::clamp(  9, 10), 9);
  EXPECT_EQ(mjr::math::ivl::clamp( 10, 10), 10);

  EXPECT_EQ(mjr::math::ivl::clamp( 11, 10), 10);
  EXPECT_EQ(mjr::math::ivl::clamp( 12, 10), 10);
  EXPECT_EQ(mjr::math::ivl::clamp( 13, 10), 10);
  EXPECT_EQ(mjr::math::ivl::clamp( 14, 10), 10);
  EXPECT_EQ(mjr::math::ivl::clamp( 15, 10), 10);
  EXPECT_EQ(mjr::math::ivl::clamp( 16, 10), 10);
  EXPECT_EQ(mjr::math::ivl::clamp( 17, 10), 10);
  EXPECT_EQ(mjr::math::ivl::clamp( 18, 10), 10);
  EXPECT_EQ(mjr::math::ivl::clamp( 19, 10), 10);
  EXPECT_EQ(mjr::math::ivl::clamp( 20, 10), 10);

  EXPECT_EQ(mjr::math::ivl::clamp( 21, 10), 10);
  EXPECT_EQ(mjr::math::ivl::clamp( 22, 10), 10);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_clamp, TYP_Long) {
  EXPECT_EQ(mjr::math::ivl::clamp(-13L, 10L), 0L);
  EXPECT_EQ(mjr::math::ivl::clamp(-12L, 10L), 0L);

  EXPECT_EQ(mjr::math::ivl::clamp(-11L, 10L), 0L);
  EXPECT_EQ(mjr::math::ivl::clamp(-10L, 10L), 0L);
  EXPECT_EQ(mjr::math::ivl::clamp( -9L, 10L), 0L);
  EXPECT_EQ(mjr::math::ivl::clamp( -8L, 10L), 0L);
  EXPECT_EQ(mjr::math::ivl::clamp( -7L, 10L), 0L);
  EXPECT_EQ(mjr::math::ivl::clamp( -6L, 10L), 0L);
  EXPECT_EQ(mjr::math::ivl::clamp( -5L, 10L), 0L);
  EXPECT_EQ(mjr::math::ivl::clamp( -4L, 10L), 0L);
  EXPECT_EQ(mjr::math::ivl::clamp( -3L, 10L), 0L);
  EXPECT_EQ(mjr::math::ivl::clamp( -2L, 10L), 0L);
  EXPECT_EQ(mjr::math::ivl::clamp( -1L, 10L), 0L);

  EXPECT_EQ(mjr::math::ivl::clamp(  0L, 10L), 0L);
  EXPECT_EQ(mjr::math::ivl::clamp(  1L, 10L), 1L);
  EXPECT_EQ(mjr::math::ivl::clamp(  2L, 10L), 2L);
  EXPECT_EQ(mjr::math::ivl::clamp(  3L, 10L), 3L);
  EXPECT_EQ(mjr::math::ivl::clamp(  4L, 10L), 4L);
  EXPECT_EQ(mjr::math::ivl::clamp(  5L, 10L), 5L);
  EXPECT_EQ(mjr::math::ivl::clamp(  6L, 10L), 6L);
  EXPECT_EQ(mjr::math::ivl::clamp(  7L, 10L), 7L);
  EXPECT_EQ(mjr::math::ivl::clamp(  8L, 10L), 8L);
  EXPECT_EQ(mjr::math::ivl::clamp(  9L, 10L), 9L);
  EXPECT_EQ(mjr::math::ivl::clamp( 10L, 10L), 10L);

  EXPECT_EQ(mjr::math::ivl::clamp( 11L, 10L), 10L);
  EXPECT_EQ(mjr::math::ivl::clamp( 12L, 10L), 10L);
  EXPECT_EQ(mjr::math::ivl::clamp( 13L, 10L), 10L);
  EXPECT_EQ(mjr::math::ivl::clamp( 14L, 10L), 10L);
  EXPECT_EQ(mjr::math::ivl::clamp( 15L, 10L), 10L);
  EXPECT_EQ(mjr::math::ivl::clamp( 16L, 10L), 10L);
  EXPECT_EQ(mjr::math::ivl::clamp( 17L, 10L), 10L);
  EXPECT_EQ(mjr::math::ivl::clamp( 18L, 10L), 10L);
  EXPECT_EQ(mjr::math::ivl::clamp( 19L, 10L), 10L);
  EXPECT_EQ(mjr::math::ivl::clamp( 20L, 10L), 10L);

  EXPECT_EQ(mjr::math::ivl::clamp( 21L, 10L), 10L);
  EXPECT_EQ(mjr::math::ivl::clamp( 22L, 10L), 10L);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_clamp, TYP_Float) {
  EXPECT_NEAR(mjr::math::ivl::clamp(-20.0, 10.0), 0.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::ivl::clamp(-19.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(-18.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(-17.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(-16.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(-15.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(-14.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(-13.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(-12.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(-11.0, 10.0), 0.0, 1.0e-5);

  EXPECT_NEAR(mjr::math::ivl::clamp(-10.0, 10.0), 0.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::ivl::clamp( -9.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( -8.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( -7.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( -6.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( -5.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( -4.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( -3.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( -2.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( -1.0, 10.0), 0.0, 1.0e-5);

  EXPECT_NEAR(mjr::math::ivl::clamp(  0.0, 10.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(  1.0, 10.0), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(  2.0, 10.0), 2.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(  3.0, 10.0), 3.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(  4.0, 10.0), 4.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(  5.0, 10.0), 5.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(  6.0, 10.0), 6.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(  7.0, 10.0), 7.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(  8.0, 10.0), 8.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp(  9.0, 10.0), 9.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 10.0, 10.0), 10.0, 1.0e-5);

  EXPECT_NEAR(mjr::math::ivl::clamp( 11.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 12.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 13.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 14.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 15.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 16.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 17.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 18.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 19.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 20.0, 10.0), 10.0, 1.0e-5); 

  EXPECT_NEAR(mjr::math::ivl::clamp( 21.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 22.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 23.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 24.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 25.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 26.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 27.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 28.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 29.0, 10.0), 10.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::clamp( 30.0, 10.0), 10.0, 1.0e-5);

  { // non-integer doubles
    double under=-0.1;
    double over= 10.1;
    double inr=0.0;
    for(int i=0; i<100; i++) {
      EXPECT_NEAR(mjr::math::ivl::clamp( under, 10.0),  0.0, 1.0e-5);
      EXPECT_NEAR(mjr::math::ivl::clamp( over,  10.0), 10.0, 1.0e-5);
      EXPECT_NEAR(mjr::math::ivl::clamp( inr,   10.0),  inr, 1.0e-5);
      under-=.3;
      over+=.3;
      inr+=0.01;
    }
  }

  { // non-integer SP floats
    float under=-0.1f;
    float over= 10.1f;
    float inr=0.0f;
    for(int i=0; i<100; i++) {
      EXPECT_NEAR(mjr::math::ivl::clamp( under, 10.0f),  0.0f, 1.0e-5);
      EXPECT_NEAR(mjr::math::ivl::clamp( over,  10.0f), 10.0f, 1.0e-5);
      EXPECT_NEAR(mjr::math::ivl::clamp( inr,   10.0f),   inr, 1.0e-5);
      under-=.3f;
      over+=.3f;
      inr+=0.01f;
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_unit_clamp, Comprehensive) {
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-2.0), 0.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-1.9), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-1.8), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-1.7), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-1.6), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-1.5), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-1.4), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-1.3), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-1.2), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-1.1), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-1.0), 0.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-0.9), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-0.8), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-0.7), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-0.6), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-0.5), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-0.4), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-0.3), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-0.2), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp(-0.1), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 0.0), 0.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 0.1), 0.1, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 0.2), 0.2, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 0.3), 0.3, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 0.4), 0.4, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 0.5), 0.5, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 0.6), 0.6, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 0.7), 0.7, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 0.8), 0.8, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 0.9), 0.9, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 1.0), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 1.1), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 1.2), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 1.3), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 1.4), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 1.5), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 1.6), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 1.7), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 1.8), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 1.9), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 2.0), 1.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 2.1), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 2.2), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 2.3), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 2.4), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 2.5), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 2.6), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 2.7), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 2.8), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 2.9), 1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::unit_clamp( 3.0), 1.0, 1.0e-5);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_right_ray_to_unit, TYP_Float) {
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -2.0), -2.00000000000000000, 1.0e-5); 
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1.8), -1.80000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1.7), -1.70000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1.5), -1.50000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1.4), -1.40000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1.2), -1.20000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1.1), -1.10000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1.0), -1.00000000000000000, 1.0e-5); 
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -0.9), -0.90000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -0.7), -0.70000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -0.6), -0.60000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -0.4), -0.40000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -0.3), -0.30000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -0.1), -0.10000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  0.0), 1.00000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  0.5), 0.66666666666666663, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  1.0), 0.50000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  1.0), 0.50000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  2.0), 0.33333333333333331, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  4.0), 0.20000000000000001, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  6.0), 0.14285714285714285, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  8.0), 0.11111111111111111, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  9.0), 0.10000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( 10.0), 0.09090909090909091, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(100.0), 0.00990099009900990, 1.0e-5);

  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -2.0f), -2.00000000000000000f, 1.0e-5); 
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1.8f), -1.80000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1.7f), -1.70000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1.5f), -1.50000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1.4f), -1.40000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1.2f), -1.20000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1.1f), -1.10000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1.0f), -1.00000000000000000f, 1.0e-5); 
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -0.9f), -0.90000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -0.7f), -0.70000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -0.6f), -0.60000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -0.4f), -0.40000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -0.3f), -0.30000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -0.1f), -0.10000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  0.0f), 1.00000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  0.5f), 0.66666666666666663f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  1.0f), 0.50000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  1.0f), 0.50000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  2.0f), 0.33333333333333331f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  4.0f), 0.20000000000000001f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  6.0f), 0.14285714285714285f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  8.0f), 0.11111111111111111f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  9.0f), 0.10000000000000000f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( 10.0f), 0.09090909090909091f, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(100.0f), 0.00990099009900990f, 1.0e-5);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_right_ray_to_unit, TYP_Int) {
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -2), -2.00000000000000000, 1.0e-5); 
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1), -1.00000000000000000, 1.0e-5); 
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  0), 1.00000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  1), 0.50000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  2), 0.33333333333333331, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  4), 0.20000000000000001, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  6), 0.14285714285714285, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  8), 0.11111111111111111, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  9), 0.10000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( 10), 0.09090909090909091, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(100), 0.00990099009900990, 1.0e-5);

  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -2L), -2.00000000000000000, 1.0e-5); 
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( -1L), -1.00000000000000000, 1.0e-5); 
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  0L), 1.00000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  1L), 0.50000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  2L), 0.33333333333333331, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  4L), 0.20000000000000001, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  6L), 0.14285714285714285, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  8L), 0.11111111111111111, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  9L), 0.10000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( 10L), 0.09090909090909091, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(100L), 0.00990099009900990, 1.0e-5);

  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  0UL), 1.00000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  1UL), 0.50000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  2UL), 0.33333333333333331, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  4UL), 0.20000000000000001, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  6UL), 0.14285714285714285, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  8UL), 0.11111111111111111, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(  9UL), 0.10000000000000000, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit( 10UL), 0.09090909090909091, 1.0e-5);
  EXPECT_NEAR(mjr::math::ivl::right_ray_to_unit(100UL), 0.00990099009900990, 1.0e-5);
}
/** @endcond */
