#ifndef MOTOR_H_
#define MOTOR_H_

#define FORWARD 1
#define BACKWARD -1

typedef struct {
	short port;
	int power;
	int direction;
} Motor;

#endif
