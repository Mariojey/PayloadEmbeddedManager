#include <Arduino.h>
#include <Wire.h>

#include "RTS.h"
#include "Environment.h"
#include "Piezo.h"
#include "Acceleration.h"

#include "SDLogger.h"

static EnvironmentSensor env;
static PiezoSensor piezo;
static AccelerationSensor adxl;

SDLogger logger;

void RTS::init(){

  Wire.begin();

  logger.begin();

  env.begin();
  piezo.begin();
  adxl.begin();

}

void RTS::update(){
  
  float temperature, humidity, pressure;
  int motionValue;
  int16_t accX, accY, accZ;

  env.readData(temperature, humidity, pressure);
  motionValue = piezo.readData();
  adxl.readData(accX, accY, accZ);

  //add logger at the end

}