#include <iostream>
#include <random>
#include <iomanip> 
#include <sstream> 

void initializeRandom() {
    std::srand(static_cast<unsigned int>(std::time(0)));
}

double generateTemperature() {
    return 95.0 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (105.0 - 95.0)));
}

int generatePulseRate() {
    return rand() % (100 - 60 + 1) + 60;
}

int generateSpO2() {
    return rand() % (100 - 90 + 1) + 90; 
}

std::string generateSensorData() {
    initializeRandom();
    double temperature = generateTemperature();
    int pulseRate = generatePulseRate() ;
    int spo2 = generateSpO2();

    std::ostringstream dataStream;
    dataStream << std::fixed << std::setprecision(1) << temperature << "," 
               << pulseRate << "," << spo2;
    return dataStream.str();
}

void sendSensorData() {
    const int readingsCount = 50; 
    for (int i = 0; i < readingsCount; ++i) {
        std::string sensorData = generateSensorData();
        std::cout << sensorData << std::endl; 
    }
}

int main() {
    sendSensorData(); 
    return 0;
}
