
// ---------------------------------------------- Libraries

#include <Servo.h>

// ---------------------------------------------- Variables

// Create servo object en helper variables
Servo myservo;
int pos; // stores position
int pos_min = 10;   // servo minimum and maximum angle limit,
int pos_max = 180;  // to avoid shaking motor when over-extending = bad for servo!

boolean wipe_direction;  // stores which way servo is moving


void setup() {

  // attaches the servo on pin 5 to the servo object
  myservo.attach(5);
  // call custom function to go to minimum position
  resetPos();
}

void loop() {

  // call custom function to move one step
  stepWipe();

  // slow everything down a little 
  delay(20);

}

void resetPos() {
  // servo to start pos
  pos = pos_min;
  myservo.write(pos);
}

void stepWipe() {

  // if direction is 1 wipe left (up), if 0 wipe right (down)
  if (wipe_direction == 1) {
    pos += 2; // increment pos value by x
  } else {
    pos -= 2; // decrement pos value by x
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
