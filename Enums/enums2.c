#include <stdio.h>

enum estado_civil {
    SOLTERO,
    CASADO,
    DIVORCIADO,
    VIUDO
};

struct persona {
    char nombre[50];
    enum estado_civil estado;  // Usamos enum aquí
};

int main() {
    struct persona p1 = {"Juan", CASADO};

    printf("Nombre: %s\n", p1.nombre);
    printf("Estado civil: %d\n", p1.estado);

    return 0;
}
