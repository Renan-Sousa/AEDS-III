#ifndef SHIFTAND_H_INCLUDED
#define SHIFTAND_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// Função que criar a máscara de bits
int* create_mask(char* pattern, int m, int begin);

// Algoritmo Shift-And
int shift_and(char* text, int n, char* pattern, int m);

#endif