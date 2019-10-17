/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot;

import edu.wpi.first.wpilibj.TimedRobot;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj.DigitalInput;

/*
 * Hall Effect Latch
 * This sensor will pull the output low when a south pole is applied to the sensor. It will stay low until a north pole is applied.
 * 
*/

public class Robot extends TimedRobot {
  DigitalInput heffect;


  @Override
  public void robotInit() {
    heffect = new DigitalInput(0); //initialize the input to be on DIO 0
  }


  @Override
  public void teleopPeriodic() {
    boolean state = heffect.get(); //Get the state of the switch
    SmartDashboard.putBoolean("DB/LED 0", state);
  }

}
