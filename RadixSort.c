#include <stdio.h>
#include <stdlib.h>

void countingSort(int *A, int *B, int tam, int exp){
    int C[10];
    int i;
    int j;
    int digito;

    // Inicializa o vetor de contagem
    for (i = 0; i < 10; i++){
        C[i] = 0;
    }

    // Conta os dígitos
    for (j = 0; j < tam; j++){
        digito = (A[j] / exp) % 10;
        C[digito]++;
    }

    // Soma acumulada
    for (i = 1; i < 10; i++){
        C[i] = C[i] + C[i - 1];
    }

    // Coloca os elementos em B
    // De trás para frente para manter a estabilidade
    for (j = tam - 1; j >= 0; j--){
        digito = (A[j] / exp) % 10;

        B[C[digito] - 1] = A[j];

        C[digito]--;
    }

    // Copia B de volta para A
    for (i = 0; i < tam; i++){
        A[i] = B[i];
    }
}

void radixSort(int *A, int tam, int d){
    int i;
    int exp;
    int *B;

    B = (int *)malloc(tam * sizeof(int));

    exp = 1;

    for (i = 1; i <= d; i++){
        countingSort(A, B, tam, exp);

        exp = exp * 10;
    }

    free(B);
}