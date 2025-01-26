#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para un nodo de la lista
typedef struct Nodo {
    char nombre[50];    // Nombre del producto
    float precio;       // Precio del producto
    struct Nodo *siguiente; // Apuntador al siguiente nodo
} Nodo;

// Función para agregar un nodo al inicio de la lista
Nodo* agregarNodo(Nodo *inicio, const char *nombre, float precio) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        perror("Error al asignar memoria");
        return inicio;
    }

    strcpy(nuevo->nombre, nombre);
    nuevo->precio = precio;
    nuevo->siguiente = inicio;
    return nuevo;
}

// Función para mostrar los elementos de la lista
void mostrarLista(Nodo *inicio) {
    Nodo *actual = inicio;
    while (actual != NULL) {
        printf("Producto: %s, Precio: %.2f\n", actual->nombre, actual->precio);
        actual = actual->siguiente;
    }
}

// Función para guardar la lista enlazada en un archivo binario
void guardarLista(Nodo *inicio, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    Nodo *actual = inicio;
    while (actual != NULL) {
        // Escribir el nodo en el archivo binario
        fwrite(actual, sizeof(Nodo), 1, archivo);
        actual = actual->siguiente;
    }


    fclose(archivo);
    printf("Lista guardada en %s\n", nombreArchivo);
}


// Función para leer una lista enlazada desde un archivo binario
Nodo* leerLista(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return NULL;
    }

    Nodo *inicio = NULL, *actual = NULL;

    // Leer nodo por nodo del archivo
    Nodo temp; // Nodo temporal para leer
    // Cada vez que fread lee un bloque de datos (en este caso, de tamaño sizeof(Nodo)), el puntero interno del archivo 
    // se mueve automáticamente al siguiente bloque.
    while (fread(&temp, sizeof(Nodo), 1, archivo)) {
        // Crear un nuevo nodo en memoria
        Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
        if (nuevo == NULL) {
            perror("Error al asignar memoria");
            fclose(archivo);
            return NULL;
        }

        // Copiar los datos leídos al nuevo nodo
        strcpy(nuevo->nombre, temp.nombre);
        nuevo->precio = temp.precio;
        nuevo->siguiente = NULL;

        // Enlazar el nodo a la lista
        if (inicio == NULL) {
            inicio = nuevo;
        } else {
            actual->siguiente = nuevo;
        }
        actual = nuevo;
    }

    fclose(archivo);
    printf("Lista cargada desde %s\n", nombreArchivo);
    return inicio;
}

// Función principal
int main() {
    Nodo *lista = NULL;

    
    // Agregar algunos nodos a la lista
    lista = agregarNodo(lista, "Producto A", 10.5);
    lista = agregarNodo(lista, "Producto B", 20.0);
    lista = agregarNodo(lista, "Producto C", 15.75);

    printf("Lista original:\n");
    mostrarLista(lista);

    // Guardar la lista en un archivo binario
    guardarLista(lista, "pedidos.bin");
    
    // Liberar la memoria original
    while (lista != NULL) {
        Nodo *temp = lista;
        lista = lista->siguiente;
        free(temp);
    }

    // Leer la lista desde el archivo binario
    lista = leerLista("pedidos.bin");

    printf("\nLista recuperada:\n");
    mostrarLista(lista);

    // Liberar la memoria de la lista recuperada
    while (lista != NULL) {
        Nodo *temp = lista;
        lista = lista->siguiente;
        free(temp);
    }

    return 0;
}
