#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
  char nome[50];
  char matricula[8];
  struct aluno *prox;
} Aluno;

void inserir(Aluno * lista, char nome[50], char mat[8]) {
  Aluno* novo = malloc(sizeof(Aluno));
  strcpy(novo->nome, nome);
  strcpy(novo->matricula, mat);
  if(lista == NULL) {
    lista = novo;
    lista -> prox = NULL;
  } else {
    novo -> prox = lista;
    lista = novo;
  }
}

void inserir_fim(Aluno* lista, char nome[50], char mat[8]) {
  Aluno * novo = malloc(sizeof(Aluno));
  strcpy(novo->nome, nome);
  strcpy(novo->matricula, mat);

  if(lista == NULL) {
    lista = novo;
    lista -> prox = NULL;
  } else {
    Aluno * p = lista;
    while(p->prox!=NULL) {
      p = p->prox;
    }
    p-> prox = novo;
    novo -> prox = NULL;
  }
}

void imprimir_lista(Aluno * lista) {
  while(lista = NULL) {
    printf("Nome: %s", lista->nome);
    printf(" Matricula: ", lista->matricula);
    lista = lista->prox;
  };
}

Aluno * criar() {
  return NULL;
}

int main() {
  Aluno * lista = criar();
  char nome[50];
  char mat[8];

  scanf("%s", nome);
  scanf("%s", mat);
  inserir_fim(lista, nome, mat);

  inserir(lista, nome, mat);
  return 0;
}