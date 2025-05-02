#ifndef Variables_h
#define Variables_h

/*
* The given pins are for L298N motor driver.
*/
int enA = 9;
int in1 = 8;
int in2 = 7;
int enB = 6;
int in3 = 5;
int in4 = 4;
int junctionPulse = 3;
int ir = 0;

int lsa_v = 255;  // stores value of LSA

/*
* The given variables are for PWM calculations.
*/
int pwm1 = 0;
int pwm2 = 0;

/*
* The given variables are for PID.
*/
float err = 0, preverr = 0, differr = 0;

float pid1 = 0, pid2 = 0;

/*
* PID values [PWM, Kp, Ki, Kd]
* arr1: for forward motion
* arr : for turns
*/
float arr1[2][4] = {
  { 90, 6, 0, 0.7 },
  { 103, 5.5, 0, 0.7 }
};

float arr[2][4] = {
  { 70, 4, 0, 1 },
  { 85, 3.6, 0, 0.8 }
};

int setp = 40;  // Setpoint for PID

LSA08 L;  // LSA08 object for line sensing

bool st = false;  // Flag for movement

long timer = 0;
long timer1 = 0;
long zztimer = 0;

/*
* Digital sensor pins for LSA
*/
int l = 11;
int r = 12;
int rm = 13;
int lm = 10;

int dv[4];  // Digital value storage
int jp[4];  // Junction pattern storage

bool zz = false;   // Flag for zig-zag motion
bool zz2 = false;
bool dc = false;   // Decision condition flag

long t1 = 0, t2 = 0;  // Timers for custom logic

// int cnt1 = 0, cnt2 = 0;
