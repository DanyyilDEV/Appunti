le prove sono complete, nel senso che il programma parte e fa ciò che chiede la consegna. Probabilmente ci sono errori che non compromettono il programma ma sono sempre errori tipo:

1) char * string = malloc(sizeof(argv[1])) sbagliato!!! (è sbagliato in molti esercizi XD) sarebbe dovuto essere :
char * string = malloc(strlen(argv[1])+1).
2) tanti free(puntatore) dimenticati

ecc...