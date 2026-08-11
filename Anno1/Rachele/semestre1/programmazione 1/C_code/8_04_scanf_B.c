#include <stdio.h> 

/* Uso di scanf(), lettura di stringhe. 
*
Specificare la massima ampiezza di campo 
ovvero che scanf dovra' consumare dallo stream 
non piu' di n caratteri..  

NB: di conseguenza, i caratteri non consumati rimangono 
nello stream, in attesa di essere consumati da una qualche funzione 
di libreria, come scanf()/fscanf(), getc()/fgetc(), fgets()/gets()

*/ 

int main(){

    char buffer3[11]={};
    char buffer1[6]={0};
    char buffer2[10]={0};

    printf("\n Inserisci una stringa di max 5 caratteri: ");
    // %5s indica che scanf deve leggere non piu' di 5 caratteri 
    scanf("%5s", buffer1);  // non consuma i caratteri oltre il quinto..

    // provare ad inserire 123456789
    // NB output del buffer2 (OK) 
    printf("\nbuffer1: %s, buffer2: %s \n", buffer1, buffer2);

		// Se erano stati inseriti piu' caratteri durante la prima chiamata scanf()
		// questi saranno erroneamente consumati con una ulteriore chiamata
    printf("\nProvo a leggere qualcos'altro, inserire una stringa di max 10 caratteri: ");
    scanf("%s", buffer3);
    printf("buffer3: %s", buffer3);

    // i caratteri oltre il quinto sono stati copiati (dalla scanf) in buffer3!! 
    
    // --> vedi esempio 8_04_scanf_c.c
}
