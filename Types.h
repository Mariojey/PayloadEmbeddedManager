#ifndef TYPES_H
#define TYPES_H

struct CollectedData {
  float temperature;
  float humidity;
  float pressure;
  int motion;
  int16_t accX;
  int16_t accY;
  int16_t accZ;
}

#endif