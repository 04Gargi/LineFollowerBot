#ifndef funcn_h
#define funcn_h

void moveForward() {
  pwm1 = constrain(pwm1, 0, 220);
  pwm2 = constrain(pwm2, 0, 220);
  digitalWrite(l1, 1);
  digitalWrite(l2, 0);
  digitalWrite(l3, 1);
  digitalWrite(l4, 0);
  analogWrite(enA, pwm1);
  analogWrite(enB, pwm2);

#ifdef pri
  Serial.print("moveForward");
  Serial.println("\t");
#endif
}
void stop() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
#ifdef pri
  Serial.print("stop");
  Serial.println("\t");
#endif
}

#endif