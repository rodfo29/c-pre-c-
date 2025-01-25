#include <stdio.h>
int contadorSlash(char*string){   
        int cont=0;
        while (*string!='\0'){   
            if (*string=='/'){
                cont++;
            }
            string++;
        }
        return cont;
}
   


int main() {
    FILE *file;
    char buffer[256];

    // Abrir el archivo en modo lectura ("r")
    file = fopen("archivo.txt", "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }
    int cont=0;
    // Leer línea por línea
    printf("Contenido del archivo:\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
        cont+=contadorSlash(buffer);
    }
    printf("\nHay un total de %d slash\n",cont);

    // Cerrar el archivo
    fclose(file);
    // Borramos el archivo...
    remove("archivo.txt");
    return 0;
}
