#pragma config(Sensor, in1,    LauncherPot,    sensorPotentiometer)
#pragma config(Sensor, dgtl1,  solenoid,       sensorDigitalOut)
#pragma config(Motor,  port2,           frontright,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           middleright,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           backright,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           frontleft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           middleleft,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           backleft,      tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c" //Main competition background code...do not modify!
#define DEADBAND 15
int scaleJoystick (int input);

/////////////////////////////////////////////////////////////////////////////////////////
//
// Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
	// .....................................................................................
	// Insert user code here.
	// .....................................................................................
}

/////////////////////////////////////////////////////////////////////////////////////////
//
// User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
		int channel3 = scaleJoystick (vexRT[Ch3]);
		int channel1 = scaleJoystick (vexRT[Ch1]);
		motor[frontright] = motor[middleright] = motor[backright] = channel3 - channel1;
		motor[frontleft] = motor[middleleft] = motor[backleft] = channel3 + channel1;
	}
}
int scaleJoystick (int input)
{
	if(input > DEADBAND)
		return input;
	else
		if (input < -DEADBAND)
		return input;
	else
		return 0;
}
