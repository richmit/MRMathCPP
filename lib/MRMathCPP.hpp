// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      MRMath.hpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Very simple math stuff very carefully implimented: Everything.@EOL
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
#ifndef MJR_INCLUDE_MRMATH

#include "MRMathLINM.hpp"  // Linear Mappings
#include "MRMathUPLY.hpp"  // Univariate polynomials
#include "MRMathSTR.hpp"   // String functions (formatting)
#include "MRMathBPLY.hpp"  // Bivariate polynomiales
#include "MRMathFC.hpp"    // FLoating point comparison
#include "MRMathODR.hpp"   // Order
#include "MRMathSFUN.hpp"  // Special functions
#include "MRMathIVL.hpp"   // Intervals

// #include "MRMathCPLX.hpp"  // Complex Numbers
// #include "MRMath3VEC.hpp"  // Vectors in R^3 (as Array or Vector)
// #include "MRMathNVEC.hpp"  // Vectors in R^N (as Array or Vector)

#define MJR_INCLUDE_MRMATH
#endif
