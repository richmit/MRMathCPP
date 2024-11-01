// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      MRMathIVL.hpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Very simple math stuff very carefully implemented: Numeric Intervals.@EOL
 @copyright
  @parblock
  Copyright (c) 1995-2024, Mitchell Jay Richling <https://www.mitchr.me> All rights reserved.

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

#ifndef MJR_INCLUDE_MRMATHIVL

#include <concepts>                                                      /* Concepts library        C++20    */
#include <cmath>

// Put everything in the mjr namespace
namespace mjr {
  namespace math {
    namespace ivl {
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** Wrap a numbers outside [0, max_out] onto [0, max_out].
          @param in_num       The value to be wrapped
          @param max_out The maximum output value
          @return The wrapped value. */
      template <typename inType, typename maxType>
      requires (std::convertible_to<maxType, inType> && std::integral<inType> && std::integral<maxType>)
      inline inType wrapCC(inType in_num, maxType max_out) {
        inType tmp = static_cast<inType>(static_cast<inType>(max_out) + static_cast<inType>(1));
        return (in_num % tmp + tmp) % tmp;
      }
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** Teplate specialization. */
      template <typename inType, typename maxType>
      requires (std::convertible_to<maxType, inType> && std::floating_point<inType> && std::floating_point<maxType>)
      inline inType wrapCC(inType in_num, maxType max_out) {
        if ((in_num >= static_cast<inType>(0)) && (in_num <= static_cast<inType>(max_out))) { [[likely]]
          return in_num;
        } else {
          return std::fmod(static_cast<inType>(std::fmod(in_num, static_cast<inType>(max_out)) + max_out), static_cast<inType>(max_out));
        }
      }
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** Wrap a floating point value to the range [0, maxValue) via a modulus like function that wraps the value onto the range (i.e. max_out will map to 0).
          Handy way to wrap angles in degrees to [0, 360).
          @param in_num The value to be wrapped
          @param max_out The maximum output value
          @return The wrapped value. */
      template <typename realType>
      inline realType wrapCO(realType in_num, realType max_out) {
        return std::fmod(std::fmod(in_num, max_out) + max_out, max_out);
      }
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** Clamp a number (integer/float) to the range [0,max_out] via a true clamping function.
          Values below the range map to 0 while values above the range map to max_out).
          @param in_num The value to be clamped
          @param max_out The maximum output value
          @return The clamped value. */
      template <typename inType, typename maxType>
      requires (std::convertible_to<maxType, inType> && ( std::integral<inType> || std::floating_point<inType>))
      inline inType clamp(inType in_num, maxType max_out) {
        if(in_num < static_cast<inType>(0))
          return static_cast<inType>(0);
        if(in_num > static_cast<inType>(max_out))
          return static_cast<inType>(max_out);
        return in_num;
      }
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** Clamp a floating point number to the range [0,1].
          Values below the range map to 0 while values above the range map to 1.
          @param in_num The value to be clamped
          @return The clamped value. */
      template <typename realType>
      requires (std::floating_point<realType>)
      inline realType unit_clamp(realType in_num) {
        return clamp(in_num, static_cast<realType>(1));
      }
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** Map a non-negative floating value into the unit interval.
          0 maps to 1 and @f$\infty@f$ maps to 0.  Negative numbers are mapped to themselves -- instead of throwing an error.
          @param x The value to be mapped
          @return The mapped value. */
      template <typename realType>
      requires (std::floating_point<realType>)
      inline realType right_ray_to_unit(realType x) {
        if (x < static_cast<realType>(0))
          return x;
        else
          return static_cast<realType>(1)/(x + static_cast<realType>(1));
      }
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** Teplate specialization. */
      template <typename intType>
      requires (std::convertible_to<intType, double> && std::integral<intType>)
      inline double right_ray_to_unit(intType x) {
        return right_ray_to_unit(static_cast<double>(x));
      }
    }
  }
} // end namespace mjr

#define MJR_INCLUDE_MRMATHIVL
#endif
