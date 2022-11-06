#include <stdio.h>
#include <stdlib.h>

typedef struct matrizFazenda{

    int linhas; 
    int colunas;
    int **matrizOriginal; //matriz lida do arquivo, nao ira mudar
    int **matrizPercorrida; // matriz zerada, que sera preenchida com a ordem da colheita das batatas
    int caminhosPercorridos; // numero de campos de batatas colhidas

}matrizFazenda;

matrizFazenda *leitura( char* caminhoArquivo );

void imprimir_matriz( matrizFazenda *dados );
