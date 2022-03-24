#include "Arduino_DebugUtils.h"

const int BUZZER = 5;
int potentiometer = A0;

unsigned long last_time = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  pinMode(potentiometer, INPUT);  //Sets the pinmode to input
  // enable debug messages on serial port
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(potentiometer);        //Read the value from the potentiometer connected to the A0 pin
  int frequenz = map(sensorValue, 0, 1023, 31, 200);  //Map the value from 0, 1023 to 31, 200

  tone(BUZZER, frequenz);  //Set the voltage to high and makes a noise

  unsigned long new_time = millis();
  if (new_time - 1000 > last_time) {
    last_time = new_time;
    Debug.print(DBG_INFO, "Potentiometer Wert: %i", sensorValue);
    Debug.print(DBG_INFO, "Frequenz: %i", frequenz);
  }
}
