#include "RealTime.h"

bool RealTime::begin(){
  
  if(rtc.lostPower()){
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    rtc.adjust(DateTime(1939, 9, 1, 4, 45, 0));
  }

  return rtc.begin();

}

bool RealTime::update(DateTime& now){
  now = rtc.now();
  return true;
}