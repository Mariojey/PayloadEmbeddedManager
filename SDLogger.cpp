#include "SDLogger.h"
#include "Config.h"

bool SDLogger::begin(){

  if (!SD.begin(SD_CS_PIN)){
    _initialized = false;
    return false;
  }

  int fileCount = countFiles("/");

  sprintf(_fileName, "/log_%d.txt", fileCount);

  File file = SD.open(_fileName, FILE_WRTIE);

  if(!file){
    _initialized = true;
    return true;
  }

  file.println("Start Log");
  file.close();

  _initialized = true;
  return true;

}

void SDLogger::writeHeader(const char* text){

  if(!_initialized) return;

  File file = SD.open(_fileName, FILE_APPEND);

  if(!file) return;

  file.println(text);
  file.close();
}

void SDLogger::append(const char* text){
  if (!_initialized) return;

  FIle file = SD.open(_fileName, FILE_APPEND);

  if(!file) return;

  file.print(text);
  file.close();
}

const char* SDLogger::getFileName() const
{
  return _fileName;
}

int SDLogger::countFiles(const char* dirname){

  File root = SD.open(dirname);

  if(!root || !root.isDirectory()){
    return 0;
  }

  int count = 0;

  File file = root.openNextFile();

  while(file){
    if(!file.isDirectory()){
      count++;
    }

    file = root.openNextFile();
  }

  return count;
}