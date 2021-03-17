// Servo motor wiping using non-blocking timer

// ---------------------------------------------- Libraries

#include <Servo.h>

// ---------------------------------------------- Variables

// Create servo object en helper variables
Servo myservo;
int pos; // stores position
int pos_min = 10;   // servo minimum and maximum angle limit,
int pos_max = 180;  // to avoid shaking motor when over-extending = bad for servo!

boolean wipe_direction;  // stores which way servo is moving

unsigned long time_now;
unsigned long timer_mark;
unsigned long timer_interval = 10; // 10ms steps

void setup() {

  // attaches the servo on pin 5 to the servo object
  myservo.attach(5);
  // call custom function to go to minimum position
  resetPos();
}

void loop() {

  if (timerElapsed()) {

    // if direction is 1 wipe left (up), if 0 wipe right (down)
    if (wipe_direction == 1) {
      pos += 1; // increment pos value by x
    } else {
      pos -= 1; // decrement pos value by x
    }
    pos = constrain(pos, pos_min, pos_max); // constrain new pos within limits range
    myservo.write(pos); // move to new pos

    // if limit reached, flip direction
    if (pos == pos_min) {   // at min, wipe left
      wipe_direction = 1;
    }
    if (pos == pos_max) {   // at max, wipe right
      wipe_direction = 0;
    }
  }
}

void resetPos() {
  // servo to start pos
  pos = pos_min;
  myservo.write(pos);
}

boolean timerElapsed() {

  // what time is it now? 
  // Ie. how many milliseconds have elapsed since boot up?
  time_now = millis();

  // has the interval duration since last time mark elasped?
  if (time_now > timer_mark + timer_interval) { 
    timer_mark = time_now;  // yes, store new time mark and return true value
    return true;
  } else {                  // no, return false value       
    return false;
  }

}
