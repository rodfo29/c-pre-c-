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

    char nombre[]="martin";
    char nombre2[]="martin";
    
    printf("%d ",comp(nombre,nombre2));

}