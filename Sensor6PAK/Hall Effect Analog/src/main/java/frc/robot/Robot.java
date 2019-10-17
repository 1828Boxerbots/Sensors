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
 * This sensor outputs a voltage based on the strength of a magnetic pole. 0V for a strong south pole, 2V for a strong north pole, and 1V for no pole detected. 
 * Use this for position sensing within the range  of the sensor (about 1-2” (3 - ~5mm), depending on magnet strength)
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
