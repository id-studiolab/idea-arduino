
// ---------------------------------------------- Libraries


// ---------------------------------------------- Variables

// Variables to track the passing of time
unsigned long timer_duration = 1000;
unsigned long timer_mark;
unsigned long time_now;

int print_counter;

int button_pin = 2;


void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(button_pin, INPUT);
}

void loop() {

  // timer controlled serial printing
  if ( timerExpired() ) {
    print_counter++;
    Serial.println(print_counter);
  }

  // setting LED, is not interfered by printing timing
  digitalWrite(LED_BUILTIN, digitalRead(button_pin));

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
