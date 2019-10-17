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
 * Digital Light Sensor
 * This sensor will be driven low based on light level
 */

public class Robot extends TimedRobot {
  DigitalInput lightSensor;


  @Override
  public void robotInit() {
    lightSensor = new DigitalInput(0); //set the sensor to input 0
  }


  @Override
  public void teleopPeriodic() {
    boolean state = lightSensor.get(); //get the data
    SmartDashboard.putBoolean("DB/LED 0", state); //put the data on the SmartDashboard
  }

}
