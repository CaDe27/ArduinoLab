#include <LiquidCrystal.h>

double mymap(double val, double a, double b, double c, double d){
  return c + (val - a)/(b-a)*(d-c);
}

double temp, v, a0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  
}


void loop() {
  a0 = analogRead(A0);
  v = mymap(a0, 0, 1023, 0, 5);
  //antes de amplificar
  //temp = v*1000/10;

  //despues de amplificar
  temp  = v*1000/100;
  Serial.print("mapeo: ");
  Serial.print(a0, 5);
  Serial.print(" voltaje :");
  Serial.print(v, 5);
  Serial.print("V temperatura: ");
  Serial.print(temp, 5);
  Serial.println("ºC");

  lcd.setCursor(0, 0);
  lcd.print(String("Voltaje: "+String(v,5)));
  lcd.setCursor(0, 1); 
  lcd.print(String("temp: "+String(temp, 5)));
  delay(1000);
  
  lcd.clear();
  
  
  
  
}
