START     
array     dcd     30,10,23,1,17,8,19,10
dim       equ     8
const1    equ     10
const2    equ     20
risultato fill    4

          mov     r0,#0
          mov     r2, #dim
          mov     r1, #array

ciclo     
          ldr     r3, [r1]
          cmp     r3, #const1
          bge     somma
continua  
          add     r1,r1,#4
          subs    r2,r2,#1
          bgt     ciclo

          ldr     r5, =risultato
          str     r0,[r5]
          end
somma     

          cmp     r3, #const2
          bgt     continua
          add     r0,r0,r3
          b       continua