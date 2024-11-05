// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      MRMathCPLX.hpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Very simple math stuff very carefully implemented: Complex Numbers.@EOL
 @keywords
 @std       C++20
 @see
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

/*############################################################################################################################################################*/
#ifndef MJR_INCLUDE_MRMATHCPLX

#include <concepts>                                                      /* Concepts library        C++20    */
#include <cstdlib>                                                       /* std:: C stdlib.h        C++11    */
#include <algorithm>                                                     /* STL algorithm           C++11    */
#include <numbers>                                                       /* C++ math constants      C++20    */
#include <complex>

namespace mjr {
  namespace math {
    namespace cplx {
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Change the sign of the real part of a complex number.
          @param z Complex number. */
      template <typename numType>
      requires (std::is_arithmetic_v<numType> && std::is_signed_v<numType>)
      inline std::complex<numType> rconj(std::complex<numType> z) {
        return std::complex<numType>( - std::real(z), std::imag(z) );
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Swap the real and complex parts of a complex number.
          @param z Complex number. */
      template <typename numType>
      requires (std::is_arithmetic_v<numType>)
      inline std::complex<numType> cswap(std::complex<numType> z) {
        return std::complex<numType>( std::imag(z), std::real(z) );
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @f$\infty@f$-norm (maximum absolute value) of a complex number.
          @param z Complex number. */
      template <typename numType>
      requires (std::is_arithmetic_v<numType>)
      inline numType normI(std::complex<numType> z) {
        return std::max(std::abs(std::real(z)), std::abs(std::imag(z)));
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** 1-norm (sum of absolute value) of a complex number.
          @param z Complex number. */
      template <typename numType>
      requires (std::is_arithmetic_v<numType>)
      inline numType norm1(std::complex<numType> z) {
        return (std::abs(std::real(z)) + std::abs(std::imag(z)));
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Sauare of the 2-norm (Euclidean) of a complex number.
          @param z Complex number. */
      template <typename numType>
      requires (std::is_arithmetic_v<numType>)
      inline numType norm2sqr(std::complex<numType> z) {
        return (std::real(z) * std::real(z) + std::imag(z) * std::imag(z));
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Square of 2-norm (Euclidean) distance between two complex numbers.
          @param z1 Complex number. 
          @param z2 Complex number. */
      template <typename numType>
      requires (std::is_arithmetic_v<numType>)
      inline numType dist2sqr(std::complex<numType> z1, std::complex<numType> z2) {
        return norm2sqr(z1-z2);
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** 2-norm (Euclidean) distance between two complex numbers.
          @param z1 Complex number. 
          @param z2 Complex number. */
      template <typename numType>
      requires (std::is_arithmetic_v<numType>)
      inline numType dist2(std::complex<numType> z1, std::complex<numType> z2) {
        return std::abs(z1-z2);
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @f$\infty@f$-norm distance between two complex numbers.
          @param z1 Complex number. 
          @param z2 Complex number. */
      template <typename numType>
      requires (std::is_arithmetic_v<numType>)
      inline numType distI(std::complex<numType> z1, std::complex<numType> z2) {
        return normI(z1-z2);
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** 1-norm distance between two complex numbers.
          @param z1 Complex number. 
          @param z2 Complex number. */
      template <typename numType>
      requires (std::is_arithmetic_v<numType>)
      inline numType dist1(std::complex<numType> z1, std::complex<numType> z2) {
        return norm1(z1-z2);
      }
    } // end namespace cplx
  } // end namespace math
} // end namespace mjr

#define MJR_INCLUDE_MRMATHCPLX
#endif

