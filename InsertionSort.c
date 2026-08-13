#include <stdio.h>
#include <stdlib.h>

/*Este método é usualmente utilizado para ordenar cartas de
baralho: Considere um elemento por vez, insira cada carta em
sua “posição correta” entre os elementos já considerados de
forma a mantê-los ordenados.

Para colocar o elemento considerado em sua posição “correta”,
basta movimentar os elementos maiores que ele dentre aqueles
já considerados (ordenados) uma posição para a direita e, então,
inserir o elemento considerado na posição vaga resultante.*/

void insertionSort(int *A, int tam){
    int chave, i, j;
    for(j=1; j<tam; j++){
        chave=A[j];
        i=j-1;
        while(i>=0 && A[i]>chave){
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=chave;
    }
}