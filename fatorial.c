#include <stdio.h>

int somaVetor(int v[], int t, int step)  {
  if(step == t) {
    return 0;
  } else {
    return v[step] + somaVetor(v, t, step + 1);
  }
}

int main( ) {
  int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int tam = 10;
  int step = 0;

  int resultado = somaVetor(vetor, tam, step);

  printf("%d", resultado);

  return(0);
}