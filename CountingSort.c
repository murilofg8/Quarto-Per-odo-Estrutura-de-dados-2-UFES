#include <stdio.h>
#include <stdlib.h>

void countingSort(int *A, int *B, int tamanho, int k){
    int *C;
    int i;
    int j;

    // Cria o vetor C com k + 1 posições
    C = (int *)malloc((k + 1) * sizeof(int));

    // C[i] = 0
    for (i = 0; i <= k; i++){
        C[i] = 0;
    }

    // Conta quantas vezes cada valor aparece em A
    for (j = 0; j < tamanho; j++){
        C[A[j]] = C[A[j]] + 1;
    }

    // C[i] passa a representar a posição acumulada
    for (i = 1; i <= k; i++){
        C[i] = C[i] + C[i - 1];
    }

    // Coloca os elementos em B
    for (j = tamanho - 1; j >= 0; j--){
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    free(C);
}