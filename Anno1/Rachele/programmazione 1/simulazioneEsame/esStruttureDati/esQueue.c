#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define recordN 20
typedef struct QueueStruct Queue;
typedef struct NodoStruct Nodo;
typedef struct DatoStruct Dato;
void push (Queue * queue, Dato dato);
void pop(Queue * queue);
void printQueue( Queue queue);
struct DatoStruct {
	char a [20];
	double b;
};
struct NodoStruct {
	Dato	dato;
	Nodo * next; 
};
struct QueueStruct{
	Nodo * head;
	Nodo * tail;
};
void push (Queue * queue, Dato dato){
	
	Nodo * newNodo=malloc(sizeof(Nodo));
	strcpy(newNodo->dato.a,dato.a);
	newNodo->dato.b=dato.b;
	if(!queue->head){
		queue->head=newNodo;
	}else{
		queue->tail->next=newNodo;
	}
	queue->tail=newNodo;
	
}
void pop(Queue * queue){
	
	Nodo * temp = queue->head;
	printf("head-> %p",queue->head);
	printf("next-> %p",(queue->head)->next );
	queue->head= (queue->head)->next;
	free(temp);
	
}
void printQueue( Queue  queue){
	
	Nodo * nodo=queue.head;
	while(nodo!=NULL){
		printf("\n nodo={a=%s, b=%lf} \n", nodo->dato.a,nodo->dato.b);
		nodo=nodo->next;
	}
}
int main (){
	Queue queue;
	queue.head=NULL;
	queue.tail=NULL;
	Dato dato1;
	strcpy(dato1.a,"ciao");
	dato1.b=2.4;
	push(&queue, dato1);
	
	
	
	
	Dato dato2;
	strcpy(dato2.a,"Buongiorno");
	dato2.b=4.8;
	push(&queue, dato2);
	
	
	
	printf("push: ");
	printQueue(queue);
	//printf("nodo={a=%s, b=%lf}", (*head).a,(*head).b);
	//printf("p[%d]={a=%s, b=%lf}", pila.top,pila.nodi[pila.top].a,pila.nodi[pila.top].b);
	pop(&queue);
	
	printf("pop: ");
	printQueue(queue);
}

