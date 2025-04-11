#ifndef funcn_h
#define funcn_h

void wait() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
void moveForward() {
  calc();
  pid1_calc();
  pwm1 = constrain(pwm1, 0, 220);
  pwm2 = constrain(pwm2, 0, 220);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(enA, pwm1);
  analogWrite(enB, pwm2);

#ifdef pri
  Serial.print("moveForward");
  Serial.print("\t");
#endif
}
void stop() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
void moveRight() {
  calc();
  pid1_calc();
  pwm1 = constrain((pwm1), 0, 220);
  pwm2 = constrain((pwm2), 0, 220);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  analogWrite(enA, 80);
  analogWrite(enB, 80);
#ifdef pri
  Serial.print("Rightt");
  Serial.print("\t");
#endif
}

void moveLeft() {
  calc();
  pid1_calc();
  pwm1 = constrain((pwm1), 0, 220);
  pwm2 = constrain((pwm2), 0, 220);
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  analogWrite(enA, 80);
  analogWrite(enB, 80);
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
  analogWrite(enA, 80);
  analogWrite(enB, 80);

#ifdef pri
  Serial.print("Forward");
  Serial.print("\t");
#endif
}
void moveBackward() {
  // For robot to move forward, both motors have to be same speed
  calc();
  pid1_calc();
  pwm1 = constrain(pwm1, 0, 220);
  pwm2 = constrain(pwm2, 0, 220);
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
  analogWrite(enA, pwm1);
  analogWrite(enB, pwm2);
  // Serial.println("Backward");
}
// void slowdown() {
    
//   // if(pwm1<)
//   while (millis() - timer < 200) {
//     pwm1 += (-2);
//     pwm2 += (-2);
//     // delay(20);
//   }
// }
#endif