/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>

#include <Pixy2.h>
#include <Controller.h>
#include <MecDrive.h>
#include <Shooter.h>
#include <Vision.h>

//this is a change

class Robot : public frc::TimedRobot {
  public:

    void RobotInit() override;
    void RobotPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestInit() override;
    void TestPeriodic() override;

  private:

    rr::Pixy2 frontPixy{frc::I2C::kOnboard, 84};
    // declare a driver controler object
    // declare an operator controller object
    // declare a mecanum driver object
    // declare a shooter object


};
// good