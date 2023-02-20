#define NUM_OF_READINGS				50
#define NUM_OF_BATTERY_PARAMS		2
#define NUM_OF_VALUES_MOVING_AVG	5

typedef enum
{
	FAILURE,
	SUCCESS
}status_en;

typedef struct
{
	float Readings[NUM_OF_READINGS];
	float MinValue;
	float MaxValue;
	float MovingAvg;
}tst_BatteryParamInfo;

void GetBatteryParameterReadings(float num, int Index);
void CheckSortingAndSwap(int i, float BatteryParam[]);
void GetMinAndMaxValue(float BatteryParam[], float *ptr_BatteryParam_Min, float *ptr_BatteryParam_Max);
float CalculateMovingAverage(float BatteryParam[], int LastIndex, int NumOfValues);
status_en receiveBatteryParameters(void);
