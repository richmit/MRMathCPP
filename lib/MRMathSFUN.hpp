// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      MRMathSFUN.hpp
 @author    Mitch Richling http://www.mitchr.me/
 @date      2024-09-12
 @brief     Very simple math stuff very carefully implemented: Special Functions.@EOL
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

#ifndef MJR_INCLUDE_MRMATHSFUN

#include <concepts>                                                      /* Concepts library        C++20    */

#include "MRMathFC.hpp"

namespace mjr {
  namespace math {
    /** Simple Functions.
    */
    namespace sfun {
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Signs */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Signum (sgn, sign) function.
          The Signum function is defined as follows:
          @f[ \mathrm{sgn}(x)=
                \begin{cases}
                    -1           & \text{if } x<0 \\
                    \phantom{-}0 & \text{if } x=0 \\
                    \phantom{-}1 & \text{if } x>0
                \end{cases} @f]
          @param x        Input value.  Must be an integer or floating point type. */
      template <typename numType>
      requires (std::integral<numType> || std::floating_point<numType>)
      inline int
      sgn(numType x) {
        if (x > numType(0)) return  1;
        if (x < numType(0)) return -1;
        return 0;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Signum with zero epsilon check.
          This function is used if we want to make sure a non-zero sign is only returned if the input value is larger than some epsilon.  i.e. we don't want tiny
          values near zero to show up as positive or negative.  More formally the function is defined as follows:
          @f[ \mathrm{sgne}(x)=
                \begin{cases}
                    0               & \text{if } \vert x\vert<\epsilon \\
                    \mathrm{sgn}(x) & \text{otherwise}
                \end{cases} @f]
          @param x            Input value.  Must be an integer or floating point type.
          @param zero_epsilon Epsilion to detect zero.  Must be the saem type as x. See: mjr::math::fc::near_zero(). */
      template <typename numType>
      requires (std::floating_point<numType>)
      inline int
      sgne(numType x, numType zero_epsilon) {
        if (mjr::math::fc::near_zero(x, zero_epsilon)) {
          return 0;
        } else {
          if (x > numType(0))
            return 1;
          else
            return -1;
        }
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Heaviside function.
          Similar to mjr::math::sfun::sgn() except:
            - Result type is that of the input type
            - Zero when x<0
            - Return when x=0 is programmable (a template argument).
          @f[ \mathrm{heaviside}(x)=
                \begin{cases}
                    0                  & \text{if } x<0 \\
                    \text{valueAtZero} & \text{if } x=0 \\
                    1                  & \text{if } x>0
                \end{cases} @f]
          @tparam valueAtZero The value to return for x=0
          @param x            Input value.  Must be an integer or floating point type. */
      template <typename numType, numType valueAtZero=static_cast<numType>(0)>
      requires (std::integral<numType> || std::floating_point<numType>)
      inline numType
      heaviside(numType x) {
        if (x < numType(0)) return static_cast<numType>(0);
        if (x > numType(0)) return static_cast<numType>(1);
        return valueAtZero;
      }
      //@}
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Integer Functions */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Integer square root.
          @f[ \text{isqrt}(x)= \text{floor}(\sqrt{x}) @f]
          @par WARNING
          This implementation is not particularly good -- kinda a hack really.
          @param x  A non-negative integer */
      template <typename intType>
      requires (std::integral<intType>)
      inline intType isqrt(intType x) {
        return static_cast<intType>(std::floor(std::sqrt(x)));
      }
      //@}
    } // end namespace sfun
  } // end namespace math
} // end namespace mjr

#define MJR_INCLUDE_MRMATHSFUN
#endif
