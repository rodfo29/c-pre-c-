#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int valor;
    struct Nodo*siguiente;
}Nodo;


Nodo*crearNodo(int valor){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->valor=valor;
    nuevo_nodo->siguiente=NULL;
    return nuevo_nodo;
}


Nodo*addFront(Nodo*head,int valor){
    Nodo*nuevo_nodo=crearNodo(valor);
    if (head==NULL){
    return nuevo_nodo;
    }
    nuevo_nodo->siguiente=head;
    return nuevo_nodo;
}

Nodo*addEnd(Nodo*head,int valor){
    Nodo*nuevo_nodo=crearNodo(valor);
    if (head==NULL){
    return nuevo_nodo;
    }
    Nodo*actual=head;
    while(actual->siguiente!=NULL){
        actual=actual->siguiente;
    }
    actual->siguiente=nuevo_nodo;
    return head;
}

void printList(Nodo*head){
    if (head!=NULL){
    printf("%d",head->valor);
     return printList(head->siguiente);
    }
    printf("\nLista vacía...\n");
}

void eliminarLista(Nodo*head){

    if (head!=NULL){
    Nodo*aux=head;
    head=head->siguiente;
    printf("\nEliminando nodo con valor: %d \n",aux->valor);
    free(aux);
    return eliminarLista(head);
    }
    printf("\nLista sin nodos...\n");
}

// imprimir lista enlzada alrevés

Nodo* reversa(Nodo*head){
    Nodo*head2=NULL;
    Nodo*aux=head;
    while (aux!=NULL)
    {
        head2=addFront(head2,aux->valor);
        aux=aux->siguiente;
    }
    
    // eliminamos la lista original.
    eliminarLista(head);
    
    return head2;
}









int main(){

    Nodo*head=NULL;
    head=addFront(head,3);
    head=addFront(head,2);
    head=addFront(head,1);
    
    printList(head);
    
    head=addEnd(head,4);
    head=addEnd(head,5);
    head=addEnd(head,6);

    head=reversa(head);
    printList(head);

    eliminarLista(head);


}