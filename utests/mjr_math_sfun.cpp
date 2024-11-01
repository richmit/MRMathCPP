// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      mjr_math_sfun.cpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Unit tests for mjr::math::sfun.@EOL
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

#include "MRMathSFUN.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(sgn) {
  BOOST_TEST_CHECK(mjr::math::sfun::sgn( 2) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn( 1) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn( 0) ==  0);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn(-1) == -1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn(-2) == -1);

  BOOST_TEST_CHECK(mjr::math::sfun::sgn( 2.0) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn( 1.0) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn( 0.0) ==  0);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn(-1.0) == -1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn(-2.0) == -1);

  BOOST_TEST_CHECK(mjr::math::sfun::sgn( 2.1) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn( 1.1) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn( 0.1) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn(-0.1) == -1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn(-1.1) == -1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn(-2.1) == -1);

  BOOST_TEST_CHECK(mjr::math::sfun::sgn( 2.9) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn( 1.9) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn( 0.9) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn(-0.9) == -1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn(-1.9) == -1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgn(-2.9) == -1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(sgne) {

  BOOST_TEST_CHECK(mjr::math::sfun::sgne( 2.0, 1.0e-5) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgne( 1.0, 1.0e-5) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgne( 0.0, 1.0e-5) ==  0);
  BOOST_TEST_CHECK(mjr::math::sfun::sgne(-1.0, 1.0e-5) == -1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgne(-2.0, 1.0e-5) == -1);

  BOOST_TEST_CHECK(mjr::math::sfun::sgne( 2.1, 1.0e-5) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgne( 1.1, 1.0e-5) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgne( 0.1, 1.0e-5) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgne(-0.1, 1.0e-5) == -1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgne(-1.1, 1.0e-5) == -1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgne(-2.1, 1.0e-5) == -1);

  BOOST_TEST_CHECK(mjr::math::sfun::sgne( 2.9, 1.0e-5) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgne( 1.9, 1.0e-5) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgne( 0.9, 1.0e-5) ==  1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgne(-0.9, 1.0e-5) == -1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgne(-1.9, 1.0e-5) == -1);
  BOOST_TEST_CHECK(mjr::math::sfun::sgne(-2.9, 1.0e-5) == -1);

  // epsilon is big enough 0.1 & -0.1 are considered zero
  BOOST_TEST_CHECK(mjr::math::sfun::sgne( 0.1, 0.20) ==  0);
  BOOST_TEST_CHECK(mjr::math::sfun::sgne(-0.1, 0.20) ==  0);
}
/** @endcond */
