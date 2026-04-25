#ifndef PIEZO_H
#define PIEZO_H

#include <Arduino.h>
#include "Config.h"

class PiezoSensor {

public:
  
  bool begin();
  int readData();


};

#endif