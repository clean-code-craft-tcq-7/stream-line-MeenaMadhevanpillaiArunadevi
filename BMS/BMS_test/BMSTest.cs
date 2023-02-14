using System;
using Xunit;
using static StreamingProject.BMS_SenderCommunication;
using static StreamingProject.BMS;
using Moq;

namespace StreamingProject
{
    public class BMSTest
    {
        static SOC soc = new SOC();
        static Temperature temperature = new Temperature();


        [Fact]
        public void Test_SimulateBMSSensorData()
        {
            var socCSVInput = soc.generateSensorInputStream();
            var socValues  = socCSVInput.Remove(socCSVInput.Length-1).Split(",\n");
            Assert.True(socValues.Length == noOfReadings);

            var tempCSVInput = temperature.generateSensorInputStream();
            var tempValues = tempCSVInput.Remove(tempCSVInput.Length-1).Split(",\n");
            Assert.True(tempValues.Length == noOfReadings);
        }

        [Fact]
        public void Test_SendBMSSensorData_toConsole()
        {
             BMS_SenderOutput();

            //Arrange
            var moq = new Mock<BMS.IBMS_SenderOutput>();
            moq.Setup(mk => mk.BMS_SenderOutput()).Verifiable();

        }
    }
}
