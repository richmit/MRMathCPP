// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      mjr_math_cplx.cpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Unit tests for mjr::math::cplx.@EOL
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

#include "MRMathCPLX.hpp"
#include "MRMathFC.hpp"

#include <gtest/gtest.h>

typedef std::complex<double> cd_t;
typedef std::complex<float>  cf_t;
typedef std::complex<int>    ci_t;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(CPLX, Double) {
  cd_t z1 = cd_t( 1.1, 2.2);
  cd_t z2 = cd_t(-3.3, 4.4);
  cd_t z3 = cd_t( 0.0, 5.5);

  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::norm2sqr(z1),          6.05, 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::norm1(z1),             3.30, 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::normI(z1),             2.20, 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::rconj(z1), cd_t(-1.1,  2.2), 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::cswap(z1), cd_t( 2.2,  1.1), 1.0e-5));
                                                                               
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::norm2sqr(z2),         30.25, 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::norm1(z2),             7.70, 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::normI(z2),             4.40, 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::rconj(z2), cd_t( 3.3,  4.4), 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::cswap(z2), cd_t( 4.4, -3.3), 1.0e-5));

  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::norm2sqr(z3),        30.25, 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::norm1(z3),            5.50, 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::normI(z3),            5.50, 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::rconj(z3), cd_t( 0.0, 5.5), 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::cswap(z3), cd_t( 5.5, 0.0), 1.0e-5));

  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::dist2(   z1, z2),  4.9193495505, 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::dist2sqr(z1, z2), 24.2000000000, 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::distI(   z1, z2),  4.4000000000, 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::dist1(   z1, z2),  6.6000000000, 1.0e-5));

  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::dist2(   z2, z1),  4.9193495505, 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::dist2sqr(z2, z1), 24.2000000000, 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::distI(   z2, z1),  4.4000000000, 1.0e-5));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::dist1(   z2, z1),  6.6000000000, 1.0e-5));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(CPLX, Float) {
  cf_t z1 = cf_t( 1.1f, 2.2f);
  cf_t z2 = cf_t(-3.3f, 4.4f);
  cf_t z3 = cf_t( 0.0f, 5.5f);

  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::norm2sqr(z1),           6.05f, 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::norm1(z1),              3.30f, 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::normI(z1),              2.20f, 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::rconj(z1), cf_t(-1.1f,  2.2f), 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::cswap(z1), cf_t( 2.2f,  1.1f), 1.0e-5f));
                                                                               
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::norm2sqr(z2),          30.25f, 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::norm1(z2),              7.70f, 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::normI(z2),              4.40f, 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::rconj(z2), cf_t( 3.3f,  4.4f), 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::cswap(z2), cf_t( 4.4f, -3.3f), 1.0e-5f));

  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::norm2sqr(z3),         30.25f, 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::norm1(z3),             5.50f, 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::normI(z3),             5.50f, 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::rconj(z3), cf_t( 0.0f, 5.5f), 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::cswap(z3), cf_t( 5.5f, 0.0f), 1.0e-5f));

  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::dist2(   z1, z2),  4.9193495505f, 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::dist2sqr(z1, z2), 24.2000000000f, 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::distI(   z1, z2),  4.4000000000f, 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::dist1(   z1, z2),  6.6000000000f, 1.0e-5f));

  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::dist2(   z2, z1),  4.9193495505f, 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::dist2sqr(z2, z1), 24.2000000000f, 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::distI(   z2, z1),  4.4000000000f, 1.0e-5f));
  EXPECT_TRUE(mjr::math::fc::near(mjr::math::cplx::dist1(   z2, z1),  6.6000000000f, 1.0e-5f));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(CPLX, Integer) {
  ci_t z1 = ci_t( 1, 2);
  ci_t z2 = ci_t(-3, 4);
  ci_t z3 = ci_t( 0, 5);

  EXPECT_EQ(mjr::math::cplx::norm2sqr(z1),  5);
  EXPECT_EQ(mjr::math::cplx::norm1(z1),     3);
  EXPECT_EQ(mjr::math::cplx::normI(z1),     2);
  EXPECT_EQ(mjr::math::cplx::rconj(z1),     ci_t(-1,  2));
  EXPECT_EQ(mjr::math::cplx::cswap(z1),     ci_t( 2,  1));
                                                           
  EXPECT_EQ(mjr::math::cplx::norm2sqr(z2),  25);
  EXPECT_EQ(mjr::math::cplx::norm1(z2),     7);
  EXPECT_EQ(mjr::math::cplx::normI(z2),     4);
  EXPECT_EQ(mjr::math::cplx::rconj(z2),     ci_t( 3,  4));
  EXPECT_EQ(mjr::math::cplx::cswap(z2),     ci_t( 4, -3));

  EXPECT_EQ(mjr::math::cplx::norm2sqr(z3),  25);
  EXPECT_EQ(mjr::math::cplx::norm1(z3),     5);
  EXPECT_EQ(mjr::math::cplx::normI(z3),     5);
  EXPECT_EQ(mjr::math::cplx::rconj(z3),     ci_t( 0, 5));
  EXPECT_EQ(mjr::math::cplx::cswap(z3),     ci_t( 5, 0));

  EXPECT_EQ(mjr::math::cplx::dist2(   z1, z2), 4);
  EXPECT_EQ(mjr::math::cplx::dist2sqr(z1, z2), 20);
  EXPECT_EQ(mjr::math::cplx::distI(   z1, z2), 4);
  EXPECT_EQ(mjr::math::cplx::dist1(   z1, z2), 6);

  EXPECT_EQ(mjr::math::cplx::dist2(   z2, z1), 4);
  EXPECT_EQ(mjr::math::cplx::dist2sqr(z2, z1), 20);
  EXPECT_EQ(mjr::math::cplx::distI(   z2, z1), 4);
  EXPECT_EQ(mjr::math::cplx::dist1(   z2, z1), 6);
}

/** @endcond */

