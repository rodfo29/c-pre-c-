#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int value;
    struct Node*next; // Pointer to the next Node.
}Node;



typedef struct LinkedList
{
        Node*head;
}LinkedList;


// Estamos devolviendo un puntero de tipo Nodo.
Node*createNode(int value){
    Node*newNode=(Node*)calloc(1,sizeof(Node));
    newNode->value=value;
    newNode->next=NULL;
    return newNode;

}

Node*addToFront(Node*head,int value){
    Node*newNode=createNode(value);
    if (head==NULL){
      return newNode;
    }
    newNode->next=head;
    return newNode;
}


Node*addToEnd(Node*head,int value){
    Node*newNode=createNode(value);
    if (head==NULL){
        return newNode;
    }
    Node*OriginalHead=head;
    while (head->next!=NULL)
    {
        head=head->next;
    }
    head->next=newNode;
    return OriginalHead;
}

void freeAllList(Node*head){
    if (head==NULL){
        printf("\nLista vacia.....\n");
        return;
    }
    Node*aux=NULL;
    while (head!=NULL)
    {
        aux=head;
        head=head->next;
        printf("\nLiberando: %d, addres=%p",aux->value,aux);
        free(aux);   
    }
    printf("\n");
}


void printList(Node*head){
    if (head==NULL){
        printf("\nLista vacia..\n");
        return;
    }
    while (head!=NULL)
    {
        printf("%d ",head->value);
        head=head->next;
    }
    printf("\n");

    


}

    



    






int main(){
    Node*head=NULL;
    head=addToEnd(head,4);
    head=addToEnd(head,5);
    head=addToEnd(head,6);

    head=addToFront(head,3);
    head=addToFront(head,2);
    head=addToFront(head,1);
    printList(head);
    freeAllList(head);

}