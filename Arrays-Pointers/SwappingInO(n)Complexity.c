#include <stdio.h>

// la forma O(n) es así, pero la forma constante es por así decirlo pirata porque solo
// cambia a donde apuntan los punteros de los arreglos, pero no hace que las direcciones de memorias intercambien valores....
void Swap(int* array1,int* array2,int size){

    for (int i=0;i<size;i++){
    int aux=*(array1+i); // Store the first element of the array1

    *(array1+i)=*(array2+i);
    *(array2+i)=aux;
    
    }


}



void print(int*arr,int size){
    for (int i=0;i<size;i++){
        printf("%d , addres: %p\n",arr[i],arr);
    }


}
int main(){
    int arr1[3]={3,2,1};
    int arr2[3]={1,2,3};



    printf("Arreglo 1: \n");
    print(arr1,3);
    printf("Arreglo 2: \n");
    print(arr2,3);
    Swap(arr1,arr2,3);
    printf("Arreglo 1: \n");
    print(arr1,3);
    printf("Arreglo 2: \n");
    print(arr2,3);
}