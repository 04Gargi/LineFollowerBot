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
int ir = 0;

int lsa_v = 255;  // stores value of lsa

/*
*The given variables are for pwm calculations.
*/
int pwm2 = 0;
int pwm1 = 0;

/*
*The given variables are for pid.
*/
float err = 0, preverr = 0, differr = 0;

// float arr1[2][4] = {
//   { 90, 6, 0, 0.7 },
//   { 103, 5.5, 0, 0.7 }
// };

// for forward
float arr1[2][4] = {
  { 90, 6.0, 0, 0.9 },
  { 103, 5.5, 0, 0.8 }
};

// for turns
float arr[2][4] = {
  { 70, 5, 0, 1.1 },
  { 85, 4.5, 0, 0.9 }
};

float pid1 = 0, pid2 = 0;

LSA08 L;  //LSA object

int setp = 40;  //setpoint for pid

bool st = false;  // flag for movement

long timer = 0;
long timer1 = 0;
long zztimer = 0;

/* The below are the pins for Digital part of LSA */
int l = 11;
int r = 12;
int rm = 13;
int lm = 10;

int dv[4];  // array to store digital value
int jp[4];  //array to store junction digital value

bool zz = false;  // flag for zigzag motion
bool zz2 = false;
bool dc = false;

// bool jncn = false;

long t1 = 0, t2 = 0;

#endif