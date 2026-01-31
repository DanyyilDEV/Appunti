#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define K 300

typedef struct{
	double x;
	double y;
	int n;
}Input;
typedef struct{
	double *v;
	int top;
}Pila;
double getDouble (double min, double max);
double pop (Pila* pila);
bool push (Pila* pila, double d, int n);
void buildStack ( Input in, Pila* pila);
void buildArray (Input in, Pila* pila, double* );
void elabValues(double* v, int n );
Input readInput(int n, char *v[]);


int main(int argc, char  *argv[]){
	srand(time(0));
	Input in=readInput(argc,  argv);
	Pila pila;
	double v[in.n];
	buildStack(in, &pila);	
	buildArray (in, &pila, v);
	elabValues(v, in.n);
	free(pila.v);
	pila.v=NULL;
}

double getDouble (double min, double max){
	
	double d;
	d=( (double) rand()/(RAND_MAX))*(max-min)+min;
	printf("d=%lf \n", d);
	return d;
}
double pop (Pila* pila){
	double d;
	if(pila->top==-1){
		return 0;
	}
	d=pila->v[pila->top];
	pila->v[pila->top]=0;
	pila->top--;
	return d;
}
bool push (Pila* pila, double d, int n){
	if(pila->top==n-1){
		return false;
	}
	pila->v[++pila->top]=d;
	return true;
}
void buildStack ( Input in, Pila* pila){
	double d;
	pila->top=-1;
	pila->v= malloc((sizeof(double))*in.n);
	for(unsigned i=0; i<in.n; i++){
		d=getDouble(in.x, in.y);
		push(pila, d, in.n);
		printf("pila[%u]=%lf  \n ",i,pila->v[i]);
	}
}
void buildArray (Input in, Pila* pila, double* v){
	
	double d=0;
	
	for(unsigned i=0; i<in.n; i++){
		d=pop(pila);
		v[i]=d;
		printf("v[%u]=%lf  \n ",i,v[i]);
	}
}

void elabValues(double *v, int n ){
	double somma=0;
	int cont=0;
	for(unsigned i=0; i<n; i++){
		somma+=v[i];
	}
	double media= (double) somma/n;
	printf("media=%lf   \n", media);
	for(unsigned i=0; i<n; i++){
		if(v[i]>media){
			cont++;
		}
	}
	printf("cont elementi > media =%d  \n",cont );
}

Input readInput(int n, char *v[]){
	Input in;
	if(n!=4){
		printf("errore; avresti dovuto inserire solo 3 valori es: ./nomeProgamma lf lf d \n");
		exit(0);
	}
	
	in.x=atof(v[1]);
	in.y=atof(v[2]);
	in.n=atof(v[3]);
	if(in.x<100||in.x>1000){
		printf("x fuori range (100-1000) \n");
		exit(0);
	}
	if(in.y<100||in.y>1000){
		printf("y fuori range (100-1000) \n");
		exit(0);
	}
	if(in.y<in.x){
		printf("y deve essere maggiore di x \n");
		exit(0);
	}
	if(in.y-in.x<300){
		printf("y-x  deve essere >300 \n");
		exit(0);
	}
	if(in.n<15||in.n>30){
		printf("n fuori range (15-30)\n");
		exit(0);
	}
	
	return in;
}
