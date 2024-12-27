#include <stdio.h>


int Average(int*array,int size){
    int aux=0;
    for(int i=0;i<size;i++){
    aux+=*(array+i);
    }
    return aux;
}
    



int main(){
    int arr[3]={1,2,3};
    printf("%d\n",Average(arr,3));

}