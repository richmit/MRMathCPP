// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      MRMathESGN.hpp
 @author    Mitch Richling http://www.mitchr.me/
 @date      2025-02-01
 @brief     Enumerated Signs for SDF Function Tests.@EOL
 @std       C++23
 @copyright 
  @parblock
  Copyright (c) 2025, Mitchell Jay Richling <http://www.mitchr.me/> All rights reserved.
  
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
 @filedetails   

  Using signed distance functions on cells leads to several classical questions that all boil down to the signs of the SDF on the cell vertexes.

    - Containment Questions:  
      - The "boundary Containment" question: Is the cell contained in the SDF zero boundary?  
        Are all of the values in the list zero? 
      - The "Interior Containment" question: Is part of the cell completely contained in the SDF interior (where the SDF is positive)?
        Are all the values positive?
      - The "Exterior Containment" question: Is part of the cell completely contained in the SDF exterior (where the SDF is negative)?
        Are all the values negative?
    - Intersection Questions: 
      By "intersection" we mean "not-empty or non-trivial intersection".  That is to say we we use the word like: "do A and B intersect?".
      - The "boundary intersection" question: Is the intersection of the cell and the SDF zero boundary non-empty?  
        Are any of the values zero, or do any of them differ?
        See: mjr::math::esgn::zero_or_change()
      - The "Interior intersection" question: Is part of the cell completely contained in the SDF interior (where the SDF is positive)?
        Are any of the values positive?
      - The "Exterior intersection" question: Is part of the cell completely contained in the SDF exterior (where the SDF is negative)?
        Are any of the values negative?
      - The "boundary crossing" question: Does the cell simultaneously intersection both the interior and exterior of the SDF?
        Do any of the non-zero values in the list differ? _or_ Does the list contain both positive and negative values?
        See: mjr::math::esgn::non_zero_change()

  Of these questions, most can be answered by using std::all_of and std::any_of.  The exceptions being the "boundary crossing" and "boundary intersection"
  questions.  This header provides a fast way to answer these two questions using an enum to encode positive, negative, and zero values to positive integer
  values.  The encoding transforms some of thees questions into simple bit manipulation operations making them quite fast.

  Alternate test statements may be formed in terms of the number of zero, positive, or negative signs on the cell vertexes.  This methodology is sometimes
  called the "sum signs methodology".  Normally these sums are formed using an array indexed by 1+sgn(v) -- which is a pretty fast way to do it.  This header
  provides for this methodology with the mjr::math::esgn::count_signs() function.

  Finally this library provides drop in replacements for mjr::math::sfun::sgn() and mjr::math::sfun::sgne().

*/
/*******************************************************************************************************************************************************.H.E.**/

#ifndef MJR_INCLUDE_MRMATHESGN

#include <cstdint>                                                       /* std:: C stdint.h        C++11    */
#include <utility>                                                       /* STL Misc Utilities      C++11    */
#include <vector>                                                        /* STL vector              C++11    */ 
#include <numeric>                                                       /* C++ numeric             C++11    */
#include <array>

#include "MRMathFC.hpp"

namespace mjr {
  namespace math {
    /** Enumerated Signs for SDF Function Tests.
    */
    namespace esgn {

      //========================================================================================================================================================
      /** @name Types For esgn */
      //@{

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Enum to represent a sign.
          Careful selection of underlying integer values for the signs allows for optimization of common SDF questions. */
      enum class signT : uint_fast8_t { esZero = 0, //!< Zero.
                                        esPos  = 1, //!< Positive.
                                        esNeg  = 2  //!< Negative.
                                      };

      //@}

      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Boundry Intersection */
      //@{

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Return true if one or more values are zero or if any of the values differ.
          @param s1 First value
          @param s2 Second value
          @return Boolean true if one or more values are zero or if any of the values differ. */
      bool zero_or_change(signT s1, signT s2)                               { return (0 == (std::to_underlying(s1) & std::to_underlying(s2)));                                                                            } // Segment

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      bool zero_or_change(signT s1, signT s2, signT s3)                     { return (0 == (std::to_underlying(s1) & std::to_underlying(s2) & std::to_underlying(s3)));                                                   } // Triangle

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      bool zero_or_change(signT s1, signT s2, signT s3, signT s4)           { return (0 == (std::to_underlying(s1) & std::to_underlying(s2) & std::to_underlying(s3) & std::to_underlying(s4)));                          } // Quad, 2D Pixel, or Tetrahedron

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      bool zero_or_change(signT s1, signT s2, signT s3, signT s4, signT s5) { return (0 == (std::to_underlying(s1) & std::to_underlying(s2) & std::to_underlying(s3) & std::to_underlying(s4) & std::to_underlying(s5))); } // Rectangular Pyramid

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      template< class InputIt>
      inline bool zero_or_change(InputIt first, InputIt last) {
        std::underlying_type_t<signT> acc = 3;
        for(auto p=first; p!=last; ++p) {
          acc &= std::to_underlying(*p);
          if (acc == 0)
            return true;
        }
        return false;
      }

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      inline bool zero_or_change(std::vector<signT> v) {
        std::underlying_type_t<signT> acc = std::to_underlying(v[0]);
        if (acc == 0) {
          return true;
        } else {
          for(auto e : v) {
            acc &= std::to_underlying(e);
            if (acc == 0)
              return true;
          }
          return false;
        }
      }

