START  
array  DCD     2, 3, 4, 5,1 ; Dichiaro Array di 4 numeri
RESULT DCD     0 ; Riserva una cella di memoria per il risultato
       ldr     r1, =array ; Carico l'indirizzo di memoria del primo elemento dell' array in r1
       ldr     r0, [r1] ; Carico in R0 il primo elemento di dell' array (il cui indirizzo è in R1)
       ldr     r2, [r1, #4] ; Carico in R2 il secondo elemento di dell' array
       ;       (il cui indirizzo è quello di R1+ 4byte visto che ogni elemento è una word)
       ldr     r3, [r1, #8]
       ldr     r4, [r1, #12]
       ldr     r5, [r1, #16]
       add     r0, r0, r2 ; sommo in R0, R0 con R2
       add     r0, r0, r3
       add     r0, r0, r4
       add     r0, r0, r5

       LDR     R6, =RESULT ; R6 = indirizzo di memoria di RESULT
       STR     R0, [R6] ; salva il contenuto di R0 (15) in memoria RESULT tramite l'indirizzo contenuto in r6


       END     ; Termina il programma

