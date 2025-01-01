#include <stdio.h>
#include <stdlib.h>



int main(){
    int **a; // stores memory pointer.

    int columns,arrows;
    
    printf("Enter number of arrows for this matrix: ");
    scanf("%d",&arrows);
    
    a=(int**)calloc(arrows,sizeof(int));
    
    for (int i = 0; i < arrows; i++)
    {   
        printf("Enter the number of columns for this arrow: ");
        scanf("%d",&columns);
        
        a[i]=(int*)calloc(columns,sizeof(int));
        
        for(int j=0;j<columns;i++){
            
            printf("\nEnter element [%d][%d]",i+1,j+1);
            scanf("%d",&a[i][j]);
        
        }

    }
    




}
