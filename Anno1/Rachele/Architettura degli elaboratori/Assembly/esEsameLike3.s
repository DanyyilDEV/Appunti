lista     dcd     1,2,3,4,5
dim       equ     5
risultato fill    4

          mov     r0,#lista
          mov     r1,#dim
          mov     r2,#risultato
          mov     r4,#0
          mov     r5,#0
ciclo     
          ldr     r6,[r0]
          add     r4,r4,r6
          add     r5,r5,#1
          add     r0,r0,#4
          subs    r1,r1,#1
          bgt     ciclo
          mov     r7,#0
ciclo2    
          subs    r4,r4,r5
          blt     exit
          add     r7,r7,#1
          b       ciclo2
exit      
          str     r7,[r2]