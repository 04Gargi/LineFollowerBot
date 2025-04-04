#ifndef PID_H
#define PID_H

#include "Declarations.h"
#include "PID.h"

float pid1(int pos) {
  float kp1 = 5, kd1 = 0.08;
  err = setp - pos;
  // differr = err - preverr;
  // differr = alpha * (err2 - preverr) + (1 - alpha) * differr;
  // sumerr += err;
  float pid = (kp1 * err);  // - (kd1 * differr);
  pwm = (base + pid);
  pwm = constrain(pwm, 0, 200);
  // Serial.print(" pid:");
  // Serial.print(pid);
  // Serial.print("\t");
  // Serial.print(" err:");
  // Serial.print(err);
  // Serial.print("\t");
  // Serial.print(" diferr:");
  // Serial.print(differr);
  // Serial.print("\t");
  return pwm;
}

float pid2(int pos) {
  float kp2 = 5, kd2 = 0.15;

  err2 = pos - setp;
  int differr2 = err2 - preverr2;
  // int differr2 = alpha * (err2 - preverr2) + (1 - alpha) * differr2;
  // sumerr2 += err2;
  float pid = (kp2 * err2);  //- (kd2 * differr2);
  pwm2 = (base2 + pid);
  // pwm = base;
  pwm2 = constrain(pwm2, 0, 200);
  // Serial.print(" pid:");
  // Serial.print(pid);
  // Serial.print("\t");
  // Serial.print(" err:");
  // Serial.print(err2);
  // Serial.print("\t");
  // Serial.print(" diferr:");
  // Serial.print(differr2);
  // Serial.print("\t");
  return pwm2;
}

#endif