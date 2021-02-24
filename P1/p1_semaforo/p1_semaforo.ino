
const int v2 = 8, a2 = 9, r2 = 10, v1 = 11, a1 = 12, r1 = 13; 
void setup()
{
  for(int i = 8; i<=13; ++i)
    pinMode(i, OUTPUT);
}

void loop()
{
  //primer estado
  digitalWrite(r2, LOW);
  digitalWrite(v2, HIGH);
  
  digitalWrite(a1, LOW);
  digitalWrite(r1, HIGH);
  
  delay(5000); // Wait for 5s
  
  //segundo
  digitalWrite(v2, LOW);
  digitalWrite(a2, HIGH);
  delay(1000);
  
  //tercero;
  digitalWrite(a2, LOW);
  digitalWrite(r2, HIGH);
  
  digitalWrite(r1, LOW);
  digitalWrite(v1, HIGH);
  delay(5000);
  
  //cuarto
  digitalWrite(v1, LOW);
  digitalWrite(a1, HIGH);
  delay(1000);
  
  
}
