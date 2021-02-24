//uso constantes para nombrar a los pines
const int boton = 12;
const int led = 13;
int val;
// the setup function runs once when you press reset or power the board
void setup() {

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(boton, INPUT);
  pinMode(led, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //con val vemos cual es el estado del boton
  val = digitalRead(boton);
  
  //le damos ese estado al led
  digitalWrite(led, val);                     
}
