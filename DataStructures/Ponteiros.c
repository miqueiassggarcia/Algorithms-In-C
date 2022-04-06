#include <stdio.h>

int main() {
  int x, y;

  int *p, *q;

  x = 2;
  y = 8;

  p = &x;
  q = &y;

  printf("O endereço de x é %p\n", &x);
  printf("O valor de x é %d\n", x);
  printf("O valor de p é %p\n", p);
  printf("O valor de *p é %d\n", *p);
  printf("O endereço de y é %p\n", &y);
  printf("O valor de y é %d\n", y);
  printf("O valor de q é %p\n", q);
  printf("O valor de *q é %d\n", *q);
  printf("O endereço de p é %p\n", &p);
  printf("O endereço de q é %p\n", &q);

  return 0;
}

//Crie as variáveis x e y e os ponteiros p e q. Atribua o valor 2 a x e 8 a y, o endereço de x para p
//e o endereço de y para q. Depois, imprima os seguintes resultados: a) o endereço de x e o valor de 
//x; b) o valor de p e o valor de *p; c) o endereço e o valor de y; d) o valor de q e o valor de *q; 
//e) o endereço de p e o endereço de q. *