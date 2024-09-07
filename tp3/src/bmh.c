#include <stdio.h>
#include <stdlib.h>

#include "bmh.h"

#define ALPHABET 26

int* shift_table(char* text, char* pattern, int m) {
    /* Cria a Shift Table */
    int* table = (int*) malloc((ALPHABET+1) * sizeof(int));
    
    /* Inicializa todas as posições com o tamnho do padrão */
    for (int j = 0; j <= ALPHABET; j++) {
        table[j] = m;
    }
   
    /* Calcula os valores de shift para os caracteres do padrão */
    for (int j = 0; j < m-1; j++) {
        int index = pattern[j] - 'a';
        table[index] = m-1-j;
    }

    return table;
}

int bmh(char* text, int n, char* pattern, int m) {
    int* table = shift_table(text, pattern, m);
    
    /* Algoritmo BMH para encontrar a posição do casamento com o padrão normal */
    int i = m-1;
    while (i <= n-1) { 
        int k = i; 
        int j = m-1; 

        while (j>=0 && text[k] == pattern[j]) {
            k--;
            j--; 
        }
        
        if(j == -1) {
            free(table);
            return k+2;
        }

        i = i + table[text[i]-'a'];
    }

    /* Algoritmo BMH para encontrar a posição do casamento com o padrão invertido */
    i = m-1;
    while (i <= n-1) { 
        int k = i;
        int j = 0;

        while (j<m && text[k] == pattern[j]) {
            k--;
            j++; 
        }
        
        if(j == m) {
            free(table);
            return k+m+1;
        }

        i = i + table[text[i]-'a'];
    }

    free(table);
    return -1;
}
