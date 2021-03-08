
// ---------------------------------------------- Libraries

#include <Servo.h>

// ---------------------------------------------- Variables

// Create servo object and helper variables
Servo myservo;
int pos; // stores position
int pos_min = 10;   // servo minimum and maximum angle limit,
int pos_max = 180;  // to avoid shaking motor when over-extending = bad for servo!


void setup() {

  // attaches the servo on pin 5 to the servo object
  myservo.attach(5);

}

void loop() {

  // move up
  for (int i = pos_min ; i <= pos_max; i++) {
    myservo.write(i); 
    delay(20);
  }

  // move down
  for (int i = pos_max ; i >= pos_min; i--) {
    myservo.write(i); 
    delay(20);
  }

}
