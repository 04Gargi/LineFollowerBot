#ifndef Declarations_H
#define Declarations_H

int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 6;
int in3 = 5;
int in4 = 4;
int t1 = 0, t2 = 0, t3 = 0;

int pwm = 0;

int pos1, pos2, pos3;
int t;
int p[5];
long timer;
int flag;
int val1[100];
int val2[100];
int val3[100];
int i = 0, r = 0, y = 0;
int min1, max1, min2, max2, min3, max3;
bool juncn = true;
bool light = true;
bool a = false;

float kp = 0.7, ki = 0, kd = 0.7;
float alpha = 0.7;
int err = 0, err2 = 0;
int differr = 0;
int preverr = 0;
int preverr2 = 0;
int sumerr = 0;
int sumerr2 = 0;
int base = 120;
int base2 = 132.5;
int setp = 35;
int pwm2 = 0;
int pwm1 = 0;
float hgj = 0, ffg = 0;

#define ns 3  // no.of sensor
#define p1 1
#define p2 2
#define p3 3

#endif