#include <stdio.h>

int swap(int*y, int*x) {
  int temp;

  temp=y;
  y=x;
  x=temp;
  return y,x;
}

void main(void) {
  int a = 4;
  int b = 5;

  printf("%d, %d", swap(a, b));
}