ARR       dcd     1,2,5,4,3,-2
LUNG      equ     6
POSMIN    fill    4
VALMAX    fill    4
          ldr     r0, =ARR
          mov     r1, #LUNG
          ldr     r2, =POSMIN
          ldr     r3, =VALMAX
          ldr     r4, [r0]
          add     r0,r0,#4
ciclo1    
          ldr     r5, [r0]
          cmp     r4,r5
          blt     NEWMAX
NEXT      
          add     r0,r0,#4
          subs    r1,r1, #1
          bgt     ciclo1
          str     r4,[r3]
          mov     r1,#LUNG
          sub     r0,r0,r1
          ldr     r5,[r4]
          add     r0,r0,#4
ciclo2    
          ldr     r6,[r0]
          cmp     r5,r6
          bgt     NEWPOSMIN
NEXT2     
          add     r0,r0,#4
          subs    r1,r1,#1
          bgt     ciclo2
          str     r4, [r2]
          end
NEWMAX    
          mov     r4, r5
          b       NEXT
NEWPOSMIN 
          ldr     r4, [r6]
          mov     r5, r6
          B       NEXT2