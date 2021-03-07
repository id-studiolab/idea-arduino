// ---------------------------------------------- Libraries

#include <FastLED.h>

// ---------------------------------------------- Variables

// Connections to the Chainable RGB LED
#define CLOCK_PIN 7
#define DATA_PIN 8

// How many leds in the chain?
#define NUM_LEDS 1

// An array to hold the led data
CRGB leds[NUM_LEDS];



// button on port D2
int buttonPin = 2;

// booleans can have only 2 states : 0/1, true/false, HIGH/LOW
boolean buttonCurrentState;
boolean buttonPreviousState;

// keep track of press count
int pressCounter;


void setup() {
  // Initialize Chainable LEDs
  FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  leds[0].setRGB(0, 0, 0);
  FastLED.show();

  pinMode(buttonPin, INPUT);
}

void loop() {

  // read state of button input pin
  buttonCurrentState = digitalRead(buttonPin);

  // has the button been pressed?
  if (buttonCurrentState == HIGH && buttonPreviousState == LOW) {

    pressCounter++; // increment counter variable value by 1

    switch (pressCounter % 3) {
      case 0:
        leds[0].setRGB(0, 255, 0);  // set color of first (only) LED in chain to green
        break;

      case 1:
        leds[0].setRGB(0, 0, 255);  // set color of first (only) LED in chain to blue
        break;

      case 2:
        leds[0].setRGB(255, 0, 0);  // set color of first (only) LED in chain to red
        break;
    }
    
    FastLED.show();  // show it!
  }
  
  // store current button state in 'memory' variable to check against in next loop
  buttonPreviousState = buttonCurrentState;

  
}
