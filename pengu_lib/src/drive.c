#include "drive.h"

void driveSetType(Robot * robot, DriveType driveType) {
	robot->driveType = driveType;
}

int motorsGetSize(Robot * robot, DriveMotorLocations location) {
	int size;
	switch (location) {
	case LEFT_SIDE:
		size = sizeof(robot->driveMotors.left)/sizeof(robot->driveMotors.left[0]);
		break;
	case RIGHT_SIDE:
		size = sizeof(robot->driveMotors.right)/sizeof(robot->driveMotors.right[0]);
		break;
	case FRONT_LEFT:
		size = sizeof(robot->driveMotors.frontLeft)/sizeof(robot->driveMotors.frontLeft[0]);
		break;
	case FRONT_RIGHT:
		size = sizeof(robot->driveMotors.frontRight)/sizeof(robot->driveMotors.frontRight[0]);
		break;
	case BACK_LEFT:
		size = sizeof(robot->driveMotors.backLeft)/sizeof(robot->driveMotors.backLeft[0]);
		break;
	case BACK_RIGHT:
		size = sizeof(robot->driveMotors.backLeft)/sizeof(robot->driveMotors.backRight[0]);
		break;
	case STRAFE:
		size = sizeof(robot->driveMotors.strafe)/sizeof(robot->driveMotors.strafe[0]);
		break;
	}
	return size;
}

void driveAddMotor(Robot * robot, short port, int power, int direction, DriveMotorLocations location) {
	// create new motor with parameters
	Motor motor;
	motor.port = port;
	motor.power = power;
	motor.direction = direction;

	int n;

	// insert robot in to proper motor array
	switch (robot->driveType) {
	case TANK:
	case H_HOLO:
		switch (location) {
		case LEFT_SIDE:
			n = motorsGetSize(robot, LEFT_SIDE);
			robot->driveMotors.left[n-1] = motor;
			break;
		case RIGHT_SIDE:
			n = motorsGetSize(robot, RIGHT_SIDE);
			robot->driveMotors.right[n-1] = motor;
			break;
		case STRAFE:
			n = motorsGetSize(robot, STRAFE);
			robot->driveMotors.strafe[n-1] = motor;
		}
		break;
	case X_HOLO:
		switch (location) {
		case FRONT_LEFT:
			n = motorsGetSize(robot, FRONT_LEFT);
			robot.driveMotors.frontLeft[n-1] = motor;
			break;
		case FRONT_RIGHT:
			n = motorsGetSize(robot, FRONT_RIGHT);
			robot.driveMotors.frontRight[n-1] = motor;
			break;
		case BACK_LEFT:
			n = motorsGetSize(robot, BACK_LEFT);
			robot.driveMotors.backLeft[n-1] = motor;
			break;
		case BACK_RIGHT:
			n = motorsGetSize(robot, BACK_RIGHT);
			robot.driveMotors.backRight[n-1] = motor;
			break;
		}
		break;
	}
}

void motorSetPower(Robot * robot, Channels channel, int power) {
	switch (robot->driveType) {
	case TANK:
		switch (channel) {
		case LEFT:
			robot->driveChannels.left = power;
			for (int i = 0; i < motorsGetSize(robot, LEFT); i++) {
				motorSet(robot->driveMotors.left[i].port, robot->driveChannels.left * robot->driveMotors.left[i].direction);
			}
			break;
		case RIGHT:
			robot->driveChannels.right = power;
			for (int i = 0; motorsGetSize(robot, RIGHT); i++) {
				motorSet(robot->driveMotors.right[i].port, robot->driveChannels.right * robot->driveMotors.right[i].direction);
			}
			break;
		}
		break;

	case X_HOLO:
	case H_HOLO:
		switch (channel) {
		case X:
			robot->driveChannels.x = power;
			break;
		case Y:
			robot->driveChannels.y = power;
			break;
		case YAW:
			robot->driveChannels.yaw = power;
			break;
		}
		if (robot->driveType == X_HOLO) {
			// set all motor values
			for (int i = 0; motorsGetSize(robot, FRONT_LEFT); i++) {
				motorSet(robot->driveMotors.frontLeft[i].port,
						(robot->driveChannels.x + robot->driveChannels.y + robot->driveChannels.yaw) * robot->driveMotors.frontLeft[i].direction);
			}

			for (int i = 0; motorsGetSize(robot, FRONT_RIGHT); i++) {
				motorSet(robot->driveMotors.frontRight[i].port,
						(robot->driveChannels.x - robot->driveChannels.y - robot->driveChannels.yaw) * robot->driveMotors.frontRight[i].direction);
			}

			for (int i = 0; motorsGetSize(robot, BACK_LEFT); i++) {
				motorSet(robot->driveMotors.backLeft[i].port,
						(robot->driveChannels.x - robot->driveChannels.y + robot->driveChannels.yaw) * robot->driveMotors.backLeft[i].direction);
			}

			for (int i = 0; motorsGetSize(robot, FRONT_RIGHT); i++) {
				motorSet(robot->driveMotors.backRight[i].port,
						(robot->driveChannels.x + robot->driveChannels.y - robot->driveChannels.yaw) * robot->driveMotors.backRight[i].direction);
			}
		} else if (robot->driveType == H_HOLO) {
			for (int i = 0; motorsGetSize(robot, LEFT); i++) {
				motorSet(robot->driveMotors.left[i].port,
						(robot->driveChannels.y + robot->driveChannels.x) * robot->driveMotors.left[i].direction);
			}

			for (int i = 0; motorsGetSize(robot, RIGHT); i++) {
				motorSet(robot->driveMotors.right[i].port,
						(robot->driveChannels.y - robot->driveChannels.x) * robot->driveMotors.right[i].direction);
			}

			for (int i = 0; motorsGetSize(robot, STRAFE); i++) {
				motorSet(robot->driveMotors.strafe[i].port, robot->driveChannels.yaw * robot->driveMotors.strafe[i].direction);
			}
		}
		break;
	}
}
