#include <stdio.h>

// Develop a recursive and interative Function that receives an array of integers and its size.
// The function should return 1 if the array is a Palindrome, otherwise 0



int palindrome(int*array,int size){
    int start=0,end=size-1;
    while(start<end){
    
        if (array[start]==array[end]){
            start+=1;
            end-=1;
        }
        else{
            return 0;
        }

    }

    return 1;
    
}

// Recursive



int PalindromeRE(int*array,int size ){
    if (*(array)    !=   *(   array + (size-1) )   ){ // Como el inicio va avanzando debemos restarle 2
                                                    // ya que apartir de este le estamos sumando el tamaño (osea es como si el final no estuviera retrocediendo)
    return 0;
    }
    if (size<=1)
    {
    return 1;
    }
    return PalindromeRE(array+1,size-2);
}





int main(){
    int arr[3]={1,2,1};
    printf("\n%d\n",PalindromeRE(arr,3));

}