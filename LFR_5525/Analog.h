#ifndef Analog_H
#define Analog_H

void analog(){
  lsa_v = L.ReadLSA();

  timer = millis();
  if (lsa_v == 255) {
    // stop();
    moveBackward();
  } 
  else if (digitalRead(junctionPulse)) {
    if (lsa_v >= 45)
      moveRight();
    else if (lsa_v >= 30 && lsa_v <45) {
      Forward();
    } else if (lsa_v < 30) {
      moveLeft();
    }
    // else moveBackward();
  }
   else {
    moveForward();
  }
  timer = millis();
#ifdef pri
  Serial.print("lsa: ");
  Serial.print(lsa_v);
  Serial.print("\t");
  Serial.print("cnt: ");
  Serial.print(cnt);
  Serial.print("\t");
  Serial.print("thresh: ");
  Serial.print(thresh);
  Serial.print("\t");
  Serial.print("jncn: ");
  Serial.print(digitalRead(junctionPulse));
  Serial.print("\t");
#endif
}
#endif