#include <stdio.h>

typedef struct Persona{
    char nombre[21];
    int edad;
    int sueldo;
    void(*informacionPersona)(char*,int,int);
}Persona;

void infoPersonal(char*nombre,int edad,int sueldo){
    printf("Nombre: %s\nEdad: %d\nSueldo:%d\n",nombre,edad,sueldo);
}

void asigNombre(char*cadenaDestino,char*cadenaFuente){
    while (*cadenaFuente!='\0')
    {
        *cadenaDestino=*cadenaFuente;
        cadenaDestino++;
        cadenaFuente++;
    }
    *cadenaDestino=*cadenaFuente;
}




int main(){
    Persona persona1;
    asigNombre(persona1.nombre,"martin");
    persona1.edad=18;
    persona1.sueldo=2500;
    persona1.informacionPersona=infoPersonal;


    persona1.informacionPersona(persona1.nombre,persona1.edad,persona1.sueldo);
    printf("%ld",sizeof(persona1));
    
}
