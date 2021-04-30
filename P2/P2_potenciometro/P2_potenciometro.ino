int analogPin = A0;
int led = 13;
int val;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(analogPin); // read the input pin 
  //normal
  /*
  Serial.print ("Conversion analogico-digital: ");
  Serial.println(val); // debug value
  */
  
  //voltaje
  
  float voltaje = float(val*5)/1024;
  Serial.print("Voltaje: ");
  Serial.println(voltaje); // debug value
  
  
  //led
  
  // mayor a 3
  /*
  if(voltaje > 3) {
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }*/
    //proporcional
  
  //analogWrite(led, 51*voltaje);
  
}
