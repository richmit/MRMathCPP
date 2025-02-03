// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      MRMathLINM.hpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Very simple math stuff very carefully implemented: One Dimensional Linear Transforms.@EOL
 @copyright
  @parblock
  Copyright (c) 1991-2024, Mitchell Jay Richling <https://www.mitchr.me> All rights reserved.

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

#ifndef MJR_INCLUDE_MRLATHLINM

#include <concepts>                                                      /* Concepts library        C++20    */
#include <cstdlib>                                                       /* std:: C stdlib.h        C++11    */
#include <numbers>                                                       /* C++ math constants      C++20    */

#include "MRMathIVL.hpp"

namespace mjr {
  namespace math {
    /** One Dimensional Linear Transformations.
    */
    namespace linm {
      //@}
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Interpolation */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Linear interpolation between two real values.
          The return is @f$(v_2-v_1)\cdot w+v_1@f$ -- in particular the return is v1 when w is 0.0 and v2 when w is 1.0.
          For interpolation @f$w\in[0,1]@f$.  If w is outside this range, then the result is extrapolation.
          @param v1 First value
          @param v2 Second value
          @param w  weight */
      template <typename realType>
      requires (std::floating_point<realType>)
      inline realType interpolate(realType v1, realType v2, realType w) {
        return (v2 - v1) * w + v1;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Linear interpolation between two real values on a wrapped interval [0, maxv) -- See: mjr::math::ivl::wrapCO & interpolate().
          This is useful for interpolation of angles (degrees, radians) and time.
          @param v1   First angle (in degrees)
          @param v2   Second angle (in degrees)
          @param w    Weight
          @param maxv Interval endpoint */
      template <typename realType>
      requires (std::floating_point<realType>)
      inline realType interpolate_wrapCO(realType v1, realType v2, realType w, realType maxv) {
        v1 = mjr::math::ivl::wrapCO(v1, maxv);
        v2 = mjr::math::ivl::wrapCO(v2, maxv);
        if ((2 * std::abs(v2 - v1)) > maxv) {
          if (v1 < v2)
            v1 += maxv;
          else
            v2 += maxv;
        }
        return mjr::math::ivl::wrapCO(interpolate(v1, v2, w), maxv);
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Linear interpolation between two real values interpreted as angles in degrees -- See: interpolate_wrapCO().
          @param v1 First angle (in degrees)
          @param v2 Second angle (in degrees)
          @param w  weight */
      template <typename realType>
      requires (std::floating_point<realType>)
      inline realType interpolate_degrees(realType v1, realType v2, realType w) {
        return interpolate_wrapCO(v1, v2, w, static_cast<realType>(360.0));
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Linear interpolation between two real values interpreted as angles in radians -- See: interpolate_wrapCO().
          @param v1 First angle (in radians)
          @param v2 Second angle (in radians)
          @param w  weight */
      template <typename realType>
      requires (std::floating_point<realType>)
      inline realType interpolate_radians(realType v1, realType v2, realType w) {
        return interpolate_wrapCO(v1, v2, w, static_cast<realType>(std::numbers::pi * 2.0));
      }
      //@}
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Linear Mapping (Interpolation & Extrapolation) */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Map an integer in the range [0,max_in] onto the range [0,max_out] via a linear mapping function.  
          That is to say, 0 maps to zero, and max_in maps to max_out. Input values outside the allowed input range will be linearly mapped outside of the
          given output range.  To guarantee an output within [0,max_in], then clamp the input values.
          @param x The value to be mapped
          @param max_in The maximum input value (used to compute slope for linear map, not to clamp)
          @param max_out The maximum output value (used to compute slope for linear map, not to clamp) */
      template <typename xType, typename moType, typename miType>
      requires (std::integral<xType> && std::floating_point<moType> && std::integral<miType> && std::convertible_to<miType, moType>)
      inline moType scl_int_to_real(xType x, moType max_out, miType max_in) {
        return (static_cast<moType>(x) * static_cast<moType>(max_out) / static_cast<moType>(max_in));
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Map an floating point type in the unit interval, the range [0,1], onto the integers in the range [0,maxOutValue] via a linear mapping function.
          That is to say, 0.0 maps to 0, and 1.0 maps to maxOutValue. Input values outside the unit interval will be linearly mapped outside of the given
          output range -- i.e. the output is not clamped.
          @param x           The value to be mapped (must be a floating point type)
          @param maxOutValue The maximum output value (must be convertible to the type use for x)
          @return The mapped value. */
      template <typename realType, typename intType>
      requires (std::floating_point<realType> && std::integral<intType> && std::convertible_to<intType, realType>)
      inline intType scl_real_to_int(realType x, intType maxOutValue) {
        return static_cast<intType>(x*static_cast<realType>(maxOutValue));
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Compute equation of a line containing the points @f$(x1, y1)@f$ and @f$(x2, y2)@f$ and return the value of this equation evaluated at @f$x@f$.
          All arithmetic is performed using the type of y1.  If y1 is an integral type, then division is saved till the last operation.
          @param x           Value at which to evaluate linear equation
          @param x1          @f$x@f$ coordinate of first point
          @param x2          @f$x@f$ coordinate of second point (must be the same type as x1 and convertible to the type of y1)
          @param y1          @f$y@f$ coordinate of first point
          @param y2          @f$y@f$ coordinate of second point (must be the same type as y1)
          @return The mapped value. */
      template <typename xType, typename yType>
      requires (std::is_arithmetic<xType>::value && std::is_arithmetic<yType>::value && std::convertible_to<xType, yType>)
      inline yType gen_map(xType x, xType x1, xType x2, yType y1, yType y2) {
        if constexpr (std::integral<yType>) {
          yType yd = y1 - y2;
          yType xd = static_cast<yType>(x1 - x2);
          return static_cast<yType>((static_cast<yType>(x) * yd - yd * static_cast<yType>(x1) + y1 * xd) / xd);  // Delay division till last step.
        } else {
          yType m = (static_cast<yType>(y1) - static_cast<yType>(y2)) / (static_cast<yType>(x1) - static_cast<yType>(x2));
          yType b = static_cast<yType>(y1) - m * static_cast<yType>(x1);
          return static_cast<yType>(m * x + b);
        }
      }
      //@}
    } // end namespace linm
  } // end namespace math
} // end namespace mjr

#define MJR_INCLUDE_MRLATHLINM
#endif
