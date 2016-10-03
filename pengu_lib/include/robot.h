#ifndef ROBOT_H_
#define ROBOT_H_

#include "drive.h"

typedef struct {
	DriveType driveType;
	DriveMotors driveMotors;
	DriveChannels driveChannels;
} Robot;

#endif
