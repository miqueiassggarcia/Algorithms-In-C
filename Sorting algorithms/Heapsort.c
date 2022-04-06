#include <stdio.h>

void criaheap(int vet[], int inicio, int final){
	int pai = vet[inicio];
	int filho = inicio * 2 + 1;
	while (filho <= final){
		if (filho < final){
			if (vet[filho] < vet[filho+1]){
				filho ++;
			}
		}
		if (vet[filho] > pai){
			vet[inicio] = vet[filho];
			inicio = filho;
			filho = inicio * 2 + 1;
		}else{
			filho = final + 1;
		}
	}
	vet[inicio] = pai;
}

void heapsort(int vet[], int tam){
	int inicio, pai;
	
	for (inicio=(tam-1)/2; inicio>=0; inicio--){
		criaheap(vet, inicio, tam-1);
	}
	
	for (inicio=tam-1; inicio>=1; inicio--){
		pai = vet[0];
		vet[0] = vet[inicio];
		vet[inicio] = pai;
		criaheap(vet, 0, inicio-1);
	}
}

int main()
{
	int tam=5,i;
	int vetor[tam];
	
	for (i=0; i<tam; i++){
		printf("Valor:");
		scanf("%d",&vetor[i]);
	}
	
	heapsort(vetor,tam);
	
	for (i=0; i<tam; i++){
		printf("%d ",vetor[i]);
	}
  printf("\n");
	
	return 0;
}