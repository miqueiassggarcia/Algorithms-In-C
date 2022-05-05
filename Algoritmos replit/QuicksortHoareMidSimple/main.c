#include <stdio.h>

//Imprime o vetor
void imprimirVetor(int vet[], int tam) {
  printf("\n[");
  for(int i=0; i<tam; i++) {
    if((i+1)==tam) {
      printf("%d]", vet[i]);
    } else {
      printf("%d, ", vet[i]);
    }
  }
}

//Faz a troca de lugar dos valores em um vetor
void swap(int vetor[], int pos_inicial, int pos_final){
  int aux = vetor[pos_final];
  vetor[pos_final] = vetor[pos_inicial];
  vetor[pos_inicial] = aux;
}

//Faz o particionamento do vetor e realiza o swap dos valores, para que sejam divididos
int partition(int vetor[], int left, int right){
  int pivot = vetor[left];
  int i = left;

  printf("\nParticionando com início %d e fim %d\n", left, right);
  for (int j = left + 1; j <= right; j++){
    if (vetor[j] <= pivot){
      imprimirVetor(vetor, 10);
      printf(" %d <= pivot %d ", vetor[j], pivot);
      i += 1;
      swap(vetor, i, j);
      printf("swap: %d, %d", i, j);
    } else {
      imprimirVetor(vetor, 10);
      printf(" %d <= pivot %d  false", vetor[j], pivot);
    }
    getchar();
  }

  imprimirVetor(vetor, 10);
  printf(" swap: %d, %d", i, left);
  swap(vetor, left, i);
  printf("\n\nVetor resultante:");
  imprimirVetor(vetor, 10);
  printf("\nIndex: %d\n", i);


  return i;
}

//Função inicial do quicksort que faz as chamadas recursivas
void quicksort(int vetor[], int left, int right){
  if(left<right) {
    int index_pivot = partition(vetor, left, right);
    quicksort(vetor, left, index_pivot-1);
    quicksort(vetor, index_pivot+1, right);
  }
}

int main(){
  int vetor[10] = {4, 6, 87, 5, 2, 0, 11, 9, 22, 3};

  quicksort(vetor, 0, 10-1);

  printf("\n\nResultado final:");
  imprimirVetor(vetor, 10);

  return 0;
}