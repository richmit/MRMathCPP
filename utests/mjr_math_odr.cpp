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

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE Main
#endif
#include <boost/test/unit_test.hpp>

#include "MRMathODR.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(min3) {
  BOOST_TEST_CHECK(mjr::math::odr::min3( 1.0,  2.0,  3.0) ==  1.0);
  BOOST_TEST_CHECK(mjr::math::odr::min3( 3.0,  2.0,  1.0) ==  1.0);

  BOOST_TEST_CHECK(mjr::math::odr::min3( 1.0f, 2.0f, 3.0f) == 1.0f);
  BOOST_TEST_CHECK(mjr::math::odr::min3( 3.0f, 2.0f, 1.0f) == 1.0f);

  BOOST_TEST_CHECK(mjr::math::odr::min3( 1,   2,   3)   == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min3( 1L,  2L,  3L)  == 1L);
  BOOST_TEST_CHECK(mjr::math::odr::min3( 1UL, 2UL, 3UL) == 1UL);

  BOOST_TEST_CHECK(mjr::math::odr::min3( 1, 2, 3) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min3( 1, 3, 2) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min3( 2, 1, 3) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min3( 2, 3, 1) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min3( 3, 1, 2) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min3( 3, 2, 1) == 1);

  BOOST_TEST_CHECK(mjr::math::odr::min3( 1, 1, 1) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min3( 3, 3, 3) == 3);
}

BOOST_AUTO_TEST_CASE(max3) {
  BOOST_TEST_CHECK(mjr::math::odr::max3( 1.0,  2.0,  3.0) ==  3.0);
  BOOST_TEST_CHECK(mjr::math::odr::max3( 3.0,  2.0,  1.0) ==  3.0);

  BOOST_TEST_CHECK(mjr::math::odr::max3( 1.0f, 2.0f, 3.0f) == 3.0f);
  BOOST_TEST_CHECK(mjr::math::odr::max3( 3.0f, 2.0f, 1.0f) == 3.0f);

  BOOST_TEST_CHECK(mjr::math::odr::max3( 1,   2,   3)   == 3);
  BOOST_TEST_CHECK(mjr::math::odr::max3( 1L,  2L,  3L)  == 3L);
  BOOST_TEST_CHECK(mjr::math::odr::max3( 1UL, 2UL, 3UL) == 3UL);

  BOOST_TEST_CHECK(mjr::math::odr::max3( 1, 2, 3) == 3);
  BOOST_TEST_CHECK(mjr::math::odr::max3( 1, 3, 2) == 3);
  BOOST_TEST_CHECK(mjr::math::odr::max3( 2, 1, 3) == 3);
  BOOST_TEST_CHECK(mjr::math::odr::max3( 2, 3, 1) == 3);
  BOOST_TEST_CHECK(mjr::math::odr::max3( 3, 1, 2) == 3);
  BOOST_TEST_CHECK(mjr::math::odr::max3( 3, 2, 1) == 3);

  BOOST_TEST_CHECK(mjr::math::odr::max3( 1, 1, 1) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::max3( 3, 3, 3) == 3);
}

BOOST_AUTO_TEST_CASE(min4) {
  BOOST_TEST_CHECK(mjr::math::odr::min4( 1.0,  2.0,  3.0,  4.0) ==  1.0);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 4.0,  3.0,  2.0,  1.0) ==  1.0);

  BOOST_TEST_CHECK(mjr::math::odr::min4( 1.0f, 2.0f, 3.0f, 4.0f) == 1.0f);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 4.0f, 3.0f, 2.0f, 1.0f) == 1.0f);

  BOOST_TEST_CHECK(mjr::math::odr::min4( 1,   2,   3,   4)   == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 1L,  2L,  3L,  4L)  == 1L);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 1UL, 2UL, 3UL, 4UL) == 1UL);

  BOOST_TEST_CHECK(mjr::math::odr::min4( 1, 2, 3, 4) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 1, 3, 2, 4) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 2, 1, 3, 4) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 2, 3, 1, 4) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 3, 1, 2, 4) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 3, 2, 1, 4) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 1, 2, 4, 3) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 1, 3, 4, 2) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 2, 1, 4, 3) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 2, 3, 4, 1) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 3, 1, 4, 2) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 3, 2, 4, 1) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 1, 4, 2, 3) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 1, 4, 3, 2) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 2, 4, 1, 3) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 2, 4, 3, 1) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 3, 4, 1, 2) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 3, 4, 2, 1) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 4, 1, 2, 3) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 4, 1, 3, 2) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 4, 2, 1, 3) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 4, 2, 3, 1) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 4, 3, 1, 2) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 4, 3, 2, 1) == 1);

  BOOST_TEST_CHECK(mjr::math::odr::min4( 1, 1, 1, 1) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::min4( 4, 4, 4, 4) == 4);
}

BOOST_AUTO_TEST_CASE(max4) {
  BOOST_TEST_CHECK(mjr::math::odr::max4( 1.0,  2.0,  3.0,  4.0) ==  4.0);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 4.0,  3.0,  2.0,  1.0) ==  4.0);

  BOOST_TEST_CHECK(mjr::math::odr::max4( 1.0f, 2.0f, 3.0f, 4.0f) == 4.0f);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 4.0f, 3.0f, 2.0f, 1.0f) == 4.0f);

  BOOST_TEST_CHECK(mjr::math::odr::max4( 1,   2,   3,   4)   == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 1L,  2L,  3L,  4L)  == 4L);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 1UL, 2UL, 3UL, 4UL) == 4UL);

  BOOST_TEST_CHECK(mjr::math::odr::max4( 1, 2, 3, 4) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 1, 3, 2, 4) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 2, 1, 3, 4) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 2, 3, 1, 4) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 3, 1, 2, 4) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 3, 2, 1, 4) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 1, 2, 4, 3) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 1, 3, 4, 2) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 2, 1, 4, 3) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 2, 3, 4, 1) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 3, 1, 4, 2) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 3, 2, 4, 1) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 1, 4, 2, 3) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 1, 4, 3, 2) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 2, 4, 1, 3) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 2, 4, 3, 1) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 3, 4, 1, 2) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 3, 4, 2, 1) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 4, 1, 2, 3) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 4, 1, 3, 2) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 4, 2, 1, 3) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 4, 2, 3, 1) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 4, 3, 1, 2) == 4);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 4, 3, 2, 1) == 4);

  BOOST_TEST_CHECK(mjr::math::odr::max4( 1, 1, 1, 1) == 1);
  BOOST_TEST_CHECK(mjr::math::odr::max4( 4, 4, 4, 4) == 4);
}
/** @endcond */
