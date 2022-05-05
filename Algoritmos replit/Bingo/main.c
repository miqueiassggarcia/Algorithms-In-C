#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int normal_search(int vetor[], int start, int end, int valor)
{
  if (start == end){
    return -1;
  } else 
  {
    for (int i = start; i < end; i++)
    {
      if (vetor[i] == valor)
      {
        return i;
      }
    }
  }

  return -1;
}

void printar_cartelas(int vetor[])
{
  int aux = 0;
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      if (vetor[aux] >= 10)
      {
        printf("%d ", vetor[aux]);
      } else 
      {
        printf(" %d ", vetor[aux]);
      }

      aux += 1;
    }
    printf("\n");
  }
}


int main(){
  srand(time(NULL));

  int n_cartelas = 0;
  printf("digite o numero de cartelas: ");
  scanf("%d", &n_cartelas);

  int cartelas[n_cartelas][25];


  // adicionando valores aleatorios
  for (int i = 0; i < n_cartelas; i++)
  {
    for(int j = 0; j < 25; j++){
      int valor_encontrado = 0;

      while(valor_encontrado == 0)
      {
        int valor_sorteado = 1 + rand()%70;
        if (normal_search(cartelas[i], 0, j, valor_sorteado) == -1)
        {
          cartelas[i][j] = valor_sorteado;
          valor_encontrado = 1;
        }
      }
    }
  }


  // printando cartelas
  for(int i = 0; i < n_cartelas; i++)
  {
    printar_cartelas(cartelas[i]);
    printf("\n");
  }


  return 0;
}