#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    float valor;
    struct No *prox;
} No;


/* Insere um elemento na lista do bucket */
void inserir(No **lista, float valor){
    No *novo;
    No *atual;

    novo = (No *)malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = NULL;

    /* Lista vazia ou valor deve ficar no início */
    if (*lista == NULL || valor < (*lista)->valor){
        novo->prox = *lista;
        *lista = novo;
    }
    else{
        atual = *lista;

        while (atual->prox != NULL && atual->prox->valor <= valor){
            atual = atual->prox;
        }

        novo->prox = atual->prox;
        atual->prox = novo;
    }
}


/* Insertion Sort de uma lista encadeada */
void insertionSort(No **lista){
    No *ordenada;
    No *atual;
    No *proximo;

    ordenada = NULL;
    atual = *lista;

    while (atual != NULL){
        proximo = atual->prox;

        if (ordenada == NULL || atual->valor < ordenada->valor){
            atual->prox = ordenada;
            ordenada = atual;
        }
        else{
            No *p = ordenada;

            while (p->prox != NULL && p->prox->valor <= atual->valor){
                p = p->prox;
            }

            atual->prox = p->prox;
            p->prox = atual;
        }

        atual = proximo;
    }

    *lista = ordenada;
}


/* Bucket Sort */
void bucketSort(float *A, int n){
    No **B;
    No *atual;
    No *proximo;

    int i;
    int indice;
    int pos;

    /* B é um vetor de ponteiros para listas */
    B = (No **)malloc(n * sizeof(No *));

    /* Inicializa todos os buckets como vazios */
    for (i = 0; i < n; i++){
        B[i] = NULL;
    }

    /* Coloca cada elemento no seu bucket */
    for (i = 0; i < n; i++){
        indice = (int)(n * A[i]);
        inserir(&B[indice], A[i]);
    }

    /* Ordena cada bucket */
    for (i = 0; i < n; i++){
        insertionSort(&B[i]);
    }

    /* Concatena os buckets de volta em A */
    pos = 0;

    for (i = 0; i < n; i++){
        atual = B[i];

        while (atual != NULL){
            A[pos] = atual->valor;
            pos++;

            proximo = atual->prox;
            free(atual);

            atual = proximo;
        }
    }

    free(B);
}