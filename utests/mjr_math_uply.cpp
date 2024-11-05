// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      mjr_math_uply.cpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Unit tests for mjr::math::uply.@EOL
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

#include "MRMathUPLY.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_eval, TYP_Double) {

  std::vector<double> UnPoly01 {1, 2, 3, 4, 5, 6};
  std::vector<double> UnPoly02 {6, 5, 4, 3, 2, 1};

  EXPECT_NEAR(mjr::math::uply::eval(UnPoly01, 0),     6, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly01, 1),    21, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly01, 2),   120, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly01, 3),   543, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly01, 4),  1818, 1.0e-5);

  EXPECT_NEAR(mjr::math::uply::eval(UnPoly02, 0),     1, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly02, 1),    21, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly02, 2),   321, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly02, 3),  2005, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly02, 4),  7737, 1.0e-5);

//  MJR COVERAGE NOTE <2024-11-04T15:54:05-0600> mjr_math_uply: Add float & int cases
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_eval, EmptyPoly) {
  std::vector<double> UnPoly03;

  EXPECT_NEAR(mjr::math::uply::eval(UnPoly03, 0),     0, 1.0e-5);
}
/** @endcond */
