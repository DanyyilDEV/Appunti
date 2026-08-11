#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct StructInput Input;
typedef struct StructNodo Nodo;
struct StructInput{
	double x;
	double y;
	int n;
};
struct StructNodo{
	double d;
	Nodo * next;
};
Input * readInput(int argn, char * argv[]);
unsigned int get_random();
double * getDouble(Input input);
void push(double d, Nodo ** head);
void printPila( Nodo * head);
void buildStack(Input input, Nodo ** head);
double * pop (Nodo ** head);
void buildArray(Input input, Nodo ** head, double ** v);
void elabValue(Input input,  double * v);
int main (int argn, char * argv[]){
	Input * input=readInput(argn, argv);
	printf("x=%fl y=%lf n=%d \n",input->x, input->y, input->n);
	
	//double * d=getDouble( *input);
	//printf("d->%lf\n",*d);
	Nodo * head=NULL;
	/*
	double * d2=getDouble(*input);
	double * d3=getDouble(*input);
	push(*d,&head);
	push(*d2,&head);
	push(*d3,&head);
	*/
	buildStack(*input, &head);
	//printPila(head);
	double * d= malloc(sizeof(double));
	//pop(&head);
	//pop(&head);
	printf("--------------------\n");
	printPila(head);
	double * v;
	buildArray(*input,&head, &v );
	 elabValue( *input,  v);
	//elabValue();
}
unsigned int get_random() {
	static unsigned int m_w = 123456;
	static unsigned int m_z = 789123;
	m_z = 36969 * (m_z & 65535) + (m_z >> 16);
	m_w = 18000 * (m_w & 65535) + (m_w >> 16);
	return (m_z << 16) + m_w;
}
Input * readInput(int argn, char * argv[]){
	if(argn!=4){
		printf("errore input, formato corretto: ./provaLab14 x y n \n");
		exit(0);
	}
	double x, y;
	x=strtod(argv[1], NULL);
	y=strtod(argv[2], NULL);
	int n=atoi(argv[3]);
	
	if(x<100||x>1000||y<100|| y>1000){
		printf("errore input, x e y non sono in range[100-1000] \n");
		exit(0);
	}
	if(y<x){
		printf("errore input, x deve essere <y \n");
		exit(0);
	}
	if((y-x)<300){
		printf("errore input, y-x deve essere > 300 \n");
		exit(0);
	}
	Input * input= malloc(sizeof(Input));
	input->x=x;
	input->y=y;
	input->n=n;
	return input;
}
double * getDouble(Input input){
	double * d= malloc(sizeof(double));
	*d=((double) get_random()/UINT_MAX)*(input.y-input.x+1)+input.x;
	//printf("d->%lf\n",*d);
	return d;
}
void push(double d, Nodo ** head){
	Nodo * nodo = malloc(sizeof(Nodo));
	nodo->d=d;
	//caso pila vuota
	if(!(*head)){
		nodo->next=NULL;
		(*head)=nodo;
		return;
	}
	nodo->next=(*head);
	(*head)=nodo;
}
double * pop (Nodo ** head){
	//caso pila vuota
	if(!(*head)){
		printf("lista vuota");
		return NULL;
	}
	Nodo * temp = malloc(sizeof(Nodo));
	double * d= malloc(sizeof(double));
	temp=(*head);
	(*head)=(*head)->next;
	*d=temp->d;
	//free(temp);
	return d;
	
}
void printPila( Nodo * head){
	if(!head){
		printf("Lista vuota \n");
		return;
	}
	Nodo * nodo= head;
	while(nodo){
		printf("%lf \n", nodo->d);
		nodo=nodo->next;
	}
}
void buildStack(Input input, Nodo ** head){
	double * d;
	for(int i=0; i<input.n; i++){
		d=getDouble(input);
		push(*d, head);
	}
	printPila(*head);
	
}
void buildArray(Input input, Nodo ** head, double ** v){
	(*v)= malloc(sizeof(double)*input.n);
	double * d;
	for(int i=0; i<input.n; i++){
		d=pop(head);
		printf("pop(%lf)\n", *d);
		(*v)[i]=*d;
	}
}
void elabValue(Input input,  double * v){
	int somma=0;
	int cont=0;
	for(int i=0; i<input.n; i++){
		somma=somma+v[i];
	}
	double media = somma/input.n;
	for(int i=0; i<input.n; i++){
		if(v[i]>media){
			cont++;
		}
	}
	printf("media: %lf,\n cont elementi maggiori di media: %d \n", media, cont);
}