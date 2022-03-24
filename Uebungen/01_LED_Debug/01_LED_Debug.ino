// reference the debugging utilties which are provided in another text (header) file
#include "Arduino_DebugUtils.h"


const int ledPin = 6; 
//const int ledPin = 4; // LED pin for Grove Beginner Kit for Arduino
 
void setup() {
 
  pinMode(ledPin,OUTPUT);   
  // enable debug messages on serial port
  Serial.begin(115200);

  // TODO mit Hilfe des Kommentars die folgende Anweisung aktivieren oder deaktiveren
  // und die Auswirkung auf den seriellen Monitor beobachten
  //Debug.setDebugLevel(DBG_NONE);
}
 
void loop() {
  
  Debug.print(DBG_INFO, "LED auf Digital-Port 6 anschalten");
  digitalWrite(ledPin, HIGH); 

  // TODO eine weitere Debug INFO message ausgeben
  ...
  delay(1000);             

  // TODO eine weitere Debug INFO message ausgeben
  ...
  digitalWrite(ledPin, LOW); 

  Debug.print(DBG_INFO, "1000 Millisekunden schlafen");
  delay(1000);             
}
