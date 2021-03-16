// Blinks a Grove chainable RGB led 
// Demonstrates the use of the switch/case statement


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


// keep track of loop count
int loopCounter;


void setup() {  
  // Initialize Chainable LEDs
  FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS); 
  
  leds[0].setRGB(0, 0, 0);
  FastLED.show();  // show it!  
}

void loop() {

  switch(loopCounter%2){
    
    case 0:
      leds[0].setRGB(0, 255, 0);  // set color of first (only) LED in chain to green
      break;

    case 1:
      leds[0].setRGB(0, 0, 0);  // set color of first (only) LED in chain to none
      break;
  }

  FastLED.show();  // show it!  
  delay(1000);     // wait a second

  loopCounter++;   // increment counter variable value by 1

}
