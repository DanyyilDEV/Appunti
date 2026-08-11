START       
lista       dcd     1,24,12,8,10,1,4,21,3,1,5,1
dim         equ     12
const       equ     10
risultato   fill    4

            mov     r0, #lista
            mov     r1, #dim
            mov     r2,#const
            mov     r3,#0 ; r3: registro somma

CICLO       
            ldr     r5, [r0] ; r5: registro i-esimo elemento
            cmp     r5,r2
            bge     ADDFUNCTION
NEXT        
            add     r0, r0,#4
            subs    r1,r1,#1
            bgt     CICLO

            ldr     r4, =risultato
            str     r3, [r4]
            end

ADDFUNCTION 
            add     r3, r3,r5
            b       NEXT