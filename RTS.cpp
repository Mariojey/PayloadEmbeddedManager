#include <Arduino.h>
#include <Wire.h>

#include "RTS.h"
#include "Environment.h"
#include "Piezo.h"
#include "Acceleration.h"
#include "RealTime.h"

#include "SDLogger.h"

#include "TemperatureController.h"
#include "TempSensor.h"

#include "Types.h"

#include "EventListener.h"

static EnvironmentSensor env;
static PiezoSensor piezo;
static AccelerationSensor adxl;
static RealTime realTimeClock;

static SDLogger logger;

static TemperatureController heater;
static TempSensor mcp;

void RTS::init(){

  Wire.begin();

  logger.begin();

  env.begin();
  piezo.begin();
  adxl.begin();

  mcp.begin();
  heater.begin(PWM_PIN);
  heater.setTarget(35.0f);

  realTimeClock.begin();

  EventListener.begin();
  EventListener.ready();

}

void RTS::update(){

  CollectedData dataToSave;
  
  float temperature, humidity, pressure;
  int motionValue;
  int16_t accX, accY, accZ;

  env.readData(dataToSave.c_temperature, dataToSave.c_humidity, dataToSave.c_pressure);
  dataToSave.c_motion = piezo.readData();
  adxl.readData(dataToSave.c_accX, dataToSave.c_accY, dataToSave.c_accZ);

  dataToSave.c_isMCPValid = mcp.readTemperature(dataToSave.c_mcpTemp);

  heater.update(dataToSave.c_mcpTemp, dataToSave.c_isMCPValid);

  EventListener.update(dataToSave.c_r0, dataToSave.c_r1, dataToSave.c_r2, dataToSave.c_r3);

  DateTime now;
  realTimeClock.update(now);
  char timestamp[32];
  sprintf(timestamp, "%d:%d:%d ", now.hour(), now.minute(), now.second());
  logger.append(timestamp);

  char buffer[256];
  sprintf(buffer, 
  
    "0 %.2f %.2f %.2f %f %f %f %d %f %B %B %B %B %B %B ACK\n",
    (dataToSave.c_accX * 0.0031), 
    (dataToSave.c_accY * 0.0031),
    (dataToSave.c_accZ * 0.0031),
    dataToSave.c_temperature,
    dataToSave.c_humidity,
    dataToSave.c_pressure,
    dataToSave.c_motion,
    dataToSave.c_mcpTemp,
    dataToSave.c_isMCPValid,
    dataToSave.c_payloadStatus,
    dataToSave.c_r0,
    dataToSave.c_r1,
    dataToSave.c_r2,
    dataToSave.c_r3
  );
  logger.append(buffer);

}