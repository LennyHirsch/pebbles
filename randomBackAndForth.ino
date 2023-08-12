
// set these to whatever pins you're using to trigger your transistors
// I've set pin1 to 13 just for debugging cause pin 13 has an LED already connected to it (on the Arduino itself).
// That way I can use it for testing. But basically change the 13 to whatever pin you're using.
const int pin1 = 13;
const int pin2 = 3;
const int pin3 = 4;
const int pin4 = 5;

// this bad boy just activates our pins so we can control them
void setup() {
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
}

// set these to the range of times that you wanna wait.
// so if you wanna wait for a minimum of 1 second and a max of 5 seconds, set them to 1000 and 5000.
// later we will randomly select some time to turn the motor on and off
const int min_delay = 10; // minimum time to wait. 0.1 seconds
const int max_delay = 1000; // maximum time to wait. 5 seconds

int dir = 1; // this just keeps track of whether we're spinning one way or the other.
// so like 1 will be clockwise, and when we change direction we change this to 0 for anticlockwise.

// these are just lil helper functions. They're gonna turn on the triggers to the transistors to spin the motor one way or the other.
// just helps us not write a bunch of rly similar code over and over again.
void clockwise() {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}

void anticlockwise() {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
}

void turn_off() {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}

void loop() {
    // turn the motor on and spin
    if dir {
      clockwise();
      dir = 0;
    } else {
      anticlockwise();
      dir = 1;
    }
    // wait some time
    delay(random(min_delay, max_delay));
    // turn off the motor (all transistors closed)
    turn_off();
    // wait some time
    delay(random(min_delay, max_delay));
}