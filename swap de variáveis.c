#include <stdio.h>

int swap(int*a, int*b) {
  int temp;

  temp=*a;
  *a=*b;
  *b=temp;
}

void main(void) {
  int a = 4;
  int b = 5;

  swap(&a, &b);

  printf("%d, %d", a, b);
}