#include <stdio.h>

int binarySearch(int vet[], int ini, int fim, int value) {
  int meio = (ini+fim)/2;

  if(vet[meio] == value) {
    return meio;
  } else if (ini == fim) {
    return -1;
  } else if (value > vet[meio]) {
    return binarySearch(vet, meio + 1, fim, value);
  } else {
    return binarySearch(vet, ini, meio - 1, value);
  }

  return -1;
}

int main() {
  int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int ini = 0, fim = 9;

  int resultado = binarySearch(vet, ini, fim, 8);

  printf("%d\n", resultado);

  return 0;
}