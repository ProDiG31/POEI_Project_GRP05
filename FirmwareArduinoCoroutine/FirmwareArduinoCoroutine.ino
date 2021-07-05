//#include <IRremote.h>
//#include <IRremoteInt.h>
#include "LedManager.h" 
#include "CommunicationManager.h"
#include "SensorManager.h"


void setup (){
  //Setup Manager
  LedManager.led_setup();
  CommunicationManager.CommunicationManager_setup(); 
  SensorManager.sensor_setup(); 
}

void loop() {

  //Retrieve IR data from Rpy
  int IRdata = CommunicationManager.ReadIRData();

  //Update in Sensor Manager
  SensorManager.updateIRState(IRdata);
  SensorManager.updateSoundState();

  //SensorManager.getStates()
  
  switch (SensorManager.getStates()){
     case 2: //isPresencedDetected
      CommunicationManager.SendAlert();
      break;
    case 1: //isSoundDetected
      break;
    case 0:
    default:
      break;
  }

  LedManager.update_led(SensorManager.getStates());
    
  
  
  
  

  
  /*
  if (CommunicationManager.isAPresenceDetected()){
    LedManager.DetectPresence();
  } else {
    LedManager.runChenillard();
  }

  CommunicationManager.SendAlert();  */
}
