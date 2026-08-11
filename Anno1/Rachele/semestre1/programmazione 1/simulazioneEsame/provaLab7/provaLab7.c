#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct StructInput Input;
typedef struct StructNodo Nodo;
typedef struct StructCoda Coda;
struct StructInput {
    char * fileIn;
    double d;
};
struct StructNodo{
	char string[31];
	double d;
	Nodo * prev;
	Nodo * next;
};
struct StructCoda{
	Nodo * head;
	Nodo * tail;
};
Input* readInput(int argn, char * argv[]);
void push(Coda * coda, char * string, double d );
void printList(Coda coda);
void buildList(Input input, Coda * coda);
void elab(Input input, Coda  coda);
int main(int argn, char * argv[])
{
	Input * input=malloc(sizeof(Input *));
	input=readInput(argn, argv);
	printf("Input{fileIn: %s, d: %lf}\n", input->fileIn, input->d);
	Coda coda;
	coda.head=NULL;
	coda.tail=NULL;
	buildList(*input, &coda);
	elab(*input, coda);
	printf("----------------------------------------------:\n");
	printList(coda);
	
	
		
/*	
   
    
    */
}
Input  * readInput(int argn, char * argv[]){
    if(argn!=3){
        printf("errore input, formato corretto: ./main.c input.txt 1.5");
    }
    Input * input=malloc(sizeof(Input));
    input->fileIn = malloc(strlen(argv[1])+1);
    strcpy(input->fileIn, argv[1]);
    input->d=atof(argv[2]);
    if( input->d<1.0||input->d>20){
	    printf("fuori range!!! [1.0, 20.0]");
	    exit(0);
	}
    return input;
}
void push(Coda * coda, char * string, double d ){
	Nodo * nodo= malloc(sizeof(Nodo));
	strncpy(nodo->string, string,30);
	nodo->string[30]=0;
	nodo->d=d;
	// caso lista vuota
	if(!coda->head){
		nodo->next=NULL;
		nodo->prev=NULL;
		coda->head=nodo;
		coda->tail=nodo;
		return;
	}
	
	//caso push testa
	if(strcmp(nodo->string, coda->head->string)<0){
		nodo->next=coda->head;
		nodo->prev=NULL;
		coda->head->prev=nodo;
		coda->head= nodo;
		return;
	}
	//caso push in coda
	
	if(strcmp(nodo->string, coda->tail->string)>0){
		nodo->next=NULL;
		nodo->prev=coda->tail;
		coda->tail->next=nodo;
		coda->tail= nodo;
		return;
	}
	//push in mezzo
	
	Nodo * curr= coda->head->next;
	while(curr && strcmp(string, curr->string)>0){
		curr=curr->next;
	}
	
	nodo->next=curr;
	nodo->prev=curr->prev;
	curr->prev->next=nodo;
	curr->prev=nodo;	
	
}
void printList(Coda coda){
	if(!coda.head){
		printf("lista vuota ERRORE\n");
		return;
	}
	Nodo * nodo= coda.head;
	while(nodo){
		printf("%s - %lf \n", nodo->string, nodo->d);
		nodo=nodo->next;
	}
}
void elab(Input input, Coda coda){
	if(!coda.head){
		printf("lista vuota ERRORE\n");
		return;
	}
	Nodo * nodo= coda.head;
	int cont=0;
	while(nodo){
		if(nodo->d>=input.d){
			cont++;
		}		
		nodo=nodo->next;
	}
	printf("Numero di record aventi lunghezza pari o maggiore di %lf : %d\n", input.d, cont);
}
void buildList(Input input, Coda * coda){
	FILE * fp = fopen(input.fileIn, "r");
	char string[31];
	double d;
	if(!fp){
		printf("errore in lettura");
		return;
	}
	
	while(fscanf(fp, " %lf %30s ", &d, string)==2){
		push(coda, string, d);
	}
	if(ferror(fp)){
		printf("errore in fase di lettura");
		return;
	}
}
