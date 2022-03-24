int light_sensor = A3;  // Original Arduino Sensor Kit
// int light_sensor = A6; // Grove Beginner Kit

unsigned long last_time = 0;

void setup() {
  Serial.begin(115200);  //begin Serial Communication
}

void loop() {
  int raw_light = analogRead(light_sensor);     // read the raw value from light_sensor pin (A3)
  int light = map(raw_light, 0, 1023, 0, 100);  // map the value from 0, 1023 to 0, 100

  unsigned long new_time = millis();
  if (new_time - 1000 > last_time) {
    last_time = new_time;
    Serial.print("Light level: ");
    Serial.println(light);  // print the light value in Serial Monitor
  }
}
