#include "Arduino.h"
#ifndef sl_h
#define sl_h

void stop();
void moveForward();
void Forward();
void moveLeft();
void moveRight();
void slowdown();
void calibration();
void moveBackward();

void s_req() {
  L.AttachAnalogPin(A1);
  pinMode(A2, INPUT);
  calibration();
  // L.debugger.Initialize("LSA", &Serial);

  Serial.begin(115200);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  pinMode(junctionPulse, INPUT);

  delay(2000);
  timer = millis();
}

void l_req() {
  lsa_v = L.ReadLSA();
  // ir = analogRead(A2);
  // if (ir > t) thresh = true;
  // else thresh = false;
  // !thresh &&

  timer = millis();
  if (lsa_v == 255) {
    // stop();
    moveBackward();
  } 
  else if (digitalRead(junctionPulse)) {
    if (lsa_v >= 45)
      moveRight();
    else if (lsa_v >= 30 && lsa_v <45) {
      Forward();
    } else if (lsa_v < 30) {
      moveLeft();
    }
    // else moveBackward();
  }
   else {
    moveForward();
  }
  timer = millis();
#ifdef pri
  Serial.print("lsa: ");
  Serial.print(lsa_v);
  Serial.print("\t");
  Serial.print("cnt: ");
  Serial.print(cnt);
  Serial.print("\t");
  Serial.print("thresh: ");
  Serial.print(thresh);
  Serial.print("\t");
  Serial.print("jncn: ");
  Serial.print(digitalRead(junctionPulse));
  Serial.print("\t");
#endif
}

#endif