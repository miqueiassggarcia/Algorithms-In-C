#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// bonito linda

typedef struct lista {
  char nome[20];
  int* ini, fim;
  struct lista * prox;
} Lista;


Lista * inserirNovo (Lista* list, char name, int * tam) {
  tam+=1;

  Lista* novo = (Lista *) malloc(sizeof(Lista));
  *list->nome = name;
}

Lista * atualizarContribuinte (Lista * list) {

}

Lista * imprimirLista (Lista * list) {

}

Lista * criar() {
  return NULL;
}

int main() {
  
  Lista* lista = criar();
  int escolha = -1;
  char nome[20];
  int tam = 1;

  lista = (Lista *) malloc(sizeof(Lista));

  printf("Lista do café:\n");

  while(escolha!=0) {
    printf("1 - Inserir novo contribuinte;\n2 - Informar próximo membro a contribuir;\n3 - Imprimir lista completa;\n0 - Sair\n");
    scanf("%d", &escolha);
    if(escolha == 1){
      inserirNovo(&lista, nome, &tam);
    }else if(escolha == 2){
      atualizarContribuinte(lista);
    }else if(escolha == 3){
      imprimirLista(lista);
    }
  }
  
  return 0;
}