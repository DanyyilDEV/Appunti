START     
array     dcd     1,21,12,8,10,1,4,21,3,1,5,1
dim       equ     12
risultato fill    4
costante  equ     1

          mov     r2, #dim
          ldr     r1, =array
          mov     r9, #0

ciclo     
          ldr     r3,[r1]
          cmp     r3, #costante
          beq     somma
continua  
          add     r1, r1,#4
          subs    r2, r2,#1
          bgt     ciclo

          ldr     r0, =risultato
          str     r9, [r0]
          end



somma     
          add     r9, r9,#1
          b       continua
