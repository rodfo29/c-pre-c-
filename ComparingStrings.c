#include <stdio.h>
#include <stdlib.h>

int comp(char*st,char*st2){
    char*str1=st,*str2=st2;
    while (*str1!='\0')
    {   
        if (*str1!=*str2){
            return 0; 
        }
        str1++;
        str2++;
    }
    
    
    return 1;


}






int main(){

    // char nombre[]="martin";
    char nombre2[]="martin";
    
    // printf("%d ",comp(nombre,nombre2));

    char nombre[7];
    printf("Ingresar nombre: ");
    scanf("%7s",nombre); // Para cadenas es mejor usar fgets a comparación de scanf. Amenos que en el scanf pongamos de tamaño 1 menos al tamaño del buffer, a diferencia de 
    // fgets(nombre,7,stdin); // fgets que si le podemos poner el mismo tamaño del buffer y este automáticamente nos leerá 1 menos del tamaño establecido.
    printf("\nNombre: %s\n",nombre);



}