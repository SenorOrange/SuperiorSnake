using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor_group LeftMotor;
extern motor_group RightMotor;
extern controller Controller1;
extern motor Intake;
//extern motor ArmsMotorB;
//extern motor_group Arms;
extern motor Launcher;
extern motor LeftMotorMotorA;
extern motor LeftMotorMotorB;
extern motor RightMotorMotorA;
extern motor RightMotorMotorB;
extern motor SpinnerA;
extern motor SpinnerB;
extern motor_group Spinner;
extern motor Wings;



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );