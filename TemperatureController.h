#ifndef TEMPERATURE_CONTROLLER_H
#define TEMPERATURE_CONTROLLER_H

#include <Arduino.h>
#include "Config.h"

class TemperatureController
{
  public:
    void begin(uint8_t pwmPin);
    void update(float measuredTemp, bool sensorValid);

    void setTarget(float temp);
    float getOutput() const;

  private:
    uint8_t _pwmPin;

    float _setpoint = 35.0f;

    float Kp = 18.0f;
    float Ki = 0.35f;
    float Kd = 8.0f;

    float integral = 0.0f;

    float previousError = 0.0f;

    unsigned long previousTime = 0;

    int pwmOutput = 0;
};

#endif;