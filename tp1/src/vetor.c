#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

Ponto *alocar_vetor(int tam) {
    Ponto *vetor;
    // Aloca dinâmicamente um vetor de pontos de tamanho 'tam'
    vetor = (Ponto *) malloc(tam * sizeof(Ponto));
    return vetor;
}


// Função para criar vetor de Pontos
Ponto *criar_vetor(FILE *fp, int n) {
    // armazena os valores lidos no arquivo
    int x, y;   

    // Chama a função para alocar um vetor de tamanho 'n'
    Ponto *pontos = alocar_vetor(n);
    
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d %d", &x, &y);  // lê os pares de inteiros
        pontos[i].x = x;  // atribui o valor de x na coordenada x do ponto
        pontos[i].y = y;  // atribui o valor de y na coordenada y do ponto
        pontos[i].cont = 0;  // inicializa todos os contadores dos pontos com '0'
    }

    return pontos; // retorna o vetor de pontos
}


// Função que cria um ponto (âncoras)
Ponto criar_ancora(int x) {
    Ponto P;  // Criar um ponto P

    // Inicializa as coordenadas x = parâmetro e y = 0
    P.x = x;
    P.y = 0;
    return P;
}

// Função para trocar a posição de dois pontos do vetor
void troca(Ponto *p1, Ponto *p2) {
    Ponto temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int particao(Ponto *vetor, int inicio, int fim) {
    // Escolhe o último ponto do vetor como pivô
    Ponto pivo = vetor[fim];

    int i = inicio; // indice do inicio do vetor

    // Percorre todo o vetor e rearranja os pontos do vetor em relação ao pivô
    for (int j = inicio; j < fim; j++) {
        if (vetor[j].y < pivo.y) {
            // Se o valor de 'y' do ponto atual for menor que o valor de 'y' do pivô, troca os pontos de posição no vetor
            troca(&vetor[i], &vetor[j]);
            i++;
        } 
    }

    troca(&vetor[i], &vetor[fim]); // coloca o pivô na posição correta
    return i; // retorna a posição final do pivô
}

// Função que realiza a ordenação recursiva do vetor
void quickSort(Ponto *vetor, int inicio, int fim) {
    // Verifica se ainda há elementos no vetor para ordenar
    if (inicio < fim) {
        int part = particao(vetor, inicio, fim); // Chama a função de partição para obter o novo ponto de particionamento
        quickSort(vetor, inicio, part - 1); // Chama recursivamente o quickSort para ordenar o lado esquerdo
        quickSort(vetor, part + 1, fim); // Chama recursivamente o quickSort para ordenar o direito
    }
}

