#include <stdio.h>

int MaxSum(int*array,int size){
    if (size<=0){
    return 0;}
    if (size==1){
    return *(array);}

    int sum=array[0]+array[1];
    
    for (int i=1;i<size;i++){
        if (    (array[i-1]+array[i])>sum   ){
        sum=array[i-1]+array[i];
        }
    }
    return sum;
}







int main(){
    int arr[5]={-4,-8,-4,-4,-7};
    int arr2[1]={4};
    printf("%d\n",MaxSum(arr2,1));
    

}