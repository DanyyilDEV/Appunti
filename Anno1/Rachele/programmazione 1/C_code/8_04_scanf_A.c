#include <stdio.h> 

/* Primo uso di scanf. Lettura di stringhe. 
* Nessun controllo sul numero di caratteri da inserire nel buffer! 
*/ 

int main(){

    // una stringa e' formata da una sequenza di caratteri oltre il carattere '\0'
    char buffer1[6]={0};
    char buffer2[10]={0};

    // NB: con scanf non vi e' alcun controllo inerente la  
    // lunghezza dei dati da scrivere nel buffer, a meno che non
    // sia specificato dal programmatore con un modificatore di 
    // di massima ampiezza --> es: %10s  
    
    printf("\n Inserisci una stringa di max 5 caratteri: ");
    // provare ad inserire 123456789
    unsigned n = scanf("%s", buffer1); // '\0'

    printf("\n Acquisiti da scanf %u caratteri!", n); 

    // NB output del buffer2! 
    // Buffer2 viene allocato immediatamente dopo nello stack
    // scanf() copiera' brutalmente i caratteri in eccesso 
    // all'interno di buffer2
    printf("buffer1: %s, buffer2: %s \n", buffer1, buffer2); 

    // --> vedi prossimo esempio 8_04_scanf_B.c
}
