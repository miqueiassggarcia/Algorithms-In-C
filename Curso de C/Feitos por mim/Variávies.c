#include <stdio.h>
#include <stdlib.h>
//Biblioteca com a linguagem do sistema.
#include <locale.h>

void main(){
  //Para possibilitar a utilização da linguagem do sistema.
  setlocale(LC_ALL,"");

  printf("Olá \n"); //A contrabarra n serve para quebrar a linha

  //Inteiros

  int a = 5;
  //printf("%d", a+b); //Mostrando a variável a"

  printf("O valor de a é: %d \n", a); //%d especifica que o valor será inteiro

  scanf("%d", &a); //O & indica que a variável está na memória do computador.
  printf("O valor de a mudou para: %d \n", a);

  //Reais

  float b = 5.5;
  //printf("%f", b); //Mostrando a variável b"

  printf("O valor de b é: %f \n", b); //%f especifica que o valor será decimal ou real que fala né

  scanf("%f", &b);
  printf("O valor de b mudou para: %f \n", b);

  //Strings

  char letter = 'w';
  //printf("%c", c); //Mostrando a variável c"

  printf("O valor de c é: %c \n", letter); //%c especifica que o valor será uma string

  __fpurge(stdin); //Serve para fazer a limpeza de memória temporaria de leitura
  //(Necessário para que possamos limpar o lixo e eliminar possíveis problemas)[No windows é usado o fflush(stdin); para a mesma função]
  
  scanf("%c", &letter);
  printf("O valor de c mudou para: %c \n", letter);

  // system("read -p 'Press any key to continue...' var");
}