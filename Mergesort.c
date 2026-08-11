/*Abordagem Dividir e Conquistar
 Divida o problema em vários subproblemas que são similares ao
 problema original, mas possuem tamanho menor.
 Resolva os subproblemas recursivamente, e então
 Combine as soluções obtidas para criar uma solução para o
problema original.*/

void Mergesort(int *V, int ini, int fim){
    if(ini<fim){
        int meio=(ini+fim)/2;
        Mergesort(V,ini,meio);
        Mergesort(V,meio+1,fim);
        Merge(V,ini,meio,fim);
    }
}

void Merge(int *V, int ini, int meio, int fim){
    int *temp=(int *)malloc((fim-ini+1)*sizeof(int));
    int i=ini,j=meio+1,k=0;
    for(k=0;k<fim-ini+1;k++){
        if(i<=meio && j<=fim){
            if(V[i]<=V[j]){
                temp[k]=V[i];
                i++;
            }else{
                temp[k]=V[j];
                j++;
            }
        }
        if(i<=meio){
            temp[k]=V[i];
            i++;
        }else{
            temp[k]=V[j];
            j++;
        }
    }
    i=ini;
    for(k=0;k<fim-ini+1;k++){
        V[i]=temp[k];
        i++;
    }
    free(temp);
}