#include <Servo.h>

Servo LeftServo;
Servo RightServo;
Servo StringServo;
Servo ClawServo;

void setup() {
  // put your setup code here, to run once:
  RightServo.attach(11);
  LeftServo.attach(10);
  StringServo.attach(5);
  ClawServo.attach(6);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop() {
  int xVal;
  int yVal;
  int number;
  int rotationSpeedUp = 300;
  int rotationSpeedDown = 1535;  // Adjust this value to control the rotation speed
  int rotationDurationUp = 11000;
  int rotationDurationDown = 9000;  // Rotation duration in milliseconds
  int stopDuration = 1000;  //


  while (true) {
    xVal = analogRead(A1) - 506;
    yVal = analogRead(A0) - 532;
    number = analogRead(A2);
    StringServo.writeMicroseconds(1525);  // Adjust the value if needed

// determine which direction joystick is pointed 
    if (abs(xVal) > abs(yVal) && abs(xVal) > 50) {
      double num = (double(xVal) / 550) * 90;
      //Serial.println(num);
      LeftServo.write(90 - num);
      RightServo.write(90 - num);
      delay(10);
      break;
    }

    if (abs(yVal) > abs(xVal) && abs(yVal) > 50) {
      double num = (double(yVal) / 550) * 90;
      LeftServo.write(90 - num);
      RightServo.write(90 + num);
      delay(10);
      break;
    }
    if (abs(xVal) < 20 && abs(yVal) < 20) {
    LeftServo.write(90);
    RightServo.write(90);
    delay(10);
  }
    if (number <= 2){
      ClawServo.write(0);
      StringServo.writeMicroseconds(1535 - rotationSpeedDown);  // Adjust the value if needed
      delay(rotationDurationDown);
      StringServo.writeMicroseconds(1535);  // Stop the servo
      ClawServo.write(180);
      delay(stopDuration);
      StringServo.writeMicroseconds(2000);  // Adjust the value if needed
      delay(rotationDurationUp);
      StringServo.writeMicroseconds(1525);  // Adjust the value if needed
      delay(10);
    }

}}