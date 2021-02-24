#include <Servo.h>
#include <LiquidCrystal.h>


Servo myservo;
const int analogPin = A0;
int val;
float angulo;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  myservo.attach(9);
}

void loop() {
  val = analogRead(analogPin);
  angulo = map(val, 0, 1023, 0, 180);
  myservo.write(angulo);
  
  lcd.setCursor(5, 0);
  lcd.print("Angulo: ");

  
  lcd.setCursor(5, 1);
  if(angulo < 100) lcd.print(" ");
  lcd.print(angulo);

}
