#include <stdio.h>

typedef struct {
  char cidade[10], bairro[10], rua[10];
  int numero;
}endereco;

typedef struct {
	int d, m,a;
}dataN;

typedef struct{
	int matricula;
	char nome[10];
	dataN d;
  endereco end;
  int telefone;
  int semestre;
}Aluno;

void ler(Aluno lista[]) {
	for (int i=0; i<1; i++){
		printf("\nInsira a matricula do aluno %d: ", i+1);
		scanf("%d",&lista[i].matricula);

    printf("\nInsira o nome do aluno %d: ", i+1);
		setbuf(stdin, NULL);
		scanf("%s", lista[i].nome);

		printf("\nInsira a data de nascimento aluno %d: ", i+1);
    printf("\nDia: ");
		scanf("%d", &lista[i].d.d);
    printf("Mês: ");
		scanf("%d", &lista[i].d.m);
    printf("Ano: ");
		scanf("%d", &lista[i].d.a);

    printf("\nInsira os dados do endereço do aluno %d: ", i+1);
    printf("\nCidade: ");
		setbuf(stdin, NULL);
		scanf("%s", &lista[i].end.cidade);
    printf("Bairro: ");
		setbuf(stdin, NULL);
		scanf("%s", &lista[i].end.bairro);
    printf("Rua: ");
		setbuf(stdin, NULL);
		scanf("%s", &lista[i].end.rua);
    printf("Número: ");
    setbuf(stdin, NULL);
		scanf("%d", &lista[i].end.numero);

    printf("\nInsira o número de telefone do aluno %d: ", i+1);
		scanf("%d",&lista[i].telefone);

    printf("Insira o semestre que o aluno %d está cursando: ", i+1);
		scanf("%d", &lista[i].semestre);
	}
	
	for (int i=0; i<1; i++){
		printf("\nA matricula do aluno %s é %d\n", lista[i].nome, lista[i].matricula);
		printf("Data de nascimento: %d/%d/%d\n", lista[i].d.d, lista[i].d.m, lista[i].d.a);
    printf("%s mora na cidade de %s, bairro %s, rua %s, de número %d", lista[i].nome, lista[i].end.cidade, lista[i].end.bairro, lista[i].end.rua, lista[i].end.numero);
    printf("\nNúmero de telefone %d", lista[i].telefone);
    printf("\nCursando o %dº semestre.\n", lista[i].semestre);
	}
}


int main( ) {
	printf("Estruturas (Registros)\n");
	
	Aluno lista[1];
	
	ler(lista);
	
	return(0);
}