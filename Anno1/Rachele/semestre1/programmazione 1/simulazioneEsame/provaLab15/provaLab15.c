#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StructInput Input;
typedef struct StructNodo Nodo;
struct StructInput{
	char * fileIn;
	char * fileOut;
	unsigned n;
	unsigned m;
};
struct StructNodo{
	char * string;
	Nodo * next;
};


Input * readInput(int argn, char * argv[]);
void push(char * string, Nodo ** head );
void printRecord(Nodo * nodo);
void printRecords(Nodo * head);
void buildStack(Input input, Nodo ** head );
int  countWords(char * string);
Nodo * pop (Nodo ** head);
int countNodi(Nodo * head);
void clearStack(Input input, int dim, Nodo ** head);
char * elabStrVowels(char * string, char p);
int main (int argn, char * argv[]){
	Input * input=readInput(argn, argv);
	printf("in: %s, out:%s, m:%u, n:%u \n",input->fileIn,input->fileOut,  input->m, input->n);
	Nodo * head=NULL;
	buildStack(*input, &head );
	int dim = countNodi(head );
	clearStack(*input, dim, &head);
	
}
Input * readInput(int argn, char * argv[]){
	if(argn!=5){
		printf("errore numero parametri in input ( fileIn fileOut m n)\n");
		exit(0);
	}
	int m=atoi(argv[3]);
	int n=atoi(argv[4]);
	if(n<0 || m<0){
		printf("errore m/n devono essere > 0\n");
		exit(0);
	}
	if(n>m){
		printf("errore n deve essere < m \n");
		exit(0);
	}
	Input * input= malloc(sizeof(Input));
	input->fileIn=malloc(strlen(argv[1])+1);
	input->fileOut=malloc(strlen(argv[2])+1);
	strcpy(input->fileIn, argv[1]);
	strcpy(input->fileOut, argv[2]);
	input->m=m;
	input->n=n;
	return input;
}
void push(char * string, Nodo ** head ){
	Nodo * nodo= malloc(sizeof(Nodo));
	nodo->string= malloc(strlen(string)+1);
	strcpy(nodo->string, string);
	
	
	if(!(*head)){
		(*head)=nodo;
		return;
	}
	
	nodo->next=(*head);
	(*head)=nodo;
	
}
void printRecord(Nodo * nodo){
	if(!nodo){
		printf("record vuoto\n");
		return;
	}
	printf("------------------------------------------\n");
	printf("#%ld#%d %s \n",strlen(nodo->string)-1, countWords(nodo->string), nodo->string);
	
	printf("------------------------------------------\n");
}
void buildStack(Input input, Nodo ** head ){
	
	FILE * fp = fopen(input.fileIn, "r");
	if(!fp){
		printf("errore apertura file\n");
		exit(0);
	}
	char *  string=NULL;
	size_t len =0;
	while(getline(&string,&len, fp)!=-1){
			//printf("weee");
			int w=countWords(string);
		
			if(input.n<=w && w<=input.m){
				push(string, head);
			}
	}
	if(ferror(fp)){
		printf("errore in lettura");
		exit(0);
	}
	fclose(fp); 
}

void printRecords(Nodo * head){
	if(!head){
		printf("lista vuota\n");
		return;
	}
	Nodo * nodo= head;
	while(nodo){
		printRecord(nodo);
		nodo= nodo->next;
	}
}
int  countWords(char * string){
	int cont=0;
	if(!string){
		printf("errore stringa nulla\n");
		return -1;
	}
	for(int i=0; i<strlen(string); i++){
		if(string[i]==' '){
			cont++;
		}
	}
	cont++;
	return cont;
}
Nodo * pop (Nodo ** head){
	if(!(*head)){
		printf("lista vuota \n");
		return NULL;
	}
	Nodo * temp= (*head);
	(*head)=(*head)->next;
	return temp;
}
int countNodi(Nodo * head){
	if(!head){
		printf("lista vuota\n");
		return 0;
	}
	Nodo * nodo= head;
	int cont=0;
	while(nodo){
		cont++;
		nodo= nodo->next;
	}
	return cont;
}
char * elabStrVowels(char * string, char p){
	char * vocali="aAeEiIoOuU";
	for(int i=0; i<strlen(string); i++){
		for(int j=0; j<strlen(vocali); j++){
			if(string[i]==vocali[j]){
				printf("s[%d]=%c\n", i, string[i]);
				string[i]=p;
				break;
			}
		}
	}
	return string;
}

void clearStack(Input input, int dim, Nodo ** head){
	FILE * fp = fopen(input.fileOut, "w");
	if(!fp){
		printf("errore apertura file\n");
		exit(0);
	}
	if(!head){
		printf("lista vuota\n");
		return;
	}
	Nodo * nodo;
	for(int i=0; i<dim; i++){
		nodo=pop(head);
		printRecord(nodo);
		fprintf(fp, "%s",elabStrVowels( nodo->string, 'X'));
		if(ferror(fp)){
			printf("errore in lettura");
			exit(0);
		}
	}
	fclose(fp);
}