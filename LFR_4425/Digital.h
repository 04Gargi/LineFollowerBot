#ifndef dig_H
#define dig_H

void digital(){
  if(digitalRead(2) && digitalRead(5))
  moveForward();
  
  // Checking for sensor number 1 and 2, if line detected, move left
  else if(digitalRead(1) || digitalRead(2))
  moveLeft();

  // Checking for sensor number 5 and 6, if line detected, move right
  else if(digitalRead(5) || digitalRead(6))
  moveRight();

  // Checking for sensors number 3 and 4, 
  // if line is detected by either of these sensor, move forward
  else if(digitalRead(3) || digitalRead(4))
  moveForward();

  // If no line is detected, stay at the position
  else
  wait();

}
#endif