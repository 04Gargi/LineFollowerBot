#ifndef Move_H
#define Move_H
#include "Declarations.h"
void moveRight(int pwm,int pwm2) {
  // For robot to move left, right motor has to be faster than left motor
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(enA, pwm-20);
  analogWrite(enB, pwm2-20);
  Serial.print("Rightt");
}

void moveLeft(int pwm,int pwm2) {
  // For robot to move right, left motor has to be faster than right motor
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  analogWrite(enA, pwm-20);
  analogWrite(enB, pwm2-20);
  Serial.print("Left");
}

void moveForward(int pwm,int pwm2) {
  // For robot to move forward, both motors have to be same speed
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(enA, pwm);
  analogWrite(enB, pwm2);
  Serial.print("Forward");
}
void wait() {
  // Function to makes the robot stay
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
void moveBackward(int pwm,int pwm2) {
  // For robot to move forward, both motors have to be same speed
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  analogWrite(enA, pwm);
  analogWrite(enB, pwm2);
  Serial.print("Backward");
}

#endif