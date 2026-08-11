#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct StructInput Input;
typedef struct StructRecord Record;
typedef struct StructNodo Nodo;
void printStack(Nodo * head);
struct StructInput{
    char * fileIn;
    char * fileOut;
    unsigned int n;
    unsigned int m;
};
struct StructRecord{
    char * string;
    int len;
};
struct StructNodo {
    Record record;
    Nodo * next;
};
Input *readInput(int argn, char * argv[]);
int countWords(char * string);
void push (char * string, Nodo ** head);
Nodo * pop (Nodo ** head);
void  printRecord(Record record);
Nodo * pop (Nodo ** head);
void buildStack( Input input, Nodo ** head);
void printStack(Nodo * head);
void elabStrVowles(char carattere, Nodo ** head);
void clearStack(Input input,  Nodo ** head);
int main(int argn, char * argv[]){
    Input * input= readInput(argn,argv);

    printf("in: %s  out: %s m: %u n: %u\n", input->fileIn, input->fileOut, input->m, input->n);
    int cont= countWords("asd b sadc");
    printf("cont:%d\n", cont);
    Nodo * head=NULL;
    buildStack(*input, &head);
    printStack(head);
    elabStrVowles('X',&head);
    printf("after elabbb--------------------------------------\n");
    printStack(head);
    clearStack(*input,&head);
    /*
    push ("hello1", &head);
    push ("hello2", &head);
    push ("hello3", &head);


    Record record=  pop (&head)->record;
    //printf("delete record->");
    //printRecord(record);
    */
    return 0;
}
Input *readInput(int argn, char * argv[]){
    if(argn!=5){
        printf("errore input (fileIn fileOut m n) \n");
        exit(0);
    }
    int m= atoi(argv[3]);
    int n= atoi(argv[4]);
    if(m<n){
        printf("errore input m deve essere > n (fileIn fileOut m n) \n");
        exit(0);
    }
    Input * input = malloc(sizeof(Input));
    input->fileIn=malloc(strlen (argv[1])+1);
    input->fileOut=malloc(strlen (argv[2])+1);
    strcpy(input->fileIn, argv[1]);
    strcpy(input->fileOut, argv[2]);
    input->n=n;
    input->m=m;
    return input;
}
int countWords(char * string){
    if(!string){
        return -1;
    }
    int cont=1;
    for(int i=0; i<strlen(string); i++){
        if(string[i]==' '){
            cont++;
        }
    }
    return cont;
}
void push (char * string, Nodo ** head){
    Nodo * nodo= malloc(sizeof(Nodo));
    nodo->record.string= malloc(sizeof(char)*200);
    strcpy(nodo->record.string, string);
    nodo->record.len=(int)strlen(string)-1;
    if(!(*head)){
        nodo->next=NULL;
        (*head)=nodo;
        return;
    }
    nodo->next= (*head);
    (*head)=nodo;
}

Nodo * pop (Nodo ** head){
    if(!(*head)){
        printf("errore pop: lista vuota \n");
        return NULL;
    }
    Nodo * temp= (*head);
    (*head)=(*head)->next;
    return temp;
}
void  printRecord(Record record){
    printf("%s [len: %u] \n", record.string, record.len);
}
void buildStack( Input input, Nodo ** head){
    FILE * fp = fopen(input.fileIn, "r");
    if(!fp){
        printf("errore apertura file \n");
        exit(0);
    }
    size_t len=0;
    char * string= malloc(sizeof(char)*201);
    while(getline(&string,&len, fp)!=-1){
        int n= countWords(string);
        if(n>=input.n && n<=input.m){
            push(string, head);
        }

    }
    if(!feof(fp)){
        printf("errore lettura file \n");
        exit(0);
    }
}
void printStack(Nodo * head){
    if(!head){
        printf("lista vuota");
        exit(0);
    }
    Nodo * nodo= head;
    while(nodo){
        printRecord(nodo->record);
        nodo= nodo->next;
    }
}
void elabStrVowles(char carattere, Nodo ** head){
    if(!head){
        printf("lista vuota");
        exit(0);
    }
    Nodo * nodo= (*head);
    char * vocali = "aeiou";
    while(nodo){
        for(int i=0; i< strlen(nodo->record.string); i++){
            for(int j=0; j<strlen(vocali); j++){
                if(nodo->record.string[i]==vocali[j]){
                    nodo->record.string[i]=carattere;
                    break;
                }
            }
        }
        nodo= nodo->next;
    }

}
void clearStack(Input input,  Nodo ** head){
    if(!head){
        printf("lista vuota");
        exit(0);
    }

    FILE * fp = fopen(input.fileOut, "w");
    if(!fp){
        printf("errore apertura file \n");
        exit(0);
    }
    Nodo * nodo= (*head);
    while(nodo){
        fprintf(fp, "%s [len %u] \n", nodo->record.string,nodo->record.len);
        nodo= nodo->next;
    }
    if(!feof(fp)){
        printf("errore scrittura file \n");
        exit(0);
    }

}
