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

#include <type_traits>                                                   /* C++ metaprogramming     C++11    */
#include <cmath>                                                         /* std:: C math.h          C++11    */
#include <numbers>                                                       /* C++ math constants      C++20    */
#include <algorithm>                                                     /* STL algorithm           C++11    */
#include <vector>                                                        /* STL vector              C++11    */ 

namespace mjr {
  namespace math {
    /** Univariate polynomials.
    */
    namespace uply {
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Evaluate a uni-variate polynomial with double coefficients.
          A polynomial is defined by it's coefficients.  In this function those coefficients are provided in a vector, and are ordered from lowest degree
          to highest (such that the index of the coefficient is equal to the degree of the term):
          @f[a_0+a_1x+a_2x^2+...+a_nx^n@f]
          @param uniPoly The polynomial
          @param x       x value at which to evaluate the polynomial */
      inline double eval(std::vector<double> const& uniPoly, double x) {
        if (uniPoly.empty()) {
          return 0;
        } else {
          double pvalue = uniPoly[0];
          for (std::vector<double>::size_type i=1; i<uniPoly.size(); i++)
            pvalue = pvalue * x + uniPoly[i];
          return pvalue;
        }
      }
    } // end namespace uply
  } // end namespace math
} // end namespace mjr

#define MJR_INCLUDE_MRMATHUPLY
#endif
