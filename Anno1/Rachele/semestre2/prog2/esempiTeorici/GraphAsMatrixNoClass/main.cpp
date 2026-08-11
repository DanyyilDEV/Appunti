#include <iostream>
using namespace std;

// Funzione che crea la matrice. Restituisce un puntatore a un array di puntatori (int**)
int** createGraph(int nVertex, int edges[][2], int nEdges) {
    // Allocazione dinamica della matrice (array di puntatori)
    int** mat = new int*[nVertex];
    for (int i = 0; i < nVertex; ++i) {
        mat[i] = new int[nVertex];
        // Inizializzazione a 0
        for (int j = 0; j < nVertex; ++j) {
            mat[i][j] = 0;
        }
    }

    // Popolamento della matrice con gli archi
    for (int i = 0; i < nEdges; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        mat[u][v] = 1;
    }

    return mat;
}

int main() {
    int nVertex = 3; // Numero di vertici
    int nEdge = 3; // Numero di archi

    // Array bidimensionale classico per gli archi
    int edges[3][2] = {{1, 0}, {2, 0}, {1, 2}};

    // Costruzione del grafo
    int** mat = createGraph(nVertex, edges, nEdge);

    // Stampa della matrice di adiacenza
    cout << "Adjacency Matrix Representation:" << endl;
    for (int i = 0; i < nVertex; i++) {
        for (int j = 0; j < nVertex; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // NOTA IMPORTANTE: Liberazione della memoria (Deallocazione)
    // Con gli array dinamici devi sempre pulire manualmente l'heap!
    for (int i = 0; i < nVertex; i++) {
        delete[] mat[i];
    }
    delete[] mat;

    return 0;
}
