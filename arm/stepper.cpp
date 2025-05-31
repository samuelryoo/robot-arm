#include "stepper.hpp"

//For the motor that rotates the base
AccelStepper baseMotor(InterfaceType, Y_STEP_PIN, Y_DIR_PIN);

//For the 2 motors that move the shoulder joint
AccelStepper leftMotor(InterfaceType, X_STEP_PIN, X_DIR_PIN);
AccelStepper rightMotor(InterfaceType, Z_STEP_PIN, Z_DIR_PIN);

//For the motor that moves the elbow joint
AccelStepper elbowMotor(InterfaceType, E0_STEP_PIN, E0_DIR_PIN);

//For the motor that moves the wrist joint
AccelStepper wristMotor(InterfaceType, E1_STEP_PIN, E1_DIR_PIN);

void stepper_setup() {
  //400 and 200 are temporary values
  //we will have to play around with the hardware a bit
  //before the desired speed/acceleration is found
  baseMotor.setMaxSpeed(400);
  baseMotor.setAcceleration(200);
  baseMotor.setEnablePin(Y_EN_PIN);
  baseMotor.setPinsInverted(false, false, true);
  baseMotor.enableOutputs();

  leftMotor.setMaxSpeed(400);
  leftMotor.setAcceleration(200);
  leftMotor.setEnablePin(X_EN_PIN);
  leftMotor.setPinsInverted(true, false, true);
  leftMotor.enableOutputs();

  rightMotor.setMaxSpeed(400);
  rightMotor.setAcceleration(200);
  rightMotor.setEnablePin(Z_EN_PIN);
  rightMotor.setPinsInverted(false, false, true);
  rightMotor.enableOutputs();

  elbowMotor.setMaxSpeed(1000);
  elbowMotor.setAcceleration(400);
  elbowMotor.setEnablePin(E0_EN_PIN);
  elbowMotor.setPinsInverted(false, false, true);
  elbowMotor.enableOutputs();

  wristMotor.setMaxSpeed(400);
  wristMotor.setAcceleration(200);
  wristMotor.setEnablePin(E1_EN_PIN);
  wristMotor.setPinsInverted(false, false, true);
  wristMotor.enableOutputs();
}

void moveShoulder(int steps) {
  rightMotor.moveTo(steps);
  leftMotor.moveTo(steps);
}

void runShoulder() {
  rightMotor.run();
  leftMotor.run();
}
