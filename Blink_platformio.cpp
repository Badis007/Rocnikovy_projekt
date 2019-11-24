#include <Arduino.h>

#define LED D0

void setup(){
  pinMode(LED, OUTPUT);
}

void loop(){
  digitalWrite(LED, LOW);
  delay(500);
  digitalWrite(LED, HIGH);
  delay(1000);
}

//Blikání ledky na pinu D0 s využitím ESP8266 a platformia
