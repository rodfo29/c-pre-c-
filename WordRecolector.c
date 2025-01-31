#include <stdio.h>
#include <stdlib.h>


int lengthWord(char*str){
    int len=0;
    while (*str!='\0')
    {
        len++;
        str++;

    }
    return len;

}




typedef int entero;








int main() {
    int a=4;
    printf("%lu\n",sizeof(a));
}

    // int rows;
    // printf("\nEnter number of rows: ");
    // scanf("%d",&rows);
    // getchar();
    
    // Allocate memory for a matrix of strings.
    
    // char**mat=(char**)calloc(rows,sizeof(char*));
    // for (int i = 0; i < rows; i++)
    // {   // All the strings must be allocated  before being stored in the matrix
    //     char *word=(char*)calloc(52,sizeof(char));
    //     printf("\nEnter Word: ");
    //     fgets(word,52,stdin);
    //     mat[i]=word;
    // }

    // for (int i = 0; i < rows; i++)
    // {
    //     printf("%s",mat[i]);
    // }
    

    // for (int i=0;i<rows;i++){
        
        
    //     printf("\n\nLiberando palabra: %s , addres: %p",mat[i],mat[i]);
    //     free(mat[i]);
    // }
    // free(mat);
    

