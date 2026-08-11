lista  dcd     1,2,3,4,5
dim    equ     5
CONST  equ     2
val    fill    4
       mov     r0, #lista
       mov     r1,#dim
       mov     r2, #CONST
       mov     r6,#val

ciclo  
       ldr     r3,[r0]
       ands     r4,r3,#1
       beq     pari
next   
       add     r0,r0,#4
       subs    r1,r1, #1
       bgt     ciclo
       end
pari   
       cmp     r3,r2
       ble     next
       str     r3,[r6]
       end