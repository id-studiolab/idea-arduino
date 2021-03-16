// Button presses cycle between 3 colors on a Grove chainable RGB led
// Program structured to match the Acting Machine Diagram

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

// ---------------------------------------------- setup() & loop() 

void setup() {
  // Initialize Chainable LEDs
  FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  leds[0].setRGB(0, 0, 0);
  FastLED.show();
  
  pinMode(buttonPin, INPUT);
}

void loop() {
  updateStateMachine(); // nothing is to be changed or added in the loop()
}


// ---------------------------------------------- Acting Machine cause functions

boolean buttonPressed() {
  
  int button_pressed = false;

  // read state of button input pin
  buttonCurrentState = digitalRead(buttonPin);

  // has the button been pressed?
  if (buttonCurrentState == HIGH && buttonPreviousState == LOW) {
    button_pressed = true;
  }

  // store current button state in 'memory' variable to check against in next call
  buttonPreviousState = buttonCurrentState;
  
  // return result
  return (button_pressed);
}

// ---------------------------------------------- Acting Machine effect functions

void ledsOff() {
  leds[0].setRGB(0, 0, 0);
  FastLED.show();
}

void ledsBlue() {
  leds[0].setRGB(0, 0, 255);
  FastLED.show();
}

void ledsRed() {
  leds[0].setRGB(255, 0, 0);
  FastLED.show();
}

void ledsGreen() {
  leds[0].setRGB(0, 255, 0);
  FastLED.show();
}


// ------------------------------------------ Acting Machine control flow

// Collection of states for the Acting Machine
const int state_idle = 0;
const int state_blue = 1;
const int state_red = 2;
const int state_green = 3;

// Remember the current state (start at state_idle)
int current_state = state_idle;

void updateStateMachine ()
{
  switch (current_state) {

    // -------------------------------------- State idle
    case state_idle :
      if (buttonPressed()) {
        ledsBlue();
        current_state = state_blue;
      }
      break;

    // -------------------------------------- State blue
    case state_blue :
      if (buttonPressed()) {
        ledsRed();
        current_state = state_red;
      }
      break;

    // -------------------------------------- State red
    case state_red :
      if (buttonPressed()) {
        ledsGreen();
        current_state = state_green;
      }
      break;

    // -------------------------------------- State gree
    case state_green :
      if (buttonPressed()) {
        ledsBlue();
        current_state = state_blue;
      }
      break;
  }
} // updateStateMachine
