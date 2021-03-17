// Program template for the Wipe Out game assignement
// Fill-in the missing code blocks labeled with TODO

// ---------------------------------------------- Libraries

// TODO: Add required library include(s)

// ---------------------------------------------- Variables

// TODO: Add the variable(s) the program needs



void setup() {
  // TODO: Add missing setup code here


  // initial effects, no changes here: 
  resetPos();
  ledsOff();
  setStartTimer();
}

void loop() {
  updateStateMachine(); // nothing is to be changed or added in the loop()
}


// ---------------------------------------------- Acting Machine cause functions

boolean startTimerExpired() {
  // TODO: Return whether condition is true or false
}

boolean roundTimerExpired() {
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

void setStartTimer() {
  // store current time mark
  start_timer_mark = millis();
}

void setDirection() {
  // choose 0 or 1 randomly
  wipe_dir = random(2);
}

void targetLed() {
  // TODO: Write code to perform this effect
}

void stepWipe() {
  
  if (millis() > wipe_timer_mark + wipe_timer_duration) {

    // if direction is 1 wipe left, if 0 wipe right
    
    // TODO: Write code to perform this effect

    wipe_timer_mark = millis();
  }
}

void ledsGreen() {
  // TODO: Write code to perform this effect
}

void ledsRed() {
  // TODO: Write code to perform this effect
}

void setWipeTimer() {
  // TODO: Write code to perform this effect
}

void setRoundTimer() {
  // TODO: Write code to perform this effect
}

void setWiperSpeed() {
  // speed up wiping by shortening the time between wipe steps
  wipe_timer_duration = map(counter, 0, 9, 20, 1); // map game rounds count to wiper step interval in milliseconds
  wipe_timer_duration = max(wipe_timer_duration, 1);   // make sure result doesn't go smaller than 1 millisecond
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
