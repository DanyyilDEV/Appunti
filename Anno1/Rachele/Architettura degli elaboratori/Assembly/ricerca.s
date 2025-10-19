START     
array     dcd     1,24,12,8,10,1,4,21,3,1,5,1
dim       equ     12
risultato fill    4
costante  equ     10

          ldr     r2, =dim
          ldr     r1, =array

ciclo     
          ldr     r3,[r1]
          cmp     r3, #costante
          beq     esci
          add     r1, r1,#4
          subs    r2, r2,#1
          bgt     ciclo

          mov     r3,#-1
esci      
          mov     r4, #risultato
          str     r1, [r4]
