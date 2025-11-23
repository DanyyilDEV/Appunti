START     
array1    dcd     1,20,20,20,2,18,30,27,3,22,26,28
dim       equ     3

          mov     r1,#array1
          mov     r2, #dim
risultato fill    12
          mov     r8, #0
          mov     r9,#0
          mov     r10,#0

ciclo     add     r1,r1,#4
          ldr     r3,[r1]
          add     r8,r8, r3
          add     r1, r1, #4
          ldr     r3,[r1]
          add     r9, r9, r3
          add     r1, r1,#4
          ldr     r3,[r1]
          add     r10, r10, r3
          subs    r2, r2,#1
          add     r1,r1,#4
          bgt     ciclo
          mov     r1, #risultato
          str     r8,[r1]
          str     r9,[r1,#4]
          str     r10,[r1, #8]



