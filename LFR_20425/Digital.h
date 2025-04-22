#ifndef dig_H
#define dig_H

void digital() {

  dv[0] = digitalRead(lm);
  dv[1] = digitalRead(l);
  dv[2] = digitalRead(r);
  dv[3] = digitalRead(rm);

#ifdef pri
  Serial.print("lm:");
  Serial.print(dv[0]);
  Serial.print("\t");
  Serial.print("l:");
  Serial.print(dv[1]);
  Serial.print("\t");
  Serial.print("r:");
  Serial.print(dv[2]);
  Serial.print("\t");
  Serial.print("rm:");
  Serial.print(dv[3]);
  Serial.print("\t");


  Serial.print("jncn: ");
  Serial.print(digitalRead(junctionPulse));
  Serial.print("\t");
#endif
}

void jn_digital() {
  if (digitalRead(junctionPulse)) {
    jp[0] = digitalRead(lm);
    jp[1] = digitalRead(l);
    jp[2] = digitalRead(r);
    jp[3] = digitalRead(rm);
  }
}

#endif