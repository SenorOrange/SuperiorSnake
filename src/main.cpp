/*                                                                          
     Module:       main.cpp                                                   
     Author:       Josh Moller   
     Team:         SuperiorSnake (7842S)         
     Members:      Josh Moller, Henry, Dio                                       
     Created:      Tue Sep 12 2023                                           
     Description:  This is our robot for the 2023/24 OverUnder
                   It has a 4 motor tank drive base.
                                                                              */

/* ---- VEXCODE DEVICES ----
   Robot Configuration: 4 Motor Tank Drive
   [Name]               [Type]        [Port(s)]
   Controller1          controller
   LeftFrontMotor            motor      2
   LeftBackMotor            motor      1
   RightFrontMotor           motor      4
   RightBackMotor           motor      3

   ---- END VEXCODE DEVICES ----   */

#include "vex.h"

using namespace vex;

int main() {
  vexcodeInit();

  int deadband = 5;

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
  }
}
