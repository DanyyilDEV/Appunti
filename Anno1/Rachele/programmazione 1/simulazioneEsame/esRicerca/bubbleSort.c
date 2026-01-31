#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define N 10
void sort (int v[]);
void swap (int * a, int * b);
void printArray (int  v[]);
void sort (int v[]){
	bool isSwapped;
	for(int i=0; i<N-1; i++){
		isSwapped=false;
		for(int j=0; j<N-1 ;j++){
			if(v[j]>v[j+1]){
				swap(&v[j], &v[j+1]);
				isSwapped=true;
			}
		}
		if(!isSwapped){
			return;
		}
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


