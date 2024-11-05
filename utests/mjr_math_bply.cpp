// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      mjr_math_bply.cpp
 @author    Mitch Richling http://www.mitchr.me/
 @date      2022-08-24
 @brief     Unit tests for mjr::math::bply.@EOL
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

#include "MRMathBPLY.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_max_pow, Comprehensive) {
  // normal cases
  for(int i=2; i<=100; i++) 
    EXPECT_EQ(mjr::math::bply::max_pow((i+1)*(i+1)), i);
  // one too small to be a poly
  for(int i=2; i<=100; i++) 
    EXPECT_EQ(mjr::math::bply::max_pow((i+1)*(i+1)-1), -3);
  // one too big to be a poly
  for(int i=2; i<100; i++) 
    EXPECT_EQ(mjr::math::bply::max_pow((i+1)*(i+1)+1), -3);
  // too big to support
  EXPECT_EQ(mjr::math::bply::max_pow((100+1)*(100+1)+1), -1);
  EXPECT_EQ(mjr::math::bply::max_pow((101+1)*(101+1)),   -1);
  // too small to support
  EXPECT_EQ(mjr::math::bply::max_pow(0), -2);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_eval, Comprehensive) {

  std::vector<double> BiPoly01 {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<double> BiPoly02 {9, 8, 7, 6, 5, 4, 3, 2, 1};

  std::vector<double> BiPoly03 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  std::vector<double> BiPoly04 {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  //------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                       
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly01, 0, 0), 9,     1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly01, 0, 1), 24,    1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly01, 1, 0), 18,    1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly01, 1, 1), 45,    1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly01, 2, 3), 282,   1.0e-5);

  EXPECT_NEAR(mjr::math::bply::eval(BiPoly02, 0, 0), 1,     1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly02, 0, 1), 6,     1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly02, 1, 0), 12,    1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly02, 1, 1), 45,    1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly02, 2, 3), 628,   1.0e-5);
                                                          
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly03, 0, 0), 16,    1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly03, 0, 1), 58,    1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly03, 1, 0), 40,    1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly03, 1, 1), 136,   1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly03, 2, 3), 2630,  1.0e-5);

  EXPECT_NEAR(mjr::math::bply::eval(BiPoly04, 0, 0), 1,     1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly04, 0, 1), 10,    1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly04, 1, 0), 28,    1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly04, 1, 1), 136,   1.0e-5);
  EXPECT_NEAR(mjr::math::bply::eval(BiPoly04, 2, 3), 7570,  1.0e-5);
}
/** @endcond */
