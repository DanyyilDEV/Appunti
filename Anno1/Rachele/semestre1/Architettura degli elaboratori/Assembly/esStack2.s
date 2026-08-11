lista     dcd     1,2,3,4,5,6,7,8,9,10
dim       dcd     10
risultato fill    4

          mov     r1,#lista
          mov     r2,#dim
          ldr     r2, [r2]
          stmfd   sp!,{r1,r2}
          mov     r3,#risultato
          bl      somma
          end
somma     stmfd   sp!,{r4,r5,lr}
          ldr     r1,[sp,#12]
          ldr     r2,[sp,#16]
          mov     r5, #0
ciclo     

          ldr     r4, [r1]
          add     r5,r5,r4
          subs    r2,r2,#1
          add     r1,r1,#4
          bgt     ciclo
          STR     r5, [r3] ; salvo somma in memoria
          LDMFD   sp!, {r4,r5,pc} ; ripristino registri e ritorno