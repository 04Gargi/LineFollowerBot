#ifndef Calibration_H
#define Calibration_H

#include "Variables.h"


int maxv(int val[]) {
  int max = val[0];
  for (int j = 1; j <30 ; j++) {
    if (max > val[j]) {
      max = val[j];
    }
  }
  return max;
}

int threshold(int min, int max) {
  return (max + min) / 2;
}


int minv(int val[]) {
  int min = val[0];
  for (int j = 1; j < 30; j++) {
    if (min < val[j]) {
      min = val[j];
    }
  }
  return min;
}

void calibration() {
  // Serial.println("Dark");
  int min = 1023;
  timer = millis();
  int i = 0;
  while (millis() - timer < 1000) {
    val[i++] = analogRead(A2);
    Serial.print(val[i]);
  }
  timer = millis();
  max = maxv(val);
  delay(1000);
  // Serial.print("Light");
  int max = 0;
  // timer = millis();
  while (millis() - timer < 1000) {
    val[i++] = analogRead(A2);
    // Serial.print("in while ligjt");
  }

  timer = millis();
  min = minv(val);
  t = threshold(min, max);
}

#endif