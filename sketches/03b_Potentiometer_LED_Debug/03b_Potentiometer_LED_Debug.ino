// reference the debugging utilties which are provided in another text (header) file
#include "Arduino_DebugUtils.h"


const int ledPin = 6;
int potentiometer = A0; 
 
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);    //Sets the pinMode to Output 
  pinMode(potentiometer, INPUT); //Sets the pinmode to input
  // enable debug messages on serial port
  Serial.begin(115200);
  
  // disable debug messages on serial port
  //Debug.setDebugLevel(DBG_NONE);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(potentiometer); //Read the value from the potentiometer connected to the A0 pin
  Debug.print(DBG_INFO, "Potentiometer Wert: %i", sensorValue);
  
  Debug.print(DBG_INFO, "LED auf Digital-Port 6 anschalten");
  digitalWrite(ledPin, HIGH); //Sets the voltage to high 

  Debug.print(DBG_INFO, "%i Millisekunden schlafen", sensorValue);
  delay(sensorValue);             //Waits for 1000 milliseconds 

  Debug.print(DBG_INFO, "LED auf Digital-Port 6 ausschalten");
  digitalWrite(ledPin, LOW);  //Sets the voltage to low

  Debug.print(DBG_INFO, "%i Millisekunden schlafen", sensorValue);
  delay(sensorValue);             //Waits for 1000 milliseconds 
}
