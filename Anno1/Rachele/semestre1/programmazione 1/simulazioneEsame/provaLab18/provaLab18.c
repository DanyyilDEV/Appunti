#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct StructInput  Input;
struct StructInput {
	char * fileIn;
	char * fileOut;
	unsigned int n;
	unsigned int m;
};
Input * readInput(int argn, char * argv[]);
void allocMatrix(int r, int c, double **** matrix);
void printMatrix(int r ,int c, double *** matrix);
void readMatrix(Input input, double **** matrix);
void trasposeMatrix(Input input, double *** matrix, double **** matrixT);
void sortColMatrix(int r, int c, double **** matrix);
void writeMatrix(Input input, double *** matrix);
int main (int argn, char * argv[]){
	Input * input=readInput(argn,argv);
	printf("in; %s out:%s n:%u m%u\n", input->fileIn, input->fileOut, input->n, input->m);
	double *** matrix;
	allocMatrix(input->n, input->m,&matrix);
	//printMatrix(*input, matrix);
	readMatrix(*input, &matrix);
	printMatrix(input->n, input->m, matrix);
	double *** matrixT;
	allocMatrix(input->m, input->n, &matrixT);
	trasposeMatrix(*input,matrix, &matrixT);
	printf("\nTraspose\n");
	printMatrix(input->m, input->n, matrixT);
	printf("\nTraspose & sort\n");
	sortColMatrix(input->m, input->n, &matrixT);
	printMatrix(input->m, input->n, matrixT);
	writeMatrix(*input, matrixT);
	
	
}
Input * readInput(int argn, char * argv[]){
	if(argn!=5){
		printf("errore input (fileIn fileOut n m)\n");
		exit(0);
	}
	Input * input = malloc(sizeof(Input));
	input->fileIn=malloc(sizeof(argv[1]));
	input->fileOut=malloc(sizeof(argv[2]));
	strcpy(input->fileIn, argv[1]);
	strcpy(input->fileOut, argv[2]);
	input->n=atoi(argv[3]);
	input->m=atoi(argv[4]);
	return input;
}
void allocMatrix(int r, int c, double **** matrix){
	(*matrix)= malloc(sizeof(double**)*r);
	for(int i=0; i<r; i++){
		(*matrix)[i]= malloc(sizeof(double*)*c);
		for(int j=0; j<c; j++){
			(*matrix)[i][j]=malloc(sizeof(double));
		}
	}
	
}
void printMatrix(int r, int c, double *** matrix){
	
	for(int i=0; i<r;i++){
		for(int j=0; j<c; j++){
			//*matrix[i][j]=0;
			printf("[%lf] ", (*matrix[i][j]));
		}
		
			printf("\n") ;
	}
}
void readMatrix(Input input, double **** matrix){
	FILE * fp = fopen(input.fileIn, "r");
	if(!fp){
		printf("errore apertura file\n");
		exit(0);
	}
	for(int i=0; i<input.n;i++){
		for(int j=0; j<input.m; j++){
			fscanf(fp, "%lf", (*matrix)[i][j]);
		}
	}
	if(ferror(fp)){
		printf("errore lettura file\n");
		exit(0);
	}
	fclose(fp);
	
}
void trasposeMatrix(Input input, double *** matrix, double **** matrixT){
	for(int i=0; i<input.n;i++){
		for(int j=0; j<input.m; j++){
			*(*matrixT)[j][i]=*matrix[i][j];
		}
	}
	
}
void sortColMatrix(int r, int c, double **** matrix){
	for(int i=0; i<c;i++){
		for(int j=0; j<r; j++){
			int k;
			double key= *(*matrix)[j][i];
			for(k=j-1; k>=0; k--){
				if(key<*(*matrix)[k][i]){
					*(*matrix)[k+1][i]=*(*matrix)[k][i];
				}else{
					break;
				}
			}
			*(*matrix)[k+1][i]=key;
		}
	}
}
void writeMatrix(Input input, double *** matrix){
	FILE * fp = fopen(input.fileOut, "w");
	if(!fp){
		printf("errore apertura file\n");
		exit(0);
	}
	int r= input.m;
	int c= input.n;
	for(int i=0; i<r;i++){
		for(int j=0; j<c; j++){
			fprintf(fp, "[%lf]", *matrix[i][j]);
		}
		fprintf(fp, " \n");
	}
	if(ferror(fp)){
		printf("errore scrittura file\n");
		exit(0);
	}
	fclose(fp);
	
}