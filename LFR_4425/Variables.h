#ifndef Variables_h
#define Variables_h

/*
*The given pins are for L298N motor driver.
*/
int enA = 9;
int in1 = 8;
int in2 = 7;
int enB = 6;
int in3 = 5;
int in4 = 4;
int junctionPulse = 3;

int lsa_v = 0;  // stores value of lsa

/*
*The given variables are for pwm calculations.
*/
int pwm2 = 0;
int pwm1 = 0;

/*
*The given variables are for pid.
*/
float err = 0, preverr = 0, differr = 0;
// float arr[2][4] = {
//   { 105, 1.2, 0, 0.6 },
//   { 120, 1.2, 0, 0.8}
// };
// float arr[2][4] = {
//   { 78, 1.3, 0, 0.3},
//   { 128, 1.5, 0, 0.2}
// };
float arr[2][4] = {
  { 110, 6.75, 0, 2.2},//6.75
  { 136,9.7, 0, 1.5}//9
};
float pid1 = 0, pid2 = 0;

LSA08 L;  //LSA object

int setp = 40;

int cnt = 0;  // count of junctions

bool st = false;  // flag for movement

#endif