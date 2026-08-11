#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct StructNodo Nodo;
typedef struct StructQueue Queue;
typedef struct StructInput Input;
struct StructNodo{
	char string[50];
	Nodo * prev;
	Nodo * next;
};
struct StructQueue{
	Nodo * head;
	Nodo * tail;
};
struct StructInput{
	char * fileIn;
	char * fileOut;
};
Input * decodeParameters(int argn, char * argv[]);
void printQueue(Queue queue);
void push(char *String,Queue * queue);
char * pop (Queue * queue);
void readFileToQueue(Input input, Queue  * queue);
int dimQueue(Queue queue);
void processQueue(int dim, Queue * queue);
void sortQueueToArray(int dim ,Queue * queue, char *** v);
void writeToFile(Input input, int dim, char ** v);
int main (int argn, char * argv[]){
	Input * input=decodeParameters(argn, argv);
	printf("fileIn: %s, fileOut: %s\n", input->fileIn, input->fileOut);
	Queue queue;
	queue.head=NULL;
	queue.tail=NULL;
	
	/*
	push("hello", &queue);
	push("world", &queue);
	push("bye", &queue);
	printf("pop->%s\n", pop(&queue));
	printf("pop->%s\n", pop(&queue));
	printf("pop->%s\n", pop(&queue));
	*/
	
	readFileToQueue(*input, &queue);
	printQueue(queue);
	int dim = dimQueue(queue);
	processQueue(dim, &queue);
	printf("-------------After Process-----------------\n");
	printQueue(queue);
	char ** v= malloc(sizeof(char*)*dim);
	sortQueueToArray(dim, &queue, &v);
	writeToFile(*input, dim, v);
	//printf("dim-%d\n",dimQueue(queue));
	//
	
	//writeToFile();
}

Input *  decodeParameters(int argn, char * argv[]){
	if(argn!=3){
		printf("errore input! formato corretto ./provaLab13v2 input.txt output.txt\n");
		exit(0);
	}
	char * sub1=strstr(argv[1],".");
	char * sub2=strstr(argv[2],".");
	if(strcmp(sub1,".txt")!=0 ||strcmp(sub2,".txt")!=0 ){
		printf("errore input! estensione file deve essere txt\n");
		exit(0);
	}
	
	Input * input= malloc(sizeof(Input));
	input->fileIn=malloc(strlen(argv[1])+1);
	input->fileIn[strlen(argv[1])]=0;
	strcpy(input->fileIn, argv[1]);
	
	input->fileOut=malloc(strlen(argv[2])+1);
	input->fileOut[strlen(argv[2])]=0;
	strcpy(input->fileOut, argv[2]);
	return input;
	
}
void push(char * string,Queue * queue){
	Nodo * nodo = malloc(sizeof(Nodo));
	strcpy(nodo->string, string);
	//caso lista vuota
	if(!queue->head){
		queue->head=nodo;
		queue->tail=nodo;
		return;
	}
	nodo->next=NULL;
	nodo->prev=queue->tail;
	queue->tail->next=nodo;
	queue->tail=nodo;
}
char * pop (Queue * queue){
	
	if(!queue->head){
		printf("Lista vuota!");
		return 0;
	}
	Nodo * temp = malloc(sizeof(Nodo));
	char * string = malloc(sizeof(char)*50);
	temp=queue->head;
	queue->head=queue->head->next;
	if(queue->head){
		queue->head->prev=NULL;
	}
	strcpy(string, temp->string);
	return string;
}
void printQueue(Queue queue){
	if(!queue.head){
		printf("coda vuota");
	}
	Nodo * nodo = malloc(sizeof(Nodo));
	nodo = queue.head;
	while(nodo){
		printf("%s\n", nodo->string);
		nodo=nodo->next;
	}
}
void readFileToQueue(Input input, Queue  * queue){
	FILE * fp= fopen(input.fileIn, "r");
	if(!fp){
		printf("errore apertura file");
		exit(0);
	}
	char * string = malloc(sizeof(char)*50);
	while(fscanf(fp, "%s", string)==1){
		push(string, queue);
	}
	if(ferror(fp)){
		printf("errore in lettura");
		exit(0);
	}
}
int dimQueue(Queue queue){
	if(!queue.head){
		return 0;
	}
	Nodo * nodo = malloc(sizeof(Nodo));
	nodo = queue.head;
	int cont=0;
	while(nodo){
		cont++;
		nodo=nodo->next;
	}
	return cont;
}
void processQueue(int dim ,Queue * queue){
	char * string;
	char *	stringSwapped;
	int pos;
	for(int i=0; i<dim; i++){
		string=pop(queue);
		stringSwapped= malloc(strlen(string)+1);
		stringSwapped[strlen(string)]=0;
		
		if(strlen(string)%2!=0){
			pos=strlen(string)-1;
			for(int j=0; j<strlen(string); j++){
				stringSwapped[j]=string[pos];
				pos--;
			}
			push(stringSwapped, queue);
		}else{
			push(string, queue);
		}
	}
}
void sortQueueToArray(int dim ,Queue * queue, char *** v){
	char * string;
	for(int i=0; i<dim; i++){
		string=pop(queue);
		(*v)[i]=malloc(sizeof(char)*50);	
		strcpy((*v)[i],string);
	}
	for(int i=0; i<dim; i++){
		printf("[%d]%s\n",i, (*v)[i]);
	}
	char *  temp= malloc(sizeof(char)*50);
	
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim-1; j++){
			
			if(strcmp((*v)[j],(*v)[j+1])>0){
				strcpy(temp, (*v)[j]);
				strcpy((*v)[j], (*v)[j+1]);
				strcpy((*v)[j+1],temp);
			}
		}
	}
}

void writeToFile(Input input, int dim, char ** v){
	FILE * fp = fopen(input.fileOut,"w");
	if(!fp){
		printf("errore apertura file");
		exit(0);
	}
	for(int i=0; i<dim; i++){
		fprintf(fp,"%s\n",v[i] );	
	}
}