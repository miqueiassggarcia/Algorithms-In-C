#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

void printar_vetor(int vetor[], int tam)
{
  for (int i = 0; i < tam; i++)
  {
    printf("%d ", vetor[i]);
  }
}

void swapdual(int* a, int* b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}
  
void DualPivotQuickSort(int* vetor, int menor, int maior)
{
  if (menor < maior) {
    int pivotesquerdo, pivotdireito;
    pivotdireito = partitiondual(vetor, menor, maior, &pivotesquerdo);
    DualPivotQuickSort(vetor, menor, pivotesquerdo - 1);
    DualPivotQuickSort(vetor, pivotesquerdo + 1, pivotdireito - 1);
    DualPivotQuickSort(vetor, pivotdireito + 1, maior);
  }
}
  
int partitiondual(int* vetor, int menor, int maior, int* pivotesquerdo)
{
  if (vetor[menor] > vetor[maior]){
    swapdual(&vetor[menor], &vetor[maior]);
  }

  int j = menor + 1;
  int g = maior - 1, k = menor + 1, minpivot = vetor[menor], maxpivot = vetor[maior];

  while (k <= g) {
    if (vetor[k] < minpivot) {
      swapdual(&vetor[k], &vetor[j]);
      j++;
    }

    else if (vetor[k] >= maxpivot){
      while (vetor[g] > maxpivot && k < g)
        g--;
      
      swapdual(&vetor[k], &vetor[g]);
      g--;

      if (vetor[k] < minpivot) {
        swapdual(&vetor[k], &vetor[j]);
        j++;
      }
    }
    k++;
  }

  j--;
  g++;

  swapdual(&vetor[menor], &vetor[j]);
  swapdual(&vetor[maior], &vetor[g]);

  *pivotesquerdo = j;

  return g;
}


int main(void) {
  srand(time(NULL));

  int rodadas = 10000;

  int total_vetores = 1;
  int tamanho_vetores = 10000;

  int vetor[total_vetores][tamanho_vetores];



  



  float total_tempo_quicksort_dual = 0.0;

  for (int i = 0; i < rodadas; i++)
  {

    // adicionando valores aleatorios aos vetores
    for (int i = 0; i < total_vetores; i++)
    {
      for (int j = 0; j < tamanho_vetores; j++)
      {
        vetor[i][j] = rand()%100;
      }
    }


    clock_t begin = clock();
  
    // ordenando vetores
    for (int i = 0; i < total_vetores; i++)
    {
      DualPivotQuickSort(vetor[i], 0, tamanho_vetores);
    }

    clock_t end = clock(); 

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;//cocks
    total_tempo_quicksort_dual += time_spent;
  
  }

  printf("\nmedia de tempo no dual quicksort: %f\n", total_tempo_quicksort_dual / rodadas);



  float total_tempo_quicksort = 0.0;

  for (int i = 0; i < rodadas; i++)
  {

    // adicionando valores aleatorios aos vetores
    for (int i = 0; i < total_vetores; i++)
    {
      for (int j = 0; j < tamanho_vetores; j++)
      {
        vetor[i][j] = rand()%100;
      }
    }


    clock_t begin = clock();
  
    // ordenando vetores
    for (int i = 0; i < total_vetores; i++)
    {
      quicksort(vetor[i], 0, tamanho_vetores -1);
    }

    clock_t end = clock(); 

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;//cocks
    total_tempo_quicksort += time_spent;
  
  }

  printf("\nmedia de tempo no quicksort: %f\n", total_tempo_quicksort / rodadas);



  return 0;
}