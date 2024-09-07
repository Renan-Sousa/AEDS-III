#ifndef CONTADOR_H_INCLUDED
#define CONTADOR_H_INCLUDED

#include "vetor.h"

/* Função que calcula a área de um triângulo a partir dos três vértices*/
float area(Ponto A, Ponto B, Ponto P);

/* Função que conta quanto pontos tem dentro de um triângulo formado entre as âncoras e um ponto no plano */
int contagem(Ponto A, Ponto B, Ponto *vetor, int indice);

/* Função que analisa se um ponto P está dentro do triângulo formado por A, B e C */
bool dentro_triangulo(Ponto A, Ponto B, Ponto C, Ponto P);

/* Teste os pontos retorna o máximo de pontos que se conectam somente nas âncoras */
int maximo_pontos(Ponto A, Ponto B, Ponto *V, int tam);

#endif