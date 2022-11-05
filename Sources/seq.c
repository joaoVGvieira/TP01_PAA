#include "../Libs/seq.h"

int fibonacci(int n){
    int i = 1;
    int j = 1;

    for(int k = 1; k < n; k++){
        int t = i + j;
        i = j;
        j = t;
    }
    return j;
}

int* sequencia(int n){

    int *seq = (int *)malloc( n * sizeof(int) );
    int pos = 1;
    seq[0] = 1;
    int contrepe = 2;
    while(pos != 200){
        for(int i = 0; i < contrepe; i ++){
            if(pos == 200) break;
            seq[pos] = fibonacci(i);
            pos++;
        }
        contrepe++;
    }

    return seq;
}

void imprimirSequencia(int vetor[],int n){
        printf("\nSEQUENCIA: ");
        for(int i = 0; i < n; i ++){
            printf("%d ", vetor[i]);
        }
        printf("\n");
}