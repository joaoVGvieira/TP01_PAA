#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int qntdLinhas;
    int qntdColunas;
    int **mat;
    
} infoArquivo;

infoArquivo *leitura( char* caminhoArquivo );

void imprimir_matriz(infoArquivo *dados );

