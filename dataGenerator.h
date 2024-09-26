#ifndef DATAGENERATOR_H_
#define DATAGENERATOR_H_

#include <iostream>
#include <random>
#include <iomanip> 
#include <sstream>

double generateTemperature();

int generatePulseRate();

int generateSpO2();

std::string generateSensorData();

void sendSensorData();

void initializeRandom();

#endif  // DATAGENERATOR_H_