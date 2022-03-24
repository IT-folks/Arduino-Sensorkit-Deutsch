// reference the debugging utilties which are provided in another text (header) file
#include "Arduino_DebugUtils.h"


const int ledPin = 6;
int potentiometer = A0; 
 
void setup() {
 
  pinMode(ledPin,OUTPUT);   
  pinMode(potentiometer, INPUT); 
 
  Serial.begin(115200);
  
  // disable debug messages on serial port
  //Debug.setDebugLevel(DBG_NONE);
}
 
void loop() {
  
  int sensorValue = analogRead(potentiometer); 
  Debug.print(DBG_INFO, "Potentiometer Wert: %i", sensorValue);
  
  Debug.print(DBG_INFO, "LED auf Digital-Port 6 anschalten");
  digitalWrite(ledPin, HIGH); 

  Debug.print(DBG_INFO, "%i Millisekunden schlafen", sensorValue);
  // TODO so lange Schlafen wie der Potentiometer-Wert sensorValue eingestellt ist
  ...           

  Debug.print(DBG_INFO, "LED auf Digital-Port 6 ausschalten");
  digitalWrite(ledPin, LOW);  

  Debug.print(DBG_INFO, "%i Millisekunden schlafen", sensorValue);
 // TODO so lange Schlafen wie der Potentiometer-Wert sensorValue eingestellt ist
  ...
}
