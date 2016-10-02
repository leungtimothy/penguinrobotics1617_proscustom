#include <API.h>
//#include <main.h>

#ifndef AUTO_FUNCTIONS_H
#define AUTO_FUNCTIONS_H

typedef enum Turn_Directions {
	LEFT,
	RIGHT
} Turn_Directions;

/**
 * Use this function command the robot to rotate about its Z axis using the data obtained via the gyroscope.
 *
 * @param turnDirection Choose LEFT or RIGHT for direction of turn.
 * @param targetDegrees the amount of degrees the robot will rotate relative to its original bearing.
 *
 */
void driveGyroTurn(Turn_Directions turnDirection, int targetDegrees, Gyro *gyro);

#endif
