START        
array        dcd     1,2,3,4,5,6,7,8,9,10,11,12,13
dim          equ     13
const1       equ     5
contMinori   fill    4
contUguali   fill    4
contMaggiori fill    4

             mov     r0,#0
             mov     r4,#0
             mov     r5,#0
             mov     r2, #dim
             mov     r1, #array
             mov     r6, #contUguali
             mov     r7, #contMaggiori
             mov     r8, #contMinori

ciclo        
             ldr     r3, [r1]
             cmp     r3, #const1
             beq     contuguali
             bgt     contmaggiore
             blt     contminore
continua     
             add     r1,r1,#4
             subs    r2,r2,#1
             bgt     ciclo

             
             str     r0,[r6]
             str     r4,[r7]
             str     r5,[r8]
             end

contuguali   

             add     r0,r0,#1
             b       continua
contmaggiore 

             add     r4,r4,#1
             b       continua
contminore   

             add     r5,r5,#1
             b       continua