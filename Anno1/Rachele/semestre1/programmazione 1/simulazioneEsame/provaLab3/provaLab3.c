//Rachele Contarino XXXX
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define inputN 3
#define wordN 200
#define charN 20
typedef struct InputDataStruct InputData;
struct InputDataStruct{
	const char * inFile;
	const char * outFile;
};
typedef struct WordStruct Word;
struct WordStruct{
	char * key;
	int length;
};

InputData readInput(int argn, char * argv[]);
void buildArray(Word  word[], InputData inputData);
void printArray(Word[]);
void inizializzaArray(Word words[]);
void filter(Word * words);
void eliminaPunteggiatura(Word * word);
void createSet(Word * words);
void save ( Word * words, InputData inData);
Word * read(InputData inData);
int main (int argn, char * argv[]){
	InputData inputData;
	inputData=readInput(argn, argv);
	Word * words = malloc(sizeof(Word)*wordN);
	printf("\n ________________________ARRAY___________________________________________________________\n");
	
	inizializzaArray(words);
	buildArray(words, inputData);
	filter(words);
	createSet(words);
	printArray(words);
	printf("\n __________________________READ FILE BIN_______________________________________________________\n");
	
	save(words, inputData);
	inizializzaArray(words);
	words=read(inputData);
	printArray(words);
	
	
}

InputData readInput(int argn, char * argv[]){
	
	if(argn!=inputN){
		printf("Errore: input da tastiera errato.... esempio corretto: 'nomeprogramma inputFile.txt outputFile.bin");
		exit(0);
	}
	InputData inputData;
	inputData.inFile=malloc(sizeof(argv[1])+1);
	inputData.outFile=malloc(sizeof(argv[2]));
	strcpy(inputData.inFile,argv[1]);
	strcpy(inputData.outFile,argv[2]);
	return inputData;
}

void inizializzaArray(Word words[]){
	
	for(int i=0; i<wordN ;i++){
		words[i].key=malloc(sizeof(char)*(charN+1));	
		words[i].length=-1;	
	}
}
void buildArray(Word  words[], InputData inputData){
	FILE * fp = fopen(inputData.inFile, "r");
	if(!fp){
		perror("errore in apertura file");
		exit(0);
	}
	int i=0;
	while(i<wordN && fscanf(fp, "%20s", words[i].key) ){
		words[i].length=strlen(words[i].key);
		words[i].key[20]=0;
		i++;
		
	}	
	
}
void printArray(Word words[]){
	int contWord=0;
	for(int i=0; i<wordN; i++){
		if(words[i].length>0){
			
			printf("Word [%d]={key: %s | length: %d} \n",contWord,words[i].key,words[i].length);
			printf("_______________________________________________________________\n");
			contWord++;			
		}
	}
	
}
void filter(Word * words){
	for(int i=0; i<wordN; i++){
		if(words[i].length>0){
	
			eliminaPunteggiatura(&words[i]);
		}
	}
}

void eliminaPunteggiatura(Word * word){
	char  punteggiatura[] ={',', ';', ':', '.',0};
	char * newWord= malloc(sizeof(char)*charN+1);
	bool isPunteggiatura;
	for(int i=0; i<word->length; i++){
		isPunteggiatura=false;		
		for(int j=0; j<strlen(punteggiatura); j++){
			if (word->key[i]==punteggiatura[j]) {
				isPunteggiatura=true;
				break;
			}
		}
		if(isPunteggiatura==true){
			continue;
		}
		newWord[i]=word->key[i];
	}
	newWord[strlen(newWord)+1]=0;
	strcpy(word->key, newWord);
}
void createSet(Word * words){
	for(int i=0; i<wordN; i++){
		for(int j=i+1; j<wordN; j++){
			if(words[i].length>0 && words[j].length>0 && (strcmp(words[i].key, words[j].key)==0)){
				words[j].length=-1;
			}
		}
	}
}
void save ( Word * words, InputData inData){
	FILE * fp= fopen(inData.outFile, "wb");
	if(!fp){
		perror("errore apertura file binario");
		exit(0);
	}
	for(int i=0; i<wordN; i++){
		if(words[i].length>0){
			fwrite(&words[i], sizeof(Word),1, fp);
		}
		
		
	}
	fclose(fp);
}
Word * read(InputData inData){
	FILE * fp= fopen(inData.outFile, "rb");
	if(!fp){
		perror("Errore in apertura file");
		exit(0);
	}
	Word * words = malloc(sizeof(Word)*wordN);
	int i=0;
	while(fread(&words[i], sizeof(Word),1, fp)==1){
		i++;
	}
	fclose(fp);
	return words;
}