#include <Servo.h>

Servo myServo;  // create servo object to control a servo

void setup() {
  myServo.attach(6);  // attaches the servo on pin 6 to the servo object
}

void loop() {
  myServo.write(0);    // move the servo to 0 degrees
  delay(200);         // wait for a second
  myServo.write(90);   // move the servo to 90 degrees
  delay(200);         // wait for a second
  myServo.write(180);  // move the servo to 180 degrees
  delay(200);         // wait for a second
}
 