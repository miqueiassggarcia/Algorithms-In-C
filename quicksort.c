#include <stdio.h>


void swap(int vetor[], int pos_inicial, int pos_final){
  int aux = vetor[pos_final];
  vetor[pos_final] = vetor[pos_inicial];
  vetor[pos_inicial] = aux;
}


int partition(int vetor[], int left, int right){
  int pivot = vetor[left];
  int i = left;

  for (int j = left + 1; j <= right; j++){
    if (vetor[j] <= pivot){
      i += 1;
      swap(vetor, i, j);
    }
  }

  swap(vetor, left, i);

  return i;
}

void quicksort(int vetor[], int left, int right){
  if (left < right){
    int index_pivot = partition(vetor, left, right);
    quicksort(vetor, left, index_pivot - 1);
    quicksort(vetor, index_pivot + 1, right);
  }
}


int main(){

  int vetor[10] = {9, 14, 3, 7, 75, 0, 1, 2, 81, 10};

  quicksort(vetor, 0, 10);

  for(int i = 0; i < 10; i++){
    printf("%d ", vetor[i]);
  }

  return 0;
}