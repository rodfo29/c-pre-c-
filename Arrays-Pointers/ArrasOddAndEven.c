#include <stdio.h>
#include <stdlib.h>

// Given an array of integers
// Create 2 dinamically allocated arrays
// First array will consist only of "Even Values"   [12,8,10,4]
// Second array will consist only of "Odd Values"   [5,7,2,9]
// The function should simply print the value of both of the arrays
// step2 Return and pass by Ref

void printArrays(int*array,int size){
    if (size<1){
    return;
    }
    if (size==1){
    return;
    }

    int oddSize=0,evenSize=0;

    for (int i=0;i<size;i++){
    if (array[i]%2==0){
        evenSize+=1;
    }else{
    oddSize+=1;
    }
    }
    int*evenArray=(int*)malloc(sizeof(int)*evenSize);
    int*oddArray=(int*)malloc(sizeof(int)*oddSize);
    
    int oddIndex=0,evenIndex=0;
    for (int i = 0; i < size; i++)
    {   
        if (array[i]%2==0){
            evenArray[evenIndex]=array[i];
            evenIndex+=1;
        }else{
            oddArray[oddIndex]=array[i];
            oddIndex+=1;
        }
        
    }
    // print odd array
    for (int i = 0; i < oddSize; i++)
    {
        printf("%d ",oddArray[i]);
    }
    printf("\n");
    
    // print even array
    for (int i = 0; i < evenSize; i++)
    {
        printf("%d ",evenArray[i]);
    }
    printf("\n");
    free(evenArray);
    free(oddArray);
}



        
    












int main(){
    int array[10]={2,3,4,5,6,7,10,11,22,11};
    printArrays(array,10);

}


