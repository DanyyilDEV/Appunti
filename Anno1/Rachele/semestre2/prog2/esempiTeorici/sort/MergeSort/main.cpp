#include <iostream>
using namespace std;

// Unisce i due sotto-array di arr[].
// Primo sotto-array: arr[left..mid]
// Secondo sotto-array: arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Creiamo array temporanei "normali" (VLA o allocati staticamente)
    // Nota: in C++ moderno è preferibile allocarli dinamicamente o usare una dimensione fissa,
    // ma per semplicità scolastica usiamo gli array a dimensione variabile.
    int L[n1], R[n2];

    // Copiamo i dati negli array temporanei L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0; // Indice iniziale del primo sotto-array
    int j = 0; // Indice iniziale del secondo sotto-array
    int k = left; // Indice iniziale dell'array unito

    // Uniamo gli array temporanei di nuovo in arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiamo gli elementi rimanenti di L[], se ce ne sono
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiamo gli elementi rimanenti di R[], se ce ne sono
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// left è l'indice sinistro, right è l'indice destro
// del sotto-array da ordinare
void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Chiamate ricorsive
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Unione
    merge(arr, left, mid, right);
}

// Driver code
int main() {
    // Definizione di un array di interi "normale"
    int arr[] = {38, 27, 43, 10};

    // Calcoliamo la dimensione dell'array dividendo la dimensione totale in byte
    // per la dimensione di un singolo elemento (int)
    int n = sizeof(arr) / sizeof(arr[0]);

    // Avviamo il merge sort
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
