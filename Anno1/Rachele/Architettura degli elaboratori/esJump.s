variabile      equ     10
costante       equ     5

               mov     r1, #variabile
               bl      sottoProgramma
               mov     r1,#2


sottoProgramma 
               add     r1, r1, #costante