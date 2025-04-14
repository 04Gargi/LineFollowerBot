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
void calc();
void pid1_calc();
void pid_calc();

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
  timer = millis();
  delay(2000);
}

void l_req() {
  lsa_v = L.ReadLSA();

  calc();
  pid1_calc();

  if (lsa_v == 255) {
    if (millis() - timer > 1000) {
      stop();
    }
    // moveBackward();

  } else if (digitalRead(junctionPulse)) {
    if (pwm1 < 0) {
      digitalWrite(in1, 1);
      digitalWrite(in2, 0);
      digitalWrite(in3, 0);
      digitalWrite(in4, 1);
      analogWrite(enA, 80);
      analogWrite(enB, 80);
    } else if (pwm2 < 0) {
      digitalWrite(in1, 0);
      digitalWrite(in2, 1);
      digitalWrite(in3, 1);
      digitalWrite(in4, 0);
      analogWrite(enA, 80);
      analogWrite(enB, 80);
    } else Forward();

    timer = millis();
  } else {
    moveForward();
  }
#ifdef pri
  Serial.print("lsa: ");
  Serial.print(lsa_v);
  Serial.print("\t");
  Serial.print("cnt: ");
  Serial.print(cnt);

  Serial.print("\t");
  Serial.print("jncn: ");
  Serial.print(digitalRead(junctionPulse));
  Serial.print("\t");
#endif
}

#endif