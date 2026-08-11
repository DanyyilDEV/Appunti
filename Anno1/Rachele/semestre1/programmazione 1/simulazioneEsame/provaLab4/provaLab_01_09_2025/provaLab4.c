#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
typedef struct ParameterStruct Parameter;
typedef struct DataStruct Data;
struct ParameterStruct{
	char codice [31];
	char nome[31];
	char cognome[31];
	unsigned eta;
	
	
};
struct DataStruct{
	char * fileIn;
	char * fileOut;
};
void readInput( int argc, char * argv[], Data * data);
void buildArray (Data data, Parameter * parameters);
void printRecord(Parameter * parameters);
void inizializza (Parameter * parameters);
void insertionSort(Parameter * parameters);
void insertionSort(Parameter * parameters);
void recordCpy(Parameter * dest, Parameter src);
void elab (Parameter * parameters, Data data);
int main ( int argc, char * argv[]){
	
	Data data;
	readInput(argc, argv, &data);
	Parameter * parameters=malloc(sizeof(Parameter)*20);
	buildArray(data,parameters);
	printRecord(parameters);
	insertionSort(parameters);
	printf("After sort \n");
	printRecord(parameters);
	insertionSort(parameters);
	elab (parameters, data);
	
}
void readInput( int argc, char * argv[], Data * data){
	if(argc!=3){
		printf("pecificare file input.bin output.txt");
		return;
	}
	data->fileIn=malloc(sizeof(argv[1]));
	data->fileOut=malloc(sizeof(argv[2]));
	strcpy(data->fileIn, argv[1]);
	strcpy(data->fileOut, argv[2]);
	
	printf("in: %s, out:%s", data->fileIn, data->fileOut);
}
void inizializza (Parameter * parameters){
	for(int i=0; i<N; i++){
		parameters[i].eta=0;
	}
}


void buildArray (Data data, Parameter * parameters){
	FILE * fp= fopen(data.fileIn, "rb");
	if(!fp){
		perror("errore in apertura file");
	}
	int i=0;
	while(fread(&parameters[i],sizeof(Parameter), 1,fp)){
		i++;
	}
}

void printRecord(Parameter * parameters){
	int i=0;
	while(parameters[i].eta!=0){
		printf("parameter[%d]:{codice: %s, nome: %s, cognome:%s, eta: %u}\n", i,parameters[i].codice, parameters[i].nome, parameters[i].cognome, parameters[i].eta);
		i++;
	}
}
void recordCpy(Parameter * dest, Parameter src){
	strcpy(dest->nome,src.nome);
	strcpy(dest->cognome,src.cognome);
	strcpy(dest->codice,src.codice);
	dest->eta=src.eta;
	
}
void insertionSort(Parameter * parameters){
	Parameter key;
	for(int i=0; i<N; i++){
		if(parameters[i].eta==0){
			continue;
		}
		recordCpy(&key,parameters[i]);
		int j;
		for(j=i-1; j>=0; j--){
			if(strcmp(key.cognome, parameters[j].cognome)<0){
				recordCpy(&parameters[j+1], parameters[j]);
			}else {
				break;
			}
		}
		recordCpy(&parameters[j+1], key);
	}
}
void elab (Parameter * parameters, Data data){
	
	FILE * fp= fopen(data.fileOut, "w");
	if(!fp){
		perror("errore in apertura");
	}
	
	for(int i=0; i<N; i++){
		//printf("parameters[i].codice[0]: %c", parameters[i].codice[0]);
		if(parameters[i].eta==0||(parameters[i].codice[0] != 'X' && parameters[i].codice[0]!='Z')){
			printf("-parameters[i].codice[0]: %c \n", parameters[i].codice[0]);
			continue;
		}
		
		fprintf(fp, "%s   %s   %s   %d \n", parameters[i].codice, parameters[i].nome, parameters[i].cognome, parameters[i].eta  );
		printf("jeeee");
	}
	
}



