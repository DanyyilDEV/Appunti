#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define datiN 10
typedef struct QueueStruct Queue;
typedef struct DatoStruct Dato;
void push (Queue * queue, Dato dato);
Dato *  pop(Queue * queue);
void printQueue( Queue queue);
struct DatoStruct {
	char a [20];
	double b;
};
struct QueueStruct{
	int  head;
	int tail;
	Dato dati[datiN];
};
void push (Queue * queue, Dato dato){
	
	if((queue->tail+1)%datiN==queue->head){
		return;
	}
	queue->dati[queue->tail]=dato;
	queue->tail=(queue->tail+1)%datiN;
	printf("\n nodo={a=%s, b=%lf} \n", queue->dati[queue->tail].a,queue->dati[queue->tail].b);
	
}
Dato * pop(Queue * queue){
	Dato * dato;
	if(queue->head==queue->tail){
		return NULL ;
	}
	dato =&queue->dati[queue->head];
	queue->head=(queue->head+1)%datiN;
	
	return dato;
	
}
void printQueue( Queue  queue){
	int i=queue.head;
	while(i!=queue.tail){
		printf("\n nodo={a=%s, b=%lf} \n", queue.dati[i].a,queue.dati[i].b);
		i=(i+1)%datiN;
	}
}
int main (){
	Queue queue;
	queue.head=0;
	queue.tail=0;
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

