#ifndef funcn_h
#define funcn_h

void moveForward() {
  calc();
  pid1_calc();


  pwm1 = constrain(pwm1, 0, 220);
  pwm2 = constrain(pwm2, 0, 220);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
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
void moveRight() {
  calc();
  pid_calc();
  if (pwm2 < 0) {
    pwm1 = constrain((pwm1), 0, 220);
    pwm2 = constrain((pwm2), 80, 220);
    zztimer = millis();

    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
    digitalWrite(in3, 1);
    digitalWrite(in4, 0);
    analogWrite(enA, pwm1);
    analogWrite(enB, pwm2);
    return;
  }
  if (pwm1 < 0) {
    zz = true;
    zztimer = millis();
    pwm1 = constrain((pwm1), 80, 220);
    pwm2 = constrain((pwm2), 0, 220);
    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(in3, 0);
    digitalWrite(in4, 1);
    analogWrite(enA, pwm1);
    analogWrite(enB, pwm2);
    return;
  }
  pwm1 = constrain((pwm1), 0, 220);
  pwm2 = constrain((pwm2), 0, 220);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(enA, pwm1);
  analogWrite(enB, pwm2);
#ifdef pri
  Serial.print("Right");
  Serial.println("\t");
#endif
}

void moveLeft() {
  calc();
  pid_calc();
  if (pwm2 < 0) {
    zztimer = millis();
    pwm1 = constrain((pwm1), 0, 220);
    pwm2 = constrain((pwm2), 80, 220);
    digitalWrite(in1, 0);
    digitalWrite(in2, 1);
    digitalWrite(in3, 1);
    digitalWrite(in4, 0);
    analogWrite(enA, pwm1);
    analogWrite(enB, pwm2);
    return;
  }
  if (pwm1 < 0) {
    zz = true;
    zztimer = millis();
    pwm1 = constrain((pwm1), 80, 220);
    pwm2 = constrain((pwm2), 0, 220);

    digitalWrite(in1, 1);
    digitalWrite(in2, 0);
    digitalWrite(in3, 0);
    digitalWrite(in4, 1);
    analogWrite(enA, pwm1);
    analogWrite(enB, pwm2);
    return;
  }
  pwm1 = constrain((pwm1), 0, 220);
  pwm2 = constrain((pwm2), 0, 220);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  analogWrite(enA, pwm1);
  analogWrite(enB, pwm2);
#ifdef pri
  Serial.print("Left");
  Serial.println("\t");
#endif
}

void Forward() {
  calc();
  pid_calc();

  pwm1 = constrain(pwm1, 0, 220);
  pwm2 = constrain(pwm2, 0, 220);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  analogWrite(enA, pwm1);
  analogWrite(enB, pwm2);


#ifdef pri
  Serial.print("Forward");
  Serial.println("\t");
#endif
}
void moveBackward() {
  // For robot to move forward, both motors have to be same speed
  calc();
  pid_calc();
  pwm1 = constrain(pwm1, 0, 220);
  pwm2 = constrain(pwm2, 0, 220);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(enA, pwm1);
  analogWrite(enB, pwm2);
#ifdef pri
  Serial.print("Backward");
  Serial.println("\t");
#endif
}

void decelerate() {
  while (pwm1 > 70 || pwm2 > 70) {
    pwm1 -= 40;
    pwm2 -= 40;
  }
}
#endif