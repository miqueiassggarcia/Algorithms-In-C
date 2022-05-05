#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
  char nome[50];
  char matricula[8];
  struct aluno *prox;
} Aluno;

Aluno* inicializar(){
  return NULL;
}
// passar a lista por referência
void inserir_inicio(Aluno* lista, char nome[50], char mat[8]){
  Aluno* novo = malloc(sizeof(Aluno));
  strcpy(novo->nome,nome);
  strcpy(novo->matricula,mat);
  if(lista==NULL){
    lista = novo;
    lista->prox = NULL;
  } else {
    novo->prox = lista;
    lista = novo;
    novo->prox = NULL;
  }
}
// passar lista por referência
void inserir_fim(Aluno* lista, char nome[50], char mat[8]){
  Aluno* novo = malloc(sizeof(Aluno));
  strcpy(novo->nome,nome);
  strcpy(novo->matricula,mat);
  if(lista==NULL){
    lista = novo;
    lista->prox = NULL;
  } else {
    Aluno* p = lista;
    while(p->prox!=NULL){
      p = p->prox;
    }
    p->prox = novo;
  }
}

void imprimir(Aluno* lista){
  while(lista != NULL){
    printf("Matrícula: %s\n",lista->matricula);
    printf("Nome: %s\n",lista->nome);
    lista=lista->prox;
  }
}

int main(void) {
  Aluno* lista = inicializar();
  char nome[50] = "Nome";
  char matricula[8] = "uepb";
  
  inserir_fim(lista,nome, matricula);
  
  inserir_fim(lista,nome, matricula);

  imprimir(lista);
  
  return 0;
}