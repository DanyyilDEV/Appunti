#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct StructInput Input;
typedef struct StructNodo Nodo;
typedef struct StructQueue Queue;
struct StructInput{
	char *fileIn;
	char *fileOut;
	int minPriority;
};
struct StructNodo{
	int  id;
	char cliente[50];
	float importo;
	int priority;
	Nodo * next;
};
struct StructQueue{
	Nodo * head;
	Nodo * tail;
};
Input * decodeParameters (int argn, char * argv[]);
void readInputToQueue(Input input, Queue * queue);
void push(int id, char * cliente, float importo, int priority, Queue * queue);
void printQueue(Queue queue);
Nodo * pop(Queue * queue);
void printNodo(Nodo nodo);
void processStatisticsAndSort(Queue queue, Nodo * v);
void insertionSort(Nodo v[], int dim);
void printArray(Nodo v[], int dim);
void filterQueueByPriority( Input input, Queue * queue, int dim);
int dimQueue(Queue queue);
void writeOutput(Input input, Queue queue);
void copyNodo(Nodo * destination, Nodo source);
int main(int argn, char * argv[]){
	Input * input;
	input=decodeParameters(argn, argv);
	printf("Valori in input{in:%s out:%s d:%d}\n", input->fileIn, input->fileOut, input->minPriority);
	Queue queue;
	queue.head=NULL;
	queue.tail=NULL;
	readInputToQueue(*input, &queue);
	printQueue(queue);
	Nodo * v;
	processStatisticsAndSort(queue, v);
	int dim=dimQueue(queue);
	filterQueueByPriority(*input,&queue, dim);
	printf("after process");
	printQueue(queue);
	writeOutput(*input,queue);
	/*
	push(10, "a", 5000.44,5, &queue);
	push(4, "asdfsd", 4444.44,5, &queue);
	push(10, "aasasxcvxcx", 5000.44,5, &queue);
	push(4, "asdfsd", 4444.44,5, &queue);
	push(10, "a", 5000.44,5, &queue);
	push(4, "asdfsd", 4444.44,5, &queue);
	push(10, "aasasxcvxcx", 5000.44,5, &queue);
	push(4, "asdfsd", 4444.44,5, &queue);
	printQueue(queue);
	
	printNodo((*pop(&queue)));
	printNodo((*pop(&queue)));
	printNodo((*pop(&queue)));
	printNodo((*pop(&queue)));
	*/
	
}
Input * decodeParameters (int argn, char * argv[]){
	if(argn!=4){
		printf("errore input (fileIn.txt fileOut.txt minPriority [1-5]) \n");
		exit(0);
	}
	char * estensione1 =strstr(argv[1], ".");
	char * estensione2 =strstr(argv[2], ".");	
	if(strcmp(estensione1, ".txt")!=0 || strcmp(estensione2, ".txt")!=0 ){
		printf("errore estensione file (fileIn.txt fileOut.txt minPriority [1-5]) \n");
		exit(0);
	}
	if(atoi(argv[3])<1 || atoi(argv[3])>5){
		printf("errore  range minPriority  (fileIn.txt fileOut.txt minPriority[1-5]) \n");
		exit(0);
	}
	Input * input= malloc(sizeof(Input));
	input->fileIn= malloc(strlen(argv[1])+1);
	input->fileOut= malloc(strlen(argv[2])+1);
	strcpy(input->fileIn, argv[1]);
	strcpy(input->fileOut, argv[2]);
	input->minPriority= atoi(argv[3]);
	return input;
}
void readInputToQueue(Input input, Queue * queue){
	FILE * fp= fopen(input.fileIn, "r");
	if(!fp){
		printf("errore  apertura file \n");
		exit(0);
	}
	Nodo nodo;
	
	while (fscanf(fp, "%d %s %f %d",&nodo.id,nodo.cliente, &nodo.importo, &nodo.priority )==4){
		push(nodo.id,nodo.cliente, nodo.importo, nodo.priority, queue);
	}
	if(ferror(fp)){
		printf("errore  lettura file \n");
		exit(0);
	}
}
void push(int id, char * cliente, float importo, int priority, Queue * queue){
	Nodo * nodo= malloc(sizeof(Nodo));
	nodo->id=id;
	strcpy(nodo->cliente, cliente);
	//todo limite importo
	nodo->importo=importo;
	nodo->priority=priority;
	nodo->next=NULL;	
	if(!queue->tail){
		queue->tail=nodo;
		queue->head=nodo;
		return;
	}
	
	queue->tail->next=nodo;
	queue->tail=nodo;
}
Nodo * pop(Queue * queue){
	if(!queue->head){
		printf("empty queue");
		return NULL;
	}
	Nodo * temp=queue->head;
	queue->head=queue->head->next;
	return temp;
}
void printQueue(Queue queue){
	printf("----------------------\n");
	Nodo * nodo=queue.head;
	if(!nodo){
		printf("empty queue \n");
		return;
	}
	while(nodo){
		printf("%d %s %f %d\n",nodo->id,nodo->cliente, nodo->importo, nodo->priority );
		nodo=nodo->next;
	}
}
void printNodo(Nodo nodo){
	//printf("dequeue: ");
	printf("%d %s %f %d\n",nodo.id,nodo.cliente, nodo.importo, nodo.priority );
}
void processStatisticsAndSort(Queue queue, Nodo * v){
	Nodo * nodo=queue.head;
	double media=0;
	double somma=0;
	int cont=0;
	if(!nodo){
		printf("empty queue \n");
		return;
	}
	while(nodo){
		cont++;
		somma=somma+nodo->importo;
		nodo=nodo->next;
	}
	media=(double)somma/cont;
	printf("media=%lf \n", media);
	v= malloc(sizeof(Nodo)*cont);
	int i=0;
	nodo=queue.head;
	while(nodo){
		if(nodo->importo>media){
			copyNodo(&v[i],*nodo );
			v[i].next=NULL;
		}
		i++;
		nodo=nodo->next;
	}
	int dim=i;
	insertionSort(v, dim);
	 printArray(v, dim);
}
void insertionSort(Nodo v[], int dim){
	for(int i=0; i<dim; i++){
		int j;
		Nodo nodoKey;
		copyNodo(&nodoKey,v[i]);
		for(j=i-1; j>=0; j--){
			if(v[j].importo<nodoKey.importo){
				copyNodo(&v[j+1],v[j]);
			}else{
				break;
			}
		}
		copyNodo(&v[j+1],nodoKey);
	}
}
void copyNodo(Nodo * destination, Nodo source){
	destination->importo=source.importo;
	strcpy(destination->cliente,source.cliente);
	destination->id=source.id;
	destination->priority=source.priority;
	destination->next=source.next;
}
int dimQueue(Queue queue){
	printf("----------------------\n");
	Nodo * nodo=queue.head;
	if(!nodo){
		printf("empty queue \n");
		return -1;
	}
	int cont=0;
	while(nodo){
		cont++;
		nodo=nodo->next;
	}
	return cont;
}
void filterQueueByPriority( Input input, Queue * queue, int dim){
	for(int i=0; i<dim; i++){
		Nodo * nodo = pop(queue);
		if(nodo->priority>=input.minPriority){
			push(nodo->id,nodo->cliente,nodo->importo, nodo->priority,queue );
		}
	}
}
void printArray(Nodo v[], int dim){
	for(int i=0; i<dim; i++){
		printf("v[%d]=", i);
		printNodo(v[i]);
	}
}
void writeOutput(Input input, Queue queue){
	FILE * fp= fopen(input.fileOut, "w");
	if(!fp){
		printf("errore  apertura file \n");
		exit(0);
	}
	Nodo * nodo=queue.head;
	if(!nodo){
		printf("empty queue \n");
		return ;
	}
	while(nodo){
		fprintf(fp, "%d, %s, %f, %d\n",nodo->id,nodo->cliente, nodo->importo, nodo->priority);
		nodo=nodo->next;
	}
	if(ferror(fp)){
		printf("errore  scrittura file \n");
		exit(0);
	}
}