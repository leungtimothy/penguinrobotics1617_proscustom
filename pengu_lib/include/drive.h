#ifndef DRIVE_H_
#define DRIVE_H_

#include "motor.h"

typedef enum { TANK, X_HOLO, H_HOLO } DriveType;

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
  MotorArray left;
  MotorArray right;

  // if x-holo
  MotorArray frontLeft;
  MotorArray frontRight;
  MotorArray backLeft;
  MotorArray backRight;

  // if h-holo
  MotorArray strafe;
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

#endif
