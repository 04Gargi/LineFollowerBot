#ifndef PID_H
#define PID_H

#include "Declarations.h"

float pid1(int pos) {
  float kp1 = 1.3, kd1 =0;
  err = setp - pos;
  differr = err - preverr;
  // differr = alpha * (err2 - preverr) + (1 - alpha) * differr;
  // sumerr += err;
  float pid = (kp1 * err)- (kd1 * differr);
  Serial.print(" pid:");
  Serial.print(pid);
  Serial.print("\t");
  Serial.print(" err:");
  Serial.print(err);
  Serial.print("\t");
  Serial.print(" diferr:");
  Serial.print(differr);
  Serial.print("\t");
  return pid;
}

float pid2(int pos) {
  float kp2 = 1.3,kd2 = 0;
  
  err2 = pos - setp;
  int differr2 = err2 - preverr2;
  // int differr2 = alpha * (err2 - preverr2) + (1 - alpha) * differr2;
  // sumerr2 += err2;
  float pid = (kp2 * err2) - (kd2 * differr2);
  Serial.print(" pid:");
  Serial.print(pid);
  Serial.print("\t");
  Serial.print(" err:");
  Serial.print(err2);
  Serial.print("\t");
  Serial.print(" diferr:");
  Serial.print(differr2);
  Serial.print("\t");
  return pid;
}

#endif