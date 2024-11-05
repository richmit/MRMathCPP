// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      mjr_math_linm.cpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Unit tests for mjr::math::linm.@EOL
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

#include "MRMathLINM.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_interpolate, Comprehensive) {
  EXPECT_NEAR(mjr::math::linm::interpolate(1.0,  2.0,  -1.0), 0.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate(1.0,  2.0,   0.0), 1.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate(1.0,  2.0,   0.5), 1.5, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate(1.0,  2.0,   1.0), 2.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate(1.0,  2.0,   2.0), 3.0, 1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::interpolate(2.0,  1.0,  -1.0), 3.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate(2.0,  1.0,   0.0), 2.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate(2.0,  1.0,   0.5), 1.5, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate(2.0,  1.0,   1.0), 1.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate(2.0,  1.0,   2.0), 0.0, 1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::interpolate(1.0f, 2.0f, -1.0f), 0.0f, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate(1.0f, 2.0f,  0.0f), 1.0f, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate(1.0f, 2.0f,  0.5f), 1.5f, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate(1.0f, 2.0f,  1.0f), 2.0f, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate(1.0f, 2.0f,  2.0f), 3.0f, 1.0e-5); 
}

TEST(FN_interpolate_wrapCO, Comprehensive) {
  // This is tested by interpolate_degrees & interpolate_radians
}

TEST(FN_interpolate_degrees, TYP_Double) {

  double vs =   0;
  double ve = 360;
  double vt =  90;
  double vb = 270;
  double vl = 180;
  double ep = 1.0f;

  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(  1.0,   2.0, -1.0), 0.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(  1.0,   2.0,  0.0), 1.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(  1.0,   2.0,  0.5), 1.5, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(  1.0,   2.0,  1.0), 2.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(  1.0,   2.0,  2.0), 3.0, 1.0e-5); 
 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vs+ep, ve-ep,  0.0), vs+ep, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vs+ep, ve-ep,  0.5), vs, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vs+ep, ve-ep,  1.0), ve-ep, 1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vt-ep, vb+ep,  0.0), vt-ep, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vt-ep, vb+ep,  0.5), vs, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vt-ep, vb+ep,  1.0), vb+ep, 1.0e-5); 

  // This one is the ambigious case -- right on the center. I'm choosing the larger value.
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(   vt,    vb,  0.0), vt, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(   vt,    vb,  0.5), vl, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(   vt,    vb,  1.0), vb, 1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vt+ep, vb-ep,  0.0), vt+ep, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vt+ep, vb-ep,  0.5), vl, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vt+ep, vb-ep,  1.0), vb-ep, 1.0e-5); 
}

TEST(FN_interpolate_degrees, TYP_Float) {
  float vs =   0;
  float ve = 360;
  float vt =  90;
  float vb = 270;
  float vl = 180;
  float ep = 1.0f;

  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vs+ep, ve-ep,  0.0f), vs+ep, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vs+ep, ve-ep,  0.5f), vs, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vs+ep, ve-ep,  1.0f), ve-ep, 1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vt-ep, vb+ep,  0.0f), vt-ep, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vt-ep, vb+ep,  0.5f), vs, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vt-ep, vb+ep,  1.0f), vb+ep, 1.0e-5); 

  // This one is the ambigious case -- right on the center. I'm choosing the larger value.
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(   vt,    vb,  0.0f), vt, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(   vt,    vb,  0.5f), vl, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(   vt,    vb,  1.0f), vb, 1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vt+ep, vb-ep,  0.0f), vt+ep, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vt+ep, vb-ep,  0.5f), vl, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_degrees(vt+ep, vb-ep,  1.0f), vb-ep, 1.0e-5); 
}

TEST(FN_interpolate_radians, TYP_Double) {
  double vs = 0.0;
  double ve = std::numbers::pi * 2.0;
  double vt = std::numbers::pi * 0.5;
  double vb = std::numbers::pi * 1.5;
  double vl = std::numbers::pi * 1.0;
  double ep = 0.01;

  EXPECT_NEAR(mjr::math::linm::interpolate_radians(  1.0,   2.0, -1.0), 0.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_radians(  1.0,   2.0,  0.0), 1.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_radians(  1.0,   2.0,  0.5), 1.5, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_radians(  1.0,   2.0,  1.0), 2.0, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_radians(  1.0,   2.0,  2.0), 3.0, 1.0e-5); 
 
  EXPECT_NEAR(mjr::math::linm::interpolate_radians(vs+ep, ve-ep,  0.0), vs+ep, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_radians(vs+ep, ve-ep,  0.5), vs, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_radians(vs+ep, ve-ep,  1.0), ve-ep, 1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::interpolate_radians(vt-ep, vb+ep,  0.0), vt-ep, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_radians(vt-ep, vb+ep,  0.5), vs, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_radians(vt-ep, vb+ep,  1.0), vb+ep, 1.0e-5); 

  // This one is the ambigious case -- right on the center. I'm choosing the larger value.
  EXPECT_NEAR(mjr::math::linm::interpolate_radians(   vt,    vb,  0.0), vt, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_radians(   vt,    vb,  0.5), vl, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_radians(   vt,    vb,  1.0), vb, 1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::interpolate_radians(vt+ep, vb-ep,  0.0), vt+ep, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_radians(vt+ep, vb-ep,  0.5), vl, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::interpolate_radians(vt+ep, vb-ep,  1.0), vb-ep, 1.0e-5); 
}

