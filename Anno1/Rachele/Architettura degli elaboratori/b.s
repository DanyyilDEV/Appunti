START      
array      dcd     10,20,12,12,5,1,5,1
dim        equ     8
const1     equ     1
const2     equ     10
risultato  fill    4

           mov     r0,#0
           mov     r2, #dim
           mov     r1, #array

ciclo      
           ldr     r3, [r1]
           cmp     r3, #const1
           cmp     r3, #const2
           bne     incremento
continua   
           add     r1,r1,#4
           subs    r2,r2,#1
           bgt     ciclo

           ldr     r5, =risultato
           str     r0,[r5]
           end
incremento 
           add     r0,r0,#1
           b       continua