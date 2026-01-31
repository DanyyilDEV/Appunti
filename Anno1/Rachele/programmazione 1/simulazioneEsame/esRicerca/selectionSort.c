#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
void sort (int v[]);
void swap (int * a, int * b);
void printArray (int  v[]);
void sort (int v[]){
	int posMin;
	for(int i=0; i<N; i++){
		posMin=i;
		for(int j=i+1; j<N; j++){
			if(v[j]<v[posMin]){
				posMin=j;
			}
		}
		swap(&v[i], &v[posMin]);
	}
}
void swap (int * a, int * b){
	int temp;
	temp= *a;
	*a=*b;
	*b=temp;
}
void printArray (int  v[]){
	for(int i=0; i<N; i++){
		printf("v[%d]=%d\n", i, v[i]);
	}
}

int main (){
	
	int v[N]={4,7,4,2,1,-1,6,3,5,-2};
	printArray(v);
	sort(v);
	printf("ordinatoooo\n");
	printArray(v);
}


