
// ---------------------------------------------- Libraries

// TODO: Add required library include(s)

// ---------------------------------------------- Variables

// TODO: Add the variable(s) the program needs



void setup() {
  // TODO: Add missing setup code here


  // initial effects, no changes here: 
  resetPos();
  ledsOff();
  setTimer1();
}

void loop() {
  updateStateMachine(); // nothing is to be changed or added in the loop()
}


// ---------------------------------------------- Acting Machine cause functions

boolean timer1Expired() {
  if (millis() > timer1_mark + timer1_duration) {
    return true;
  } else {
    return false;
  }
}

boolean timer2Expired() {
  // TODO: Return whether condition is true or false
}

boolean buttonPressed() {
  // TODO: Return whether condition is true or false
}

boolean wipeFinished() {
  // TODO: Return whether condition is true or false
}



// ---------------------------------------------- Acting Machine effect functions

void resetPos() {
  // servo to start (center) pos
  // TODO: Write code to perform this effect
}

void ledsOff() {
  // leds off
  // TODO: Write code to perform this effect
}

void setTimer1() {
  // store current time mark
  timer1_mark = millis();
}

void setDirection() {
  // choose 0 or 1 randomly
  wipe_dir = random(2);
}

void targetLed() {
  // TODO: Write code to perform this effect
}

void stepWipe() {
  
  if (millis() > timer3_mark + timer3_duration) {

    // if direction is 1 wipe left, if 0 wipe right
    // TODO: Write code to perform this effect

    timer3_mark = millis();
  }
}

void ledsGreen() {
  // TODO: Write code to perform this effect
}

void ledsRed() {
  // TODO: Write code to perform this effect
}

void setTimer2() {
  // TODO: Write code to perform this effect
}

void setTimer3() {
  // TODO: Write code to perform this effect
}

void setWiperSpeed() {
  // speed up wiping by shortening the time between wipe steps
  timer3_duration = map(counter, 0, 9, 20, 1); // map game rounds count to wiper step interval in milliseconds
  timer3_duration = max(timer3_duration, 1);   // make sure result doesn't go smaller than 1 millisecond
}



// ******* no changes or additions below this *******

// ------------------------------------------ Acting Machine control flow

// Collection of states for the Acting Machine 
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
      if (timer1Expired()) {
        setDirection();
        targetLed();
        setWiperSpeed();
        setTimer3();
        current_state = state_wipe;
      }
      break;

    // -------------------------------------- State wipe
    case state_wipe :

      stepWipe();

      if (buttonPressed()) {
        ledsGreen();
        setTimer2();
        current_state = state_win;
      } else {
        if (wipeFinished()) {
          ledsRed();
          setTimer2();
          current_state = state_lose;
        }
      }
      break;

    // -------------------------------------- State win
    case state_win :
      if (timer2Expired()) {
        counter++; // increment game rounds counter
        ledsOff();
        resetPos();
        setTimer1();
        current_state = state_idle;
      }
      break;

    // -------------------------------------- State lose
    case state_lose :
      if (timer2Expired()) {
        counter = 0; // reset game rounds counter
        ledsOff();
        resetPos();
        setTimer1();
        current_state = state_idle;
      }
      break;
  }
} // updateStateMachine
