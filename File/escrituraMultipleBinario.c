#include <stdio.h>

typedef struct {
    int id;
    char nombre[50];
    float salario;
} Empleado;

int main() {
    FILE *archivo;
    Empleado empleados[] = {
    {1, "Juan Pérez", 50000.50},
    {2, "Ana Gómez", 45000.75},
    {3, "Carlos Ruiz", 60000.80}
    };

    // Abrir archivo en modo binario de escritura
    archivo = fopen("empleados.bin", "wb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Escribir estructura en el archivo binario
    fwrite(empleados, sizeof(Empleado), 3, archivo);

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


/*
Cuando usas funciones como fwrite y fread en C, lo que estás haciendo es trabajar directamente con los bytes crudos que representan al struct en memoria. Esto significa que:

Al escribir (fwrite):

La función toma los bytes desde la dirección del struct en memoria (&struct).
Copia esos bytes, exactamente como están en memoria (incluyendo padding, si lo hay), al archivo.
En esencia, el archivo se convierte en un "reflejo" de cómo el struct estaba organizado en la memoria.
Al leer (fread):

La función toma los bytes desde el archivo.
Los "inyecta" (copia) directamente en la dirección de memoria del struct pasado como argumento.
Esto recrea el struct con todos sus datos en el estado en que estaban cuando fueron escritos, preservando el orden de los atributos y el padding.

*/




/*
sar structs en C es una de las formas más eficaces y organizadas para trabajar con datos binarios porque:

Estructura y organización:

Los structs te permiten agrupar datos relacionados en un solo bloque lógico (como un registro de base de datos).
Esto facilita la representación en memoria y hace que la escritura/lectura sea más simple.
Manipulación directa en binario:

Puedes escribir o leer toda la estructura de datos como un bloque continuo de bytes, sin preocuparte por manejar cada atributo individualmente.
Esto elimina la necesidad de procesar cadenas o dividir los datos en partes más pequeñas.
Código más limpio:

El código es más legible y fácil de mantener. En lugar de manejar muchos datos individuales, puedes trabajar directamente con la instancia del struct.
Eficiencia:

Usar structs reduce la cantidad de operaciones de entrada/salida (I/O), ya que puedes trabajar con toda la estructura de una sola vez, lo que es más rápido que procesar atributos uno por uno.
*/