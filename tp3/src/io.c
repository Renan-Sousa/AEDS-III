#include "io.h"

// Função que realiza a leitura do arquivo e aloca as strings padrão e texto
char* createString(FILE *input, int* size, int m, int max) {
    // Variáveis para armazenar o caractere lido e o caractere de parada
    char c, endString;
    
    // Aloca espaço para armazenar a string
    char *string = (char*) malloc((max+1) * sizeof(char));
    

    // Define o caractere de término da string com base no valor de m (Tamanho do padrão)
    // Se o padrão é igual a 0, então ele não existe e a leitura vai até encontrar um espaço
    // Se o padrão existe então e lido o texto e a leitura vai até a quebra de linha
    if (m == 0)
        endString = ' ';
    else
        endString = '\n';
    
    int i = 0;
    
    // Lê caracteres do arquivo de entrada até encontrar o caractere que representa o fim da string   
    while (fscanf(input, "%c", &c) == 1 && c != endString) {
        string[i] = c;
        i++;
    }
    
    // Para criar a circularidade do texto, copia m-1 caracteres do início da string para o final
    for (int k = 0; k < m-1 ; k++) {
        string[i] = string[k];
        i++;
    }

    // Adiciona o caractere do fim da string
    string[i] = '\0';
    
    // Atualiza o tamanho da string
    *size = i;

    // Realoca a memória para o tamanho correto da string
    string = (char*) realloc(string, (i+1) * sizeof(char));
    
    return string;
}






/* OUTPUT */
void output(FILE* out, int index) {
    if(index > 0)
        //fprintf(out, "S %d\n", index);
        printf("S %d\n", index);
    else 
        //fprintf(out, "N\n");
        printf("N\n");
}
