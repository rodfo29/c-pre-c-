#include <stdio.h>
#include <stdlib.h>











int main(){

// declaramos la columna principal, y luego reservamos la memoria para las filas.
int*array[5];
for(int i=0;i<5;i++){
    array[i]=(int*)malloc(sizeof(int)*3);

}

// OPS
array[1][1]=30;
scanf("%d",&array[0][2]);
printf("array [4][2]= %d\n",array[4][2]);

int numOfColumns;
// El usuario puede decidir cuántos elementos quiere reservar para cada fila.
for (int i=0;i<5;i++){
    printf("Please enter number of columns for this arrow: ");
    scanf("%d",&numOfColumns);
    array[i]=(int*)calloc(numOfColumns,sizeof(int));
    

}








}