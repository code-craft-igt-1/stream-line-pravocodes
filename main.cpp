#include <iostream>
#include <random>
#include <iomanip> 
#include <sstream> 

std::string generateSensorData() {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_real_distribution<double> tempDist(95.0, 105.0); 
    std::uniform_int_distribution<int> pulseDist(60, 100); 
    std::uniform_int_distribution<int> spo2Dist(90, 100); 

    double temperature = tempDist(generator);
    int pulseRate = pulseDist(generator);
    int spo2 = spo2Dist(generator);

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
