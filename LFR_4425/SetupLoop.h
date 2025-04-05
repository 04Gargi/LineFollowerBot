#ifndef sl_h
#define sl_h
void stop();
void moveForward();
void s_req() {
  L.AttachAnalogPin(A1);
  // L.debugger.Initialize("LSA", &Serial);

  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay(3000);
}

void l_req() {
  lsa_v = L.ReadLSA();

  if (lsa_v == 255) stop();
  else moveForward();
}
#endif