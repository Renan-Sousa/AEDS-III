#include "shiftAnd.h"

#define ALPHABET 26

// Função que criar a máscara de bits
int* create_mask(char* pattern, int m, int begin) {
    // Aloca espaço para armazenar a máscara
    int* mask = (int*) malloc((ALPHABET+1) * sizeof(int));

    // Inicializa todas posições como 0
    for (int k = 0; k <= ALPHABET; k++) {
        mask[k] = 0;
    }

    // Decide se a máscara é feita para o padrão normal ou invertido
    // begin = 0 padrão normal | else padrão invertido
    if (begin == 0) {
        for (int j = 0; j < m; j++) {
            int index = pattern[j] - 'a'; // Calcula o índice correspondente à letra do padrão
            mask[index] |= (1 << (m-1-j)); // Define o bit correspondente à posição j
        }
    }
    else {
        for (int j = m-1; j >= 0; j--) {
            int index = pattern[j] - 'a';
            mask[index] |= (1 << (j));
        }
    }

    return mask;
}

int shift_and(char* text, int n, char* pattern, int m) {
    // chama a função de criar a máscara
    int* mask = create_mask(pattern, m, 0);

    int R = 0;
    int Rline = 0; 
    
    // Realiza o algoritmo shift and para o padrão normal
    for (int i = 0; i < n; i++) {
        R = Rline >> 1 | (1 << (m-1));
        Rline = R & mask[text[i]-'a'];
        // se o ultimo bit de R' chega ao fim houve casamento exato e retorna a posição
        if(Rline & 1 == 1) {
            free(mask);
            return i-m+2;
        }
    }
    free(mask);

    // cria a máscara para o padrão invertido
    mask = create_mask(pattern, m, m);

    R = 0;
    Rline = 0; 
    
    // Realiza o algoritmo shift and para o padrão invertido
    for (int i = 0; i < n; i++) {
        R = Rline >> 1 | (1 << (m-1));
        Rline = R & mask[text[i]-'a'];
        // se o ultimo bit de R' chega ao fim houve casamento exato e retorna a posição
        if(Rline & 1 == 1) {  
            free(mask);
            return i+1;
        }
    }
    free(mask);     
    
    // se não houver casamento retorna -
    return -1;
}
