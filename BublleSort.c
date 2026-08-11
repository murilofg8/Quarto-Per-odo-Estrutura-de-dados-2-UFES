/*Bubble Sort (ordenação por bolha) é um algoritmo de ordenação simples. 
Ele funciona comparando pares de elementos vizinhos e trocando seus lugares se eles estiverem na ordem errada. 
Esse ciclo se repete até que a lista inteira fique ordenada, fazendo os maiores valores "subirem" para o final como bolhas.*/

void bubbleSort(int A[], int n){
    int i, j, t;
    for(i=n-1; i>=0; i--){
        for(j=1; j<=i; j++){
            if(A[j-1]>A[j]){
                t=A[j-1];
                A[j-1]=A[j];
                A[j]=t;
            }
        }
    }
}