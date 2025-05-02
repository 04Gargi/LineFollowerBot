#include "Arduino.h"
#ifndef sl_h
#define sl_h

// Function Declarations
void stop();
void moveForward();
// void Forward();
void moveLeft();
void moveRight();
void slowdown();
void calibration();
void moveBackward();
void calc();
void pid1_calc();
void pid_calc();
void digital();
void decision();
void decelerate();
void jn_digital();
void nojndecision();

// Setup function
void s_req() {
  L.AttachAnalogPin(A1);
  // pinMode(A2, INPUT);
  // calibration();
  // L.debugger.Initialize("LSA", &Serial);

  Serial.begin(115200);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(lm, INPUT);
  pinMode(rm, INPUT);
  pinMode(l, INPUT);
  pinMode(r, INPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  pinMode(junctionPulse, INPUT);
  timer = millis();
  delay(2000);
}

// Main loop logic
void l_req() {
  lsa_v = L.ReadLSA();  // get analog sensor value
  digital();            // read digital line sensors

  calc();       // PID helper calculations
  pid1_calc();  // main PID logic

  if (lsa_v == 255) {  // no line condition
    if (millis() - timer > 1000) {
      stop();
      return;
    }
  } else if (digitalRead(junctionPulse)) {
    jn_digital();
    decision();
    timer = millis();
  } else {
    nojndecision();  // for straight or turns not at junctions
    moveForward();
    zz = false;
    timer1 = millis();
    timer = millis();
  }

#ifdef pri
  Serial.print("lsa: ");
  Serial.print(lsa_v);
  Serial.print("\t");
  Serial.print("jncn: ");
  Serial.print(digitalRead(junctionPulse));
  Serial.print("\t");
#endif
}

#endif
