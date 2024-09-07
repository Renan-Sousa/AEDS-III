#include "recursividade.h"

int vida_minima(Matriz matriz, int l, int c){
    // Inicializa as variáveis que vão navegar pela esquerda ou para baixo e a que guarda o menor valor
    int direita, baixo, menor_valor;

    // Se a posição atual da matriz for em alguma borda, faz com que ela retorne um valor suficientemente
    // grande, para que na hora da seleção, ele seja descartado
    if(l == matriz.linha+1 || c == matriz.coluna+1) 
        return 1000000;
    
    // Condição de parada, sinaliza que esse é o limite e retorna o oposto do valor em caso de negativo
    // ou 1 em caso de positivo
    if(l == matriz.linha && c == matriz.coluna) {
        if(matriz.valor[l][c] < 0)
            return - matriz.valor[l][c]+1;
        else
            return 1;
    }

    direita = vida_minima(matriz,l,c+1);    //variável que chama a função a fim de navegar pela direita
    baixo = vida_minima(matriz,l+1,c);      //variável que chama a função a fim de navegar para baixo
    
    // Seleciona a menor dentre as duas navegações e a soma do oposto do valor naquela posição
    if(direita < baixo)
        menor_valor = direita - matriz.valor[l][c];
    else
        menor_valor = baixo - matriz.valor[l][c];

    // Caso o valor encontrado anteriormente seja positivo ele é devolvido, enquanto que no caso de ele
    // ser negativo ou igual a 0, ele retornará 1
    if(menor_valor > 0)
        return menor_valor;    
    else
        return 1;

}
