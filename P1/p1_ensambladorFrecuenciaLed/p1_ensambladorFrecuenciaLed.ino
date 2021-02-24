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
   * si esta en high, se llama dos veces al tiempo para 
   * generar un delay de 1 segundo entre instrucciones
   * si esta low, solo se llama una vez y el delay es de 1/2 segundo
   * cbi apaga el 7 bit del puerto b
   * vuelve a hacer lo mismo si D12 esta high/low
   * 
   * asi que el codigo prende el led con frecuencia de 1Hz si 
   * el input esta apagado y de 0.5Hz si esta prendido 
   * 
   * tiempo son tres loops anidado que gastan 255*255*45 operaciones 
   */
  asm (
    "inicio: \n\t"
    "sbi 0x05,0x07 \n\t"
    "sbis 0x05, 0x06 \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "cbi 0x05,0x07 \n\t"
    "sbis 0x05, 0x06 \n\t"
    "call tiempo \n\t"
    "call tiempo \n\t"
    "jmp main \n\t"
    "tiempo: \n\t"
    "LDI r22, 45 \n\t"
    "LOOP_3: \n\t"
    "LDI r21, 255 \n\t"
    "LOOP_2: \n\t"
    "LDI r20, 255 \n\t"
    "LOOP_1: \n\t"
    "DEC r20 \n\t"
    "BRNE LOOP_1 \n\t"
    "DEC r21 \n\t"
    "BRNE LOOP_2 \n\t"
    "DEC r22 \n\t"
    "BRNE LOOP_3 \n\t"
    "ret \n\t"
    );
}
