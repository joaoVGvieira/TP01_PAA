#include "sequenciaFibonacci/seq.h"
#include "caminho/walk.h"
int main() {
    matrizFazenda *matriz;
    char nome_arquivo[1000];
    int opc,tamanho;
    int* vetor;
    do
    {
        printf("\n");
        printf(
          " _________________(MENU PRINCIPAL)___________________ \n"
          "|                                                    |\n"
          "| LER ARQUIVO = 1                                    |\n"
          "| CALCULAR E IMPRIMIR CAMINHO = 2                    |\n"
          "| MATRIZ PERCORRIDA (PARA TESTE)  = 3                |\n"                    
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
            break;
        case 2:
            vetor = sequencia(500);
            int b = 0;
            for ( int i = 0; i < matriz->colunas; i++ ) {
                int a = i;
                if ( matriz->matrizOriginal[0][i] == 1 ){
                    int resultado = movimentar( &b, &a, matriz, vetor, 1 );
                    if ( resultado == TRUE ) {
                        matriz->matrizPercorrida[0][i] = 1;
                        break; 
                    }  
                } 
            }
            Imprimircaminho(&matriz->linhas,&matriz->colunas,matriz);
            break;
            case 3:
                for(int i=0;i<matriz->linhas;i++){
                for(int j=0;j<matriz->colunas;j++){
                    printf("%-2d ",matriz->matrizPercorrida[i][j]);
                } 
                printf("\n");
             }
                break;
        case 0 :
            printf("\nVOLTE SEMPRE!\n");
            break;
        default:
            printf("OPCAO INVALIDA!!!!");
            break;
        }
    } while (opc!=0);
    
   

    return 0;
}