#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftMotorMotorA = motor(PORT12, ratio18_1, false);
motor LeftMotorMotorB = motor(PORT3, ratio18_1, false);
motor_group LeftMotor = motor_group(LeftMotorMotorA, LeftMotorMotorB);
motor RightMotorMotorA = motor(PORT2, ratio18_1, true);
motor RightMotorMotorB = motor(PORT4, ratio18_1, true);
motor_group RightMotor = motor_group(RightMotorMotorA, RightMotorMotorB);
controller Controller1 = controller(primary);
motor ArmsMotorA = motor(PORT11, ratio18_1, false);
motor ArmsMotorB = motor(PORT1, ratio18_1, true);
motor Spinner = motor(PORT21, ratio6_1, true);
motor_group Arms = motor_group(ArmsMotorA, ArmsMotorB);
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