#include <stdio.h>

typedef struct {
    int id;
    char nombre[50];
    float salario;
} Empleado;

int main() {
    FILE *archivo;
    Empleado empleado;

    // Abrir archivo en modo binario de lectura
    archivo = fopen("empleado.bin", "rb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Leer estructura del archivo binario
    fread(&empleado, sizeof(Empleado), 1, archivo);

    // Cerrar el archivo
    fclose(archivo);

    // Mostrar los datos leídos
    printf("ID: %d\n", empleado.id);
    printf("Nombre: %s\n", empleado.nombre);
    printf("Salario: %.2f\n", empleado.salario);

    return 0;
}
