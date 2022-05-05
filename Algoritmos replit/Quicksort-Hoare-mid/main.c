#include <stdio.h>
  
int partition(int* vetor, int menor, int maior, int* pivotesquerdo);

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

void swap(int* a, int* b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}
  
void dualPivotQuickSort(int* vetor, int menor, int maior)
{
  if (menor < maior) {
    int pivotesquerdo, pivotdireito;
    pivotdireito = partition(vetor, menor, maior, &pivotesquerdo);
    dualPivotQuickSort(vetor, menor, pivotesquerdo - 1);
    dualPivotQuickSort(vetor, pivotesquerdo + 1, pivotdireito - 1);
    dualPivotQuickSort(vetor, pivotdireito + 1, maior);
  }
}
  
int partition(int* vetor, int menor, int maior, int* pivotesquerdo)
{
  if (vetor[menor] > vetor[maior]){
    swap(&vetor[menor], &vetor[maior]);
  }

  int j = menor + 1;
  int g = maior - 1, k = menor + 1, minpivot = vetor[menor], maxpivot = vetor[maior];

  while (k <= g) {
    if (vetor[k] < minpivot) {
      swap(&vetor[k], &vetor[j]);
      j++;
    }

    else if (vetor[k] >= maxpivot){
      while (vetor[g] > maxpivot && k < g)
        g--;
      
      swap(&vetor[k], &vetor[g]);
      g--;

      if (vetor[k] < minpivot) {
        swap(&vetor[k], &vetor[j]);
        j++;
      }
    }
    k++;
  }

  j--;
  g++;

  swap(&vetor[menor], &vetor[j]);
  swap(&vetor[maior], &vetor[g]);

  *pivotesquerdo = j;

  return g;
}
  
int main() {
  int vetor[] = { 57, 8, 42, 75, 29, 77, 38, 28, 43, 2 };

  printf("\nVetor não ordenado:");
  imprimirVetor(vetor, 0, 9);

  dualPivotQuickSort(vetor, 0, 9);

  printf("\n\nVetor ordenado:");
  imprimirVetor(vetor, 0, 9);
  
  return 0;
}