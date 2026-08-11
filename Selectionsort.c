/*Funcionamento: primeiro, encontre o menor elemento no arranjo
e troque-o com o elemento na primeira posição. Depois,
encontre o segundo menor elemento do arranjo e troque-o com o
elemento na segunda posição. Continue o processo até que todo
o arranjo esteja ordenado.*/

void selectionSort(int A[], int n){
    int i, j, min, t;
    for(i=0; i<n-1; i++){
        min=i;
        for(j=i+1; j<n; j++){
            if(A[j]<A[min]) min=j;
        }
        t=A[min];
        A[min]=A[i];
        A[i]=t;
    }
}