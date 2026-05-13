#ifndef TYPES_H
#define TYPES_H

struct CollectedData {
  float c_temperature;
  float c_humidity;
  float c_pressure;
  int c_motion;
  int16_t c_accX;
  int16_t c_accY;
  int16_t c_accZ;
  float c_mcpTemp;
  bool c_isMCPValid;
  bool c_payloadStatus;
  bool c_r0;
  bool c_r1;
  bool c_r2;
  bool c_r3;
}

#endif