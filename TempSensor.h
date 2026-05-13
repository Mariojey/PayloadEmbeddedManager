#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include <Adafruit_MCP9600.h>
#include "Config.h"

class TempSensor
{
  public:
    bool begin();
    bool readTemperature(float& temp);

  private:
    Adafruit_MCP9600 mcp;
};

#endif