#include <stdio.h>

// Definimos algunas funciones que operan sobre enteros
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    // Declaramos un arreglo de punteros a funciones
    int (*operations[3])(int, int) = {add, subtract, multiply};

    int x = 10, y = 5;

    // Usamos los punteros a funciones en el arreglo
    printf("Add: %d + %d = %d\n", x, y, operations[0](x, y));
    printf("Subtract: %d - %d = %d\n", x, y, operations[1](x, y));
    printf("Multiply: %d * %d = %d\n", x, y, operations[2](x, y));

    return 0;
}