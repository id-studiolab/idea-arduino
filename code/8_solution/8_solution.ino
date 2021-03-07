
// ---------------------------------------------- Libraries


// ---------------------------------------------- Variables

// Variables to track the passing of time
unsigned long timer_duration = 1000;
unsigned long timer_mark;
unsigned long time_now;

boolean led_state;


void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  // timer controlled blinking
  if ( timerExpired() ) {
    if (led_state) {
      digitalWrite(LED_BUILTIN, LOW);
      led_state = 0;
    } else {
      digitalWrite(LED_BUILTIN, HIGH);
      led_state = 1;
    }
  }
}

boolean timerExpired() {

  // what time is it now? Ie. how many milliseconds have elapsed since boot up?
  time_now = millis();

  // has the interval duration since last time mark elasped?
  if (time_now > timer_mark + timer_duration) {   // yes, store new time mark and return true value
    timer_mark = time_now;
    return true;
  } else {    // no, return false value
    return false;
  }
}
