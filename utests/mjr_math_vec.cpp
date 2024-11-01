// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      mjr_math_vec.cpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Unit tests for mjr::math::vec.@EOL
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

#include "MRMathVEC.hpp"

typedef std::complex<double> cc_t;

typedef std::array<cc_t,   1> c1_t;
typedef std::array<cc_t,   2> c2_t;
typedef std::array<cc_t,   3> c3_t;
typedef std::array<cc_t,   4> c4_t;

typedef std::array<double, 1> r1_t;
typedef std::array<double, 2> r2_t;
typedef std::array<double, 3> r3_t;
typedef std::array<double, 4> r4_t;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(vec1, * boost::unit_test::tolerance(0.00001)) {
  r1_t v1 = {1.1};
  r1_t v2 = {2.2};
  r1_t v3 = {3.3};

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v1)                                                     == 1.21);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v1)                                                        == 1.1);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v1)                                                        == 1.1);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v1)                                                        == 1.1);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v1, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v1, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v2)                                                     == 4.84);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v2)                                                        == 2.2);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v2)                                                        == 2.2);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v2)                                                        == 2.2);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v2, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v2, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v3)                                                     == 10.89);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v3)                                                        == 3.3);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v3)                                                        == 3.3);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v3)                                                        == 3.3);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v3, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v3, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::dot_product(v1, v2)                                              == 2.42);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::sum(v1, v2),                                 r1_t{  3.3 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::diff(v1, v2),                                r1_t{ -1.1 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::diff(v2, v1),                                r1_t{  1.1 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::linear_combination(2.0, v1, 3.0, v2),        r1_t{  8.8 }, 1.0e-5) == true); 

  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v2, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v3, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v2, v3, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v1, 1.0e-5)                                            == true);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v2, v2, 1.0e-5)                                            == true);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v3, v3, 1.0e-5)                                            == true);

  mjr::math::vec::unitize2_destructive(v1, 1.0e-5);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1,                                                           r1_t{ 1.0 }, 1.0e-5) == true);
  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v1)                                                     == 1.0);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v1)                                                        == 1.0);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v1)                                                        == 1.0);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v1)                                                        == 1.0);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v1, 1.0e-5)                                        == 0);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v1, 1.0e-5)                                        == 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(vec2, * boost::unit_test::tolerance(0.00001)) {
  r2_t v1 = {1.1, 2.2};
  r2_t v2 = {3.3, 4.4};
  r2_t v3 = {5.5, 6.6};

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v1)                                                     == 6.05);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v1)                                                        == 2.45967477525);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v1)                                                        == 3.3);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v1)                                                        == 2.2);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v1, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v1, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v2)                                                     == 30.25);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v2)                                                        == 5.5);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v2)                                                        == 7.7);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v2)                                                        == 4.4);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v2, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v2, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v3)                                                     == 73.81);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v3)                                                        == 8.5912746435);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v3)                                                        == 12.1);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v3)                                                        == 6.6);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v3, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v3, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::dot_product(v1, v2)                                              == 13.31);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::sum(v1, v2),                                 r2_t{  4.4,  6.6 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::diff(v1, v2),                                r2_t{ -2.2, -2.2 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::diff(v2, v1),                                r2_t{  2.2,  2.2 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::linear_combination(2.0, v1, 3.0, v2),        r2_t{ 12.1, 17.6 }, 1.0e-5) == true); 

  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v2, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v3, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v2, v3, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v1, 1.0e-5)                                            == true);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v2, v2, 1.0e-5)                                            == true);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v3, v3, 1.0e-5)                                            == true);

  mjr::math::vec::unitize2_destructive(v1, 1.0e-5);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1,                                                           r2_t{ 0.447214, 0.894427 }, 1.0e-5) == true);
  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v1)                                                     == 1);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v1)                                                        == 1);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v1)                                                        == 1.34164);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v1)                                                        == 0.894427);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v1, 1.0e-5)                                        == 0);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v1, 1.0e-5)                                        == 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(vec3, * boost::unit_test::tolerance(0.00001)) {
  r3_t v1 = {1.1,2.2,3.3};
  r3_t v2 = {4.4,5.5,6.6};
  r3_t v3 = {7.7,8.8,9.9};

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v1)                                                     == 16.94);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v1)                                                        == 4.11582312545);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v1)                                                        == 6.6);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v1)                                                        == 3.3);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v1, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v1, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v2)                                                     == 93.17);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v2)                                                        == 9.65246082613);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v2)                                                        == 16.5);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v2)                                                        == 6.6);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v2, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v2, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v3)                                                     == 234.74);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v3)                                                        == 15.3212271049);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v3)                                                        == 26.4);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v3)                                                        == 9.9);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v3, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v3, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::dot_product(v1, v2)                                              == 38.72);
  BOOST_TEST_CHECK(mjr::math::vec::scalar_triple_product(v1, v2, v3)                                == 0.0);
  BOOST_TEST_CHECK(mjr::math::vec::scalar_triple_product(v1, v2, v3)                                == mjr::math::vec::dot_product(v1, mjr::math::vec::cross_product(v2, v3)));
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::sum(v1, v2),                                 r3_t{  5.50,  7.70,  9.90 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::diff(v1, v2),                                r3_t{ -3.30, -3.30, -3.30 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::diff(v2, v1),                                r3_t{  3.30,  3.30,  3.30 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::cross_product(v1, v2),                       r3_t{ -3.63,  7.26, -3.63 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::cross_product(v2, v1),                       r3_t{  3.63, -7.26,  3.63 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::linear_combination(2.0, v1, 3.0, v2),        r3_t{ 15.40, 20.90, 26.40 }, 1.0e-5) == true); 

  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v2, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v3, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v2, v3, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v1, 1.0e-5)                                            == true);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v2, v2, 1.0e-5)                                            == true);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v3, v3, 1.0e-5)                                            == true);

  mjr::math::vec::unitize2_destructive(v1, 1.0e-5);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1,                                                           r3_t{ 0.267261, 0.534522, 0.801784 }, 1.0e-5) == true);
  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v1)                                                     == 1);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v1)                                                        == 1);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v1)                                                        == 1.60357);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v1)                                                        == 0.801784);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v1, 1.0e-5)                                        == 0);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v1, 1.0e-5)                                        == 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(vec3n, * boost::unit_test::tolerance(0.00001)) {
  r3_t v1 = {-1.1,  2.2,  3.3};
  r3_t v2 = { 4.4, -5.5,  6.6};
  r3_t v3 = { 7.7,  8.8, -9.9};

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v1)                                                     == 16.94);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v1)                                                        == 4.11582312545);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v1)                                                        == 6.6);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v1)                                                        == 3.3);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v1, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v1, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v2)                                                     == 93.17);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v2)                                                        == 9.65246082613);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v2)                                                        == 16.5);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v2)                                                        == 6.6);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v2, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v2, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v3)                                                     == 234.74);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v3)                                                        == 15.3212271049);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v3)                                                        == 26.4);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v3)                                                        == 9.9);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v3, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v3, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::dot_product(v1, v2)                                              == 4.84);
  BOOST_TEST_CHECK(mjr::math::vec::scalar_triple_product(v1, v2, v3)                                == 479.16);
  BOOST_TEST_CHECK(mjr::math::vec::scalar_triple_product(v1, v2, v3)                                == mjr::math::vec::dot_product(v1, mjr::math::vec::cross_product(v2, v3)));
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::sum(v1, v2),                                 r3_t{   3.30,  -3.30,  9.90 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::diff(v1, v2),                                r3_t{  -5.50,   7.70, -3.30 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::diff(v2, v1),                                r3_t{   5.50,  -7.70,  3.30 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::cross_product(v1, v2),                       r3_t{  32.67,  21.78, -3.63 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::cross_product(v2, v1),                       r3_t{ -32.67, -21.78,  3.63 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::linear_combination(2.0, v1, 3.0, v2),        r3_t{  11.00, -12.10, 26.40 }, 1.0e-5) == true); 

  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v2, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v3, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v2, v3, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v1, 1.0e-5)                                            == true);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v2, v2, 1.0e-5)                                            == true);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v3, v3, 1.0e-5)                                            == true);

  mjr::math::vec::unitize2_destructive(v1, 1.0e-5);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1,                                                           r3_t{ -0.267261, 0.534522, 0.801784 }, 1.0e-5) == true);
  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v1)                                                     == 1);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v1)                                                        == 1);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v1)                                                        == 1.60357);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v1)                                                        == 0.801784);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v1, 1.0e-5)                                        == 0);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v1, 1.0e-5)                                        == 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(vec3c, * boost::unit_test::tolerance(0.00001)) {
  c3_t v1 = {cc_t(-1.1,  2.2), cc_t(3.3,  4.4), cc_t( 5.5,  6.6)};
  c3_t v2 = {cc_t( 7.7,  8.8), cc_t(9.9, -1.2), cc_t( 2.3,  3.4)};
  c3_t v3 = {cc_t( 4.5,  5.6), cc_t(6.7,  7.8), cc_t(-9.0,  1.4)};
  cc_t s1(2.0, 3.0);
  cc_t s2(4.0, 5.0);

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v1)                                                     == 110.11);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v1)                                                        == 10.4933312156);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v1)                                                        == 16.5509);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v1)                                                        == 8.59127);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v1, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v1, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v2)                                                     == 253.03);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v2)                                                        == 15.9069167346);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v2)                                                        == 25.7705);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v2)                                                        == 11.6932);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v2, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v2, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v3)                                                     == 240.3);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v3)                                                        == 15.5016128193);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v3)                                                        == 26.5748);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v3)                                                        == 10.2825);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v3, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v3, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::fc::near(mjr::math::vec::dot_product(v1, v2),                           cc_t(   0.330,  80.740), 1.0e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near(mjr::math::vec::scalar_triple_product(v1, v2, v3),             cc_t(-896.126, 417.934), 1.0e-5) == true);
  BOOST_TEST_CHECK(mjr::math::fc::near(mjr::math::vec::scalar_triple_product(v1, v2, v3),
                                       mjr::math::vec::dot_product(v1, mjr::math::vec::cross_product(v2, v3)),                 1.0e-5));
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::sum(v1, v2),                                 c3_t{ cc_t(  6.60,  11.0), cc_t(13.20,   3.2), cc_t(  7.80,  10.00) }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::diff(v1, v2),                                c3_t{ cc_t( -8.80,  -6.6), cc_t(-6.60,   5.6), cc_t(  3.20,   3.20) }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::diff(v2, v1),                                c3_t{ cc_t(  8.80,   6.6), cc_t( 6.60,  -5.6), cc_t( -3.20,  -3.20) }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::cross_product(v1, v2),                       c3_t{ cc_t(-69.74, -37.4), cc_t(-5.72,  97.9), cc_t(  5.06, -39.82) }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::cross_product(v2, v1),                       c3_t{ cc_t( 69.74,  37.4), cc_t( 5.72, -97.9), cc_t( -5.06,  39.82) }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::linear_combination(s1, v1, s2, v2),          c3_t{ cc_t( -22.00, 74.8), cc_t(39.00,  63.4), cc_t(-16.60,  54.80) }, 1.0e-5) == true); 

  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v2, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v3, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v2, v3, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v1, 1.0e-5)                                            == true);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v2, v2, 1.0e-5)                                            == true);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v3, v3, 1.0e-5)                                            == true);

  mjr::math::vec::unitize2_destructive(v1, 1.0e-5);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1,                                                           c3_t{ cc_t(-0.104828, 0.209657), cc_t(0.314485, 0.419314), cc_t(0.524142, 0.628971) }, 1.0e-5) == true);
  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v1)                                                     == 1);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v1)                                                        == 1);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v1)                                                        == 1.57728);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v1)                                                        == 0.818737);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v1, 1.0e-5)                                        == 0);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v1, 1.0e-5)                                        == 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_CASE(vec4, * boost::unit_test::tolerance(0.00001)) {
  r4_t v1 = {1.1, 2.2, 3.3, 4.4};
  r4_t v2 = {5.5, 6.6, 7.7, 8.8};
  r4_t v3 = {9.9, 1.2, 2.3, 3.4};

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v1)                                                     == 36.3);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v1)                                                        == 6.02495);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v1)                                                        == 11.0);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v1)                                                        == 4.4);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v1, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v1, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v2)                                                     == 210.54);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v2)                                                        == 14.51);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v2)                                                        == 28.6);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v2)                                                        == 8.8);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v2, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v2, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v3)                                                     == 116.3);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v3)                                                        == 10.7842);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v3)                                                        == 16.8);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v3)                                                        == 9.9);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v3, 1.0e-5)                                        == false);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v3, 1.0e-5)                                        == false);

  BOOST_TEST_CHECK(mjr::math::vec::dot_product(v1, v2)                                              == 84.7);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::sum(v1, v2),                                 r4_t{  6.6,  8.8,  11.0, 13.2 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::diff(v1, v2),                                r4_t{ -4.4, -4.4,  -4.4, -4.4 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::diff(v2, v1),                                r4_t{  4.4,  4.4,   4.4,  4.4 }, 1.0e-5) == true); 
  BOOST_TEST_CHECK(mjr::math::vec::nearI(mjr::math::vec::linear_combination(2.0, v1, 3.0, v2),        r4_t{ 18.7,  24.2, 29.7, 35.2 }, 1.0e-5) == true); 

  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v2, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v3, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v2, v3, 1.0e-5)                                            == false);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1, v1, 1.0e-5)                                            == true);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v2, v2, 1.0e-5)                                            == true);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v3, v3, 1.0e-5)                                            == true);

  mjr::math::vec::unitize2_destructive(v1, 1.0e-5);
  BOOST_TEST_CHECK(mjr::math::vec::nearI(v1,                                                           r4_t{ 0.182574, 0.365148, 0.547723, 0.730297 }, 1.0e-5) == true);
  BOOST_TEST_CHECK(mjr::math::vec::norm2sqr(v1)                                                     == 1);
  BOOST_TEST_CHECK(mjr::math::vec::norm2(v1)                                                        == 1);
  BOOST_TEST_CHECK(mjr::math::vec::norm1(v1)                                                        == 1.82574);
  BOOST_TEST_CHECK(mjr::math::vec::normI(v1)                                                        == 0.730297);
  BOOST_TEST_CHECK(mjr::math::vec::all_near_zero(v1, 1.0e-5)                                        == 0);
  BOOST_TEST_CHECK(mjr::math::vec::any_near_zero(v1, 1.0e-5)                                        == 0);
}

/** @endcond */

