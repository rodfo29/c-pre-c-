#include <stdio.h>
#include <stdlib.h>

typedef int* hola;
int main(){
    int a,b;
    printf("%p\n%p",&a,&b);
    // for (int i=0;i<5;i++){
    //     char filename[20];
    //     sprintf(filename, "file%d.txt", i);
    //     FILE*file=fopen(filename,"w");
    //     (i%2==0)?fprintf(file,"Hola desde Un archivo Par"):fprintf(file,"Hola desde un archivo Impar");
    //     fclose(file);
    // }

}