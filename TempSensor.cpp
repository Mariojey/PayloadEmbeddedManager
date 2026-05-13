#include "TempSensor.h"

bool TempSensor::begin(){
  return mcp.begin(MCP_ADDRESS);
}

bool TempSensor::readTemperature(float& temp){
  mcp.setThermocoupleType(MCP9600_TYPE_K);
  temp = mcp.readThermocouple();

  if(isnan(temp)){
    return false;
  }

  if(temp < -20 || temp > 100){
    return false;
  }

  return true;
}