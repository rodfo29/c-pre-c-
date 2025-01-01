#include <stdio.h>
#include <stdlib.h>

int**allocatedMatrix(int rows,int columns){
    int**mat=(int**)calloc(rows,sizeof(int));
    
    for (int i=0;i<rows;i++){
        
        mat[i]=(int*)calloc(columns,sizeof(int));
        
        for(int j=0;j<columns;j++){
        
            printf("\nEnter number [%d][%d]",i+1,j+1);
        
            scanf("%d",&mat[i][j]);
        
        }
    }
    
    return mat;

}

void printMatrix(int**mat,int rows,int columns){
   
    for(int i=0;i<rows;i++){
        
        for (int j = 0; j < columns; j++)
        
        {
        
            printf("%d ",mat[i][j]);
        
        }
        
        printf("\n");
    
    }

}
// en caso de querer que la matriz quede apuntando a NULL debemos usar un triple puntero.
void freeMatrix(int**mat,int rows,int columns){
    for (int i = 0; i < rows; i++)
    {
        free(mat[i]);
    }
    printf("%p \n",mat);
    free(mat);
    
    // si quisieramos usar un triple puntero: 
    // for (int i = 0; i < rows; i++) {
    //     free((*mat)[i]);
    // }
    // free(*mat);
    // *mat = NULL;


}



int main(){
    int**a;
    int rows =3,columns=3;
    a=allocatedMatrix(rows,columns);
    printMatrix(a,rows,columns);
    freeMatrix(a,rows,columns);


}