#ifndef dec_h
#define dec_h

void decision() {
  digital();
  // jn_digital();

  if ((jp[0] == 1 && jp[1] == 1 && jp[3] == 1) && !zz && (millis() - zztimer > 300)) {

    while (dv[1] != 1 || dv[2] != 1) {
      // moveRight();
      digital();
    }
    return;
  }
  
  if (jp[0] == 1 && jp[3] == 0 || err < -15) {
    long t1 = millis();
    while (dv[1] != 1 && millis() - t1 < 200) {
      digital();
      moveLeft();
    }
    return;
  }

  if ((jp[3] == 1) && jp[0] == 0) {
    long t1 = millis();
    while (dv[2] != 1 && millis() - t1 < 200) {
      digital();
      moveRight();

      // if()
    }
    return;
  }
  dv[0] = 0;
  dv[1] = 0;
  dv[2] = 0;
  dv[3] = 0;

  jp[0] = 0;
  jp[1] = 0;
  jp[2] = 0;
  jp[3] = 0;
  moveForward();
  // zz = false;
  return;
}

void nojndecision(){
  if(dv[0] == 1 && dv[3] == 1 || dv[0] == 1 && dv[1] == 1 || dv[2] == 1 && dv[3] == 1){
    moveForward();
  }
}
#endif
