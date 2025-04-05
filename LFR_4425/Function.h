#ifndef funcn_h
#define funcn_h

void wait() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
void moveForward() {
  calc();
  pid_calc();
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(enA, pwm1);
  analogWrite(enB, pwm2);

#ifdef pri
  Serial.print("Forward");
#endif
}
void stop() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
#endif