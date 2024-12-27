#include <stdio.h>

void print(int*array,int size){
    for (int i=0;i<size;i++){
        printf("%d",*(array+i));
    
    }


}


int binarySearch(int*array,int size, int wanted){
    int start=0;
    int end=size-1;

    while(start<=end){
        int mid=(start+end)/2;

        if (wanted>mid){
        start=mid+1;
        }

        else if (wanted<mid){
        end=mid-1;
        }
        else if (wanted==mid)
        {return 1;
        
        }
        
    
    }
    return 0;



}



int main(){
    int arr[3]={1,2,4};
    // print(arr,3);
    printf("%d\n",binarySearch(arr,3,1));

}