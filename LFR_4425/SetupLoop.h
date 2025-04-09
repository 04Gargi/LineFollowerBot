#ifndef sl_h
#define sl_h

void stop();
void moveForward();
void Forward();
void moveLeft();
void moveRight();

void s_req() {
  L.AttachAnalogPin(A1);
  // L.debugger.Initialize("LSA", &Serial);

  Serial.begin(115200);
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

  pinMode(junctionPulse, INPUT);

  delay(2000);
}

void l_req() {
  lsa_v = L.ReadLSA();
  if (lsa_v == 255) {
    stop();
   } 
  else {
  //   // if (digitalRead(junctionPulse)) {
  //   //   if (++cnt > 4) {
  //   //     stop();
  //   //   }
  //   //   else moveForward();
  //   // } else {
  //     moveForward();
  //   // }
  // }
  // else{
    if(lsa_v>=55) moveRight();
    else if(lsa_v<=25) moveLeft();
    else Forward();
  }





#ifdef pri
  Serial.print("lsa: ");
  Serial.print(lsa_v);
  Serial.print("\t");
  Serial.print("cnt: ");
  Serial.print(cnt);
#endif
}
#endif