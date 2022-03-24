#include "Arduino_DebugUtils.h"

const int BUZZER = 5;
int potentiometer = A0;

unsigned long last_time = 0;

void setup() {
 
  pinMode(BUZZER, OUTPUT);
  pinMode(potentiometer, INPUT); 
 
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(potentiometer);   

  // TODO den eingeleseenen sensorValue im Wertebereich 0-1023 auf den Frequenzbereich 31-200 abbilden
  int frequenz = map( ... );  

  // TODO den Buzzer auf die eingelesene "frequenz" einstellen
  ...

  unsigned long new_time = millis();
  if (new_time - 1000 > last_time) {
    last_time = new_time;
    Debug.print(DBG_INFO, "Potentiometer Wert: %i", sensorValue);
    Debug.print(DBG_INFO, "Frequenz: %i", frequenz);
  }
}
