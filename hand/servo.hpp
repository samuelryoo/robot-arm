#ifndef _SERVO_HPP
#define _SERVO_HPP

#include <Servo.h>

extern Servo fingersUp;
extern Servo fingersDown;
extern Servo thumbUp;
extern Servo thumbDown;

#define SERVO0 3
#define SERVO1 5
#define SERVO2 6
#define SERVO3 9

void servoSetup();

#endif /* _SERVO_HPP */
