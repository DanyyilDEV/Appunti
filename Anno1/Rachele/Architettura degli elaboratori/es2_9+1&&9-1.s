START       
somma       dcd     0
sottrazione dcd     0
            mov     r0,#9
            add     r1, r0,#1
            sub     r2, r0,#1
            ldr     r3, =somma
            ldr     r4, =sottrazione
            str     r1,[r3]
            str     r2,[r4]
            END