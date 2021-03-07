
// ---------------------------------------------- Libraries

#include <Servo.h>

// ---------------------------------------------- Variables

// Create servo object en helper variables
Servo myservo;
int pos; // stores position
int pos_min = 10;   // servo minimum and maximum angle limit,
int pos_max = 180;  // to avoid shaking motor when over-extending = bad for servo!

boolean wipe_direction;  // stores which way servo is moving


// rotation sensor on analog pin A0
int rotaPin = A0;
// stores rotation sensor input value
int rotaValue;


void setup() {

  // attaches the servo on pin 5 to the servo object
  myservo.attach(5);
  // call custom function to go to minimum position
  resetPos();

  pinMode(rotaPin, INPUT);
}

void loop() {

  // read sensor input value
  rotaValue = analogRead(rotaPin);

  // scale sensor input value [0,1023] to step size range 
  int step_size = map(rotaValue, 0, 1023, 1, 10);

  // call custom function to move one step, pass step_size parameter
  stepWipe(step_size);

  // slow everything down a little 
  delay(20);

}


void resetPos() {
  // servo to start pos
  pos = pos_min;
  myservo.write(pos);
}

void stepWipe(int st_size) {

  // if direction is 1 wipe left (up), if 0 wipe right (down)
  if (wipe_direction == 1) {
    pos += st_size; // increment pos value by x
  } else {
    pos -= st_size; // decrement pos value by x
  }
  pos = constrain(pos, pos_min, pos_max); // constrain new pos within limits range
  myservo.write(pos); // move step

  // if limit reached, flip direction
  if (pos == pos_min) {   // at min, wipe left
    wipe_direction = 1;
  }
  if (pos == pos_max) {   // at max, wipe right
    wipe_direction = 0;
  }

}
