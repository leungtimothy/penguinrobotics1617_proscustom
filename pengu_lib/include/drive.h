#ifndef DRIVE_H_
#define DRIVE_H_

#include "API.h"
#include "motor.h"
#include "robot.h"

typedef enum {
	TANK,
	X_HOLO,
	H_HOLO
} DriveType;

typedef enum {
	// Tank
	LEFT_SIDE,
	RIGHT_SIDE,

	// X-Holonomic
	FRONT_LEFT,
	FRONT_RIGHT,
	BACK_LEFT,
	BACK_RIGHT,

	// H-Holonomic
	STRAFE
} DriveMotorLocations;

typedef enum {
	LEFT,
	RIGHT,

	X,
	Y,
	YAW
} Channels;

typedef struct {
	// if tank/h-holo
	Motor left[5];
	Motor right[5];

	// if x-holo
	Motor frontLeft[4];
	Motor frontRight[4];
	Motor backLeft[4];
	Motor backRight[4];

	// if h-holo
	Motor strafe[2];
} DriveMotors;

typedef struct {
	// if tank
	int left;
	int right;

	// if holo
	int x;
	int y;
	int yaw;
} DriveChannels;

void driveSetType(Robot *robot, DriveType driveType);
int motorsGetSize(Robot *robot, DriveMotorLocations location);
void driveAddMotor(Robot *robot, short port, int power, int direction, DriveMotorLocations location);

#endif
