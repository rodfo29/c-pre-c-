#include <stdio.h>
#include <stdlib.h>

int**allocatedMatrix(int rows,int columns){
    int**mat=(int**)calloc(rows,sizeof(int*));
    
    for (int i=0;i<rows;i++){
        
        mat[i]=(int*)calloc(columns,sizeof(int));
        
        // for(int j=0;j<columns;j++){
        
        //     printf("\nEnter number [%d][%d]: ",i+1,j+1);
        
        //     scanf("%d",&mat[i][j]);
        
        // }
    }
    
    return mat;

}

void printMatrix(int**mat,int rows,int columns){
   
    for(int i=0;i<rows;i++){
        
        for (int j = 0; j < columns; j++)
        
        {
        
            printf(" %d ",mat[i][j]);
        
        }
        
        printf("\n");
    
    }

}
// En caso de querer que la matriz quede apuntando a NULL debemos usar un triple puntero.
void freeMatrix(int**mat,int rows,int columns){
    for (int i = 0; i < rows; i++)
    {
        free(mat[i]);
    }
    free(mat);
    // printf("%p \n",&mat);
    
    // si quisieramos usar un triple puntero: 
    // for (int i = 0; i < rows; i++) {
    //     free((*mat)[i]);
    // }
    // free(*mat);
    // *mat = NULL;
}




int**swapRows(int**mat,int rows,int row1,int row2){
    if (row1>rows || row1<=0 ||row2>rows || row2<=0 ){
        printf("\nRow out of range..\n");
        return NULL;
    }    
    
    int*aux=mat[row1-1];
    mat[row1-1]=mat[row2-1];
    mat[row2-1]=aux;
    return mat;


}


int main(){
    int**a;
    int rows,columns;

    printf("\nEnter number of rows and columns : "); 
    scanf("%d %d", &rows,&columns);
    
    a=allocatedMatrix(rows,columns);
    printMatrix(a,rows,columns);
    a=swapRows(a,rows,1,rows);
    
    printf("\n");
    printMatrix(a,rows,columns);
    freeMatrix(a,rows,columns);


}