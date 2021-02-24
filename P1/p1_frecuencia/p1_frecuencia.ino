//uso constantes para nombrar a los pines
const int boton = 12;
const int led = 13;
int val;
int contH;
// the setup function runs once when you press reset or power the board
void setup() {

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(boton, INPUT);
  pinMode(led, OUTPUT);
  contH = 0;
}


// the loop function runs over and over again forever
void loop() {
  //con val vemos cual es el estado del boton
  val = digitalRead(boton);
  digitalWrite(led, HIGH);
  if(val == LOW) delay(500);
  else delay(1000);
  digitalWrite(led, LOW);
  if(val == LOW) delay(500);
  else delay(1000);
  }
  //le damos ese estado al led             
}
