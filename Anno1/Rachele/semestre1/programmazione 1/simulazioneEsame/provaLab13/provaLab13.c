#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
typedef struct StructInput Input;
typedef struct StructQueue Queue;
typedef struct StructNodo Nodo;
struct StructInput {
	char * fileIn;
	char * fileOut;
};
struct StructNodo{
	char string[50];
	Nodo * next;
	Nodo * prev;
};
struct StructQueue{
	Nodo * head;
	Nodo * tail;
};
Input * decodeParameters(int argn, char * argv[]);
void push (char * string, Queue * queue);
void printQueue ( Queue  queue);
void readFileToQueue(Input input, Queue * queue);
Nodo * pop (Queue * queue);
void processQueue( Queue * queue);
void sortQueueToArray(Queue * queue, char ***, int dim);
int dimQueue(Queue queue);
void writeToFile(Input input, char ** v, int dim);
int main (int argn, char * argv[]){
	Input * input =decodeParameters(argn, argv);
	printf("FileIn:%s, fileOut:%s\n",input->fileIn, input->fileOut);
	Queue queue;
	readFileToQueue(*input,&queue);
	/*
	printf("-%s\n",pop(&queue));
	printf("-%s\n",pop(&queue));
	printf("-%s\n",pop(&queue));
	printf("-%s\n",pop(&queue));
	printf("-%s\n",pop(&queue));
	*/
	printQueue (queue);
	processQueue(&queue);
	printf("dimQueue=%d", dimQueue(queue));
	printf("-----------------AFTER PROCESS-------------------\n");
	printQueue (queue);
	char ** v;
	int dim=dimQueue(queue);
	sortQueueToArray(&queue, &v, dim);
	writeToFile(*input, v, dim);
}
Input * decodeParameters(int argn, char * argv[]){
	if(argn!=3){
		printf("errore Input, formato corretto: ./provaLab13 input.txt output.txt\n");
		exit(0);
	}
	for(int i=1; i<3; i++){
		char * estensione=strstr(argv[i],".txt");
		int indexEstensione=strlen(argv[i])-4;
		if(!estensione || estensione!=&argv[i][indexEstensione]){
			printf("errore Input, i file DEVONO avere estensione .txt \n");
			exit(0);
		}
	}
	Input * input= malloc(sizeof(Input));
	input->fileIn=malloc(strlen(argv[1])+1);
	input->fileOut=malloc(strlen(argv[2])+1);
	strcpy(input->fileIn,argv[1]);
	strcpy(input->fileOut,argv[2]);
	return input;
}
void readFileToQueue(Input input, Queue * queue){
	FILE * fp = fopen(input.fileIn,"r");
	if(!fp){
		printf("errore in apertura file\n");
		exit(0);
	}
	char string[50];
	while(fscanf(fp,"%s",string )==1){
		push(string, queue);
	}
	if(ferror(fp)){
		printf("errore in lettura file\n");
	}
	fclose(fp);
}
void push (char * string, Queue * queue){
	Nodo * newNodo = malloc(sizeof(Nodo));
	strcpy(newNodo->string, string);
	// caso lista vuota
	if(!(*queue).head){
		newNodo->next=NULL;
		newNodo->prev=NULL;
		(*queue).head=newNodo;
		(*queue).tail=newNodo;
		return;
	}
	newNodo->prev=(*queue).tail;
	newNodo->next=NULL;
	(*queue).tail->next=newNodo;
	(*queue).tail=newNodo;
	
}
Nodo * pop (Queue * queue){
	Nodo * temp = malloc(sizeof(Nodo));
	// caso lista vuota
	if(!(*queue).head){
		return NULL;
	}
	temp=(*queue).head;
	(*queue).head=(*queue).head->next;
	if((*queue).head){
		(*queue).head->prev=NULL;
	}
	
	return temp;
}
void processQueue( Queue * queue){
	if(!queue->head){
		printf("Lista vuota!!!\n");
		return;
	}
	Nodo * nodo=queue->head;
	char *string= malloc(sizeof(char)*50);
	char *stringSwaped= malloc(sizeof(char)*50);
	int dim=dimQueue(*queue);
	for(int i=0; i<dim; i++){
		nodo=pop(queue);
		strcpy(string,nodo->string);
		//printf("\n weee- %s\n", nodo->string);
		//printf("stri->%s, len=", string, );
		if((strlen(string))%2==1){
			int pos=strlen(string)-1;
			
				//printf("\n weee-\n");
			for(int i=0; i<strlen(string); i++ ){
				stringSwaped[pos]=string[i];
				pos--;
				
			}
			stringSwaped[strlen(string)+1]=0;
			push(stringSwaped, queue);
		}else{
			push(string, queue);
		}
		nodo=nodo->next;
		
	}
	free(string);
	string=NULL;
	free(stringSwaped);
	stringSwaped=NULL;
}
void sortQueueToArray(Queue * queue, char *** v, int dim){
	
	Nodo * nodo= malloc(sizeof(Nodo));
	(*v)=malloc(sizeof(char*)*dim);
	for(int i=0; i<dim; i++){
		nodo=pop(queue);
		(*v)[i]=malloc(strlen(nodo->string)+1);
		strcpy((*v)[i], nodo->string);
	}
	
	char  temp[50];
	bool isSwapped;
	for(int i=0; i<dim; i++){
		isSwapped=false;
		for(int j=0; j<dim-1; j++){
			if(strcmp((*v)[j],(*v)[j+1])>0){
				strcpy(temp,(*v)[j]);
				strcpy((*v)[j], (*v)[j+1]);
				strcpy((*v)[j+1], temp);
				isSwapped=true;
			}
		}
		if(!isSwapped){
			break;
		}
	}
	for(int i=0; i<dim; i++){
		printf("v[%d]=%s \n",i, (*v)[i]);
	}
	
}
int dimQueue(Queue queue){
	if(!queue.head){
		printf("Lista vuota!!!\n");
		return -1;
	}
	int cont=0;
	Nodo * nodo=queue.head;
	while(nodo){
		cont++;
		nodo=nodo->next;
	}
	return cont;
}
void printQueue ( Queue  queue){
	if(!queue.head){
		printf("Lista vuota!!!\n");
		return;
	}
	Nodo * nodo=queue.head;
	while(nodo){
		printf("%s (len=%ld)\n", nodo->string, strlen(nodo->string));
		nodo=nodo->next;
	}
	
}
void writeToFile(Input input, char ** v, int dim){
	
	FILE * fp = fopen(input.fileOut,"w");
	if(!fp){
		printf("errore in apertura file\n");
		exit(0);
	}
	for(int i=0; i<dim; i++){
		fprintf(fp,"v[%d]=%s \n",i, v[i]);
	}
	if(ferror(fp)){
		printf("errore in lettura file\n");
	}
	fclose(fp);
}