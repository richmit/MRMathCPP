// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      mjr_math_fc.cpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Unit tests for mjr::math::fc.@EOL
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

#include "MRMathFC.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_near_zero, Comprehensive) {
  EXPECT_TRUE( mjr::math::fc::near_zero( 0.0, 1e-5));
  EXPECT_TRUE( mjr::math::fc::near_zero(1e-5, 1e-5));  // Can fail if system has bad FP arithmatic (non-IEEE for example)
  EXPECT_TRUE( mjr::math::fc::near_zero(1e-6, 1e-5));
  EXPECT_FALSE(mjr::math::fc::near_zero(2e-5, 1e-5));

  EXPECT_TRUE( mjr::math::fc::near_zero(std::complex( 0.0,  0.0), 1e-5));
  EXPECT_TRUE( mjr::math::fc::near_zero(std::complex(1e-5,  0.0), 1e-5));
  EXPECT_TRUE( mjr::math::fc::near_zero(std::complex(1e-6,  0.0), 1e-5));
  EXPECT_FALSE(mjr::math::fc::near_zero(std::complex(2e-5,  0.0), 1e-5));

  EXPECT_TRUE( mjr::math::fc::near_zero(std::complex( 0.0,  0.0), 1e-5));
  EXPECT_TRUE( mjr::math::fc::near_zero(std::complex( 0.0, 1e-5), 1e-5));
  EXPECT_TRUE( mjr::math::fc::near_zero(std::complex( 0.0, 1e-6), 1e-5));
  EXPECT_FALSE(mjr::math::fc::near_zero(std::complex( 0.0, 2e-5), 1e-5));

  EXPECT_TRUE( mjr::math::fc::near_zero(std::complex( 0.0,  0.0), 1e-5));
  EXPECT_TRUE( mjr::math::fc::near_zero(std::complex(1e-5, 1e-5), 1e-5));
  EXPECT_TRUE( mjr::math::fc::near_zero(std::complex(1e-6, 1e-6), 1e-5));
  EXPECT_FALSE(mjr::math::fc::near_zero(std::complex(2e-5, 2e-5), 1e-5));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_near, Comprehensive) {
  EXPECT_TRUE( mjr::math::fc::near( 0.0,      0.0, 1e-5));
  EXPECT_TRUE( mjr::math::fc::near(1e-5,      0.0, 1e-5));  // Can fail if system has bad FP arithmatic (non-IEEE for example)
  EXPECT_TRUE( mjr::math::fc::near(1e-6,      0.0, 1e-5));
  EXPECT_FALSE(mjr::math::fc::near(2e-5,      0.0, 1e-5));
                                                 
  EXPECT_TRUE( mjr::math::fc::near( 0.0,      0.0, 1e-5));
  EXPECT_TRUE( mjr::math::fc::near( 0.0,     1e-5, 1e-5));  // Can fail if system has bad FP arithmatic (non-IEEE for example)
  EXPECT_TRUE( mjr::math::fc::near( 0.0,     1e-6, 1e-5));
  EXPECT_FALSE(mjr::math::fc::near( 0.0,     2e-5, 1e-5));
                                                 
  EXPECT_TRUE( mjr::math::fc::near( 1.0,      1.0, 1e-5));
  EXPECT_FALSE(mjr::math::fc::near(1e-5,     3e-5, 1e-5));

  EXPECT_FALSE(mjr::math::fc::near( 1.0, 1.000020, 1e-5));
  EXPECT_TRUE( mjr::math::fc::near( 1.0, 1.000002, 1e-5));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_not_near_zero, Comprehensive) {
  EXPECT_FALSE(mjr::math::fc::not_near_zero( 0.0, 1e-5));
  EXPECT_FALSE(mjr::math::fc::not_near_zero(1e-5, 1e-5));  // Can fail if system has bad FP arithmatic (non-IEEE for example)
  EXPECT_FALSE(mjr::math::fc::not_near_zero(1e-6, 1e-5));
  EXPECT_TRUE( mjr::math::fc::not_near_zero(2e-5, 1e-5));

  EXPECT_FALSE(mjr::math::fc::not_near_zero(std::complex( 0.0,  0.0), 1e-5));
  EXPECT_FALSE(mjr::math::fc::not_near_zero(std::complex(1e-5,  0.0), 1e-5));
  EXPECT_FALSE(mjr::math::fc::not_near_zero(std::complex(1e-6,  0.0), 1e-5));
  EXPECT_TRUE( mjr::math::fc::not_near_zero(std::complex(2e-5,  0.0), 1e-5));

  EXPECT_FALSE(mjr::math::fc::not_near_zero(std::complex( 0.0,  0.0), 1e-5));
  EXPECT_FALSE(mjr::math::fc::not_near_zero(std::complex( 0.0, 1e-5), 1e-5));
  EXPECT_FALSE(mjr::math::fc::not_near_zero(std::complex( 0.0, 1e-6), 1e-5));
  EXPECT_TRUE( mjr::math::fc::not_near_zero(std::complex( 0.0, 2e-5), 1e-5));

  EXPECT_FALSE(mjr::math::fc::not_near_zero(std::complex( 0.0,  0.0), 1e-5));
  EXPECT_FALSE(mjr::math::fc::not_near_zero(std::complex(1e-5, 1e-5), 1e-5));
  EXPECT_FALSE(mjr::math::fc::not_near_zero(std::complex(1e-6, 1e-6), 1e-5));
  EXPECT_TRUE( mjr::math::fc::not_near_zero(std::complex(2e-5, 2e-5), 1e-5));
}
/** @endcond */

