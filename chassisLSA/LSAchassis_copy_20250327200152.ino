#include <LSA08.h>
LSA08 L;
// #include <LSA08.h>
#include "Move.h"
#include "PID.h"
#include "Declarations.h"

#define analogpin A0

void setup() {
  // put your setup code here, to run once:
  L.AttachAnalogPin(A1);
  // Enable Debugger for the LSA.
  L.debugger.Initialize("LSA", &Serial);
  timer = millis();
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Turn off motors - Initial state

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  // delay(1000);
  // timer = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("hjljwvjo;");
  if (millis() - timer >= 5) {
    int pos = L.ReadLSA();
    Serial.print("pos:");
    Serial.print(pos);

    hgj = pid1(pos);
    ffg = pid2(pos);
    pwm = abs(base + hgj);
    pwm2 = abs(base2 + ffg);
    // pwm = base;

    pwm = constrain(pwm, 0, 200);
    pwm2 = constrain(pwm2, 0, 200);
    if (pos == 255)
      // moveBackward(pwm, pwm2);
      wait();

    // moveBackward(pwm, pwm2);
    // // else if (pos > 25 && pos < 55) {
    else moveForward(pwm, pwm2);

    // if (pos <= 10) {
    //   moveLeft(pwm, pwm2);
    // }
    // else if (pos >= 60)
    //   moveRight(pwm, pwm2);
    // if (pos == 255) {
    //   wait();
    //   // delay(200
    //   // moveBackward(pwm, pwm2);
    // }
    Serial.print("\t");
    Serial.print(" pwm:");
    Serial.print(pwm);
    Serial.print("\t");
    Serial.print("\t");
    Serial.print(" pwm2:");
    Serial.print(pwm2);
    Serial.print("\t");
  }
  // wait();
  // } else if (pos >= 55) {
  //   moveRight(pwm, pwm2);


  preverr = err;
  preverr2 = err2;
  timer = millis();
}
