#include <stdio.h>
#include <stdlib.h>

int main() {
  int quant;
  int tipo = -1;
  int verticeA, verticeB, arestas;

  printf("Quantos vertices possuí o grafo? ");
  scanf("%d", &quant);
  while(tipo < 1 || tipo > 2) {
    printf("Qual o tipo de grafo?\n(1-Direcionado)\n(2-Não direcionado) ");
    scanf("%d", &tipo);
  }

  // matriz = (int *) malloc((quant * quant) * sizeof(int));
  int matriz[quant][quant];
  for(int i = 0; i < quant; i++) {
    for(int j = 0; j < quant; j++) {
      matriz[i][j] = 0;
    }
  }

  do {
    printf("Qual o vertice de partida?(-1 para sair) ");
    scanf("%d", &verticeA);

    printf("Qual o vertice de chegada?(-1 para sair) ");
    scanf("%d", &verticeB);

    printf("Quantas arestas?(-1 para sair) ");
    scanf("%d", &arestas);

    if (verticeA >= 0 && verticeB >= 0 && arestas >= 0 && verticeA < quant && verticeB < quant) {
      matriz[verticeA][verticeB] = arestas;
      if(tipo == 2) {
        matriz[verticeB][verticeA] = arestas;
      }
    } else {
      printf("\nValor informado inválido ou de saída\n\n");
    }
    
  } while(verticeA >= 0 && verticeB >= 0 && arestas >= 0);

  for(int i = 0; i < quant; i++) {
    for(int j = 0; j < quant; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}