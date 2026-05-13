#include "TemperatureController.h"

void TemperatureController::begin(uint8_t pwmPin)
{
  _pwmPin = pwmPin;

  pinMode(_pwmPin, OUTPUT);

  analogWrite(_pwmPin, 0);

  previousTime = millis();
}

void TemperatureController::setTarget(float temp){

  _setpoint = temp;
}

float TemperatureController::getOutput() const
{
  return pwmOutput;
}

void TemperatureController::update(float measuredTemp, bool sensorValid){

  if(!sensorValid){
    analogWrite(_pwmPin, 0);
    integral = 0;

    previousError = 0;
    return;
  }

  if(measuredTemp > MAX_SAFE_TEMP)
  {

      analogWrite(_pwmPin, 0);
      integral = 0;

      return;

  }


  unsigned long now = millis();

  float dt = (now - previousTime) / 1000.0f;

  if(dt <= 0.0f){
    return;
  }

  previousTime = now;

  float error = _setpoint - measuredTemp;

  integral += error * dt;

  integral = constrain(integral, -50.0f, 50.00f);

  float derivative = (error - previousError) / dt;

  float output = Kp * error + Ki * integral + Kd * derivative;

  previousError = error;

  pwmOutput = constrain((int)output, 0, MAX_PWM);


  analogWrite(_pwmPin, pwmOutput);

}