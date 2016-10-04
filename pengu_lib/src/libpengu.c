#include "libpengu.h"

void motorInit(Motor *motor, short port, int direction) {
	motor->port = port;
	motor->direction = direction;
}

void motorSetPower(Robot *robot, Channels channel, int power) {
  switch (robot->driveType) {
  case TANK:
    switch (channel) {
    case LEFT_SIDE:
      robot->driveChannels.left = power;
      for (int i = 0; i < robot->driveMotors.left.size; i++) {
        motorSet(robot->driveMotors.left.motors[i].port,
                 robot->driveChannels.left *
                     robot->driveMotors.left.motors[i].direction);
      }
      break;
    case RIGHT_SIDE:
      robot->driveChannels.right = power;
      for (int i = 0; robot->driveMotors.left.size; i++) {
        motorSet(robot->driveMotors.right.motors[i].port,
                 robot->driveChannels.right *
                     robot->driveMotors.right.motors[i].direction);
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
      for (int i = 0; robot->driveMotors.frontLeft.size; i++) {
        motorSet(robot->driveMotors.frontLeft.motors[i].port,
                 (robot->driveChannels.x + robot->driveChannels.y +
                  robot->driveChannels.yaw) *
                     robot->driveMotors.frontLeft.motors[i].direction);
      }

      for (int i = 0; robot->driveMotors.frontRight.size; i++) {
        motorSet(robot->driveMotors.frontRight.motors[i].port,
                 (robot->driveChannels.x - robot->driveChannels.y -
                  robot->driveChannels.yaw) *
                     robot->driveMotors.frontRight.motors[i].direction);
      }

      for (int i = 0; robot->driveMotors.backLeft.size; i++) {
        motorSet(robot->driveMotors.backLeft.motors[i].port,
                 (robot->driveChannels.x - robot->driveChannels.y +
                  robot->driveChannels.yaw) *
                     robot->driveMotors.backLeft.motors[i].direction);
      }

      for (int i = 0; robot->driveMotors.backRight.size; i++) {
        motorSet(robot->driveMotors.backRight.motors[i].port,
                 (robot->driveChannels.x + robot->driveChannels.y -
                  robot->driveChannels.yaw) *
                     robot->driveMotors.backRight.motors[i].direction);
      }
    } else if (robot->driveType == H_HOLO) {
      for (int i = 0; robot->driveMotors.left.size; i++) {
        motorSet(robot->driveMotors.left.motors[i].port,
                 (robot->driveChannels.y + robot->driveChannels.x) *
                     robot->driveMotors.left.motors[i].direction);
      }

      for (int i = 0; robot->driveMotors.right.size; i++) {
        motorSet(robot->driveMotors.right.motors[i].port,
                 (robot->driveChannels.y - robot->driveChannels.x) *
                     robot->driveMotors.right.motors[i].direction);
      }

      for (int i = 0; robot->driveMotors.strafe.size; i++) {
        motorSet(robot->driveMotors.strafe.motors[i].port,
                 robot->driveChannels.yaw *
                     robot->driveMotors.strafe.motors[i].direction);
      }
    }
    break;
  }
}

void robotAddDriveMotors(Robot *robot, Motor motors[], int size,
                         DriveMotorLocations location) {
  switch (location) {
  case LEFT_SIDE:
    for (int i = 0; i < size; i++) {
      robot->driveMotors.left.motors[i] = motors[i];
    }
    robot->driveMotors.left.size = size;
    break;
  case RIGHT_SIDE:
    for (int i = 0; i < size; i++) {
      robot->driveMotors.right.motors[i] = motors[i];
    }
    robot->driveMotors.right.size = size;
    break;

  case FRONT_LEFT:
    for (int i = 0; i < size; i++) {
      robot->driveMotors.frontLeft.motors[i] = motors[i];
    }
    robot->driveMotors.frontLeft.size = size;
    break;
  case FRONT_RIGHT:
    for (int i = 0; i < size; i++) {
      robot->driveMotors.frontRight.motors[i] = motors[i];
    }
    robot->driveMotors.frontRight.size = size;
    break;
  case BACK_LEFT:
    for (int i = 0; i < size; i++) {
      robot->driveMotors.backLeft.motors[i] = motors[i];
    }
    robot->driveMotors.backLeft.size = size;
    break;
  case BACK_RIGHT:
    for (int i = 0; i < size; i++) {
      robot->driveMotors.backRight.motors[i] = motors[i];
    }
    robot->driveMotors.backRight.size = size;
    break;
  case STRAFE:
    for (int i = 0; i < size; i++) {
      robot->driveMotors.strafe.motors[i] = motors[i];
    }
    robot->driveMotors.strafe.size = size;
    break;
  }
}
