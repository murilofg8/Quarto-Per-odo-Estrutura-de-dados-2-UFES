#include <stdio.h>
#include <stdlib.h>

void maxHeapify(int A[], int tam, int i){
    int maior;
    int aux;

    maior = i;

    if (2 * i <= tam && A[2 * i] > A[i]){
        maior = 2 * i;
    }

    if (2 * i + 1 <= tam && A[2 * i + 1] > A[maior]){
        maior = 2 * i + 1;
    }

    if (maior != i){
        aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;

        maxHeapify(A, tam, maior);
    }
}


void construirHeap(int A[], int tam){
    int i;

    for (i = tam / 2; i >= 1; i--){
        maxHeapify(A, tam, i);
    }
}


void heapSort(int A[], int tam){
    int i;
    int aux;

    construirHeap(A, tam);

    for (i = tam; i >= 2; i--){
        aux = A[1];
        A[1] = A[i];
        A[i] = aux;

        maxHeapify(A, i - 1, 1);
    }
}