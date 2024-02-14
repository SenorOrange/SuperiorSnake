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
bool ArcadeDrive = true;
bool FunkyTownDrive = false;

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
  if (x >= 20 && y >= 40 && x <= 230 && y <= 180 && DriveSelect == false) 
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

  //Select Tank
  if (x >= 20 && y >= 40 && x <= 160 && y <= 180 && DriveSelect == true) 
  {
    Brain.Screen.setFillColor(black);
    Brain.Screen.drawRectangle(170, 40, 140, 140);
    Brain.Screen.printAt(175, 75, "Funky Town");
    Brain.Screen.drawRectangle(320, 40, 140, 140);
    Brain.Screen.printAt(325, 75, "Arcade");

    Brain.Screen.setFillColor(green);
    Brain.Screen.drawRectangle(20, 40, 140, 140);
    Brain.Screen.printAt(25, 75, "Tank");

    TankDrive = true;
    FunkyTownDrive = false;
    ArcadeDrive = false;
  }
  
  //Select Funky Town
  if (x >= 170 && y >= 40 && x <= 310 && y <= 180 && DriveSelect == true) 
  {
    Brain.Screen.setFillColor(black);
    Brain.Screen.drawRectangle(20, 40, 140, 140);
    Brain.Screen.printAt(25, 75, "Tank");
    Brain.Screen.drawRectangle(320, 40, 140, 140);
    Brain.Screen.printAt(325, 75, "Arcade");

    Brain.Screen.setFillColor(green);
    Brain.Screen.drawRectangle(170, 40, 140, 140);
    Brain.Screen.printAt(175, 75, "Funky Town");

    TankDrive = false;
    FunkyTownDrive = true;
    ArcadeDrive = false;
  }

  //Select Arcade
  if (x >= 320 && y >= 40 && x <= 460 && y <= 180 && DriveSelect == true) 
  {
    Brain.Screen.setFillColor(black);
    Brain.Screen.drawRectangle(20, 40, 140, 140);
    Brain.Screen.printAt(25, 75, "Tank");
    Brain.Screen.drawRectangle(170, 40, 140, 140);
    Brain.Screen.printAt(175, 75, "Funky Town");

    Brain.Screen.setFillColor(green);
    Brain.Screen.drawRectangle(320, 40, 140, 140);
    Brain.Screen.printAt(325, 75, "Arcade");

    TankDrive = false;
    FunkyTownDrive = false;
    ArcadeDrive = true;
  }

  //Change Select
  if (x >= 143 && y >= 190 && x <= 333 && y <= 230) 
  {
    //Change Select
    if(DriveSelect == true)
    {
      //Auton Select
      DriveSelect = false;
      Brain.Screen.clearScreen();
      Brain.Screen.setFillColor(black);
      Brain.Screen.printAt(180, 30, "Select Auton");
      Brain.Screen.drawRectangle(20, 40, 210, 140);
      Brain.Screen.printAt(25, 75, "Defence");
      Brain.Screen.drawRectangle(250, 40, 210, 140);
      Brain.Screen.printAt(265, 75, "Offense");
      Brain.Screen.drawRectangle(143, 190, 190, 40);
      Brain.Screen.printAt(180, 215, "Drive Select");

    } else {
      //Drive Select
      DriveSelect = true;
      Brain.Screen.clearScreen();
      Brain.Screen.setFillColor(black);
      Brain.Screen.printAt(180, 30, "Select Drive");
      Brain.Screen.drawRectangle(20, 40, 140, 140);
      Brain.Screen.printAt(25, 75, "Tank");
      Brain.Screen.drawRectangle(170, 40, 140, 140);
      Brain.Screen.printAt(175, 75, "Funky Town");
      Brain.Screen.drawRectangle(320, 40, 140, 140);
      Brain.Screen.printAt(325, 75, "Arcade");
      Brain.Screen.drawRectangle(143, 190, 190, 40);
      Brain.Screen.printAt(180, 215, "Auton Select");
      
    }
  }

 
  wait(10, msec); // slow it down
  Brain.Screen.setFillColor(black);
}