TEST(FN_scl_int_to_real, Comprehensive) {
  EXPECT_NEAR(mjr::math::linm::scl_int_to_real(  0,  1.0, 255), 0.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::scl_int_to_real(255,  1.0, 255), 1.0,  1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::scl_int_to_real(  0,  1.0, 254), 0.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::scl_int_to_real(127,  1.0, 254), 0.5,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::scl_int_to_real(254,  1.0, 254), 1.0,  1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::scl_int_to_real(  0,  1.5, 255), 0.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::scl_int_to_real(255,  1.5, 255), 1.5,  1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::scl_int_to_real(  0, 1.0f, 255), 0.0f, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::scl_int_to_real(255, 1.0f, 255), 1.0f, 1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::scl_int_to_real(  0L, 1.0, 255), 0.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::scl_int_to_real(255L, 1.0, 255), 1.0,  1.0e-5); 
}

TEST(FN_gen_map, Comprehensive) {
  EXPECT_NEAR(mjr::math::linm::gen_map(0.0, 1.0, 2.0, 1.0, 2.0), 0.0,  1.0e-5);
  EXPECT_NEAR(mjr::math::linm::gen_map(1.0, 1.0, 2.0, 1.0, 2.0), 1.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::gen_map(2.0, 1.0, 2.0, 1.0, 2.0), 2.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::gen_map(3.0, 1.0, 2.0, 1.0, 2.0), 3.0,  1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::gen_map(0.0, 2.0, 3.0, 2.0, 3.0), 0.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::gen_map(1.0, 2.0, 3.0, 2.0, 3.0), 1.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::gen_map(2.0, 2.0, 3.0, 2.0, 3.0), 2.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::gen_map(3.0, 2.0, 3.0, 2.0, 3.0), 3.0,  1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::gen_map(0.0, 3.0, 2.0, 3.0, 2.0), 0.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::gen_map(1.0, 3.0, 2.0, 3.0, 2.0), 1.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::gen_map(2.0, 3.0, 2.0, 3.0, 2.0), 2.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::gen_map(3.0, 3.0, 2.0, 3.0, 2.0), 3.0,  1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::gen_map(0.0, 2.0, 3.0, 4.0, 5.0), 2.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::gen_map(1.0, 2.0, 3.0, 4.0, 5.0), 3.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::gen_map(2.0, 2.0, 3.0, 4.0, 5.0), 4.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::gen_map(3.0, 2.0, 3.0, 4.0, 5.0), 5.0,  1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::gen_map(0.0, 2.0, 3.0, 5.0, 4.0), 7.0,  1.0e-5);
  EXPECT_NEAR(mjr::math::linm::gen_map(1.0, 2.0, 3.0, 5.0, 4.0), 6.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::gen_map(2.0, 2.0, 3.0, 5.0, 4.0), 5.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::gen_map(3.0, 2.0, 3.0, 5.0, 4.0), 4.0,  1.0e-5); 

  EXPECT_NEAR(mjr::math::linm::gen_map(0.0, 1.0, 2.0, 3.0, 6.0), 0.0,  1.0e-5);
  EXPECT_NEAR(mjr::math::linm::gen_map(1.0, 1.0, 2.0, 3.0, 6.0), 3.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::gen_map(2.0, 1.0, 2.0, 3.0, 6.0), 6.0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::gen_map(3.0, 1.0, 2.0, 3.0, 6.0), 9.0,  1.0e-5); 
}

TEST(FN_scl_real_to_int, Comprehensive) {
  EXPECT_NEAR(mjr::math::linm::scl_real_to_int(0.0,  255),  0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::scl_real_to_int(1.0,  255),  255,  1.0e-5); 
                                                                      
  EXPECT_NEAR(mjr::math::linm::scl_real_to_int(0.0,  254),  0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::scl_real_to_int(0.5,  254),  127,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::scl_real_to_int(1.0,  254),  254,  1.0e-5); 
                                                                     
  EXPECT_NEAR(mjr::math::linm::scl_real_to_int(0.0,  255),  0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::scl_real_to_int(1.4,  255),  357,  1.0e-5); 
                                                                     
  EXPECT_NEAR(mjr::math::linm::scl_real_to_int(0.0f, 255),  0,  1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::scl_real_to_int(1.0f, 255),  255,  1.0e-5); 
                                                                    
  EXPECT_NEAR(mjr::math::linm::scl_real_to_int(0.0,  255L), 0L, 1.0e-5); 
  EXPECT_NEAR(mjr::math::linm::scl_real_to_int(1.0,  255L), 255L, 1.0e-5); 
}
/** @endcond */
