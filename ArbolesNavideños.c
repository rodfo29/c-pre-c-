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

    // // Arboles desde el lateral
    // for (int i=0;i<5;i++){
    //     for (int j=0;j<i+1;j++){
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    // // árbol completo
    // The first * starts at : num/2, 
    // num/2+1= number of rows
    printf("\n\n\n\n\n");
    int num=9;
    int start=num/2,end=num/2;
    
    for (int i =0; i <(num/2)+1; i++)
    {
        
        for (int j =0; j <num; j++)
        {   
            if (j==start){
                while (j<=end)
                {
            
                    printf("*");
                    j++;
                }
             }
            printf(" ");
            
        
            
        }
            printf("\n");
            start--;
            end++;
        

    }
    for (int i=0;i<num;i++){
        if (i==(num/2))
        {  
             printf("|");

        } 
        printf("_");
    }
    printf("\n\n\n\n\n");
}