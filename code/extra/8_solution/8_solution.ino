// Non-blocking version of blink
// Rotation sensor controls rate of blinking

int loop_counter;

unsigned long time_now;
unsigned long timer_mark;
unsigned long timer_interval = 500;

// led
boolean led_state;

// rotation sensor
int rotaPin = A0;
int rotaValue;


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(rotaPin, INPUT);
}


void loop() {

  rotaValue = analogRead(rotaPin); // get sensor input value
  
  timer_interval = map(rotaValue, 0, 1023, 50, 1000); // map sensor input to ms rate range
  
  // timer controlled blinking
  if (timerElapsed()) {
    if (led_state == 0) {
      digitalWrite(LED_BUILTIN, HIGH);
      led_state = 1;
    } else {
      digitalWrite(LED_BUILTIN, LOW);
      led_state = 0;
    }
  }
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
