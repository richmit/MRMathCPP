// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      MRMathBPLY.hpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Very simple math stuff very carefully implimented: Polynomials.@EOL
 @copyright
  @parblock
  Copyright (c) 1988-2024, Mitchell Jay Richling <https://www.mitchr.me> All rights reserved.

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

#ifndef MJR_INCLUDE_MRMATHBPLY

#include <cmath>                                                         /* std:: C math.h          C++11    */
#include <numbers>                                                       /* C++ math constants      C++20    */
#include <vector>                                                        /* STL vector              C++11    */ 

// Put everything in the mjr namespace
namespace mjr {
  namespace math {
    namespace bply {
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Return the maximum exponent possible for a bi-variate polynomial stored in a vector of n terms, or a negative value on error.
          @param n Number of terms.
          @return Maximum exponent, or a negative value on error.
          @retval -1 n was too big (>10201)
          @retval -2 n was too small (==0)
          @retval -3 n was not the correct size for a dense bi-variate polynomial */
      int max_pow(std::vector<double>::size_type n) {
        if (n>10201)
          return -1;
        if (n == 0)
          return -2;
        double nsqrt  = std::sqrt(n);
        double nsqrtr = std::round(nsqrt);
        if (std::abs(nsqrtr-nsqrt) > 0.00001)
          return -3;
        return static_cast<int>(nsqrtr)-1;
      } 
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Evaluate a bi-variate polynomial with double coefficients. 
          A polynomial is defined by it's coefficients.  In this function those coefficients are provided in a vector, and are in lexicographic order:
          - 2nd: 00 01 02 10 11 12 20 21 22 -> a00*x^2*y^2 + a01*x^2*y^1 + ... + a21*x^0*y^1 + a22*x^0*y^0
          - 3rd: 00 01 02 03 10 11 12 13 20 21 22 23 30 31 32 33
          @param biPoly The polynomial
          @param x      x value at which to evaluate the polynomial
          @param y      x value at which to evaluate the polynomial
          @return Value of polynomial evaluated at (x, y). */
      double eval(std::vector<double> const& biPoly, double x, double y) {
        int maxPower = max_pow(biPoly.size());
        if (maxPower < 0)
          return -1;  // This is an error.  Probably should throw.
        std::vector<double> xpowers(maxPower+1);
        xpowers[0] = 1;
        std::vector<double> ypowers(maxPower+1);
        ypowers[0] = 1;
        for(int i=1; i<=maxPower; i++) {
          xpowers[i] = x * xpowers[i-1];
          ypowers[i] = y * ypowers[i-1];
        }
        double pvalue = 0;
        std::vector<double>::size_type k=biPoly.size()-1;
        for(int i=0; i<=maxPower; i++) {
          for(int j=0; j<=maxPower; j++) {
            pvalue += biPoly[k] * xpowers[i] * ypowers[j];
            k--;
          }
        }
        return pvalue;
      } 
    } // end namespace bply
  } // end namespace math
} // end namespace mjr

#define MJR_INCLUDE_MRMATHBPLY
#endif
