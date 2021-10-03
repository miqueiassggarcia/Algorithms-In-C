#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct contato{
  char nome[40];
  char telefone[15];
  char celular[15];
  char email[40];
  struct contato *prox;
} Contato;

Contato* cria_agenda(){
  return NULL;
}

void diminuirString(char string[40]){
  for(int i = 0; string[i]; i++){
		string[i] = tolower(string[i]);
	}
}

void inserirContato(Contato** contato) {
  char nome[40], telefone[15], celular[15], email[40];
  Contato *atual, *prox = NULL;
  Contato *novoContato = (Contato *) malloc(sizeof(Contato));

  printf("Digite o nome: ");
  setbuf(stdin, NULL);
  fgets(nome, sizeof(nome), stdin);
  diminuirString(nome);
  strcpy(novoContato -> nome,nome);

  printf("Digite o telefone: ");
  setbuf(stdin, NULL);
  fgets(telefone, sizeof(telefone), stdin);
  strcpy(novoContato -> telefone,telefone);

  printf("Digite o celular: ");
  setbuf(stdin, NULL);
  fgets(celular, sizeof(celular), stdin);
  strcpy(novoContato -> celular,celular);

  printf("Digite o email: ");
  setbuf(stdin, NULL);
  fgets(email, sizeof(email), stdin);
  strcpy(novoContato -> email,email);

  if (*contato == NULL) {
    novoContato -> prox = NULL;
    *contato = novoContato;
  } else {
    atual = *contato;
    prox = *contato;
    while(strcmp(prox->nome, nome) <= 0 && prox->prox != NULL) {
      if(prox != *contato) {
        atual = atual->prox;
      }
      prox = prox->prox;
    }
    if((*contato)->prox == NULL && prox->prox == NULL && strcmp(prox->nome, nome) > 0) {
      novoContato->prox = *contato;
      *contato = novoContato;
    } else if(prox->prox == NULL && strcmp(prox->nome, nome) <= 0) {
      prox->prox = novoContato;
      prox->prox->prox = NULL;
    } else {
      atual->prox = novoContato;
      novoContato->prox = prox;
    }
  }
}

void listarContatos(Contato *contato) {
  if(contato == NULL) {
    printf("\nA lista de contatos está vazia!\n");
  } else {
    while(contato != NULL) {
      printf("\nNome: %s", contato->nome);
      printf("Telefone: %s", contato->telefone);
      printf("Celular: %s", contato->celular);
      printf("Email: %s\n", contato->email);
      contato = contato->prox;
    }
  }
}

void inserir_fim(Contato** contato, char nome[50], char tel[15], char cel[15], char email[40]){
  Contato* novo = malloc(sizeof(Contato));
  strcpy(novo->nome,nome);
  strcpy(novo->telefone,tel);
  strcpy(novo->celular, cel);
  strcpy(novo->email,email);
  if(*contato==NULL){
    *contato = novo;
    (*contato)->prox = NULL;
  } else {
    Contato* p = *contato;
    while(p->prox!=NULL){
      p = p->prox;
    }
    p->prox = novo;
  }
}

Contato* buscar(Contato* contato) {
  char nome[40];

  printf("Digite o nome: ");
  setbuf(stdin, NULL);
  fgets(nome, sizeof(nome), stdin);
  diminuirString(nome);

  while(strcmp(contato->nome, nome) != 0) {
    contato = contato->prox;
  }

  return contato;
}

void excluir(Contato** contato) {
  char nome[40];

  printf("Digite o nome: ");
  setbuf(stdin, NULL);
  fgets(nome, sizeof(nome), stdin);
  diminuirString(nome);

  Contato* atual = *contato;
  Contato* prox = *contato;

  while(strcmp(prox->nome, nome) != 0) {
    if(prox != *contato) {
      atual = atual->prox;
    }
    prox = prox->prox;
  }

  atual->prox = prox->prox;
  free(prox);
}

void excluirLista(Contato** contato) {
  Contato *aux = *contato;
  
  while(aux != NULL) {
    *contato = aux->prox;
    free(aux);
    aux = *contato;
  }
}

int main() {
  Contato * contatos = cria_agenda();
  int escolha = -1;
  Contato * resultadoBuscar;

  while(escolha != 6) {
    printf("\n1 – Inserir Contato\n2 – Listar Contatos\n3 – Buscar Contatos\n4 - Exclui um Contato\n5 - Exclui Agenda\n6 – Sair\n");
    setbuf(stdin, NULL);
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      inserirContato(&contatos);
      break;

    case 2:
      listarContatos(contatos);
      break;

    case 3:
      resultadoBuscar = buscar(contatos);
      printf("\nResultado da busca\n");
      printf("Nome: %s", resultadoBuscar->nome);
      printf("Telefone: %s", resultadoBuscar->telefone);
      printf("Celular: %s", resultadoBuscar->celular);
      printf("Email: %s\n", resultadoBuscar->email);
      break;

    case 4:
      excluir(&contatos);
      break;

    case 5:
      excluirLista(&contatos);
      break;

    case 6:
      printf("\nBye, and have a nice day!\n");
      break;
    
    default:
      printf("Valor inválido, tente novamente");
      break;
    }

  }

}