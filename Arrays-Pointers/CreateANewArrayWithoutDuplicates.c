#include <stdio.h>
#include <stdlib.h>
// 1- returning 2 pointers
void arrayWithoutDuplicates1(int*array,int size,int*newSize,int**returnedArray){
    if (size<1){
    
    return;
     }
     if (size==1){
    *returnedArray= array;
    return;
     }

    int realSize=1;
    int aux=*(array); // ---> array[0]
    // Get the real size of the array
    for(int i=1;i<size;i++){
        if (aux!=array[i]){
            realSize+=1;
            aux=array[i];
        }
    }

    // Reserve memory for the new array
    int*newArray=(int*)malloc(sizeof(int)*realSize);
    aux=array[0];
    *(newArray)=aux;
    int newIndex=1;
    
    for(int i=1;i<size;i++){
        if (array[i]!=aux){
        newArray[newIndex]=array[i];
        aux=array[i];
        newIndex+=1;
        }
    
    }
    *returnedArray=newArray;
    *newSize=realSize;



}


int*arrayWithoutDuplicates2(int*array,int size,int*newSize){
    if (size<1){
    return NULL;
    }

    if (size==1){
    return array;
    }

    int realSize=1,actualElement=*(array);
    for(int i=1;i<size;i++){
        if (array[i]!=actualElement){
        realSize+=1;
        actualElement=array[i];
        }
    }

    int*newArray=(int*)malloc(sizeof(int)*realSize);
    int newIndex=1;
    actualElement=*(array);
    *newArray=actualElement;

    for(int i=1;i<size;i++){
        if (actualElement!=array[i]){
        newArray[newIndex]=array[i];
        actualElement=array[i];
        newIndex+=1;

        }
    
    }
    
    *newSize=realSize;
    return newArray;
    

}



int main(){
    int array[10]={1,3,3,4,6,6,8,8,12,12,};
    int newSize;

    int*newArray=arrayWithoutDuplicates2(array,10,&newSize);
    // arrayWithoutDuplicates(array,10,&newSize,&newArray);
   
    
    for (int i=0;i<newSize;i++){
        printf("%d ",newArray[i]);
    }
    printf("\n");
    free(newArray);
    printf("%d",*newArray);


    

}