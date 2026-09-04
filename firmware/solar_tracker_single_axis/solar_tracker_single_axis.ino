#include <Servo.h>

// Two LDRs compare the light intensity on the left and right.
const int LEFT_LDR_PIN  = A0;
const int RIGHT_LDR_PIN = A1;

// Signal pin of the servo that rotates the solar panel.
const int SERVO_PIN = 9;

Servo panelServo;

int panelAngle = 90;

// Adjust these limits to suit the mechanical range of the prototype.
const int MIN_ANGLE = 15;
const int MAX_ANGLE = 165;

// Prevents unnecessary movement when both readings are almost equal.
const int TOLERANCE = 40;
const int STEP_SIZE = 1;

void setup() {
  panelServo.attach(SERVO_PIN);
  panelServo.write(panelAngle);

  Serial.begin(9600);
  delay(1000);
}

void loop() {
  int leftLight  = analogRead(LEFT_LDR_PIN);
  int rightLight = analogRead(RIGHT_LDR_PIN);

  int lightDifference = leftLight - rightLight;

  // Move only when one side receives noticeably more light.
  if (abs(lightDifference) > TOLERANCE) {
    if (leftLight > rightLight) {
      panelAngle += STEP_SIZE;
    } else {
      panelAngle -= STEP_SIZE;
    }

    panelAngle = constrain(panelAngle, MIN_ANGLE, MAX_ANGLE);
    panelServo.write(panelAngle);
  }

  // Display the readings for testing and calibration.
  Serial.print("Left LDR: ");
  Serial.print(leftLight);
  Serial.print(" | Right LDR: ");
  Serial.print(rightLight);
  Serial.print(" | Servo angle: ");
  Serial.println(panelAngle);

  delay(30);
}
