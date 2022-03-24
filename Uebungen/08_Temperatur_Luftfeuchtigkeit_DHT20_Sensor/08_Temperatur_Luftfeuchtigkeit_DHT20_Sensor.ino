// TODO die Biliotheken für I2C (Wire.h) und DHT20 (DHT.h) einbinden
...

#define DHTTYPE DHT20   // DHT 20

DHT dht(DHTTYPE);        
 
void setup() {
 
    Serial.begin(115200);
    Serial.println("DHT20 test!");
    // TODO den DHT20 Sensor am I2C Bus initialisieren
    ...
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
