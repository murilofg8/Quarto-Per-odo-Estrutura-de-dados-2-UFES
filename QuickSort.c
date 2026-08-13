#include <stdio.h>
#include <stdlib.h>
#include <random>

/*O Quick Sort é um algoritmo de ordenação 
muito rápido que usa o método dividir para conquistar. 
Ele escolhe um item como pivô, 
separa a lista em números menores e maiores que esse pivô, 
e repete o processo de forma recursiva até que tudo esteja ordenado*/

/*Primeiro caso Quick Sort padrão*/
int Particao(int *A,int p, int r){
    int i,j,aux;
    i=p-1;
    for(j=p;j<r;j++){
        if(A[j]<=A[r]){
            i++; aux=A[i]; A[i]=A[j]; A[j]=aux;
        }
    }
    aux=A[i+1];A[i+1]=A[r];A[r]=aux;
}

void QuickSort(int *A,int p, int r){
    int q;
    if(p<r){
        q=Particao(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}

/*Segundo caso Quick Sort Aleatorizado*/
int ParticaoAleatorizado(int *A, int p, int r){
    int i,aux;
    i=random(p,r);
    aux=A[r]; A[r]=A[i]; A[i]=aux;
    return Particao(A,p,r);
}

void QuickSortAleatorizado(int *A, int p, int r){
    int q;
    if(p<r){
        q=ParticaoAleatorizado(A,p,r);
        QuickSortAleatorizado(A,p,q-1);
        QuickSortAleatorizado(A,q+1,r);
    }
}

/*Terceiro caso Quick Sort com o termo médio de 3 termos no sorteio*/


/*Quarto caso Quick Sort para muitos numeros repetidos*/