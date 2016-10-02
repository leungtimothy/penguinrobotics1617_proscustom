#ifndef UTIL_H_
#define UTIL_H_

#define JOYSTICK_DEADZONE 15


/*
 * Use this function to ensure that the value being sent to the motors is within the correct range
 *
 *@param value of the motor
 *@return value of the motor between -127 to 127
 */
int motorCap(int value);

// needs documentation
int joystickCheckDeadzone(int value);

int cap(int value, int min, int max);

#endif
