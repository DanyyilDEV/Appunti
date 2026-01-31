#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct StructInput Input;
typedef struct StructNodo Nodo;
struct StructInput {
	char * fileIn;
	int k;
};

struct StructNodo{
	char string[31];
	Nodo * next;
};
void readInput(char * argv[], int argn, Input * input);
void pushWord(char * string, Nodo ** head);
void printStack(Nodo ** head, Input input);
void buildStack(Nodo ** head, Input input);
char * sortWord(char * string);
void swap(char * a, char * b);
void popWord(Nodo ** head);
int main (int argn,char * argv[] ){
	Input input;
	readInput(argv,argn, &input);
	printf("Inpunt{fileIn: %s, k: %d}\n", input.fileIn, input.k);
	Nodo * head=NULL;
	buildStack(&head, input);
	printStack(&head, input);
	printf("------ \n");
	printStack(&head, input);
	
	
}

void readInput(char * argv[], int argn, Input * input){
	if(argn!=3){
		printf("numero di input errati formato corretto: /nomeprogramma inputFile.txt k");
	}
	input->k= atoi(argv[2]);
	if(input->k<5 || input->k>15){
		printf("k non e' nel range[5-15] \n");
		exit(0);
	}
	input->fileIn=malloc(sizeof(argv[1]));
	strcpy(input->fileIn, argv[1]);
	
}
void pushWord(char * string, Nodo ** head){
	Nodo * nodo=malloc(sizeof(Nodo));
	strcpy(nodo->string,string);
	nodo->next=*head;
	*head=nodo;
	//printf("|%p|->string %s \n", *head, nodo->string);
	
	
}
void popWord(Nodo ** head){
	if(!(*head)){
		return;
	}
	Nodo * temp= *head;
	*head =(*head)->next;
	free(temp);
	//printf("|%p|->string %s \n", *head, nodo->string);
}

void buildStack(Nodo ** head, Input input){
	FILE * fp= fopen(input.fileIn, "r");
	if(!fp){
		perror("errore apertura");
		exit(0);
	}
	char string[31];
	while(fscanf(fp, "%s", string)==1){
		pushWord(string, head);
	}
	if(ferror(fp)){
		printf("errore in lettura file");
		exit(0);
	}
	fclose(fp);
}
char * sortWord(char * string){
	char * sortedWord=malloc(strlen(string)+1);
	strcpy(sortedWord, string);
	for(int i=0; i<strlen(sortedWord); i++){
		for(int j=i+1; j<strlen(sortedWord); j++){
			if(sortedWord[i]>sortedWord[j]){
				swap(&(sortedWord[i]),&(sortedWord[j]));
			}
		}
	}
	return sortedWord;
}

void swap(char * a, char * b){
	char temp[1];
	*temp=*a;
	*a=*b;
	*b=*temp;
}
void printStack(Nodo ** head, Input input){
	
	Nodo ** nodo= head;
	if(!(*nodo)){
		printf("lista vuotaaa");
		return;
	}
	while((*nodo)){
		if(strlen((*nodo)->string)>= input.k){
			printf("%s \n", sortWord( (*nodo)->string));
		}else{
			printf("%s \n", (*nodo)->string);
		}		
		popWord(head);		
	}
} 