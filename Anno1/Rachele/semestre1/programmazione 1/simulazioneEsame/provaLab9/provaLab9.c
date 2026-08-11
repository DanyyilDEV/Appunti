#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct StructInput Input;
struct StructInput{
	char * fileIn;
	char * fileOut;
	unsigned n;
	unsigned m;
};
Input * readInput(int argn, char * argv[]);
void allocMatrix(int n, int m, double **** matrix);
void readMatrix(Input input, double *** matrix);
void printMatrix(int n, int m, double *** matrix);
double *** trasposeMatrix(int n, int m, double *** matrix);
void sortColMatrix(int r, int c, double **** matrix);
void writeMatrix(Input input, int r ,int c,double *** matrix);
int main (int argn, char * argv[]){
	
	Input * input = malloc(sizeof(Input));
	input=readInput(argn, argv);
	printf("in:%s out:%s, n%u, m:%u \n",input->fileIn,input->fileOut, input->n, input->m );
	double *** matrix;
	allocMatrix(input->n,input->m, &matrix);
	printf("-------------------Matrice:\n");
	readMatrix(*input, matrix);
	printf("-------------------trasposta:\n");
	double *** matrixT=trasposeMatrix(input->n,input->m, matrix);
	printf("-------------------SortCol:\n");
	sortColMatrix(input->m,input->n, &matrixT);
	
	writeMatrix(*input,input->m, input->n, matrixT);
	
}
Input * readInput(int argn, char * argv[]){
	if(argn!=5){
		printf("errore input, formato corretto ./provaLab9 input.txt output.txt n m \n");
		exit(0);
	}
	Input * input = malloc(sizeof(Input));
	input->fileIn=malloc(sizeof(strlen(argv[1])+1));
	input->fileOut=malloc(sizeof(strlen(argv[2])+1));
	strcpy(input->fileIn, argv[1]);
	strcpy(input->fileOut,argv[2]);
	input->fileIn[strlen(argv[1])]=0;
	input->fileOut[strlen(argv[2])]=0;
	input->n=atoi(argv[3]);
	input->m=atoi(argv[4]);
	return input;
	
}
void allocMatrix(int n, int m, double **** matrix){
	(*matrix)= malloc(sizeof(double**)*n);
	for(int i=0; i<n; i++){
		(*matrix)[i]= malloc(sizeof(double*)*m);
		for(int j=0; j<m; j++){
			(*matrix)[i][j]= malloc(sizeof(double));
		}
	}
}
void readMatrix(Input input, double *** matrix){
	FILE * fp= fopen(input.fileIn, "r");
	if(!fp){
		printf("errore apertura file");
		exit(0);
	}
	//double * d= malloc(sizeof(double));
	for(int i=0; i<input.n; i++){
		for(int j=0; j<input.m; j++){
			fscanf(fp, "%lf",matrix[i][j]);
			//printf("%lf   ", *d);
		}
		printf("\n");
	}
	printMatrix(input.n, input.m,matrix);
}
void printMatrix(int n, int m, double *** matrix){
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%lf    ", *matrix[i][j]);
		}
		printf("\n");
	}
	
}
double *** trasposeMatrix(int n, int m, double *** matrix){
	double *** matrixT;
	allocMatrix(m,n,  &matrixT);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			*matrixT[j][i]=*matrix[i][j];
		}
	}
	printMatrix(m,n,matrixT);
	return matrixT;
}
void sortColMatrix(int r, int c, double **** matrix){
	for(int i=0; i<c; i++){
		for(int j=0; j<r; j++){
			int k;
			int val=*(*matrix)[j][i];
			for(k=j-1; k>=0; k--){
				if(val<*(*matrix)[k][i]){
					*(*matrix)[k+1][i]=*(*matrix)[k][i];
				}else{
					break;
				}
			}
			*(*matrix)[k+1][i]=val;
		}
	}
	printMatrix(r,c,*matrix);
	
}
void writeMatrix(Input input,int r, int c, double *** matrix){
	FILE * fp= fopen(input.fileOut, "w");
	if(!fp){
		printf("errore apertura file");
		exit(0);
	}
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			fprintf(fp, "%lf     ",*matrix[i][j]);
			
		}
		fprintf(fp,"\n");
	}
}