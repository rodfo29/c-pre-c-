#include <stdio.h>

#include <stdlib.h>

// Recuerda que si queremos retornar un puntero este estar de forma dinámica.


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


}