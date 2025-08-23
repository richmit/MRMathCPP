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
#include "MRMathVEC.hpp"
#include "MRMathFC.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_eval, TYP_CplxDouble) {

  std::vector<std::complex<double>> UnPoly01 {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  std::vector<std::complex<double>> UnPoly02 {6.0, 5.0, 4.0, 3.0, 2.0, 1.0};

  EXPECT_TRUE(mjr::math::fc::near(mjr::math::uply::eval(UnPoly01, std::complex<double>(0.0, 0.0)),  std::complex<double>(   6.0, 0.0), 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::uply::eval(UnPoly01, std::complex<double>(1.0, 0.0)),  std::complex<double>(  21.0, 0.0), 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::uply::eval(UnPoly01, std::complex<double>(2.0, 0.0)),  std::complex<double>( 120.0, 0.0), 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::uply::eval(UnPoly01, std::complex<double>(3.0, 0.0)),  std::complex<double>( 543.0, 0.0), 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::uply::eval(UnPoly01, std::complex<double>(4.0, 0.0)),  std::complex<double>(1818.0, 0.0), 1.0e-5));

  EXPECT_TRUE(mjr::math::fc::near(mjr::math::uply::eval(UnPoly02, std::complex<double>(0.0, 0.0)),  std::complex<double>(   1.0, 0.0), 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::uply::eval(UnPoly02, std::complex<double>(1.0, 0.0)),  std::complex<double>(  21.0, 0.0), 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::uply::eval(UnPoly02, std::complex<double>(2.0, 0.0)),  std::complex<double>( 321.0, 0.0), 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::uply::eval(UnPoly02, std::complex<double>(3.0, 0.0)),  std::complex<double>(2005.0, 0.0), 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::uply::eval(UnPoly02, std::complex<double>(4.0, 0.0)),  std::complex<double>(7737.0, 0.0), 1.0e-5));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_eval, TYP_Double) {

  std::vector<double> UnPoly01 {1, 2, 3, 4, 5, 6};
  std::vector<double> UnPoly02 {6, 5, 4, 3, 2, 1};

  EXPECT_NEAR(mjr::math::uply::eval(UnPoly01, 0.0),     6.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly01, 1.0),    21.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly01, 2.0),   120.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly01, 3.0),   543.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly01, 4.0),  1818.0, 1.0e-5);

  EXPECT_NEAR(mjr::math::uply::eval(UnPoly02, 0.0),     1.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly02, 1.0),    21.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly02, 2.0),   321.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly02, 3.0),  2005.0, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly02, 4.0),  7737.0, 1.0e-5);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_eval, TYP_Float) {

  std::vector<float> UnPoly01 {1, 2, 3, 4, 5, 6};
  std::vector<float> UnPoly02 {6, 5, 4, 3, 2, 1};

  EXPECT_NEAR(mjr::math::uply::eval(UnPoly01, 0.0F),     6.0F, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly01, 1.0F),    21.0F, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly01, 2.0F),   120.0F, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly01, 3.0F),   543.0F, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly01, 4.0F),  1818.0F, 1.0e-5);

  EXPECT_NEAR(mjr::math::uply::eval(UnPoly02, 0.0F),     1.0F, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly02, 1.0F),    21.0F, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly02, 2.0F),   321.0F, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly02, 3.0F),  2005.0F, 1.0e-5);
  EXPECT_NEAR(mjr::math::uply::eval(UnPoly02, 4.0F),  7737.0F, 1.0e-5);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_eval, TYP_Int) {

  std::vector<int> UnPoly01 {1, 2, 3, 4, 5, 6};
  std::vector<int> UnPoly02 {6, 5, 4, 3, 2, 1};

  EXPECT_EQ(mjr::math::uply::eval(UnPoly01, 0),     6);
  EXPECT_EQ(mjr::math::uply::eval(UnPoly01, 1),    21);
  EXPECT_EQ(mjr::math::uply::eval(UnPoly01, 2),   120);
  EXPECT_EQ(mjr::math::uply::eval(UnPoly01, 3),   543);
  EXPECT_EQ(mjr::math::uply::eval(UnPoly01, 4),  1818);

  EXPECT_EQ(mjr::math::uply::eval(UnPoly02, 0),     1);
  EXPECT_EQ(mjr::math::uply::eval(UnPoly02, 1),    21);
  EXPECT_EQ(mjr::math::uply::eval(UnPoly02, 2),   321);
  EXPECT_EQ(mjr::math::uply::eval(UnPoly02, 3),  2005);
  EXPECT_EQ(mjr::math::uply::eval(UnPoly02, 4),  7737);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_eval, EmptyPoly) {
  std::vector<double> UnPolyD;
  EXPECT_NEAR(mjr::math::uply::eval(UnPolyD, 0.0),  0.0,  1.0e-5);

  std::vector<float> UnPolyF;
  EXPECT_NEAR(mjr::math::uply::eval(UnPolyF, 0.0F), 0.0F, 1.0e-5);

  std::vector<int> UnPolyI;
  EXPECT_NEAR(mjr::math::uply::eval(UnPolyI, 0),    0,    1.0e-5);

  std::vector<std::complex<double>> UnPolyCD;
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::uply::eval(UnPolyCD, std::complex<double>(0.0, 0.0)),  std::complex<double>(0.0, 0.0),  1.0e-5));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_evald, TYP_Double) {
  std::vector<double> UnPoly01 {2, 3, 4};
  std::array<double, 1> Val1 { -1.0 };
  std::array<double, 2> Val2 { -1.0, -1.0 };
  std::array<double, 3> Val3 { -1.0, -1.0, -1.0 };
  std::array<double, 4> Val4 { -1.0, -1.0, -1.0, -1.0 };
  std::array<double, 5> Val5 { -1.0, -1.0, -1.0, -1.0, -1.0 };

  mjr::math::uply::evald(UnPoly01, -1.0, Val1); EXPECT_TRUE(mjr::math::vec::nearI(Val1, std::array<double, 1> { 3.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  0.0, Val1); EXPECT_TRUE(mjr::math::vec::nearI(Val1, std::array<double, 1> { 4.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  1.0, Val1); EXPECT_TRUE(mjr::math::vec::nearI(Val1, std::array<double, 1> { 9.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  2.0, Val1); EXPECT_TRUE(mjr::math::vec::nearI(Val1, std::array<double, 1> {18.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  3.0, Val1); EXPECT_TRUE(mjr::math::vec::nearI(Val1, std::array<double, 1> {31.0}, 1e-5));

  mjr::math::uply::evald(UnPoly01, -1.0, Val2); EXPECT_TRUE(mjr::math::vec::nearI(Val2, std::array<double, 2> { 3.0, -1.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  0.0, Val2); EXPECT_TRUE(mjr::math::vec::nearI(Val2, std::array<double, 2> { 4.0,  3.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  1.0, Val2); EXPECT_TRUE(mjr::math::vec::nearI(Val2, std::array<double, 2> { 9.0,  7.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  2.0, Val2); EXPECT_TRUE(mjr::math::vec::nearI(Val2, std::array<double, 2> {18.0, 11.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  3.0, Val2); EXPECT_TRUE(mjr::math::vec::nearI(Val2, std::array<double, 2> {31.0, 15.0}, 1e-5));

  mjr::math::uply::evald(UnPoly01, -1.0, Val3); EXPECT_TRUE(mjr::math::vec::nearI(Val3, std::array<double, 3> { 3.0, -1.0, 4.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  0.0, Val3); EXPECT_TRUE(mjr::math::vec::nearI(Val3, std::array<double, 3> { 4.0,  3.0, 4.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  1.0, Val3); EXPECT_TRUE(mjr::math::vec::nearI(Val3, std::array<double, 3> { 9.0,  7.0, 4.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  2.0, Val3); EXPECT_TRUE(mjr::math::vec::nearI(Val3, std::array<double, 3> {18.0, 11.0, 4.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  3.0, Val3); EXPECT_TRUE(mjr::math::vec::nearI(Val3, std::array<double, 3> {31.0, 15.0, 4.0}, 1e-5));

  mjr::math::uply::evald(UnPoly01, -1.0, Val4); EXPECT_TRUE(mjr::math::vec::nearI(Val4, std::array<double, 4> { 3.0, -1.0, 4.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  0.0, Val4); EXPECT_TRUE(mjr::math::vec::nearI(Val4, std::array<double, 4> { 4.0,  3.0, 4.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  1.0, Val4); EXPECT_TRUE(mjr::math::vec::nearI(Val4, std::array<double, 4> { 9.0,  7.0, 4.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  2.0, Val4); EXPECT_TRUE(mjr::math::vec::nearI(Val4, std::array<double, 4> {18.0, 11.0, 4.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  3.0, Val4); EXPECT_TRUE(mjr::math::vec::nearI(Val4, std::array<double, 4> {31.0, 15.0, 4.0, 0.0}, 1e-5));

  mjr::math::uply::evald(UnPoly01, -1.0, Val5); EXPECT_TRUE(mjr::math::vec::nearI(Val5, std::array<double, 5> { 3.0, -1.0, 4.0, 0.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  0.0, Val5); EXPECT_TRUE(mjr::math::vec::nearI(Val5, std::array<double, 5> { 4.0,  3.0, 4.0, 0.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  1.0, Val5); EXPECT_TRUE(mjr::math::vec::nearI(Val5, std::array<double, 5> { 9.0,  7.0, 4.0, 0.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  2.0, Val5); EXPECT_TRUE(mjr::math::vec::nearI(Val5, std::array<double, 5> {18.0, 11.0, 4.0, 0.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01,  3.0, Val5); EXPECT_TRUE(mjr::math::vec::nearI(Val5, std::array<double, 5> {31.0, 15.0, 4.0, 0.0, 0.0}, 1e-5));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_evald, TYP_Int) {
  std::vector<int> UnPoly01 {2, 3, 4};
  std::array<int, 1> Val1 { -1 };
  std::array<int, 2> Val2 { -1, -1 };
  std::array<int, 3> Val3 { -1, -1, -1 };
  std::array<int, 4> Val4 { -1, -1, -1, -1 };
  std::array<int, 5> Val5 { -1, -1, -1, -1, -1 };

  mjr::math::uply::evald(UnPoly01, -1, Val1); EXPECT_TRUE(mjr::math::vec::equal(Val1, std::array<int, 1> { 3}));
  mjr::math::uply::evald(UnPoly01,  0, Val1); EXPECT_TRUE(mjr::math::vec::equal(Val1, std::array<int, 1> { 4}));
  mjr::math::uply::evald(UnPoly01,  1, Val1); EXPECT_TRUE(mjr::math::vec::equal(Val1, std::array<int, 1> { 9}));
  mjr::math::uply::evald(UnPoly01,  2, Val1); EXPECT_TRUE(mjr::math::vec::equal(Val1, std::array<int, 1> {18}));
  mjr::math::uply::evald(UnPoly01,  3, Val1); EXPECT_TRUE(mjr::math::vec::equal(Val1, std::array<int, 1> {31}));

  mjr::math::uply::evald(UnPoly01, -1, Val2); EXPECT_TRUE(mjr::math::vec::equal(Val2, std::array<int, 2> { 3, -1}));
  mjr::math::uply::evald(UnPoly01,  0, Val2); EXPECT_TRUE(mjr::math::vec::equal(Val2, std::array<int, 2> { 4,  3}));
  mjr::math::uply::evald(UnPoly01,  1, Val2); EXPECT_TRUE(mjr::math::vec::equal(Val2, std::array<int, 2> { 9,  7}));
  mjr::math::uply::evald(UnPoly01,  2, Val2); EXPECT_TRUE(mjr::math::vec::equal(Val2, std::array<int, 2> {18, 11}));
  mjr::math::uply::evald(UnPoly01,  3, Val2); EXPECT_TRUE(mjr::math::vec::equal(Val2, std::array<int, 2> {31, 15}));

  mjr::math::uply::evald(UnPoly01, -1, Val3); EXPECT_TRUE(mjr::math::vec::equal(Val3, std::array<int, 3> { 3, -1, 4}));
  mjr::math::uply::evald(UnPoly01,  0, Val3); EXPECT_TRUE(mjr::math::vec::equal(Val3, std::array<int, 3> { 4,  3, 4}));
  mjr::math::uply::evald(UnPoly01,  1, Val3); EXPECT_TRUE(mjr::math::vec::equal(Val3, std::array<int, 3> { 9,  7, 4}));
  mjr::math::uply::evald(UnPoly01,  2, Val3); EXPECT_TRUE(mjr::math::vec::equal(Val3, std::array<int, 3> {18, 11, 4}));
  mjr::math::uply::evald(UnPoly01,  3, Val3); EXPECT_TRUE(mjr::math::vec::equal(Val3, std::array<int, 3> {31, 15, 4}));

  mjr::math::uply::evald(UnPoly01, -1, Val4); EXPECT_TRUE(mjr::math::vec::equal(Val4, std::array<int, 4> { 3, -1, 4, 0}));
  mjr::math::uply::evald(UnPoly01,  0, Val4); EXPECT_TRUE(mjr::math::vec::equal(Val4, std::array<int, 4> { 4,  3, 4, 0}));
  mjr::math::uply::evald(UnPoly01,  1, Val4); EXPECT_TRUE(mjr::math::vec::equal(Val4, std::array<int, 4> { 9,  7, 4, 0}));
  mjr::math::uply::evald(UnPoly01,  2, Val4); EXPECT_TRUE(mjr::math::vec::equal(Val4, std::array<int, 4> {18, 11, 4, 0}));
  mjr::math::uply::evald(UnPoly01,  3, Val4); EXPECT_TRUE(mjr::math::vec::equal(Val4, std::array<int, 4> {31, 15, 4, 0}));

  mjr::math::uply::evald(UnPoly01, -1, Val5); EXPECT_TRUE(mjr::math::vec::equal(Val5, std::array<int, 5> { 3, -1, 4, 0, 0}));
  mjr::math::uply::evald(UnPoly01,  0, Val5); EXPECT_TRUE(mjr::math::vec::equal(Val5, std::array<int, 5> { 4,  3, 4, 0, 0}));
  mjr::math::uply::evald(UnPoly01,  1, Val5); EXPECT_TRUE(mjr::math::vec::equal(Val5, std::array<int, 5> { 9,  7, 4, 0, 0}));
  mjr::math::uply::evald(UnPoly01,  2, Val5); EXPECT_TRUE(mjr::math::vec::equal(Val5, std::array<int, 5> {18, 11, 4, 0, 0}));
  mjr::math::uply::evald(UnPoly01,  3, Val5); EXPECT_TRUE(mjr::math::vec::equal(Val5, std::array<int, 5> {31, 15, 4, 0, 0}));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_evald, TYP_CplxDouble) {
  std::vector<std::complex<double>> UnPoly01 {2, 3, 4};
  std::array<std::complex<double>, 1> Val1 { -1.0 };
  std::array<std::complex<double>, 2> Val2 { -1.0, -1.0 };
  std::array<std::complex<double>, 3> Val3 { -1.0, -1.0, -1.0 };
  std::array<std::complex<double>, 4> Val4 { -1.0, -1.0, -1.0, -1.0 };
  std::array<std::complex<double>, 5> Val5 { -1.0, -1.0, -1.0, -1.0, -1.0 };

  mjr::math::uply::evald(UnPoly01, std::complex<double>(-1.0, 0.0), Val1); EXPECT_TRUE(mjr::math::vec::nearI(Val1, std::array<std::complex<double>, 1> { 3.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 0.0, 0.0), Val1); EXPECT_TRUE(mjr::math::vec::nearI(Val1, std::array<std::complex<double>, 1> { 4.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 1.0, 0.0), Val1); EXPECT_TRUE(mjr::math::vec::nearI(Val1, std::array<std::complex<double>, 1> { 9.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 2.0, 0.0), Val1); EXPECT_TRUE(mjr::math::vec::nearI(Val1, std::array<std::complex<double>, 1> {18.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 3.0, 0.0), Val1); EXPECT_TRUE(mjr::math::vec::nearI(Val1, std::array<std::complex<double>, 1> {31.0}, 1e-5));

  mjr::math::uply::evald(UnPoly01, std::complex<double>(-1.0, 0.0), Val2); EXPECT_TRUE(mjr::math::vec::nearI(Val2, std::array<std::complex<double>, 2> { 3.0, -1.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 0.0, 0.0), Val2); EXPECT_TRUE(mjr::math::vec::nearI(Val2, std::array<std::complex<double>, 2> { 4.0,  3.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 1.0, 0.0), Val2); EXPECT_TRUE(mjr::math::vec::nearI(Val2, std::array<std::complex<double>, 2> { 9.0,  7.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 2.0, 0.0), Val2); EXPECT_TRUE(mjr::math::vec::nearI(Val2, std::array<std::complex<double>, 2> {18.0, 11.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 3.0, 0.0), Val2); EXPECT_TRUE(mjr::math::vec::nearI(Val2, std::array<std::complex<double>, 2> {31.0, 15.0}, 1e-5));

  mjr::math::uply::evald(UnPoly01, std::complex<double>(-1.0, 0.0), Val3); EXPECT_TRUE(mjr::math::vec::nearI(Val3, std::array<std::complex<double>, 3> { 3.0, -1.0, 4.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 0.0, 0.0), Val3); EXPECT_TRUE(mjr::math::vec::nearI(Val3, std::array<std::complex<double>, 3> { 4.0,  3.0, 4.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 1.0, 0.0), Val3); EXPECT_TRUE(mjr::math::vec::nearI(Val3, std::array<std::complex<double>, 3> { 9.0,  7.0, 4.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 2.0, 0.0), Val3); EXPECT_TRUE(mjr::math::vec::nearI(Val3, std::array<std::complex<double>, 3> {18.0, 11.0, 4.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 3.0, 0.0), Val3); EXPECT_TRUE(mjr::math::vec::nearI(Val3, std::array<std::complex<double>, 3> {31.0, 15.0, 4.0}, 1e-5));

  mjr::math::uply::evald(UnPoly01, std::complex<double>(-1.0, 0.0), Val4); EXPECT_TRUE(mjr::math::vec::nearI(Val4, std::array<std::complex<double>, 4> { 3.0, -1.0, 4.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 0.0, 0.0), Val4); EXPECT_TRUE(mjr::math::vec::nearI(Val4, std::array<std::complex<double>, 4> { 4.0,  3.0, 4.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 1.0, 0.0), Val4); EXPECT_TRUE(mjr::math::vec::nearI(Val4, std::array<std::complex<double>, 4> { 9.0,  7.0, 4.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 2.0, 0.0), Val4); EXPECT_TRUE(mjr::math::vec::nearI(Val4, std::array<std::complex<double>, 4> {18.0, 11.0, 4.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 3.0, 0.0), Val4); EXPECT_TRUE(mjr::math::vec::nearI(Val4, std::array<std::complex<double>, 4> {31.0, 15.0, 4.0, 0.0}, 1e-5));

  mjr::math::uply::evald(UnPoly01, std::complex<double>(-1.0, 0.0), Val5); EXPECT_TRUE(mjr::math::vec::nearI(Val5, std::array<std::complex<double>, 5> { 3.0, -1.0, 4.0, 0.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 0.0, 0.0), Val5); EXPECT_TRUE(mjr::math::vec::nearI(Val5, std::array<std::complex<double>, 5> { 4.0,  3.0, 4.0, 0.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 1.0, 0.0), Val5); EXPECT_TRUE(mjr::math::vec::nearI(Val5, std::array<std::complex<double>, 5> { 9.0,  7.0, 4.0, 0.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 2.0, 0.0), Val5); EXPECT_TRUE(mjr::math::vec::nearI(Val5, std::array<std::complex<double>, 5> {18.0, 11.0, 4.0, 0.0, 0.0}, 1e-5));
  mjr::math::uply::evald(UnPoly01, std::complex<double>( 3.0, 0.0), Val5); EXPECT_TRUE(mjr::math::vec::nearI(Val5, std::array<std::complex<double>, 5> {31.0, 15.0, 4.0, 0.0, 0.0}, 1e-5));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_evald, EmptyPoly) {
  std::vector<std::complex<double>> UnPolyCD;
  std::array<std::complex<double>, 1> ValCD1 { -1.0 };
  std::array<std::complex<double>, 2> ValCD2 { -1.0, -1.0 };
  std::array<std::complex<double>, 3> ValCD3 { -1.0, -1.0, -1.0 };
  std::array<std::complex<double>, 4> ValCD4 { -1.0, -1.0, -1.0, -1.0 };
  std::array<std::complex<double>, 5> ValCD5 { -1.0, -1.0, -1.0, -1.0, -1.0 };

  mjr::math::uply::evald(UnPolyCD, std::complex<double>(0.0, 0.0), ValCD1); EXPECT_TRUE(mjr::math::vec::nearI(ValCD1, std::array<std::complex<double>, 1> { 0.0                     }, 1e-5));
  mjr::math::uply::evald(UnPolyCD, std::complex<double>(0.0, 0.0), ValCD2); EXPECT_TRUE(mjr::math::vec::nearI(ValCD2, std::array<std::complex<double>, 2> { 0.0, 0.0                }, 1e-5));
  mjr::math::uply::evald(UnPolyCD, std::complex<double>(0.0, 0.0), ValCD3); EXPECT_TRUE(mjr::math::vec::nearI(ValCD3, std::array<std::complex<double>, 3> { 0.0, 0.0, 0.0           }, 1e-5));
  mjr::math::uply::evald(UnPolyCD, std::complex<double>(0.0, 0.0), ValCD4); EXPECT_TRUE(mjr::math::vec::nearI(ValCD4, std::array<std::complex<double>, 4> { 0.0, 0.0, 0.0, 0.0      }, 1e-5));
  mjr::math::uply::evald(UnPolyCD, std::complex<double>(0.0, 0.0), ValCD5); EXPECT_TRUE(mjr::math::vec::nearI(ValCD5, std::array<std::complex<double>, 5> { 0.0, 0.0, 0.0, 0.0, 0.0 }, 1e-5));

  std::vector<double> UnPolyD;
  std::array<double, 1> ValD1 { -1.0 };
  std::array<double, 2> ValD2 { -1.0, -1.0 };
  std::array<double, 3> ValD3 { -1.0, -1.0, -1.0 };
  std::array<double, 4> ValD4 { -1.0, -1.0, -1.0, -1.0 };
  std::array<double, 5> ValD5 { -1.0, -1.0, -1.0, -1.0, -1.0 };

  mjr::math::uply::evald(UnPolyD, 0.0, ValD1); EXPECT_TRUE(mjr::math::vec::nearI(ValD1, std::array<double, 1> { 0.0                     }, 1e-5));
  mjr::math::uply::evald(UnPolyD, 0.0, ValD2); EXPECT_TRUE(mjr::math::vec::nearI(ValD2, std::array<double, 2> { 0.0, 0.0                }, 1e-5));
  mjr::math::uply::evald(UnPolyD, 0.0, ValD3); EXPECT_TRUE(mjr::math::vec::nearI(ValD3, std::array<double, 3> { 0.0, 0.0, 0.0           }, 1e-5));
  mjr::math::uply::evald(UnPolyD, 0.0, ValD4); EXPECT_TRUE(mjr::math::vec::nearI(ValD4, std::array<double, 4> { 0.0, 0.0, 0.0, 0.0      }, 1e-5));
  mjr::math::uply::evald(UnPolyD, 0.0, ValD5); EXPECT_TRUE(mjr::math::vec::nearI(ValD5, std::array<double, 5> { 0.0, 0.0, 0.0, 0.0, 0.0 }, 1e-5));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_evald_vs_eval, Comprehensive) {
  std::vector<double> UnPolyD01 {2, 3, 4};
  std::array<double, 1> ValD1 { -1.0 };
  std::array<double, 2> ValD2 { -1.0, -1.0 };
  std::array<double, 3> ValD3 { -1.0, -1.0, -1.0 };
  std::array<double, 4> ValD4 { -1.0, -1.0, -1.0, -1.0 };
  std::array<double, 5> ValD5 { -1.0, -1.0, -1.0, -1.0, -1.0 };

  for(int i=-10; i<11; i++) {
    mjr::math::uply::evald(UnPolyD01, static_cast<double>(i), ValD1); 
    EXPECT_NEAR(ValD1[0], mjr::math::uply::eval(UnPolyD01, static_cast<double>(i)), 1e-5);
    mjr::math::uply::evald(UnPolyD01, static_cast<double>(i), ValD2); 
    EXPECT_NEAR(ValD2[0], mjr::math::uply::eval(UnPolyD01, static_cast<double>(i)), 1e-5);
    mjr::math::uply::evald(UnPolyD01, static_cast<double>(i), ValD3); 
    EXPECT_NEAR(ValD3[0], mjr::math::uply::eval(UnPolyD01, static_cast<double>(i)), 1e-5);
    mjr::math::uply::evald(UnPolyD01, static_cast<double>(i), ValD4); 
    EXPECT_NEAR(ValD4[0], mjr::math::uply::eval(UnPolyD01, static_cast<double>(i)), 1e-5);
    mjr::math::uply::evald(UnPolyD01, static_cast<double>(i), ValD5); 
    EXPECT_NEAR(ValD5[0], mjr::math::uply::eval(UnPolyD01, static_cast<double>(i)), 1e-5);
  }

  std::vector<int> UnPolyI01 {2, 3, 4};
  std::array<int, 1> ValI1 { -1 };
  std::array<int, 2> ValI2 { -1, -1 };
  std::array<int, 3> ValI3 { -1, -1, -1 };
  std::array<int, 4> ValI4 { -1, -1, -1, -1 };
  std::array<int, 5> ValI5 { -1, -1, -1, -1, -1 };

  for(int i=-10; i<11; i++) {
    mjr::math::uply::evald(UnPolyI01, static_cast<int>(i), ValI1); 
    EXPECT_EQ(ValI1[0], mjr::math::uply::eval(UnPolyI01, static_cast<int>(i)));
    mjr::math::uply::evald(UnPolyI01, static_cast<int>(i), ValI2); 
    EXPECT_EQ(ValI2[0], mjr::math::uply::eval(UnPolyI01, static_cast<int>(i)));
    mjr::math::uply::evald(UnPolyI01, static_cast<int>(i), ValI3); 
    EXPECT_EQ(ValI3[0], mjr::math::uply::eval(UnPolyI01, static_cast<int>(i)));
    mjr::math::uply::evald(UnPolyI01, static_cast<int>(i), ValI4); 
    EXPECT_EQ(ValI4[0], mjr::math::uply::eval(UnPolyI01, static_cast<int>(i)));
    mjr::math::uply::evald(UnPolyI01, static_cast<int>(i), ValI5); 
    EXPECT_EQ(ValI5[0], mjr::math::uply::eval(UnPolyI01, static_cast<int>(i)));
  }
}

/** @endcond */
