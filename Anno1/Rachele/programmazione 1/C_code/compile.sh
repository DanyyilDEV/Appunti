set -x 
for f in `ls -1 *.c | grep -v flush.c | grep -v "8_0[123456789]_scanf_" | grep -v numbers`; do
    echo $f
    gcc -Wall -std=c18 $f -o `echo $f | sed -e 's/\.c//'`
done 

gcc -Wall -o 8_04_scanf_A flush.c 8_04_scanf_A.c
gcc -Wall -o 8_04_scanf_B flush.c 8_04_scanf_B.c
gcc -Wall -o 8_04_scanf_C flush.c 8_04_scanf_C.c
gcc -Wall -o 8_05_scanf_numbers flush.c 8_05_scanf_numbers.c
