#include "Piezo.h"


bool PiezoSensor::begin() {

  int vib = analogRead(piezoSensorPin);
  
  if (vib < 0) return false;

  return true;

}

int PiezoSensor::readData()
{
  
  return analogRead(piezoSensorPin);

}