// SD Karte
#include <SPI.h>
#include <SD.h>
// Sensor kit
#include "Arduino_SensorKit.h"

// low power
#include "LowPower.h"

const int chipSelect = 10;

float pressure;

void setup() {
  Oled.begin();
  Oled.setFlipMode(true);
  Pressure.begin();
  Serial.begin(115200);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1)
      ;
  }
  Serial.println("card initialized.");
}

void loop() {

  // für die Zeit brauchen wir eine Real Time Clock (RTC) shield oder ein
  // GPS shield, da beim Sleep die millis() wieder von vorne zählen

  // make a string for assembling the data to log:
  String dataString = "";

  Oled.setFont(u8x8_font_amstrad_cpc_extended_r);

  // Get and print temperatures
  Oled.setCursor(0, 1);
  Oled.print("Temperatur: ");
  Oled.setCursor(3, 2);
  Oled.print(Pressure.readTemperature());
  Oled.print(" C   ");  // The unit for  Celsius because        original arduino don't support speical symbols

  dataString += "Temperatur: ";
  dataString += String(Pressure.readTemperature());


  // Get and print atmospheric pressure data
  Oled.setCursor(0, 3);
  Oled.print("Luftdruck: ");
  Oled.setCursor(3, 4);
  Oled.print(Pressure.readPressure());
  Oled.print(" Pa   ");

  dataString += " Grad Celsius, Luftdruck: ";
  dataString += String(Pressure.readPressure());

  // Get and print altitude data
  Oled.setCursor(0, 5);
  Oled.print("Hoehe:");
  Oled.setCursor(3, 6);
  Oled.print(Pressure.readAltitude());
  Oled.print(" m  ");

  dataString += " Pa, Hoehe: ";
  dataString += String(Pressure.readAltitude());
  dataString += " m ueber NN";
 
  Oled.refreshDisplay();    // Update the Display  

  // SD Karte schreiben - der Dateiname darf maximal 8.3 Zeichen haben
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("lowpower.txt", FILE_WRITE);
  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening lowpower.txt");
  }

   // Enter power down state for 8 s with ADC and BOD module disabled
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
}
