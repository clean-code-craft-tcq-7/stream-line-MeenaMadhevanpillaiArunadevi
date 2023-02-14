using System;
using System.Collections.Generic;
using System.Text;
using static StreamingProject.BMS_SensorParams;
using static StreamingProject.BMS_ParamsThresoldLimit;

namespace StreamingProject
{

    class SOC : BMS
    {
        public SOC()
        {
            this.inputBMSSensor = BMS_KeyParams.SOC;
            this.minLimit = SocMin;
            this.maxLimit = SocMax;
        }
    }
}
