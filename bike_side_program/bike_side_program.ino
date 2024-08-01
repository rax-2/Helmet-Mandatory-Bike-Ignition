//__________________FATIMA______________//
int starter = 5;        //Relay pin 


void setup() {
  pinMode(starter,OUTPUT);
  
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600); 
}

void loop() {  
  if (Serial.available() > 0) 
  { 
    String inputString = Serial.readStringUntil('\n'); 
    inputString.trim(); 
    Serial.println(inputString);
    
    if (inputString == "A"){
      digitalWrite(starter,HIGH);
    }
    
    if (inputString == "D"){
      delay(6000);
      
      if (inputString == "D"){
        
        while (true){
          String inputString = Serial.readStringUntil('\n'); 
          inputString.trim(); 
          Serial.println(inputString);
          
          if (inputString == "A"){
            digitalWrite(starter,HIGH);
            break;
          }
          
          else
          {
            digitalWrite(starter,LOW);
            digitalWrite(LED_BUILTIN,HIGH);
            delay(1000);
            digitalWrite(LED_BUILTIN,LOW);
            delay(1000); 
          }
        }
      }
    }
  }
  delay(500);
}
