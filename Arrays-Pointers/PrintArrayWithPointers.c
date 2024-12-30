#include <stdio.h>





int main(){
    int arr[4]={1,4,5,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
    printf("%d ",*(arr+i));
    }
   

}