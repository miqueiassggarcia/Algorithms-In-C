#include <stdio.h>

void bubblesort(int vet[], int tam) {
	int temp = 0;
	for(int i=0; i<tam; i++) {
    for(int j=0; j<tam-i; j++) {
      if(vet[j]>vet[j+1]) {
        temp = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = temp;
      }
    }
	}
}

void fillVetor(int vetor[], int tam) {
  for(int i=0; i<tam; i++){
		printf("Digite o %dº valor: ", i+1);
		scanf("%d", &vetor[i]);
	}
}

void printVetor(int vet[], int tam) {
  printf("\nVetor [ ");
  for(int i=0; i<tam; i++) {
    if(i!=tam-1) {
      printf("%d, ", vet[i]);
    } else {
      printf("%d ]", vet[i]);  
    }
  }
}

int binarySearch(int vet[], int tam, int value) {
  int ini = 0;
  int  fim = tam-1;
  int meio;
  while(ini <= fim) {
    meio = (ini+fim)/2;

    if (value==vet[meio]) {
      return meio;
    } else if (value < vet[meio]) {
      fim = meio - 1;
    } else {
      ini = meio + 1;
    }
  }
  return -1;
}

int main() {
	int tam = 10;
	int vetor[tam];
	int valor;
  int posicao;

  fillVetor(vetor, tam);
  printVetor(vetor, tam);
  bubblesort(vetor, tam);
  printVetor(vetor, tam);

  printf("\n\nPesquise um valor no vetor: ");
  scanf("%d", &valor);

	posicao = binarySearch(vetor, tam, valor);
  printf("\nO valor %d se encontra na posição %d", valor, posicao);

	return 0;
}