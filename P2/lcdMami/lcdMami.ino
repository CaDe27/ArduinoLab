#include <LiquidCrystal.h>
/*
 * 12 - le da RS
 * 11 - E
 * 5  - D4
 * 4- D5
 * 3 - D6
 * 2 - D7
 */

String nombre =   "Te quiero ";
String apellido = "mucho Mami!     ";
int it1, it2;;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  it1 = it2 = 0;
  Serial.begin(9600);
 delay(2000);
  
}

void loop() {

  lcd.setCursor(15, 0);
  lcd.print(nombre);
  it1 = 0;
  while(it1 < nombre.length()){
    lcd.scrollDisplayLeft();
    delay(500);
    ++it1;
  }

  lcd.setCursor(25, 1);
  lcd.print(apellido);
  for(int i= 0; i < 5; ++i) {
    lcd.scrollDisplayLeft(); 
    delay(500);
  }
  
  it1 = 24;
  it2 = 0;
  while(it2 <= 9){
    lcd.setCursor(it1, 1);
    lcd.print(apellido);
    delay(500);
    --it1;
    ++it2;
  }

  delay(1000);

  lcd.clear();
  
  
  
}
