#include <stdio.h>
#include <stdlib.h>

//Função que adiciona valores a um vetor, pedindo valores ao usuário
void inserirDados(int vet[], int tam) {
  for(int i = 0; i<tam; i++) {
    printf("Valor[%d]: ", i+1);
    scanf("%d", &vet[i]);
  }
}

//Função que imprime um vetor
int imprimirVetor(int vet[], int tam, int passo) {
  if(passo==0) {
    printf("\nVetor[");
    return 0;
  }
  
  return imprimirVetor(vet, tam, passo-1), (passo==tam ? printf("%d]\n", vet[passo-1]) : printf("%d, ", vet[passo-1]));
}

//Função que faz a troca de lugar de dois valores em um vetor
void swap(int vetor[], int pos_inicial, int pos_final){
  int aux = vetor[pos_final];
  vetor[pos_final] = vetor[pos_inicial];
  vetor[pos_inicial] = aux;
}

//Função que faz particionamento para o Quicksort
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

//Função que faz a iniciação e recursividade do Quicksort
void quicksort(int vetor[], int left, int right){
  if (left < right){
    int index_pivot = partition(vetor, left, right);
    quicksort(vetor, left, index_pivot - 1);
    quicksort(vetor, index_pivot + 1, right);
  }
}

//Função que faz a busca binária
int busca(int vet[], int ini, int fim, int valor) {
  int meio = (ini+fim)/2;
  if (ini>fim) {
    return -1;
  }

  if(vet[meio] == valor) {
    return meio;
  } else if(meio>valor) {
    return busca(vet, ini, meio-1, valor);
  } else if(meio<valor) {
    return busca(vet, meio+1, fim, valor);
  }
}

int main() {
  int escolha = - 1;
  int *vet;
  int tam = 0;
  int valor = 0;
  int condicao = -1;

  //While que vai manter as condições de escolha até 0
  while (escolha != 0) {
    printf("\n1 - Inserir dados;\n2 - Ordenar dados;\n3 - Imprimir dados;\n4 - Realizar busca;\n0 - Sair.\n\nDigite sua escolha: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
      printf("\nDigite o tamanho do vetor: ");
      scanf("%d", &tam);
      vet = (int *) malloc(tam * sizeof(int));
      inserirDados(vet, tam);
      condicao = 0;
    } else if (escolha == 2) {
      if(condicao == -1) {
        printf("\nPor favor, adicione os valores primeiro\n");
      } else {
        quicksort(vet, 0, tam-1);
        printf("Ordenação concluída\n");
        condicao = 1;
      }
    } else if (escolha == 3) {
      if(condicao == -1) {
        printf("\nPor favor, adicione os valores primeiro\n");
      } else {
        imprimirVetor(vet, tam, tam);
      }
    } else if (escolha == 4) {
      if(condicao == 1) {
        printf("Valor para procurar: ");
        scanf("%d", &valor);
        int resultado = busca(vet, 0, tam-1, valor);
        if(resultado == -1) {
          printf("\nValor não encontrado\n");
        } else {
          printf("\nValor encontrado na posição %d\n", resultado);
        }
      } else if(condicao == 0) {
        printf("\nPor favor, realize a ordenação antes da busca\n");
      } else {
        printf("\nPor favor, adicione os valores primeiro\n");
      }
    } else if (escolha == 0) {
      printf("\nGoodbye, and have a nice day :)\n");
    } else {
      printf("\nValor inválido, tente novamente\n");
    }
  }

  return 0;
}