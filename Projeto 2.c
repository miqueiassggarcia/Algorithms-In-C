#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct controle {
  char nome[40];
  struct controle *prox;
} Controle;

Controle* inicializar() {
  return NULL;
}

void inserirContribuinte(Controle **lista) {
  char nome[40];

  printf("\nDigite o nome do contribuinte: ");
  setbuf(stdin, NULL);
  fgets(nome, sizeof(nome), stdin);

  Controle *novo_contribuinte;
  novo_contribuinte = malloc(sizeof(Controle));
  strcpy(novo_contribuinte->nome, nome);
  
  Controle *aux = *lista;
  if (aux == NULL){
    *lista = novo_contribuinte;
    novo_contribuinte->prox = NULL;
  } else {
    while (aux->prox != NULL) 
      aux = aux->prox;
    
    aux->prox = novo_contribuinte;
    novo_contribuinte->prox = NULL;
  }
}

void imprimirLista(Controle *lista) {
  int i = 1;
  printf("\n");
  while (lista != NULL){
    printf("Contribuinte %d: %s", i, lista->nome);
    lista = lista->prox;
    i++;
  }
}


void proximoContribuinte(Controle **lista) {
  if(*lista == NULL) {
    printf("Nenhum contribuinte foi adicionado!");
    return;
  }

  printf("\nO próximo contribuinte é %s", (*lista)->nome);

  Controle *aux = *lista;
 
  while(aux->prox != NULL) {
    aux = aux->prox;
  }

  aux->prox = *lista;
  *lista = (*lista)->prox;
  aux->prox->prox = NULL;

}

int main() {
  Controle *lista = inicializar();
  int escolha = -1;

  printf("\n----------Controle do café-----------\n");

  while(escolha != 0) {
    printf("\n1 - Inserir novo contribuinte");
    printf("\n2 - Informar próximo membro a contribuir");
    printf("\n3 - Imprimir lista completa");
    printf("\n0 - Sair\n");
    setbuf(stdin, NULL);
    scanf("%d", &escolha);
    
    switch(escolha) {
      case 0:
      printf("Bye, and have a nice day!");
      break;
      
      case 1:
        inserirContribuinte(&lista);
        break;

      case 2:
        proximoContribuinte(&lista);
        break;
      
      case 3:
        imprimirLista(lista);
        break;
      
      default:
      printf("Valor inválido, tente novamente");
      break;
    }
  }
  return 0;
}