#ifndef Calibration_H
#define Calibration_H

int maxv(int val[], int size) {
  int max = val[0];
  for (int j = 1; j < size; j++) {
    if (val[j] > max) {
      max = val[j];
    }
  }
  return max;
}

int minv(int val[], int size) {
  int min = val[0];
  for (int j = 1; j < size; j++) {
    if (val[j] < min) {
      min = val[j];
    }
  }
  return min;
}

int threshold(int min, int max) {
  return (max + min) / 2;
}

void readSensorSamples(bool isDarkPhase) {
  int i = 0;
  timer = millis();
  while (millis() - timer < 50 && i < SAMPLE_SIZE) {
    for (int s = 0; s < NUM_SENSORS; s++) {
      sensorValues[s][i] = analogRead(sensorPins[s]);
    }
    i++;
    if (!isDarkPhase) {
      Serial.println("Reading light values...");
    }
  }
}

void calibrateSensors() {
  Serial.println("Place on DARK surface...");
  delay(1000);
  readSensorSamples(true);

  for (int s = 0; s < NUM_SENSORS; s++) {
    maxVals[s] = maxv(sensorValues[s], SAMPLE_SIZE);
  }

  Serial.println("Place on LIGHT surface...");
  delay(1000);
  readSensorSamples(false);

  for (int s = 0; s < NUM_SENSORS; s++) {
    minVals[s] = minv(sensorValues[s], SAMPLE_SIZE);
    thresholds[s] = threshold(minVals[s], maxVals[s]);
  }

  for (int s = 0; s < NUM_SENSORS; s++) {
    Serial.print("Sensor ");
    Serial.print(s);
    Serial.print(" Threshold: ");
    Serial.println(thresholds[s]);
  }
}

#endif
