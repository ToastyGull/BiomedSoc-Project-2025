#include <Servo.h>


// delares pre-void setup == global variables
Servo myServo;  // create servo object to control a servo
bool toggle = 0;  // declare toggle as a global variable

void setup() {
  Serial.begin(9600);
  myServo.attach(6);  // attaches the servo on pin 6 to the servo object
}

void loop() {
  consoleinput();

  Sweep(toggle);

}

void consoleinput() {
  println("Enter 1 to sweep the servo");
  if (Serial.available() > 0) {
    // read the incoming byte:
    toggle = Serial.read();
    // say what you got:
    Serial.print("I received: ");
    Serial.println(toggle);
  }
}

void Sweep(bool toggle) {
  if (toggle == 1) {
    // Sweep from 0 to 180 degrees
    for (int angle = 0; angle <= 180; angle++) {
      myServo.write(angle);
      delay(15);  // Small delay for smooth movement
    }
    
    // Sweep back from 180 to 0 degrees
    for (int angle = 180; angle >= 0; angle--) {
      myServo.write(angle);
      delay(15);
    }
    toggle = 0;
    println("Servo sweep complete");
    println("toggle reset to 0");
  }
}