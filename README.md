Limit Switch info gotten from: https://frc-pdr.readthedocs.io/en/latest/motors/limitswitch.html

CODE EXAMPLE:

#include <math.h>

class Robot: public IterativeRobot
{
    DigitalInput forwardLimitSwitch, reverseLimitSwitch;
    Joystick joystick1;
    Talon motor;

public:
    Robot() {

    }

    void RobotInit(){
        forwardLimitSwitch = new DigitalInput(1);
        reverseLimitSwitch = new DigitalInput(2);
        joystick = new Joystick(1);
        motor = new Talon(1);
    }

    void teleopPeriodic() {
        int output = joystick1->getY(); //Moves the joystick based on Y value
        if (forwardLimitSwitch->get()) // If the forward limit switch is pressed, we want to keep the values between -1 and 0
            output = fmin(output, 0);
        else if(reverseLimitSwitch->get()) // If the reversed limit switch is pressed, we want to keep the values between 0 and 1
            output = fmax(output, 0);
        motor->set(output);
    }
}
 
