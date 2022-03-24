// a constant, declared once and then used multiple times
const int ledPin = 6; // LED pin for Original Arduino Sensor Kit
//const int ledPin = 4; // LED pin for Grove Beginner Kit for Arduino
 
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);    //Sets the pinMode to Output 
}
 
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH); //Sets the voltage to high 
  delay(1000);             //Waits for 1000 milliseconds 
  digitalWrite(ledPin, LOW);  //Sets the voltage to low
  delay(1000);             //Waits for 1000 milliseconds 
}
