#include "../Libs/matrizFazenda.h"

matrizFazenda *leitura( char* caminhoArquivo ){
    
    FILE *arq;
    matrizFazenda *matriz; // Para termos linhas e colunas do arquivo armazenadas
    matriz = (matrizFazenda*)malloc(sizeof(matrizFazenda));

    arq = fopen( caminhoArquivo, "r" );
    if ( arq == NULL ) {
        printf("\nARQUIVO NAO ENCONTRADO\n");
    }
    else {
        printf("\nLEITURA DE ARQUIVO FEITA COM SUCESSO!\n");
        fscanf( arq, "%d %d", &matriz->linhas, &matriz->colunas ); // lendo linhas e colunas
        // no arquivo separado por espaço
        
        matriz->matrizOriginal = ( int ** )malloc( sizeof( int ) * matriz->linhas * 2 );
        for ( int i = 0; i < matriz->linhas; i++ ){
            matriz->matrizOriginal[i] = ( int * )malloc( sizeof( int ) * matriz->colunas * 2 );

            for ( int j = 0; j < matriz->colunas; j++ ) {
                int valor;
                
                if ( j < matriz->colunas - 1 ) { // Lendo os valores no arquivo
                    fscanf( arq, "%d ", &valor );
                }
                else { // Lendo o último valor no arquivo
                    fscanf( arq, "%d", &valor );
                }
                matriz->matrizOriginal[i][j] = valor;
            }
        }
    }
    
    matriz->matrizPercorrida = ( int ** )malloc( sizeof( int ) * matriz->linhas * 2 );
    for ( int i = 0; i < matriz->linhas; i++ ){
            matriz->matrizPercorrida[i] = ( int * )malloc( sizeof( int ) * matriz->colunas * 2 );
    }
    for( int i=0;i<matriz->linhas;i++ ){
                for( int j=0;j<matriz->colunas;j++ ){
                    matriz->matrizPercorrida[i][j] = 0;
                }
    }
    fclose( arq );
    return matriz;
}

void imprimir_matriz( matrizFazenda *matriz ){
        printf("\nAREA MAPEADA:\n\n");
             for(int i=0;i<matriz->linhas;i++){
                for(int j=0;j<matriz->colunas;j++){
                    printf("%d ",matriz->matrizOriginal[i][j]);
                } 
            printf("\n");   
        }
}