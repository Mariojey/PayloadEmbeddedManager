#include "Acceleration.h"


bool AccelerationSensor::begin() {
  
  Wire.beginTransmission(ADXL345_register);
  Wire.write(0x32);
  Wire.write(0x0B);
  Wire.endTransmission();

  Wire.beginTransmission(ADXL345_register);
  Wire.write(0x2D);
  Wire.write(0x08);
  Wire.endTransmission();

  int8_t accelerations_raw[6];
  
  Wire.beginTransmission(ADXL345_register);
  Wire.write(0x32);

  if(!Wire.endTransmission()){

    Wire.requestFrom(ADXL345_register, 6);
    for(int i = 0; i < 6; i++){
      accelerations_raw[i] = Wire.read();
    }

    int16_t Xraw = accelerations_raw[0] | accelerations_raw[1] << 8; //move older bits by 8 and OR it with 
    int16_t Yraw = accelerations_raw[2] | accelerations_raw[3] << 8;
    int16_t Zraw = accelerations_raw[4] | accelerations_raw[5] << 8;

    return true;

  }else{
    return false;
  }

}

bool AccelerationSensor::readData(int16_t& accX, int16_t& accY, int16_t& accY)
{

  int8_t accelerations_raw[6];
  
  Wire.beginTransmission(ADXL345_register);
  Wire.write(0x32);

  if(!Wire.endTransmission()){

    Wire.requestFrom(ADXL345_register, 6);
    for(int i = 0; i < 6; i++){
      accelerations_raw[i] = Wire.read();
    }

    int16_t Xraw = accelerations_raw[0] | accelerations_raw[1] << 8; //move older bits by 8 and OR it with 
    int16_t Yraw = accelerations_raw[2] | accelerations_raw[3] << 8;
    int16_t Zraw = accelerations_raw[4] | accelerations_raw[5] << 8;

    return true;

  }else{
    return false;
  }

}