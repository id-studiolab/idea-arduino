// Demonstrates labelling and formatting of serial monitor messages.


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


// rotation sensor on analog pin A0
int rotaPin = A0;

// stores rotation sensor input value
int rotaValue;


void setup() {  
  // Initialize serial connection
  Serial.begin(9600);
  
  // Initialize Chainable LEDs
  FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS); 

  pinMode(rotaPin, INPUT);
}

void loop() {

  // read sensor input value
  rotaValue = analogRead(rotaPin);

  // scale sensor input value [0,1023] to LED brightness range [0,255]
  int dim = map(rotaValue, 0, 1023, 0, 255);

  // print value to serial
  Serial.print("Rotation sensor: ");
  Serial.print(rotaValue);
  Serial.print("\tDim value: ");
  Serial.println(dim);

  // set color and show
  leds[0].setRGB(dim, dim, dim);
  FastLED.show();
}
