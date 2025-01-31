#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int valor;
    struct Nodo*siguiente;
}Nodo;


typedef struct Cola{
    Nodo*inicio;
    Nodo*fin;
}Cola;

Nodo*crearNodo(int num){
    Nodo*nuevoNodo=(Nodo*)calloc(1,sizeof(Nodo));
    nuevoNodo->valor=num;
    nuevoNodo->siguiente=NULL;
    return nuevoNodo;
}



Cola crearCola(){
    Cola c;
    c.inicio=NULL;
    c.inicio=NULL;
    return c;
}


void encolar(Cola*cola,int num){
    Nodo*nuevoNodo=crearNodo(num);
    if (!cola->inicio){
        cola->inicio=nuevoNodo;
        cola->fin=nuevoNodo;
        return;
    }
    Nodo*aux=cola->inicio;
    while (aux->siguiente!=NULL)
    {   
            aux=aux->siguiente;
    }
    aux->siguiente=nuevoNodo;
    cola->fin=nuevoNodo;
}
        
int desencolar(Cola*cola){
    Nodo*aux=cola->inicio;
    cola->inicio=cola->inicio->siguiente;
    int valor=aux->valor;
    free(aux);
    return valor;

}

void printCola(Cola*cola){
    if (!cola->inicio){
        printf("Cola vacia...\n");
        return;
    }


    Nodo*aux=cola->inicio;
    
    while(aux){
        printf("%d ",aux->valor);
        aux=aux->siguiente;
    }

    printf("\n\n");

}

void freeQeue(Cola*cola){
    if (!cola->inicio){
        printf("No hay espacio en la cola....\n\n");
        return;
    }

    Nodo*aux;
    while (cola->inicio)
    {
        aux=cola->inicio;
        cola->inicio=cola->inicio->siguiente;
        printf("Liberando NOdo: %d, address : %p\n",aux->valor,aux);
        free(aux);
    }
    // Inicializamos ambos extremos de la cola como nulos.
    cola->inicio=NULL;
    cola->fin=NULL;


}


    



int main(){
    Cola cola=crearCola();

    encolar(&cola,1);
    encolar(&cola,2);
    encolar(&cola,3);
    encolar(&cola,4);
    encolar(&cola,5);


    printCola(&cola);
    desencolar(&cola);
    desencolar(&cola);
    desencolar(&cola);

    printCola(&cola);

    freeQeue(&cola);



}