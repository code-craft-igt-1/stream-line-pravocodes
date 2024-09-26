#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include "./dataGenerator.h" 

TEST(SensorDataTests, GenerateTemperature) {
    double temperature = generateTemperature();
    EXPECT_GE(temperature, 95.0);
    EXPECT_LE(temperature, 105.0);
}

TEST(SensorDataTests, GeneratePulseRate) {
    int pulseRate = generatePulseRate();
    EXPECT_GE(pulseRate, 60);
    EXPECT_LE(pulseRate, 100);
}

TEST(SensorDataTests, GenerateSpO2) {
    int spo2 = generateSpO2();
    EXPECT_GE(spo2, 90);
    EXPECT_LE(spo2, 100);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
