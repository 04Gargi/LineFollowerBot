#ifndef PID_H
#define PID_H

#include "Declarations.h"

float pid(int pos);

float pid(int pos) {
  err = setp - pos;
  differr = err - preverr;
  float pid = (kp * err) - (kd * differr);
  Serial.print(" err:");
  Serial.print(err);
  Serial.print("\t");
  Serial.print(" diferr:");
  Serial.print(differr);
  Serial.print("\t");
  Serial.print(" pid:");
  Serial.print(pid);
  Serial.print("\t");
  return pid;
}

#endif