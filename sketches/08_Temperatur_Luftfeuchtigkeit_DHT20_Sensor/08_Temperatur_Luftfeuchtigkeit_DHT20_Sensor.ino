// Example testing sketch for various DHT humidity/temperature sensors
#include "Wire.h"
#include "DHT.h"
#define DHTTYPE DHT20   // DHT 20
/*Notice: The DHT10 and DHT20 is different from other DHT* sensor ,it uses i2c interface rather than one wire*/
/*So it doesn't require a pin.*/
DHT dht(DHTTYPE);         //   DHT10 DHT20 don't need to define Pin
 
void setup() {
 
    Serial.begin(115200);
    Serial.println("DHT20 test!");
    Wire.begin();
    dht.begin();
}
 
void loop() {
    float temp_hum_val[2] = {0};
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
 
 
    if (!dht.readTempAndHumidity(temp_hum_val)) {
        Serial.print("Luftfeuchtigkeit: ");
        Serial.print(temp_hum_val[0]);
        Serial.print(" %\t");
        Serial.print("Temperatur: ");
        Serial.print(temp_hum_val[1]);
        Serial.println(" Grad Celsius");
    } else {
        Serial.println("Konnte Temperatur und Luftfeuchtigkeit nicht lesen.");
    }
 
    delay(1500);
}
