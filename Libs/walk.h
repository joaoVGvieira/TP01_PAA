#include "seq.h"
#include "matrizFazenda.h"

#define TRUE 1
#define FALSE 0
void caminhar();

int movimentar(int* linha, int* coluna, matrizFazenda* matriz, int* sequenciaFibonnaci, int contador,int *contChamadas, int* maxProfundidade);

void atualizaPosicao(int *linha, int *coluna, int opcao);

int verificaLimite(int linha, int coluna, matrizFazenda* matriz);

void Imprimircaminho(int* linha, int* coluna, matrizFazenda* matriz);
