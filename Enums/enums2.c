#include <stdio.h>

typedef enum estado_civil {
    SOLTERO,
    CASADO,
    DIVORCIADO,
    VIUDO
}estado_civil;

struct persona {
    char nombre[50];
    estado_civil estado;  // Usamos enum aquí
};

int main() {
    struct persona p1 = {"Juan", CASADO};
    if (p1.estado==CASADO){
        printf("Mano si es casado \n");
    }

    printf("Nombre: %s\n", p1.nombre);
    printf("Estado civil: %d\n", p1.estado);

    return 0;
}
