#include <stdio.h>

int main( )
{

int turmas = 2;
int alunos = 2;
int notas = 2;
int i, j, k;

char aluno[turmas][alunos][20];

float vetor[turmas][alunos][notas];

for(i=0; i<turmas; i++) {
	for(j=0; j<alunos; j++) {
		printf("Digite o nome do %dº aluno da %dª turma: ", j+1, i+1);
		fgets(aluno[i][j], sizeof(aluno), stdin);
	}
}

for (i=0;i<turmas;i++){
	for (j=0;j<alunos;j++){
		for (k=0;k<notas;k++){
			printf("Digite a %dª nota de %s", k+1, aluno[i][j]);
			scanf("%f",&vetor[i][j][k]);
		}
		
	}	
}

printf("\n");
for (i=0;i<turmas;i++){
	printf("Turma %d:\n", i+1);
	for (j=0;j<alunos;j++){
		for (k=0;k<notas;k++){
			if (k==1) {
				printf("%1.f;",vetor[i][j][k]);	
			}
			else {
				printf("%s notas: %1.f, ", aluno[i][j], vetor[i][j][k]);
			}
		}
		printf("\n");
	}	
	printf("\n");
}


return(0);
}