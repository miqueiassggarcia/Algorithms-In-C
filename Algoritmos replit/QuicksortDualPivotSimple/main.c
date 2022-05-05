#include <stdio.h>
 
void quick_sort(int *a, int esquerda, int direita);

void imprimirVetor(int vet[], int ini, int fim);

void swap(int vetor[], int pos_inicial, int pos_final);

int main() {
  int vet[10] = {5, 8, 47, 22, 6, 3, 14, 7, 65, 0};

  printf("\nVetor não ordenado");
  imprimirVetor(vet, 0, 9);

  quick_sort(vet, 0, 9);

  printf("\n\nVetor ordenado");
  imprimirVetor(vet, 0, 9);

  return 0;
}

void quick_sort(int *vet, int esquerda, int direita) {
  int inicio, fim, pivot;
    
  inicio = esquerda;
  fim = direita;
  pivot = vet[(esquerda + direita) / 2];
    
  while(inicio <= fim) {
    while(vet[inicio] < pivot && inicio < direita){
      inicio++;
    }
    while(vet[fim] > pivot && fim > esquerda) {
      fim--;
    }
    if(inicio <= fim) {
      swap(vet, inicio, fim);
      inicio++;
      fim--;
    }
  }
    
  if(fim > esquerda) {
    quick_sort(vet, esquerda, fim);
  }
  if(inicio < direita) {
    quick_sort(vet, inicio, direita);
  }
}

void imprimirVetor(int vet[], int ini, int fim) {
  printf("\n[");
  for(int i=ini; i<=fim; i++) {
    if((i)==fim) {
      printf("%d]", vet[i]);
    } else {
      printf("%d, ", vet[i]);
    }
  }
}

void swap(int vetor[], int pos_inicial, int pos_final){
  int aux = vetor[pos_final];
  vetor[pos_final] = vetor[pos_inicial];
  vetor[pos_inicial] = aux;
}