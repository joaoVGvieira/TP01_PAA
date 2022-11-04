#include "read.h"

infoArquivo *leitura( char* caminhoArquivo ){
    
    FILE *arq;
    infoArquivo *info; // Para termos linhas e colunas do arquivo armazenadas
    info = (infoArquivo*)malloc(sizeof(infoArquivo));

    arq = fopen( caminhoArquivo, "r" );
    if ( arq == NULL ) {
        printf("\nARQUIVO NAO ENCONTRADO\n");
    }
    else {
        printf("\nLEITURA DE ARQUIVO FEITA COM SUCESSO!\n");
        fscanf( arq, "%d %d", &info->qntdLinhas, &info->qntdColunas ); // lendo qntdLinhas e qntdColunas
        // no arquivo separado por espaço
        
        info->mat = ( int ** )malloc( sizeof( int ) * info->qntdLinhas * 2 );
        for ( int i = 0; i < info->qntdLinhas; i++ ){
            info->mat[i] = ( int * )malloc( sizeof( int ) * info->qntdColunas * 2 );

            for ( int j = 0; j < info->qntdColunas; j++ ) {
                int valor;
                
                if ( j < info->qntdColunas - 1 ) { // Lendo os valores no arquivo
                    fscanf( arq, "%d ", &valor );
                }
                else { // Lendo o último valor no arquivo
                    fscanf( arq, "%d", &valor );
                }
                info->mat[i][j] = valor;
            }
        }
    }
    fclose( arq );
    return info;
}

void imprimir_matriz( infoArquivo *info ){
        printf("\nAREA MAPEADA:\n\n");
             for(int i=0;i<info->qntdLinhas;i++){
                for(int j=0;j<info->qntdColunas;j++){
                    printf("%d ",info->mat[i][j]);
                } 
            printf("\n");   
        }
}