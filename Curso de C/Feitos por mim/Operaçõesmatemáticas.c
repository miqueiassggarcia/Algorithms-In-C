#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
  setlocale(LC_ALL,"");
  //Definindo variávies
  int a = -5, b = 3;

  //Soma
  printf("A soma de %d e %d é: %d\n", a, b, a + b); //O %d indica onde que será adicionado o valor da variável.
  
  //Subtração
  printf("A subtração de %d e %d é: %d\n", a, b, a - b);
  
  //Divisão
  printf("A divisão de %d e %d é: %d\n", a, b, a / b);
  
  //Multiplicação
  printf("A multiplicação de %d e %d é: %d\n", a, b, a * b);
  
  //Resto da divisão
  printf("O resto da divisão de %d e %d é: %d\n", a, b, a % b);

  //Valor absoluto
  printf("O valor absoluto de %d é: %d\n", a, abs(a)); //A função abs retorna o valor absoluto do número.

  // system("read -p 'Press any key to continue...' var");

}