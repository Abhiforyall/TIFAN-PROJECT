// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 100;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // Set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // Initialize the serial port:
  Serial.begin(9600);
  Serial.println("Enter '1' to move forward or '2' to move backward.");
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();

    if (input == '1') {
      // Move forward one revolution
      Serial.println("Moving forward (clockwise)");
      myStepper.step(stepsPerRevolution);
    } 
    else if (input == '2') {
      // Move backward one revolution
      Serial.println("Moving backward (counterclockwise)");
      myStepper.step(-stepsPerRevolution);
    }
  }
}
