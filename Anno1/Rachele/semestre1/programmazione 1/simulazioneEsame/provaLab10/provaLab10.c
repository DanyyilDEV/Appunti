#include <stdio.h>
#include<stdlib.h>
char * readInput(int argn, char * argv[]);
void readDimMatrix(char * fileName, int * r, int * c);
void allocaMatrix(double **** matrix, int  r, int c);
void printMatrix(double *** matrix, int  r, int c);
void fillMatrix(char * fileIn, double **** matrix);
void normalize(double **** matrix, double **** matrixN, int  r, int c);
void sortCols(double **** matrix, int  r, int c);
int main(int argn, char * argv[]){
	
	char * fileIn=readInput(argn, argv);
	int m,n;
	readDimMatrix(fileIn, &n,  &m);
	printf("%d %d\n", n, m);
	double *** matrix;
	allocaMatrix(&matrix, n, m);
	//printMatrix(matrix, n, m);
	fillMatrix(fileIn, &matrix);
	printf("_______________ORIGINAL_________________ \n");
	printMatrix(matrix, n, m);
	double *** w;
	allocaMatrix(&w, n, m);
	normalize(&matrix,&w, n, m);
	printf("_______________NORMALIZE_________________ \n");
	printMatrix(w, n, m);
	printf("_______________SORTED_________________ \n");
	sortCols(&w, n, m);
	printMatrix(w, n, m);
}
char * readInput(int argn, char * argv[]){
	if(argn!=2){
		printf("input errato formato corretto: ./provaLab10 input.txt");
		exit(0);
	}
	return argv[1];
}
void readDimMatrix(char * fileName, int * r, int * c){
	FILE * fp= fopen(fileName, "r");
	if(!fp){
		printf("errore apertura file");
	}
	if(ferror(fp)){
		printf("errore in lettura riga e colonna");
		exit(0);
	}
	fscanf(fp, "%d %d", r, c);
	fclose(fp);
}
void allocaMatrix(double **** matrix, int  r, int c){
	(*matrix)=malloc(sizeof(double**)*r);
	for(int i=0; i<r; i++){
		(*matrix)[i]=malloc(sizeof(double*)*c);
		for(int j=0; j<c; j++){
			(*matrix)[i][j]=malloc(sizeof(double));
			*(*matrix)[i][j]=1.5;
		}
	}
}
void printMatrix(double *** matrix, int  r, int c){
	
	for(int i=0; i<r; i++){
		
		for(int j=0; j<c; j++){
			
			printf("%lf  ",*matrix[i][j]);
		}
		printf("\n");
	}
}
void fillMatrix(char * fileIn, double **** matrix){
	FILE * fp= fopen(fileIn, "r");
	if(!fp){
		printf("errore apertura file");
		exit(0);
	}
	int r;
	int c;
	fscanf(fp, "%d %d", &r, &c);
	//printf("%d %d\n", r, c);
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			fscanf(fp,"%lf  ",(*matrix)[i][j]);
		}
	}
	fclose(fp);
}
void normalize(double **** matrix, double **** matrixN, int  r, int c){
	double MaxCol;
	for(int i=0; i<c; i++){
		MaxCol=*(*matrix)[0][i];
		for(int j=0; j<r; j++){
			if(MaxCol<*(*matrix)[j][i]){
				MaxCol=*(*matrix)[j][i];
				
			}			
		}
		//printf("maxCol(%d)=%lf\n",i,MaxCol);
		for(int j=0; j<r; j++){
			*(*matrixN)[j][i]=(*(*matrix)[j][i])/MaxCol;			
		}
		
	}
}
void sortCols(double **** matrix, int  r, int c){
	
	for(int i=0; i<c; i++){
		for(int j=0; j<r; j++){
			int k;
			double key=*(*matrix)[j][i];
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
