class SensorManager{
  
  private : 
    // Sound sensor in
    int RECV_SOUND_PIN = 5; 
    
  public: 
    bool CurrentIRStates = false;
    bool CurrentSoundStates = false;
     
    void sensor_setup() {
     //Setup Capteur Son
      pinMode(RECV_SOUND_PIN, INPUT);
    }


    int getStates(){
      if(CurrentIRStates  && CurrentSoundStates) {
        return 2;
      } else if (CurrentSoundStates){
        return 1;
      } else {
        return 0;
      }
    }
 

    void updateIRState(int PresenceSensorState) {
      if (PresenceSensorState == 1) {
         CurrentIRStates = true;
      } else {
         CurrentIRStates = false;
      }
    }

    void updateSoundState(){
      int val = digitalRead(RECV_SOUND_PIN);
      //Serial.print("Val Lu : \t");
      //Serial.println(val);
     
      // when the sensor detects a signal above the threshold value, LED flashes
      CurrentSoundStates = (val!=LOW);
      
    }

    
};

SensorManager SensorManager;
