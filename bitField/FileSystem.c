#include <stdio.h>

typedef struct FileSystem
{
    unsigned int read:1;
    unsigned int write:1;
    unsigned int execute:1;

}FileSystem;

void printFileDetails(FileSystem*file){
    printf("READ: %u\nWRITE: %u\nEXECUTE: %u\n",file->read,file->write,file->execute);
}

void changePermissions(FileSystem*file,unsigned int newReadPerm,unsigned int newWritePerm,unsigned int newExecutePerm){
    file->read=newReadPerm;
    file->write=newWritePerm;
    file->execute=newExecutePerm;
}



int main(){
    /*De esta manera podemos representar el uso de los bit field en un sistema de permisos de archivos.*/
    FileSystem file={1,1,1};
    printFileDetails(&file);
    changePermissions(&file,0,0,1);
    printFileDetails(&file);


}

