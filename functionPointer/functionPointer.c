#include <stdio.h>

int sum(int a,int b){

    return a+b;
}

int multiplicacion(int a,int b){
    return a*b;
}


// Manera en la que podemos reutilizar una función cambiando sus parámetro que es Puntero a otras funciones. Hacemos que no sea dependiente de únicamente una función en específica.
void operation(int(*function)(int,int),int a,int b){
    printf("El resultado de la operacion de %d y %d es : %d\n",a,b,function(a,b));
    
}

int main(){
    // De este manera declaramos el puntero a la función, tipoDeDato(*nombreFunción)(tipoDeDato Parámetro1, tipoDeDato Parámetro2).
    int(*ptrFunctionSum)(int, int);
    ptrFunctionSum=&sum;
    int s=(*ptrFunctionSum)(1,2);
    printf("El resultado es: %d \n",s);

    // Reutilizamos el código para cualquier función.
    operation(&sum,2,3);
    operation(&multiplicacion,2,3);


}