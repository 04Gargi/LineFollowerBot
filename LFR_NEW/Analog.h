#ifndef Analog_H
#define Analog_H

void analog() {
  for (int i = 0; i < 12; i++) {
    if (dv[i] == 0) {
      anv = +i * 10;
    }
  }
timer = millis();
#ifdef pri
Serial.print(anv);
Serial.print("\t");
#endif
}
#endif