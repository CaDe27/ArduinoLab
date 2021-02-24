#include <LiquidCrystal.h>
/*
 * 12 - le da RS
 * 11 - E
 * 5  - D4
 * 4- D5
 * 3 - D6
 * 2 - D7
 */

String nombre =   "Carlos  Alberto ";
String apellido = "Delgado Elizondo ";
int it1, it2;;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  it1 = it2 = 0;
  Serial.begin(9600);

  
}

void loop() {

  lcd.setCursor(15, 0);
  lcd.print(nombre);
  lcd.setCursor(15, 1);
  lcd.print(apellido);
  it1 = 0;
  while(it1 < 15){
    lcd.scrollDisplayLeft();
    delay(500);
    ++it1;
  }

  delay(1000);

  lcd.clear();
  
  
  
}
