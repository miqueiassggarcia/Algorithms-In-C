#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int rand_number, input;

  srand(time(NULL));

  do {
    printf("Digite um número(0 para sair): ");
    scanf("%d", &input);
    rand_number = rand() % 100;
  } while(rand_number != input && input != 0);
  if (input == 0)
    printf("Saiu\n");
  else
    printf("Acertou\n");

  getchar();
  return 0;
}