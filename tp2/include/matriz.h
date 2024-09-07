#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

// A estrutura Matriz armazena os valores da dimensão (número de linhas e colunas). 
// O atributo "valor" representa a própria matriz, em que cada elemento contém um valor inteiro
typedef struct {
    int linha;
    int coluna;
    int** valor;
} Matriz;

// Função que aloca dinâmicamente uma matriz com as dimensões lidas no arquivo
Matriz alocarMatriz (int linhas, int colunas);

// Função que lê o arquivo e atribui os valores para cada espaço da matriz
Matriz criarMatriz(FILE *entrada);

// Criar a matriz da programação dinâmica
Matriz criarMatrizPD(Matriz matriz);

// Função que libera as estruturas alocadas
void freeMatriz(Matriz matriz);

#endif
