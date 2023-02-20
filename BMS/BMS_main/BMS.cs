using System;
using System.Collections.Generic;
using System.Text;
using static StreamingProject.BMS_SensorParams;
namespace StreamingProject
{
    partial class BMS
    {
        public BMS_KeyParams inputBMSSensor;
        public float minLimit;
        public float maxLimit;
        public const int noOfReadings = 50;
        public void setInputSensor(BMS_KeyParams sensorName)
        {
            this.inputBMSSensor = sensorName;
        }

        public void setMaxValue(float maxLimit)
        {
            this.maxLimit = maxLimit;
        }

        public void setMinValue(float minLimit)
        {
            this.minLimit = minLimit;
        }

        public float generateSensorParamValue()
        {
            Random random = new Random();
            float paramValue = (float)(random.NextDouble() * (maxLimit - minLimit) + minLimit);
            return paramValue;
        }

        public string generateSensorInputStream()
        {
            String SensorInputStream = string.Empty;
            for (int i=0;i<noOfReadings;i++)
            {
                SensorInputStream = string.Concat(SensorInputStream, generateSensorParamValue(), ",\n");
            }
            return SensorInputStream;
        }

        //public BMSKeyParams(string Sensor)
        //{
        //    this.inputBMSSensor = Sensor;
        //    getMinLimit(Sensor);
        //    getMaxLimit(Sensor);
        //}

        //public getMinLimit(string Sensor)
        //{
        //    this.maxLimit = ;
        //}
    }
}
