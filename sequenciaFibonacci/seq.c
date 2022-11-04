#include "seq.h"

int fibonacci( int n ) {
    if( n == 0 ) return 1;
    else if( n == 1 ) return 1;
    else return fibonacci( n - 1 ) + fibonacci( n - 2);
}

int* sequencia(int n){
    int *seq = (int *)malloc( (n+2) * (n+2) * sizeof(int));
    int pos = 0;
    for(int i = 1;i<=n+1;i++){
        for(int j = 0;j<i;j++){
            seq[pos++] = fibonacci(j);
        }
    }
    return seq;
}
