// a constant, declared once and then used multiple times
const int button = 4;  // Original Arduino Sensor Kit: button connected to digital port D4
// const int button = 6; // Grove Beginner Kit: button connected to digital port D6

int button_state = 0;  // variable for reading the pushbutton status

unsigned long last_time = 0;  // last time we took the time

void setup() {
  Serial.begin(115200);

  // initialize the pushbutton pin as an input:
  pinMode(button, INPUT);
}

void loop() {

  // read the state of the pushbutton value:
  button_state = digitalRead(button);

  unsigned long new_time = millis();
  // if our last measurement is 500 Milliseconds ago
  if (new_time - 500 > last_time) {
    // remember new last_time
    last_time = new_time;
    // print out button state to serial port
    if (button_state == HIGH) {
      Serial.println("Knopf gedrückt!");
    } else {
      Serial.println("Knopf nicht gedrückt!");
    }
  }
}
