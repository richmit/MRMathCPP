// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      MRMathFC.hpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Very simple math stuff very carefully implemented: Floating Point Comparisons.@EOL
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

#ifndef MJR_INCLUDE_MRMATHFC

#include <concepts>                                                      /* Concepts library        C++20    */
#include <cstdlib>                                                       /* std:: C stdlib.h        C++11    */
#include <algorithm>                                                     /* STL algorithm           C++11    */
#include <numbers>                                                       /* C++ math constants      C++20    */
#include <complex>                                                       /* Complex Numbers         C++11    */

namespace mjr {
  namespace math {
    /** Real & Complex Floating Point Comparisons.
    */
    namespace fc {
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Zero Comparison */
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Detect if a floating point value is near zero.
          @param x            Value to test.  Must be a floating point type.
          @param zero_epsilon Epsilon to detect zero sign.  Must be the same type as x.
          @return Returns true if @f$\vert x\vert_1=\vert x\vert_2=\vert x\vert_\infty\le\epsilon@f$, otherwise returns false. */
      template <typename realType>
      requires (std::floating_point<realType>)
      inline bool near_zero(realType x, realType zero_epsilon) {
        return ((x <= zero_epsilon) && (x >= -zero_epsilon));
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Detect if a complex floating point value is near zero with regard to the @f$\infty@f$-norm.
          @f$z@f$ is near zero with regard to the @f$\infty@f$-norm if both the real and imaginary parts of @f$z@f$ are near zero.
          @param z            Value to test.  Must be a floating point type.
          @param zero_epsilon Epsilon to detect zero sign.  Must be the same type as z.
          @return Returns true if @f$\vert z\vert_\infty\le\epsilon@f$, otherwise returns false.  */
      template <typename realType>
      requires (std::floating_point<realType>)
      inline bool near_zero(std::complex<realType> z, realType zero_epsilon) {
        return (near_zero(std::real(z), zero_epsilon) && near_zero(std::imag(z), zero_epsilon));
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Detect if a floating point value is not near zero.
          @param x            Value to test.  Must be a floating point type.
          @param zero_epsilon Epsilon to detect zero sign.  Must be the same type as x.
          @return Returns true if @f$\vert x\vert_1=\vert x\vert_2=\vert x\vert_\infty\le\epsilon@f$, otherwise returns false. */
      template <typename realType>
      requires (std::floating_point<realType>)
      inline bool not_near_zero(realType x, realType zero_epsilon) {
        return ((x > zero_epsilon) || (x < -zero_epsilon));
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Detect if a complex floating point value is not near zero with regard to the @f$\infty@f$-norm.
          @f$z@f$ is near zero with regard to the @f$\infty@f$-norm if both the real and imaginary parts of @f$z@f$ are near zero.
          @param z            Value to test.  Must be a floating point type.
          @param zero_epsilon Epsilon to detect zero sign.  Must be the same type as z.
          @return Returns true if @f$\vert z\vert_\infty\le\epsilon@f$, otherwise returns false.  */
      template <typename realType>
      requires (std::floating_point<realType>)
      inline bool not_near_zero(std::complex<realType> z, realType zero_epsilon) {
        return (not_near_zero(std::real(z), zero_epsilon) || not_near_zero(std::imag(z), zero_epsilon));
      }
      //@}
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Non-Zero Comparison */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Detect if two floating point values are near each other.
          In other words make sure @f$x_1-x_2@f$ is near zero -- See: near_zero().
          @param x1           Value to test.  Must be a floating point type.
          @param x2           Value to test.  Must be an integer or floating point type.
          @param zero_epsilon Epsilon to detect zero sign.  Must be the same type as x.
          @return Returns true if @f$\vert x_1-x_2\vert_1=\vert x_1-x_2\vert_2=\vert x_1-x_2\vert_\infty\le\epsilon@f$, otherwise returns false. */
      template <typename realType>
      requires (std::floating_point<realType>)
      inline bool near(realType x1, realType x2, realType zero_epsilon) {
        return near_zero(x1-x2, zero_epsilon);
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Detect if two complex floating point values are near each other with regard to the @f$\infty@f$-norm.
          In other words make sure @f$z_1-z_2@f$ is near zero -- See: near_zero().
          @param z1           Value to test.  Must be a floating point type.
          @param z2           Value to test.  Must be an integer or floating point type.
          @param zero_epsilon Epsilon to detect zero sign.  Must be the same type as x.
          @return Returns true if @f$\vert z_1-z_2\vert_\infty\le\epsilon@f$, otherwise returns false. */
      template <typename realType>
      requires (std::floating_point<realType>)
      inline bool near(std::complex<realType> z1, std::complex<realType> z2, realType zero_epsilon) {
        return near_zero(z1 - z2, zero_epsilon);
      }
      //@}
    } // end namespace fc
  } // end namespace math
} // end namespace mjr

#define MJR_INCLUDE_MRMATHFC
#endif
