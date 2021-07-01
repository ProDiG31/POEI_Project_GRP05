#include <Arduino.h>
#include <AceRoutine.h>
using namespace ace_routine;


class CommunicationManager: public Coroutine{

  private :
  public : 
    //enum {DETECTED, NOTDETECTED} sensorStates;
    /*sensorStates CurrentIRStates;
    sensorStates CurrentSoundStates;
    sensorStates PresenceStates;*/

     
    void CommunicationManager_setup() {
        Serial.begin(9600);
    }


    int ReadIRData() {
      //Read IR Sensor data from raspy 
       if (Serial.available()) {
          // 0 - Rien detecté 
          // 1 - Objet detecté  
          int irdata = int(Serial.read());
          Serial.flush();
          
          return irdata;
       }
    }

    void SendAlert (){
      Serial.print("1");
    } 
    
};

CommunicationManager CommunicationManager;
