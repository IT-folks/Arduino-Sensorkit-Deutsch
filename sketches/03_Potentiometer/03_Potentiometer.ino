int potentiometer = A0;  //Assign to pin A0

unsigned long last_time = 0;

void setup() {
  Serial.begin(115200);           //Begin serial communication
  pinMode(potentiometer, INPUT);  //Sets the pinmode to input
}

void loop() {
  int sensor_value = analogRead(potentiometer);  //Read the value from the potentiometer connected to the A0 pin

  unsigned long new_time = millis();
  if (new_time - 500 > last_time) {  // print values every 500 milliseconds
    last_time = new_time;
    int value = map(sensor_value, 0, 1023, 0, 100);  //Map the value from 0, 1023 to 0, 100
    Serial.print("Potentiometer value: ");
    Serial.println(value);  //Print the value in the serial monitor
  }
}
