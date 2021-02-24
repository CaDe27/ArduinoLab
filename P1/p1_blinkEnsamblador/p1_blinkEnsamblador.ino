void setup()
{
  DDRB = DDRB | B10000000;
  // Data Direction Register B: Inputs 0-6, Output 7
}
void loop()
{
  /*
   * 0x05 es el puerto B
   * sbi pone en uno el bit 7 del puerto b
   * se llama al tiempo para generar un delay
   * cbi apaga el 7 bit del puerto b
   * vuelve a llamar a tiempo y reinicia
   * 
   * asi que el codigo hace el blink
   * prende, gasta tiempo, apaga, gasta tiempo, repite
   * 
   * tiempo son tres loops anidado que gastan 255*255*45 operaciones 
   */
  asm (
    "inicio: \n\t"
    "sbi 0x05,0x07 \n\t"
    "call tiempo \n\t"
    "cbi 0x05,0x07 \n\t"
    "call tiempo \n\t"
    "jmp main \n\t"
    "tiempo: \n\t"
    "LDI r22, 45 \n\t"
    "LOOP_3: \n\t"
    "LDI r21, 255 \n\t"
    "LOOP_2: \n\t"
    "LDI r20, 255 \n\t"
    "LOOP_1: \n\t""DEC r20 \n\t"
    "BRNE LOOP_1 \n\t"
    "DEC r21 \n\t"
    "BRNE LOOP_2 \n\t"
    "DEC r22 \n\t"
    "BRNE LOOP_3 \n\t"
    "ret \n\t"
    );
}
