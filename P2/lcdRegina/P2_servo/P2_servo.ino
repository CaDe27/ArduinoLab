#include <Servo.h>
#include <LiquidCrystal.h>


Servo myservo;
const int analogPin = A0;
int val;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  val = analogRead(analogPin);
  myservo.write(map(val, 0, 1023, 0, 180));
  
  
}
