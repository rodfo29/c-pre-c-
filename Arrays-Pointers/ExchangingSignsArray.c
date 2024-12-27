#include <stdio.h>

// Develop a recursive Function thar receives an array of integers and its size
// The function should return : 
        // 1- if every two adjacent elements have the opposite sign
        // 0, otherwise (at least one pair of adjacent elements with the same sign)

// if the size of the array is even the result should be odd and if the size of the array the is odd the result should be even
int Exchanging(int*array,int size){
        // Verificamos si 2 numeros adyacentes son del mismo signo si es así retornamos 0, en caso de qeu termine el bucle sin problemas retornamos 1.
        if (size<1){
        return 0;
        }

        for (int i=1;i<size;i++){
                if ((array[i-1]<0 && array[i]<0 ) || (array[i-1]>0) && array[i]>0){
                return 0;
                }
        
        }
        return 1;
        
        
}

int main(){
        // int arr1[] = {1, -2, 3, -4, 5};
        // printf("%d\n",Exchanging(arr1,5));
        // int arr2[] = {-1, 2, -3, 4, -5};
        // printf("%d\n",Exchanging(arr2,5));
        // int arr3[] = {1, 2, -3, -4, 5};
        // printf("%d\n",Exchanging(arr3,5));
        int arr4[] = {-1, -2, -3, -4, -5};
        printf("%d\n",Exchanging(arr4,5));
        int arr5[] = {1, -1, 1, -1, 1};
        printf("%d\n",Exchanging(arr5,5));
        int arr6[] = {1};
        printf("%d\n",Exchanging(arr6,1));
        int arr7[] = {1, -1, -1, 1};
        printf("%d\n",Exchanging(arr7,4));
        int arr8[] = {-1, 1, -1, 1, -1, 1}; 
        printf("%d\n",Exchanging(arr8,6));
        int arr9[] = {1, -2, 3, -4, 5, -6};
        printf("%d\n",Exchanging(arr9,6));
        int arr10[] = {1, 2, 3, 4, 5};
        printf("%d\n",Exchanging(arr10,5));







}