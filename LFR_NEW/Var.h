#ifndef VARIABLES_H
#define VARIABLES_H

//Motor driver
const int enA = 6; 
const int enB = 5;  

const int l1 = 2;  
const int l2 = 3;  
const int l3 = 4; 
const int l4 = 7; 

// Sensor Input
const int in1 = 0;   
const int in2 = 1;   
const int in3 = A0;  
const int in4 = A1;  
const int in5 = A2;  
const int in6 = A3;  
const int in7 = 8;   
const int in8 = 9;    
const int in9 = 10; 
const int in10 = 11; 
const int in11 = 12; 
const int in12 = 13; 

//Array to sotore sensor val
int dv[12];

//timer for sampling
long timer = 0;

//Calibartion variables
const int NUM_SENSORS = 6;
const int SAMPLE_SIZE = 50;

const int sensorPins[NUM_SENSORS] = {0,1,A0, A1, A2, A3};

int sensorValues[NUM_SENSORS][SAMPLE_SIZE];
int minVals[NUM_SENSORS];
int maxVals[NUM_SENSORS];
int thresholds[NUM_SENSORS];

//analog value
int anv = 0;

//count fro sensors
int cnt =0;

// falgs
bool juncn = false;
bool allF = false;

//pwm 
int pwm1 = 120;
int pwm2 = 130;

float arr1[2][4] = {
  { 90, 0.9, 0, 0 },
  { 100, 0.9, 0, 0 }
};
float arr[2][4] = {
  { 90, 0.9, 0, 0 },
  { 100, 0.9, 0, 0 }
};

float err = 0, preverr = 0, differr = 0;
int setp = 50;

#endif
