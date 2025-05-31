#include "servo.hpp"

Servo thumbUp;
Servo thumbDown;
Servo fingersUp;
Servo fingersDown;

void servoSetup() {
  fingersUp.attach(SERVO0);
  fingersDown.attach(SERVO1);
  thumbUp.attach(SERVO2);
  thumbDown.attach(SERVO3);
}
