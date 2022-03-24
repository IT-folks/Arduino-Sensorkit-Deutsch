  
#include "Arduino_SensorKit.h"
 
void setup() {
  Oled.begin();
  Oled.setFlipMode(true); // Sets the rotation of the screen
  pinMode(A0, INPUT);
}
 
void loop() {
  int poti_value = analogRead(A0);   //read value from A0
 
  Oled.setFont(u8x8_font_chroma48medium8_r); 
  Oled.setCursor(0, 0);    // Set the Coordinates 
  Oled.print("A0 Pin:");   
  Oled.print(poti_value); // Print the Values  
  Oled.print("   "); // Clear older values
  Oled.refreshDisplay();    // Update the Display 
}
