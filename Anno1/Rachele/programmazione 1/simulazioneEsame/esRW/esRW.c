#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ProvaStruct Prova; 
typedef struct InputDataStruct InputData;
struct ProvaStruct {
	char a[100];
	double b;
};

struct InputDataStruct {
	char * inFile;
	char * outFile;
};
Prova read(InputData inputData);
void write (InputData inputData, Prova prova);
void writeB(InputData inputData, Prova prova);

Prova readB(InputData inputData);
int main (){
	InputData inputDataTxt;
	inputDataTxt.inFile="input.txt";
	inputDataTxt.outFile="output.txt";
	Prova prova;
	prova=read(inputDataTxt);
	write(inputDataTxt,prova);
	
	InputData inputDataBin;
	inputDataBin.inFile="input.bin";
	inputDataBin.outFile="output.bin";
	
	strcpy(prova.a,"ciaoBin");
	prova.b=1.3;
	writeB(inputDataBin, prova);
	prova=readB(inputDataBin);
	printf("lettoBIN-> a:%s b:%lf", prova.a, prova.b);
	
}
Prova  read (InputData inputData){
	FILE * fp = fopen(inputData.inFile, "r");
	if(!fp){
		perror("errore in apertura");
	}
	Prova prova;
	
	fscanf(fp, "a:%99s b:%lf", prova.a, &prova.b);
	printf("letto1-> a:%s b:%lf", prova.a, prova.b);
	fclose(fp);
	return prova;
}
void write (InputData inputData, Prova prova){
	FILE* fp= fopen(inputData.outFile, "w");
	if(!fp){
		perror("errore apertura file");
		exit(0);
	}
	
	printf("letto2-> a:%s b:%lf", prova.a, prova.b);
	fprintf(fp, "write-> a:%s b:%lf", prova.a, prova.b);
}
void writeB(InputData inputData, Prova prova){
	FILE * fp = fopen(inputData.outFile, "wb");
	if(!fp){
		perror("errore in apertura");
		exit(0);
	}
	fwrite(&prova,sizeof(Prova),1, fp );
	
}
Prova readB(InputData inputData){
	FILE * fp = fopen(inputData.inFile,"rb");
	if(!fp){
		perror("errore in apertura");
		exit(0);
	}
	Prova prova; 
	fread(&prova, sizeof(Prova), 1, fp);
	return prova;
}
