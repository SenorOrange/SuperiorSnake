/*                                                                          
     Module:       main.cpp                                                   
     Author:       Moller, Josh   
     Team:         SuperiorSnake (7842S)         
     Members:      Josh Moller, Henry Huynh, Dio Hsieh                                       
     Created:      Tue Sep 12 2023                                           
     Description:  This is our robot for the 2023/24 OverUnder
                   It has a 4 motor tank drive base.
                                                                              */

/* ---- VEXCODE DEVICES ----
   Robot Configuration: 4 Motor Tank Drive
   [Name]               [Type]        [Port(s)]
   Controller1          controller
   LeftFrontMotor            motor      7
   LeftBackMotor            motor      11
   RightFrontMotor           motor      20
   RightBackMotor           motor      18

   ---- END VEXCODE DEVICES ----   */

#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftMotor            motor_group   7, 11           
// RightMotor           motor_group   20, 18          
// Controller1          controller                    
// Arms                 motor_group   1, 10           
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

competition Competition;

//Pre Autonomous Code
void pre_auton(void) {

  int (main);
  vexcodeInit();
}

//Autonomous Code
void autonomous(void) {
  int (main);
  RightMotor.spinTo(100, deg, 100, rpm, false);
  LeftMotor.spinTo(100, deg, 100, rpm);
  wait(1, sec);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  RightMotor.spinTo(-100, deg, 100, rpm, false);
  LeftMotor.spinTo(-100, deg, 100, rpm);
}

//User Control Code
void usercontrol(void) {
  vexcodeInit();
  int (main);
  int deadband = 5;
    //Below this text is the 4 motor tank drivebase which moves and controls the robot.
  while (true) {
    int leftMotorSpeed = Controller1.Axis3.position();
    int rightMotorSpeed = Controller1.Axis2.position();

    if (abs(leftMotorSpeed) < deadband) {
      LeftMotor.setVelocity(0, percent);
    } else {
      LeftMotor.setVelocity(leftMotorSpeed, percent);
    }

    if (abs(rightMotorSpeed) < deadband) {
      RightMotor.setVelocity(0, percent);
    } else {
      RightMotor.setVelocity(rightMotorSpeed, percent);
    }

    LeftMotor.spin(forward);
    RightMotor.spin(forward);

    wait(25, msec);

    //Future code for the Arm (endgame)
    if(Controller1.ButtonR1.pressing()) {
      Arms.spin(forward);
    } else {
      Arms.stop();
    }

  }
    
}
