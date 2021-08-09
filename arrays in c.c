#include <stdio.h>

int main(void) {
  
  int i;
  int tam;
  printf("Insira a quantidade de valores que deseja armazenar: ");
  scanf("%d",&tam);
  int vet[tam];

  for (i=0;i<tam;i++){
    printf("Insira o %d° valor: ",i+1);
    scanf("%d",&vet[i]);
  }

  printf("Valores: ");
  for (i=0;i<tam;i++){
    if(i != tam - 1) {
      printf("%d, ",vet[i]);
    } else {
      printf("%d\n",vet[i]);
    }
  }

  


  return 0;
}