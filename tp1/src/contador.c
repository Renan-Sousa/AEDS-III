#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "contador.h"

float area(Ponto A, Ponto B, Ponto P) {
    // cálculo da área do triângulo usando os vértices
    float AR = (float) (A.x*(B.y-P.y) + B.x*(P.y-A.y) + P.x*(A.y-B.y)) / 2;    

    if (AR < 0) {
        // a área deve ser positiva. Se for negativa retorna o inverso 
        return -AR;     
    }

    return AR;
}


int contagem(Ponto A, Ponto B, Ponto *vetor, int indice) {

    int cont = 0;              // Variável para armazenar quantos pontos estão dentro do triângulo
    float ART, AR1, AR2, AR3;  // Variáveis para armazenar as áreas dos triângulos
    Ponto P = vetor[indice];   // Obtém o ponto do vetor usando o índice fornecido

    // Cálculo da área do triângulo ABP
    ART = area(A, B, P);

    for (int i = 0; i < indice; i++) {
        // Cálculo das áreas dos triângulos internos
        AR1 = area(A, B, vetor[i]);
        AR2 = area(A, P, vetor[i]);
        AR3 = area(P, B, vetor[i]);   

        if (ART == (AR1 + AR2 + AR3) && AR1!=0 && AR2!=0 && AR3!=0) {
            // Se o ponto da iteração i está dentro do triângulo o contador aumenta 1
            cont++;
        }     
    }

    // retorna o número de pontos dentro do triâgulo
    return cont;
}


bool dentro_triangulo(Ponto A, Ponto B, Ponto C, Ponto P) {
    // Variáveis para armazenar as áreas dos triângulos
    float ART, AR1, AR2, AR3;
    
    // Cálculo da área do triângulo ABC
    ART = area(A, B, C);

    // Cálculo da área dos triângulos ABP, ACP, BCP
    AR1 = area(A, B, P);
    AR2 = area(A, C, P);
    AR3 = area(B, C, P);  
    
    // Verifica se área do triângulo ABC é igual a soma das áreas dos triângulos internos
    if (ART == (AR1 + AR2 + AR3) && AR1!=0 && AR2!=0 && AR3!=0) {
        // Se sim, o ponto P está dentro do triângulo ABC
        return true;
    }     

    return false;
}


int maximo_pontos(Ponto A, Ponto B, Ponto *V, int tam) {
    // Armazena o máximo de pontos que só se interceptam nas âncoras
    int maximo = 0;     

    // Testa todos os pontos do vetor
    for (int i = 0; i < tam; i++) {
        // Para cada ponto calcula quantos pontos estão dentro do triângulo formado entre ele e as âncoras
        int dentro = contagem(A, B, V, i);

        // Se nenhum ponto estiver dentro do triângulo, o contador ("memória") do ponto armazena 1
        if(dentro == 0) {
            V[i].cont = 1;
        }
        else {

            for (int j = 0; j < i; j++) {
                // Verifica se o ponto V[j] está dentro do triângulo ABV[i] 
                if(dentro_triangulo(A, B, V[i], V[j]) == true) {
        
                    // Soma 1 ao contador do ponto anterior V[j]
                    int temp = 1 + V[j].cont;
                    
                    // Atualiza a contagem do ponto V[i] se o número calculado for maior que o valor atual
                    if(temp > V[i].cont) {
                        V[i].cont = temp;
                    }
                }   
            }
        }
    
        // Atualiza o valor máximo de pontos se a contagem do ponto atual for maior que o valor máximo atual
        if (V[i].cont > maximo) {
            maximo = V[i].cont;
        }
    }

    return maximo;
}
