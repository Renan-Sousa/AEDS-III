#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// Essa função realiza a leitura do arquivo e aloca as strings padrão e texto
char* createString(FILE *input, int* size, int m, int max); 

// Essa função 
void output(FILE* out, int index);

#endif