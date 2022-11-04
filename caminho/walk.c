#include "../sequenciaFibonacci/seq.h"
#include "../leituraArquivo/read.h"
#include "../matrizFazenda/matrizFazenda.h"

#include <math.h>

void atualizaPosicao(int *linha, int *coluna, int opcao){
    if(opcao == 0){
        linha ++;
        return;
    }if(opcao == 1){
        coluna ++;
        return;
    }if(opcao == 2){
        coluna --;
        return;
    }if(opcao == 3){
        linha ++;
        return;
    }
}

int movimentar(int* linha, int* coluna, matrizFazenda* matriz){

    int linhaOriginal = *linha;
    int colunaOriginal = *coluna;

    int* vetorFibonnaci = sequencia(matriz->linhas * matriz->colunas); // Salvando sequencia da sequencia de Fibonnaci

    if(*linha == matriz->linhas-1){ //condicao de parada final
        return TRUE;
    }   

    for(int i = 0; i < 4; i++){ 

        atualizaPosicao(linha, coluna, i); // muda o valor das variaveis linha e coluna

        if( matriz->matrizOriginal[*linha][*coluna] ==  vetorFibonnaci[matriz->caminhosPercorridos] && matriz->matrizPercorrida[*linha][*coluna] != 0){ //Se o lugar que ira andar == a sequencia
            if( movimentar(linha, coluna, matriz )){ //
                return TRUE;
            }
        }

        *linha = linhaOriginal;
        *coluna = colunaOriginal;
        
    }
}