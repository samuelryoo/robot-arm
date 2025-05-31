#include "main.hpp"
#include "stepper.hpp"

bool done = 0;

void setup() {
  pinMode(RPS_INPUT, INPUT);
  pinMode(RPS_OUTPUT, OUTPUT);
  digitalWrite(RPS_OUTPUT, LOW);

  stepper_setup();
}

void loop() {
    if (!digitalRead(RPS_INPUT)) {
      rps();
    }
  }

void rps() {
  for (int i = 0; i < 3; ++i) {
    elbowMotor.moveTo(400);
    while (elbowMotor.isRunning()) {
      elbowMotor.run();
    }
    if (i != 2) {
      elbowMotor.moveTo(0);
      while (elbowMotor.isRunning()) {
        elbowMotor.run();
      }
    } else {
      digitalWrite(RPS_OUTPUT, HIGH);
      delay(50);
      digitalWrite(RPS_OUTPUT, LOW);
    }
  }
  delay(5000);
  elbowMotor.moveTo(0);
  while (elbowMotor.isRunning()) {
    elbowMotor.run();
  }
}
