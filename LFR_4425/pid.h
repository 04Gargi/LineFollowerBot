#ifndef pid_h
#define pid_h

void calc() {
  err = setp - lsa_v;
  differr = err - preverr;
  preverr = err;
#ifdef pri
  Serial.print(" err:");
  Serial.print(err);
  Serial.print("\t");
  Serial.print(" diferr:");
  Serial.print(differr);
  Serial.print("\t");
#endif
}
void pid_calc() {
  pwm1 = arr[0][0] + arr[0][1] * err - arr[0][3] * differr;
  pwm2 = arr[1][0] - arr[1][1] * err + arr[1][3] * differr;

#ifdef pri
  Serial.print(" p1:");
  Serial.print(pwm1);
  Serial.print("\t");
  Serial.print(" p2:");
  Serial.print(pwm2);
  Serial.println("\t");
#endif
}
void pid1_calc() {
  pwm1 = arr1[0][0] + arr1[0][1] * err - arr1[0][3] * differr;
  pwm2 = arr1[1][0] - arr1[1][1] * err + arr1[1][3] * differr;

#ifdef pri
  Serial.print(" p1:");
  Serial.print(pwm1);
  Serial.print("\t");
  Serial.print(" p2:");
  Serial.print(pwm2);
  Serial.println("\t");
#endif
}

#endif