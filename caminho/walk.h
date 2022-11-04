#include "../sequenciaFibonacci/seq.h"
#include "../MatrizFazenda/matrizFazenda.h"

#define TRUE 1
#define FALSE 0
void caminhar();

int movimentar(int* linha, int* coluna, matrizFazenda* matriz, int* sequenciaFibonnaci, int contador);

void atualizaPosicao(int *linha, int *coluna, int opcao);

int verificaLimite(int linha, int coluna, matrizFazenda* matriz);