#include <stdio.h>

void maxHeapify(int *A, int tam, int i){
    int maior;
    int esquerda;
    int direita;
    int aux;

    maior = i;

    esquerda = 2 * i + 1;
    direita = 2 * i + 2;

    if (esquerda < tam && A[esquerda] > A[maior]){
        maior = esquerda;
    }

    if (direita < tam && A[direita] > A[maior]){
        maior = direita;
    }

    if (maior != i){
        aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;

        maxHeapify(A, tam, maior);
    }
}

void construirHeap(int *A, int tam){
    int i;

    for (i = tam / 2 - 1; i >= 0; i--){
        maxHeapify(A, tam, i);
    }
}

void heapSort(int *A, int tam){
    int i;
    int aux;

    construirHeap(A, tam);

    for (i = tam - 1; i >= 1; i--){
        aux = A[0];
        A[0] = A[i];
        A[i] = aux;

        maxHeapify(A, i, 0);
    }
}