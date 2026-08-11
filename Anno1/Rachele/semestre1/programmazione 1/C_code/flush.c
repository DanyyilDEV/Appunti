#include "flush_stdin.h"
#include <stdio.h>

/* Funzione di utilita' che permette di svuotare il canale 
* di input stdin. 
*/ 
void flush_stdin(){
    char flush; 

    /*  
    * L'utente potrebbe aver digitato CTRL+d oppure CTRL +z (su windows) 
    * questo rappresenta il carattere EOF. 
    * In alternativa il buffer potrebbe contenere eventuali 
    * caratteri non letti in precedenza oltre al carattere '\n'. 
    * NB: scanf() non consuma il carattere '\n'. 
    * Ma questa funzione lo consuma e il flusso ritorna al chiamante (vedi esempio 8_04_scanf_c.c) 
    * NB: la funzioe fgets(..., stdin) consuma il carattere '\n', 
    * quindi l'uso di questa funzione andrebbe condizionato 
    * alla non presenza di tale carattere nel buffer di lettura (vedi esempio 8_05_fgets.c) 
    */ 
    while((flush=fgetc(stdin))!='\n' && flush!=EOF) 
    // EOF=End of File, su stdin viene rilevato solo quando utente lo "digita" (CTRL-d o CTRL-z)
	fprintf(stderr, "\nletto e scartato: %c", flush); 	
    fprintf(stderr, "\nletto e scartato: (char code) %u", flush); 
}
