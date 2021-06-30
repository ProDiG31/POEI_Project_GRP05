//#include <IRremote.h>
//#include <IRremoteInt.h>
#include "LedManager.h" 


// Sound sensor in
int RECV_SOUND_PIN = 5; 

void setup (){

 
  //Setup Led Manager
  LedManager.led_setup();
  
  //Setup Capteur Son
  pinMode(RECV_SOUND_PIN, INPUT);
}

void loop() {

  int val = digitalRead(RECV_SOUND_PIN);
  Serial.print("Val Lu : \t");
  Serial.println(val);
 
  // when the sensor detects a signal above the threshold value, LED flashes
  if (val!=LOW) {
    LedManager.DetectSound();
  } else {
    LedManager.runChenillard();
  }
}