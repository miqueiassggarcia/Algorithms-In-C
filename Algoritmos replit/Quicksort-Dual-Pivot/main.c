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
  
void DualPivotQuickSort(int* vetor, int menor, int maior)
{
  if (menor < maior) {
    int pivotesquerdo, pivotdireito;
    pivotdireito = partition(vetor, menor, maior, &pivotesquerdo);
    DualPivotQuickSort(vetor, menor, pivotesquerdo - 1);
    DualPivotQuickSort(vetor, pivotesquerdo + 1, pivotdireito - 1);
    DualPivotQuickSort(vetor, pivotdireito + 1, maior);
  }
}
  
int partition(int* vetor, int menor, int maior, int* pivotesquerdo)
{

  printf("\n\n\nInicio em %d e fim em %d", menor, maior);
  imprimirVetor(vetor, menor, maior);
  printf("\n\n");
  getchar();

  if (vetor[menor] > vetor[maior]){
    printf("\n\nSe o inicial for maior que o final");
    imprimirVetor(vetor, menor, maior);
    swap(&vetor[menor], &vetor[maior]);
    imprimirVetor(vetor, menor, maior);
    getchar();
  }

  // minpivot é o pivot esquerdo, e maxpivot é o pivot direito.
  int j = menor + 1;
  int g = maior - 1, k = menor + 1, minpivot = vetor[menor], maxpivot = vetor[maior];
  while (k <= g) {
    // Se os elementos forem menores que o pivot esquerdo
    if (vetor[k] < minpivot) { //Se vetor em k for menor que o menor pivot, ele vai ser trocado com a variável de controle j;
      printf("\n\nSe vetor[k] for menor que o menor pivot");
      imprimirVetor(vetor, menor, maior);
      swap(&vetor[k], &vetor[j]);
      j++;
      imprimirVetor(vetor, menor, maior);
      printf(" k = %d j = %d", k, j-1);
      getchar();
    }

    // Se os elementos forem maiores ou iguais ao pivot direito
    else if (vetor[k] >= maxpivot){
      while (vetor[g] > maxpivot && k < g) //Se vetor em k for maior que o maior pivot, ele irá com o g a partir do maior pivot, até achar um valor que seja menor que o pivot maior
        g--;
      printf("\n\nPara vetor[k] maior que o maior pivot e g contendo o valor menor que o maior pivot");
      imprimirVetor(vetor, menor, maior);
      swap(&vetor[k], &vetor[g]); //E então fará a troca de lugar com o valor que é menor que o maior pivot, com k
      imprimirVetor(vetor, menor, maior);
      printf(" k = %d e g = %d", k, g);
      getchar();
      g--;
      if (vetor[k] < minpivot) { //Depois verificará se o novo valor para k é menor que o menor pivot, se sim, fará a troca com j
        printf("\n\nSe o pivot trocado com g for menor que o menor pivot");
        imprimirVetor(vetor, menor, maior);
        swap(&vetor[k], &vetor[j]);
        j++;
        imprimirVetor(vetor, menor, maior);
        getchar();
      }
    }
    k++;
  }
  j--;
  g++;// Voltando os valores de j e g para o valor certo antes da troca com pivot

  // Trazer pivots para suas posições corretas.
  printf("\n\nMenor pivot para seu lugar j = %d", j);
  swap(&vetor[menor], &vetor[j]);
  imprimirVetor(vetor, menor, maior);
  printf("\n\nMaior pivot para seu lugar g = %d", g);
  swap(&vetor[maior], &vetor[g]);
  imprimirVetor(vetor, menor, maior);
  getchar();

  // Retornando indices dos pivots.
  *pivotesquerdo = j; // Pois uma função não pode ter 2 returns

  return g;
}
  
int main() {
  int vetor[] = { 57, 8, 42, 75, 29, 77, 38, 28, 43, 2 };

  DualPivotQuickSort(vetor, 0, 9);

  printf("\n\nVetor ordenado:");
  imprimirVetor(vetor, 0, 9);
  
  return 0;
}