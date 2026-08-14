#include <stdio.h>
#include <stdlib.h>
#include <random>

/*O Quick Sort é um algoritmo de ordenação
muito rápido que usa o método dividir para conquistar.
Ele escolhe um item como pivô,
separa a lista em números menores e maiores que esse pivô,
e repete o processo de forma recursiva até que tudo esteja ordenado*/

/*Primeiro caso Quick Sort padrão*/
int Particao(int *A, int p, int r)
{
    int i, j, aux;
    i = p - 1;
    for (j = p; j < r; j++)
    {
        if (A[j] <= A[r])
        {
            i++;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }
    aux = A[i + 1];
    A[i + 1] = A[r];
    A[r] = aux;
    return i + 1;
}

void QuickSort(int *A, int p, int r)
{
    int q;
    if (p < r)
    {
        q = Particao(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

/*Segundo caso Quick Sort Aleatorizado*/
int ParticaoAleatorizado(int *A, int p, int r)
{
    int i, aux;
    i = random(p, r);
    aux = A[r];
    A[r] = A[i];
    A[i] = aux;
    return Particao(A, p, r);
}

void QuickSortAleatorizado(int *A, int p, int r)
{
    int q;
    if (p < r)
    {
        q = ParticaoAleatorizado(A, p, r);
        QuickSortAleatorizado(A, p, q - 1);
        QuickSortAleatorizado(A, q + 1, r);
    }
}

/*Terceiro caso Quick Sort com o termo médio de 3 termos no sorteio*/

/*Quarto caso Quick Sort para muitos numeros repetidos*/
void QuickSortMuitos(int *mat, int p, int r){
    if (p < r){
        int aux, med = (p + r) / 2;
        int ini, fim; // guarda inicio e fim de elementos repetidos
        if(mat[p] > mat[r]){
            if (mat[p] > mat[med]){
                if (mat[r] > mat[med])
                {
                    aux = mat[r];
                    mat[r] = mat[med];
                    mat[med] = aux;
                } // meio mediano
                // ultimo mediano
            }
            else{
                aux = mat[r];
                mat[r] = mat[p];
                mat[p] = aux;
            } // medio no inicio
        }
        else{
            if (mat[p] > mat[med]){
                aux = mat[r];
                mat[r] = mat[p];
                mat[p] = aux;
            } // medio no inicio
            else{
                if (mat[r] > mat[med]){
                    aux = mat[r];
                    mat[r] = mat[med];
                    mat[med] = aux;
                } // meio mediano
            } // ultimo mediano
        }
        ini = Particiona(mat, p, r, &fim);
        if(ini - 1 > p){
            QuickSortMuitos(mat, p, ini - 1);
        }
        if (fim + 1 < r){
            QuickSortMuitos(mat, fim + 1, r);
        }    
    }
}

int Particiona(int *mat, int p, int r, int *f)
{
    int i, j, k, t, aux;
    for (j = p, i = p - 1, k = r; j < k; j++)
    {
        if (mat[j] < mat[r])
        {
            i++;
            aux = mat[i];
            mat[i] = mat[j];
            mat[j] = aux;
        }
        else
        {
            if (mat[j] == mat[r])
            {
                k--;
                aux = mat[k];
                mat[k] = mat[j];
                mat[j] = aux;
                j--;
            }
        }
    }
    i++;
    for (t = i; j <= r; j++, t++){
        aux = mat[t];
        mat[t] = mat[j];
        mat[j] = aux;
    }
    (*f) = t - 1;
    return i;
}