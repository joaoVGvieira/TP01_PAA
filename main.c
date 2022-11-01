#include <stdio.h>
#include <stdlib.h>
int main(){
   FILE *arq;
    int **mat;
    char nome_arquivo[1000];
    int i,j,opc;
    int l,c;
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
            if ((arq=fopen (nome_arquivo,"r"))==NULL){
                printf ("\nErro na abertura do arquivo.\n");
            }
                
            else{
                printf("\nArquivo aberto com sucesso.\n");
                fscanf(arq, "%d %d\n",&l,&c);
                mat = malloc (l * sizeof (int*)) ;
                for (i=0; i < l; i++)
                    mat[i] = malloc (c * sizeof (int)) ;
                for(i=0;i<l;i++){
                    for(j=0;j<c;j++){
                        fscanf(arq,"%d ", &mat[i][j]);
                    }    
                }
            }
            break;
        case 2:
         if (arq!=NULL)
         {
            printf("\nAREA MAPEADA:\n\n");
             for(int i=0;i<l;i++){
                for(int j=0;j<c;j++){
                    printf("%d ",mat[i][j]);
                } 
            printf("\n");   
            }
         }  
        break;
        case 0 :
            break;
        default:
            printf("OPCAO INVALIDA!!!!");
            break;
        }
    } while (opc!=0);
}
   