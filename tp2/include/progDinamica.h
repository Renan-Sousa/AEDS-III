#ifndef progDinamica_H_INCLUDED
#define progDinamica_H_INCLUDED

#include "matriz.h"

// Função que calcula a vida mínima quando só pode mover para uma direção
int valorUnico(int valorPD, int valorOriginal); 

// Função que calcula a vida mínima e escolhe o melhor caminho qaundo pode se mover para duas dimensões
int compararValores(int dir, int abx, int valorMatriz);

// Função que encontra a vida mínima necessária para chegar com vida positiva no fim do grid por programação dinâmica.
int vidaMinimaPD (Matriz matriz, Matriz matrizPD);

#endif