#include <stdio.h>

// Definir una estructura con campos de bits
struct Estado {
    unsigned int encendido : 1;  // 1 bit (0 o 1)
    unsigned int modo      : 2;  // 2 bits (0-3)
    unsigned int velocidad : 3;  // 3 bits (0-7)
};

int main() {
    struct Estado motor = {1, 2, 5};  // Encendido, modo 2, velocidad 5

    printf("Encendido: %d\n", motor.encendido);
    printf("Modo: %d\n", motor.modo);
    printf("Velocidad: %d\n", motor.velocidad);
    /*El formato %u en printf se usa para imprimir números enteros sin signo (unsigned int). En el contexto de bitfields, es útil porque:*/

    return 0;
}
/*
Explicación:

encendido usa 1 bit (solo 0 o 1).
modo usa 2 bits (puede almacenar valores de 0 a 3).
velocidad usa 3 bits (valores de 0 a 7).

Sin Bit Fields, una estructura normal ocuparía 3 enteros (12 bytes). Con Bit Fields, usa 6 bits en total, optimizando memoria.

// Modificaciones posibles: 
motor.velocidad = 3; // Cambia la velocidad
motor.encendido = 0; // Apagar el motor

*/



/*Es esencial usar unsigned int en los bitfields en C y C++ porque:

Evita comportamiento indefinido:

Si usas signed int, el signo puede causar problemas al interpretar los bits. Algunos compiladores pueden generar resultados inesperados cuando se accede a los bits más altos.
Mejor aprovechamiento del almacenamiento:

Los valores sin signo (unsigned int) permiten usar todos los bits para representar valores positivos, lo que es más eficiente en términos de espacio.
Operaciones bit a bit predecibles:

Con unsigned int, las operaciones como desplazamientos (<<, >>) y máscaras (&, |, ^) funcionan de manera más predecible. En cambio, en signed int, el desplazamiento a la derecha (>>) puede realizar extensión de signo, lo que no siempre es deseado.
Compatibilidad con hardware:

En algunos procesadores, las operaciones con enteros sin signo pueden ser más rápidas o requerir menos instrucciones adicionales.*/