      //@}

      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Boundary Crossing */
      //@{

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Return true if there exist a pair of non-zero values that differ.
          @param s1 First value
          @param s2 Second value
          @return Boolean true if there exist a pair of non-zero values that differ. */
      bool non_zero_change(signT s1, signT s2)                               { return(3 == (std::to_underlying(s1) | std::to_underlying(s2)));                                                                            } // Segment

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      bool non_zero_change(signT s1, signT s2, signT s3)                     { return(3 == (std::to_underlying(s1) | std::to_underlying(s2) | std::to_underlying(s3)));                                                   } // Triangle

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      bool non_zero_change(signT s1, signT s2, signT s3, signT s4)           { return(3 == (std::to_underlying(s1) | std::to_underlying(s2) | std::to_underlying(s3) | std::to_underlying(s4)));                          } // Quad or Tetrahedron

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      bool non_zero_change(signT s1, signT s2, signT s3, signT s4, signT s5) { return(3 == (std::to_underlying(s1) | std::to_underlying(s2) | std::to_underlying(s3) | std::to_underlying(s4) | std::to_underlying(s5))); } // Rectangular Pyramid

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      template< class InputIt>
      inline bool non_zero_change(InputIt first, InputIt last) {
        std::underlying_type_t<signT> acc = 0;
        for(auto p=first; p!=last; ++p) {
          acc |= std::to_underlying(*p);
          if (acc == 3)
            return true;
        }
        return false;
      }

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      inline bool non_zero_change(std::vector<signT> v) { return (non_zero_change(v.cbegin(), v.cend())); }

      //@}

      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Counting Signs */
      //@{

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Return an std::array<int, 3> of sign counts (element 0: number of zeros, element 1: number of positives, and element 2: number of negatives).

          @param s1 First value
          @return Boolean true if there exist a pair of non-zero values that differ. */
      inline std::array<int, 3> count_signs(signT s1) {
        std::array<int, 3> counts { 0, 0, 0 };
        counts[std::to_underlying(s1)]++;
        return (counts);
      }

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      inline std::array<int, 3> count_signs(signT s1, signT s2) {
        std::array<int, 3> counts { 0, 0, 0 };
        counts[std::to_underlying(s1)]++;
        counts[std::to_underlying(s2)]++;
        return (counts);
      }

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      inline std::array<int, 3> count_signs(signT s1, signT s2, signT s3) {
        std::array<int, 3> counts { 0, 0, 0 };
        counts[std::to_underlying(s1)]++;
        counts[std::to_underlying(s2)]++;
        counts[std::to_underlying(s3)]++;
        return (counts);
      }

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      inline std::array<int, 3> count_signs(signT s1, signT s2, signT s3, signT s4) {
        std::array<int, 3> counts { 0, 0, 0 };
        counts[std::to_underlying(s1)]++;
        counts[std::to_underlying(s2)]++;
        counts[std::to_underlying(s3)]++;
        counts[std::to_underlying(s4)]++;
        return (counts);
      }

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      inline std::array<int, 3> count_signs(signT s1, signT s2, signT s3, signT s4, signT s5) {
        std::array<int, 3> counts { 0, 0, 0 };
        counts[std::to_underlying(s1)]++;
        counts[std::to_underlying(s2)]++;
        counts[std::to_underlying(s3)]++;
        counts[std::to_underlying(s4)]++;
        counts[std::to_underlying(s5)]++;
        return (counts);
      }

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      template< class InputIt>
      inline std::array<int, 3> count_signs(InputIt first, InputIt last) {
        std::array<int, 3> counts { 0, 0, 0 };
        for(auto p=first; p!=last; ++p) 
          counts[std::to_underlying(*p)]++;
        return (counts);
      }

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** @overload */
      inline std::array<int, 3> count_signs(std::vector<signT> v) { return (count_signs(v.cbegin(), v.cend())); }

      //@}

      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Sign Functions */
      //@{

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Signum (sgn, sign) function that returns a signT value.  See: mjr::math::sfun::sgn().
          @param x Input value.  Must be an integer or floating point type. */
      template <typename numType>
      requires (std::integral<numType> || std::floating_point<numType>)
      inline signT sgn(numType x) {
        if (x > static_cast<numType>(0))
          return signT::esPos;
        else if (x < static_cast<numType>(0))
          return signT::esNeg;
        else
          return signT::esZero;
      }

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Signum with zero epsilon check that returns a signT value.  See: See: mjr::math::sfun::sgne().
          @param x            Input value.  Must be an integer or floating point type.
          @param zero_epsilon Epsilion to detect zero.  Must be the saem type as x. See: mjr::math::fc::near_zero(). */
      template <typename numType>
      requires (std::floating_point<numType>)
      inline signT sgne(numType x, numType zero_epsilon) {
        if (mjr::math::fc::near_zero(x, zero_epsilon)) {
          return signT::esZero;
        } else {
          if (x > numType(0))
            return signT::esPos;
          else
            return signT::esNeg;
        }
      }

      //@}

      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name Sign Conversions */
      //@{

      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Map -1, 0, and 1 to signT::esNeg, signT::esZero, signT::esPos restpectively.
          @param x Input value to map.  Must be a signed integer type. */
      template <typename intType>
      requires (std::signed_integral<intType>) 
      inline signT sign2encSgnENum(intType x) { return sgn(x); }

      //@}

    } // end namespace esn
  } // end namespace math
} // end namespace mjr

#define MJR_INCLUDE_MRMATHESGN
#endif


// ((s1 == 0) || (s2 == 0)             || (s1 != s2))
// ((s1 == 0) || (s2 == 0) || s3 == 0) || (s1 != s2) || (s1 != s3))

// A&B == 0 <=> some are zero or some differ
//      00 01 10
// 00   00 00 00
// 01   00 01 00
// 10   00 00 10


// A|B == 11 <=> some non-zero differ
//      00 01 10
// 00   00 01 10
// 01   01 01 11
// 10   10 11 10

