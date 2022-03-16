// Solution code of the Wipe Out game assignment 

// ---------------------------------------------- Libraries

#include <FastLED.h>
#include <Servo.h>

// ---------------------------------------------- Variables

// Connections of the ChainableLED
#define CLOCK_PIN 7
#define DATA_PIN 8

// How many leds
#define NUM_LEDS 2

// An array to hold the led data
CRGB leds[NUM_LEDS];

// Create servo object en helper variables
Servo myservo;
int pos; // stores position
int pos_min = 10;   // servo minimum and maximum angle limit,
int pos_max = 180;  // to avoid shaking motor when over-extending = bad for servo!

// Make it possible to track the passing of time
unsigned long start_timer_duration = 2000; // start delay
unsigned long start_timer_mark = 0;
unsigned long round_timer_duration = 2000; // round end delay
unsigned long round_timer_mark = 0;
unsigned long wipe_timer_duration = 20; // wiper step interval
unsigned long wipe_timer_mark = 0;

// Variables to track button states
boolean button_success = false;

int button1_pin = 2;
boolean button1_current_state = LOW;
boolean button1_last_state = LOW;

int button2_pin = 3;
boolean button2_current_state = LOW;
boolean button2_last_state = LOW;

// Variable to store game progression
int counter = 0;

// Variable for direction of movement
boolean wipe_dir;

void setup() {

  // Initialize Chainable LED
  FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);

  // attaches the servo on pin 5 to the servo object
  myservo.attach(5);

  // seed random generator to make it non-repetitive,
  // using A1 because it's unlikely a Grove component is attached to it,
  // noise on the input feeds the seed
  randomSeed(analogRead(A1));

  // set button pins to input
  pinMode(button1_pin, INPUT);
  pinMode(button2_pin, INPUT);

  // initial effects
  resetPos();
  ledsOff();
  setStartTimer();
}

void loop() {
  updateStateMachine();
}

// ---------------------------------------------- Acting Machine cause functions

boolean startTimerExpired() {
  if (millis() > start_timer_mark + start_timer_duration) {
    return true;
  } else {
    return false;
  }
}

boolean roundTimerExpired() {
  if (millis() > round_timer_mark + round_timer_duration) {
    return true;
  } else {
    return false;
  }
}

boolean buttonPressed() {

  // return true if the correct button is pressed, else false

  if (wipe_dir == 1) { // wiping left

    button1_current_state = digitalRead(button1_pin);

    if (button1_current_state == HIGH && button1_last_state == LOW) {
      button_success = true;
    } else {
      button_success = false;
    }
    button1_last_state = button1_current_state;
    return (button_success);

  } else { // wiping right

    button2_current_state = digitalRead(button2_pin);

    if (button2_current_state == HIGH && button2_last_state == LOW) {
      button_success = true;
    } else {
      button_success = false;
    }
    button2_last_state = button2_current_state;
    return (button_success);
  }
}

boolean wipeFinished() {
  // return true if wiper arrived at destination, else false
  if (wipe_dir == 1) {    // wiping left
    if (pos == pos_max) {
      return true;
    } else {
      return false;
    }
  } else {                // wiping right
    if (pos == pos_min) {
      return true;
    } else {
      return false;
    }
  }
}



// ---------------------------------------------- Acting Machine effect functions

void resetPos() {
  // servo to start pos
  pos = 90;
  myservo.write(pos);
}

void ledsOff() {
  // leds off
  leds[0].setRGB(0, 0, 0);
  leds[1].setRGB(0, 0, 0);
  FastLED.show();
}

void setStartTimer() {
  // store current time mark
  start_timer_mark = millis();
}

void setDirection() {
  // choose 0 or 1 randomly
  wipe_dir = random(2);
}

void targetLed() {
  // if counter is even number light right led, else left led
  if (wipe_dir == 1) {
    leds[0].setRGB(255, 255, 255);
  } else {
    leds[1].setRGB(255, 255, 255);
  }
  FastLED.show();
}

void stepWipe() {
  // if direction is 1 wipe left, if 0 wipe right

  if (millis() > wipe_timer_mark + wipe_timer_duration) {
    if (wipe_dir == 1) {
      pos++; // left, increment pos value by 1
    } else {
      pos--; // right, decrement pos value by 1
    }
    pos = constrain(pos, pos_min, pos_max); // constrain new pos within [min, max] servo range
    myservo.write(pos); // move step

    wipe_timer_mark = millis();
  }
}

void ledsGreen() {
  leds[0].setRGB(0, 255, 0);
  leds[1].setRGB(0, 255, 0);
  FastLED.show();
}

void ledsRed() {
  leds[0].setRGB(255, 0, 0);
  leds[1].setRGB(255, 0, 0);
  FastLED.show();
}

void setRoundTimer() {
  // store current time mark
  round_timer_mark = millis();
}

void setWipeTimer() {
  // store current time mark
  wipe_timer_mark = millis();
}

void setWiperSpeed() {
  // speed up wiping by shortening the time between wipe steps
  wipe_timer_duration = map(counter, 0, 9, 20, 1); // wiper step interval in milliseconds
  wipe_timer_duration = max(wipe_timer_duration, 1); // make sure result doesn't go smaller than 1 millisecond
}


// ------------------------------------------ Acting Machine control flow

// Collection of states of the Acting Machine (state machine)
const int state_idle = 0;
const int state_wipe = 1;
const int state_lose = 2;
const int state_win = 3;

// Remember the current state
int current_state = 0;

void updateStateMachine ()
{
  switch (current_state) {

    // -------------------------------------- State idle
    case state_idle :
      if (startTimerExpired()) {
        setDirection();
        targetLed();
        setWiperSpeed();
        setWipeTimer();
        current_state = state_wipe;
      }
      break;

    // -------------------------------------- State wipe
    case state_wipe :

      stepWipe();

      if (buttonPressed()) {
        ledsGreen();
        setRoundTimer();
        current_state = state_win;
      } else {
        if (wipeFinished()) {
          ledsRed();
          setRoundTimer();
          current_state = state_lose;
        }
      }
      break;

    // -------------------------------------- State win
    case state_win :
      if (roundTimerExpired()) {
        counter++; // increment game rounds counter
        ledsOff();
        resetPos();
        setStartTimer();
        current_state = state_idle;
      }
      break;

    // -------------------------------------- State lose
    case state_lose :
      if (roundTimerExpired()) {
        counter = 0; // reset game rounds counter
        ledsOff();
        resetPos();
        setStartTimer();
        current_state = state_idle;
      }
      break;
  }
} // updateStateMachine
