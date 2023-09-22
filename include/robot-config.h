using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor_group LeftMotor;
extern motor_group RightMotor;
extern motor Arm;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );