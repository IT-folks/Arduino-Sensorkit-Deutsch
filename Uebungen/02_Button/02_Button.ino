
const int button = 4;  // Original Arduino Sensor Kit: button connected to digital port D4
// const int button = 6; // Grove Beginner Kit: button connected to digital port D6

int button_state = 0;  // variable for reading the pushbutton status

unsigned long last_time = 0;  

void setup() {
  Serial.begin(115200);

  // TODO den digitalen Pin "button" auf Eingang setzen
  ...
}

void loop() {

  // TODO den digitalen Pin "button" in die Variable "button_state" einlesen
  button_state = digitalRead(button);

  unsigned long new_time = millis();
 
  if (new_time - 500 > last_time) {
   
    last_time = new_time;
   // TODO die Bedingung ersetzen: Wenn der Knopf gedrückt ist, dann...
    if ( ...Bedingung_hier_hineinschreiben... ) {
      Serial.println("Knopf gedrückt!");
    } else {
      Serial.println("Knopf nicht gedrückt!");
    }
  }
}
