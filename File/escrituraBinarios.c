#include <stdio.h>

typedef struct {
    int id;
    char nombre[50];
    float salario;
} Empleado;

int main() {
    FILE *archivo;
    Empleado empleado = {1, "Juan Pérez", 50000.50};

    // Abrir archivo en modo binario de escritura
    archivo = fopen("empleado.bin", "wb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Escribir estructura en el archivo binario
    fwrite(&empleado, sizeof(Empleado), 1, archivo);

    // Cerrar el archivo
    fclose(archivo);

    printf("Datos escritos en el archivo binario.\n");
    return 0;
}

/*Modo de apertura del archivo:

"wb": Escritura en binario (sobrescribe el archivo si existe).
"rb": Lectura en binario.
"ab": Agregar datos en binario al final del archivo.


Ventajas del formato binario:

- Más eficiente en términos de espacio y velocidad.
- Almacena los datos directamente como se representan en memoria, sin convertirlos a texto.*/