/** @file init.c
 * @brief File for initialization code
 *
 * This file should contain the user initialize() function and any functions
 * related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "../../pengu_lib/include/libpengu.h"
// TODO: rewrite makefile/common.mk so that this relative path isn't need

/*
 * Runs pre-initialization code. This function will be started in kernel mode
 * one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API
 * functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes
 * (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It
 * can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO() {}

/*
 * Runs user initialization code. This function will be started in its own task
 * with the default
 * priority and stack size once when the robot is starting up. It is possible
 * that the VEXnet
 * communication link may not be fully established at this time, so reading from
 * the VEX
 * Joystick may fail.
 *
 * This function should initialize most sensors (gyro, encoders, ultrasonics),
 * LCDs, global
 * variables, and IMEs.
 *
 * This function must exit relatively promptly, or the operatorControl() and
 * autonomous() tasks
 * will not start. An autonomous mode selection menu like the pre_auton() in
 * other environments
 * can be implemented in this task if desired.
 */
void initialize() {
	Motor fl[2];
	motorInit(&fl[0], 1, FORWARD);
	motorInit(&fl[1], 10, BACKWARD);

	Motor fr[1];
	motorInit(&fr[0], 6, BACKWARD);

	Motor bl[1];
	motorInit(&bl[0], 5, FORWARD);

	Motor br[2];
	motorInit(&br[0], 2, BACKWARD);
	motorInit(&br[1], 3, FORWARD);

	robotAddDriveMotors(&robot, fl, 2, FRONT_LEFT);
	robotAddDriveMotors(&robot, fr, 1, FRONT_RIGHT);
	robotAddDriveMotors(&robot, bl, 1, BACK_LEFT);
	robotAddDriveMotors(&robot, br, 2, BACK_RIGHT);
}
