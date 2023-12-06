/*                                                                          
     Module:       main.cpp                                                   
     Author:       Moller, Josh   
     Team:         SuperiorSnake (7842S)         
     Members:      Josh Moller (Master Oogway), Henry Huynh (Tai Lung), Brandon McDoonnell (Dragon Warrior)                                     
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

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
 int (main);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  Arms.resetPosition();
 //straight
  RightMotor.spinTo(390, deg, 100, rpm, false);
  LeftMotor.spinTo(390, deg, 100, rpm);
  wait(1, sec);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  //turn right
  RightMotor.spinTo(-220, deg, 100, rpm, false);
  LeftMotor.spinTo(220, deg, 100, rpm);
  wait(1, sec);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  //straight
  RightMotor.spinTo(250, deg, 100, rpm, false);
  LeftMotor.spinTo(250, deg, 100, rpm);
  wait(1, sec);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  //turn right
  RightMotor.spinTo(220, deg, 100, rpm, false);
  LeftMotor.spinTo(-220, deg, 100, rpm);
  wait(1, sec);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  //straight
  RightMotor.spinTo(200, deg, 100, rpm, false);
  LeftMotor.spinTo(2000, deg, 100, rpm);
  wait(1, sec);
  
  wait(1, sec);
  Arms.spinTo(2009, degrees);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  int (main);
  int deadband = 5;
  while (1) {

    int leftY = Controller1.Axis3.position();
    int rightX = Controller1.Axis4.position();
        
        // Move the left side of the robot
        LeftMotor.spin(forward, leftY + rightX, pct);
        
        // Move the right side of the robot 
        RightMotor.spin(forward, leftY - rightX, pct);

    
    //Intake Forward and Reverse
    if(Controller1.ButtonR1.pressing()) {
      Arms.spin(forward, 200, rpm);
    } else {
      if(Controller1.ButtonL1.pressing()) {
        Arms.spin(reverse, 200, rpm);
      } else {
        Arms.stop();
      }
    }

    


    //Launcher Code

    //Pick Up Ball
    
/*/
    //Launch Ball and Reset Launcher
    if(Controller1.ButtonB.pressing()) {
      Arms.spinTo(10000, deg, 200, rpm, false);
      wait(0.5, sec);
      Launcher.resetPosition();
      Launcher.spinTo(800, deg, 50, rpm, true);
      wait(1, sec);
      Launcher.spinTo(-200, deg, 50, rpm, false);
      Arms.stop(); 
    } */

    wait(20, msec); // Sleep the task for a short amount of time to prevent wasted resources.


  }

}


//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
