#include "leituraArquivo/read.h"
#include "sequenciaFibonacci/seq.h"
int main() {
    infoArquivo *info;
    char nome_arquivo[1000];
    int opc;
    do
    {
        printf("\n");
        printf(
          " _________________(MENU PRINCIPAL)___________________ \n"
          "|                                                    |\n"
          "| LER ARQUIVO = 1                                    |\n"
          "| IMPRIMIR MATRIZ = 2                                |\n"       
          "| ENCERRAR OPERACOES = 0                             |\n"
          "|____________________________________________________|\n\n");
        printf("DIGITE A OPERACAO DESEJADA: ");
        scanf("%d",&opc);
        switch (opc)
        {
        case 1 :
            printf("\nDIGITE O NOME DO ARQUIVO DE ENTRADA: ");
            scanf(" %[^\n]s ",nome_arquivo);
            info = leitura(nome_arquivo);
            break;
        case 2:
         if (info->mat!=NULL)
         {
                imprimir_matriz(info);
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