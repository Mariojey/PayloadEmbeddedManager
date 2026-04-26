#ifndef SD_LOGGER_H
#define SD_LOGGER_H

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

class SDLogger {

public:
  bool begin();
  void writeHeader(const char* text);
  void append(const char* text);

  template<typename T>

  void appendValue(T value)
  {
    if(!_initialized) return;

    File file = SD.open(_fileName, FILE_APPEND);

    if(!file) return;

    file.print(value);
    file.close();

  }

  const char* getFileName() const;

private:
  bool _initialized = false;
  char _fileName[32];

  int countFiles(const char* dirname);

};

#endif