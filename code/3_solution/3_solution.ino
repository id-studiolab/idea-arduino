// button on port D2
int buttonPin = 2;

// booleans can have only 2 states : 0/1, true/false, HIGH/LOW 
boolean buttonCurrentState;
boolean buttonPreviousState;

boolean ledState;


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {

  // read state of button input pin
  buttonCurrentState = digitalRead(buttonPin);

  // has the button been pressed?
  if(buttonCurrentState == HIGH && buttonPreviousState == LOW) {
    // is the LED on?
    if(ledState){
      // yes, turn it off
      digitalWrite(LED_BUILTIN, LOW);
      ledState = LOW;
    } else {
      // no, turn it on
      digitalWrite(LED_BUILTIN, HIGH);
      ledState = HIGH;
    }
  } 
  
  // store current button state in 'memory' variable to check against in next loop
  buttonPreviousState = buttonCurrentState;

}
