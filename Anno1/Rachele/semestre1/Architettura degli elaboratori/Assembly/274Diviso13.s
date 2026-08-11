          ;dividere i numeri 274, 13

costante1 equ     274
costante2 equ     13
risultato fill    4
resto     fill    4

          ldr     r0,=costante1
          mov     r1,#costante2
          mov     r2,#0
          mov     r3,#risultato
          mov     r4,#resto

ciclo     


          cmp     r0,r1
          blt     esci
          subs    r0,r0,r1
          add     r2,r2,#1
          b       ciclo
esci      
          str     r2,[r3]
          str     r0,[r4]