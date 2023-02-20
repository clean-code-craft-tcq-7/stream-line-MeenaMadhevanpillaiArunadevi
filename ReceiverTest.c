
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Receiver.h"

extern tst_BatteryParamInfo ChargeRate_st;
extern tst_BatteryParamInfo Temperature_st;

float Sample[NUM_OF_READINGS];

void testfunctions(){
	int i =0;
	float Min =0, Max =0, Avg =  0;
	for(i = 0; i< NUM_OF_READINGS; i++){
		Sample[i] = NUM_OF_READINGS - i; //generates numbers from 50 to 1
	}

	//Test the BatteryParameters readings
	GetBatteryParameterReadings(0.77, 20);//Test ChargeRate
	assert(ChargeRate_st.Readings[20] <= 0.77);
	assert(Temperature_st.Readings[20] == 0);
	GetBatteryParameterReadings(89, 67); //Test Temperature
	assert(ChargeRate_st.Readings[17] == 0);
	assert(Temperature_st.Readings[17] >= 89);

	//Test Sorting
	CheckSortingAndSwap(0, Sample);
	assert(Sample[0] == 1);

	//Test Min and Max values
	GetMinAndMaxValue(Sample, &Min, &Max);
	assert(Min == 1);
	assert(Max == 50);

	//Test MovingAverage
	Avg = CalculateMovingAverage(Sample, 5, 5);
	assert(Avg == 3);
}

int main(void) {
	testfunctions();
	receiveBatteryParameters();

	return 0;
}
