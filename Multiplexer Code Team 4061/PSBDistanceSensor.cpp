////////////////////////////////////////////////////////////////////////////////
//
// License:
//   Copyright (c) 2020  PART Sciborgs, FRC Team 4061
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
#include "PSBDistanceSensor.h"
#include "frc/I2C.h"
#include "PsbRev2mDistanceSensor.h"
namespace Psb
{
    namespace Subsystem
    {     
        PSBDistanceSensor::PSBDistanceSensor(Rev2mDistanceSensor::Port i2cPort,
					     Rev2mDistanceSensor::DistanceUnit units,
					     Rev2mDistanceSensor::RangeProfile profile,
					     I2CBreakout& breakout, uint8_t breakoutChannel):
	    m_breakout(breakout),
	    m_breakoutChannel(breakoutChannel)
        {
	    SetActive();
	    m_distanceSensor = new Rev2mDistanceSensor(i2cPort, units, profile);
	    m_distanceSensor->StartMeasurement();
        }

        void PSBDistanceSensor::SetActive() 
	{
            m_breakout.SetChannel(1 << m_breakoutChannel);
        }

        bool PSBDistanceSensor::IsRangeValid()
	{
            SetActive();
	    return m_distanceSensor->IsRangeValid();
	}

        double PSBDistanceSensor::GetRange()
	{
   	    SetActive();
	    m_distanceSensor->GetMeasurementData();
	    return m_distanceSensor->GetRange();
	}
 
        bool PSBDistanceSensor::StatusIsFatal()
	{
	    SetActive();
	    return m_distanceSensor->StatusIsFatal();
	}

   }
    
} // namespace Psb
