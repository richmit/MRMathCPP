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

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE Main
#endif
#include <boost/test/unit_test.hpp>

#include "MRMathFC.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(near_zero) {
  BOOST_TEST_CHECK(mjr::math::fc::near_zero( 0.0, 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near_zero(1e-5, 1e-5) == true);  // Can fail if system has bad FP arithmatic (non-IEEE for example)
  BOOST_TEST_CHECK(mjr::math::fc::near_zero(1e-6, 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near_zero(2e-5, 1e-5) == false);

  BOOST_TEST_CHECK(mjr::math::fc::near_zero(std::complex( 0.0,  0.0), 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near_zero(std::complex(1e-5,  0.0), 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near_zero(std::complex(1e-6,  0.0), 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near_zero(std::complex(2e-5,  0.0), 1e-5) == false);

  BOOST_TEST_CHECK(mjr::math::fc::near_zero(std::complex( 0.0,  0.0), 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near_zero(std::complex( 0.0, 1e-5), 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near_zero(std::complex( 0.0, 1e-6), 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near_zero(std::complex( 0.0, 2e-5), 1e-5) == false);

  BOOST_TEST_CHECK(mjr::math::fc::near_zero(std::complex( 0.0,  0.0), 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near_zero(std::complex(1e-5, 1e-5), 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near_zero(std::complex(1e-6, 1e-6), 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near_zero(std::complex(2e-5, 2e-5), 1e-5) == false);
}

BOOST_AUTO_TEST_CASE(near) {
  BOOST_TEST_CHECK(mjr::math::fc::near( 0.0,      0.0, 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near(1e-5,      0.0, 1e-5) == true);  // Can fail if system has bad FP arithmatic (non-IEEE for example)
  BOOST_TEST_CHECK(mjr::math::fc::near(1e-6,      0.0, 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near(2e-5,      0.0, 1e-5) == false);
                                                 
  BOOST_TEST_CHECK(mjr::math::fc::near( 0.0,      0.0, 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near( 0.0,     1e-5, 1e-5) == true);  // Can fail if system has bad FP arithmatic (non-IEEE for example)
  BOOST_TEST_CHECK(mjr::math::fc::near( 0.0,     1e-6, 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near( 0.0,     2e-5, 1e-5) == false);
                                                 
  BOOST_TEST_CHECK(mjr::math::fc::near( 1.0,      1.0, 1e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near(1e-5,     3e-5, 1e-5) == false);

  BOOST_TEST_CHECK(mjr::math::fc::near( 1.0, 1.000020, 1e-5) == false);
  BOOST_TEST_CHECK(mjr::math::fc::near( 1.0, 1.000002, 1e-5) == true);
}
/** @endcond */
