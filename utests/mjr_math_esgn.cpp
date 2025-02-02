// -*- Mode:C++; Coding:us-ascii-unix; fill-column:158 -*-
/*******************************************************************************************************************************************************.H.S.**/
/**
 @file      mjr_math_esgn.cpp
 @author    Mitch Richling http://www.mitchr.me/
 @date      2025-02-02
 @brief     Unit tests for mjr::math::esgn.@EOL
 @std       C++20
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
*/
/*******************************************************************************************************************************************************.H.E.**/
/** @cond exj */

#include <gtest/gtest.h>

#include "MRMathESGN.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_sgn, Comprehensive) {
  EXPECT_EQ(mjr::math::esgn::sgn( 2  ), mjr::math::esgn::signT::esPos  );
  EXPECT_EQ(mjr::math::esgn::sgn( 1  ), mjr::math::esgn::signT::esPos  );
  EXPECT_EQ(mjr::math::esgn::sgn( 0  ), mjr::math::esgn::signT::esZero );
  EXPECT_EQ(mjr::math::esgn::sgn(-1  ), mjr::math::esgn::signT::esNeg  );
  EXPECT_EQ(mjr::math::esgn::sgn(-2  ), mjr::math::esgn::signT::esNeg  );

  EXPECT_EQ(mjr::math::esgn::sgn( 2.0), mjr::math::esgn::signT::esPos  );
  EXPECT_EQ(mjr::math::esgn::sgn( 1.0), mjr::math::esgn::signT::esPos  );
  EXPECT_EQ(mjr::math::esgn::sgn( 0.0), mjr::math::esgn::signT::esZero );
  EXPECT_EQ(mjr::math::esgn::sgn(-1.0), mjr::math::esgn::signT::esNeg  );
  EXPECT_EQ(mjr::math::esgn::sgn(-2.0), mjr::math::esgn::signT::esNeg  );

  EXPECT_EQ(mjr::math::esgn::sgn( 2.1), mjr::math::esgn::signT::esPos  );
  EXPECT_EQ(mjr::math::esgn::sgn( 1.1), mjr::math::esgn::signT::esPos  );
  EXPECT_EQ(mjr::math::esgn::sgn( 0.1), mjr::math::esgn::signT::esPos  );
  EXPECT_EQ(mjr::math::esgn::sgn(-0.1), mjr::math::esgn::signT::esNeg  );
  EXPECT_EQ(mjr::math::esgn::sgn(-1.1), mjr::math::esgn::signT::esNeg  );
  EXPECT_EQ(mjr::math::esgn::sgn(-2.1), mjr::math::esgn::signT::esNeg  );

  EXPECT_EQ(mjr::math::esgn::sgn( 2.9), mjr::math::esgn::signT::esPos  );
  EXPECT_EQ(mjr::math::esgn::sgn( 1.9), mjr::math::esgn::signT::esPos  );
  EXPECT_EQ(mjr::math::esgn::sgn( 0.9), mjr::math::esgn::signT::esPos  );
  EXPECT_EQ(mjr::math::esgn::sgn(-0.9), mjr::math::esgn::signT::esNeg  );
  EXPECT_EQ(mjr::math::esgn::sgn(-1.9), mjr::math::esgn::signT::esNeg  );
  EXPECT_EQ(mjr::math::esgn::sgn(-2.9), mjr::math::esgn::signT::esNeg  );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_sgne, Comprehensive) {
  EXPECT_EQ(mjr::math::esgn::sgne( 2.0, 1.0e-5), mjr::math::esgn::signT::esPos);
  EXPECT_EQ(mjr::math::esgn::sgne( 1.0, 1.0e-5), mjr::math::esgn::signT::esPos);
  EXPECT_EQ(mjr::math::esgn::sgne( 0.0, 1.0e-5), mjr::math::esgn::signT::esZero);
  EXPECT_EQ(mjr::math::esgn::sgne(-1.0, 1.0e-5), mjr::math::esgn::signT::esNeg);
  EXPECT_EQ(mjr::math::esgn::sgne(-2.0, 1.0e-5), mjr::math::esgn::signT::esNeg);

  EXPECT_EQ(mjr::math::esgn::sgne( 2.1, 1.0e-5), mjr::math::esgn::signT::esPos);
  EXPECT_EQ(mjr::math::esgn::sgne( 1.1, 1.0e-5), mjr::math::esgn::signT::esPos);
  EXPECT_EQ(mjr::math::esgn::sgne( 0.1, 1.0e-5), mjr::math::esgn::signT::esPos);
  EXPECT_EQ(mjr::math::esgn::sgne(-0.1, 1.0e-5), mjr::math::esgn::signT::esNeg);
  EXPECT_EQ(mjr::math::esgn::sgne(-1.1, 1.0e-5), mjr::math::esgn::signT::esNeg);
  EXPECT_EQ(mjr::math::esgn::sgne(-2.1, 1.0e-5), mjr::math::esgn::signT::esNeg);

  EXPECT_EQ(mjr::math::esgn::sgne( 2.9, 1.0e-5), mjr::math::esgn::signT::esPos);
  EXPECT_EQ(mjr::math::esgn::sgne( 1.9, 1.0e-5), mjr::math::esgn::signT::esPos);
  EXPECT_EQ(mjr::math::esgn::sgne( 0.9, 1.0e-5), mjr::math::esgn::signT::esPos);
  EXPECT_EQ(mjr::math::esgn::sgne(-0.9, 1.0e-5), mjr::math::esgn::signT::esNeg);
  EXPECT_EQ(mjr::math::esgn::sgne(-1.9, 1.0e-5), mjr::math::esgn::signT::esNeg);
  EXPECT_EQ(mjr::math::esgn::sgne(-2.9, 1.0e-5), mjr::math::esgn::signT::esNeg);

  // epsilon is big enough 0.1 & -0.1 are considered zero
  EXPECT_EQ(mjr::math::esgn::sgne( 0.1, 0.20), mjr::math::esgn::signT::esZero);
  EXPECT_EQ(mjr::math::esgn::sgne(-0.1, 0.20), mjr::math::esgn::signT::esZero);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_zero_or_change, TwoArg) {
  EXPECT_FALSE(mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff

  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff

  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_FALSE(mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_zero_or_change, ThreeArg) {
  EXPECT_FALSE(mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff

  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff

  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_FALSE(mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_zero_or_change, FourArg) {
  EXPECT_FALSE(mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff

  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero

  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_FALSE(mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_zero_or_change, FiveArg) {
  EXPECT_FALSE(mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff

  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));  // zero + diff

  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); // zero + diff
  EXPECT_FALSE(mjr::math::esgn::zero_or_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_zero_or_change, OneVec) {
  EXPECT_FALSE(mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg  })));
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero }))); // zero
  EXPECT_FALSE(mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos  })));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_zero_or_change, TwoVec) {
  EXPECT_FALSE(mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  })));
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  }))); // diff

  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero }))); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero }))); // zero + diff

  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  }))); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  }))); // zero + diff
  EXPECT_FALSE(mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  }))); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_zero_or_change, ThreeVec) {
  EXPECT_FALSE(mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  })));
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  }))); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  }))); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  }))); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  }))); // diff

  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero }))); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero }))); // zero + diff

  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  }))); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  }))); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  }))); // zero
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  }))); // zero + diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  }))); // diff
  EXPECT_TRUE( mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  }))); // zero + diff
  EXPECT_FALSE(mjr::math::esgn::zero_or_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  }))); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_zero_or_change, Itr) {

  std::vector<mjr::math::esgn::signT> daVec;

  daVec.push_back(mjr::math::esgn::signT::esNeg);
  for(int s0=0; s0<3; s0++) {
    daVec[0] = static_cast<mjr::math::esgn::signT>(s0);
    EXPECT_EQ(mjr::math::esgn::zero_or_change(daVec), mjr::math::esgn::zero_or_change(daVec.cbegin(), daVec.cend()));
  }

  daVec.push_back(mjr::math::esgn::signT::esNeg);
  for(int s0=0; s0<3; s0++) {
    daVec[0] = static_cast<mjr::math::esgn::signT>(s0);
    for(int s1=0; s1<3; s1++) {
      daVec[1] = static_cast<mjr::math::esgn::signT>(s1);
      EXPECT_EQ(mjr::math::esgn::zero_or_change(daVec), mjr::math::esgn::zero_or_change(daVec.cbegin(), daVec.cend()));
    }
  }

  daVec.push_back(mjr::math::esgn::signT::esNeg);
  for(int s0=0; s0<3; s0++) {
    daVec[0] = static_cast<mjr::math::esgn::signT>(s0);
    for(int s1=0; s1<3; s1++) {
      daVec[1] = static_cast<mjr::math::esgn::signT>(s1);
      for(int s2=0; s2<3; s2++) {
        daVec[2] = static_cast<mjr::math::esgn::signT>(s2);
        EXPECT_EQ(mjr::math::esgn::zero_or_change(daVec), mjr::math::esgn::zero_or_change(daVec.cbegin(), daVec.cend()));
      }
    }
  }

  daVec.push_back(mjr::math::esgn::signT::esNeg);
  for(int s0=0; s0<3; s0++) {
    daVec[0] = static_cast<mjr::math::esgn::signT>(s0);
    for(int s1=0; s1<3; s1++) {
      daVec[1] = static_cast<mjr::math::esgn::signT>(s1);
      for(int s2=0; s2<3; s2++) {
        daVec[2] = static_cast<mjr::math::esgn::signT>(s2);
        for(int s3=0; s3<3; s3++) {
          daVec[3] = static_cast<mjr::math::esgn::signT>(s3);
          EXPECT_EQ(mjr::math::esgn::zero_or_change(daVec), mjr::math::esgn::zero_or_change(daVec.cbegin(), daVec.cend()));
        }
      }
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_non_zero_change, TwoArg) {
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); // diff

  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));

  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); // diff
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_non_zero_change, ThreeArg) {
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 

  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 

  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_non_zero_change, FourArg) {
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg  ));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg  )); 

  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero ));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero )); 

  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos  ));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE(mjr::math::esgn::non_zero_change( mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos  )); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_non_zero_change, FiveArg) {
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 

  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 

  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,   mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_non_zero_change, OneVec) {
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg  })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos  })));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_non_zero_change, TwoVec) {
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  })));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  })));

  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero })));

  EXPECT_TRUE( mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  }))); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_non_zero_change, ThreeVec) {
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  })));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  })));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  })));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  })));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  })));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  })));

  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero })));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero })));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero })));

  EXPECT_TRUE( mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  })));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  })));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  })));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  })));
  EXPECT_TRUE( mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  })));
  EXPECT_FALSE(mjr::math::esgn::non_zero_change(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  }))); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_non_zero_change, Itr) {

  std::vector<mjr::math::esgn::signT> daVec;

  daVec.push_back(mjr::math::esgn::signT::esNeg);
  for(int s0=0; s0<3; s0++) {
    daVec[0] = static_cast<mjr::math::esgn::signT>(s0);
    EXPECT_EQ(mjr::math::esgn::non_zero_change(daVec), mjr::math::esgn::non_zero_change(daVec.cbegin(), daVec.cend()));
  }

  daVec.push_back(mjr::math::esgn::signT::esNeg);
  for(int s0=0; s0<3; s0++) {
    daVec[0] = static_cast<mjr::math::esgn::signT>(s0);
    for(int s1=0; s1<3; s1++) {
      daVec[1] = static_cast<mjr::math::esgn::signT>(s1);
      EXPECT_EQ(mjr::math::esgn::non_zero_change(daVec), mjr::math::esgn::non_zero_change(daVec.cbegin(), daVec.cend()));
    }
  }

  daVec.push_back(mjr::math::esgn::signT::esNeg);
  for(int s0=0; s0<3; s0++) {
    daVec[0] = static_cast<mjr::math::esgn::signT>(s0);
    for(int s1=0; s1<3; s1++) {
      daVec[1] = static_cast<mjr::math::esgn::signT>(s1);
      for(int s2=0; s2<3; s2++) {
        daVec[2] = static_cast<mjr::math::esgn::signT>(s2);
        EXPECT_EQ(mjr::math::esgn::non_zero_change(daVec), mjr::math::esgn::non_zero_change(daVec.cbegin(), daVec.cend()));
      }
    }
  }

  daVec.push_back(mjr::math::esgn::signT::esNeg);
  for(int s0=0; s0<3; s0++) {
    daVec[0] = static_cast<mjr::math::esgn::signT>(s0);
    for(int s1=0; s1<3; s1++) {
      daVec[1] = static_cast<mjr::math::esgn::signT>(s1);
      for(int s2=0; s2<3; s2++) {
        daVec[2] = static_cast<mjr::math::esgn::signT>(s2);
        for(int s3=0; s3<3; s3++) {
          daVec[3] = static_cast<mjr::math::esgn::signT>(s3);
          EXPECT_EQ(mjr::math::esgn::non_zero_change(daVec), mjr::math::esgn::non_zero_change(daVec.cbegin(), daVec.cend()));
        }
      }
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_count_signs, OneArg) {
  EXPECT_EQ((std::array<int, 3>({ 0, 0, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg));
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero));
  EXPECT_EQ((std::array<int, 3>({ 0, 1, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_count_signs, TwoArg) {
  EXPECT_EQ((std::array<int, 3>({ 0, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));

  EXPECT_EQ((std::array<int, 3>({ 1, 0, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));

  EXPECT_EQ((std::array<int, 3>({ 0, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_count_signs, ThreeArg) {
  EXPECT_EQ((std::array<int, 3>({ 0, 0, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 

  EXPECT_EQ((std::array<int, 3>({ 1, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 

  EXPECT_EQ((std::array<int, 3>({ 0, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_count_signs, FourArg) {
  EXPECT_EQ((std::array<int, 3>({ 0, 0, 4})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_EQ((std::array<int, 3>({ 0, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 

  EXPECT_EQ((std::array<int, 3>({ 1, 0, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 4, 0, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 

  EXPECT_EQ((std::array<int, 3>({ 0, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 4, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_count_signs, FiveArg) {
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 4})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 4, 0, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero )); 
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 4, 0, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 4, 0, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 4, 0, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 5, 0, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 4, 1, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 4, 1, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 4, 1, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 3, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero )); 
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 4, 1, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 3, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 3, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 3, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 2, 3, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero ));
  EXPECT_EQ((std::array<int, 3>({ 1, 4, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero )); 

  EXPECT_EQ((std::array<int, 3>({ 0, 1, 4})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 4, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 4, 1, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 3, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 3, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 3, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 4, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  )); 
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 4, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 2, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 3, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 3, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 4, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 4, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 3, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 4, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 4, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 4, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 5, 0})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  )); 

  EXPECT_EQ((std::array<int, 3>({ 0, 0, 5})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 4})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 1, 4})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 4})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 1, 4})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 4})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_EQ((std::array<int, 3>({ 0, 1, 4})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 4})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 4, 0, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  )); 
  EXPECT_EQ((std::array<int, 3>({ 0, 1, 4})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 3, 1, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 3})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 2, 2, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 2})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 1, 3, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  ));
  EXPECT_EQ((std::array<int, 3>({ 0, 4, 1})), mjr::math::esgn::count_signs(mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  )); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_count_signs, OneVec) {
  EXPECT_EQ((std::array<int, 3>({ 0, 0, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg  })));
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 0})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero })));
  EXPECT_EQ((std::array<int, 3>({ 0, 1, 0})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos  })));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_count_signs, TwoVec) {
  EXPECT_EQ((std::array<int, 3>({ 0, 0, 2})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  })));
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  })));
  EXPECT_EQ((std::array<int, 3>({ 0, 1, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  })));

  EXPECT_EQ((std::array<int, 3>({ 1, 0, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero })));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 0})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero })));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 0})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero })));

  EXPECT_EQ((std::array<int, 3>({ 0, 1, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  })));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 0})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  })));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 0})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  }))); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_count_signs, ThreeVec) {
  EXPECT_EQ((std::array<int, 3>({ 0, 0, 3})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  })));
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 2})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  })));
  EXPECT_EQ((std::array<int, 3>({ 0, 1, 2})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg  })));
  EXPECT_EQ((std::array<int, 3>({ 1, 0, 2})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  })));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  })));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg  })));
  EXPECT_EQ((std::array<int, 3>({ 0, 1, 2})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  })));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  })));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg  }))); 

  EXPECT_EQ((std::array<int, 3>({ 1, 0, 2})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero })));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero })));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero })));
  EXPECT_EQ((std::array<int, 3>({ 2, 0, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero })));
  EXPECT_EQ((std::array<int, 3>({ 3, 0, 0})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero })));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 0})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero })));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero })));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 0})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero })));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 0})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero }))); 

  EXPECT_EQ((std::array<int, 3>({ 0, 1, 2})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  })));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  })));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos  })));
  EXPECT_EQ((std::array<int, 3>({ 1, 1, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  })));
  EXPECT_EQ((std::array<int, 3>({ 2, 1, 0})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  })));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 0})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos  })));
  EXPECT_EQ((std::array<int, 3>({ 0, 2, 1})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esNeg,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  })));
  EXPECT_EQ((std::array<int, 3>({ 1, 2, 0})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esZero, mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  })));
  EXPECT_EQ((std::array<int, 3>({ 0, 3, 0})), mjr::math::esgn::count_signs(std::vector<mjr::math::esgn::signT>({ mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos,  mjr::math::esgn::signT::esPos  }))); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(FN_count_signs, Itr) {

  std::vector<mjr::math::esgn::signT> daVec;

  daVec.push_back(mjr::math::esgn::signT::esNeg);
  for(int s0=0; s0<3; s0++) {
    daVec[0] = static_cast<mjr::math::esgn::signT>(s0);
    EXPECT_EQ(mjr::math::esgn::count_signs(daVec), mjr::math::esgn::count_signs(daVec.cbegin(), daVec.cend()));
  }

  daVec.push_back(mjr::math::esgn::signT::esNeg);
  for(int s0=0; s0<3; s0++) {
    daVec[0] = static_cast<mjr::math::esgn::signT>(s0);
    for(int s1=0; s1<3; s1++) {
      daVec[1] = static_cast<mjr::math::esgn::signT>(s1);
      EXPECT_EQ(mjr::math::esgn::count_signs(daVec), mjr::math::esgn::count_signs(daVec.cbegin(), daVec.cend()));
    }
  }

  daVec.push_back(mjr::math::esgn::signT::esNeg);
  for(int s0=0; s0<3; s0++) {
    daVec[0] = static_cast<mjr::math::esgn::signT>(s0);
    for(int s1=0; s1<3; s1++) {
      daVec[1] = static_cast<mjr::math::esgn::signT>(s1);
      for(int s2=0; s2<3; s2++) {
        daVec[2] = static_cast<mjr::math::esgn::signT>(s2);
        EXPECT_EQ(mjr::math::esgn::count_signs(daVec), mjr::math::esgn::count_signs(daVec.cbegin(), daVec.cend()));
      }
    }
  }

  daVec.push_back(mjr::math::esgn::signT::esNeg);
  for(int s0=0; s0<3; s0++) {
    daVec[0] = static_cast<mjr::math::esgn::signT>(s0);
    for(int s1=0; s1<3; s1++) {
      daVec[1] = static_cast<mjr::math::esgn::signT>(s1);
      for(int s2=0; s2<3; s2++) {
        daVec[2] = static_cast<mjr::math::esgn::signT>(s2);
        for(int s3=0; s3<3; s3++) {
          daVec[3] = static_cast<mjr::math::esgn::signT>(s3);
          EXPECT_EQ(mjr::math::esgn::count_signs(daVec), mjr::math::esgn::count_signs(daVec.cbegin(), daVec.cend()));
        }
      }
    }
  }
}

/** @endcond */
