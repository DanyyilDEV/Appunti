#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define recordN 20
typedef struct NodoStruct Nodo;
typedef struct DatoStruct Dato;
void push (Nodo ** head, Dato dato);
void printPila( Nodo * head);
void pop(Nodo ** head, Dato dato);
bool cmpDato (Dato d1, Dato d2);
struct DatoStruct {
	char a [20];
	double b;
};
struct NodoStruct {
	Dato	dato;
	Nodo * next; 
};

//teoricamente nella pila la logica di push e pop la puoi decidere tu, volendo si può fare una lista/coda (vedi esQueue.c) o una lista/pila (vedi esStack.c)
//seguo l'esempio del prof con push ordinato (secondo double in questo caso) e pop che confrota i dati scorrendo ogni dato e facendo un confronto con quello da elminare per trovare la posizione nella pila e quindi eliminarlo
void push (Nodo ** head, Dato dato){
	
	Nodo * newNodo=malloc(sizeof(Nodo));
	strcpy(newNodo->dato.a , dato.a);
	newNodo->dato.b=dato.b;
	Nodo * nodo=(*head);
	Nodo * prev=NULL;
	
	if(!nodo){
		newNodo->next=(*head);
		(*head)=newNodo;
		return;
	}
	
	while(nodo!=NULL){
		if(!prev && dato.b<=nodo->dato.b){
			newNodo->next=(*head);
			(*head)=newNodo;
			return;
		}
		if(dato.b<=nodo->dato.b){
			prev->next=newNodo;
			newNodo->next=nodo;
			return;
		}
		prev=nodo;
		nodo=nodo->next;
	}
	prev->next=newNodo;
	newNodo->next=NULL;
	
}
bool cmpDato (Dato d1, Dato d2){
	if(strcmp(d1.a,d2.a)==0 && d1.b==d2.b){
		return true;
	}
	return false;
}
void pop(Nodo ** head, Dato dato){
	if(!(*head)){
		return;
	}
	Nodo * nodo=(*head);
	Nodo * prev=NULL;
	while(nodo!=NULL){
		if(!prev && cmpDato(nodo->dato, dato)){
			Nodo * temp=(*head);
			(*head)=temp->next;
			free(temp);
			break;
		}
		if(cmpDato(nodo->dato, dato)){
			prev->next=nodo->next;
			free(nodo);
			break;
		}
		prev=nodo;
		nodo=nodo->next;
	}
	
}
void printPila( Nodo * head){
	
	Nodo * nodo=head;
	while(nodo!=NULL){
		printf("\n nodo={a=%s, b=%lf} \n", nodo->dato.a,nodo->dato.b);
		nodo=nodo->next;
	}
}
int main (){
	Nodo * head= NULL;
	Dato dato1;
	strcpy(dato1.a,"ciao");
	dato1.b=2.4;
	push(&head, dato1);
	printf("push1: ");
	printPila(head);
	
	Dato dato2;
	strcpy(dato2.a,"Buongiorno");
	dato2.b=4.8;
	push(&head, dato2);
	
	if(!head){
		printf("wtf");
	}
	printf("push2: ");
	printPila(head);
	
	Dato dato3;
	strcpy(dato3.a,"Buonsera");
	dato3.b=2.8;
	push(&head, dato3);
	printf("push3: ");
	printPila(head);
	
	
	//printf("nodo={a=%s, b=%lf}", (*head).a,(*head).b);
	//printf("p[%d]={a=%s, b=%lf}", pila.top,pila.nodi[pila.top].a,pila.nodi[pila.top].b);
	pop(&head, dato2);
	
	printf("pop: ");
	printPila(head);
	
}

