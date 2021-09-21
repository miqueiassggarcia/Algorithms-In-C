#include <stdio.h>

typedef struct {
  char nome[20];
  int tam;
  int* ini, fim;
} Lista;

Lista * inserirNovo(Lista * list, char nome) {

}

Lista * atualizarContribuinte(Lista * list) {

}

Lista * imprimirLista(Lista * list) {

}

int main() {
  
  Lista* lista;
  int escolha = -1;
  char nome;

  printf("Lista do café:\n");

  while(escolha!=0) {
    printf("1 - Inserir novo contribuinte;\n2 - Informar próximo membro a contribuir;\n3 - Imprimir lista completa;\n0 - Sair\n");
    scanf("%d", &escolha);
    if(escolha == 1){
      inserirNovo(lista, nome);
    }else if(escolha == 2){
      atualizarContribuinte(lista);
    }else if(escolha == 3){
      imprimirLista(lista);
    }
  }
  
  return 0;
}