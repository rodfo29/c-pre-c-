#include <stdio.h>



int main(){
    const int num=10;
    const int * ptrNUm=&num;
    *ptrNUm=20;
    printf("%d\n",num);


}