#include <stdio.h>

int longitud(char*str){
    char*ptr_str=str;
    int cont=0;
    while (*ptr_str!='\0')
    {
        cont++;
        ptr_str++;

    }
    return cont;

}


int palindromo(char*str){
    // Pointer to the last character.
    int start=0, end=longitud(str)-1;
    while (start<=end)
    {
        if (str[start]!=str[end]){
            return 0;
        
        }
        start++;
        end--;
    }
    return 1;
}
    



int main(){
    char word[]="reconocer";
    printf("\nLa palabra es palindromo: %d\n",palindromo(word));


}












