#include <stdio.h>

// 32 bit control register
typedef struct ControlRegister
{   
    unsigned int enableDevice: 1; // Bit 0:Enable or disable the device
    unsigned int resetDevice: 1; // bit 1: Reset the device
    unsigned int interrupEnable: 1; // Bit 2: Enable or disable interrupts
    unsigned int modeSelect: 2; // Bits 3-4: Select operating mide (00,01,10 or 11)
    unsigned int reserve : 27; // Bits 5-31: Reserved for future use
    
}ControlRegister;
// Fíjate que el tamaño es de 4 bytes ya que si sumamos llegamos a los 32 bits en total
// Lo que es equivalente a 4 bytes. Por eso es que al determinar el tamaño del struct 
// Nos devuelve 4. Igualmetne si llegamos a agregar otro miembro por ejemplo entero
// Se nos aplicaría el padding subiendo el tamaño a 8 bytes.








int main(){
    ControlRegister control1;
    control1.enableDevice=1;
    control1.interrupEnable=1;
    control1.modeSelect=3;
    control1.resetDevice=1;
    control1.reserve=200;


    printf("%ld\n",sizeof(control1));





}