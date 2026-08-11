text      dcd     99, 105, 97, 111, 32, 67, 97, 114, 108, 97, 33
subString dcd     67, 97, 114, 108, 97

dimT      equ     12
dimS      equ     4
result    fill    4

          mov     r1,#text
          mov     r2,#subString
          mov     r3,#result
          mov     r4,#dimT
          mov     r5,#dimS

          sub     r4,r4, r5
          add     r4,r1, r4
          add     r5, r2, r5
ciclo     mov     r6, r1
          mov     r7,r2
ciclo2    ldrb    r8,[r6],#1
          ldrb    r9,[r7],#1
          cmp     r8,r9
          bne     notequal
          cmp     r5, r7
          bgt ciclo2

notequal end