using System;
using System.Collections.Generic;
using System.Text;
using static StreamingProject.SOC;
using static StreamingProject.Temperature;

namespace StreamingProject
{
    class BMS_SenderCommunication
    {
        static SOC soc = new SOC();
        static Temperature temperature = new Temperature();
        
        public static void BMS_SenderOutput()
        {            
            Console.WriteLine(format_SenderOutput());
        }

        public static string format_SenderOutput()
        {
            string soc_communication = string.Concat(soc.inputBMSSensor.ToString(), "\n", soc.generateSensorInputStream());
            string temp_communication = string.Concat(temperature.inputBMSSensor.ToString(), "\n", temperature.generateSensorInputStream());
            string sensors_output = string.Concat(soc_communication,"\n",temp_communication);
            return sensors_output;
        }

    }
}
