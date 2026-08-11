lista       dcd     1,5,13,4,1
dim         equ     5
MAXMINCOST  fill    4
MAX         fill    4
const       equ     10

            mov     r0,#lista
            mov     r1,#dim
            mov     r2,#MAX
            mov     r3,#const
            mov     r6,#MAXMINCOST
            mov     r7,#0

ciclo       
            ldr     r4,[r0]
            cmp     r4, r3
            blt     MINORECONST
NEXT        
            ADD     r0,r0,#4
            subs    r1,r1,#1
            bgt     ciclo
            cmp     r7,#0
            beq     ALLMAXCOST
NEXT2       
            str     r5,[r6]
            mov     r0, #lista
            mov     r1, #dim
            ldr     r5, [r0]
            add     r0,r0,#4
            sub     r1,r1,#1
ciclo2      
            ldr     r4,[r0]
            cmp     r5,r4
            blt     NEWMAX
NEXT3       
            add     r0,r0,#4
            subs    r1,r1, #1
            bgt     ciclo2
            str     r5, [r2]
            end
MINORECONST 
            mov     r7,#1
            cmp     r5,r4
            bge     NEXT
            mov     r5,r4
            b       NEXT
ALLMAXCOST  
            mov     r5,#11
            b       NEXT2
NEWMAX      
            mov     r5,r4
            b       NEXT3