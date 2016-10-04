#ifndef LIBPENGU_H_
#define LIBPENGU_H_

#include <API.h>

#include "robot.h"

void robotSetDriveType(Robot *robot, DriveType driveType);

void robotAddDriveMotors(Robot *robot, Motor motors[], int size,
                         DriveMotorLocations location);

void motorSetPower(Robot *robot, Channels channel, int power);

#endif
