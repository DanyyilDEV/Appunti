START
array     dcd     1,24,12,8,10,1,4,21,3,1,5,1
dim equ     12
const     equ     10
risultato fill    4

          mov     r8,#0
          mov     r2, #dim
          mov     r1, #array

ciclo
        ldr r3, [r1]
        cmp r3, #const
        bge somma
        continua
        subs r2,#1
        add r1,#4
        bgt ciclo

        ldr r5, =risultato
        str r8,[r5]
end
somma
    add r8,r3
    b continua