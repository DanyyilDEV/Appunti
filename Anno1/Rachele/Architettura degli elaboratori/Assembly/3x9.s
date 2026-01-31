          ;Moltiplicare i numeri 9,3

costante1 equ     9
costante2 equ     3
risultato fill    4

          mov     r0,#costante1
          mov     r1,#costante2
          mov     r2, #0
          mov     r3,#risultato

ciclo     
          add     r2,r2,r0
          subs    r1,r1,#1
          bgt     ciclo
          str     r2,[r3]