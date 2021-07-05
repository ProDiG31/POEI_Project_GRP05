class LedManager{
  
  private : 
  
    //Led Pins
    int LED01_PIN = 12; //Red
    int LED02_PIN = 11; //Red
    int LED03_PIN = 10; //Yellow
    int LED04_PIN = 9;  //Yellow
    int LED05_PIN = 8;  //Green
    int LED06_PIN = 7;  //Green
    
    int Default_Blink_Delay = 100; 
    unsigned long previousMillis = 0;
    unsigned long paternMillis = 0;
    unsigned long startDetectionMillis = 0;
    unsigned long SoundLedPaternDuration = 1000;
    unsigned long DetectLedPaternDuration = 10000; 
    
    // Variables will change:
    int ledState = LOW;             // ledState used to set the LED

    int CurrentLed;
    bool isAscending;
    bool isBusy; 
  
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

    
    void blinkLed(int Led_Pin01, int Led_Pin02){
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
        digitalWrite(Led_Pin01, ledState);
        digitalWrite(Led_Pin02, ledState);
      }
    }
    
  public: 
     
    void led_setup() {
      //Setup Pin Led 
      pinMode(LED01_PIN, OUTPUT);
      pinMode(LED02_PIN, OUTPUT);
      pinMode(LED03_PIN, OUTPUT);
      pinMode(LED04_PIN, OUTPUT);
      pinMode(LED05_PIN, OUTPUT);
      pinMode(LED06_PIN, OUTPUT);
      
      CurrentLed = LED01_PIN;
      isAscending = false;
      isBusy = false;
    }

    void update_led(int alertState){
      
      switch (alertState){
            case 2:
          runPresencePatern();
          break;
        case 1:
          runSoundPatern();
          break;
        case 0:
        default:
          if(!isBusy){
            runChenillardPatern();
          }
          break;
      }
    }
        
    void runChenillardPatern(){
    
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

    void runSoundPatern(){
        
      unsigned long elapsedTime =  millis() - paternMillis;
      isBusy = true;
      
      if (elapsedTime >= SoundLedPaternDuration){
        isBusy = false;
      } else{
          if(elapsedTime % (Default_Blink_Delay * 2)){
            blinkLed(LED01_PIN,LED05_PIN);   
          } else {
            blinkLed(LED02_PIN,LED06_PIN);
          }         
      }
    }
    
    void runPresencePatern(){
      unsigned long elapsedTime =  millis() - paternMillis;
      isBusy = true;
      
      if (elapsedTime >= DetectLedPaternDuration){
        isBusy = false;
      } else{

        
        if (elapsedTime <= 5000){//FirstCycle
            if(elapsedTime % (Default_Blink_Delay * 2)){
              blinkLed(LED01_PIN,LED05_PIN);   
            } else {
              blinkLed(LED02_PIN,LED06_PIN);
            }
        } else if ((elapsedTime <= 7500)) { //SecondCycle
              if(elapsedTime % (Default_Blink_Delay * 2)){
              blinkLed(LED05_PIN);   
            } else {
              blinkLed(LED06_PIN);
            }
        } else {
            if(elapsedTime % (Default_Blink_Delay * 2)){
              blinkLed(LED01_PIN);   
            } else {
              blinkLed(LED02_PIN);
            }
        }
         
      }
    }
};

LedManager LedManager;
