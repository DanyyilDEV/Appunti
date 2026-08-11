#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct StructInput Input;
typedef struct StructRecord Record;
typedef struct StructNodo Nodo;
struct StructInput {
	int n;
	char a;
	char b;
};
struct StructRecord {
	char val;
};
struct StructNodo {
	Record record;
	Nodo * next;
	Nodo * prev;
};
Input * readInput(int argn, char * argv[]);
char genVowel();
unsigned int get_random();
char genConsonant();
void push (char c, Nodo **  head);
void printStack(Nodo *  head);
void fillStack(Input input, Nodo **  head);
int main (int argn, char * argv[]){
	Input * input=readInput(argn, argv);
	printf("n: %d, a:%c, b %c \n", input->n, input->a, input->b );
	//printf("v->%d", genVowel());
	//printf("c->%d", genConsonant());
	Nodo * head=NULL;
	fillStack(*input, &head);
	printStack(head);
	
}
Input * readInput(int argn, char * argv[]){
	if(argn!=4){
		printf("errore input (n[5-10] a b)\n");
		exit(0);
	}
	if(atoi(argv[1])<5 || atoi(argv[1])>10){
		printf("errore range n (n[5-10] a[a-z] b[a-z])\n");
		exit(0);
	}
	if(argv[2][0]<'a' || argv[2][0]>'z'|| argv[3][0]<'a' || argv[3][0]>'z'){
		printf("errore range a/b (n[5-10] a[a-z] b[a-z])=> %d\n",argv[2][0]);
		exit(0);
	}
	Input * input = malloc(sizeof(Input));
	input->n=atoi(argv[1]);
	input->a=argv[2][0];
	input->b=argv[3][0];
	return input;
}
unsigned int get_random() {
	static unsigned int m_w = 123456;
	static unsigned int m_z = 789123;
	m_z = 36969 * (m_z & 65535) + (m_z >> 16);
	m_w = 18000 * (m_w & 65535) + (m_w >> 16);
	return (m_z << 16) + m_w;
}
char genVowel(){
	char * vocali = "aeiou";
	int i= (int) get_random()%5;
	printf("v[%c]",vocali[i]);
	return vocali[i];
}
char genConsonant(){
	char * consonanti = "bcdfghjklmnpqrstvwxyz";
	int i= (int)(get_random()%21);
	printf("c[%c]",consonanti[i]);
	return consonanti[i];
}
void push (char c, Nodo **  head){
	Nodo * nodo=malloc(sizeof(Nodo));
	nodo->record.val=c;
	if(!(*head)){
		nodo->next=NULL;
		nodo->prev=NULL;
		(*head)=nodo;
		return;
	}
	nodo->next=(*head);
	nodo->prev=NULL;
	(*head)->prev=nodo;
	(*head)=nodo;
}
void printStack(Nodo *  head){
	if(!head){
		printf("lista vuota\n");
		return;
	}
	Nodo * nodo= head;
	printf("TOP-->\n");
	while(nodo){
		printf("%c ",nodo->record.val);
		nodo=nodo->next;
	}
	printf("<--BOTTOM");
	printf("\n");
}
void fillStack(Input input, Nodo **  head){
	char x;
	char c;
	for(int i=0; i<input.n; i++){
		x= (char) (get_random()%9)+'1';
		int d=x-'0';
		printf("xd=>%d\n", d);
		if(d>=1 && d<=4){
			for(int j=0; j<d; j++){
				c=genVowel();
				if(c==input.a){
					c='*';
				}
				push(c, head);
			}
		}else{
			for(int j=0; j<d; j++){
				c=genConsonant();
				if(c==input.b){
					c='?';
				}
				push(c, head);
			}
		}
		push(x, head);
	}
	
}