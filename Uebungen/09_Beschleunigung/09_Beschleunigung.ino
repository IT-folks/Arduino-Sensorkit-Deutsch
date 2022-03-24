#include "Arduino_SensorKit.h"
 
void setup() {
  Serial.begin(115200);
  
  // TODO den Beschleunigungssensor aktivieren
 ...
}
 
void loop() {
  
  Serial.print("x:"); 
  // TODO den X Wert des BeschleunigungsSensors ausgeben
  Serial.print(Accelerometer. ...);  
  Serial.print("  ");
  Serial.print("y:"); 
  Serial.print(Accelerometer.readY());  
  Serial.print("  ");
  Serial.print("z:"); 
  Serial.println(Accelerometer.readZ()); 
 
  delay(1000);
}
