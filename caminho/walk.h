#include "../sequenciaFibonacci/seq.h"
#include "../leituraArquivo/read.h"
#include "../MatrizFazenda/matrizFazenda.h"

#define TRUE 1
#define FALSE 0
void caminhar();

int movimentar(int* linha, int* coluna, matrizFazenda* matriz);

void atualizaPosicao(int *linha, int *coluna, int opcao);
