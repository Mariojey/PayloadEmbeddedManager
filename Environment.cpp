#include "Environment.h"


bool EnvironmentSensor::begin() {
  return bme.begin();
}

bool EnvironmentSensor::readData(float& temperature, float& humidity, float& pressure)
{
  BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
  BME280::PresUnit presUnit(BME280::PresUnit_Pa);

  return bme.read(pressure, temperature, humidity, tempUnit, presUnit);
}