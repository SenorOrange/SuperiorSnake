#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftMotorMotorA = motor(PORT10, ratio18_1, false);
motor LeftMotorMotorB = motor(PORT4, ratio18_1, false);
motor_group LeftMotor = motor_group(LeftMotorMotorA, LeftMotorMotorB);
motor RightMotorMotorA = motor(PORT5, ratio18_1, true);
motor RightMotorMotorB = motor(PORT3, ratio18_1, true);
motor_group RightMotor = motor_group(RightMotorMotorA, RightMotorMotorB);
controller Controller1 = controller(primary);
motor Intake = motor(PORT2, ratio18_1, false);
//motor ArmsMotorB = motor(PORT1, ratio18_1, true);
//motor_group Arms = motor_group(ArmsMotorA);
motor SpinnerA = motor(PORT7, ratio6_1, false);
motor SpinnerB = motor(PORT20, ratio6_1, true);
motor_group Spinner = motor_group(SpinnerA, SpinnerB);
motor Wings = motor(PORT6, ratio36_1, false);

//ports 8, 9 are dead ports


//motor LauncherA = motor(PORT19, ratio36_1, true);
//motor LauncherB = motor(PORT18, ratio18_1, false);
//motor_group Launcher = motor_group(LauncherA);


// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}