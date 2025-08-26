// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      MRMathVEC.hpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Very simple math stuff very carefully implemented: Real & complex vectors using std::array.@EOL
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

#ifndef MJR_INCLUDE_MRMATHVEC

#include <array>                                                         /* array template          C++11    */
#include <cmath>                                                         /* std:: C math.h          C++11    */
#include <concepts>                                                      /* Concepts library        C++20    */
#include <iomanip>                                                       /* C++ stream formatting   C++11    */
#include <ios>                                                           /* C++ I/O                 C++      */
#include <iostream>                                                      /* C++ iostream            C++11    */
#include <sstream>                                                       /* C++ string stream       C++      */
#include <string>                                                        /* C++ strings             C++11    */
#include <type_traits>                                                   /* C++ metaprogramming     C++11    */
#include <vector>                                                        /* STL vector              C++11    */ 
#include <complex>                                                       /* Complex Numbers         C++11    */

#include "MRMathFC.hpp"
#include "MRMathSFUN.hpp"

namespace mjr {
  namespace math {
    /** Mathematical Real/Complex Vectors Stored In std::array Containers.
        The focus of this library is small, fixed size mathematical vectors like might be used to implement things like
          - Coordinates for 2D imaging or vector rendering
          - Points in 3D Euclidean space for geometric modeling & visualization
          - Channels in color space models
    */
    namespace vec {
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Two Norm */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Square of the 2-norm (Euclidean) -- real vectors.
          @param v  A vector*/
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline numType norm2sqr(const std::array<numType, size>& v) {
        numType ret_val = 0;
        for(auto e : v)
          ret_val += e * e;
        return ret_val;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Square of the 2-norm (Euclidean) -- complex vectors.
          @param v  A vector*/
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline numType norm2sqr(std::array<std::complex<numType>, size> v) {
        numType ret_val = 0;
        for(auto e : v)
          ret_val += std::pow(std::abs(e), 2);
        return ret_val;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** 2-norm (Euclidean) -- floating point real vectors.
          BLAS: nrm2
          @param v  A vector*/
      template <typename realType, std::size_t size>
      requires ((size > 0) && std::floating_point<realType>)
      inline realType norm2(const std::array<realType, size>& v) {
        return std::sqrt(norm2sqr(v));
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** 2-norm (Euclidean) -- integer real vectors.
          BLAS: nrm2
          @param v  A vector*/
      template <typename intType, std::size_t size>
      requires ((size > 0) && std::integral<intType>)
      inline intType norm2(const std::array<intType, size>& v) {
        return mjr::math::sfun::isqrt(norm2sqr(v));
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** 2-norm (Euclidean) -- floating point complex vectors.
          BLAS: nrm2
          @param v  A vector*/
      template <typename realType, std::size_t size>
      requires ((size > 0) && std::floating_point<realType>)
      inline realType norm2(std::array<std::complex<realType>, size> v) {
        return std::sqrt(norm2sqr(v));
      }
      //@}
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Infinity Norm */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @f$\infty@f$-norm (maximum absolute value) -- real vectors.
          BLAS: i_amax
          @param v  A vector*/
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline numType normI(const std::array<numType, size>& v) {
        numType ret_val = 0;
        for(auto e : v)
          if (std::abs(e) > ret_val)
            ret_val = std::abs(e);
        return ret_val;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @f$\infty@f$-norm (maximum absolute value) -- complex vectors.
          BLAS: i_amax
          @param v  A vector*/
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline numType normI(const std::array<std::complex<numType>, size>& v) {
        numType ret_val = 0;
        for(auto e : v)
          if (std::abs(e) > ret_val)
            ret_val = std::abs(e);
        return ret_val;
      }
      //@}
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name One Norm */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** The 1-norm (taxi cab, sum of absolute values) -- real vectors.
          BLAS: asum
          @param v  A vector*/
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline numType norm1(const std::array<numType, size>& v) {
        numType ret_val = 0;
        for(auto e : v)
          ret_val += std::abs(e);
        return ret_val;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** The 1-norm (taxi cab, sum of absolute values) -- complex vectors.
          BLAS: asum
          @param v  A vector*/
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline numType norm1(const std::array<std::complex<numType>, size>& v) {
        numType ret_val = 0;
        for(auto e : v)
          ret_val += std::abs(e);
        return ret_val;
      }
      //@}
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Sums & Products */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** The dot product -- real vectors.
          BLAS: dot
          @param v1  A vector
          @param v2  A vector */
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline numType dot_product(const std::array<numType, size>& v1, const std::array<numType, size>& v2) {
        numType ret_val = 0.0;
        for(std::size_t i=0; i<size; ++i)
          ret_val += v1[i]*v2[i];
        return ret_val;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** The dot product -- complex vectors.
          BLAS: dotc
          @param v1  A vector
          @param v2  A vector */
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline std::complex<numType> dot_product(const std::array<std::complex<numType>, size>& v1, const std::array<std::complex<numType>, size>& v2) {
        std::complex<numType> ret_val = 0.0;
        for(std::size_t i=0; i<size; ++i)
          ret_val += v1[i]*std::conj(v2[i]);
        return ret_val;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** The cross product -- real and complex vectors of length 3.
          @param v1  A vector (must be of length 3)
          @param v2  A vector (must be of length 3) */
      template <typename numType, std::size_t size>
      requires (size == 3)
      inline std::array<numType, size> cross_product(const std::array<numType, size>& v1, const std::array<numType, size>& v2) {
        std::array<numType, size> ret_val;
        ret_val[0] = v1[1]*v2[2]-v1[2]*v2[1];
        ret_val[1] = v1[2]*v2[0]-v1[0]*v2[2];
        ret_val[2] = v1[0]*v2[1]-v1[1]*v2[0];
        return ret_val;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** The difference -- real and complex vectors.
          @param v1  A vector
          @param v2  A vector */
      /** Compute the  */
      template <typename numType, std::size_t size>
      requires (size > 0)
      inline std::array<numType, size> diff(const std::array<numType, size>& v1, const std::array<numType, size>& v2) {
        std::array<numType, size> ret_val;
        for(std::size_t i=0; i<size; ++i)
          ret_val[i] = v1[i] - v2[i];
        return ret_val;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** The sum -- real and complex vectors.
          @param v1  A vector
          @param v2  A vector */
      /** Compute the  */
      template <typename numType, std::size_t size>
      requires (size > 0)
      inline std::array<numType, size> sum(const std::array<numType, size>& v1, const std::array<numType, size>& v2) {
        std::array<numType, size> ret_val;
        for(std::size_t i=0; i<size; ++i)
          ret_val[i] = v1[i] + v2[i];
        return ret_val;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** linear combination (s1*v1+s2*v2) -- real vectors.
          BLAS: Combination of axpy & scal
          @param s1  A scalar
          @param v1  A vector
          @param s2  A scalar
          @param v2  A vector */
      template <typename numType, std::size_t size>
      requires (size > 0)
      inline std::array<numType, size> linear_combination(numType s1, const std::array<numType, size>& v1, numType s2, const std::array<numType, size>& v2) {
        std::array<numType, size> ret_val;
        for(std::size_t i=0; i<size; ++i)
          ret_val[i] = s1 * v1[i] + s2 * v2[i];
        return ret_val;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** linear combination (s1*v1+s2*v2+s3*v3) -- real vectors.
          @param s1  A scalar
          @param v1  A vector
          @param s2  A scalar
          @param v2  A vector
          @param s3  A scalar
          @param v3  A vector */
      template <typename numType, std::size_t size>
      requires (size > 0)
      inline std::array<numType, size> linear_combination(numType s1, const std::array<numType, size>& v1, 
                                                          numType s2, const std::array<numType, size>& v2, 
                                                          numType s3, const std::array<numType, size>& v3) {
        std::array<numType, size> ret_val;
        for(std::size_t i=0; i<size; ++i)
          ret_val[i] = s1 * v1[i] + s2 * v2[i] + s3 * v3[i];
        return ret_val;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** linear combination (s1*v1+s2*v2+s3*v3+s4*v4) -- real vectors.
          @param s1  A scalar
          @param v1  A vector
          @param s2  A scalar
          @param v2  A vector
          @param s3  A scalar
          @param v3  A vector
          @param s4  A scalar
          @param v4  A vector */
      template <typename numType, std::size_t size>
      requires (size > 0)
      inline std::array<numType, size> linear_combination(numType s1, const std::array<numType, size>& v1, 
                                                          numType s2, const std::array<numType, size>& v2, 
                                                          numType s3, const std::array<numType, size>& v3, 
                                                          numType s4, const std::array<numType, size>& v4) {
        std::array<numType, size> ret_val;
        for(std::size_t i=0; i<size; ++i)
          ret_val[i] = s1 * v1[i] + s2 * v2[i] + s3 * v3[i] + s4 * v4[i];
        return ret_val;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Multiply vector by scalar -- real or complex vectors.
          BLAS: scal
          @param s  A scalar
          @param v  A vector */
      template <typename numType, std::size_t size>
      requires (size > 0)
      inline std::array<numType, size> scale(numType s, const std::array<numType, size>& v) {
        std::array<numType, size> ret_val;
        for(std::size_t i=0; i<size; ++i)
          ret_val[i] = s * v[i];
        return ret_val;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** The triple product -- real vectors of length 3.
          The triple product is defined as:
          @f[ \vec{v_1}\cdot(\vec{v_2}\times\vec{v_3}) = \text{det}[\vec{v_1}, \vec{v_2}, \vec{v_3}] @f]
          @param v1  A vector (must be of length 3)
          @param v2  A vector (must be of length 3)
          @param v3  A vector (must be of length 3) */
      template <typename numType, std::size_t size>
      requires ((size == 3) && std::is_arithmetic_v<numType>)
      inline numType scalar_triple_product(const std::array<numType, size>& v1, const std::array<numType, size>& v2, const std::array<numType, size>& v3) {
        return (v1[0] * v2[1] * v3[2] -
                v1[0] * v2[2] * v3[1] -
                v1[1] * v2[0] * v3[2] +
                v1[1] * v2[2] * v3[0] +
                v1[2] * v2[0] * v3[1] -
                v1[2] * v2[1] * v3[0]);
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** The scalar quadruple product -- real vectors of length 3.
          The scalar quadruple product is defined as:
          @f[(\vec{v_1}\times\vec{v_2})\cdot(\vec{v_3}\times\vec{v_4})@f]
          @param v1  A vector (must be of length 3)
          @param v2  A vector (must be of length 3)
          @param v3  A vector (must be of length 3)
          @param v4  A vector (must be of length 3) */
      template <typename numType, std::size_t size>
      requires ((size == 3) && std::is_arithmetic_v<numType>)
      inline numType scalar_quadruple_product(const std::array<numType, size>& v1, const std::array<numType, size>& v2,
                                              const std::array<numType, size>& v3, const std::array<numType, size>& v4) {
        return dot_product(cross_product(v1, v2), cross_product(v3, v4));
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** The vector quadruple product -- real vectors of length 3.
          The vector quadruple product is defined as:
          @f[(\vec{v_1}\times\vec{v_2})\times(\vec{v_3}\times\vec{v_4})@f]
          @param v1  A vector (must be of length 3)
          @param v2  A vector (must be of length 3)
          @param v3  A vector (must be of length 3)
          @param v4  A vector (must be of length 3) */
      template <typename numType, std::size_t size>
      requires ((size == 3) && std::is_arithmetic_v<numType>)
      inline std::array<numType, size> vector_quadruple_product(const std::array<numType, size>& v1, const std::array<numType, size>& v2,
                                                                const std::array<numType, size>& v3, const std::array<numType, size>& v4) {
        return cross_product(cross_product(v1, v2), cross_product(v3, v4));
      }
      //@}
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Unitize */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Unitize the given vector in place with the two norm returning true if the result is valid -- real vectors.
          @param v            A vector
          @param zero_epsilon Epsilon to detect zero sign.  See: mjr::math::fc::near_zero() */
      template <typename realType, std::size_t size>
      requires ((size > 0) && std::floating_point<realType>)
      inline bool unitize2_destructive(std::array<realType, size>& v, realType zero_epsilon) {
        realType length = norm2(v);
        if (mjr::math::fc::near_zero(length, zero_epsilon)) {
          return false;
        } else {
          for(std::size_t i=0; i<size; ++i)
            v[i] = v[i] / length;
          return true;
        }
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Unitize the given vector in place with the two norm returning true if the result is valid -- complex vectors.
          @param v            A vector
          @param zero_epsilon Epsilon to detect zero sign.  See: mjr::math::fc::near_zero() */
      template <typename realType, std::size_t size>
      requires ((size > 0) && std::floating_point<realType>)
      inline bool unitize2_destructive(std::array<std::complex<realType>, size>& v, realType zero_epsilon) {
        realType length = norm2(v);
        if (mjr::math::fc::near_zero(length, zero_epsilon)) {
          return false;
        } else {
          for(std::size_t i=0; i<size; ++i)
            v[i] = v[i] / length;
          return true;
        }
      }
      //@}
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Comparisons */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Test if all elements are near zero using mjr::math::fc::near_zero() -- real vectors.
          The "I" in the name indicates the @f$\infty@f$-norm. Also see mjr::math::vec::nearI().
          @param v            A vector
          @param zero_epsilon Epsilon to detect zero sign.  See: mjr::math::fc::near_zero() */
      template <typename realType, std::size_t size>
      requires ((size > 0) && std::floating_point<realType>)
      bool near_zeroI(const std::array<realType, size>& v, realType zero_epsilon) {
        for(auto e : v)
          if ( !(mjr::math::fc::near_zero(e, zero_epsilon)))
            return false;
        return true;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Test if all elements are near zero using mjr::math::fc::near_zero() -- complex vectors.
          The "I" in the name indicates the @f$\infty@f$-norm. Also see mjr::math::vec::nearI().
          @param v            A vector
          @param zero_epsilon Epsilon to detect zero sign.  See: mjr::math::fc::near_zero() */
      template <typename realType, std::size_t size>
      requires ((size > 0) && std::floating_point<realType>)
      inline bool near_zeroI(const std::array<std::complex<realType>, size>& v, realType zero_epsilon) {
        for(auto e : v)
          if ( !(mjr::math::fc::near_zero(e, zero_epsilon)))
            return false;
        return true;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Test if two vectors are close via the @f$\infty@f$-norm using mjr::math::fc::near_zero() -- real vectors.
          @param v1           A vector
          @param v2           A vector
          @param zero_epsilon Epsilon to detect zero sign.  See: mjr::math::fc::near_zero() */
      template <typename realType, std::size_t size>
      requires ((size > 0) && std::floating_point<realType>)
      inline bool nearI(const std::array<realType, size>& v1, const std::array<realType, size>& v2, realType zero_epsilon) {
        for(std::size_t i=0; i<size; ++i)
          if ( !(mjr::math::fc::near(v1[i], v2[i], zero_epsilon)))
            return false;
        return true;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Test if two vectors are close via the @f$\infty@f$-norm using mjr::math::fc::near_zero() -- complex vectors.
          @param v1           A vector
          @param v2           A vector
          @param zero_epsilon Epsilon to detect zero sign.  See: mjr::math::fc::near_zero() */
      template <typename realType, std::size_t size>
      requires ((size > 0) && std::floating_point<realType>)
      inline bool nearI(const std::array<std::complex<realType>, size>& v1, const std::array<std::complex<realType>, size>& v2, realType zero_epsilon) {
        for(std::size_t i=0; i<size; ++i)
          if ( !(mjr::math::fc::near(v1[i], v2[i], zero_epsilon)))
            return false;
        return true;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Are two vectors equal -- real or complex vectors.
          Elements are compared with ==.  This function can be used with floating point numbers, but be careful.
          @param v1  A vector
          @param v2  A vector */
      template <typename numType, std::size_t size>
      requires (size > 0)
      inline bool equal(const std::array<numType, size>& v1, const std::array<numType, size>& v2) {
        for(std::size_t i=0; i<size; ++i)
          if ( !(v1[i] == v2[i]))
            return false;
        return true;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Lexicographic Less Than Predicate -- floating point real vectors.
          @param v1           A vector
          @param v2           A vector 
          @param zero_epsilon Epsilon to detect zero sign.  See: mjr::math::fc::near_zero() */
      template <typename realType, std::size_t size>
      requires ((size > 0) && std::floating_point<realType>)
      inline bool lex_less(const std::array<realType, size>& v1, const std::array<realType, size>& v2, realType zero_epsilon) {
        for(std::size_t i=0; i<size; ++i) {
          if (mjr::math::fc::near(v1[i], v2[i], zero_epsilon)) {
            if (i == size-1) {
              return false;
            }
          } else {
            if (v1[i] < v2[i]) {
              return true;
            } else {
              return false;
            }
          }
        }
        return true; // Can't get here...
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Lexicographic Less Than Predicate -- integer real vectors.
          This function is redundant given std::lexicographical_compare(); however, it makes for a nice uniform interface.
          @param v1  A vector
          @param v2  A vector */
      template <typename intType, std::size_t size>
      requires ((size > 0) && std::integral<intType>)
      inline bool lex_less(std::array<intType, size> v1, std::array<intType, size> v2) {
        for(std::size_t i=0; i<size; ++i)
          if (v1[i] < v2[i]) {
            return true;
          } else {
            if (v1[i] == v2[i]) {
              if (i == size-1) {
                return false;
              }
            } else {
              return false;
            }
          }
        return true; // Can't get here...
      }
      //@}
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Strings */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Convert a vector to a string -- real vectors.
          @param v  A vector*/
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      std::string to_string(const std::array<numType, size>& v) {
        std::ostringstream stringStream;
        stringStream << std::setprecision(6);
        stringStream << std::fixed;
        stringStream << "[ ";
        for(std::size_t i=0; i<size-1; ++i)
          stringStream << v[i] << ", ";
        stringStream << v[size-1] << " ]";
        return stringStream.str();
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Convert a vector to a string -- complex vectors.
          @param v  A vector*/
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      std::string to_string(const std::array<std::complex<numType>, size>& v) {
        std::ostringstream stringStream;
        stringStream << std::setprecision(6);
        stringStream << std::fixed;
        stringStream << "[ ";
        for(std::size_t i=0; i<size-1; ++i)
          stringStream << "(" << std::real(v[i]) << ", " << std::imag(v[i]) << "), ";
        stringStream << "(" << std::real(v[size-1]) << ", " << std::imag(v[size-1]) << ") ]";;
        return stringStream.str();
      }
      //@}
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Distances */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Square of the 2-norm (Euclidean) distance between two vectors -- real vectors.
          @param v1  A vector
          @param v2  A vector */
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline numType dist2sqr(const std::array<numType, size>& v1, const std::array<numType, size>& v2) {
        numType ret_val = 0;
        for(std::size_t i=0; i<size; ++i)
          ret_val += std::pow(v1[i] - v2[i], 2);
        return ret_val;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Square of the 2-norm (Euclidean) distance between two vectors -- complex vectors.
          @param v1  A vector
          @param v2  A vector */
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline numType dist2sqr(const std::array<std::complex<numType>, size>& v1, const std::array<std::complex<numType>, size>& v2) {
        numType ret_val = 0;
        for(std::size_t i=0; i<size; ++i)
          ret_val += std::pow(std::abs(v1[i]-v2[i]), 2);
        return ret_val;
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** The 2-norm (Euclidean) distance between two vectors -- real vectors.
          @param v1  A vector
          @param v2  A vector */
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline numType dist2(const std::array<numType, size>& v1, const std::array<numType, size>& v2) {
        return std::sqrt(dist2sqr(v1, v2));
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** The 2-norm (Euclidean) distance between two vectors -- complex vectors.
          @param v1  A vector
          @param v2  A vector */
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline numType dist2(const std::array<std::complex<numType>, size>& v1, const std::array<std::complex<numType>, size>& v2) {
        return std::sqrt(dist2sqr(v1, v2));
      }
      //@}
    } // end namespace vec
  } // end namespace math
} // end namespace mjr

#define MJR_INCLUDE_MRMATHVEC
#endif
