// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      MRMathSTR.hpp
 @author    Mitch Richling http://www.mitchr.me/
 @date      2024-09-12
 @brief     Very simple math stuff very carefully implemented: Formatting & Strings.@EOL
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

#ifndef MJR_INCLUDE_MRMATHSTR

#include <string>                                                        /* C++ strings             C++11    */
#include <sstream>                                                       /* C++ string stream       C++      */
#include <iostream>                                                      /* C++ iostream            C++11    */
#include <iomanip>                                                       /* C++ stream formatting   C++11    */
#include <ios>                                                           /* C++ I/O                 C++      */
#include <concepts>                                                      /* Concepts library        C++20    */

namespace mjr {
  namespace math {
    /** Formatting & Strings.
    */
    namespace str {
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Format an integer as a string.
          If the type of inInt is convertable to an int, then it will be converted to int and will be formated via an std::ostringstream.  If it can't be
          converted, then it will be passed unchanged.
          @par Warning
          For new code I suggest using C++20's std::format.
          @param inInt         The integer to format
          @param width         The width of the string
          @param fill          Fill character
          @param base          An integer (valid values: 16, 10, 8)
          @param rightJustify  If true, then right justify.  Otherwise, left.
          
          @return A formatted string.  */
      template <typename intType>
      requires (std::integral<intType>)
      std::string fmt_int(intType inInt, int width = 0, char fill = ' ', int base = 10, bool rightJustify = true) {
        if constexpr ( !(std::same_as<intType, int>) && std::convertible_to<intType, int>) {
          return fmt_int(static_cast<int>(inInt), width, fill, base, rightJustify);
        } else {
          std::ostringstream stringStream;
          if (width > 0)
            stringStream << std::setfill(fill) << std::setw(width);
          else
            stringStream << std::setfill(fill) << std::setw(0);
          if(rightJustify)
            stringStream << std::right;
          else
            stringStream << std::left;
          if (base == 16)
            stringStream << std::hex << std::noshowbase;
          if (base == 8)
            stringStream << std::oct << std::noshowbase;
          // TODO: Should throw if base is not 8, 10, or 16...
          stringStream << inInt;
          return stringStream.str();
        }
      }
    } // end namespace str
  } // end namespace math
} // end namespace mjr

#define MJR_INCLUDE_MRMATHSTR
#endif
