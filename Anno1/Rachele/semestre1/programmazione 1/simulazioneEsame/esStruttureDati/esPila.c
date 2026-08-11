#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define recordN 20
typedef struct PilaStruct Pila;
typedef struct NodoStruct Nodo;
typedef struct DatoStruct Dato;
void push (Nodo ** head, Dato dato);
void printPila( Nodo * head);
void pop(Nodo ** head);
struct DatoStruct {
	char a [20];
	double b;
};
struct NodoStruct {
	Dato	dato;
	Nodo * next; 
};
void push (Nodo ** head, Dato dato){
	
	Nodo * newNodo=malloc(sizeof(Nodo));
	strcpy(newNodo->dato.a,dato.a);
	newNodo->dato.b=dato.b;
	newNodo->next=(*head);
	(*head)=newNodo;
}
void pop(Nodo ** head){
	if(!(*head)){
		return;
	}
	Nodo * temp=(*head);
	(*head)=temp->next;
	free(temp);
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
	
	Dato dato2;
	strcpy(dato2.a,"Buongiorno");
	dato2.b=4.8;
	push(&head, dato2);
	
	if(!head){
		printf("wtf");
		}
	printf("push: ");
	printPila(head);
	//printf("nodo={a=%s, b=%lf}", (*head).a,(*head).b);
	//printf("p[%d]={a=%s, b=%lf}", pila.top,pila.nodi[pila.top].a,pila.nodi[pila.top].b);
	pop(&head);
	
	printf("pop: ");
	printPila(head);
}


