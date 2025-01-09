#include <stdio.h>
#include <stdlib.h>


int longitud(char*string){
    char*ptr=string;
    int lon=0;
    while (*(ptr)!='\0')
    {
        lon++;
        ptr++;
    }
    return lon;

}

 
char*concatSame(char*string){
    int lon=(longitud(string)*2)+1;
    
    // Remember: the String`s pointer only can point to the first element.
    char*newString=(char*)calloc(lon,sizeof(char));
    char*ptr_newString=newString;

    char*ptr=string;
    
    while (*(ptr)!='\0')
    {
        *ptr_newString=*ptr;
        ptr_newString++;
        ptr++;

    }
    ptr=string;
    
    while (*(ptr)!='\0')
    {
        *ptr_newString=*ptr;
        ptr_newString++;
        ptr++;

    }

    *ptr_newString=*ptr;
    return newString;

}


int main(){
    
    char nombre[]="martin";
    char*new=concatSame(nombre);
    // First Way
    printf("%s\n", new);
    // Second way
    for (char*i=new;*i!='\0';i++){
        printf("%c",*i);
    }



}