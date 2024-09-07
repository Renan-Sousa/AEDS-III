#include "bruteForce.h"

/* Algoritmo Força Bruta para casamento de padrão */
int bruteForce(char* text, int n, char* pattern, int m) {
    // Indices do padrão e texto
    int j, k;
    
    // Calcula a posição do casamento para o padrão normal
    for (int i = 0; i < n-m+1; i++) {
        k = i; 
        j = 0;

        // Enquanto os caracteres casarem os indices incrementam, pecorrendo o padrão e o texto
        while (text[k] == pattern[j]) {
            j++;
            k++;
        }

        // Se 
        if(j==m)
            return i+1;
    }

    // Se não encontra para o padrão normal, calcula a posição do casamento para o padrão invertido
    for (int i = n-1; i >= m-1; i--) {
        k = i; 
        j = 0;

        // 
        while (k>=0 && text[k] == pattern[j]) {
            j++;
            k--;
        }

        // 
        if(j==m)
            return i+1;
    }

    // Retorna 0 quando não há casamento
    return 0;
}
