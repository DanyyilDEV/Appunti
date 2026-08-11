#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NRECORD 200
typedef struct StructInput Input;
typedef struct StructRecord Record;

struct StructInput {
    char * fileIn;
    char * fileOut;
};
struct StructRecord {
    char string[20];
    int len;
};
Input * readInput(int argn, char * argv[]);
void buildArray(Input input, Record ** v);
void printArray(Record * v);
void filer(Record **v);
void createSet(Record **v);
void save(Input input, Record * v);
void read(Input input);
int main(int argn, char * argv[]){
    Input * input= readInput(argn, argv);
    printf("in %s out %s\n", input->fileIn, input->fileOut);
    Record * v= malloc(sizeof(Record)*200);
    buildArray(*input, &v);
    //printArray(v);
    filer(&v);
    printf("createSet\n");
    createSet( &v);
    printArray(v);
    save(*input,v);
    printf("read---------------------------------\n");
    read(*input);
    return 0;
}
Input * readInput(int argn, char * argv[]){
    if(argn!=3){
        printf("errore input \n");
        exit(0);
    }
    Input * input= malloc(sizeof(Input));
    input->fileIn=malloc(strlen(argv[1])+1);
    input->fileOut=malloc(strlen(argv[2])+1);
    strcpy(input->fileIn, argv[1]);
    strcpy(input->fileOut, argv[2]);
    return input;
}
void buildArray(Input input, Record ** v){
    FILE * fp = fopen(input.fileIn, "r");
    if(!fp){
        printf("errore apertura file");
        exit(0);
    }

    int i=0;
    char string [20];
    while(fscanf(fp, "%s", string)==1){
        strcpy((*v)[i].string,string);
        //printf("[%d]",i);
        (*v)[i].len=strlen(string);
        //printf("len %d\n",(*v)[i].len);
        i++;
    }
    while(i<NRECORD-1){
        (*v)[i].len=-1;
        i++;
    }
    if(ferror(fp)){
        printf("errore apertura file");
        exit(0);
    }
}
void printArray(Record * v){
    for(int i=0; i<NRECORD; i++){
        if(v[i].len>0){
            printf("%s [len:%d]\n", v[i].string, v[i].len);
        }
    }
}
void filer(Record **v){
    char * punteggiatura=".;:,";
    for(int i=0; i<NRECORD; i++){
        for(int j=0; j<strlen((*v)[i].string);j++){

            for(int k=0; k<strlen(punteggiatura); k++){
                if((*v)[i].string[j]==punteggiatura[k]){
                    (*v)[i].string[j]=0;


                }
            }
        }
    }
}
void createSet(Record **v){

    for(int i=0; i<NRECORD; i++){
        if((*v)[i].len==-1){
                continue;
        }
        for(int j=i+1; j<NRECORD;j++){
            if((*v)[j].len==-1){
                continue;
            }
            if(strcmp((*v)[i].string,(*v)[j].string)==0){
                    (*v)[j].len=-1;
                    //printf("%s [len:%d] vs %s [len:%d]\n", (*v)[i].string, (*v)[i].len, (*v)[j].string, (*v)[j].len);
            }
        }
    }
}
void save(Input input, Record * v){
    FILE * fp = fopen(input.fileOut,"w");
    if(!fp){
        printf("errore in apertura file");
        exit(0);
    }

    for(int i=0; i<NRECORD; i++){
        fwrite(&v[i],sizeof(Record), 1,fp);
    }
    if(feof(fp)){
        printf("errore in scrittura file");
        exit(0);
    }
}
void read(Input input){
    FILE * fp = fopen(input.fileOut,"rb");
    if(!fp){
        printf("errore in apertura file");
        exit(0);
    }
    Record record;
    while(fread(&record,sizeof(Record), 1,fp)==1){
        printf("%s [%d]\n",record.string, record.len);
    }
    if(!feof(fp)){
        printf("errore in scrittura file");
        exit(0);
    }
}

