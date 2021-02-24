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
  
  /*
  
    rutina inicio
    le prende el bit 7 al registro io 0x05
    llama a tiempo
    apaga el bit 7 al registro io 0x05
    salta al main
    
    rutina tiempo
    con ayuda tres loops, hace 45*255*255 =  2926125 operaciones
    para consumir tiempo
  
    loop3 hace 45 veces el loop2
    loop 2 hace 255 veces el loop1  
    loop 1 hace 255 operaciones por ciclo 
    ret regresa a la linea despues de donde se llamo la rutina 
  */
  //portB tiene direccion IO 0x05
  
  asm(
    "inicio: sbi 0x05,0x07 \n\t"
    "call tiempo \n\t"   
    "cbi 0x05,0x07 \n\t"
    "call tiempo \n\t"   
    "jmp main \n\t"      
    
    "tiempo: LDI r22, 45 \n\t"   
    "LOOP_3: LDI r21, 255 \n\t" 
    "LOOP_2: LDI r20, 255 \n\t" 
    "LOOP_1: DEC r20 \n\t"      
    "BRNE LOOP_1 \n\t"  
    "DEC r21 \n\t"      
    "BRNE LOOP_2 \n\t" 
    "DEC r22 \n\t" 
    "BRNE LOOP_3 \n\t" 
    "ret \n\t"      
  );
}
