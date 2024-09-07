/* Trabalho feito por RENAN RODRIGUES SOUSA e ADÉLSON OLIVEIRA DO CARMO JÚNIOR */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vetor.h"
#include "contador.h"
#include "tempo.h"

//////////////////////////////////////////////////////////////////////

int main(int argc, char const **argv) {

    (void)argc;

    FILE *in, *out;             // arquivos de entrada e saída
    Ponto A, B;                 // âncoras
    Ponto *pontos;              // vetor de pontos
    int n, xA, xB, resultado;   // número de pontos, coordenada x da âncora A, coordenada x da âncora B, resultado

    // Funções de medir tempo (getrusage)
    /* struct rusage start, end;
    getrusage(RUSAGE_SELF, &start); */
    
    in = fopen(argv[2], "r");
    out = fopen(argv[4], "w+");

    while (fscanf(in, "%d %d %d", &n, &xA, &xB) == 3) { 

        /* Cria as âncora A e B */
        A = criar_ancora(xA);
        B = criar_ancora(xB);

        pontos = criar_vetor(in, n);  // Aloca e cria o vetor 
        quickSort(pontos, 0, n-1);  // Ordena o vetor com o QuickSort
        
        resultado = maximo_pontos(A, B, pontos, n);  // Encontra o máximo de pontos
        fprintf(out, "%d\n", resultado);  //Imprime o resultado em um arquivo

        free(pontos);  // Libera o vetor de pontos 
    }
    fclose(out);
    fclose(in);

    /* getrusage(RUSAGE_SELF, &end);
    printf("CPU tempo: %.06f sec usuário, %.06f sec sistema\n", diffUserTime(&start, &end), diffSystemTime(&start, &end)); */

    return 0;
}
