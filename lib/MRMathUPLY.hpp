// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      MRMathUPLY.hpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Very simple math stuff very carefully implemented: Polynomials.@EOL
 @copyright
  @parblock
  Copyright (c) 1993-2024, Mitchell Jay Richling <https://www.mitchr.me> All rights reserved.

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

#ifndef MJR_INCLUDE_MRMATHUPLY

#include <array>                                                         /* array template          C++11    */
#include <type_traits>                                                   /* C++ metaprogramming     C++11    */
#include <cmath>                                                         /* std:: C math.h          C++11    */
#include <numbers>                                                       /* C++ math constants      C++20    */
#include <algorithm>                                                     /* STL algorithm           C++11    */
#include <vector>                                                        /* STL vector              C++11    */ 
#include <type_traits>                                                   /* C++ metaprogramming     C++11    */

#include "MRMathCPLX.hpp"

namespace mjr {
  namespace math {
    /** Univariate real/complex polynomials.
        A polynomial is defined by it's coefficients.  In this function those coefficients are provided in a vector, and are ordered from highest degree
        to lowest:
        @f[a_0x^n+a_1x^{n-1}+\cdots+a_{n-1}x+a_n@f]
    */
    namespace uply {
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Evaluate a polynomial.
          @param poly The polynomial
          @param x    x value at which to evaluate the polynomial */
      template <typename numType>
      requires (std::is_arithmetic_v<numType> || mjr::math::cplx::is_complex<numType>::value)
      inline numType eval(std::vector<numType> const& poly, numType x) {
        if (poly.empty()) {
          return 0;
        } else {
          numType pvalue = poly[0];
          for (typename std::vector<numType>::size_type i=1; i<poly.size(); i++)
            pvalue = pvalue * x + poly[i];
          return pvalue;
        }
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Evaluate a polynomial and its derivatives.
         Reference:
           - W. Pankiewicz (1968); Algorithm 337: calculation of a polynomial and its derivative values by Horner scheme; Communications of the ACM; Vol 11, Issue 9, pp 633; zotero://select/items/0_N73T5N2S      
          @param poly The polynomial
          @param x    x value at which to evaluate the polynomial 
          @param v   Polynomial value and derivative values.  Number of derivatives is determined by size of v.
      */
      template <typename numType, std::size_t size>
      requires ((size > 0) && (std::is_arithmetic_v<numType> || mjr::math::cplx::is_complex<numType>::value))
      inline void evald(std::vector<numType> const& poly, numType x, std::array<numType, size>& v) {
        int deg = static_cast<int>(poly.size()) - 1;
        int order = static_cast<int>(size) - 1;
        for(int i=0; i<=order; i++)
          v[i] = 0;
        if (deg > 0) {
          v[0] = poly[0];
          if constexpr (size > 1) 
            for(int i = 1; i<=order; i++)
              v[i] = 0;
          for(int i = deg-1; i>=0; i--) {
            int nnd = std::min(order, deg - i);
            for(int j=nnd; j>0; j--) 
              v[j] = x * v[j] + v[j - 1];
            v[0] = x * v[0] + poly[deg - i];
          }
          numType c = 1;
          for(int i=2; i<=order; i++) {
            if constexpr (mjr::math::cplx::is_complex<numType>::value) {
              c = numType(i, 0) * c;
            } else {
              c = i * c;
            }
            v[i] = c * v[i];
          }
        }
      }
    } // end namespace uply
  } // end namespace math
} // end namespace mjr

#define MJR_INCLUDE_MRMATHUPLY
#endif
