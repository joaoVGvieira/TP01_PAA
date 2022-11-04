

typedef struct matrizFazenda{

    int linhas; 
    int colunas;
    int **matrizOriginal; //matriz lida do arquivo, nao ira mudar
    int **matrizPercorrida; // matriz zerada, que sera preenchida com a ordem da colheita das batatas
    int caminhosPercorridos; // numero de campos de batats colhidos

}matrizFazenda;