// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

// returns length (lower -1 than real length);
int len(char*str){
    char*ptr_str=str;
    int i=0;
    while (*ptr_str!='\0')
    {
        i++;
        ptr_str++;
    }
    return i;
}

    

    



int main() {
    // Write C code here
    char name[8];
    printf("Ingresar nombre: ");
    fgets(name,8,stdin);
    // name[len(name)-1]='\0';
    printf("\nEl nombre es: %d",len(name));

}