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

// Cria uma nova lista com valor NULL
Contato* cria_agenda(){
  return NULL;
}

// Função para diminuir strings
void diminuirString(char string[40]){
  for(int i = 0; string[i]; i++){
		string[i] = tolower(string[i]);
	}
}

// Função que adicionar contatos em ordem alfabetica
void inserirContato(Contato** contato) {
  char nome[40], telefone[15], celular[15], email[40];
  Contato *atual, *prox = NULL;
  Contato *novoContato = (Contato *) malloc(sizeof(Contato));

  printf("\nDigite o nome: ");
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

  novoContato->prox = NULL;

  if (*contato == NULL) { // Caso a lista estiver vazia
    novoContato -> prox = NULL;
    *contato = novoContato;
  } else if (strcmp((*contato)->nome, nome) > 0) { // Caso o valor deva ser colocado no inicio da lista
    novoContato->prox = *contato;
    *contato = novoContato;
  } else {
    atual = *contato;
    prox = *contato;
    while(strcmp(prox->nome, nome) <= 0 && prox->prox != NULL) { // Percorre a lista até achar a posição que a nova struct deve ficar
      if(prox != *contato) {
        atual = atual->prox;
      }
      prox = prox->prox;
    }
    
    if(prox->prox == NULL && strcmp(prox->nome, nome) <= 0) { // Caso a struct deva ficar no final
      prox->prox = novoContato;
    } else { // Caso a struct deva entrar no meio da lista
      atual->prox = novoContato;
      novoContato->prox = prox;
    }
  }
}

// Função que lista os contatos
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

// Função que busca um contato
Contato* buscar(Contato* contato) {
  char nome[40];

  printf("\nDigite o nome: ");
  setbuf(stdin, NULL);
  fgets(nome, sizeof(nome), stdin);
  diminuirString(nome);

  while(strcmp(contato->nome, nome) != 0 && contato->prox != NULL) {
    contato = contato->prox;
  }

  if(strcmp(contato->nome, nome) != 0) {
    return NULL;
  }

  return contato;
}

// Função que exclui um contato
void excluir(Contato** contato) {
  char nome[40];

  printf("\nDigite o nome: ");
  setbuf(stdin, NULL);
  fgets(nome, sizeof(nome), stdin);
  diminuirString(nome);

  if(strcmp((*contato)->nome, nome) == 0) {
    Contato* aux = *contato;
    *contato = (*contato)->prox;
    free(aux);
  } else {
    Contato* atual = *contato;
    Contato* prox = *contato;

    while(strcmp(prox->nome, nome) != 0 && prox->prox != NULL) {
      if(prox != *contato) {
        atual = atual->prox;
      }
      prox = prox->prox;
    }

    if(strcmp(prox->nome, nome) != 0) {
      printf("\nValor não encontrado, tente novamente!\n");
      return;
    }

    atual->prox = prox->prox;
    free(prox);
  }
  printf("\nContato apagado\n");
}

// Função que exclui a lista de contatos inteira
void excluirLista(Contato** contato) {
  Contato *aux = *contato;
  
  while(aux != NULL) {
    *contato = aux->prox;
    free(aux);
    aux = *contato;
  }

  printf("\nLista de contatos apagada\n");
}

int main() {
  Contato * contatos = cria_agenda();
  int escolha = -1;
  Contato * resultadoBuscar;

  // Laço que mostra o menu e gerencia as escolhas
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
      if(resultadoBuscar == NULL) {
        printf("\nValor não encontrado, tente novamente!\n");
      } else {
        printf("\nResultado da busca:\n");
        printf("Nome: %s", resultadoBuscar->nome);
        printf("Telefone: %s", resultadoBuscar->telefone);
        printf("Celular: %s", resultadoBuscar->celular);
        printf("Email: %s\n", resultadoBuscar->email);
      }
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

  // Adição da struct resultante em arquivo
  FILE *arquivo;

  arquivo = fopen("Contatos.txt", "w");

  while(contatos != NULL) {
    fprintf(arquivo,"Nome: %s", contatos->nome);
    fprintf(arquivo,"Telefone: %s", contatos->telefone);
    fprintf(arquivo,"Celular: %s", contatos->celular);
    fprintf(arquivo,"Email: %s\n", contatos->email);
    contatos = contatos->prox;
  }

  fclose(arquivo);

  return 0;
}