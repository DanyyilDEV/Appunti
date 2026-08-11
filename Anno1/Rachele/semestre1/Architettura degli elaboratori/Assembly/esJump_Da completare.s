vet       dcd     1,2,3,4,5,6,7,8
dim       dcd     8
risultato fill    4

          mov     r1, #dim
          ldr     r1, [r1]
          mov     r2, #vet
          ldr     r2, [r2]
          mov     r3, #risultato
          bl      somma




somma     
store     stmfd   sp!,{r3}
          mov     r0,#0
ciclo     
          add     r0, r0, r2
          ldr     r2,[r2],#4
          subs    r1,r1, #1
          bgt     ciclo

          ldmfd   sp!,{r3}
          mov     pc,lr