#include <stdio.h>
#include <stdlib.h>
#include "Receiver.h"

tst_BatteryParamInfo ChargeRate_st;
tst_BatteryParamInfo Temperature_st;


void GetBatteryParameterReadings(float num, int Index){
	if(Index < NUM_OF_READINGS){
		ChargeRate_st.Readings[Index] = num;
	}
	else{
		Temperature_st.Readings[Index - NUM_OF_READINGS] = num;
	}
}


void CheckSortingAndSwap(int i, float BatteryParam[]){
	int j = 0;
	float temp = 0;
	for (j = i+1; j < NUM_OF_READINGS; j++)
	{
		if (BatteryParam[i] > BatteryParam[j])
		{
			temp = BatteryParam[i];
			BatteryParam[i] = BatteryParam[j];
			BatteryParam[j] = temp;
		}
	}
}

void GetMinAndMaxValue(float BatteryParam[], float *ptr_BatteryParam_Min, float *ptr_BatteryParam_Max){
	int i = 0;
	//Sort the readings and determine the min and max value
	for (i = 0; i < NUM_OF_READINGS - 1; i++)
	{
		CheckSortingAndSwap(i, BatteryParam);
	}
	*ptr_BatteryParam_Min = BatteryParam[0];
	*ptr_BatteryParam_Max = BatteryParam[NUM_OF_READINGS - 1];
}


float CalculateMovingAverage(float BatteryParam[], int LastIndex, int NumOfValues){
	float movingAvg = 0, sum = 0;
	int index = 0;

	for(index = LastIndex - NumOfValues; index <LastIndex; index++)
	{
		sum += BatteryParam[index];
	}
	movingAvg = sum/NumOfValues;

	return movingAvg;
}


status_en receiveBatteryParameters(void){
	status_en operationStatus_en = FAILURE;
	int index = 0;
	float num = 0;
	//Get the parameter readings from console
	for(index = 0; index < NUM_OF_READINGS * NUM_OF_BATTERY_PARAMS; index++)
	{
		scanf("%f",&num);
		GetBatteryParameterReadings(num, index);
	}
	//Calculate Moving Average of the received Battery parameters
	CalculateMovingAverage(ChargeRate_st.Readings, NUM_OF_READINGS, NUM_OF_VALUES_MOVING_AVG);
	CalculateMovingAverage(Temperature_st.Readings, NUM_OF_READINGS, NUM_OF_VALUES_MOVING_AVG);
	//Determine the minimum & maximum value from the received readings stream
	GetMinAndMaxValue(ChargeRate_st.Readings, &ChargeRate_st.MinValue, &ChargeRate_st.MaxValue);
	GetMinAndMaxValue(Temperature_st.Readings, &Temperature_st.MinValue, &Temperature_st.MaxValue);
	operationStatus_en = SUCCESS;

	return operationStatus_en;
