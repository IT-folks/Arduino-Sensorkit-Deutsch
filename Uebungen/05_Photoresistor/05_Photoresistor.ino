int light_sensor = A3;  // Original Arduino Sensor Kit
// int light_sensor = A6; // Grove Beginner Kit

unsigned long last_time = 0;

void setup() {
  Serial.begin(115200);  //begin Serial Communication
}

void loop() {

  // TODO den Helligkeitswert der Photodiode am analogen Port "light_sensor" in die Variable raw_light einlesen
  int raw_light = ...    
  // TODO den Wert auf den Wertebereich 0-100 abbilden
  int light = map( ... );  // map the value from 0, 1023 to 0, 100

  unsigned long new_time = millis();
  if (new_time - 1000 > last_time) {
    last_time = new_time;
    Serial.print("Light level: ");
    Serial.println(light);  // print the light value in Serial Monitor
  }
}
