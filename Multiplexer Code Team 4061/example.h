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
#ifndef __trenchController_h__
#define __trenchController_h__


// ///////////////////////////////////////////////////////////////////////////// 
// Include(s)
// /////////////////////////////////////////////////////////////////////////////
#include "PSBColorSensor.h"
#include "PSBDistanceSensor.h"

// /////////////////////////////////////////////////////////////////////////////
// Namespace(s)
// /////////////////////////////////////////////////////////////////////////////
namespace Psb {
namespace Subsystem {
namespace Trench {

////////////////////////////////////////////////////////////////////////////////
/// @brief
/// This class is the main controller for the Trench devices
////////////////////////////////////////////////////////////////////////////////
class Controller : public Psb::Subsystem::Controller_I
{
   public:
      //////////////////////////////////////////////////////////////////////////
      /// @brief
      /// Constructor
      //////////////////////////////////////////////////////////////////////////
      Controller(void);

      //////////////////////////////////////////////////////////////////////////
      /// @brief
      /// Destructor
      //////////////////////////////////////////////////////////////////////////
      virtual ~Controller(void);

      //////////////////////////////////////////////////////////////////////////
      /// @brief
      /// does the init of the class
      //////////////////////////////////////////////////////////////////////////
      void init(void);

  private:
      //////////////////////////////////////////////////////////////////////////
      /// @see
      //////////////////////////////////////////////////////////////////////////
      void performDisabledUpdate(void);

      //////////////////////////////////////////////////////////////////////////
      /// @brief
      /// updates distance sensor pod with new values
      //////////////////////////////////////////////////////////////////////////
      void updateDistanceSensor(void);

      //////////////////////////////////////////////////////////////////////////
      /// @brief
      /// updates color sensor pod with new values
      //////////////////////////////////////////////////////////////////////////
      void updateColorSensor(void);

   private:

      //////////////////////////////////////////////////////////////////////////
      /// @brief
      /// The storage for all the data
      //////////////////////////////////////////////////////////////////////////
      int m_distanceFront;
      int m_distanceRear;
      I2CBreakout *m_breakout;

      //////////////////////////////////////////////////////////////////////////
      /// @brief 
      //////////////////////////////////////////////////////////////////////////
      PSBDistanceSensor *m_distanceSensorFront;
      PSBDistanceSensor *m_distanceSensorRear;
      PSBColorSensor *m_colorSensor;
 private:
      DISALLOW_COPY_CTOR(Controller);
      DISALLOW_ASSIGNMENT_OPER(Controller);
}; // END class Controller

} // END namespace Trench
} // END namespace Subsystem
} // END namespace Psb

#endif // __trenchController_h__


// /////////////////////////////////////////////////////////////////////////////
// END OF FILE
// /////////////////////////////////////////////////////////////////////////////

