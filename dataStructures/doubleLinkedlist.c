#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo
{
    int valor;
    struct Nodo *siguiente;
    struct Nodo *anterior;
}Nodo;

typedef struct LinkedList
{
    Nodo *head;
}LinkedList;

Nodo* crearNodo(int valor){
    Nodo *nuevoNodo=(Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor=valor;
    nuevoNodo->siguiente=NULL;
    nuevoNodo->anterior=NULL;
    return nuevoNodo;
}


LinkedList* crearLista(){
    LinkedList*nuevaLista=(LinkedList*)malloc(sizeof(LinkedList));
    nuevaLista->head=NULL;
    return nuevaLista;
}

Nodo*addFront(Nodo*head,int valor){
    // Creamos el nuevo nodo
    Nodo*nuevoNodo=crearNodo(valor);
    if (head==NULL){
        return nuevoNodo;
    }

    // El campo siguiente del nuevo nodo apunta a la antigua cabeza, el campo anterior el la vieja cabeza apunta al nuevo nodo y retornamos el nuevo nodo para que sea la nueva cabeza.
    nuevoNodo->siguiente=head;
    head->anterior=nuevoNodo;
    return nuevoNodo;
}

Nodo *addEnd(Nodo*head,int valor){
    Nodo*nuevoNodo=crearNodo(valor);
    if (head==NULL){
        return nuevoNodo;
    }

    Nodo*aux=head;
    while(aux->siguiente!=NULL){
        aux=aux->siguiente;
    }

    aux->siguiente=nuevoNodo;
    nuevoNodo->anterior=aux;

    // Retornamos el puntero a la cabeza de la lista.
    return head;
}    

// Puntero de tipo nodo (cabeza de la lista)
void printLista(Nodo*head){
    if (head== NULL){
        printf("Lista vacia...\n\n");
        return;
    }

    Nodo*aux;

    printf("Lista Normal: ");
    
    // Iteramos hasta el último nodo y guardamos su referencia en "aux"
    while(head!=NULL)
    {
        printf("%d -> ",head->valor);
        if (head->siguiente==NULL){
        aux=head;
        }
        head=head->siguiente;
    }
    printf("NULL\n");



    printf("Lista en reversa: ");
    
    while (aux!=NULL)
    {
        printf("%d -> ",aux->valor);
        aux=aux->anterior; // La variable ahora apunta a la dirección de memoria que guarda en su campo " anterior "

    }
    printf("NULL\n");

}

void freeAll(LinkedList*list){
    if (list->head==NULL){
        printf("Lista vacia..\n");
        return;
    }

    Nodo*aux;
    while (list->head!=NULL)
    {
        aux=list->head;
        printf("Liberando la memoria de : %d , address : %p\n",list->head->valor,list->head);
        list->head=list->head->siguiente;
        free(aux);
    }
  // Hacemos campo head (Cabeza de la lista) apunte a null, esto evita que siga apuntando a una dirección de memoria no válida.
   list->head=NULL;
    


}



    






int main(){
    LinkedList*newlist=crearLista();
    newlist->head=addFront(newlist->head,3);
    newlist->head=addFront(newlist->head,2);
    newlist->head=addFront(newlist->head,1);
    
    
    newlist->head=addEnd(newlist->head,4);
    newlist->head=addEnd(newlist->head,5);
    newlist->head=addEnd(newlist->head,6);
	/*
	 Podemos imprimir la lista sin problemas ya que estamos usando una puntero que es una copia 
	 al head de la lista. No estamos accediendo a partir de la estructura de la lista, sino 
	 que lo estamos haciendo con un puntero copia. Eso nos permite poder dejar como nulos
	los punteros en los bucles while para recorrer toda la lista. En cambio si usaramos el puntero al head
	a partir de la estructura de la lista, y no usamos un puntero copia, estaríamos modificando el head sin siquiera querer
	y perderíamos su referencia. por eso a menos que queramos modificar el valor directamente del campo de la estructura "lista"
	debemos usar un puntero copia del tipo de dato del campo: 
	
	EJ: usar -> printLista(Nodo*head)
		// Podemos avanzar simplemente con head=head->siguiente 
		// sin preocuparnos de perder la referencia a la cabeza de la lista
		


	 no usar -> printfLista(LinkedList*list)
	 //  Si usamos esta forma por lo menos debemos usar un puntero copia : Nodo*aux=list->head
	// porque si iteramos haciendo list->head=list->head->siguiente en vez de aux=aux->siguiente
	// Estamos modificando directamente el campo "head" de la estructura y perderíamos la referencia a la cabeza de la lista	
		
		*/    
    printLista(newlist->head);
    freeAll(newlist);
    free(newlist);
}
