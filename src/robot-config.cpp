#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftMotorMotorA = motor(PORT7, ratio18_1, true);
motor LeftMotorMotorB = motor(PORT11, ratio18_1, true);
motor_group LeftMotor = motor_group(LeftMotorMotorA, LeftMotorMotorB);
motor RightMotorMotorA = motor(PORT20, ratio18_1, false);
motor RightMotorMotorB = motor(PORT18, ratio18_1, false);
motor_group RightMotor = motor_group(RightMotorMotorA, RightMotorMotorB);
controller Controller1 = controller(primary);
motor ArmsMotorA = motor(PORT1, ratio18_1, true);
motor ArmsMotorB = motor(PORT10, ratio18_1, false);
motor_group Arms = motor_group(ArmsMotorA, ArmsMotorB);
motor Launcher = motor(PORT19, ratio6_1, true);




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