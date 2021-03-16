// variation on blink, uses 2 custom functions for turning on and off the led
// with a rate argument for setting the wait period


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  ledOn(200);   // call my custom function ledOn, pass it a rate argument
  ledOff(1000);  // call my custom function ledOff, pass it a rate argument                
}


void ledOn(int rate) {
  digitalWrite(LED_BUILTIN, HIGH);   // turn led on
  delay(rate);                       // wait x milliseconds
}
  
void ledOff(int rate) {  
  digitalWrite(LED_BUILTIN, LOW);    // turn led off
  delay(1000);                       // wait x milliseconds
}
