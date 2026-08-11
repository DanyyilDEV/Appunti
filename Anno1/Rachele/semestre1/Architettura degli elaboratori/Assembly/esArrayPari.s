          ;Data   la lista [1,2,3,4,5,6,7,8,9,10] sommare tutti i numeri pari e minori di 8 e salvare il
          ;risultato in memoria.

lista     dcd     1,2,3,4,5,6,7,8,9,10
dim       equ     10
risultato fill    4
costante  equ     8

          mov     r0,#lista
          mov     r1,#dim
          mov     r2,#risultato
          mov     r3,#costante
          mov     r4,#0
          ldr     r5,[r0]
          sub     r1, r1,#1
ciclo     cmp     r3, r5
          blt     continua
          and     r6,r5,#1
          bne     continua
          cmp     r3, r5
          add     r4, r4, r5
continua  
          add     r0,r0,#4
          ldr     r5,[r0]
          subs    r1, r1,#1
          bne     ciclo
esci      

          str     r4, [r2]
          end     
