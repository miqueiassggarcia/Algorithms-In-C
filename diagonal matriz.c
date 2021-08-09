#include <stdio.h>

int main(void) {
  int matriz[10][10];
  int ordem;

  printf("Qual a ordem da matriz: ");
  scanf("%d", &ordem);

  for(int i=0; i<ordem; i++) {
    for(int j=0; j<ordem; j++) {
      printf("Digite o valor para[%d, %d]: ", i+1, j+1);
      scanf("%d", &matriz[i][j]);
    }
  }

  for(int i=0; i<ordem; i++) {
    for(int j=0; j<ordem; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  int soma;

  for(int i=0; i<ordem; i++) {
    for(int j=0; j<ordem; j++) {
      if (i+j+1==ordem) {
        printf("%d", matriz[i][j]);
        soma = soma + matriz[i][j];
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
  printf("\nA soma do valor da diagonal secundária é %d\n", soma);

  return 0;
}