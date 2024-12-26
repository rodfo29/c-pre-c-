#include <stdio.h>


// Pointers store a memory address, so we can dereference them to access the value.

void swap(int*num1,int*num2){
    int temp=*num1;
    *num1=*num2;
    *num2=temp;

}


int main(){
    int num1=10,num2=20,*ptr_num1;
    ptr_num1=&num1;
    printf("%d && %d\n", *ptr_num1,num2);
    swap(&num1,&num2);
    printf("%d && %d\n", num1,num2);

}

