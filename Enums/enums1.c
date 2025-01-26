#include <stdio.h>

enum mes {
    ENERO = 1,  // Asignamos explícitamente el valor 1
    FEBRERO = 2,
    MARZO = 3,
    ABRIL = 4,
    MAYO = 5,
    JUNIO = 6,
    JULIO = 7,
    AGOSTO = 8,
    SEPTIEMBRE = 9,
    OCTUBRE = 10,
    NOVIEMBRE = 11,
    DICIEMBRE = 12
};

int main() {
    enum mes mes_actual = MAYO;

    printf("El mes actual es el número %d.\n", mes_actual);

    return 0;
}
