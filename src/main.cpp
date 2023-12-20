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

int AutonSelected = 0;

bool DefenceAuton = false;
bool OffenseAuton = false;

bool DriveSelect = false;
bool TankDrive = false;
bool ArcadeDrive = false;


// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

//Auton Select Stuff

void drawGUI() {
  Brain.Screen.clearScreen();
  Brain.Screen.printAt(180, 30, "Select Auton");

  Brain.Screen.setFillColor(black);
  Brain.Screen.drawRectangle(20, 40, 210, 140);
  Brain.Screen.printAt(25, 75, "Defence");
  Brain.Screen.drawRectangle(250, 40, 210, 140);
  Brain.Screen.printAt(265, 75, "Offense");
  Brain.Screen.drawRectangle(143, 190, 190, 40);
  Brain.Screen.printAt(180, 215, "Drive Select");
  Brain.Screen.setFillColor(black);
}


//Select Which Auton We Want
void selectAuton() {
  bool selectingAuton = true;
  

  int x = Brain.Screen.xPosition(); // get the x position of last touch of the screen
  int y = Brain.Screen.yPosition(); // get the y position of last touch of the screen
  // check to see if buttons were pressed

  //Select Defence
  if (x >= 20 && y >= 40 && x <= 210 && y <= 140 && DriveSelect == false) 
  {
    Brain.Screen.setFillColor(green);
    Brain.Screen.drawRectangle(20, 40, 210, 140);
    Brain.Screen.printAt(25, 75, "Defence");

    Brain.Screen.setFillColor(black);
    Brain.Screen.drawRectangle(250, 40, 210, 140);
    Brain.Screen.printAt(265, 75, "Offense");

    DefenceAuton = true;
    OffenseAuton = false;
  }

  //Select Offense
  if (x >= 250 && y >= 40 && x <= 360 && y <= 180 && DriveSelect == false) 
  {
    Brain.Screen.setFillColor(black);
    Brain.Screen.drawRectangle(20, 40, 210, 140);
    Brain.Screen.printAt(25, 75, "Defence");

    Brain.Screen.setFillColor(green);
    Brain.Screen.drawRectangle(250, 40, 210, 140);
    Brain.Screen.printAt(265, 75, "Offense");

    DefenceAuton = false;
    OffenseAuton = true;
  }

  //Drive Select
  if (x >= 143 && y >= 190 && x <= 333 && y <= 230 && DefenceAuton == true || OffenseAuton == true) 
  {
    /*Brain.Screen.setFillColor(green);
    Brain.Screen.drawRectangle(143, 190, 190, 40);
    Brain.Screen.printAt(25, 75, "Defence");*/

    DriveSelect = true;
  }

 
  wait(10, msec); // slow it down
  Brain.Screen.setFillColor(black);
}


//Select Which Driver Controls We Want
void selectDrive() {

  

  int x = Brain.Screen.xPosition(); // get the x position of last touch of the screen
  int y = Brain.Screen.yPosition(); // get the y position of last touch of the screen

  if (x >= 20 && y >= 40 && x <= 210 && y <= 140) 
  {
    Brain.Screen.setFillColor(blue);
    Brain.Screen.drawRectangle(20, 40, 210, 140);
    Brain.Screen.printAt(25, 75, "Tank");

    Brain.Screen.setFillColor(purple);
    Brain.Screen.drawRectangle(250, 40, 210, 140);
    Brain.Screen.printAt(265, 75, "arcade");

    DefenceAuton = true;
    OffenseAuton = false;
  }

  //Select Offense
  if (x >= 250 && y >= 40 && x <= 360 && y <= 180) 
  {
    Brain.Screen.setFillColor(black);
    Brain.Screen.drawRectangle(20, 40, 210, 140);
    Brain.Screen.printAt(25, 75, "Defence");

    Brain.Screen.setFillColor(green);
    Brain.Screen.drawRectangle(250, 40, 210, 140);
    Brain.Screen.printAt(265, 75, "Offense");

    DefenceAuton = false;
    OffenseAuton = true;
  }

  //Drive Select
  if (x >= 143 && y >= 190 && x <= 333 && y <= 230 && DefenceAuton == true || OffenseAuton == true) 
  {
    Brain.Screen.setFillColor(green);
    Brain.Screen.drawRectangle(143, 190, 190, 40);
    Brain.Screen.printAt(25, 75, "Defence");

    DriveSelect = false;
  }
}

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
  Brain.Screen.setFont(monoM); 
  Brain.Screen.printAt(1, 40, "pre auton is running");
  drawGUI();
  Brain.Screen.pressed(selectAuton);
  
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
  switch (AutonSelected) {
  case 0:



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
  break;
    case 1:



    //Defence Auton
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  RightMotor.spinTo(850, deg, 100, rpm, false);
  LeftMotor.spinTo(850, deg, 100, rpm);

  wait(0.5, sec);
  ArmsMotorA.resetPosition();
  ArmsMotorB.resetPosition();
  ArmsMotorA.spinTo(2000, degrees, 200, rpm, false);
  ArmsMotorB.spinTo(2000, degrees, 200, rpm);
  //Arms.spinTo(2000, degrees, 200, rpm);

  wait(1, sec);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  RightMotor.spinTo(-850, deg, 100, rpm, false);
  LeftMotor.spinTo(-850, deg, 100, rpm);
  break;
  }
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

    //int leftY = Controller1.Axis3.position();
    //int rightX = Controller1.Axis4.position();
    int leftMotorSpeed = Controller1.Axis3.position();
    int rightMotorSpeed = Controller1.Axis2.position();

    //Arcade Drive
        // Move the left side of the robot
        /*LeftMotor.spin(forward, leftY + rightX, pct);
        
        // Move the right side of the robot 
        RightMotor.spin(forward, leftY - rightX, pct);*/


    //Tank Drive
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
    
    if (Controller1.ButtonB.pressing()) {
      Spinner.spin(forward, 600, rpm);
    }
    
    if (Controller1.ButtonA.pressing()) {
      Spinner.stop();
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
