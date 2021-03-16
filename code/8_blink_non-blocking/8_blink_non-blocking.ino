// Non-blocking version of blink
// Prints to serial monitor while blinking

int loop_counter;

unsigned long time_now;
unsigned long timer_mark;
unsigned long timer_interval = 500;

boolean led_state;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
}


void loop() {

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

  loop_counter++;

  Serial.println(loop_counter);
}


boolean timerElapsed() {

  // what time is it now? 
  // Ie. how many milliseconds have elapsed since boot up?
  time_now = millis();

  // example :
  // timer_mark = 2000 ms (event started 2sec ago)
  // timer_interval = 500 ms (0,5sec blink interval)
  // returns true at 2501 ms (>2500)

  // has the interval duration since last time mark elasped?
  if (time_now > timer_mark + timer_interval) { 
    timer_mark = time_now;  // yes, store new time mark and return true value
    return true;
  } else {                  // no, return false value       
    return false;
  }

}
