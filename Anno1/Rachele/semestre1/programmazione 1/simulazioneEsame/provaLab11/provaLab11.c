#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct StructInput Input;

struct StructInput {
	unsigned a;
	unsigned b;
	double alpha;
	double beta;
};
Input * readInput(int argn, char * argv[]);
double *** allocMatrix(unsigned r, unsigned c);
void printMatrix(unsigned r, unsigned c, double *** m);
void fillMatrix (Input input, double **** m);
unsigned int get_random() ;
void transpose (unsigned r, unsigned c, double *** m, double **** mT);
int main (int argn, char * argv[]){
	Input * input;
	input=readInput(argn, argv);
	printf("%u %u %lf %lf \n", input->a,input->b, input->alpha, input->beta);
	double *** matrix;
	matrix=allocMatrix(input->a,input->b);
	//printMatrix(input->a,input->b, matrix);
	
	fillMatrix(*input, &matrix);
	printMatrix(input->a,input->b, matrix);
	printf("____________________TRANSPOSE_________________________\n");
	double *** matrixT;
	matrixT=allocMatrix(input->b, input->a);
	transpose(input->b, input->a, matrix, &matrixT );
	printMatrix(input->b, input->a, matrixT);
}
unsigned int get_random() {
	static unsigned int m_w = 123456;
	static unsigned int m_z = 789123;
	m_z = 36969 * (m_z & 65535) + (m_z >> 16);
	m_w = 18000 * (m_w & 65535) + (m_w >> 16);
	return (m_z << 16) + m_w;
}
Input * readInput(int argn, char * argv[]){
	if(argn!=5){
		printf("errore input, formato corretto: ./provaLab11 u u lf lf \n");
		exit(0);
	}
	Input * input= malloc(sizeof(Input));
	input->a=atoi(argv[1]);
	input->b=atoi(argv[2]);
	if(input->a<5 || input->a>20 || input->b<5 || input->b>20 ){
		printf("errore input, a e/o b non sono nel range [5-20]\n");
		exit(0);
	}
	input->alpha=strtod(argv[3], NULL);
	if(input->alpha<10 || input->alpha>20 ){
		printf("errore input, alpha non è nel range [10-20] \n");
		exit(0);
	}
	input->beta=strtod(argv[4], NULL);
	if(input->beta<1 || input->beta>5 ){
		printf("errore input,  beta non è nel range [1-5] \n");
		exit(0);
	}
	return input;
}

double *** allocMatrix(unsigned r, unsigned c){
	double *** matrix;
	matrix= malloc(sizeof(double**)*r);
	for(int i=0; i<r; i++){
		matrix[i]=malloc(sizeof(double*)*c);
		for(int j=0; j<c; j++){
			matrix[i][j]=malloc(sizeof(double));
			//*(matrix[i][j])=2.4;
		}
		
	}
	return matrix;
}
void printMatrix(unsigned r, unsigned c, double *** m){
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			printf("%lf   ",(*m[i][j]));
			
		}
		printf("\n");
		
	}
}
void fillMatrix (Input input, double **** m){
	double p=((double) get_random()/(UINT_MAX))*(1);
	printf("P:%lf \n", p);
	double max, min ;
	if(p>0.2){
		printf("P(%lf)>0.2 => matrice valorizzata \n", p);
		min= input.alpha-input.beta;
		max= input.alpha+input.beta;
	}else{
		printf("P(%lf)<0.2 => matrice NULL \n", p);
		min=-1;
	}
	for(int i=0; i<input.a; i++){
		for(int j=0; j<input.b; j++){
			if(min==-1){
				(*m)[i][j]=NULL;
			}else{
				*(*m)[i][j]=((double) get_random()/UINT_MAX)*(max-min);
			}			
		}
		
	}
}
void transpose (unsigned r, unsigned c, double *** m,  double **** mT){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			*(*mT)[i][j]=*(m[j][i]);		
		}
		
	}
}