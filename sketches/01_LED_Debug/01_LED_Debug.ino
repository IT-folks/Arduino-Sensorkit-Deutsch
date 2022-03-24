// reference the debugging utilties which are provided in another text (header) file
#include "Arduino_DebugUtils.h"

// a constant, declared once and then used multiple times
const int ledPin = 6; // LED pin for Original Arduino Sensor Kit
//const int ledPin = 4; // LED pin for Grove Beginner Kit for Arduino
 
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);    //Sets the pinMode to Output 
  // enable debug messages on serial port
  Serial.begin(115200);
  // disable debug messages on serial port
  //Debug.setDebugLevel(DBG_NONE);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  Debug.print(DBG_INFO, "LED auf Digital-Port 6 anschalten");
  digitalWrite(ledPin, HIGH); //Sets the voltage to high 

  Debug.print(DBG_INFO, "1000 Millisekunden schlafen");
  delay(1000);             //Waits for 1000 milliseconds 

  Debug.print(DBG_INFO, "LED auf Digital-Port 6 ausschalten");
  digitalWrite(ledPin, LOW);  //Sets the voltage to low

  Debug.print(DBG_INFO, "1000 Millisekunden schlafen");
  delay(1000);             //Waits for 1000 milliseconds 
}
