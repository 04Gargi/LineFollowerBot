#include "Arduino.h"
#ifndef sl_h
#define sl_h

void digital();
void calibrateSensors();
void analog();
void iterate();
void stop();
void moveForward();
void calc();
void pid1_calc();

void s_req() {
  Serial.begin(115200);

  // Motor Control
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);

  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);

  //Sensor Input
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(in3, INPUT);
  pinMode(in4, INPUT);
  pinMode(in5, INPUT);
  pinMode(in6, INPUT);
  pinMode(in7, INPUT);
  pinMode(in8, INPUT);
  pinMode(in9, INPUT);
  pinMode(in10, INPUT);
  pinMode(in11, INPUT);
  pinMode(in12, INPUT);

  calibrateSensors();

  timer = millis();
  delay(2000);
}

void l_req() {
  digital();
  // analog();
  iterate();
  calc();
  pid1_calc();
  // if (allF) {
  //   // Serial.println("No line detected");
  //   if (millis() - timer > 1000) {
  //     stop();
  //     return;
  //   }
  // else {
  // Serial.println("Moving forward");
  moveForward();
  timer = millis();
  // }
  // }
  allF = false;
  juncn = false;
}
#endif