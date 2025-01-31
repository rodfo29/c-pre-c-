#include <stdio.h>

int main() {
    int x = 5; // 101 en binario
    int pos = 1;

    printf("Original: %d\n", x);
    x = x | (1 << pos); // Activar bit
    printf("Activar bit %d: %d\n", pos, x);

    x = x & ~(1 << pos); // Apagar bit
    printf("Apagar bit %d: %d\n", pos, x);

    x = x ^ (1 << pos); // Alternar bit
    printf("Alternar bit %d: %d\n", pos, x);

    if (x & (1 << pos))
        printf("Bit %d está encendido\n", pos);
    else
        printf("Bit %d está apagado\n", pos);

    return 0;
}
