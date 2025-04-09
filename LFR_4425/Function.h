#ifndef funcn_h
#define funcn_h

void wait() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
void moveForward() {
  calc();
  pid_calc();
  pwm1 = constrain(pwm1, 0, 220);
  pwm2 = constrain(pwm2, 0, 220);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(enA, pwm1);
  analogWrite(enB, pwm2);

#ifdef pri
  Serial.print("Forward");
  Serial.print("\t");
#endif
}
void stop() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
void moveRight() {
  // For robot to move left, right motor has to be faster than left motor
  calc();
  pid_calc();
  pwm1 = constrain(abs(pwm1), 0, 220);
  pwm2 = constrain(abs(pwm2), 0, 220);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(enA, pwm1);
  analogWrite(enB, pwm2);
#ifdef pri
  Serial.print("Rightt");
  Serial.print("\t");
#endif
}

void moveLeft() {
  // For robot to move right, left motor has to be faster than right motor
  calc();
  pid_calc();
  pwm1 = constrain(abs(pwm1), 0, 220);
  pwm2 = constrain(abs(pwm2), 0, 220);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  analogWrite(enA, pwm1);
  analogWrite(enB, pwm2);
#ifdef pri
  Serial.print("Left");
  Serial.print("\t");
#endif
}

void Forward() {
  calc();
  pid_calc();
  pwm1 = constrain(pwm1, 0, 220);
  pwm2 = constrain(pwm2, 0, 220);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(enA, 70);
  analogWrite(enB, 70);

#ifdef pri
  Serial.print("Forward");
  Serial.print("\t");
#endif
}
#endif