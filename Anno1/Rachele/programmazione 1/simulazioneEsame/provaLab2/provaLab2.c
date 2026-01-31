/*************************************************
 * Nome:        INSERIRE NOME
 * Cognome:     INSERIRE COGNOME
 * Matricola:   INSERIRE MATRICOLA
 *************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- STRUTTURE ---------- */

typedef struct {
    char codiceEvento[31];
    char nomeLuogo[31];
    int capienzaMax;
} Record;

typedef struct nodo {
    Record dato;
    struct nodo *next;
} Nodo;

typedef struct {
    char inputFile[100];
    char outputFile[100];
    int k;
} InputParams;

/* ---------- PROTOTIPI ---------- */

InputParams ReadInput(int argc, char *argv[]);
Nodo *insertRecord(Nodo *head, Record r);
Nodo *buildList(const char *filename);
void printList(Nodo *head);
void elab(Nodo *head, const char *outfile, int k);
void freeList(Nodo *head);

/* ---------- MAIN ---------- */

int main(int argc, char *argv[]) {
    InputParams params;
    Nodo *lista = NULL;

    params = ReadInput(argc, argv);

    lista = buildList(params.inputFile);

    printf("** PrintList() **\n\n");
    printList(lista);

    elab(lista, params.outputFile, params.k);

    freeList(lista);
    return 0;
}

/* ---------- FUNZIONI ---------- */

InputParams ReadInput(int argc, char *argv[]) {
    InputParams p;

    if (argc != 4) {
        fprintf(stderr, "Errore: uso corretto -> %s input.bin output.txt k\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strncpy(p.inputFile, argv[1], 99);
    strncpy(p.outputFile, argv[2], 99);
    p.k = atoi(argv[3]);

    if (p.k < 0) {
        fprintf(stderr, "Errore: k deve essere >= 0\n");
        exit(EXIT_FAILURE);
    }

    return p;
}

Nodo *insertRecord(Nodo *head, Record r) {
    Nodo *newNode = malloc(sizeof(Nodo));
    if (!newNode) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    newNode->dato = r;
    newNode->next = NULL;

    if (head == NULL || strcmp(r.codiceEvento, head->dato.codiceEvento) < 0) {
        newNode->next = head;
        return newNode;
    }

    Nodo *curr = head;
    while (curr->next != NULL &&
           strcmp(r.codiceEvento, curr->next->dato.codiceEvento) > 0) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

Nodo *buildList(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Errore apertura file binario");
        exit(EXIT_FAILURE);
    }

    Nodo *head = NULL;
    Record r;

    while (fread(&r, sizeof(Record), 1, fp) == 1) {
        head = insertRecord(head, r);
    }

    fclose(fp);
    return head;
}

void printList(Nodo *head) {
    while (head != NULL) {
        printf("%s %s %d\n",
               head->dato.codiceEvento,
               head->dato.nomeLuogo,
               head->dato.capienzaMax);
        head = head->next;
    }
    printf("\n");
}

void elab(Nodo *head, const char *outfile, int k) {
    FILE *fp = fopen(outfile, "w");
    if (!fp) {
        perror("Errore apertura file output");
        exit(EXIT_FAILURE);
    }

    while (head != NULL) {
        if (head->dato.capienzaMax >= k) {
            fprintf(fp, "%s %s %d\n",
                    head->dato.codiceEvento,
                    head->dato.nomeLuogo,
                    head->dato.capienzaMax);
        }
        head = head->next;
    }

    fclose(fp);
}

void freeList(Nodo *head) {
    Nodo *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
