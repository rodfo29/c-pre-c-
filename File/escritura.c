#include <stdio.h>

int main() {
    FILE *file;

    // Abrir el archivo en modo escritura ("w")
    file = fopen("archivo.txt", "w");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Escribir en el archivo
    fprintf(file, "Primera/línea/de/texto.\n");
    fprintf(file, "Segunda/línea/de/texto.\n");

    // Cerrar el archivo
    fclose(file);

    printf("Archivo creado y datos escritos correctamente.\n");
    return 0;
}
