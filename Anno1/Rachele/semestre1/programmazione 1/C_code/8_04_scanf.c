#include <stdio.h> 

/* Primo uso di scanf 
* Lettura di stringhe. 
*/ 

int main(){

    // una stringa e' formata da una sequenza di caratteri oltre il carattere '\0'
    char stringa[31] = {0}; // tutti i caratteri saranno inizialmente '\0'


    printf("\n Inserisci una stringa (max 30 caratteri): ");

    // Provare a digitare una sequenza di spazi, tab o newline prima della stringa, 
    // questi saranno scartati in fase di lettura da stdin dalla funzione scanf
    // finche' non si digita almeno un carattere che non sia ``blank`` e poi invio,
    // la funzione rimarra' in attesa di input
    // Vale lo stesso principio per i ``trailing`` white spaces, 
    // che saranno scartati, incluso il newline finale
    unsigned int n = scanf("%s", stringa);  

    // Scanf restituisce il numero di ``token`` acquisiti da standard input
    printf("\n Ecco la stringa acquisita: \"%s\", numero di elementi acquisiti da scanf: %d \n", stringa, n);

    // NB: il carattere '\n' rimane nel buffer di input..
    char c; 
    scanf("%c", &c); 

    printf("\n c: %c, \n c (ASCII) : %hhd", c, c); 
    
}
