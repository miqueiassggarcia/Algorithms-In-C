#include <stdio.h>

void ler_vetor(int vet[], int tam) {
  for(int i = 0; i < tam; i++) {
    printf("Vetor[%d]: ", i+1);
    scanf("%d", &vet[i]);
    }
    printf("\n");
}

void imprimir_vetor(int vet[], int tam) {
  for(int i = 0; i < tam; i++) {
    printf("[%d]", vet[i]);
    }
    printf("\n");
}

void ordenar_vetor(int vet[], int tam) {
  int replace = 0;
  for (int i = 0; i < tam-1; i++) {
    for(int j = 0; j < tam-1-i; j++) {
      if (vet[j] > vet[j+1]) {
        replace = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = replace;
      }
    }
  }
  imprimir_vetor(vet, tam);
}

int buscar_elemento(int vet[], int tam, int elemento) {
  for(int i = 0; i < tam-1; i++) {
    if(elemento == vet[i]) {
      return i;
    }
  }
  return -1;
}

int main(void) {
  const int MAXTAM = 100;
  int tamanho;
  int vetor[MAXTAM];
  int elemento;

  printf("Qual o tamanho do vetor? ");
  scanf("%d", &tamanho);

  ler_vetor(vetor, tamanho);
  imprimir_vetor(vetor, tamanho);
  ordenar_vetor(vetor, tamanho);

  printf("Digite o valor a ser procurado: ");
  scanf("%d", &elemento);

  int pos = buscar_elemento(vetor, tamanho, elemento);
  if (pos > 0) {
    printf("A posíção em que o valor %d foi encontrado foi %d.", elemento, pos+1);
  } else {
    printf("Não foi encontrado.");
  }
  return 0;
}