#include <stdio.h>
#include <stdlib.h>



typedef struct Nodo
{
    int value;
    struct Nodo*next; // Campo que almacenará la direccion de memoria de otro nodo.
}Nodo;


typedef struct Pila
{
    Nodo*top;
    
}Pila;


Nodo*createNode(int num){
    // Los valores que almacenan las direcciones de memoria que acabas de reservar se inicializarán en cero,
    // En vez de tener valores randoms hasta que definamos los campos.
    Nodo*newNode=(Nodo*)calloc(1,sizeof(Nodo));
    newNode->value=num;
    newNode->next=NULL;
    return newNode;
}

int emptyStack(Pila*stack){
    return (stack->top)?1:0; // En caso de que no sea nulo devolverá 1, de lo contrario, devolverá 0.
}

int top(Pila*stack){
    return stack->top->value;
}

void push(Pila*stack,int value){
    Nodo*newNode=createNode(value);
    newNode->next=stack->top;
    stack->top=newNode;
}

int pop(Pila*stack){
    Nodo*oldNode=stack->top;     // Usamos el Puntero (oldNode) para no perder la referencia al tope de la stack al mommento de se mueva al siguiente elemento.
    int top=stack->top->value;
    stack->top=stack->top->next; // Hacemos que el tope avance al siguiente elemento.
    printf("Liberando la memoria del nodo : %d, address: %p\n",oldNode->value,oldNode);
    free(oldNode); // Liberamos la memoria del antiguo nodo
    return top; 
}


void freeStack(Pila*stack){
    if (!stack->top){
        printf("Pila vacia\n");
        return;
    }

    Nodo*aux;
    while(stack->top!=NULL)
    {
        aux=stack->top;
        printf("Liberando la memoria del nodo : %d, address: %p\n",aux->value,aux);
        stack->top=stack->top->next;
        free(aux);
    }
    stack->top=NULL;
}
    
    
Pila createStack(){
    Pila p;
    p.top=NULL;
    return p;
}
void printStack(Pila*stack){
    if (stack->top){
    
        Nodo*aux=stack->top;
        printf("\n\n===== Pila ====\n\n");
        while (aux!=NULL)
        {
            printf("%d\n",aux->value);
            aux=aux->next;
            
        }
    }
        

}    
int main(){
    Pila stack=createStack();
    push(&stack,5);
    push(&stack,4);
    push(&stack,3);
    push(&stack,2);
    push(&stack,1);
    printStack(&stack);


    (emptyStack(&stack))?printf("Tope: %d\n",top(&stack)):printf("Pila vacía....");
    (emptyStack(&stack))?printf("Tope: %d\n",pop(&stack)):printf("Pila vacía....");
    (emptyStack(&stack))?printf("Tope: %d\n",pop(&stack)):printf("Pila vacía....");
    printStack(&stack);

    freeStack(&stack);

}
    

        


    


    










