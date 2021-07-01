class CommunicationManager {

  private :
  public : 
    enum {DETECTED, NOTDETECTED} sensorStates;
    /*sensorStates CurrentIRStates;
    sensorStates CurrentSoundStates;
    sensorStates PresenceStates;*/
    byte CurrentIRStates = NOTDETECTED;
    byte CurrentSoundStates = NOTDETECTED;
    byte PresenceStates = NOTDETECTED;
     
    void CommunicationManager_setup() {
        Serial.begin(9600);
    }

    void UpdateStates() {
        if(CurrentIRStates == DETECTED && CurrentSoundStates == DETECTED) {
            PresenceStates = DETECTED;
        } else {
            PresenceStates = NOTDETECTED;
        }
    }


    void ReadData() {
      //Read IR Sensor data from raspy 
       if (Serial.available()) {
          
          // 0 - Rien detecté 
          // 1 - Objet detecté  
          byte PresenceSensorState = Serial.read();
          if (int(PresenceSensorState) == 1) {
              CurrentIRStates = DETECTED;
          } else {
             CurrentIRStates = NOTDETECTED;
          }
        }
    }

    bool isAPresenceDetected(){
      return PresenceStates == DETECTED;
    }

    void SendAlert (){
      if (Serial.available()) {
        if(isAPresenceDetected()){
          Serial.print("1");
        } else {
          Serial.print("0");
        }
      } 
    } 
};

CommunicationManager CommunicationManager;
