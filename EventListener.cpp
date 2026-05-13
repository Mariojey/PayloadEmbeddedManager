#include "EventListener.h"

bool EventListener::begin(){
  
  //ROCKET Communication
  pinMode(GPIO10_0, INPUT);
  pinMode(GPIO9_1, INPUT);
  pinMode(GPIO8_2, INPUT);
  pinMode(GPIO7_3, INPUT);

  //Thor's validation
  pinMode(NORTH_PAYLOAD_STATS_OUT, OUTPUT);

}

bool EventListener::ready(){
    digitalWrite(NORTH_PAYLOAD_STATS_OUT, HIGH);
    return true;
}

void RealTime::update(bool& rocket10_0, bool& rocket9_1, bool& rocket8_2, bool& rocket7_3){
  
      (digitalRead(GPIO10_0) == HIGH) ?
      rocket10_0 = true; 
      : rocket10_0 = false;

            (digitalRead(GPIO9_1) == HIGH) ?
      rocket9_1 = true; 
      : rocket9_1 = false;

            (digitalRead(GPIO8_2) == HIGH) ?
      rocket18_2 = true; 
      : rocket8_2 = false;

            (digitalRead(GPIO7_3) == HIGH) ?
      rocket7_3 = true; 
      : rocket7_3 = false;

}