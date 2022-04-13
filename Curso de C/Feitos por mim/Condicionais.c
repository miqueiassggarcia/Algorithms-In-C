#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main() {
  setlocale(LC_ALL,"");

  int a = 2;
  char b = "2";

  if(a == 5){
    printf("A variável a é igual a 5\n");
  }else{
    printf("A variável a não é igual a 5\n");
  }

  if(a % 2 == 0) {
    printf("A variável a é par\n");
  }else { // também existe o else if no C.
    printf("A variável a é ímpar\n");
  }

  if(a != b){
    printf("Ele diferencia\n");
  }
}