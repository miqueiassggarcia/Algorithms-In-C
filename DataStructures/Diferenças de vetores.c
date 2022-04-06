#include <stdio.h>

lerVetor(int vetor[], int tamanho) {
  for(int i=0; i<tamanho; i++) {
    printf("Digite o %dº valor: ", i+1);
    scanf("%d", &vetor[i]);
  }
}

imprimirVetor(int vetor[], int tamanho) {
  for(int i=0; i<tamanho; i++) {
    if (i==tamanho - 1) {
      printf("%d.\n",vetor[i]);
    }
    printf("%d, ",vetor[i]);
  }
}

imprimirDiferenca(int vetor1[], int vetor2[], int tamanho) {
  int diferenca[tamanho];

  for(int i=0; i<tamanho; i++) {
    diferenca[i] = vetor1[i] - vetor2[i];
  }

  return diferenca;
}

int main(void) {
  int tamanhovetor;

  tamanhovetor = 3;

  int vetor1[tamanhovetor];
  int vetor2[tamanhovetor];


  lerVetor(vetor1, tamanhovetor);
  lerVetor(vetor2, tamanhovetor);

  imprimirVetor(vetor1, tamanhovetor);
  imprimirVetor(vetor2, tamanhovetor);

  imprimirDiferenca(vetor1, vetor2, tamanhovetor);

  return 0;
}