# Introduction to Programming with Arduino for Design Students
On this page you will find all the materials related to the online class. Components from the IDE Electronics Kit are necessary. The used components list is:
- 1x Seeeduino Lotus Arduino board
- 2x Grove Button
- 2x Grove Chainable RGB LED
- 1x Grove Rotation Sensor
- 1x Grove Servo motor
- 1x Micro USB cable
- 6x Grove cables

## SESSIONS LIST

### 🍅 1. Introduction : why prototyping for designers?
Intro to the Arduino and Grove eco-systems, and their value for designers.

{% include vimeoPlayer.html id=523239406 %}

[[VIDEO]](https://vimeo.com/523239406/4390efdae5)

Installation steps:
1. download and install the [CP2102x USB driver](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)*
2. download and install the [Arduino IDE software](https://www.arduino.cc/en/software/) (v1.8.x, not v2.x or the web editor)
3. [configure](https://wiki.seeedstudio.com/Seeed_Arduino_Boards/) the Arduino IDE software for using the **Seeeduino Lotus** board (not Seeduino Stalker). Start from step 2. In the boards manager select and install **'Seeeduino AVR'** package (not Stalker). **NOTE: the Seeedstudio page has an error, this is the correct URL to add in preferences: https://raw.githubusercontent.com/Seeed-Studio/Seeed_Platform/master/package_legacy_seeeduino_boards_index.json** 

\* This is for current Lotus v1.1 boards. For older v1.0 boards use the [CH340 USB driver](http://www.wch-ic.com/downloads/CH341SER_ZIP.html) 

### 🍅 2. Hello world : Arduino IDE & Blink
Introduction to the Arduino IDE software and controlling the internal LED.

{% include vimeoPlayer.html id=523240097 %}

[[VIDEO]](https://vimeo.com/523240097/a5b9baab76)

[[CODE: Blink with functions]](https://github.com/id-studiolab/idea-arduino/blob/main/code/2_blink_function_1/2_blink_function_1.ino)

**Solution:** [[here]](https://github.com/id-studiolab/idea-arduino/blob/main/code/extra/2_solution/2_solution.ino)

### 🍅 3. My first interaction: button & led
Reading the digital button sensor input, if/else statement and serial monitor feedback.

{% include vimeoPlayer.html id=523470804 %}

[[VIDEO]](https://vimeo.com/523470804/cdb7809d5b)

[[CODE: button and led]](https://github.com/id-studiolab/idea-arduino/blob/main/code/3_button_and_led/3_button_and_led.ino)

**Solution:** [[here]](https://github.com/id-studiolab/idea-arduino/blob/main/code/extra/3_solution/3_solution.ino)

### 🍅 4. Rainbow Warrior : Grove Chainable RGB Led
The Grove chainable RGB LED, FastLED library and switch/case statement.

{% include vimeoPlayer.html id=523241204 %}

[[VIDEO]](https://vimeo.com/523241204/a698351a80)

[[CODE: initializing the chainable RGB led]](https://github.com/id-studiolab/idea-arduino/blob/main/code/4_init_chainable_RGB_led/4_init_chainable_RGB_led.ino)

[[CODE: blink the chainable RGB led]](https://github.com/id-studiolab/idea-arduino/blob/main/code/4_blink_chainable_RGB_led/4_blink_chainable_RGB_led.ino)

[[CODE: blink 2 chainable RGB leds]](https://github.com/id-studiolab/idea-arduino/blob/main/code/4_blink_2x_chainable_RGB_led/4_blink_2x_chainable_RGB_led.ino)

[[CODE: switch/case]](https://github.com/id-studiolab/idea-arduino/blob/main/code/4_blink_switch_case_chainable_led/4_blink_switch_case_chainable_led.ino)

**Solution:** [[here]](https://github.com/id-studiolab/idea-arduino/blob/main/code/extra/4_solution/4_solution.ino)

### 🍅 5. Let's do the twist : rotation sensor
Reading the analog rotation sensor input, scaling values with the map function, more serial monitoring.

{% include vimeoPlayer.html id=523242101 %}

[[VIDEO]](https://vimeo.com/523242101/ac8614c8ca)

[[CODE: rotation sensor]](https://github.com/id-studiolab/idea-arduino/blob/main/code/5_rotation_sensor/5_rotation_sensor.ino)

**Solution:** [[here]](https://github.com/id-studiolab/idea-arduino/blob/main/code/extra/5_solution/5_solution.ino)

### 🍅 6. Talk to me baby : serial messaging
Formatting neat serial monitor messages.

{% include vimeoPlayer.html id=523242373 %}

[[VIDEO]](https://vimeo.com/523242373/dc9f018fee)

[[CODE: serial messaging]](https://github.com/id-studiolab/idea-arduino/blob/main/code/6_serial_messaging/6_serial_messaging.ino)


### 🍅 7. My first robot : servo motor
Controlling the servo motor manually with a rotation sensor and automatically with the for loop. Plus a blocking problem.

{% include vimeoPlayer.html id=523401340 %}

[[VIDEO]](https://vimeo.com/523401340/52f9b3df7a)

[[CODE: servo and rotation sensor]](https://github.com/id-studiolab/idea-arduino/blob/main/code/7_servo_motor_rotation_sensor/7_servo_motor_rotation_sensor.ino)

[[CODE: servo wiper with for loop]](https://github.com/id-studiolab/idea-arduino/blob/main/code/7_servo_wiper_for_loop/7_servo_wiper_for_loop.ino)


### 🍅 8. Time is honey : millis() & proper timing
Non-blocking timing of events.

{% include vimeoPlayer.html id=523401869 %}

[[VIDEO]](https://vimeo.com/523401869/8ea40c624f)

[[CODE: non-blocking blink]](https://github.com/id-studiolab/idea-arduino/blob/main/code/8_blink_non-blocking/8_blink_non-blocking.ino)

**Solution #1:** [[here]](https://github.com/id-studiolab/idea-arduino/blob/main/code/extra/8_solution/8_solution.ino)
**Solution #2:** [[here]](https://github.com/id-studiolab/idea-arduino/blob/main/code/extra/8_solution_2/8_solution_2.ino)

### 🍅 9. The game : Wipe-Out

{% include vimeoPlayer.html id=523402167 %}

[[VIDEO]](https://vimeo.com/523402167/5a131160f3)

[[Acting Machine Diagram: RGB lamp]](https://github.com/id-studiolab/idea-arduino/blob/main/code/9%20RGB%20lamp%20Acting%20Machine%20Diagram.pdf)

[[CODE: RGB lamp with acting machine]](https://github.com/id-studiolab/idea-arduino/blob/main/code/9_RGB_button_acting_machine/9_RGB_button_acting_machine.ino)

[[Acting Machine Diagram: Wipe-Out game]](https://github.com/id-studiolab/idea-arduino/blob/main/code/9%20Wipe%20Out%20game%20Acting%20Machine%20Diagram.pdf)

[[CODE: Wipe-Out template]](https://github.com/id-studiolab/idea-arduino/blob/main/code/9_wipe_out_template/9_wipe_out_template.ino)


## OTHER RESOURCES AND LINKS
- Seeedstudio [Grove wiki](https://wiki.seeedstudio.com/Grove/) documents all the available components
- Seeedstudio [Seeeduino Lotus](https://wiki.seeedstudio.com/Seeeduino_Lotus/) board documentation
- the official [Arduino tutorials](https://www.arduino.cc/en/Tutorial/HomePage/) are a great place to continue your exploration after completing this IDE Academy, and the [Arduino forum](https://forum.arduino.cc/) to look for answers to questions and problems

- A [great game song](https://youtu.be/wmin5WkOuPw) to play during Wipe-Out
- A great [soundscape for coding](https://youtu.be/6xBCdNBqJWE)
- [Dieter Vandoren on the web](https://dietervandoren.net/)
- ... enjoy ❤️

Dieter Vandoren & Aadjan van der Helm

## DID YOU FIND ERRORS OR HAVE SUGGESTIONS ON HOW TO MAKE THIS VIDEO CLASS BETTER?
Please open an issue on the GitHub repository and help us improve the materials for the future students of this course.
