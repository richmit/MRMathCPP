// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      MRMathODR.hpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Very simple math stuff very carefully implemented: Order.@EOL
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

#ifndef MJR_INCLUDE_MRMATHODR

#include <algorithm>                                                     /* STL algorithm           C++11    */
#include <cmath>                                                         /* std:: C math.h          C++11    */

#include "MRMathCPLX.hpp"

namespace mjr {
  namespace math {
    /** Numeric Order Functions (max/min & abs_max/abs_min).
    */
    namespace odr {
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Two Items */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Value with minimum absolute value (real or complex).
          @param x1 First number.  Must be an integer or floating point type.
          @param x2 Second number.  Must be the same type as x1.
          @return Value with minimum absolute value. */
      template <typename numType>
      requires(std::is_signed_v<numType> || mjr::math::cplx::is_complex<numType>::value)
      inline numType abs_min2(numType x1, numType x2) {
        if (std::abs(x1) < std::abs(x2))
            return x1;
           else
            return x2;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Value with maximum absolute value (real or complex).
          @param x1 First number.  Must be an integer or floating point type.
          @param x2 Second number.  Must be the same type as x1.
          @return Value with maximum absolute value. */
      template <typename numType>
      requires(std::is_signed_v<numType> || mjr::math::cplx::is_complex<numType>::value)
      inline numType abs_max2(numType x1, numType x2) {
        if (std::abs(x1) < std::abs(x2))
            return x2;
           else
            return x1;
      }
      //@}
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Three Items */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Minimum of three numbers.
          @param x1 First number.  Must be an integer or floating point type.
          @param x2 Second number.  Must be the same type as x1.
          @param x3 Third number.  Must be the same type as x1.
          @return Minimum of input values. */
      template <typename numType>
      inline numType min3(numType x1, numType x2, numType x3) {
        if (x1 < x2) {   // opts: x1 or x3  (x1<x2)
          if (x1 < x3) {    // opts: X1        (x3>x1<x2)
            return x1;
          } else {          // opts: X3        (x3<=x1<x2)
            return x3;
          }
        } else {         // opts: X2 or X3  (x1>=x2)
          if (x2 < x3) {    // opts: X2        (x1>=x2<x3)
            return x2;
          } else {          // opts: X3        (x1>=x2>=x3)
            return x3;
          }
        }
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Maximum of three numbers.
          @param x1 First number.  Must be an integer or floating point type.
          @param x2 Second number.  Must be the same type as x1.
          @param x3 Third number.  Must be the same type as x1.
          @return Maximum of input values. */
      template <typename numType>
      inline numType max3(numType x1, numType x2, numType x3) {
        if (x2 < x1) {   // opts: x1 or x3
          if (x3 < x1) {    // opts: X1
            return x1;
          } else {          // opts: X3
            return x3;
          }
        } else {         // opts: X2 or X3
          if (x3 < x2) {    // opts: X2
            return x2;
          } else {          // opts: X3
            return x3;
          }
        }
      }
      //@}
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Four Items */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Minimum of four numbers.
          @param x1 First number.  Must be an integer or floating point type.
          @param x2 Second number.  Must be the same type as x1.
          @param x3 Third number.  Must be the same type as x1.
          @param x4 Fourth number.  Must be the same type as x1.
          @return Minimum of input values. */
      template <typename numType>
      inline numType min4(numType x1, numType x2, numType x3, numType x4) {
        if (x3 < x4) // opts: X1, X2, X3
          return min3(x1, x2, x3);
        else // opts: X1, X2, X4
          return min3(x1, x2, x4);
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Maximum of four numbers.
          @param x1 First number.  Must be an integer or floating point type.
          @param x2 Second number.  Must be the same type as x1.
          @param x3 Third number.  Must be the same type as x1.
          @param x4 Fourth number.  Must be the same type as x1.
          @return Maximum of input values. */
      template <typename numType>
      inline numType max4(numType x1, numType x2, numType x3, numType x4) {
        if (x3 > x4) // opts: X1, X2, X3
          return max3(x1, x2, x3);
        else // opts: X1, X2, X4
          return max3(x1, x2, x4);
      }
      //@}
    } // end namespace odr
  } // end namespace math
} // end namespace mjr

#define MJR_INCLUDE_MRMATHODR
#endif



