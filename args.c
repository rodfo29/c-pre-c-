#include <stdio.h>
/*Date cuenta que int argc nos indica la cantidad de elementos que pasamos por linea de comando,
osea que realmente esta cantidad la obtendremos cuando hagamos la llamada al ejecutable : ./argc hola mundo. acá hay 3 argumentos.
ahora como nos podemos dar cuenta argv es un arreglo de punteros que vendría siendo un arreglo que apunta a cada palabra que usemos como argumento
*/
int main(int argc,int*arr) {
    for (int i = 0; i < argc; i++) {
        printf("Argumento %d: %d\n", i, arr[i]);
    }
    return 0;
}