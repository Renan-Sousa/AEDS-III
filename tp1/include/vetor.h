#ifndef VETOR_H_INCLUDED
#define VETOR_H_INCLUDED

/* Estrutura Ponto composta por x e y, representando as coordenadas,
A variável 'cont' guarda a resposta daquele subproblema que será usado nos próximo pontos. */
   
typedef struct {
    int x;
    int y;
    int cont;
} Ponto;

/* Função que aloca dinâmicamente um vetor de struct Ponto */
Ponto *alocar_vetor(int tam);

/* Função que lê o arquivo e coloca os pontos dentro do vetor */
Ponto *criar_vetor(FILE *fp, int n);

/* Função que criar e retorna um ponto(âncoras) do tipo (x,0) */
Ponto criar_ancora(int x);

/* Funções do QuickSort para ordenar o vetor em ordem crescente de y */
void troca(Ponto *p1, Ponto *p2); 
int particao(Ponto *vetor, int inicio, int fim);
void quickSort(Ponto *vetor, int inicio, int fim);

#endif