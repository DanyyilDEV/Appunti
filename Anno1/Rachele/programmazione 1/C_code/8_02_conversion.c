#include <stdio.h>

int main(){

    float x = +12345.678; 

		// + ovvero anteporre il segno 
		// .6 ovvero 6 cifre decimali 
		// f ovvero specificatore di conversione 
		// 20 ovvero lughezza di campo (almeno 20 caratteri, padding di spazi a sinistra!) 
    printf("\nx: %+20.6f", x); 


    // padding di ZERI a sinistra al posto degli spazi 
    printf("\nx: %+020.3f", x);  


		// '-' ovvero allineamento a sinistra nel campo di 200 caratteri (no padding) 
    printf("\nx: %-+20.3f", x); 

		// un double con oltre 15 cifre significative, in totale 16 caratteri!
    double y = 123456789.123456;

		
		// lunghezza minima 10, ma output piu lungo..OK
    printf("\ny: %-+10.6f", y); 

    // long, unsigned, char 
    long a = 10000000000;
		// l e' modificatore di ampiezza o lunghezza 
    printf("\na=%ld", a); // ok, a e' un long int..
    printf("\na=%d", a); // NO! a e' un long int, genera un warning..

		// 
    long k = 10e12; // variabile long, letterale double che viene convertito in long 
    printf("\n k=%ld", k);

		// il numero long va stampato come double (notazione scientifica), richiede una conversione 
    printf("\n k=%e", (double) k); // serve un type-cast
    printf("\n k=%e", k); // NO! serve un type-cast

		// specificatore di conversione 'u' ovvero unsigned
    unsigned i = 123456; 
    printf("\ni=%u", i); 

    char c = 'h';
    printf("\nx=%hhd", c); // e' un numero.. (hh vale per i char, 1 byte) 

    printf("\nx=%c", c); // stampa il carattere..

		short s = 1024; 
    printf("\ns=%hd", s); // 'h' vale per lo short..

    // stampare una stringa o un carattere? 
    const char *messaggio = "Hello world!";
    printf("\nmessaggio=%s", messaggio); // e' un numero..

    // notazione esponenziale 
    printf("\ny=%e", y); // notazione scientifica (occhio alla precisione!)
    printf("\ny=%.15g", y); // notazione scientifica. Se specificato g, allora la precisione si riferira' al numero di cifre significative da stampare
    printf("\ny=%.15g", y); // notazione scientifica se necessario 

    double z = 12345.12345; 
    // g--> notazione esponenziale (se esponente < -4 o maggiore della precisione specificata)
    printf("\nz=%.10g", z); 

   //stampare in formato esadecimale 
   // la stampa del numero double mostra segno, mantissa ed esponente 
   printf("\ndouble in hex format: %a", 223.45678); // lettere minuscole 
   printf("\ndouble in hex format: %A", -223.45678); // lettere maiuscole
   printf("\ninteger in hex format: %x", 1234); // lettere minuscole 
   printf("\ninteger in hex format: %X\n", -1234); // lettere maiuscole
}
