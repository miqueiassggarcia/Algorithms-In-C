#include <stdio.h>


void swap(int vetor[], int pos_inicial, int pos_final)
{
  int aux = vetor[pos_final];
  vetor[pos_final] = vetor[pos_inicial];
  vetor[pos_inicial] = aux;
}


int partition(int vetor[], int left, int right)
{
  int pivot = vetor[left];
  int i = left;

  for (int j = left + 1; j <= right; j++)
  {
    if (vetor[j] <= pivot)
    {
      i += 1;
      swap(vetor, i, j);
    }
  }

  swap(vetor, left, i);

  return i;
}

void quicksort(int vetor[], int left, int right)
{
  if (left < right)
  {
    int index_pivot = partition(vetor, left, right);
    quicksort(vetor, left, index_pivot - 1);
    quicksort(vetor, index_pivot + 1, right);
  }
}

void printar_vetor(int vetor[], int tam) {
  printf("[") ;
  for (int i = 0; i < tam; i++) {
    if(i+1==tam) {
      printf("%d]", vetor[i]);
    } else {
      printf("%d, ", vetor[i]);
    }
  }
}

int main() {
  int vet[10] = {5, 8, 9, 74, 6, 65, 4, 1, 12, 0};

  printf("\nVetor não ordenado:\n");
  printar_vetor(vet, 10);

  quicksort(vet, 0, 9);

  printf("\n\nVetor ordenado:\n");
  printar_vetor(vet, 10);

  return 0;
}