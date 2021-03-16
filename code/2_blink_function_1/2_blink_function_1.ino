// variation on blink
// uses 2 custom functions for turning on and off the led


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  ledOn();   // call my custom function ledOn
  ledOff();  // call my custom function ledOff                
}


void ledOn() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn led on
  delay(1000);                       // wait 1000 milliseconds
}
  
void ledOff() {  
  digitalWrite(LED_BUILTIN, LOW);    // turn led off
  delay(1000);                       // wait 1000 milliseconds
}