//Select Which Driver Controls We Want


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
  
  if(OffenseAuton == true)
  {
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  Arms.resetPosition();
 //straight
  RightMotor.spinTo(390, deg, 100, rpm, false);
  LeftMotor.spinTo(390, deg, 100, rpm);
  wait(0.2, sec);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  //turn right
  RightMotor.spinTo(-220, deg, 100, rpm, false);
  LeftMotor.spinTo(220, deg, 100, rpm);
  wait(0.2, sec);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  //straight
  RightMotor.spinTo(600, deg, 100, rpm, false);
  LeftMotor.spinTo(600, deg, 100, rpm);
  wait(0.2, sec);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  //turn right
  RightMotor.spinTo(220, deg, 100, rpm, false);
  LeftMotor.spinTo(-220, deg, 100, rpm);
  wait(0.2, sec);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  //straight
  RightMotor.spinTo(210, deg, 100, rpm, false);
  LeftMotor.spinTo(210, deg, 100, rpm);
  wait(0.2, sec);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  //Arms
  Arms.spinTo(-2009, deg, 350, rpm);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  //Backup
  RightMotor.spinTo(-100, deg, 100, rpm, false);
  LeftMotor.spinTo(-100, deg, 100, rpm);
  wait(0.2, sec);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  //Slight Turn
  RightMotor.spinTo(600, deg, 100, rpm, false);
  LeftMotor.spinTo(-600, deg, 100, rpm);
  wait(2, sec);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  //straight
  RightMotor.spinTo(-180, deg, 100, rpm, false);
  LeftMotor.spinTo(-180, deg, 100, rpm);
  wait(0.2, sec);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  //Backup
  RightMotor.spinTo(180, deg, 100, rpm, false);
  LeftMotor.spinTo(180, deg, 100, rpm);
  }



  if(DefenceAuton == true)
  {
  //Spinner.spin(forward, 600, rpm);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  RightMotor.spinTo(850, deg, 100, rpm, false);
  LeftMotor.spinTo(850, deg, 100, rpm);

  wait(0.5, sec);
  ArmsMotorA.resetPosition();
  ArmsMotorB.resetPosition();
  ArmsMotorA.spinTo(-2000, degrees, 200, rpm, false);
  ArmsMotorB.spinTo(-2000, degrees, 200, rpm);
  //Arms.spinTo(2000, degrees, 200, rpm);

  wait(1, sec);
  RightMotor.resetPosition();
  LeftMotor.resetPosition();
  RightMotor.spinTo(-850, deg, 100, rpm, false);
  LeftMotor.spinTo(-850, deg, 100, rpm);
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

    int Axis3 = Controller1.Axis3.position();
    int Axis4 = Controller1.Axis4.position();
    int Axis2 = Controller1.Axis2.position();
    int Axis1 = Controller1.Axis1.position();
    int leftMotorSpeed = Controller1.Axis3.position();
    int rightMotorSpeed = Controller1.Axis2.position();
    bool SpinnerOff = true;
    

    if(ArcadeDrive == true)
    {
     LeftMotor.spin(forward, Axis3 + Axis4, percent);
     RightMotor.spin(forward, Axis3 - Axis4, percent);
    }

    if(TankDrive == true)
    {
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
    }

    if(FunkyTownDrive == true)
    {
      
      if (abs(Axis3) < deadband) {
        LeftMotor.setVelocity(0, percent);
        RightMotor.setVelocity(0, percent);

        if (abs(Axis1) < deadband) {
        LeftMotor.setVelocity(0, percent);
        RightMotor.setVelocity(0, percent);
      } else {
        LeftMotor.setVelocity(Axis1, percent);
        RightMotor.setVelocity(0 - Axis1, percent);
      }
      } else {
        LeftMotor.setVelocity(Axis3, percent);
        RightMotor.setVelocity(Axis3, percent);
      }

      LeftMotor.spin(forward);
      RightMotor.spin(forward);
    }
  

    //Arms Code
    if (Controller1.ButtonL1.pressing()) {
      Arms.spin(reverse, 200, rpm);
    }

    if (Controller1.ButtonR1.pressing()) {
      Arms.spin(forward, 200, rpm);
    }

    if (Controller1.ButtonL2.pressing()) {
      Arms.stop();
    }

    //Spinner Code
    if (Controller1.ButtonB.pressing()) {
      Spinner.spin(forward, 600, rpm);
    }

    if (Controller1.ButtonA.pressing()) {
      Spinner.stop();
    }
    
    //Controller Screen
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print(Spinner.temperature(fahrenheit));
    Controller1.Screen.print("|");
    Controller1.Screen.setCursor(1, 18);
    Controller1.Screen.print("|");
    Controller1.Screen.print(Spinner.temperature(fahrenheit));
    Controller1.Screen.setCursor(2, 1);
    Controller1.Screen.print("____|           |_____");
    Controller1.Screen.setCursor(3, 10);
    Controller1.Screen.print(Spinner.velocity(rpm));

    
    

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
