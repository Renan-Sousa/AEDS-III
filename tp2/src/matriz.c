#include "matriz.h"

// Alocação de dinâmica de matriz
Matriz alocarMatriz(int linhas, int colunas) {
    //Matriz que será alocada e retornada
    Matriz matriz;   

    // Matriz recebe as dimensões
    matriz.linha = linhas;
    matriz.coluna = colunas;    

    // Alocar um vetor de dimesão número de linhas da matriz +1
    matriz.valor = malloc(sizeof(int*) * (matriz.linha+1) );

    // Para cada espaço do vetor aloca um novo vetor de dimensão número de colunas da matriz +1
    // Cria uma matriz de dimensão (linha+1,coluna+1)
    for (int i = 0; i <= matriz.linha; i++) {
        matriz.valor[i] = malloc(sizeof(int) * (matriz.coluna+1) );
    }
    
    return matriz;
}

Matriz criarMatriz(FILE *entrada) {
    int linhas, colunas;
    // Lê as dimensões da matriz e guarda os números de linhas e colunas
    fscanf(entrada, "%d %d", &linhas, &colunas);

    // Chama a função de alocação e aloca uma matriz
    Matriz matriz = alocarMatriz(linhas, colunas);
    
    // Guarda o valor do espaço da matriz lido no arquivo
    int valor;  

    // Percorre a matriz criada, atribuindo os valores do arquivo para cada espaço da matriz.
    for (int l = 0; l <= matriz.linha; l++) {
        for (int c = 0; c <= matriz.coluna; c++) {
            // Preenche a primeira linha e primeira coluna com 0. Elas nunca são acessadas.
            // Estas linhas e colunas servem somente para que o personagem comece na coordenada (1,1)
            if (l == 0 || c == 0) {
                matriz.valor[l][c] = 0;
            }
            // o restante da matriz recebe os valores do arquivo
            else {
                fscanf(entrada, "%d", &valor);
                matriz.valor[l][c] = valor;
            }
        }   
    }
    
    return matriz;
}

Matriz criarMatrizPD(Matriz matriz) {
    // Chama a função de alocação e aloca uma matriz
    Matriz matrizPD = alocarMatriz(matriz.linha, matriz.coluna);
    
    // Percorre a matriz criada inicializando todos os valores como 0
    for (int l = 0; l <= matriz.linha; l++) {
        for (int c = 0; c <= matriz.coluna; c++) {
            matrizPD.valor[l][c] = 0;
        }   
    }
    
    return matrizPD;
}

// Função que libera as estruturas alocadas
void freeMatriz(Matriz matriz) {
    for (int i = 0; i <= matriz.linha; i++) {
        // Percorre as linhas liberando todas as colunas
        free(matriz.valor[i]);
    }
    // Libera as linhas
    free(matriz.valor);
}