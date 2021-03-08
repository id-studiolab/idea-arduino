
// ---------------------------------------------- Libraries

#include <Servo.h>

// ---------------------------------------------- Variables

// Create servo object and helper variables
Servo myservo;
int pos; // stores position
int pos_min = 10;   // servo minimum and maximum angle limit,
int pos_max = 180;  // to avoid shaking motor when over-extending = bad for servo!

// rotation sensor
int rotaPin = A0;
int rotaValue;

void setup() {

  // attaches the servo on pin 5 to the servo object
  myservo.attach(5);

  pinMode(rotaPin, INPUT);
  
}

void loop() {

  rotaValue = analogRead(rotaPin); // get sensor input value

  pos = map(rotaValue, 0, 1023, pos_min, pos_max); // map sensor input to position range

  myservo.write(pos); // move to new pos


}
