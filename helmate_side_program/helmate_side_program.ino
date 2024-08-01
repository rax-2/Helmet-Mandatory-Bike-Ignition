//                          || श्री ||
#include "lib.h"

int infra_1 = 6;        //IR Sensor 1 pin
int infra_2 = 7;       //IR Sensor 2 pin
int gas = A5;         //Gas Sensor
int gas_limit = 150; // Thresold

void setup() {
  Serial.begin(9600); 
  
  pinMode(infra_1,INPUT);
  pinMode(infra_2,INPUT);
  pinMode(gas,INPUT);
  
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
}

void loop() {
  digitalWrite(LED_BUILTIN,LOW);
  delay(10); 

  int gas_value = analogRead(gas);

//Check Sensors Values
//  Serial.print("gas : ");
//  Serial.println(gas_value);
//  Serial.println(ReadIr(infra_1));
//  Serial.println(ReadIr(infra_2));

//Bike on script
  if ((ReadIr(infra_1) == on()) && (ReadIr(infra_2) == on()) && (gas_value < gas_limit) ) 
  {
    Serial.println("A");
  }

//  Bike Off script
  if ((ReadIr(infra_1) == off())||(ReadIr(infra_2) == off())||(gas_value >= gas_limit))
  {
    digitalWrite(LED_BUILTIN,HIGH);
    delay(5000);
    digitalWrite(LED_BUILTIN,LOW);
    delay(1000);
    while (true)
    {
//      Second time Check
      if ((ReadIr(infra_1) == off())||(ReadIr(infra_2) == off())||(gas_value >= gas_limit))
      {
        digitalWrite(LED_BUILTIN,HIGH);
        Serial.println("D");
        delay(6000);
        digitalWrite(LED_BUILTIN,LOW);
        delay(100);
      }
      else
      {
        digitalWrite(LED_BUILTIN,LOW);
        break;
      }
    }
  }
  digitalWrite(LED_BUILTIN,LOW);
  delay(100); 
}
