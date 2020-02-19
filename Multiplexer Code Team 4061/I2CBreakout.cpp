////////////////////////////////////////////////////////////////////////////////
//
// License:
//   Copyright (c) 2016-2017 PART Sciborgs, FRC Team 4061
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

#include "I2CBreakout.h"
#include "frc/I2C.h"
#include <iostream>
namespace Psb
{
    namespace Subsystem
    {     
        uint8_t MIN_PORT = 1;
        uint8_t MAX_PORT = 8;
        I2CBreakout::I2CBreakout(frc::I2C::Port i2cPort, int breakoutAddress)
        {
            m_breakout_board = new frc::I2C(i2cPort, breakoutAddress);
            m_current_channel = 0;
        }


        // Communicate which channel the mux should be on
        //          [x,x,x,x,x,x,x,x]
        // channel   7,6,5,4,3,2,1,0
        bool I2CBreakout::SetChannel(uint8_t channel)
        {
            bool retVal = true;

            if(m_current_channel != channel)
            {
                m_current_channel = channel;
                retVal = m_breakout_board->WriteBulk(&channel, 1);
		//if (retVal) {std::cout << "Write to breakout failed " << retVal << std::endl;}
            }
            return retVal;
        }

        uint8_t I2CBreakout::GetChannel()
        {
            return m_current_channel;
        }
    }
    
} // namespace Psb
