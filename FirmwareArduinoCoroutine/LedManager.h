#include <Arduino.h>
#include <AceRoutine.h>
using namespace ace_routine;

class LedManager : public Coroutine{
  
  private : 
  
    //Led Pins
    int LED01_PIN = 12; //Red
    int LED02_PIN = 11; //Red
    int LED03_PIN = 10; //Yellow
    int LED04_PIN = 9;  //Yellow
    int LED05_PIN = 8;  //Green
    int LED06_PIN = 7;  //Green
    
    int Default_Blink_Delay = 100; 
    unsigned long previousMillis = 0

    
    // Variables will change:
    int ledState = LOW;             // ledState used to set the LED

    int CurrentLed;
    bool isAscending;

  /*
    void blinkLed(int Led_Pin){
      digitalWrite(Led_Pin, HIGH);
      delay(Default_Blink_Delay);
      digitalWrite(Led_Pin, LOW);
    }
  */
  
    void blinkLed(int Led_Pin){
       unsigned long currentMillis = millis();
    
      if (currentMillis - previousMillis >= Default_Blink_Delay) {
        // save the last time you blinked the LED
        previousMillis = currentMillis;
    
        // if the LED is off turn it on and vice-versa:
        if (ledState == LOW) {
          ledState = HIGH;
        } else {
          ledState = LOW;
        }

        digitalWrite(Led_Pin, ledState);
      }
    }

    
  public: 
     
    void led_setup() {
     
      //Setup Led 
      pinMode(LED01_PIN, OUTPUT);
      pinMode(LED02_PIN, OUTPUT);
      pinMode(LED03_PIN, OUTPUT);
      pinMode(LED04_PIN, OUTPUT);
      pinMode(LED05_PIN, OUTPUT);
      pinMode(LED06_PIN, OUTPUT);
      
      CurrentLed = LED01_PIN;
      isAscending = false;
    }
        
    void runChenillard(){
    
      blinkLed(CurrentLed);
    
      //7 - 12
      if (isAscending){
        CurrentLed++;
      } else  {
        CurrentLed--;    
      }
      if(CurrentLed <= 7 || CurrentLed >= 12){
         isAscending = !isAscending;
      }
    }

    
    void DetectPresence(){
      
      int startDetectionTime = millis();
      
      //Yellow Led Blinking 10 * (250ms * 2) => 5 Sec
      int timeBlink = 5000;
      int count = timeBlink / (Default_Blink_Delay     * 2) ;
      
      while (count > 0){
        digitalWrite(LED03_PIN,HIGH);
        digitalWrite(LED04_PIN,LOW);
        delay(Default_Blink_Delay);
        digitalWrite(LED03_PIN,LOW);
        digitalWrite(LED04_PIN,HIGH);
        delay(Default_Blink_Delay);
        digitalWrite(LED04_PIN,LOW);
        count--;
      }
    
      //Green Led Blinking 4 * (250ms * 2) => 2 Sec
      timeBlink = 2000;
      count = timeBlink / (Default_Blink_Delay * 2) ;
      
      while (count > 0){
        digitalWrite(LED05_PIN,HIGH);
        digitalWrite(LED06_PIN,LOW);
        delay(Default_Blink_Delay);
        digitalWrite(LED05_PIN,LOW);
        digitalWrite(LED06_PIN,HIGH);
        delay(Default_Blink_Delay);
        digitalWrite(LED06_PIN,LOW);
        count--;
      }
    
      
      //Red Led Blinking 4 * (250ms * 2) => 2 Sec
      count = timeBlink / (Default_Blink_Delay * 2) ;
      while (count > 0){
        digitalWrite(LED01_PIN,HIGH);
        digitalWrite(LED02_PIN,LOW);
        delay(Default_Blink_Delay);
        digitalWrite(LED01_PIN,LOW);
        digitalWrite(LED02_PIN,HIGH);
        delay(Default_Blink_Delay);
        digitalWrite(LED02_PIN,LOW);
        count--;
      }
    }

    void DetectSound()
    {
      digitalWrite(LED01_PIN,HIGH);
      digitalWrite(LED05_PIN,HIGH);
      delay(Default_Blink_Delay);
      digitalWrite(LED01_PIN,LOW);
      digitalWrite(LED05_PIN,LOW);
      digitalWrite(LED06_PIN,HIGH);
      digitalWrite(LED02_PIN,HIGH);
      delay(Default_Blink_Delay);
      digitalWrite(LED02_PIN,LOW);
      digitalWrite(LED06_PIN,LOW);
    }
};

LedManager LedManager;
