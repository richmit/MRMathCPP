// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      mjr_math_odr.cpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Unit tests for mjr::math::odr.@EOL
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

#include "MRMathODR.hpp"
#include "MRMathFC.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_abs_min2, TYP_Double) {
  EXPECT_EQ(mjr::math::odr::abs_min2( 1.0,  2.0), 1.0);
  EXPECT_EQ(mjr::math::odr::abs_min2( 3.0,  2.0), 2.0);

  EXPECT_EQ(mjr::math::odr::abs_min2(-1.0, -2.0), -1.0);
  EXPECT_EQ(mjr::math::odr::abs_min2(-3.0, -2.0), -2.0);

  EXPECT_EQ(mjr::math::odr::abs_min2( 1.0, -2.0), 1.0);
  EXPECT_EQ(mjr::math::odr::abs_min2(-3.0,  2.0), 2.0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_abs_min2, TYP_Float) {
  EXPECT_EQ(mjr::math::odr::abs_min2( 1.0f, 2.0f), 1.0f);
  EXPECT_EQ(mjr::math::odr::abs_min2( 3.0f, 2.0f), 2.0f);

  EXPECT_EQ(mjr::math::odr::abs_min2( 1.0f,-2.0f), 1.0f);
  EXPECT_EQ(mjr::math::odr::abs_min2(-3.0f, 2.0f), 2.0f);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_abs_min2, TYP_Int) {
  EXPECT_EQ(mjr::math::odr::abs_min2( 1,   2),   1);
  EXPECT_EQ(mjr::math::odr::abs_min2( 1,  -2),   1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_abs_min2, TYP_Long) {
  EXPECT_EQ(mjr::math::odr::abs_min2( 1L,  2L),  1L);
  EXPECT_EQ(mjr::math::odr::abs_min2( 1L, -2L),  1L);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_abs_min2, TYP_CplxDouble) {
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::odr::abs_min2( std::complex<double>(3.0, 4.0), std::complex<double>( 5.0,  6.0)), std::complex<double>(3.0, 4.0), 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::odr::abs_min2( std::complex<double>(3.0, 4.0), std::complex<double>(-5.0, -6.0)), std::complex<double>(3.0, 4.0), 1.0e-5));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_abs_max2, TYP_Double) {
  EXPECT_EQ(mjr::math::odr::abs_max2( 1.0,  2.0), 2.0);
  EXPECT_EQ(mjr::math::odr::abs_max2( 3.0,  2.0), 3.0);

  EXPECT_EQ(mjr::math::odr::abs_max2( 1.0, -2.0), -2.0);
  EXPECT_EQ(mjr::math::odr::abs_max2(-3.0,  2.0), -3.0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_abs_max2, TYP_Float) {
  EXPECT_EQ(mjr::math::odr::abs_max2( 1.0f, 2.0f), 2.0f);
  EXPECT_EQ(mjr::math::odr::abs_max2( 3.0f, 2.0f), 3.0f);

  EXPECT_EQ(mjr::math::odr::abs_max2( 1.0f,-2.0f), -2.0f);
  EXPECT_EQ(mjr::math::odr::abs_max2(-3.0f, 2.0f), -3.0f);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_abs_max2, TYP_Int) {
  EXPECT_EQ(mjr::math::odr::abs_max2( 1,   2),   2);
  EXPECT_EQ(mjr::math::odr::abs_max2( 1,  -2),   -2);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_abs_max2, TYP_Long) {
  EXPECT_EQ(mjr::math::odr::abs_max2( 1L,  2L),  2L);
  EXPECT_EQ(mjr::math::odr::abs_max2( 1L, -2L),  -2L);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_abs_max2, TYP_CplxDouble) {
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::odr::abs_max2( std::complex<double>(3.0, 4.0), std::complex<double>( 5.0,  6.0)), std::complex<double>( 5.0,  6.0), 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::odr::abs_max2( std::complex<double>(3.0, 4.0), std::complex<double>(-5.0, -6.0)), std::complex<double>(-5.0, -6.0), 1.0e-5));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_sort2, TYP_Double) {
  double vaD1, vaD2, vbD1, vbD2;

  vaD1 = vbD1 = 1.0;
  vaD2 = vbD2 = 2.0;
  mjr::math::odr::sort2(vaD1, vaD2); EXPECT_NEAR(vaD1, vbD1, 1.0e-5); EXPECT_NEAR(vaD2, vbD2, 1.0e-5); 

  vaD1 = vbD1 = 2.0;
  vaD2 = vbD2 = 1.0;
  mjr::math::odr::sort2(vaD1, vaD2); EXPECT_NEAR(vaD2, vbD1, 1.0e-5); EXPECT_NEAR(vaD1, vbD2, 1.0e-5); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_sort2, TYP_Int) {
  int    vaI1, vaI2, vbI1, vbI2;

  vaI1 = vbI1 = 1;
  vaI2 = vbI2 = 2;
  mjr::math::odr::sort2(vaI1, vaI2); EXPECT_EQ(vaI1, vbI1); EXPECT_EQ(vaI2, vbI2); 

  vaI1 = vbI1 = 2;
  vaI2 = vbI2 = 1;
  mjr::math::odr::sort2(vaI1, vaI2); EXPECT_EQ(vaI2, vbI1); EXPECT_EQ(vaI1, vbI2); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_abs_sort2, TYP_CplxDouble) {
  std::complex<double> vaCD1, vaCD2, vbCD1, vbCD2;

  vaCD1 = vbCD1 = std::complex<double>(1.0, 2.0);
  vaCD2 = vbCD2 = std::complex<double>(2.0, 3.0);
  mjr::math::odr::abs_sort2(vaCD1, vaCD2); EXPECT_TRUE(mjr::math::fc::near(vaCD1, vbCD1, 1.0e-5)); EXPECT_TRUE(mjr::math::fc::near(vaCD2, vbCD2, 1.0e-5)); 

  vaCD1 = vbCD1 = std::complex<double>(2.0, 3.0);
  vaCD2 = vbCD2 = std::complex<double>(1.0, 2.0);
  mjr::math::odr::abs_sort2(vaCD1, vaCD2); EXPECT_TRUE(mjr::math::fc::near(vaCD2, vbCD1, 1.0e-5)); EXPECT_TRUE(mjr::math::fc::near(vaCD1, vbCD2, 1.0e-5)); 

  vaCD1 = vbCD1 = std::complex<double>( 1.0,  2.0);
  vaCD2 = vbCD2 = std::complex<double>(-2.0, -3.0);
  mjr::math::odr::abs_sort2(vaCD1, vaCD2); EXPECT_TRUE(mjr::math::fc::near(vaCD1, vbCD1, 1.0e-5)); EXPECT_TRUE(mjr::math::fc::near(vaCD2, vbCD2, 1.0e-5)); 

  vaCD1 = vbCD1 = std::complex<double>(-2.0, -3.0);
  vaCD2 = vbCD2 = std::complex<double>( 1.0,  2.0);
  mjr::math::odr::abs_sort2(vaCD1, vaCD2); EXPECT_TRUE(mjr::math::fc::near(vaCD2, vbCD1, 1.0e-5)); EXPECT_TRUE(mjr::math::fc::near(vaCD1, vbCD2, 1.0e-5)); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_abs_sort2, TYP_Double) {
  double vaD1, vaD2, vbD1, vbD2;

  vaD1 = vbD1 = 1.0;
  vaD2 = vbD2 = 2.0;
  mjr::math::odr::abs_sort2(vaD1, vaD2); EXPECT_NEAR(vaD1, vbD1, 1.0e-5); EXPECT_NEAR(vaD2, vbD2, 1.0e-5); 

  vaD1 = vbD1 = 2.0;
  vaD2 = vbD2 = 1.0;
  mjr::math::odr::abs_sort2(vaD1, vaD2); EXPECT_NEAR(vaD2, vbD1, 1.0e-5); EXPECT_NEAR(vaD1, vbD2, 1.0e-5); 

  vaD1 = vbD1 =  1.0;
  vaD2 = vbD2 = -2.0;
  mjr::math::odr::abs_sort2(vaD1, vaD2); EXPECT_NEAR(vaD1, vbD1, 1.0e-5); EXPECT_NEAR(vaD2, vbD2, 1.0e-5); 

  vaD1 = vbD1 = -2.0;
  vaD2 = vbD2 =  1.0;
  mjr::math::odr::abs_sort2(vaD1, vaD2); EXPECT_NEAR(vaD2, vbD1, 1.0e-5); EXPECT_NEAR(vaD1, vbD2, 1.0e-5); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_abs_sort2, TYP_Int) {
  int    vaI1, vaI2, vbI1, vbI2;

  vaI1 = vbI1 = 1;
  vaI2 = vbI2 = 2;
  mjr::math::odr::abs_sort2(vaI1, vaI2); EXPECT_EQ(vaI1, vbI1); EXPECT_EQ(vaI2, vbI2); 

  vaI1 = vbI1 = 2;
  vaI2 = vbI2 = 1;
  mjr::math::odr::abs_sort2(vaI1, vaI2); EXPECT_EQ(vaI2, vbI1); EXPECT_EQ(vaI1, vbI2); 

  vaI1 = vbI1 =  1;
  vaI2 = vbI2 = -2;
  mjr::math::odr::abs_sort2(vaI1, vaI2); EXPECT_EQ(vaI1, vbI1); EXPECT_EQ(vaI2, vbI2); 

  vaI1 = vbI1 = -2;
  vaI2 = vbI2 =  1;
  mjr::math::odr::abs_sort2(vaI1, vaI2); EXPECT_EQ(vaI2, vbI1); EXPECT_EQ(vaI1, vbI2); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_min3, Comprehensive) {
  EXPECT_EQ(mjr::math::odr::min3( 1.0,  2.0,  3.0), 1.0);
  EXPECT_EQ(mjr::math::odr::min3( 3.0,  2.0,  1.0), 1.0);

  EXPECT_EQ(mjr::math::odr::min3( 1.0f, 2.0f, 3.0f), 1.0f);
  EXPECT_EQ(mjr::math::odr::min3( 3.0f, 2.0f, 1.0f), 1.0f);

  EXPECT_EQ(mjr::math::odr::min3( 1,   2,   3),   1);
  EXPECT_EQ(mjr::math::odr::min3( 1L,  2L,  3L),  1L);
  EXPECT_EQ(mjr::math::odr::min3( 1UL, 2UL, 3UL), 1UL);

  EXPECT_EQ(mjr::math::odr::min3( 1, 2, 3), 1);
  EXPECT_EQ(mjr::math::odr::min3( 1, 3, 2), 1);
  EXPECT_EQ(mjr::math::odr::min3( 2, 1, 3), 1);
  EXPECT_EQ(mjr::math::odr::min3( 2, 3, 1), 1);
  EXPECT_EQ(mjr::math::odr::min3( 3, 1, 2), 1);
  EXPECT_EQ(mjr::math::odr::min3( 3, 2, 1), 1);

  EXPECT_EQ(mjr::math::odr::min3( 1, 1, 1), 1);
  EXPECT_EQ(mjr::math::odr::min3( 3, 3, 3), 3);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_max3, Comprehensive) {
  EXPECT_EQ(mjr::math::odr::max3( 1.0,  2.0,  3.0), 3.0);
  EXPECT_EQ(mjr::math::odr::max3( 3.0,  2.0,  1.0), 3.0);

  EXPECT_EQ(mjr::math::odr::max3( 1.0f, 2.0f, 3.0f), 3.0f);
  EXPECT_EQ(mjr::math::odr::max3( 3.0f, 2.0f, 1.0f), 3.0f);

  EXPECT_EQ(mjr::math::odr::max3( 1,   2,   3),   3);
  EXPECT_EQ(mjr::math::odr::max3( 1L,  2L,  3L),  3L);
  EXPECT_EQ(mjr::math::odr::max3( 1UL, 2UL, 3UL), 3UL);

  EXPECT_EQ(mjr::math::odr::max3( 1, 2, 3), 3);
  EXPECT_EQ(mjr::math::odr::max3( 1, 3, 2), 3);
  EXPECT_EQ(mjr::math::odr::max3( 2, 1, 3), 3);
  EXPECT_EQ(mjr::math::odr::max3( 2, 3, 1), 3);
  EXPECT_EQ(mjr::math::odr::max3( 3, 1, 2), 3);
  EXPECT_EQ(mjr::math::odr::max3( 3, 2, 1), 3);

  EXPECT_EQ(mjr::math::odr::max3( 1, 1, 1), 1);
  EXPECT_EQ(mjr::math::odr::max3( 3, 3, 3), 3);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_min4, Comprehensive) {
  EXPECT_EQ(mjr::math::odr::min4( 1.0,  2.0,  3.0,  4.0), 1.0);
  EXPECT_EQ(mjr::math::odr::min4( 4.0,  3.0,  2.0,  1.0), 1.0);

  EXPECT_EQ(mjr::math::odr::min4( 1.0f, 2.0f, 3.0f, 4.0f), 1.0f);
  EXPECT_EQ(mjr::math::odr::min4( 4.0f, 3.0f, 2.0f, 1.0f), 1.0f);

  EXPECT_EQ(mjr::math::odr::min4( 1,   2,   3,   4),   1);
  EXPECT_EQ(mjr::math::odr::min4( 1L,  2L,  3L,  4L),  1L);
  EXPECT_EQ(mjr::math::odr::min4( 1UL, 2UL, 3UL, 4UL), 1UL);

  EXPECT_EQ(mjr::math::odr::min4( 1, 2, 3, 4), 1);
  EXPECT_EQ(mjr::math::odr::min4( 1, 3, 2, 4), 1);
  EXPECT_EQ(mjr::math::odr::min4( 2, 1, 3, 4), 1);
  EXPECT_EQ(mjr::math::odr::min4( 2, 3, 1, 4), 1);
  EXPECT_EQ(mjr::math::odr::min4( 3, 1, 2, 4), 1);
  EXPECT_EQ(mjr::math::odr::min4( 3, 2, 1, 4), 1);
  EXPECT_EQ(mjr::math::odr::min4( 1, 2, 4, 3), 1);
  EXPECT_EQ(mjr::math::odr::min4( 1, 3, 4, 2), 1);
  EXPECT_EQ(mjr::math::odr::min4( 2, 1, 4, 3), 1);
  EXPECT_EQ(mjr::math::odr::min4( 2, 3, 4, 1), 1);
  EXPECT_EQ(mjr::math::odr::min4( 3, 1, 4, 2), 1);
  EXPECT_EQ(mjr::math::odr::min4( 3, 2, 4, 1), 1);
  EXPECT_EQ(mjr::math::odr::min4( 1, 4, 2, 3), 1);
  EXPECT_EQ(mjr::math::odr::min4( 1, 4, 3, 2), 1);
  EXPECT_EQ(mjr::math::odr::min4( 2, 4, 1, 3), 1);
  EXPECT_EQ(mjr::math::odr::min4( 2, 4, 3, 1), 1);
  EXPECT_EQ(mjr::math::odr::min4( 3, 4, 1, 2), 1);
  EXPECT_EQ(mjr::math::odr::min4( 3, 4, 2, 1), 1);
  EXPECT_EQ(mjr::math::odr::min4( 4, 1, 2, 3), 1);
  EXPECT_EQ(mjr::math::odr::min4( 4, 1, 3, 2), 1);
  EXPECT_EQ(mjr::math::odr::min4( 4, 2, 1, 3), 1);
  EXPECT_EQ(mjr::math::odr::min4( 4, 2, 3, 1), 1);
  EXPECT_EQ(mjr::math::odr::min4( 4, 3, 1, 2), 1);
  EXPECT_EQ(mjr::math::odr::min4( 4, 3, 2, 1), 1);

  EXPECT_EQ(mjr::math::odr::min4( 1, 1, 1, 1), 1);
  EXPECT_EQ(mjr::math::odr::min4( 4, 4, 4, 4), 4);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_max4, Comprehensive) {
  EXPECT_EQ(mjr::math::odr::max4( 1.0,  2.0,  3.0,  4.0), 4.0);
  EXPECT_EQ(mjr::math::odr::max4( 4.0,  3.0,  2.0,  1.0), 4.0);

  EXPECT_EQ(mjr::math::odr::max4( 1.0f, 2.0f, 3.0f, 4.0f), 4.0f);
  EXPECT_EQ(mjr::math::odr::max4( 4.0f, 3.0f, 2.0f, 1.0f), 4.0f);

  EXPECT_EQ(mjr::math::odr::max4( 1,   2,   3,   4),   4);
  EXPECT_EQ(mjr::math::odr::max4( 1L,  2L,  3L,  4L),  4L);
  EXPECT_EQ(mjr::math::odr::max4( 1UL, 2UL, 3UL, 4UL), 4UL);

  EXPECT_EQ(mjr::math::odr::max4( 1, 2, 3, 4), 4);
  EXPECT_EQ(mjr::math::odr::max4( 1, 3, 2, 4), 4);
  EXPECT_EQ(mjr::math::odr::max4( 2, 1, 3, 4), 4);
  EXPECT_EQ(mjr::math::odr::max4( 2, 3, 1, 4), 4);
  EXPECT_EQ(mjr::math::odr::max4( 3, 1, 2, 4), 4);
  EXPECT_EQ(mjr::math::odr::max4( 3, 2, 1, 4), 4);
  EXPECT_EQ(mjr::math::odr::max4( 1, 2, 4, 3), 4);
  EXPECT_EQ(mjr::math::odr::max4( 1, 3, 4, 2), 4);
  EXPECT_EQ(mjr::math::odr::max4( 2, 1, 4, 3), 4);
  EXPECT_EQ(mjr::math::odr::max4( 2, 3, 4, 1), 4);
  EXPECT_EQ(mjr::math::odr::max4( 3, 1, 4, 2), 4);
  EXPECT_EQ(mjr::math::odr::max4( 3, 2, 4, 1), 4);
  EXPECT_EQ(mjr::math::odr::max4( 1, 4, 2, 3), 4);
  EXPECT_EQ(mjr::math::odr::max4( 1, 4, 3, 2), 4);
  EXPECT_EQ(mjr::math::odr::max4( 2, 4, 1, 3), 4);
  EXPECT_EQ(mjr::math::odr::max4( 2, 4, 3, 1), 4);
  EXPECT_EQ(mjr::math::odr::max4( 3, 4, 1, 2), 4);
  EXPECT_EQ(mjr::math::odr::max4( 3, 4, 2, 1), 4);
  EXPECT_EQ(mjr::math::odr::max4( 4, 1, 2, 3), 4);
  EXPECT_EQ(mjr::math::odr::max4( 4, 1, 3, 2), 4);
  EXPECT_EQ(mjr::math::odr::max4( 4, 2, 1, 3), 4);
  EXPECT_EQ(mjr::math::odr::max4( 4, 2, 3, 1), 4);
  EXPECT_EQ(mjr::math::odr::max4( 4, 3, 1, 2), 4);
  EXPECT_EQ(mjr::math::odr::max4( 4, 3, 2, 1), 4);

  EXPECT_EQ(mjr::math::odr::max4( 1, 1, 1, 1), 1);
  EXPECT_EQ(mjr::math::odr::max4( 4, 4, 4, 4), 4);
}
/** @endcond */
