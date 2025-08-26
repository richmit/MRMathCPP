// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      MRMathODE.hpp
 @author    Mitch Richling http://www.mitchr.me/
 @brief     Very simple math stuff very carefully implemented: ODE IVP Solvers.@EOL
 @copyright
  @parblock
  Copyright (c) 1993-2024, Mitchell Jay Richling <https://www.mitchr.me> All rights reserved.

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

#ifndef MJR_INCLUDE_MRMATHODE

#include <array>                                                         /* array template          C++11    */
#include <type_traits>                                                   /* C++ metaprogramming     C++11    */
#include <cmath>                                                         /* std:: C math.h          C++11    */
#include <numbers>                                                       /* C++ math constants      C++20    */
#include <algorithm>                                                     /* STL algorithm           C++11    */
#include <vector>                                                        /* STL vector              C++11    */ 
#include <type_traits>                                                   /* C++ metaprogramming     C++11    */

#include "MRMathVEC.hpp"

namespace mjr {
  namespace math {
    /** Explicit Runge-Kutta Methods.
    */
    namespace ode {
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name DEQ Types */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      /** Autonomous DEQ. */
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      using deqnt_t = std::function<std::array<numType, size>(std::array<numType, size> const&)>;
      /** Nonautonomous DEQ. */
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      using deqwt_t = std::function<std::array<numType, size>(numType, std::array<numType, size> const&)>;
      //@}
      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      /** @name ODE Solvers */ 
      //@{
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      // SS-BEGIN:rk1_t:
      /** Euler's Method.
          Reutrns delta y.
          @param t       Initial Condition
          @param y       Initial Condition
          @param deq     ODE derivative function
          @param t_delta Step size
          @par References:
          - Euler (1768); Institutionum Calculi Integralis. Volumen Primum, Opera Omnia, Vol XI. p424
          - Hairer, Norsett & Wanner (2009). Solving Ordinary Differential Equations. I: Nonstiff Problems. p35"
          - Butcher (2016); Numerical Methods for Ordinary Differential Equations. 3rd Ed; Wiley; p98 */
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline std::array<numType, size> rk1(numType t, std::array<numType, size> const& y, deqwt_t<numType, size> deq, numType t_delta) {
        return mjr::math::vec::scale(t_delta, deq(t, y));
      }
      // SS-END:rk1_t:
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      // SHELLO: sed -n '/SS-BEGIN:rk1_t:$/,/SS-END:rk1_t:$/p' MRMathODE.hpp | sed -E 's/(rk1|deq)\([^,]+, */\1(/g; /SS-/d; /@param t /d; s/deqwt_t/deqnt_t/'
      /** Euler's Method.
          Reutrns delta y.
          @param y       Initial Condition
          @param deq     ODE derivative function
          @param t_delta Step size
          @par References:
          - Euler (1768); Institutionum Calculi Integralis. Volumen Primum, Opera Omnia, Vol XI. p424
          - Hairer, Norsett & Wanner (2009). Solving Ordinary Differential Equations. I: Nonstiff Problems. p35"
          - Butcher (2016); Numerical Methods for Ordinary Differential Equations. 3rd Ed; Wiley; p98 */
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline std::array<numType, size> rk1(std::array<numType, size> const& y, deqnt_t<numType, size> deq, numType t_delta) {
        return mjr::math::vec::scale(t_delta, deq(y));
      }
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      // SS-BEGIN:rk4_t:
      /** The classic 4th order Runge-Kutta Method.
          Reutrns delta y.
          @param t       Initial Condition
          @param y       Initial Condition
          @param deq     ODE derivative function
          @param t_delta Step size 
          @par References:
           - Kutta (1901); Beitrag Zur N\"herungsweisen Integration Totaler Differentialgleichungen; Z. Math. Phys. 46; p435-53
           - Hairer, Norsett & Wanner (2009). Solving Ordinary Differential Equations. I: Nonstiff Problems. p138
           - Butcher (2016); Numerical Methods for Ordinary Differential Equations. 3rd Ed; Wiley; p102 */
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline std::array<numType, size> rk4(numType t, std::array<numType, size> const& y, deqwt_t<numType, size> deq, numType t_delta) {
        numType tmp_t_delta;
        std::array<numType, size> tmp_y_delta;
        std::array<numType, size> k1 = deq(t, y);
        tmp_t_delta = t_delta/2;
        tmp_y_delta = mjr::math::vec::scale(tmp_t_delta, k1);
        std::array<numType, size> k2 = deq(t + tmp_t_delta, mjr::math::vec::sum(y, tmp_y_delta));
        tmp_y_delta = mjr::math::vec::scale(tmp_t_delta, k2);
        std::array<numType, size> k3 = deq(t + tmp_t_delta, mjr::math::vec::sum(y, tmp_y_delta));
        tmp_y_delta = mjr::math::vec::scale(t_delta, k3);
        std::array<numType, size> k4 = deq(t + t_delta, mjr::math::vec::sum(y, tmp_y_delta));
        tmp_y_delta = mjr::math::vec::linear_combination(t_delta/6, k1, t_delta/3, k2, t_delta/3, k3, t_delta/6, k4);
        return tmp_y_delta;
      }
      // SS-END:rk4_t:
      //--------------------------------------------------------------------------------------------------------------------------------------------------------
      // SHELLO: sed -n '/SS-BEGIN:rk4_t:$/,/SS-END:rk4_t:$/p' MRMathODE.hpp | sed -E 's/(rk4|deq)\([^,]+, */\1(/g; /SS-/d; /@param t /d; s/deqwt_t/deqnt_t/'
      /** The classic 4th order Runge-Kutta Method.
          Reutrns delta y.
          @param y       Initial Condition
          @param deq     ODE derivative function
          @param t_delta Step size
          @par References:
           - Kutta (1901); Beitrag Zur N\"herungsweisen Integration Totaler Differentialgleichungen; Z. Math. Phys. 46; p435-53
           - Hairer, Norsett & Wanner (2009). Solving Ordinary Differential Equations. I: Nonstiff Problems. p138
           - Butcher (2016); Numerical Methods for Ordinary Differential Equations. 3rd Ed; Wiley; p102 */
      template <typename numType, std::size_t size>
      requires ((size > 0) && std::is_arithmetic_v<numType>)
      inline std::array<numType, size> rk4(std::array<numType, size> const& y, deqnt_t<numType, size> deq, numType t_delta) {
        numType tmp_t_delta;
        std::array<numType, size> tmp_y_delta;
        std::array<numType, size> k1 = deq(y);
        tmp_t_delta = t_delta/2;
        tmp_y_delta = mjr::math::vec::scale(tmp_t_delta, k1);
        std::array<numType, size> k2 = deq(mjr::math::vec::sum(y, tmp_y_delta));
        tmp_y_delta = mjr::math::vec::scale(tmp_t_delta, k2);
        std::array<numType, size> k3 = deq(mjr::math::vec::sum(y, tmp_y_delta));
        tmp_y_delta = mjr::math::vec::scale(t_delta, k3);
        std::array<numType, size> k4 = deq(mjr::math::vec::sum(y, tmp_y_delta));
        tmp_y_delta = mjr::math::vec::linear_combination(t_delta/6, k1, t_delta/3, k2, t_delta/3, k3, t_delta/6, k4);
        return tmp_y_delta;
      }
      //@}
    } // end namespace rk
  } // end namespace math
} // end namespace mjr

#define MJR_INCLUDE_MRMATHODE
#endif
