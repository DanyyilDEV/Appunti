#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define NPARAMETRI 4

struct InputData{
	char * inFile;
	char * outFile;
	int k;
	
};
struct Record{
	char id[31];
	char  luogo [31];
	int capienzaMax;
	
};
struct Nodo{
	struct Record record;
	struct Nodo * next;
	
};
void readInput(int argc, const char * argv[], struct InputData  * inData );
void readInput(int argc, const char * argv[], struct InputData  * inData );
void printList ( struct Nodo * nodo );
void insertRecord(struct Record  record, struct Nodo ** head );
void buildList ( struct Nodo ** head , struct InputData inputData);
void elab (struct InputData inputData, struct Nodo * head);
int main (int argc, const char * argv[] ){
	struct InputData inData;
	
	
	readInput(argc, argv, &inData);
	//struct Nodo nodo;
	//struct Record record;

	struct Nodo * head=NULL;
	//strcpy(record.id,"pid");
	//strcpy(record.luogo, "pluogo");
	//record.capienzaMax=3;
	//insertRecord(record,&nodo);
	buildList(&head, inData);
	printList(head);
	elab(inData, head);
	}
	
void readInput(int argc, const char * argv[], struct InputData  * inData ){
	if(argc!=NPARAMETRI){
		printf("errore: vanno inseriti 4 campi provaLabv2 inputFile.bin outputfile.txt k");
		exit(0);
	}
	inData->inFile= malloc(sizeof( argv[1]));
	inData->outFile= malloc(sizeof( argv[2]));
	strcpy(inData->inFile, argv[1]);
	strcpy(inData->outFile, argv[2]);
	inData->k= atoi(argv[3]);
}
void printList ( struct Nodo * head ){
	
	int i=0;
	struct Nodo * nodo =head;
	while(nodo){
		
		printf("l%d: record{id:%s, luogo:%s, capienzaMax:%d}\n", i,nodo->record.id,nodo->record.luogo, nodo->record.capienzaMax);
		nodo= nodo->next;
		i++;
	}
}
/* basic senza ordine

void insertRecord(struct Record  record, struct Nodo ** head ){
	//printf("head t1: %p \n", *head);
	struct Nodo * newFirst= malloc(sizeof(struct Nodo));
	//printf("newFirst: %p \n", newFirst);
	struct Nodo * oldFirst=*head;	
	//printf("oldFirst: %p \n", oldFirst);
	strcpy(newFirst->record.id, record.id);
	strcpy(newFirst->record.luogo, record.luogo);
	newFirst->record.capienzaMax= record.capienzaMax;
	newFirst->next=oldFirst;
	*head=newFirst;
	//printf("head t2: %p \n", *head);
}
*/
struct Nodo * findNodoPrev(const char * id, struct Nodo * head){	
	if(!head){
		return NULL;
		
	}
	struct Nodo * nodo= head;
	struct Nodo * lastNodo= malloc(sizeof(struct Nodo));
	
	while( nodo &&strcmp(id, nodo->record.id)>0){
		lastNodo=nodo;
		nodo=nodo->next;
	}
	return lastNodo;
	
}
void insertRecord(struct Record  record, struct Nodo ** head ){	
	struct Nodo * nodoPrev= findNodoPrev(record.id, *head);
	struct Nodo * newNodo=malloc(sizeof(struct Nodo));	
	strcpy(newNodo->record.id, record.id);
	strcpy(newNodo->record.luogo, record.luogo);
	newNodo->record.capienzaMax= record.capienzaMax;
	if(!nodoPrev){
		*head=newNodo;
		newNodo->next=NULL;
		return;
	}
	newNodo->next=nodoPrev->next;
	nodoPrev->next=newNodo;
	
}
void buildList ( struct Nodo ** head , struct InputData inputData){
	FILE * fp= fopen(inputData.inFile, "rb");
	if(!fp){
		perror("errore apertura file binario");
		exit(0);
	}
	struct Record record;
	while(fread(&record,sizeof(struct Record), 1,fp) == 1 ){
		insertRecord(record, head);
		
	}
	fclose(fp);
}
void elab (struct InputData inputData, struct Nodo * head){
	FILE * fp = fopen(inputData.outFile, "w");
	struct Nodo * nodo= head;
	if(!fp){
		perror("errore apertura file");
	}
	while(nodo){
		if(nodo->record.capienzaMax>=inputData.k)
		fprintf(fp,"%s %s %d \n", nodo->record.id,nodo->record.luogo, nodo->record.capienzaMax);
		nodo= nodo->next;
	}
	fclose(fp);
	
}

