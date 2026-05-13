#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <Arduino.h>
#include <Wire.h>
#include <BME280I2C.h>

#include "Config.h"

class EnvironmentSensor {

public:
  
  bool begin();
  bool readData(float& temperatur, float& humidity, float& pressure);

private:
  BME280I2C bme;

};

#endif