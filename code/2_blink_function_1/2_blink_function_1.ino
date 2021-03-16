


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {

  blinky(250);   // call my custom blinky function, pass it a rate argument
                    
}


void blinky(int rate) {
  digitalWrite(LED_BUILTIN, HIGH);   // turn on
  delay(rate);                       // use rate parameter passed with function call
  digitalWrite(LED_BUILTIN, LOW);    // turn off
  delay(rate);                       // use rate parameter passed with function call
}
