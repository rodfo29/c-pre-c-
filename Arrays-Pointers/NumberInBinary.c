#include <stdio.h>

/*  
 Develop a recursive Function that receives an integer value "n"
The function should print the value of "n" in Binary-Representation (base 2)
For example: 
    "n"=4 --> 100
    "n"=6 --> 110
    "n"=12 --> 1100
*/


void Binary(int number){
    if (number==0){
    return;
    }
    // En este caso primero entra en la función y luego que esta termina es que termina es que se ejecuta la instrucción de imprimir.
    // en vez de ejecutarse de atrás hacia adelante, es adelante hacia atrás. 
    Binary(number/2);
    printf("%d",number%2);
}

int main(){
    Binary(10);


}