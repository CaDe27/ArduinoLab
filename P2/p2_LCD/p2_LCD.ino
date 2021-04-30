#include <LiquidCrystal.h>
/*
 * 12 - le da RS
 * 11 - E
 * 5  - D4
 * 4- D5
 * 3 - D6
 * 2 - D7
 */

String nombre =   "Carlos Alberto  ";
String apellido = "Delgado Elizondo";
int pos, colIni;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  colIni = 16;
}

void loop() {
  
  lcd.setCursor(colIni, 0);
  lcd.print(nombre);
  lcd.setCursor(colIni, 1);
  lcd.print(apellido);
  pos = colIni;
  while(pos != 0){
    lcd.scrollDisplayLeft();
    delay(500);
    --pos;
  }

  delay(1000);

  lcd.clear();
  
  
  
  
}
