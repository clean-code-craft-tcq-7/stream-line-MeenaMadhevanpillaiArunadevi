#include<stdio.h>
#include<stdlib.h>
#include <math.h>

#define readings_count 50

void readDataFromConsole(float* Temperature, float* SOC);
float fetchMaxValue(float *sensorparameter);
float fetchMinValue(float *sensorparameter);
float calculateMovingAverage(float *sensorparameter);
int printReceivedDataToConsole(float *sensorparameter, float maxvalue, float minvalue, float SMA);
void receiveAndProcessSensorData(float* Temperature, float* SOC);
