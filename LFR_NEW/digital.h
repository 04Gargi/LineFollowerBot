#ifndef dig_H
#define dig_H

void digital() {
  // Serial.print("in digital");
  for(int i = 0; i< NUM_SENSORS;i++){
    if (analogRead(sensorPins[i]) < thresholds[i]) dv[i] = 0;
    else dv[i] = 1;
  }
  // if (analogRead(in1) < thresholds[0]) dv[0] = 0;
  // if (analogRead(in2) < t) dv[1] = 0;
  // if (analogRead(in3) < t) dv[2] = 0;
  // if (analogRead(in4) < t) dv[3] = 0;
  // if (analogRead(in5) < t) dv[4] = 0;
  // if (analogRead(in6) < t) dv[5] = 0;
  // dv[0] = digitalRead(in1);
  // dv[1] = digitalRead(in2);
  // dv[2] = digitalRead(in3);
  // dv[3] = digitalRead(in4);
  // dv[4] = digitalRead(in5);
  // dv[5] = digitalRead(in6);
  dv[6] = digitalRead(in7);
  dv[7] = digitalRead(in8);
  dv[8] = digitalRead(in9);
  dv[9] = digitalRead(in10);
  dv[10] = digitalRead(in11);
  dv[11] = digitalRead(in12);

for (int i = 0; i < 12; i++) {
    if (dv[i] == 0) {
      anv = +i * 10;
    }
  }
  #ifdef pri
  Serial.print("dv: ");
  for (int i = 0; i < 12; i++) {
    Serial.print(dv[i]);
    Serial.print(" ");
  }
  // Serial.println(" ");
  Serial.print(" analog val");
    for (int i = 0; i < 6; i++) {
    Serial.print(analogRead(sensorPins[i]));
    Serial.print(" ");
  }
  Serial.print(" ");
  Serial.print(anv);
  Serial.print(" ");

  #endif
}

void iterate() {
  cnt = 0;
  for (int i = 0; i < 12; i++) {
    if (dv[i] == 1) cnt++;
  }
  if (cnt == 12) allF = true;
  if (cnt <= 8) juncn = true;

#ifdef pri
  Serial.print(allF);
  Serial.print("\t");
  Serial.print(juncn);
    Serial.print("\t");
#endif
}
#endif