////////////////////////////////////////////////////////////////////////////////
//
// License:
//   Copyright (c) 2020 PART Sciborgs, FRC Team 4061
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "frc/I2C.h"
#include "PsbRev2mDistanceSensor.h"

namespace Psb
{
    namespace Subsystem
    {
        class PSBDistanceSensor {

        public:
	  PSBDistanceSensor(Rev2mDistanceSensor::Port i2cPort,
			    Rev2mDistanceSensor::DistanceUnit units,
			    Rev2mDistanceSensor::RangeProfile profile,
			    I2CBreakout& breakout, uint8_t breakoutChannel);
	    void SetActive();
	    bool IsRangeValid();
	    double GetRange();
	    bool StatusIsFatal();
	    
        private:
            I2CBreakout& m_breakout;
	    uint8_t m_breakoutChannel;
	    frc::I2C::Port m_i2cPort;
	    Rev2mDistanceSensor* m_distanceSensor;
        };
        
    } // namespace Subsystem
    
} // namespace Psb
