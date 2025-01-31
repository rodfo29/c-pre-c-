#include <stdio.h>


 enum PASOS{
        STOP='q',
        CONTINUE='c',
        NEW='n',
        EDIT='e',
        DELETE='d'
};
int main(){
    // char optionbuf[4];
    // while (optionbuf[0]!=STOP)
    // {
    //     scanf("%4s",optionbuf);
    //     switch (optionbuf[0])
    //     {
    //     case STOP:printf("Saliendo del programa");break;
    //     case CONTINUE:printf("Continuamos\n");break;
    //     case NEW:printf("NUEVO\n");break;
    //     case EDIT:printf("EDITADO\n");break;
    //     case DELETE:printf("BORAMMOS TODO\n");break;



    //     default:
    //         break;
    //     }
    // }
    
        // Recordemos que es tenemos fijo 1 espacio para el salto de línea y también 1 espacio para el caracter nulo 

    char optionbuf[6];
        printf("Ingrese una opción (5 caracteres): ");
    // Con scanf también podemos especificar el tamaño de caracteres que queremos leer únicamente sin excederse.
    // Acá estamos únicamente leyendo 4 caracteres por teclado, y dejamos el último para el caracter nulo.
    // scanf("%6s", optionbuf);
    fgets(optionbuf,5,stdin); // tomará 5 caracteres, el 6to sería para el caracter nulo. osea siempre será 1 menos de lo que indiquemos acá.
    /* Si se encuentra un salto de línea antes de alcanzar el límite máximo de caracteres, 
    este también se almacena en el búfer. Sin embargo, 
    si no se encuentra un salto de línea antes de llegar al límite, 
    no se agrega ningún carácter adicional.*/

    // Entonces siempre será = tamañó -1, si en ese rango se encuentra un salto de línea se añade al buffer, sino este se omite.
    printf("La opción ingresada es: %s", optionbuf);

}