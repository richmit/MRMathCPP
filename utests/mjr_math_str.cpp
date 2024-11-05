// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      mjr_math_str.cpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Unit tests for mjr::math::str.@EOL
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

#include "MRMathSTR.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_fmt_int, Comprehensive) {

  // Check default args
  EXPECT_EQ(mjr::math::str::fmt_int(10                  ),    "10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4               ),  "  10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4, ' '          ),  "  10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4, ' ', 10      ),  "  10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4, ' ', 10, true),  "  10");

  // dec
  EXPECT_EQ(mjr::math::str::fmt_int(10, 0, ' ', 10, true),  "10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 1, ' ', 10, true),  "10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 2, ' ', 10, true),  "10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 3, ' ', 10, true),  " 10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4, ' ', 10, true),  "  10");

  EXPECT_EQ(mjr::math::str::fmt_int(10, 0, 'X', 10, true),  "10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 1, 'X', 10, true),  "10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 2, 'X', 10, true),  "10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 3, 'X', 10, true),  "X10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4, 'X', 10, true),  "XX10");

  EXPECT_EQ(mjr::math::str::fmt_int(10, 0, ' ', 10, false), "10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 1, ' ', 10, false), "10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 2, ' ', 10, false), "10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 3, ' ', 10, false), "10 ");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4, ' ', 10, false), "10  ");

  EXPECT_EQ(mjr::math::str::fmt_int(10, 0, 'X', 10, false), "10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 1, 'X', 10, false), "10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 2, 'X', 10, false), "10");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 3, 'X', 10, false), "10X");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4, 'X', 10, false), "10XX");

  // hex
  EXPECT_EQ(mjr::math::str::fmt_int(10, 0, ' ', 16, true),  "a");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 1, ' ', 16, true),  "a");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 2, ' ', 16, true),  " a");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 3, ' ', 16, true),  "  a");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4, ' ', 16, true),  "   a");
                                                  
  EXPECT_EQ(mjr::math::str::fmt_int(10, 0, 'X', 16, true),  "a");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 1, 'X', 16, true),  "a");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 2, 'X', 16, true),  "Xa");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 3, 'X', 16, true),  "XXa");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4, 'X', 16, true),  "XXXa");

  EXPECT_EQ(mjr::math::str::fmt_int(10, 0, ' ', 16, false), "a");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 1, ' ', 16, false), "a");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 2, ' ', 16, false), "a ");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 3, ' ', 16, false), "a  ");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4, ' ', 16, false), "a   ");
                                                  
  EXPECT_EQ(mjr::math::str::fmt_int(10, 0, 'X', 16, false), "a");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 1, 'X', 16, false), "a");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 2, 'X', 16, false), "aX");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 3, 'X', 16, false), "aXX");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4, 'X', 16, false), "aXXX");

  // oct
  EXPECT_EQ(mjr::math::str::fmt_int(10, 0, ' ', 8, true),   "12");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 1, ' ', 8, true),   "12");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 2, ' ', 8, true),   "12");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 3, ' ', 8, true),   " 12");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4, ' ', 8, true),   "  12");

  EXPECT_EQ(mjr::math::str::fmt_int(10, 0, 'X', 8, true),   "12");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 1, 'X', 8, true),   "12");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 2, 'X', 8, true),   "12");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 3, 'X', 8, true),   "X12");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4, 'X', 8, true),   "XX12");

  EXPECT_EQ(mjr::math::str::fmt_int(10, 0, ' ', 8, false),  "12");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 1, ' ', 8, false),  "12");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 2, ' ', 8, false),  "12");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 3, ' ', 8, false),  "12 ");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4, ' ', 8, false),  "12  ");

  EXPECT_EQ(mjr::math::str::fmt_int(10, 0, 'X', 8, false),  "12");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 1, 'X', 8, false),  "12");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 2, 'X', 8, false),  "12");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 3, 'X', 8, false),  "12X");
  EXPECT_EQ(mjr::math::str::fmt_int(10, 4, 'X', 8, false),  "12XX");
}
/** @endcond */
