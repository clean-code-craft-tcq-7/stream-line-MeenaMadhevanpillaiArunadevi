using System;
using System.Collections.Generic;
using System.Text;
using static StreamingProject.BMS_SensorParams;
using static StreamingProject.BMS_ParamsThresoldLimit;

namespace StreamingProject
{
    class Temperature : BMS
    {
        public Temperature()
        {
            this.inputBMSSensor = BMS_KeyParams.Temperature;
            this.minLimit = TemperatureMin;
            this.maxLimit = TemperatureMax;
        }
    }
}
