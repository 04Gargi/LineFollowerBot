#include "Arduino.h"
#ifndef sl_h
#define sl_h

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

void l_req() {
  lsa_v = L.ReadLSA();  //get analog
  digital();            //get digital

  calc();       //calculate helper for pid
  pid1_calc();  // pid calc

  if (lsa_v == 255) {  //no line condn
    if (millis() - timer > 1000) {
      stop();
      return;
    }


  } else if (digitalRead(junctionPulse)) {
    jn_digital();
    decision();
    // moveRight();

    timer = millis();
  } else {
    moveForward();
    zz = false;
    timer1 = millis();
    timer = millis();
  }
#ifdef pri
  Serial.print("lsa: ");
  Serial.print(lsa_v);
  Serial.print("\t");
  Serial.print("cnt1: ");
  Serial.print(cnt1);
  Serial.print("\t");
  Serial.print("cnt2: ");
  Serial.print(cnt2);
  Serial.print("\t");
  Serial.print("jncn: ");
  Serial.print(digitalRead(junctionPulse));
  Serial.print("\t");
#endif
}

#endif