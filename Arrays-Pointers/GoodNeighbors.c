#include <stdio.h>

/*
    Write a function that receives an array and its size. Return 1, if the array has some element which value
    is equals to the sum of both its neighbors

*/




int GoodNeighbors(int*array,int size){
    if (size<3){
        return 0;
    }
    // Ponemos el menos 1 para evitar llegar al último y usar una dirección de memoria inválida.
    for (int i=1;i<size-1;i++){
            // Validamos que el vecino de enfrente no sea mayor indice que el size del arreglo.
            if (( *(array+i) == (*(array+(i+1)) + *(array+(i-1))) )  ){
            return 1;
        }

    
    }
    return 0;


}





int main(){
    int arr[10]={1,1,3,5345,34,65,32,234,6,7};
    int arr2[2]={1,1};
    printf("%d\n",GoodNeighbors(arr2,2));



}