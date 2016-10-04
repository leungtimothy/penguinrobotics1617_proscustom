#ifndef LIBPENGU_H_
#define LIBPENGU_H_

#include <API.h>

#include "robot.h"

void motorInit(Motor *motor, short port, int direction);

void motorSetPower(Robot *robot, Channels channel, int power);

void robotAddDriveMotors(Robot *robot, Motor motors[], int size,
                         DriveMotorLocations location);

#endif
