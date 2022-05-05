#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  FILE *pont_arq; // cria variável ponteiro para o arquivo
  char palavra[20]; // variável do tipo string
  
  //abrindo o arquivo com tipo de abertura w
  pont_arq = fopen("arquivo_palavra.txt", "w");
  
  //testando se o arquivo foi realmente criado
  if(pont_arq == NULL)
  {
  printf("Erro na abertura do arquivo!");
  return 1;
  }
  
  printf("Escreva uma palavra para testar gravação de arquivo: ");
  scanf("%s", palavra);
  
  //usando fprintf para armazenar a string no arquivo
  fprintf(pont_arq, "%s", palavra);
  
  //usando fclose para fechar o arquivo
  fclose(pont_arq);
  
  printf("\nDados gravados com sucesso!\n\n");

  char texto_str[20];
  
  //abrindo o arquivo_frase em modo "somente leitura"
  pont_arq = fopen("arquivo_palavra.txt", "r");
  
  //enquanto não for fim de arquivo o looping será executado
  //e será impresso o texto
  while(fgets(texto_str, 20, pont_arq) != NULL)
  printf("%s", texto_str);
  
  //fechando o arquivo
  fclose(pont_arq);

  pont_arq = fopen("arquivo_palavra.txt", "a");

  printf("\n\nEscreva uma palavra para testar a sobscrita de arquivo: ");
  scanf("%s", palavra);
  
  //usando fprintf para armazenar a string no arquivo
  fprintf(pont_arq, "%s", palavra);
  
  //usando fclose para fechar o arquivo
  fclose(pont_arq);
  
  printf("\nNovos dados gravados com sucesso!\n\n");
  
  //abrindo o arquivo_frase em modo "somente leitura"
  pont_arq = fopen("arquivo_palavra.txt", "r");
  
  //enquanto não for fim de arquivo o looping será executado
  //e será impresso o texto
  while(fgets(texto_str, 20, pont_arq) != NULL)
  printf("%s", texto_str);
  
  //fechando o arquivo
  fclose(pont_arq);

  return(0);
}