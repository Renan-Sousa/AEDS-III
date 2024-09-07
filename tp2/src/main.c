#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"
#include "progDinamica.h"
#include "recursividade.h"
#include "tempo.h"

int main(int argc, char const **argv) {
    (void)argc;
    FILE *entrada, *saida;     // arquivos de entrada e saída, respectivamente
    int T;                     // número de "grids" no arquivo
    int vidaMin;               // vida minima (solução)
    Matriz matriz;             // matriz que representa o grid com os valores do arquivo

    // Funções de medir tempo (getrusage)
    struct rusage start, end;
    getrusage(RUSAGE_SELF, &start);

    entrada = fopen(argv[2], "r");
    saida = fopen("saida.txt", "w+");

    int solucao = atoi(argv[1]);    
    
    // Se a solução escolhida for "1" resolve o problema por recursividade
    if (solucao == 1) {
        fscanf(entrada, "%d", &T);
        for (int x = 0; x < T; x++) {
            matriz = criarMatriz(entrada);       // lê o arquivo e cria o "grid mágico"
            vidaMin = vida_minima(matriz,1,1);   // resolve o problema por programação dinâmica
            fprintf(saida, "%d\n", vidaMin);     // imprime as soluções no arquivo de saída
            freeMatriz(matriz);                  // libera a matriz
        }   
    }

    // Se a solução escolhida for "2" resolve o problema por programação dinâmica
    if (solucao == 2) {
        fscanf(entrada, "%d", &T);
        for (int x = 0; x < T; x++) {
            Matriz matrizPD;                           // matriz usada na programação dinâmica para guardar a vida minima
            matriz = criarMatriz(entrada);             // lê o arquivo e cria o "grid mágico"
            matrizPD = criarMatrizPD(matriz);          // cria a matriz da programação dinâmica
            vidaMin = vidaMinimaPD(matriz, matrizPD);  // resolve o problema por programação dinâmica
            fprintf(saida, "%d\n", vidaMin);           // imprime as soluções no arquivo de saída
            freeMatriz(matriz);                        // libera a matriz
            freeMatriz(matrizPD);                      // libera a matrizPD
        }
    }

    fclose(saida);
    fclose(entrada);

    getrusage(RUSAGE_SELF, &end);
    printf("CPU tempo: %.06f sec usuário, %.06f sec sistema\n", diffUserTime(&start, &end), diffSystemTime(&start, &end));

    return 0;
}
