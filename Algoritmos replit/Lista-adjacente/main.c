#include <stdio.h>

void limparArray() {

}

int main() {
  // Declarando variáveis
  int tipo;
  int tamanho;
  int valor;

  // Pegando quantidade de vertices
  printf("Quantidade de vertices do grafo: ");
  scanf("%d", &tamanho);

  // Pegando uma opção de tipo
  do {
    printf("Digite o tipo de grafo:\n(1-Direcionado)\n(2-Não Direcionado)\n(3-Ponderado)\n");
    scanf("%d", &tipo);
  } while(tipo < 1 || tipo > 3);

  // Adicionando caso tipo seja direcionado
  if (tipo == 1) {
    int grafo[tamanho][tamanho];
    for(int i = 0; i < tamanho; i++) {
      for(int j = 0; j < tamanho; j++) {
        printf("Digite o vertice adjacente a [%d](-1 para pular): ", i);
        scanf("%d", &valor);
        if(valor > -2 && valor < tamanho){ // Garantindo que valores maiores que a quantidade de vertices seja colocados
          grafo[i][j] = valor;
        } else {
          printf("\nVertice informado não pertence ao grafo\n");
          j--;
        }
      }
    }

    for(int i = 0; i < tamanho; i++) {
      for(int j = 0; j < tamanho; j++) {
        if(grafo[i][j] != -1) {
          if(j==0) {
            printf("Vertice[%d] → %d", i, grafo[i][j]);
          } else {
            printf(" → %d", grafo[i][j]);
          }
        } else {
          if(j==0) {
            printf("Vertice[%d]", i);
          }
        }
      }
      printf("\n");
    }
  }

  if (tipo == 2) {
    int grafo[tamanho][tamanho];
    for(int i = 0; i < tamanho; i++) {
      for(int j = 0; j <= i; j++) {
        printf("Digite o vertice adjacente a [%d](-1 para pular): ", i);
        scanf("%d", &valor);

        if(valor > -2 && valor < tamanho){
          grafo[i][j] = valor;
        } else {
          printf("\nVertice informado não pertence ao grafo\n");
          j--;
        }
      }
      for(int j = tamanho; j > i; j--) {
        grafo[j][i] = grafo[i][j];
      }
    }

    for(int i = 0; i < tamanho; i++) {
      for(int j = 0; j < tamanho; j++) {
        if(grafo[i][j] != -1) {
          if(j==0) {
            printf("Vertice[%d] → %d", i, grafo[i][j]);
          } else {
            printf(" → %d", grafo[i][j]);
          }
        } else {
          if(j==0) {
            printf("Vertice[%d]", i);
          }
        }
      }
      printf("\n");
    }
  }

  if (tipo == 3) {
    int valorAresta;
    int grafo[tamanho][tamanho][2];
    for(int i = 0; i < tamanho; i++) {
      for(int j = 0; j < tamanho; j++) {
        printf("Digite o vertice adjacente a [%d](-1 para pular): ", i);
        scanf("%d", &valor);
        printf("Digite o peso da aresta: ");
        scanf("%d", &valorAresta);

        if(valor > -2 && valor < tamanho){
          grafo[i][j][0] = valor;
          grafo[i][j][1] = valorAresta;
        } else {
          printf("\nVertice informado não pertence ao grafo\n");
          j--;
        }
      }
    }

    for(int i = 0; i < tamanho; i++) {
      for(int j = 0; j < tamanho; j++) {
        if(grafo[i][j][0] != -1) {
          if(j==0) {
            printf("Vertice[%d] → %d,%d", i, grafo[i][j][0], grafo[i][j][1]);
          } else {
            printf(" → %d,%d", grafo[i][j][0], grafo[i][j][1]);
          }
        } else {
          if(j==0) {
            printf("Vertice[%d]", i);
          }
        }
      }
      printf("\n");
    }
  }
}