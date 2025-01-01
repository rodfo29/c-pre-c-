#include <stdio.h>
#include <stdlib.h>



int*insert(int*array,int*size,int newElement,int position){

    if (position>=*(size)){
        *size=*size+1;
        int*newArray=realloc(array,*(size));
        if (newArray== NULL){
            printf("\nError al asignar memoria..\n");
            return NULL;
        }
        else{
            array=newArray;
            array[*(size)-1]=newElement;
            return array;
        
        }
    }else if (position<0){
        *size=*size+1;
        int*newArray=realloc(array,*(size));
        if (newArray== NULL){
            printf("\nError al asignar memoria..\n");
            return NULL;
        }
        else{
            array=newArray;
            for (int i=*(size)-1;i>0;i--){
                array[i]=array[i-1];
            }
            array[0]=newElement;
            return array;
        }
    }
    
    *size=*size+1;
    int*newArray=realloc(array,*(size));
    if (newArray== NULL){
            printf("\nError al asignar memoria..\n");
            return NULL;
    }
    else{
    array=newArray;
    for(int i=*(size)-1;i>position;i--){
        array[i]=array[i-1];
    }
    array[position]=newElement;;
    return array;
    }
        

    

}


// ahora lo hacemos reservando la memoria en la propia función
int*insert2(int*array,int*size,int newElement,int position){
    // We will be always adding 1 element. 
    *(size)=*(size)+1;
    int*newArray=(int*)malloc(sizeof(int)*(*(size)));
    
    if (position>=*(size)){
        for (int i = 0; i <*(size)-1; i++)
        {
            newArray[i]=array[i];
        }
        newArray[*(size)-1]=newElement;
        return newArray;
    }
    
    else if (position<0){
        newArray[0]=newElement;
        for(int i=1,j=0;i<*(size);i++){
        newArray[i]=array[j];
        j++;
        }
        return newArray;

    }

    for(int i=0;i<position;i++){
        newArray[i]=array[i];
    }
    newArray[position]=newElement;

    for (int i =position+1,j=0 ; i<*(size); i++)
    {
        newArray[i]=array[position+j];
        j++;
    }
    return newArray;
    




}



int main(){
    
    // int*array=(int*)malloc(sizeof(int)*5);
    // array[0]=1;
    // array[1]=2;
    // array[2]=4;
    // array[3]=5;
    // array[4]=6;
    // int size=5;
        
    // int*newArray=insert(array,&size,10,3);
    // for(int i=0;i<6;i++){
    // printf("%d ",newArray[i]);
    // }
    // printf("\n");

    int array[5]={1,2,3,4,5};
    int size=sizeof(array)/sizeof(array[0]);
    int*newArray=insert2(array,&size,6,4);
    for (int i=0;i<size;i++){
    printf("%d ",newArray[i]);
    
    }
    printf("\n");
    free(newArray);



}