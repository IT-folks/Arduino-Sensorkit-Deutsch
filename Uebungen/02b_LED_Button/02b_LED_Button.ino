
const int button = 4; // Original Arduino Sensor Kit: button connected to digital port D4
// const int button = 6; // Grove Beginner Kit: button connected to digital port D6

const int ledPin = 6;
// const int ledPin = 4; // LED pin for Grove Beginner Kit for Arduino

int button_state = 0; 

unsigned long last_time = 0; 

void setup()
{
  Serial.begin(115200);
  // TODO den ledPin auf Ausgang setzen
  pinMode(ledPin, ... );

  // TODO den Schalter Pin "Button" auf Eingang setzen
  pinMode(button, ...);
}

void loop()
{

  // TODO den Zustand des Schalters "button" in die Variable "button_state" einlesen
  button_state = ... ;
  if (button_state == HIGH)
  {
    // TODO: wenn der Schalter gedrückt ist die LED einschalten
    digitalWrite(ledPin, ... );
  }
  else
  {
     // TODO: wenn der Schalter NICHT gedrückt ist die LED ausschalten
    digitalWrite(ledPin, ... );
  }

  unsigned long new_time = millis();

  if (new_time - 500 > last_time)
  {
    last_time = new_time;
    // print out button state to serial port
    if (button_state == HIGH)
    {
      Serial.println("Knopf gedrückt!");
    }
    else
    {
      Serial.println("Knopf nicht gedrückt!");
    }
  }
}
