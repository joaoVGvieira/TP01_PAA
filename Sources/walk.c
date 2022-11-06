#include "../Libs/walk.h"


void atualizaPosicao(int *linha, int *coluna, int opcao){
    if(opcao == 0){ // baixo
        *linha+=1;
        return;
    }else if(opcao == 1){ // direita
        *coluna+=1;
        return;
    }else if(opcao == 2){ // esquerda
        *coluna-=1;
        return;
    }else if(opcao == 3){ //cima
        *linha -=1;
        return;
    }
}

//TODO condicao para nao tentar movimentar em alg posicao nao existente na matriz

int movimentar(int* linha, int* coluna, matrizFazenda* matriz, int* sequenciaFibonnaci, int contador, int *contChamadas, int* maxProfundidade){

    *contChamadas = *contChamadas + 1;
    if(contador > *maxProfundidade){
        *maxProfundidade = contador;
    }
    
    int linhaOriginal = *linha; // tem que começar do 1
    int colunaOriginal = *coluna; // tem que começar do 1
    // int* sequenciaFibonnaci = sequencia(matriz->linhas * matriz->colunas); // Salvando sequencia da sequencia de Fibonnaci

    if(*linha == matriz->linhas-1){ //condicao de parada final
        return TRUE;
    }   
    
    for(int i = 0; i < 4; i++){ 

        atualizaPosicao(linha, coluna, i); // muda o valor das variaveis linha e coluna
        if(verificaLimite(*linha, *coluna, matriz)){ // verifica se é a borda da matriz
            if( matriz->matrizOriginal[*linha][*coluna] ==  sequenciaFibonnaci[contador]){ //Se o lugar que ira andar == a sequencia
                if( matriz->matrizPercorrida[*linha][*coluna] == 0 ){ // Verifica se o lugar ja foi percorrido
                    matriz->matrizPercorrida[*linha][*coluna] = contador+1; // Salva na matriz percorrida o numero que visitou
                    if( movimentar(linha, coluna, matriz, sequenciaFibonnaci, contador+1,contChamadas, maxProfundidade) ){ // Verifica para essa posicao se o movimentar é verdadeiro
                        return TRUE;
                    }
                }
            }
        }
        //voltando para os valores originais se o movimentar n der certo
        
        *linha = linhaOriginal; 
        *coluna = colunaOriginal;
         
        
    }
    matriz->matrizPercorrida[*linha][*coluna] = 0; 
    return FALSE;
}

int verificaLimite(int linha, int coluna, matrizFazenda* matriz) {
    if ( linha >= 0 && linha < matriz->linhas && coluna >= 0 && coluna < matriz->colunas ) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

void Imprimircaminho(int* linha, int* coluna, matrizFazenda* matriz){
    int cont = 0;
    int max =  (*linha)*(*coluna);
    int cont2= 1;
    for (int i = 0; i < *linha; i++)
    {
        for (int j = 0; j < *coluna; j++)
        {
            if (matriz->matrizPercorrida[i][j] == 0)
            {
                cont++;
            }
            
        }
        
    }
    if (max ==cont)
    {
        printf("\nIMPOSSÍVEL!\n");
        return;
    }else
    {
        for (int i = 0; i < matriz->linhas; i++)
            {
                for (int j = 0; j < matriz->colunas; j++)
                {
                    if (matriz->matrizPercorrida[i][j] == cont2)
                    {
                        printf("%d %d\n",i+1,j+1);
                        i =0;
                        j=0;
                        cont2++;
                    }
            
                }
            }
    }
}
