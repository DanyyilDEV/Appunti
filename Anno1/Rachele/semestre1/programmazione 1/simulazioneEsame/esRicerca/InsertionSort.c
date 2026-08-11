#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
void sort (int v[]);
void printArray (int  v[]);
void sort (int v[]){
	int key;
	for(int i=1; i<N; i++){
		key=v[i];
		int j;
		for( j=i-1; j>=0; j--){
			
			if(key<v[j]){
				v[j+1]=v[j];
				
			}else{
				break;
			}
		}
		v[j+1]=key;
	}
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


