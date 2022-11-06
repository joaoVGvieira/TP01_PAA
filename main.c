#include <time.h>
#include "Libs/seq.h"
#include "Libs/walk.h"
int main() {
    matrizFazenda *matriz;
    clock_t tempo_execu;
    float tempoTotal;
    int contChamadas, maxProfundidade;
    tempo_execu = clock();
    char nome_arquivo[1000];
    int opc,tamanho;
    int caminhoCalculado=FALSE;
    int* vetor;
    do
    {
        printf("\n");
        printf(
          " _________________(MENU PRINCIPAL)___________________ \n"
          "|                                                    |\n"
          "| LER ARQUIVO = 1                                    |\n"
          "| CALCULAR E IMPRIMIR CAMINHO = 2                    |\n"
          "| IMPRIMIR CAMINHO EM FORMA DE MATRIZ = 3            |\n"
          "| DADOS DO MODO ANALISE = 4                          |\n"
          "| ENCERRAR OPERACOES = 0                             |\n"
          "|____________________________________________________|\n\n");
        printf("DIGITE A OPERACAO DESEJADA: ");
        scanf("%d",&opc);
        switch (opc)
        {
        case 1 :
            printf("\nDIGITE O NOME DO ARQUIVO DE ENTRADA: ");
            scanf(" %[^\n]s ",nome_arquivo);
            matriz = leitura(nome_arquivo);
            contChamadas = 0;
            maxProfundidade = 0;
            caminhoCalculado = FALSE;
            break;
        case 2:
            if (matriz->matrizOriginal!=NULL && caminhoCalculado == FALSE)
            {
                tempo_execu = clock();
                vetor = sequencia(500);
                int b = 0;
                for ( int i = 0; i < matriz->colunas; i++ ) {
                    int a = i;
                    if ( matriz->matrizOriginal[0][i] == 1 ){
                        int resultado = movimentar( &b, &a, matriz, vetor, 1,&contChamadas, &maxProfundidade);
                        if ( resultado == TRUE ) {
                            matriz->matrizPercorrida[0][i] = 1;
                            break; 
                        }  
                    } 
                }
                Imprimircaminho(&matriz->linhas,&matriz->colunas,matriz);
                tempo_execu =  clock() - tempo_execu;
                tempoTotal = ((float)tempo_execu)/((float)CLOCKS_PER_SEC);
                caminhoCalculado = TRUE;
                break;
            }else
            {
                printf("\nNENHUM ARQUIVO LIDO OU CAMINHO JA FOI CALCULADO!\n");
            }
            break;
        case 4:
            if (contChamadas!=0 || maxProfundidade!=0 || vetor != NULL)
            {
                printf("\n\n------- RESULTADO DO MODO ANALISE -------\n\n");
                printf("Nome do arquivo analisado: %s\n",nome_arquivo);
                printf("Tempo de Execucao: %f segundos\n",tempoTotal);
                printf("Numeros de Chamadas Recursivas:%d \n",contChamadas);
                printf("Numero maximo de Recursao:%d \n",maxProfundidade);
            }else
            {
                printf("\nSEM DADOS PARA SER ANALISADOS!!! CALCULE O CAMINHO PRIMEIRO!!!\n");
            }
            break;
        case 3:
            printf("\n\n    ----- RESULTADO EM MATRIZ CAMINHO PERCORRIDO ----\n\n");
                for(int i=0;i<matriz->linhas;i++){
                    for(int j=0;j<matriz->colunas;j++){
                    printf("%-2d ",matriz->matrizPercorrida[i][j]);
                } 
                printf("\n");
             }
             printf("\nOBS: Se a matriz estiver zerada e porque nao possui solucao!\n");
            break;
        case 0 :
            printf("\nPROGRAMA ENCERRADO!\n\n");
            break;
        default:
            printf("\nOPCAO INVALIDA!!!!\n");
            break;
        }
    } while (opc!=0);
    return 0;
}