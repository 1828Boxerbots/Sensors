/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot;

import edu.wpi.first.wpilibj.TimedRobot;
import edu.wpi.first.wpilibj.AnalogInput;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
/**
 * Analog Hall Effect Example
 * This sensor outputs a voltage based on the brighness shone on the sensor. 0V for little light. 5v for high intensity
 */
public class Robot extends TimedRobot {
  AnalogInput m_sensor;
  
  @Override
  public void robotInit() {
    m_sensor = new AnalogInput(0);
  }

  @Override
  public void robotPeriodic() {
    double m_sensordata = m_sensor.getVoltage();
    SmartDashboard.putNumber("Sensor Value", m_sensordata);
  }


}
