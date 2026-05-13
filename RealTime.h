#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include "RTClib.h"
#include <Arduino.h>
// #include <ctime>
// #include <numeric>
// #include <iostream>

class RealTime
{
  public:
    bool begin();
    bool update();

  private:
    RTC_DS3231 rtc;
};

#endif