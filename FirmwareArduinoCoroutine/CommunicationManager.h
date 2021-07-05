class CommunicationManager{

  private :
  public : 
    //enum {DETECTED, NOTDETECTED} sensorStates;
    /*sensorStates CurrentIRStates;
    sensorStates CurrentSoundStates;
    sensorStates PresenceStates;*/

     
    void CommunicationManager_setup() {
        Serial.begin(9600);

         while (!Serial) {
           digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
        }  
        
        digitalWrite(LED_BUILTIN, LOW);
        delay(250);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(250);
        digitalWrite(LED_BUILTIN, LOW);
        delay(250);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(250);
        digitalWrite(LED_BUILTIN, LOW);
    }


    int ReadIRData() {
      //Read IR Sensor data from raspy 
       if (Serial.available()) {
          // 0 - Objet non detecté 
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
