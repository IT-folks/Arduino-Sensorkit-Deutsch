#include "Arduino_SensorKit.h"
 
float pressure;
 
void setup() {
  Oled.begin();
  Oled.setFlipMode(true);
  Pressure.begin();
}
 
void loop() {

  Oled.setFont(u8x8_font_amstrad_cpc_extended_r); 
  
  // Get and print temperatures
  Oled.setCursor(0, 1);
  Oled.print("Temperatur: ");
  Oled.setCursor(3, 2);
  Oled.print(Pressure.readTemperature());
  Oled.print(" C   "); // The unit for  Celsius because        original arduino don't support speical symbols
 
  // Get and print atmospheric pressure data
  Oled.setCursor(0, 3);
  Oled.print("Luftdruck: ");
  Oled.setCursor(3, 4);
  Oled.print(Pressure.readPressure());
  Oled.print(" Pa   ");
 
  // Get and print altitude data
  Oled.setCursor(0, 5);
  Oled.print("Hoehe:"); 
  Oled.setCursor(3, 6);
  Oled.print(Pressure.readAltitude());
  Oled.print(" m  ");
 
  Oled.refreshDisplay();    // Update the Display  
 
  delay(1000);
}
