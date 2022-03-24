// TODO die Bibliothek für das Sensor Kit einbinden (#include)
...
 
void setup() {
  Serial.begin(115200);

  Pressure.begin();
}
 
void loop() {

  Serial.print("Temp: ");
  // TODO die Temperatur ausgeben
  Serial.print(Pressure. ...);
  Serial.println("C"); 
 
  // Get and print atmospheric pressure data
  Serial.print("Pressure: ");
  // TODO den Luftdruck ausgeben
  Serial.print(Pressure. ...);
  Serial.println("Pa");
 
  
  Serial.print("Altitude: ");
  // TODO die Höhe über Normal Null ausgeben
  Serial.print(Pressure....);
  Serial.println("m");
 
  Serial.println("\n");
 
  delay(1000);
}
