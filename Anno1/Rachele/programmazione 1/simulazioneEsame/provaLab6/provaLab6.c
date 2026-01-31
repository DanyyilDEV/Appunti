#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct StructNodo Nodo; 
typedef struct StructInput Input; 
typedef struct StructQueue Queue;
struct StructNodo{
	char * string;
	Nodo * next;
};
struct StructQueue{
	Nodo * head;
	Nodo * tail;
};
struct StructInput{
	char * fileIn;
};
void readInput(int argn, char * argv[], Input * input);
void enqueueWord(char * string, Queue * queue);
void printQueue(Queue queue);
Nodo *  dequeueWord(Queue * queue);
void buildQueue(Input input, Queue * queue);
void buildArrayString(Queue * queue, char ** array);
void printArray( char ** array);
void swap(char ** a, char ** b);
void sort(char ** array);
int main (int argn, char * argv[]){
	Input input;
	readInput(argn, argv, &input);
	printf("Input{str:%s}\n", argv[1]);
	Queue queue;
	queue.head=NULL;
	queue.tail=NULL;
	char **array= malloc(sizeof(char *)*100);
	buildQueue(input, &queue);
	//printQueue(queue);
	buildArrayString(&queue, array);
	printf("-----------------------------------------------------\n");
	printArray(array);
	sort(array);
	printf("------------------------------------Sorted array: \n");
	printArray(array);
//	buildArrayString(&queue, array);
//	printf("-----------------------------------------------------\n");
//	buildArrayString(queue, array);
	
//	printf("-----------------------------------------------------\n");

	
}
void readInput(int argn, char * argv[], Input * input){
	if(argn!=2){
		printf("errore numero di input, formato corretto: ./provaLab6,c input.txt \n");
		exit(0);
	}
	input->fileIn=malloc(sizeof(argv[1]));
	strcpy(input->fileIn, argv[1]);
}

void enqueueWord(char * string, Queue * queue){
	if(!string){
		printf("stringa inesistente da aggiungere");
		return;
	}
	Nodo * nodo= malloc(sizeof(Nodo));
	nodo->string=malloc(sizeof(string));
	nodo->next=NULL;
	strcpy(nodo->string, string);
	if(queue->tail){
		queue->tail->next=nodo;	
	}else{
		queue->head =nodo;
		queue->tail =nodo;
	}
	queue->tail=nodo;
}
Nodo * dequeueWord( Queue * queue){
	if(!queue->head){
		printf("coda vuota");
		return NULL;
	}
	Nodo * temp= malloc(sizeof(Nodo));
	
	temp=queue->head;
	queue->head=queue->head->next;
	
	return temp;
}
void printQueue(Queue queue){
	Nodo * nodo= queue.head;
	while(nodo){
		printf("%s \n ", nodo->string);
		nodo= nodo->next;
	}
}
void buildQueue(Input input, Queue * queue){
	FILE * fp =fopen(input.fileIn, "r");
	if(!fp){
		printf("errore in apertura file\n");
	}
	char string[31];
	while(fscanf(fp, "%s", string)==1){
		enqueueWord(string, queue);
	}
	if(ferror(fp)){
		printf("errore in lettura\n");
		exit(0);
	}
}
void printArray( char ** array){
	for(int i=0; i<100; i++){
		if(!array[i]){
			continue;
		}
		printf("[%d]=%s\n",i,array[i]);
	}
}
void sort(char ** array){
	bool isSwapped;
	for(int i=0; i<100; i++){
		isSwapped=false;
		for(int j=0; j<99-i; j++){
			if(!array[j+1]){
				break;
			}
			if(strcmp(array[j],array[j+1])>0){
				swap(&array[j],&array[j+1]);
				isSwapped=true;
			}
		}
		if(!isSwapped){
			return;
		}
	}
}
void swap(char ** a, char ** b){
	char *temp = *a;
	*a = *b;         
	*b = temp;    
}

void buildArrayString(Queue * queue, char ** array){
	if(!queue->head){
		printf("errore lista vuota\n");
	}
	int i =0;
	while(queue->head){
		Nodo * nodo=dequeueWord(queue);
		printf("%s\n", nodo->string );
		array[i]=malloc(sizeof(char )*31);
		strcpy(array[i], nodo->string);
		i++;
	}
}
