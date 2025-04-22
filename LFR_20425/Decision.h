#ifndef dec_h
#define dec_h

void decision() {
  digital();
  // jn_digital();

  if ((jp[0] == 1 && jp[1] == 1 && jp[3] == 1) &&
      !zz && (millis() - zztimer > 300)) {

    while (dv[1] != 1 || dv[2] != 1) {
      moveRight();
      digital();
    }
    return;
  }
  if (err > -11) {
    zz = true;
    moveLeft(); 
  } else if (err < 9) {
    zz = true;
    moveRight();  
  }
  if ((jp[0] == 1) && jp[3] == 0) {
    long t1 = millis();
    while (dv[1] != 1 && millis() - t1 < 300) {
      digital();
      moveLeft();
    }
    return;
  }

  if ((jp[3] == 1) && jp[0] == 0) {
    long t1 = millis();
    while (dv[2] != 1 && millis() - t1 < 300) {
      digital();
      moveRight();
      // if()
    }
    jp[0] = 0;
    jp[1] = 0;
    jp[2] = 0;
    jp[3] = 0;
    return;
  }

  // moveForward();
  // zz = false;
  return;
}

#endif
