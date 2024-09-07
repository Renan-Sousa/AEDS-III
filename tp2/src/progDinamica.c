#include "progDinamica.h"

// Função que calcula a vida mínima quando aponta apenas para uma casa
int valorUnico(int valorPD, int valorOriginal) {
    // Calcula a vida mínima necessária 
    int calculo = valorPD - valorOriginal;

    // Se a vida mínima for menor ou igual a zero, define o valor mínimo como 1, que é o limite inferior de vida
    if (calculo <= 0) 
        calculo = 1;

    return calculo;
}

// Função que recebe os valores das casa à direita e abaixo da matrizPD e a vida ganha ou perdida.
int compararValores(int dir, int abx, int valorOriginal) {
    int minimo;
    
    // Calcula a vida mínima necessária para cada caminho possível
    int direita = dir - valorOriginal;
    int abaixo = abx - valorOriginal;

    // Seleciona o menor valor como a vida mínima necessária
    if (direita < abaixo) 
        minimo = direita;
    else 
        minimo = abaixo;
    
    // Se a vida mínima for menor ou igual a zero, define o valor mínimo como 1, que é o limite inferior de vida
    if (minimo <= 0) 
        minimo = 1;

    return minimo;
}

// Função calcula a solução e retorna a vida mínima
int vidaMinimaPD (Matriz matriz, Matriz matrizPD) {
    // Valor da vida minima (solução)
    int vidaMin;

    // Número de linhas e colunas da matriz
    int linhas = matriz.linha;
    int colunas = matriz.coluna;
    
    // Percorre as matrizes de valor e programação dinâmica calculando as vidas mínimas
    for (int l = linhas; l >= 1; l--) {
        for (int c = colunas; c >= 1; c--) {
            // Caso base. Último espaço da matriz, a vida minima para chegar no destino é 1
            if (l == linhas && c == colunas) 
                matrizPD.valor[l][c] = 1; 
               
            // Cada espaço da última linha aponta apenas para a casa da direita. Acessa a casa da [linhas][c+1]
            else if (l == linhas && c != colunas) 
                matrizPD.valor[l][c] = valorUnico(matrizPD.valor[l][c+1], matriz.valor[l][c]);
            
            // Cada espaço da última coluna aponta apenas para a casa abaixo. Acessa a casa da [l+1][coluna]
            else if (l != linhas && c == colunas) 
                matrizPD.valor[l][c] = valorUnico(matrizPD.valor[l+1][c], matriz.valor[l][c]);

            // As casas restantes da matriz apontam para duas casas, à direita e abaixo. Deve comparar e escolher a mínima  
            else 
                matrizPD.valor[l][c] = compararValores(matrizPD.valor[l][c+1], matrizPD.valor[l+1][c], matriz.valor[l][c]);
        }
    }

    // Retorna a vida mínima da primeira posição da matrizPD
    vidaMin = matrizPD.valor[1][1];

    return vidaMin;
}
