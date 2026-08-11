#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct StructRecord Record;
typedef struct StructInput Input; 
typedef struct StructNodo Nodo;
struct StructRecord{
	char codiceEvento[31];
	char nomeLuogo[31];
	int capienzaMax;
};
struct StructInput {
	char * fileIn;
	char* fileOut;
	int k;
};

struct StructNodo {
	Record record;
	Nodo * next;
};
Input * readInput ( int argn, char * argv[]);
void insertRecord(Nodo ** head, Record record);
void printList(Nodo * head);
void buildList(Input input, Nodo ** head);
void elab(Input input, Nodo * head);
int main (int argn, char * argv[] ){
	Input *  input;
	Nodo * head = NULL;
	input=readInput(argn, argv);
	//printf("%s %s %d \n", input->fileIn, input->fileOut, input->k);
	/*
	Record record;
	strcpy(record.codiceEvento,"zzz");
	strcpy(record.nomeLuogo,"bbb");
	record.capienzaMax=4;
	insertRecord(&head, record);
	printList(head);
	printf("------------------ \n");
	
	//printf("record n%d: %s %s %d",1, record.codiceEvento, record.nomeLuogo,record.capienzaMax );
	Record record2;
	strcpy(record2.codiceEvento,"aaa");
	strcpy(record2.nomeLuogo,"cc");
	record2.capienzaMax=4;
	insertRecord(&head, record2);
	printList(head);
	printf("------------------ \n");
	//printf("record n%d: %s %s %d",1, record.codiceEvento, record.nomeLuogo,record.capienzaMax );
	Record record3;
	strcpy(record3.codiceEvento,"ccc");
	strcpy(record3.nomeLuogo,"cc");
	record3.capienzaMax=4;
	insertRecord(&head, record3);
	*/
	buildList(*input, &head);
	printList(head);
	elab(*input, head);
	//printList();
	//buildList();
	
}
Input * readInput ( int argn, char * argv[]){
	Input * input= malloc(sizeof(Input));
	if(argn!=4 || !strstr(argv[1], "bin") ||!strstr(argv[2], "txt") ){
		printf("numero input validi, esempio formato: ./provaLab8.c input.bin output.txt 5 \n");
	}
	input->fileIn=malloc(strlen(argv[1])+1);
	input->fileOut=malloc(strlen(argv[2])+1);
	
	
	strcpy(input->fileIn, argv[1]);
	strcpy(input->fileOut, argv[2]);
	
	input->fileIn[strlen(argv[1])]=0;
	input->fileOut[strlen(argv[2])]=0;
	
	input->k=atoi(argv[3]);
	
	return input;
}
void printList(Nodo * head){
	if(!head){
		printf("LISTA VUOTA ERRORE\n");
		return;
	}
	Nodo * nodo = head;
	while(nodo){
		printf(" %s %s %d\n", nodo->record.codiceEvento, nodo->record.nomeLuogo,nodo->record.capienzaMax );
		nodo=nodo->next;
	}
}
void insertRecord(Nodo ** head, Record record){
	
	Nodo * nodo = malloc(sizeof(Nodo));
	strcpy(nodo->record.codiceEvento, record.codiceEvento);
	strcpy(nodo->record.nomeLuogo, record.nomeLuogo);
	nodo->record.capienzaMax=record.capienzaMax;
	
	//caso lista vuota:
	if(!(*head)){
		//printf("weeee");
		(*head)=nodo;
		return;
	}
	//caso push testa
	if(strcmp(record.codiceEvento, (*head)->record.codiceEvento)<0){
		printf("weeeeeeeee");
		nodo->next= (*head);
		(*head)=nodo;
		return;
	}
	
	
	// caso push coda
	Nodo * curr =(*head);
	Nodo * prev =NULL;
	while(curr){
		prev=curr;
		curr= curr->next;
	}
	if(strcmp(record.codiceEvento, prev->record.codiceEvento)>0){
		nodo->next=NULL;
		prev->next=nodo;
		return;
	}
	
	//caso inserimento in mezzo
	curr =(*head);
	prev =NULL;
	while(curr && strcmp(record.codiceEvento, curr->record.codiceEvento)>0){
		prev=curr;
		curr= curr->next;
	}
	nodo->next=curr;
	prev->next=nodo;
}

void buildList(Input input, Nodo ** head){
	FILE * fp = fopen(input.fileIn, "rb");
	if(!fp){
		printf("errore apertura file");
	}
	Record * record= malloc(sizeof(Record));
	while(fread(record,sizeof(Record), 1, fp)){
		insertRecord(head, *record);
	}
	if(ferror(fp)){
		printf("errore lettura file");
		exit(0);
	}
	fclose(fp);
}
void elab(Input input, Nodo * head){
	FILE * fp = fopen(input.fileOut, "w");
	if(!fp){
		printf("errore apertura file");
		exit(0);
	}
	
	Nodo * nodo= head;
	while(nodo){
		

		if(nodo->record.capienzaMax<=input.k){
			printf("aaaaaaaaaaa");
			fprintf(fp, "%s %s %d\n", nodo->record.codiceEvento, nodo->record.nomeLuogo,nodo->record.capienzaMax );
		}
		nodo=nodo->next;
	}
	if(ferror(fp)){
		printf("errore scrittura file");
		exit(0);
	}
	fclose(fp);
}
