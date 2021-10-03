#include <stdio.h>

int main() {
  int tipo;
  int tamanho;

  printf("Quantidade de vertices do grafo: ");
  scanf("%d", &tamanho);

  do {
    printf("Digite o tipo de grafo:\n(1-Direcionado)\n(2-Não Direcionado)\n(3-Ponderado)\n");
    scanf("%d", &tipo);
  } while(tipo < 1 && tipo > 3);

  if (tipo == 1) {
    int grafo[tamanho][tamanho];
    for(int i = 0; i < tamanho; i++) {
      for(int j = 0; j < tamanho; j++) {
        printf("Digite o vertice adjacente a [%d](-1 para pular): ", i);
        scanf("%d", &grafo[i][j]);
      }
    }

    for(int i = 0; i < tamanho; i++) {
      for(int j = 0; j < tamanho; j++) {
        if(grafo[i][j] != -1) {
          if(j==0) {
            printf("%d → %d", i, grafo[i][j]);
          } else {
            printf(" → %d", grafo[i][j]);
          }
        }
      }
      printf("\n");
    }
  }
}