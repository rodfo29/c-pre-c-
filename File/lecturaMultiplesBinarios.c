#include <stdio.h>

typedef struct {
    int id;
    char nombre[50];
    float salario;
} Empleado;

int main() {
    FILE *archivo;
    Empleado empleados[3];
    // Abrir archivo en modo binario de lectura
    archivo = fopen("empleados.bin", "rb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }


    // Leer estructura del archivo binario
    /*En este caso lo que está pasando es que esa cadena de bytes podemos verlo que 
    es cómo se organiza el arreglo en memoria, por lo que básicamente podemos asignarle 
    ese Bloque de bytes al puntero empleados que nos funcionará como un arreglo sin problemas.
    Leer el archivo binario devuelve el struct en su forma original, con todos los datos ya organizados.*/
    
    fread(empleados, sizeof(Empleado), 3, archivo);

    // Cerrar el archivo
    fclose(archivo);

    for (int i = 0; i < 3; i++) {
            printf("ID: %d, Nombre: %s, Salario: %.2f\n", 
           empleados[i].id, empleados[i].nombre, empleados[i].salario);
}

    return 0;
}
