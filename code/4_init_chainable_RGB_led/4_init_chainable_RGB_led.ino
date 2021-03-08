// A sketch with all the required initialization elements to use 1 chainable LED.
// The sketch does nothing but initialize it.


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



void setup() {  
  // Initialize Chainable LEDs
  FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS); 

}

void loop() {


}
