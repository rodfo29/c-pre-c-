/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{   int num1=1;
   int num2=2;
    int*ptr_1=&num1;
    int*ptr_2=&num2;
    int**ptr_ptr1=&ptr_1;
    int***ptr_ptr_ptr1=&ptr_ptr1;
    *ptr_ptr_ptr1=&ptr_2;
    
    
    printf("\n[ %p ] --> ",&ptr_ptr_ptr1); // Dirección de memoria de *** (triple puntero)
    printf("[ %p ] --> ",ptr_ptr_ptr1); // Dirección de memoria del doble puntero ** (accedemos mediante el contenido del triple puntero)
    printf("[ %p ] --> ",*(ptr_ptr_ptr1)); // Dirección de memoria del puntero simple * (Accedemos mediante la desreferenciación del punteto triple)
    printf("[ %p ] --> ",*(*(ptr_ptr_ptr1))); // Dirección de memoria de la variable num2 (2)
    
    
    printf("         %d\n ",*(*(*ptr_ptr_ptr1))); // Logramos acceder al 
    
    
    printf("\n Triple Puntero (***) "); 
    printf("  Doble Puntero (**) "); 
    printf("   Puntero Simple (*) "); 
    printf("     Direcc.M var num2"); 
    
    
    printf("     Contenido var num2 "); 
 
    
    
    
    
    
    

    return 0;
}