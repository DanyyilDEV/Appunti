#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200
typedef struct StructInput Input;
typedef struct StructRecord Record;
struct StructInput {
	char * fileIn;
	int k;
};
struct StructRecord{
	char key[20];
	int length;
};
Input * readInput(int argn, char * argv []);
void inizializzaArray(Record record []);
void buildArray(Input input, Record  record  []);
void printArray(Record * record , int k);
void filter(Record * record );
void createSet(Record * record );
int main (int argn, char  *argv[]){
	Input * input;
	input=readInput( argn, argv);
	printf("%s %d\n", input->fileIn, input->k);
	Record record[N];
	buildArray(*input, record);
	filter(record);
	createSet(record);
	printArray(record,input->k);
	
	
}

Input * readInput(int argn, char * argv []){
	if(argn!=3){
		printf("errore input, formato corretto: ./provaLab11 input.txt d");
		exit(0);
	}
	Input * input= malloc(sizeof(Input));
	input->fileIn=malloc(strlen(argv[1])+1);
	strcpy(input->fileIn, argv[1]);
	input->fileIn[strlen(argv[1])]=0;
	input->k=atoi(argv[2]);
	return input;
}
void inizializzaArray(Record * record ){
	for(int i=0; i<N; i++){
		record[i].length=-1;
		//printf("X %d\n", record[i].length);
	}
}
void buildArray(Input input, Record * record){
	inizializzaArray(record);
	FILE * fp= fopen(input.fileIn, "r");
	if(!fp){
		printf("errore apertura file");
		exit(0);
	}
	
	int i=0;
	while(fscanf(fp, "%s", record[i].key)==1 &&  i<N){
		record[i].length=strlen(record[i].key);
		i++;
	}
	if(ferror(fp)){
		printf("errore lettura file");
		exit(0);
	}
	fclose(fp);
}
void printArray(Record * record, int k ){
	for(int i=0; i<N; i++){
		if(record[i].length==-1 ||record[i].length<k){
			continue;
		}
		printf("%s    (%d) \n",record[i].key, record[i].length);
	}
}
void filter(Record * record ){
	int m=4;
	char  v[]={',',';',':','.'};
	
	int lastChar;
	for(int i=0; i<N; i++){
		for(int j=0; j<m; j++){
			if(record[i].length==-1){
				return;
			}
			lastChar=record[i].length-1;
			if(record[i].key[lastChar]==v[j]){
				record[i].key[lastChar]=0;
				record[i].length--;
			}
		}
		
	}
}
void createSet(Record * record ){
	
	for(int i=0; i<N; i++){
		for(int j=i; j<N; j++){
			if(record[i].length==-1 || record[j].length==-1|| i==j ){
				continue;
			}
			
			if(strcmp(record[i].key, record[j].key)==0){
				record[j].length=-1;
				//printf("%s    (%d) \n",record[j].key, record[j].length);
			}
			
		}
		
	}
}
 