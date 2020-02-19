// /////////////////////////////////////////////////////////////////////////////
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
// /////////////////////////////////////////////////////////////////////////////


// /////////////////////////////////////////////////////////////////////////////
// Include(s)
// /////////////////////////////////////////////////////////////////////////////
#include "frc/I2C.h"
#include "PSBColorSensor.h"
#include "PSBDistanceSensor.h"
#include "PsbRev2mDistanceSensor.h"
#include "I2CBreakout.h"
#include <iostream>

// /////////////////////////////////////////////////////////////////////////////
// This is where we actually build the dashstream interface
// since this is the object that will hand it out if someone wants it
// /////////////////////////////////////////////////////////////////////////////
#define BUILD_IT
#include "example.h"
#undef BUILD_IT


// /////////////////////////////////////////////////////////////////////////////
// Define(s)
// /////////////////////////////////////////////////////////////////////////////

// /////////////////////////////////////////////////////////////////////////////
// Namespace(s)
// /////////////////////////////////////////////////////////////////////////////
namespace Psb {
namespace Subsystem {
namespace Trench {

////////////////////////////////////////////////////////////////////////////////
Controller::Controller(void)
{
   // TBD: get sensor channels info from robot config, not hardcoded
   m_breakout = new I2CBreakout(frc::I2C::Port::kOnboard);
   m_distanceSensorFront = new PSBDistanceSensor(Psb::Rev2mDistanceSensor::Port::kOnboard,
					 Psb::Rev2mDistanceSensor::DistanceUnit::kMilliMeters,
					 Psb::Rev2mDistanceSensor::RangeProfile::kDefault,
					 *m_breakout, 1
					 );
   if (m_distanceSensorFront->StatusIsFatal()) {m_distanceSensorFront = NULL;}
   if (m_distanceSensorFront) {std::cout << "created front distance sensor on channel 1" <<std::endl;}
   m_distanceSensorRear = new PSBDistanceSensor(Psb::Rev2mDistanceSensor::Port::kOnboard,
					 Psb::Rev2mDistanceSensor::DistanceUnit::kMilliMeters,
					 Psb::Rev2mDistanceSensor::RangeProfile::kDefault,
					 *m_breakout, 2
					 );
   if (m_distanceSensorRear->StatusIsFatal()) {m_distanceSensorRear = NULL;}
   if (m_distanceSensorRear) {std::cout << "created rear distance sensor on channel 2" <<std::endl;}
   m_colorSensor = new PSBColorSensor(frc::I2C::Port::kOnboard, *m_breakout, 0);
   if (m_colorSensor->StatusIsFatal()) {m_colorSensor = NULL;}
   if (m_colorSensor) {std::cout << "created color sensor on channel 0" << std::endl;}
}


////////////////////////////////////////////////////////////////////////////////
void
Controller::performDisabledUpdate(void)
{
   updateDistanceSensor();
   updateColorSensor();
}

void
Controller::updateColorSensor(void)
{
  if (!m_colorSensor) {std::cout << "No color sensor" << std::endl; return;}
  rev::ColorSensorV3::RawColor detectedColor = m_colorSensor->GetRawColor();

  // Do something with detecttedColor
}

void
Controller::updateDistanceSensor(void)
{
  // NOTE: for the distance sensors, call GetRange() *before*
  // calling IsRangeValid, because it GetRange() that actually
  // interacts with the sensor.
  if (!m_distanceSensorFront) {std::cout << "No Front Distance sensor" << std::endl; return;}
  if (m_distanceSensorFront)
   {
     uint32_t distance = m_distanceSensorFront->GetRange();
     bool isValid = m_distanceSensorFront->IsRangeValid();
     if (isValid) {
       m_distanceFront = distance;
     }
   }
  if (!m_distanceSensorRear) {std::cout << "No Rear Distance sensor" << std::endl; return;}
  if (m_distanceSensorRear)
   {
     uint32_t distance = m_distanceSensorRear->GetRange();
     bool isValid = m_distanceSensorRear->IsRangeValid();
     if (isValid) {
       m_distanceRear = distance;
     }
   }
}



} // END namespace Trench
} // END namespace Subsystem
} // END namespace Psb


// /////////////////////////////////////////////////////////////////////////////
// END OF FILE
// /////////////////////////////////////////////////////////////////////////////

