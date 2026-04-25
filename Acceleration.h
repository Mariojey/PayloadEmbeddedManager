#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <Arduino.h>
#include <Wire.h>

class AccelerationSensor {

public:
  
  bool begin();
  bool readData(int16_t& accX, int16_t& accY, int16_t& accY);


};

#endif