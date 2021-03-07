// button on port D2
int buttonPin = 2;

// booleans can have only 2 states : 0/1, true/false, HIGH/LOW
boolean buttonCurrentState;
boolean buttonPreviousState;


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {

  // read state of button input pin
  buttonCurrentState = digitalRead(buttonPin);

  // has the button been pressed?
  if (buttonCurrentState == HIGH && buttonPreviousState == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    // has the button been released?
    if (buttonCurrentState == LOW && buttonPreviousState == HIGH) {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }

  // store current button state in 'memory' variable to check against in next loop
  buttonPreviousState = buttonCurrentState;

}
